package ac

import "base:runtime"

import "core:container/xar"
import "core:flags"
import "core:fmt"
import "core:os"
import "core:strconv"
import "core:strings"
import "core:unicode"
import "core:unicode/utf8"

Options :: struct {
    tree_sitter_ast : ^os.File `args:"required,file=r" usage:"path to AST dump from tree-sitter"`,
    odin_dumper_ast : ^os.File `args:"required,file=r" usage:"path to AST dump from odin"`,
}

Sexpat_Token_Type :: enum {
    Open_Paren,
    Close_Paren,
    Open_Bracket,
    Close_Bracket,
    Comma,
    Dash,
    Symbol,
    Number,
    String,
    EOF,
    Garbage,
}

Sexpat_Token :: struct {
    type : Sexpat_Token_Type,
    string : string,
}

Sexpat_Read_State :: struct {
    index, line, column, nesting : int,
}

Sexpat :: struct {
    contents : string,
    read_state : Sexpat_Read_State,
}

sexpat_init :: proc(s : ^Sexpat, file: ^os.File, loc := #caller_location) {
    contents, err := os.read_entire_file(file, context.allocator)
    if err != nil {
        fail("failed to read file contents: %v", err)
    }
    s.contents = transmute(string)contents
    s.read_state.index = 0
    s.read_state.line = 1
    s.read_state.column = 0
    s.read_state.nesting = 0
    return
}

sexpat_destroy :: proc(s : ^Sexpat) {
    free(raw_data(s.contents))
}

is_rune_symbolic :: proc(r : rune) -> bool {
    switch r {
    case 'a'..='z', 'A'..='Z', '0'..='9', '-', '_':
        return true
    }
    return false
}

is_rune_numeric :: proc(r : rune) -> bool {
    switch r {
    case '0'..='9':
        return true
    }
    return false
}

sexpat_next_token :: proc(s : ^Sexpat) -> (tok : Sexpat_Token, nesting: int) {
    last_rune : rune
    last_rune_byte_idx, last_rune_byte_len : int
    for {
        if s.read_state.index >= len(s.contents) {
            tok.type = .EOF
            return
        }
        last_rune, last_rune_byte_len = utf8.decode_rune_in_string(s.contents[s.read_state.index:])
        last_rune_byte_idx = s.read_state.index
        s.read_state.index += last_rune_byte_len
        if last_rune == '\n' {
            s.read_state.column = 0
            s.read_state.line += 1
        } else {
            s.read_state.column += 1
        }
        if last_rune == utf8.RUNE_ERROR {
            tok.type = .Garbage
            tok.string = s.contents[last_rune_byte_idx : last_rune_byte_idx + last_rune_byte_len]
            return
        }
        if !unicode.is_space(last_rune) {
            break
        }
    }
    Token_Mode :: enum {
        Single_Rune,
        Matching_Set,
        String,
    }
    In_Matching_Set_Proc :: #type proc(r : rune) -> bool
    token_mode := Token_Mode.Single_Rune
    in_matching_set : In_Matching_Set_Proc
    nesting = s.read_state.nesting
    switch last_rune {
    case '(':
        tok.type = .Open_Paren
        s.read_state.nesting += 1
        nesting += 1
    case ')':
        tok.type = .Close_Paren
        s.read_state.nesting -= 1
    case '[':
        tok.type = .Open_Bracket
    case ']':
        tok.type = .Close_Bracket
    case '-':
        tok.type = .Dash
    case ',':
        tok.type = .Comma
    case '"':
        tok.type = .String
        token_mode = .String
    case '0'..='9':
        tok.type = .Number
        token_mode = .Matching_Set
        in_matching_set = is_rune_numeric
    case:
        tok.type = .Symbol
        token_mode = .Matching_Set
        in_matching_set = is_rune_symbolic
    }
    switch token_mode {
    case .Single_Rune:
        tok.string = s.contents[last_rune_byte_idx : last_rune_byte_idx + last_rune_byte_len]
    case .Matching_Set:
        byte_index := last_rune_byte_idx
        byte_len := last_rune_byte_len
        for {
            if s.read_state.index >= len(s.contents) {
                break
            }
            r, l := utf8.decode_rune_in_string(s.contents[s.read_state.index:])
            if in_matching_set(r) {
                if r == '\n' {
                    s.read_state.column = 0
                    s.read_state.line += 1
                } else {
                    s.read_state.column += 1
                }
                s.read_state.index += l
                byte_len += l
            } else {
                break
            }
        }
        tok.string = s.contents[byte_index : byte_index + byte_len]
    case .String:
        string_byte_index := last_rune_byte_idx
        string_byte_len := last_rune_byte_len
        escape := false
        for {
            if s.read_state.index >= len(s.contents) {
                tok.type = .Garbage
                tok.string = s.contents[string_byte_index : string_byte_index + string_byte_len]
                return
            }
            r, l := utf8.decode_rune_in_string(s.contents[s.read_state.index:])
            s.read_state.index += l
            if r == '\n' {
                s.read_state.column = 0
                s.read_state.line += 1
            } else {
                s.read_state.column += 1
            }
            string_byte_len += l
            if r == utf8.RUNE_ERROR {
                tok.type = .Garbage
                tok.string = s.contents[string_byte_index : string_byte_index + string_byte_len]
                return
            }
            if !escape {
                if r == '\\' {
                    escape = true
                }
                if r == '"' {
                    break
                }
            } else {
                escape = false
            }
        }
        tok.string = s.contents[string_byte_index : string_byte_index + string_byte_len]
    }
    return
}

TS_Location :: struct {
    line, column : int,
}

TS_Range :: struct {
    begin, end : TS_Location,
}

ts_range_fill :: proc(state : ^State, range : ^TS_Range, loc := #caller_location) {
    ts_location_fill(state, &range.begin, loc = loc)
    _, _ = state_assert_ts_token(state, .Dash, -1, "between tree sitter locations in tree-sitter range", loc = loc)
    ts_location_fill(state, &range.end, loc = loc)
}

ts_location_fill :: proc(state : ^State, location : ^TS_Location, loc := #caller_location) {
    _, _ = state_assert_ts_token(state, .Open_Bracket, -1, "opening tree-sitter location", loc = loc)
    tok, _ := state_assert_ts_token(state, .Number, -1, "tree-sitter location line", loc = loc)
    ok : bool
    location.line, ok = strconv.parse_int(tok.string, 10)
    if !ok {
        fail(state, "%s is not a number for line", tok.string, loc = loc)
    }
    _, _ = state_assert_ts_token(state, .Comma, -1, "between tree-sitter line and column", loc = loc)
    tok, _ = state_assert_ts_token(state, .Number, -1, "tree-sitter location column", loc = loc)
    location.column, ok = strconv.parse_int(tok.string, 10)
    if !ok {
        fail(state, "%s is not a number for column", tok.string, loc = loc)
    }
    _, _ = state_assert_ts_token(state, .Close_Bracket, -1, "closing tree-sitter location", loc = loc)
    // make them 1-based
    location.line += 1
    location.column += 1
}

TS_Scope :: struct {
    nesting : int,
    element : TS_Element,
    element_state : int,
    range : TS_Range,
    current_event : Scope_Event,
    child_element : TS_Element,
}

OD_Scope :: struct {
    nesting : int,
    element : Maybe(OD_Element),
    string : string,
    ts_element : TS_Element,
}

Recorded_Read_State :: struct {
    begin, end : Sexpat_Read_State,
    element : TS_Element,
}

nil_recorded_read_state := Recorded_Read_State {}

State :: struct {
    od, ts: Sexpat,
    str_to_od : map[string]OD_Element,
    str_to_ts : map[string]TS_Element,
    ts_scopes : xar.Array(TS_Scope, 6),
    od_scopes : xar.Array(OD_Scope, 6),
    ts_inner_scope : ^TS_Scope,
    od_inner_scope : ^OD_Scope,

    ts_mode : TS_Mode,
    rr_element : TS_Element, // used when recording and replaying
    recorded_read_states : [dynamic]Recorded_Read_State,
    recorded_read_state_opened_scopes : int, // used when recording
    saved_ts_read_state : Sexpat_Read_State, // used when replaying
}

state_init :: proc(state : ^State, opts : ^Options, loc := #caller_location) {
    sexpat_init(&state.od, opts.odin_dumper_ast)
    sexpat_init(&state.ts, opts.tree_sitter_ast)
    state.str_to_od = od_elements_map_make()
    state.str_to_ts = ts_elements_map_make()
    xar.array_init(&state.ts_scopes)
    xar.array_init(&state.od_scopes)
    err : runtime.Allocator_Error
    state.ts_inner_scope, err = xar.push_back_elem_and_get_ptr(&state.ts_scopes, TS_Scope{})
    if err != nil {
        fail("could not add empty tree-sitter scope: %v", err, loc = loc)
    }
    state.od_inner_scope, err = xar.push_back_elem_and_get_ptr(&state.od_scopes, OD_Scope{})
    if err != nil {
        fail("could not add empty Odin dumper scope: %v", err, loc = loc)
    }

    state.ts_mode = .Reading_From_State
    state.rr_element = .Nil_Element
    // state.recorded_read_states
    state.recorded_read_state_opened_scopes = 0
}

state_destroy :: proc(state : ^State) {
    delete(state.recorded_read_states)
    state.od_inner_scope = nil
    state.ts_inner_scope = nil
    xar.destroy(&state.od_scopes)
    xar.destroy(&state.ts_scopes)
    delete(state.str_to_ts)
    delete(state.str_to_od)
    sexpat_destroy(&state.ts)
    sexpat_destroy(&state.od)
}

fail_no_state :: proc(format : string, args : ..any, loc := #caller_location) -> ! {
    fmt.eprintf("FAIL (at %s:%d:%d): ", loc.file_path, loc.line, loc.column)
    fmt.eprintfln(format, ..args)
    os.exit(1)
}

fail_with_state :: proc(state : ^State, format : string, args : ..any, loc := #caller_location) -> ! {
    tsrs := state.ts.read_state
    odrs := state.od.read_state
    ts_sb, od_sb : strings.Builder
    strings.builder_init(&ts_sb)
    ts_it := xar.iterator(&state.ts_scopes)
    _, _, _ = xar.iterate_by_val(&ts_it)
    for val, idx in xar.iterate_by_val(&ts_it) {
        if idx > 1 {
            fmt.sbprint(&ts_sb, " -> ")
        }
        fmt.sbprintf(&ts_sb, "%v (%d, %v)", val.element, val.element_state, val.current_event)
    }
    strings.builder_init(&od_sb)
    od_it := xar.iterator(&state.od_scopes)
    _, _, _ = xar.iterate_by_val(&od_it)
    for val, idx in xar.iterate_by_val(&od_it) {
        if idx > 1 {
            fmt.sbprint(&od_sb, " -> ")
        }
        if val.element == nil {
            if val.string == "" {
                fmt.sbprint(&od_sb, "array")
            } else {
                fmt.sbprintf(&od_sb, "named (%s)", val.string)
            }
        } else {
            fmt.sbprintf(&od_sb, "%v (%s)", val.element, val.string)
        }
    }
    fmt.eprintf("FAIL (at %s:%d:%d): ", loc.file_path, loc.line, loc.column)
    fmt.eprintfln(format, ..args)
    fmt.eprintfln("  TS:\n    line: %d, column: %d\n    stack: %s\n  OD:\n    line: %d, column: %d\n    stack: %s", tsrs.line, tsrs.column, strings.to_string(ts_sb), odrs.line, odrs.column, strings.to_string(od_sb))
    os.exit(1)
}

fail :: proc{
    fail_no_state,
    fail_with_state,
}

TS_Scope_Item_Type :: enum {
    Done,
    Open_Scope,
    Close_Scope,
    AST,
}

TS_Scope_Item :: struct {
    type : TS_Scope_Item_Type,
    nesting : int, // valid for Open_Scope, Close_Scope and AST
    element : TS_Element, // valid only for .AST
    range : TS_Range, // valid only for .AST
}

state_next_ts_scope_item :: proc(state : ^State, loc := #caller_location) -> (item : TS_Scope_Item) {
    tok, nesting := sexpat_next_token(&state.ts)
    switch tok.type {
    case .EOF:
        item.type = .Done
        return
    case .Open_Paren:
        item.type = .Open_Scope
    case .Close_Paren:
        item.type = .Close_Scope
    case .Symbol:
        item.type = .AST
        ts_e, ok := state.str_to_ts[tok.string]
        if !ok {
            fail(state, "unexpected tree sitter element received: %s", tok.string, loc = loc)
        }
        item.element = ts_e
        ts_range_fill(state, &item.range, loc = loc)
    case .Open_Bracket, .Close_Bracket, .Comma, .Dash, .Number, .String, .Garbage:
        fail(state, "unexpected tree-sitter sexp token when getting next scope item, expected a EOF or open paren or close paren or a symbol, got %v", tok.type, loc = loc)
    case:
        fail(state, "aieee!", loc = loc)
    }
    item.nesting = nesting
    return
}

state_is_od_element_sub_next :: proc(state : ^State, name : string) -> bool {
    saved_read_state := state.od.read_state
    defer state.od.read_state = saved_read_state
    tok, _ := sexpat_next_token(&state.od)
    if tok.type != .Open_Paren {
        return false
    }
    tok, _ = sexpat_next_token(&state.od)
    if tok.type != .Symbol {
        return false
    }
    if tok.string != name {
        return false
    }
    return true
}

state_peek_ts_scope_item :: proc(state : ^State, loc := #caller_location) -> (item : TS_Scope_Item) {
    saved_read_state := state.ts.read_state
    item = state_next_ts_scope_item(state, loc = loc)
    state.ts.read_state = saved_read_state
    return
}

state_push_ts_scope :: proc(state : ^State, nesting : int, loc := #caller_location) {
    err : runtime.Allocator_Error
    state.ts_inner_scope, err = xar.push_back_elem_and_get_ptr(&state.ts_scopes, TS_Scope {
        nesting = nesting,
    })
    if err != nil {
        fail(state, "could not append tree-sitter scope: %v", err, loc = loc)
    }
}

state_pop_ts_scope :: proc(state : ^State, expected_popped_element := TS_Element.Nil_Element, loc := #caller_location) {
    if xar.len(state.ts_scopes) < 2 {
        fail(state, "no tree-sitter scopes to pop", loc = loc)
    }
    if expected_popped_element == .Nil_Element {
        _ = xar.pop(&state.ts_scopes)
    } else if popped_element := xar.pop(&state.ts_scopes).element; popped_element != expected_popped_element {
        fail(state, "expected popped ts scope to be %v, got %v", expected_popped_element, popped_element, loc = loc)
    }
    state.ts_inner_scope = xar.get_ptr(&state.ts_scopes, xar.len(state.ts_scopes) - 1)
}

state_maybe_expect_od_element_open :: proc(state : ^State, element : OD_Element, expected_nesting : int = -1, loc := #caller_location) -> (ok : bool) {
    saved_read_state := state.od.read_state
    defer if !ok {
        state.od.read_state = saved_read_state
    }
    expected_nesting := state_fix_expected_od_nesting(state, expected_nesting, "open scope", loc = loc)
    tok, nesting := sexpat_next_token(&state.od)
    if tok.type != .Open_Paren || expected_nesting != nesting {
        return
    }
    tok, nesting = sexpat_next_token(&state.od)
    if tok.type != .Symbol || expected_nesting != nesting {
        return
    }
    od_element := state.str_to_od[tok.string] or_return
    if element != od_element {
        return
    }
    ok = true
    state_push_od_scope(state, nesting, loc = loc)
    state.od_inner_scope.ts_element = state.ts_inner_scope.element
    state.od_inner_scope.element = element
    state.od_inner_scope.string = tok.string
    return
}

state_expect_od_element_open :: proc(state : ^State, element : OD_Element, expected_nesting : int = -1, loc := #caller_location) {
    expected_nesting := state_fix_expected_od_nesting(state, expected_nesting, "open scope", loc = loc)
    _, _ = state_assert_next_od_token(state, .Open_Paren, expected_nesting, "open scope", loc = loc)
    tok, nesting := state_assert_next_od_token(state, .Symbol, expected_nesting, "open scope symbol", loc = loc)
    od_element, ok := state.str_to_od[tok.string]
    if !ok {
        fail(state, "unexpected Odin dumper element received: %s", tok.string, loc = loc)
    }
    if element != od_element {
        fail(state, "syntax tree mismatch, for tree-sitter's %v we expected odin dumper's %v, got %v", state.ts_inner_scope.element, element, od_element, loc = loc)
    }
    state_push_od_scope(state, nesting, loc = loc)
    state.od_inner_scope.ts_element = state.ts_inner_scope.element
    state.od_inner_scope.element = element
    state.od_inner_scope.string = tok.string
}

state_push_od_scope :: proc(state : ^State, nesting : int, loc := #caller_location) {
    err : runtime.Allocator_Error
    state.od_inner_scope, err = xar.push_back_elem_and_get_ptr(&state.od_scopes, OD_Scope {
        nesting = nesting,
    })
    if err != nil {
        fail(state, "could not append Odin dumper scope: %v", err, loc = loc)
    }
}

state_maybe_expect_od_element_sub_open :: proc(state : ^State, name : string, expected_nesting : int = -1, loc := #caller_location) -> (ok : bool) {
    saved_read_state := state.od.read_state
    defer if !ok {
        state.od.read_state = saved_read_state
    }
    expected_nesting := state_fix_expected_od_nesting(state, expected_nesting, "open sub scope", loc = loc)
    tok, nesting := sexpat_next_token(&state.od)
    if tok.type != .Open_Paren || expected_nesting != nesting {
        return
    }
    tok, nesting = sexpat_next_token(&state.od)
    if tok.type != .Symbol || expected_nesting != nesting {
        return
    }
    if tok.string != name {
        return
    }
    ok = true
    state_push_od_scope(state, nesting, loc = loc)
    state.od_inner_scope.ts_element = state.od_inner_scope.ts_element
    state.od_inner_scope.string = tok.string
    return
}

state_expect_od_element_sub_open :: proc(state : ^State, name : string, expected_nesting : int = -1, loc := #caller_location) {
    expected_nesting := state_fix_expected_od_nesting(state, expected_nesting, "open sub scope", loc = loc)
    _, _ = state_assert_next_od_token(state, .Open_Paren, expected_nesting, "open sub scope", loc = loc)
    tok, nesting := state_assert_next_od_token(state, .Symbol, expected_nesting, "open sub scope symbol", loc = loc)
    if tok.string != name {
        fail(state, "syntax tree mismatch, inside Odin dumper's %v (or %q) we expected %s, got %s", state.od_inner_scope.element, state.od_inner_scope.string, name, tok.string, loc = loc)
    }
    state_push_od_scope(state, nesting, loc = loc)
    state.od_inner_scope.ts_element = state.od_inner_scope.ts_element
    state.od_inner_scope.string = tok.string
}

state_expect_od_int :: proc(state : ^State, loc := #caller_location) -> int {
    tok, _ := state_assert_next_od_token(state, .Number, loc = loc)
    n, ok := strconv.parse_int(tok.string, 10)
    if !ok {
        fail(state, "%s is not a valid number", tok.string, loc = loc)
    }
    return n
}

state_unescape_od_quoted_string :: proc(state : ^State, quoted_escaped : string, loc := #caller_location) -> string {
    if len(quoted_escaped) < 3 {
        fail(state, "string %s is too short, should have at least length of 3 (two for quotes and at least one rune", quoted_escaped)
    }
    b := strings.builder_make()
    escaped := quoted_escaped[1:][:len(quoted_escaped) - 2]
    skip_check := false
    for r in escaped {
        if !skip_check && r == '\\' {
            skip_check = true
            continue
        }
        if skip_check {
            switch r {
            case '\\', '"':
                skip_check = false
            case:
                fail(state, "unexpected escaped character %v", r, loc = loc)
            }
        }
        _, err := strings.write_rune(&b, r)
        if err != nil {
            fail(state, "failed to write a rune: %v", err, loc = loc)
        }
    }
    return strings.to_string(b)
}

state_expect_od_string :: proc(state : ^State, loc := #caller_location) -> string {
    tok, _ := state_assert_next_od_token(state, .String, loc = loc)
    return state_unescape_od_quoted_string(state, tok.string, loc = loc)
}

state_expect_od_element_sub_close :: proc(state : ^State, name : string, loc := #caller_location) {
    tok, nesting := state_assert_next_od_token(state, .Close_Paren, state.od_inner_scope.nesting, "close sub scope", loc = loc)
    if state.od_inner_scope.string != name {
        fail(state, "mismatch in name of Odin dumper's closing sub scope, expected %s, innermost scope has %s (element: %v)", name, state.od_inner_scope.string, state.od_inner_scope.element, loc = loc)
    }
    state_pop_od_scope(state, loc = loc)
}

state_pop_od_scope :: proc(state : ^State, loc := #caller_location) {
    if xar.len(state.od_scopes) < 2 {
        fail(state, "no Odin dumper scopes to pop", loc = loc)
    }
    _ = xar.pop(&state.od_scopes)
    state.od_inner_scope = xar.get_ptr(&state.od_scopes, xar.len(state.od_scopes) - 1)
}

state_expect_od_array_begin :: proc(state : ^State, expected_nesting : int = -1, loc := #caller_location) {
    expected_nesting := state_fix_expected_od_nesting(state, expected_nesting, "open array", loc = loc)
    _, nesting := state_assert_next_od_token(state, .Open_Paren, expected_nesting, "open array", loc = loc)
    state_push_od_scope(state, nesting, loc = loc)
    state.od_inner_scope.ts_element = state.od_inner_scope.ts_element
}

state_maybe_expect_od_array_end :: proc(state : ^State, loc := #caller_location) -> (ok : bool) {
    saved_read_state := state.od.read_state
    defer if !ok {
        state.od.read_state = saved_read_state
    }
    tok, nesting := sexpat_next_token(&state.od)
    if tok.type != .Close_Paren {
        return
    }
    if state.od_inner_scope.element != nil || state.od_inner_scope.string != "" {
        return
    }
    ok = true
    state_pop_od_scope(state, loc = loc)
    return
}

state_expect_od_array_end :: proc(state : ^State, loc := #caller_location) {
    _, _ = state_assert_next_od_token(state, .Close_Paren, -1, "close array", loc = loc)
    if state.od_inner_scope.element != nil || state.od_inner_scope.string != "" {
        fail(state, "not an end of an array (got element %v, string %s)", state.od_inner_scope.element, state.od_inner_scope.string, loc = loc)
    }
    state_pop_od_scope(state)
}

state_skip_od_element_sub :: proc(state : ^State, name : string, expected_nesting : int = -1, loc := #caller_location) {
    expected_nesting := state_fix_expected_od_nesting(state, expected_nesting, name, loc = loc)
    _, _ = state_assert_next_od_token(state, .Open_Paren, expected_nesting, "open skipped sub", loc = loc)
    tok, _ := state_assert_next_od_token(state, .Symbol, expected_nesting, "skipped sub symbol", loc = loc)
    state_assert_od_token(state, name, tok.string, "skipped sub symbol", loc = loc)
    for {
        tok, nesting := sexpat_next_token(&state.od)
        if tok.type == .Close_Paren && expected_nesting == nesting {
            break
        }
        if tok.type == .EOF {
            fail(state, "whoops, we went overboard with skipping %s", name, loc = loc)
        }
    }
}

state_assert_od_token :: proc(state : ^State, expected, got : string, desc : string = "", loc := #caller_location) {
    if expected != got {
        if len(desc) > 0 {
            fail(state, "expected %s in Odin dumper's output, got %s (%s)", expected, got, desc, loc = loc)
        } else {
            fail(state, "expected %s in Odin dumper's output, got %s", expected, got, loc = loc)
        }
    }
}

state_fix_expected_od_nesting :: proc(state : ^State, expected_nesting : int, desc : string = "", loc := #caller_location) -> int {
    if expected_nesting < 0 {
        if state.od_inner_scope.nesting == 0 {
            if len(desc) > 0 {
                fail(state, "no Odin dumper inner scope available for next expected nesting (%s)", desc, loc = loc)
            } else {
                fail(state, "no Odin dumper inner scope available for next expected nesting", loc = loc)
            }
        }
        return state.od_inner_scope.nesting + 1
    }
    return expected_nesting
}

Range_Check_Ignore :: enum {
    Line,
    Column,
}

Range_Check_Ignore_Set :: bit_set[Range_Check_Ignore]

state_expect_od_token :: proc(state : ^State, name : string, expected_nesting : int = -1, range_check_ignore : Range_Check_Ignore_Set = {}, loc := #caller_location) {
    expected_nesting := state_fix_expected_od_nesting(state, expected_nesting, "token", loc = loc)
    _, _ = state_assert_next_od_token(state, .Open_Paren, expected_nesting, "open token", loc = loc)
    tok, _ := state_assert_next_od_token(state, .Symbol, expected_nesting, "token name", loc = loc)
    state_assert_od_token(state, name, tok.string, "token name", loc = loc)
    _, _ = state_assert_next_od_token(state, .Open_Paren, expected_nesting + 1, "open token contents", loc = loc)
    tok, _ = state_assert_next_od_token(state, .Symbol, expected_nesting + 1, "token keyword", loc = loc)
    state_assert_od_token(state, "token", tok.string, "token name", loc = loc)
    _, _ = state_assert_next_od_token(state, .Open_Paren, expected_nesting + 2, "open token string", loc = loc)
    tok, _ = state_assert_next_od_token(state, .Symbol, expected_nesting + 2, "token string keyword", loc = loc)
    state_assert_od_token(state, "string", tok.string, "token string keyword", loc = loc)
    // probably there's no point in getting the string based on ts
    // ranges - as long the ts range and od line and column agree, we
    // can be sure that the token refers to the same string
    _, _ = state_assert_next_od_token(state, .String, expected_nesting + 2, "token string", loc = loc)
    _, _ = state_assert_next_od_token(state, .Close_Paren, expected_nesting + 2, "close token string", loc = loc)
    _ = state_expect_od_symbol_number_pair(state, "offset", expected_nesting + 2, loc = loc)
    line := state_expect_od_symbol_number_pair(state, "line", expected_nesting + 2, loc = loc)
    column := state_expect_od_symbol_number_pair(state, "column", expected_nesting + 2, loc = loc)
    _, _ = state_assert_next_od_token(state, .Close_Paren, expected_nesting + 1, "close token contents", loc = loc)
    _, _ = state_assert_next_od_token(state, .Close_Paren, expected_nesting, "close token", loc = loc)
    if .Line not_in range_check_ignore && line != state.ts_inner_scope.range.begin.line {
        fail(state, "unexpected location of the %s token, expected line %d, got %d", name, line, state.ts_inner_scope.range.begin.line, loc = loc)
    }
    if .Column not_in range_check_ignore && column != state.ts_inner_scope.range.begin.column {
        fail(state, "unexpected location of the %s token, expected column %d, got %d", name, column, state.ts_inner_scope.range.begin.column, loc = loc)
    }
}

// can be used in cases where we don't have a ts range matching the od
// token
state_expect_od_token_string :: proc(state : ^State, name, value : string, expected_nesting : int = -1, loc := #caller_location) {
    expected_nesting := state_fix_expected_od_nesting(state, expected_nesting, "token", loc = loc)
    _, _ = state_assert_next_od_token(state, .Open_Paren, expected_nesting, "open token", loc = loc)
    tok, _ := state_assert_next_od_token(state, .Symbol, expected_nesting, "token name", loc = loc)
    state_assert_od_token(state, name, tok.string, "token name", loc = loc)
    _, _ = state_assert_next_od_token(state, .Open_Paren, expected_nesting + 1, "open token contents", loc = loc)
    tok, _ = state_assert_next_od_token(state, .Symbol, expected_nesting + 1, "token keyword", loc = loc)
    state_assert_od_token(state, "token", tok.string, "token name", loc = loc)
    _, _ = state_assert_next_od_token(state, .Open_Paren, expected_nesting + 2, "open token string", loc = loc)
    tok, _ = state_assert_next_od_token(state, .Symbol, expected_nesting + 2, "token string keyword", loc = loc)
    state_assert_od_token(state, "string", tok.string, "token string keyword", loc = loc)
    tok, _ = state_assert_next_od_token(state, .String, expected_nesting + 2, "token string", loc = loc)
    s := state_unescape_od_quoted_string(state, tok.string, loc = loc)
    state_assert_od_token(state, value, s, "token string value", loc = loc)
    _, _ = state_assert_next_od_token(state, .Close_Paren, expected_nesting + 2, "close token string", loc = loc)
    _ = state_expect_od_symbol_number_pair(state, "offset", expected_nesting + 2, loc = loc)
    _ = state_expect_od_symbol_number_pair(state, "line", expected_nesting + 2, loc = loc)
    _ = state_expect_od_symbol_number_pair(state, "column", expected_nesting + 2, loc = loc)
    _, _ = state_assert_next_od_token(state, .Close_Paren, expected_nesting + 1, "close token contents", loc = loc)
    _, _ = state_assert_next_od_token(state, .Close_Paren, expected_nesting, "close token", loc = loc)
}

// can be used in cases where we don't have a ts range matching the od
// token
state_maybe_expect_od_token_string :: proc(state : ^State, name, value : string, expected_nesting : int = -1, loc := #caller_location) -> (ok : bool) {
    saved_read_state := state.od.read_state
    defer if !ok {
        state.od.read_state = saved_read_state
    }
    expected_nesting := state_fix_expected_od_nesting(state, expected_nesting, "token", loc = loc)
    tok, nesting := sexpat_next_token(&state.od)
    if tok.type != .Open_Paren || expected_nesting != nesting {
        return
    }
    tok, nesting = sexpat_next_token(&state.od)
    if tok.type != .Symbol || expected_nesting != nesting {
        return
    }
    if tok.string != name {
        return
    }
    tok, nesting = sexpat_next_token(&state.od)
    if tok.type != .Open_Paren || expected_nesting + 1 != nesting {
        return
    }
    tok, nesting = sexpat_next_token(&state.od)
    if tok.type != .Symbol || expected_nesting + 1 != nesting {
        return
    }
    if tok.string != "token" {
        return
    }
    // so this is a token we wanted, let's consume the rest of it, but
    // with asserts now.
    ok = true
    _, _ = state_assert_next_od_token(state, .Open_Paren, expected_nesting + 2, "open token string", loc = loc)
    tok, _ = state_assert_next_od_token(state, .Symbol, expected_nesting + 2, "token string keyword", loc = loc)
    state_assert_od_token(state, "string", tok.string, "token string keyword", loc = loc)
    tok, _ = state_assert_next_od_token(state, .String, expected_nesting + 2, "token string", loc = loc)
    s := state_unescape_od_quoted_string(state, tok.string, loc = loc)
    state_assert_od_token(state, value, s, "token string value", loc = loc)
    _, _ = state_assert_next_od_token(state, .Close_Paren, expected_nesting + 2, "close token string", loc = loc)
    _ = state_expect_od_symbol_number_pair(state, "offset", expected_nesting + 2, loc = loc)
    _ = state_expect_od_symbol_number_pair(state, "line", expected_nesting + 2, loc = loc)
    _ = state_expect_od_symbol_number_pair(state, "column", expected_nesting + 2, loc = loc)
    _, _ = state_assert_next_od_token(state, .Close_Paren, expected_nesting + 1, "close token contents", loc = loc)
    _, _ = state_assert_next_od_token(state, .Close_Paren, expected_nesting, "close token", loc = loc)
    return
}

state_expect_od_symbol_number_pair :: proc(state : ^State, name : string, expected_nesting : int = -1, loc := #caller_location) -> int {
    expected_nesting := state_fix_expected_od_nesting(state, expected_nesting, "symbol number pair", loc = loc)
    _, _ = state_assert_next_od_token(state, .Open_Paren, expected_nesting, "open symbol number pair", loc = loc)
    tok, _ := state_assert_next_od_token(state, .Symbol, expected_nesting, "symbol name", loc = loc)
    state_assert_od_token(state, name, tok.string, "symbol name", loc = loc)
    tok, _ = state_assert_next_od_token(state, .Number, expected_nesting, "id number", loc = loc)
    number, ok := strconv.parse_int(tok.string, 10)
    if !ok {
        fail(state, "%s is not a number in symbol number pair", tok.string, loc = loc)
    }
    _, _ = state_assert_next_od_token(state, .Close_Paren, expected_nesting, "close symbol number pair", loc = loc)
    return number
}

Sexpat_Source :: enum {
    Odin_Dumper,
    Tree_Sitter,
}

state_assert_ts_token :: proc(state : ^State, expected_type : Sexpat_Token_Type, expected_nesting : int = -1, desc : string = "", loc := #caller_location) -> (tok : Sexpat_Token, nesting : int) {
    tok, nesting = sexpat_next_token(&state.ts)
    state_assert_token(state, .Tree_Sitter, tok, expected_type, desc, loc = loc)
    state_assert_nesting(state, .Tree_Sitter, nesting, expected_nesting, desc, loc = loc)
    return
}

state_assert_next_od_token :: proc(state : ^State, expected_type : Sexpat_Token_Type, expected_nesting : int = -1, desc : string = "", loc := #caller_location) -> (tok : Sexpat_Token, nesting : int) {
    tok, nesting = sexpat_next_token(&state.od)
    state_assert_token(state, .Odin_Dumper, tok, expected_type, desc, loc = loc)
    state_assert_nesting(state, .Odin_Dumper, nesting, expected_nesting, desc, loc = loc)
    return
}

state_assert_token :: proc(state : ^State, source : Sexpat_Source, tok : Sexpat_Token, type : Sexpat_Token_Type, desc : string = "", loc := #caller_location) {
    if tok.type != type {
        if len(desc) > 0 {
            fail(state, "expected %v %v token (%s), got %v", type, source, desc, tok.type, loc = loc);
        } else {
            fail(state, "expected %v %v token, got %v", type, source, tok.type, loc = loc);
        }
    }
}

state_assert_nesting :: proc(state : ^State, source : Sexpat_Source, got_nesting, expected_nesting : int, desc : string = "", loc := #caller_location) {
    if expected_nesting < 0 || got_nesting == expected_nesting {
        return
    }
    if len(desc) > 0 {
        fail(state, "expected nesting in %v (%s) to be %d, got %d", source, desc, expected_nesting, got_nesting, loc = loc)
    } else {
        fail(state, "expected nesting in %v to be %d, got %d", source, expected_nesting, got_nesting, loc = loc)
    }
}

state_maybe_expect_open_ts_element :: proc(state : ^State, expected_element : TS_Element, loc := #caller_location) -> (ok : bool) {
    saved_read_state := state.ts.read_state
    ts_scope_item := state_next_ts_scope_item(state, loc = loc)
    if ts_scope_item.type != .Open_Scope {
        state.ts.read_state = saved_read_state
        return
    }
    nesting := ts_scope_item.nesting
    ts_scope_item = state_next_ts_scope_item(state, loc = loc)
    if ts_scope_item.type != .AST {
        state.ts.read_state = saved_read_state
        return
    }
    if ts_scope_item.element != expected_element {
        state.ts.read_state = saved_read_state
        return
    }
    state_push_ts_scope(state, nesting, loc = loc)
    state.ts_inner_scope.element = expected_element
    state.ts_inner_scope.range = ts_scope_item.range
    ok = true
    return
}

state_expect_ts_element_open :: proc(state : ^State, expected_element : TS_Element, loc := #caller_location) {
    ts_scope_item := state_next_ts_scope_item(state, loc = loc)
    if ts_scope_item.type != .Open_Scope {
        fail(state, "expected an opening of tree-sitter scope, got %v", ts_scope_item.type, loc = loc)
    }
    state_push_ts_scope(state, ts_scope_item.nesting, loc = loc)
    ts_scope_item = state_next_ts_scope_item(state, loc = loc)
    if ts_scope_item.type != .AST {
        fail(state, "expected a tree-sitter AST, got %v", ts_scope_item.type, loc = loc)
    }
    if ts_scope_item.element != expected_element {
        fail(state, "expected tree-sitter %v, got %v", expected_element, ts_scope_item.element, loc = loc)
    }
    state.ts_inner_scope.element = expected_element
    state.ts_inner_scope.range = ts_scope_item.range
}

state_expect_ts_element_close :: proc(state : ^State, expected_element : TS_Element, loc := #caller_location) {
    ts_scope_item := state_next_ts_scope_item(state, loc = loc)
    if ts_scope_item.type != .Close_Scope {
        fail(state, "expected a closing of tree-sitter scope, got %v", ts_scope_item.type, loc = loc)
    }
    state_pop_ts_scope(state, expected_element, loc = loc)
}

state_skip_od_docs :: proc(state : ^State, name : string, loc := #caller_location) {
    saved_read_state := state.od.read_state
    tok, _ := sexpat_next_token(&state.od)
    if tok.type != .Open_Paren {
        state.od.read_state = saved_read_state
        return
    }
    tok, _ = sexpat_next_token(&state.od)
    if tok.type != .Symbol || tok.string != name {
        state.od.read_state = saved_read_state
        return
    }
    tok, _ = sexpat_next_token(&state.od)
    if tok.type != .Open_Paren {
        state.od.read_state = saved_read_state
        return
    }
    for {
        tok, _ = sexpat_next_token(&state.od)
        if tok.type == .Open_Paren {
            _, _ = state_assert_next_od_token(state, .String, -1, "docs string", loc = loc)
            _, _ = state_assert_next_od_token(state, .Close_Paren, -1, "docs string close", loc = loc)
        } else if tok.type == .Close_Paren {
            break
        } else {
            fail(state, "expected either open paren or close paren in docs, got %v", tok.type, loc = loc)
        }
    }
    _, _ = state_assert_next_od_token(state, .Close_Paren, -1, "close docs", loc = loc)
}

state_expect_od_element_close :: proc(state : ^State, element : OD_Element, loc := #caller_location) {
    tok, nesting := state_assert_next_od_token(state, .Close_Paren, state.od_inner_scope.nesting, "close sub scope", loc = loc)
    if state.od_inner_scope.element != element {
        fail(state, "mismatch in name of Odin dumper's closing scope, expected %v, innermost scope has %v (string: %s)", element, state.od_inner_scope.element, state.od_inner_scope.string, loc = loc)
    }
    state_pop_od_scope(state, loc = loc)
}

TS_Mode :: enum {
    Reading_From_State,
    Recording_Initialized,
    Recording_Ongoing,
    Replaying_Initialized,
    Replaying_Ongoing,
}

state_initialize_ts_recording :: proc(state : ^State, element : TS_Element) {
    if state.ts_mode != .Reading_From_State {
        fail(state, "can't initialize recording when we are in %v state", state.ts_mode)
    }
    state.ts_mode = .Recording_Initialized
    state.rr_element = element
}

state_initialize_ts_replaying :: proc(state : ^State, element : TS_Element) -> bool {
    if state.ts_mode != .Reading_From_State {
        fail(state, "can't initialize replaying when we are in %v state", state.ts_mode)
    }
    rr := state_peek_recorded_read_state(state)
    if rr.element == element {
        state.ts_mode = .Replaying_Initialized
        state.rr_element = element
        return true
    }
    return false
}

state_peek_recorded_read_state :: proc(state : ^State) -> ^Recorded_Read_State {
    if len(state.recorded_read_states) > 0 {
        idx := len(state.recorded_read_states) - 1
        return &state.recorded_read_states[idx]
    }
    return &nil_recorded_read_state
}

state_pop_recorded_read_state :: proc(state : ^State) {
    _, _ = pop_safe(&state.recorded_read_states)
}

Scope_Event :: enum {
    Just_Entered,
    About_To_Switch_To_Child,
    Just_Returned_From_Child,
    About_To_Leave,
}

state_handle_scope_event :: proc(state : ^State, event : Scope_Event) {
    ts_scope := state.ts_inner_scope
    ts_scope.current_event = event
    fmt.eprintfln("element %v, state %d, event %v, child %v", ts_scope.element, ts_scope.element_state, ts_scope.current_event, ts_scope.child_element)
    #partial switch ts_scope.element {
    case .Nil_Element:
        #partial switch event {
        case .About_To_Switch_To_Child:
            if ts_scope.element_state != 0 {
                fail(state, "more than one toplevel scope")
            }
            ts_scope.element_state = 1
        case .Just_Returned_From_Child:
            if ts_scope.element_state != 1 {
                fail(state, "should not happen")
            }
            ts_scope.element_state = 2
        }
    case .Assign_Statement:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Assign_Statement)
        case .Just_Returned_From_Child:
            #partial switch ts_scope.child_element {
            case .Lhs_Expressions:
                state_expect_ts_element_open(state, .Op)
                state_expect_od_token(state, "op")
                state_expect_ts_element_close(state, .Op)
            }
        case .About_To_Leave:
            state_expect_od_element_close(state, .Assign_Statement)
        }
    case .Attributes:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Attribute)
            // ignore column, the @ token is a part of
            // .Attribute_Statement
            state_expect_od_token(state, "token", range_check_ignore = {.Column})
            if state_maybe_expect_od_token_string(state, "open", "(") {
                ts_scope.element_state = 1
            }
            state_expect_od_element_sub_open(state, "elems")
            state_expect_od_array_begin(state)
        case .About_To_Leave:
            state_expect_od_array_end(state)
            state_expect_od_element_sub_close(state, "elems")
            if ts_scope.element_state == 1 {
                state_expect_od_token_string(state, "close", ")")
            }
            state_expect_od_element_close(state, .Attribute)
        }
    case .Attribute_Statement:
        #partial switch event {
        case .Just_Entered:
            state_initialize_ts_recording(state, .Attributes)
        }
    case .Attribute:
        // nothing to do
    case .Binary_Expression:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Binary_Expression)
            state_expect_od_element_sub_open(state, "left")
            ts_scope.element_state = 1
        case .Just_Returned_From_Child:
            switch ts_scope.element_state {
            case 1:
                ts_scope.element_state = 2
                state_expect_od_element_sub_close(state, "left")
                state_expect_ts_element_open(state, .Op)
                state_expect_od_token(state, "op")
                state_expect_ts_element_close(state, .Op)
                state_expect_od_element_sub_open(state, "right")
            case 2:
                state_expect_od_element_sub_close(state, "right")
                ts_scope.element_state = 3
            case:
                fail(state, "unexpected binary expression state %d", ts_scope.element_state)
            }
        case .About_To_Leave:
            state_expect_od_element_close(state, .Binary_Expression)
        }
    case .Bit_Set_Type:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Bit_Set_Type)
            state_expect_od_token(state, "token")
            state_expect_od_element_sub_open(state, "elem")
            ts_scope.element_state = 1
        case .Just_Returned_From_Child:
            switch ts_scope.element_state {
            case 1:
                ts_scope.element_state = 2
                state_expect_od_element_sub_close(state, "elem")
                if state_maybe_expect_od_element_sub_open(state, "underlying") {
                    ts_scope.element_state = 3
                }
            case 2:
                // nothing to do
            case 3:
                state_expect_od_element_sub_close(state, "underlying")
                ts_scope.element_state = 4
            case:
                fail(state, "unexpected bit set type state %d", ts_scope.element_state)
            }
        case .About_To_Leave:
            state_expect_od_element_close(state, .Bit_Set_Type)
        }
    case .Block_Statement:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Block_Statement)
            state_expect_od_token(state, "open")
            state_expect_od_element_sub_open(state, "stmts")
            state_expect_od_array_begin(state)
        case .About_To_Leave:
            state_expect_od_array_end(state)
            state_expect_od_element_sub_close(state, "stmts")
            state_expect_od_token_string(state, "close", "}")
            state_expect_od_element_close(state, .Block_Statement)
        }
    case .Call_Atom_Expression, .Instantiated_Type:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Call_Expression)
            state_expect_od_element_sub_open(state, "proc")
            ts_scope.element_state = 1
            if ts_scope.element == .Directive_Call {
                if !state_is_od_element_sub_next(state, "basic-directive") {
                    fail(state, "expected basic directive as a proc for directive call, got %v", "(TODO: get next OD element)")
                }
            }
        case .Just_Returned_From_Child:
            switch ts_scope.element_state {
            case 1:
                state_expect_od_element_sub_close(state, "proc")
                state_expect_od_token_string(state, "open", "(")
                state_expect_od_element_sub_open(state, "args")
                state_expect_od_array_begin(state)
                ts_scope.element_state = 2
            case 2:
                // Call args are within call expression scope, so we
                // are probing for a closing parenthesis of "args". If
                // there is not one, next arg will come.
                if state_maybe_expect_od_array_end(state) {
                    state_expect_od_element_sub_close(state, "args")
                    state_expect_od_token_string(state, "close", ")")
                    ts_scope.element_state = 3
                }
            case:
                fail(state, "unexpected call atom expression state %d", ts_scope.element_state)
            }
        case .About_To_Leave:
            state_expect_od_element_close(state, .Call_Expression)
        }
    case .Calling_Convention:
        // already handled by procedure type
        /*#partial switch event {
        case .Just_Entered:
            state_expect_od_element_sub_open(state, "calling_convention")
            _, _ = state_assert_next_od_token(state, .String, -1, "calling convention string")
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "calling_convention")
        }*/
    case .Const_Declaration:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Value_Declaration)
            state_skip_od_docs(state, "docs")
            if state_initialize_ts_replaying(state, .Attributes) {
                state_expect_od_element_sub_open(state, "attributes")
                state_expect_od_array_begin(state)
                ts_scope.element_state = 1
            } else {
            }
        case .Just_Returned_From_Child:
            if ts_scope.element_state == 1 {
                ts_scope.element_state = 2
                state_expect_od_array_end(state)
                state_expect_od_element_sub_close(state, "attributes")
            }
        case .About_To_Leave:
            state_skip_od_docs(state, "comment")
            state_expect_od_element_close(state, .Value_Declaration)
        }
    case .Comment:
        // just ignore it
    case .Context:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Implicit)
            state_expect_od_token(state, "token")
        case .About_To_Leave:
            state_expect_od_element_close(state, .Implicit)
        }
    case .Default_Value:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_sub_open(state, "default_value")
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "default_value")
        }
    case .Defer_Statement:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Defer_Statement)
            state_expect_od_token(state, "token")
            state_expect_od_element_sub_open(state, "stmt")
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "stmt")
            state_expect_od_element_close(state, .Defer_Statement)
        }
    case .Directive:
        #partial switch event {
        case .Just_Entered:
            if state_maybe_expect_od_element_open(state, .Basic_Directive) {
                state_expect_od_token(state, "token")
            } else {
                fail(state, "TODO: handle non-basic-directive directives");
            }
        case .About_To_Leave:
            if ts_scope.element_state == 0 {
                state_expect_od_element_close(state, .Basic_Directive)
            }
        }
    case .Directive_Call:
        #partial switch event {
        case .Just_Entered:
            if state_maybe_expect_od_element_open(state, .Call_Expression) {
                state_expect_od_element_sub_open(state, "proc")
                ts_scope.element_state = 10

            } else {
                fail(state, "TODO: handle non-call-expression directive call")
            }
        case .Just_Returned_From_Child:
            switch ts_scope.element_state {
            case 10:
                state_expect_od_element_sub_close(state, "proc")
                state_expect_od_token_string(state, "open", "(")
                state_expect_od_element_sub_open(state, "args")
                state_expect_od_array_begin(state)
                ts_scope.element_state = 11
            case 11:
                // Call args are within directive call scope, so we
                // are probing for a closing parenthesis of "args". If
                // there is not one, next arg will come.
                if state_maybe_expect_od_array_end(state) {
                    state_expect_od_element_sub_close(state, "args")
                    state_expect_od_token_string(state, "close", ")")
                    ts_scope.element_state = 12
                }
            case:
                fail(state, "unexpected call atom expression state %d", ts_scope.element_state)
            }
        case .About_To_Leave:
            switch ts_scope.element_state {
            case 10..<20:
                state_expect_od_element_close(state, .Call_Expression)
            }
        }
    case .Directive_Name:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_token(state, "name")
        }
    case .Directive_Statement:
        // nothing to do, we will handle specific statements
    // TODO: directive_with_type, record the directive, and replay it at array type
    case .Distinct_Type:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Distinct_Type)
            state_expect_od_token(state, "token")
        case .About_To_Leave:
            state_expect_od_element_close(state, .Distinct_Type)
        }
    case .Dynamic_Array_Type:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Dynamic_Array_Type)
            state_expect_od_token(state, "token")
            state_expect_od_element_sub_open(state, "elem")
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "elem")
            state_expect_od_element_close(state, .Dynamic_Array_Type)
        }
    case .Enum_Field_Entries:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_sub_open(state, "fields")
            state_expect_od_array_begin(state)
        case .About_To_Leave:
            state_expect_od_array_end(state)
            state_expect_od_element_sub_close(state, "fields")
        }
    case .Enum_Field_Entry:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Enum_Field_Value)
            state_expect_od_element_sub_open(state, "name")
        case .Just_Returned_From_Child:
            switch ts_scope.element_state {
            case 0:
                ts_scope.element_state = 1
                state_expect_od_element_sub_close(state, "name")
                if state_maybe_expect_od_element_sub_open(state, "value") {
                    ts_scope.element_state = 2
                }
            }
        case .About_To_Leave:
            if ts_scope.element_state == 2 {
                state_expect_od_element_sub_close(state, "value")
            }
            state_skip_od_docs(state, "comment")
            state_expect_od_element_close(state, .Enum_Field_Value)
        }
    case .Enum_Type:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Enum_Type)
            state_expect_od_token(state, "token")
            state_expect_od_element_sub_open(state, "base_type")
        case .Just_Returned_From_Child:
            switch ts_scope.element_state {
            case 0:
                ts_scope.element_state = 1
                state_expect_od_element_sub_close(state, "base_type")
            }
        case .About_To_Leave:
            state_expect_od_element_close(state, .Enum_Type)
        }
    case .Expression_Statement, .Call_Directive_Statement:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Expression_Statement)
            state_expect_od_element_sub_open(state, "expr")
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "expr")
            state_expect_od_element_close(state, .Expression_Statement)
        }
    case .Field:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Field)
        case .About_To_Leave:
            state_expect_od_element_close(state, .Field)
        }
    case .Field_List:
        if ts_scope.element_state == 100 {
            // a fake struct field list, meh
            #partial switch event {
            case .About_To_Leave:
                state_expect_od_array_end(state)
                state_expect_od_element_sub_close(state, "fields")
            }
            break
        }
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Field_List)
            state_expect_od_token(state, "token")
            state_expect_od_element_sub_open(state, "list")
            state_expect_od_array_begin(state)
        case .About_To_Leave:
            state_expect_od_array_end(state)
            state_expect_od_element_sub_close(state, "list")
            state_expect_od_element_close(state, .Field_List)
        }
    case .Fixed_Array_Type:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Array_Type)
            state_expect_od_token(state, "token")
            state_expect_od_element_sub_open(state, "count")
        case .Just_Returned_From_Child:
            if ts_scope.element_state == 0 {
                ts_scope.element_state = 1
                state_expect_od_element_sub_close(state, "count")
                state_expect_od_element_sub_open(state, "elem")
            }
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "elem")
            state_expect_od_element_close(state, .Array_Type)
        }
    case .Float, .Integer, .Rune, .String:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Basic_Literal)
            state_expect_od_token(state, "token")
        case .About_To_Leave:
            state_expect_od_element_close(state, .Basic_Literal)
        }
    case .For_Cond:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_sub_open(state, "cond")
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "cond")
        }
    case .For_Statement:
        #partial switch event {
        case .Just_Entered:
            if state_maybe_expect_od_element_open(state, .For_Statement) {
                // TODO: label
                state_expect_od_token(state, "token")
                ts_scope.element_state = 0
            } else if state_maybe_expect_od_element_open(state, .Range_Statement) {
                fail(state, "TODO: range_statement")
                // TODO: label
                // TODO: reverse
                //state_expect_od_token(state, "token")
                //ts_scope.element_state = 10
            } else if state_maybe_expect_od_element_open(state, .Unroll_Range_Statement) {
                fail(state, "TODO: unroll_range_statement")
                //ts_scope.element_state = 20
            } else {
                fail(state, "unexpected Odin dumper element %v for tree-sitter element %v", "(TODO: get odin dumper element)", ts_scope.element)
            }
        case .About_To_Switch_To_Child:
            switch ts_scope.element_state {
            case 0..<10:
                // for loop
                #partial switch ts_scope.child_element {
                case .Block_Statement, .Do_Statement:
                    ts_scope.element_state = 9
                    state_expect_od_element_sub_open(state, "body")
                }
            case 10..<20:
                // range loop
            case 20..<30:
                // unroll range loop
            case:
                fail(state, "unexpected for statement state %d", ts_scope.element_state)
            }
        case .Just_Returned_From_Child:
            switch ts_scope.element_state {
            case 0..<9, 10..<19, 20..<29:
                // nothing to do
            case 9, 19, 29:
                state_expect_od_element_sub_close(state, "body")
            case:
                fail(state, "unexpected for statement state %d", ts_scope.element_state)
            }
        case .About_To_Leave:
            switch ts_scope.element_state {
            case 0..<10:
                // for loop
                state_expect_od_element_close(state, .For_Statement)
            case 10..<20:
                // range loop
                state_expect_od_element_close(state, .Range_Statement)
            case 20..<30:
                // unroll range loop
                state_expect_od_element_close(state, .Unroll_Range_Statement)
            case:
            fail(state, "unexpected for statement state %d", ts_scope.element_state)
            }
        }
    case .High_Bound:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_sub_open(state, "high")
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "high")
        }
    case .Identifier:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Identifier)
            state_expect_od_token(state, "token")
        case .About_To_Leave:
            state_expect_od_element_close(state, .Identifier)
        }
    case .If_Statement, .When_Statement:
        #partial switch event {
        case .Just_Entered:
            if ts_scope.element == .If_Statement {
                state_expect_od_element_open(state, .If_Statement)
            } else {
                state_expect_od_element_open(state, .When_Statement)
            }
            state_expect_od_token(state, "token")
            state_expect_od_element_sub_open(state, "cond")
            ts_scope.element_state = 1
        case .Just_Returned_From_Child:
            switch ts_scope.element_state {
            case 1:
                ts_scope.element_state = 2
                state_expect_od_element_sub_close(state, "cond")
                state_expect_od_element_sub_open(state, "body")
            case 2:
                ts_scope.element_state = 3
                state_expect_od_element_sub_close(state, "body")
                if state_maybe_expect_od_element_sub_open(state, "else_stmt") {
                    ts_scope.element_state = 4
                }
            case 4:
                ts_scope.element_state = 5
                state_expect_od_element_sub_close(state, "else_stmt")
            case:
                fail(state, "unexpected if statement state %d", ts_scope.element_state)
            }
        case .About_To_Leave:
            if ts_scope.element == .If_Statement {
                state_expect_od_element_close(state, .If_Statement)
            } else {
                state_expect_od_element_close(state, .When_Statement)
            }
        }
    case .Import_Declaration:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Import_Declaration)
            state_expect_od_token(state, "token")
            state_expect_ts_element_open(state, .String)
            state_expect_od_token(state, "relpath")
            state_expect_od_element_close(state, .Import_Declaration)
            state_expect_ts_element_close(state, .String)
        }
    case .Lhs_Expressions:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_sub_open(state, "lhs_exprs")
            state_expect_od_array_begin(state)
        case .About_To_Leave:
            state_expect_od_array_end(state)
            state_expect_od_element_sub_close(state, "lhs_exprs")
        }
    case .Literal_Value_Atom_Expression:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Compound_Literal)
            state_expect_od_element_sub_open(state, "type")
        case .Just_Returned_From_Child:
            if ts_scope.element_state == 0 {
                state_expect_od_element_sub_close(state, "type")
                state_expect_od_token_string(state, "open", "{")
                close_elems_in_child := state_maybe_expect_od_element_sub_open(state, "elems")
                ts_scope.element_state = 1
                state_expect_ts_element_open(state, .Literal_Value)
                if close_elems_in_child {
                    state_expect_od_array_begin(state)
                } else {
                    // this will mean to skip closing elems
                    state.ts_inner_scope.element_state = 100
                }
            }
        case .About_To_Leave:
            // this is handled by .Literal_Value
        }
    case .Literal_Value:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Compound_Literal)
            state_expect_od_token_string(state, "open", "{")
            state_expect_od_element_sub_open(state, "elems")
            state_expect_od_array_begin(state)
        case .About_To_Leave:
            if ts_scope.element_state != 100 {
                state_expect_od_array_end(state)
                state_expect_od_element_sub_close(state, "elems")
            }
            state_expect_od_token_string(state, "close", "}")
            state_expect_od_element_close(state, .Compound_Literal)
        }
    case .Low_Bound:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_sub_open(state, "low")
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "low")
        }
    case .Multiple:
        // TODO: nothing to do, should this be removed?
    case .Names:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_sub_open(state, "names")
            state_expect_od_array_begin(state)
        case .About_To_Leave:
            state_expect_od_array_end(state)
            state_expect_od_element_sub_close(state, "names")
        }
    case .Or_Return_Atom_Expression:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Or_Return_Expression)
            state_expect_od_element_sub_open(state, "expr")
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "expr")
            state_expect_od_token_string(state, "token", "or_return")
            state_expect_od_element_close(state, .Or_Return_Expression)
        }
    case .Package:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Package_Declaration)
            state_skip_od_docs(state, "docs")
            state_expect_od_token(state, "token")
            state_expect_ts_element_open(state, .Package_Name)
            state_expect_od_token(state, "name")
            state_skip_od_docs(state, "comment")
            state_expect_od_element_close(state, .Package_Declaration)
            state_expect_ts_element_close(state, .Package_Name)
        }
    case .Package_Name:
        fail(state, "this should be handled as a part of .Package")
    case .Parameters:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_sub_open(state, "params")
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "params")
        }
    case .Parentheses_Expression:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Parentheses_Expression)
            state_expect_od_token_string(state, "open", "(")
            state_expect_od_element_sub_open(state, "expr")
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "expr")
            state_expect_od_token_string(state, "close", ")")
            state_expect_od_element_close(state, .Parentheses_Expression)
        }
    case .Pointer_Type:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Pointer_Type)
            state_expect_od_token(state, "token")
        case .About_To_Leave:
            state_expect_od_element_close(state, .Pointer_Type)
        }
    case .Poly_Params:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_sub_open(state, "polymorphic_params")
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "polymorphic_params")
        }
    case .Poly_Type:
        #partial switch event {
        case .Just_Entered:
            // if it is not polymorphic_type on OD end, then it will be a typeid, handled separately
            if state_maybe_expect_od_element_open(state, .Polymorphic_Type) {
                state_expect_od_token(state, "token")
                state_expect_od_element_sub_open(state, "type")
                ts_scope.element_state = 1
            }
        case .Just_Returned_From_Child:
            if ts_scope.element_state == 1 {
                state_expect_od_element_sub_close(state, "type")
                ts_scope.element_state = 2
            }
            case .About_To_Leave:
            if ts_scope.element_state > 0 {
                state_expect_od_element_close(state, .Polymorphic_Type)
            }
        }
    case .Procedure_Group:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Procedure_Group)
            state_expect_od_token(state, "token")
            state_expect_od_token_string(state, "open", "{")
            state_expect_od_element_sub_open(state, "args")
            state_expect_od_array_begin(state)
        case .About_To_Leave:
            state_expect_od_array_end(state)
            state_expect_od_element_sub_close(state, "args")
            state_expect_od_token_string(state, "close", "}")
            state_expect_od_element_close(state, .Procedure_Group)
        }
    case .Procedure_Literal:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Procedure_Literal)
        case .Just_Returned_From_Child:
            #partial switch ts_scope.child_element {
            case .Procedure_Type:
                state_expect_od_element_sub_open(state, "body")
            case .Block_Statement:
                state_expect_od_element_sub_close(state, "body")
            }
        case .About_To_Leave:
            state_expect_od_element_close(state, .Procedure_Literal)
        }
    case .Procedure_Results:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_sub_open(state, "results")
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "results")
        }
    case .Procedure_Type:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_sub_open(state, "type")
            state_expect_od_element_open(state, .Procedure_Type)
            state_expect_od_token(state, "token")
            if state_maybe_expect_od_element_sub_open(state, "calling_convention") {
                _ = state_expect_od_string(state)
                state_expect_od_element_sub_close(state, "calling_convention")
            }
            if state_maybe_expect_od_element_sub_open(state, "generic") {
                _ = state_expect_od_string(state)
                state_expect_od_element_sub_close(state, "generic")
            }
        case .Just_Returned_From_Child:
            if ts_scope.child_element == .Calling_Convention {
                if state_maybe_expect_od_element_sub_open(state, "generic") {
                    _ = state_expect_od_string(state)
                    state_expect_od_element_sub_close(state, "generic")
                }
            }
        case .About_To_Leave:
            state_expect_od_element_close(state, .Procedure_Type)
            state_expect_od_element_sub_close(state, "type")
        }
    case .Return_Statement:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Return_Statement)
            state_expect_od_token(state, "token")
            if state_maybe_expect_od_element_sub_open(state, "results") {
                state_expect_od_array_begin(state)
                ts_scope.element_state = 1
            }
        case .About_To_Leave:
            if ts_scope.element_state == 1 {
                state_expect_od_array_end(state)
                state_expect_od_element_sub_close(state, "results")
            }
            state_expect_od_element_close(state, .Return_Statement)
        }
    case .Rhs_Expressions:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_sub_open(state, "rhs_exprs")
            state_expect_od_array_begin(state)
        case .About_To_Leave:
            state_expect_od_array_end(state)
            state_expect_od_element_sub_close(state, "rhs_exprs")
        }
    case .Selector_Atom_Expression:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Selector_Expression)
            state_expect_od_element_sub_open(state, "expr")
            ts_scope.element_state = 1
        case .Just_Returned_From_Child:
            switch ts_scope.element_state {
            case 1:
                ts_scope.element_state = 2
                state_expect_od_element_sub_close(state, "expr")
                state_expect_od_token_string(state, "token", ".")
                state_expect_od_element_sub_open(state, "selector")
            case 2:
                ts_scope.element_state = 3
                state_expect_od_element_sub_close(state, "selector")
            case:
                fail(state, "unexpected selector expression state %d", ts_scope.element_state)
            }
        case .About_To_Leave:
            state_expect_od_element_close(state, .Selector_Expression)
        }
    case .Single_Type:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Field_List)
            state_expect_od_token(state, "token")
            state_expect_od_element_sub_open(state, "list")
            state_expect_od_array_begin(state)
            state_expect_od_element_open(state, .Field)
        case .About_To_Leave:
            state_expect_od_element_close(state, .Field)
            state_expect_od_array_end(state)
            state_expect_od_element_sub_close(state, "list")
            state_expect_od_element_close(state, .Field_List)
        }
    case .Slice_Atom_Expression:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Slice_Expression)
            state_expect_od_element_sub_open(state, "expr")
        case .Just_Returned_From_Child:
            switch ts_scope.element_state {
            case 0:
                state_expect_od_element_sub_close(state, "expr")
                state_expect_od_token_string(state, "open", "[")
                if state_is_od_element_sub_next(state, "low") {
                    ts_scope.element_state = 1
                } else {
                    state_expect_od_token(state, "interval", range_check_ignore = {.Column})
                    ts_scope.element_state = 2
                }
            case 1:
                state_expect_od_token(state, "interval", range_check_ignore = {.Column})
                ts_scope.element_state = 2
            case 2:
                // there was a high bound element, do nothing here
                ts_scope.element_state = 3
            case:
                fail(state, "unexpected slice index expression state %d", ts_scope.element_state)
            }
        case .About_To_Leave:
            state_expect_od_token_string(state, "close", "]")
            state_expect_od_element_close(state, .Slice_Expression)
        }
    case .Slice_Index_Atom_Expression:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Index_Expression)
            state_expect_od_element_sub_open(state, "expr")
        case .Just_Returned_From_Child:
            switch ts_scope.element_state {
            case 0:
                state_expect_od_element_sub_close(state, "expr")
                state_expect_od_token_string(state, "open", "[")
                state_expect_od_element_sub_open(state, "index")
                ts_scope.element_state = 1
            case 1:
                state_expect_od_element_sub_close(state, "index")
                state_expect_od_token_string(state, "close", "]")
                ts_scope.element_state = 2
            case:
                fail(state, "unexpected slice index expression state %d", ts_scope.element_state)
            }
        case .About_To_Leave:
            state_expect_od_element_close(state, .Index_Expression)
        }
    case .Slice_Type:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Array_Type)
            state_expect_od_token(state, "token")
            state_expect_od_element_sub_open(state, "elem")
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "elem")
            state_expect_od_element_close(state, .Array_Type)
        }
    case .Source_File:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Source_File, 1)
            state_expect_od_element_sub_open(state, "version")
            version := state_expect_od_int(state)
            if version != 1 {
                fail(state, "unsupported odin dumper's syntax tree version: %d", version)
            }
            state_expect_od_element_sub_close(state, "version")
            state_expect_od_array_begin(state)
        case .About_To_Leave:
            state_expect_od_array_end(state)
            state_expect_od_element_close(state, .Source_File)
        }
    case .Specialization:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_sub_open(state, "specialization")
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "specialization")
        }
    case .Struct_Type:
        check_field_count := false
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Struct_Type)
            state_expect_od_token(state, "token")
            check_field_count = true
        case .Just_Returned_From_Child:
            check_field_count = true
        case .About_To_Leave:
            state_expect_od_element_close(state, .Struct_Type)
        }
        if check_field_count && state_maybe_expect_od_element_sub_open(state, "field_count") {
            _ = state_expect_od_int(state)
            state_expect_od_element_sub_close(state, "field_count")
            state_expect_ts_element_open(state, .Field_List)
            // a hack to tell .Field_List ts handler that this is
            // kinda sorta fake field list (without token and named
            // "list" array, just goes straight into the array)
            state.ts_inner_scope.element_state = 100
            // this normally would be in .Just_Entered section of
            // .Field_List
            state_expect_od_element_sub_open(state, "fields")
            state_expect_od_array_begin(state)
        }
    case .Ternary_Expression:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Ternary_If_Expression)
            state_expect_od_element_sub_open(state, "x")
            ts_scope.element_state = 1
        case .Just_Returned_From_Child:
            switch ts_scope.element_state {
            case 1:
                ts_scope.element_state = 2
                state_expect_od_element_sub_close(state, "x")
                state_expect_od_element_sub_open(state, "cond")
            case 2:
                ts_scope.element_state = 3
                state_expect_od_element_sub_close(state, "cond")
                state_expect_od_element_sub_open(state, "y")
            case 3:
                ts_scope.element_state = 4
                state_expect_od_element_sub_close(state, "y")
            case:
                fail(state, "unexpected ternary statement state %d", ts_scope.element_state)
            }
        case .About_To_Leave:
            state_expect_od_element_close(state, .Ternary_If_Expression)
        }
    case .Type:
        #partial switch event {
        case .Just_Entered:
            if state_maybe_expect_od_element_sub_open(state, "type") {
                ts_scope.element_state = 1
            }
        case .About_To_Leave:
            if ts_scope.element_state == 1 {
                state_expect_od_element_sub_close(state, "type")
            }
        }
    case .Typeid:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Typeid)
            state_expect_od_token(state, "token")
        case .About_To_Leave:
            state_expect_od_element_close(state, .Typeid)
        }
    case .Unary_Expression:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Unary_Expression)
            state_expect_ts_element_open(state, .Op)
            state_expect_od_token(state, "op")
            state_expect_ts_element_close(state, .Op)
            state_expect_od_element_sub_open(state, "expr")
        case .About_To_Leave:
            state_expect_od_element_sub_close(state, "expr")
            state_expect_od_element_close(state, .Unary_Expression)
        }
    case .Values:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_sub_open(state, "values")
            state_expect_od_array_begin(state)
        case .About_To_Leave:
            state_expect_od_array_end(state)
            state_expect_od_element_sub_close(state, "values")
        }
    case .Var_Declaration:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_element_open(state, .Value_Declaration)
            state_skip_od_docs(state, "docs")
            if state_initialize_ts_replaying(state, .Attributes) {
                state_expect_od_element_sub_open(state, "attributes")
                state_expect_od_array_begin(state)
                ts_scope.element_state = 1
            } else {
            }
        case .About_To_Switch_To_Child:
            if ts_scope.child_element == .Values {
                ts_scope.element_state = 2
                state_expect_od_element_sub_open(state, "is_mutable")
                s := state_expect_od_string(state)
                state_assert_od_token(state, "true", s, "is_mutable value")
                state_expect_od_element_sub_close(state, "is_mutable")
            }
        case .Just_Returned_From_Child:
            if ts_scope.element_state == 1 {
                ts_scope.element_state = 3
                state_expect_od_array_end(state)
                state_expect_od_element_sub_close(state, "attributes")
            }
        case .About_To_Leave:
            if ts_scope.element_state != 2 {
                state_expect_od_element_sub_open(state, "is_mutable")
                s := state_expect_od_string(state)
                state_assert_od_token(state, "true", s, "is_mutable value")
                state_expect_od_element_sub_close(state, "is_mutable")
            }
            state_skip_od_docs(state, "comment")
            state_expect_od_element_close(state, .Value_Declaration)
        }
    case .Where_Clauses:
        #partial switch event {
        case .Just_Entered:
            state_expect_od_token(state, "where_token")
            state_expect_od_element_sub_open(state, "where_clauses")
            state_expect_od_array_begin(state)
        case .About_To_Leave:
            state_expect_od_array_end(state)
            state_expect_od_element_sub_close(state, "where_clauses")
        }
    case:
        fail(state, "unhandled tree-sitter AST %v", state.ts_inner_scope.element)
    }
}

// TODO: check if the events are still going as they should with the
// recording and replaying stuff
//
// TODO: allow recording and replaying on just entered only?
state_loop :: proc(state : ^State) {
    for {
        fmt.eprintfln("we are now in mode %v", state.ts_mode)
        switch state.ts_mode {
        case .Reading_From_State:
            ts_scope_item := state_next_ts_scope_item(state)
            switch ts_scope_item.type {
            case .Done:
                od_tok, _ := sexpat_next_token(&state.od)
                if od_tok.type != .EOF {
                    fail(state, "there is more data in Odin dumper's output, got %v", od_tok.type)
                }
                return
            case .Open_Scope:
                ts_scope_item = state_next_ts_scope_item(state)
                if ts_scope_item.type != .AST {
                    fail(state, "expected an AST, not %v", ts_scope_item.type)
                }
                state.ts_inner_scope.child_element = ts_scope_item.element
                state_handle_scope_event(state, .About_To_Switch_To_Child)
                state_push_ts_scope(state, ts_scope_item.nesting)
                state.ts_inner_scope.element = ts_scope_item.element
                state.ts_inner_scope.range = ts_scope_item.range
                state_handle_scope_event(state, .Just_Entered)
            case .Close_Scope:
                state_handle_scope_event(state, .About_To_Leave)
                state_pop_ts_scope(state)
                state_handle_scope_event(state, .Just_Returned_From_Child)
            case .AST:
                fail(state, "expected either an opening of a scope or closing, got AST")
            }
        case .Recording_Initialized:
            if _, err := append(&state.recorded_read_states, Recorded_Read_State{}); err != nil {
                fail(state, "failed to append recorded read state: %v", err)
            }
            recorded_read_state := state_peek_recorded_read_state(state)
            recorded_read_state.element = state.rr_element
            recorded_read_state.begin = state.ts.read_state
            ts_scope_item := state_next_ts_scope_item(state)
            if ts_scope_item.type != .Open_Scope {
                fail(state, "expected opening scope of %v element for initializing recording of read state, %v", ts_scope_item.type)
            }
            state.recorded_read_state_opened_scopes = 1
            ts_scope_item = state_next_ts_scope_item(state)
            if ts_scope_item.type != .AST {
                fail(state, "expected an AST after opening scope for initializing recording of read state, not %v", ts_scope_item.type)
            }
            state.ts_mode = .Recording_Ongoing
        case .Recording_Ongoing:
            ts_scope_item := state_next_ts_scope_item(state)
            switch ts_scope_item.type {
            case .Done:
                fail(state, "expected %v element for ongoing recording of read state, got end of the file", state.rr_element)
            case .Open_Scope:
                state.recorded_read_state_opened_scopes += 1
                ts_scope_item = state_next_ts_scope_item(state)
                if ts_scope_item.type != .AST {
                    fail(state, "expected an AST after opening scope for ongoing recording of read state, not %v", ts_scope_item.type)
                }
            case .Close_Scope:
                state.recorded_read_state_opened_scopes -= 1
                if state.recorded_read_state_opened_scopes == 0 {
                    recorded_read_state := state_peek_recorded_read_state(state)
                    recorded_read_state.end = state.ts.read_state
                    state.ts_mode = .Reading_From_State
                    state.rr_element = .Nil_Element
                }
            case .AST:
                fail(state, "opening or closing of scope for ongoing recording of read state, got AST")
            }
        case .Replaying_Initialized:
            recorded_read_state := state_peek_recorded_read_state(state)
            if recorded_read_state.element == .Nil_Element {
                fail(state, "no recorded read states at all")
            }
            if recorded_read_state.element != state.rr_element {
                fail(state, "expected last recorded read state to be for %v, is for %v", state.rr_element, recorded_read_state.element)
            }
            state.saved_ts_read_state = state.ts.read_state
            state.ts.read_state = recorded_read_state.begin
            ts_scope_item := state_next_ts_scope_item(state)
            if ts_scope_item.type != .Open_Scope {
                fail(state, "expected replay to begin with open scope, starts with %v", ts_scope_item.type)
            }
            ts_scope_item = state_next_ts_scope_item(state)
            if ts_scope_item.type != .AST {
                fail(state, "expected an AST when replaying, not %v", ts_scope_item.type)
            }
            state.ts_inner_scope.child_element = ts_scope_item.element
            state_handle_scope_event(state, .About_To_Switch_To_Child)
            state_push_ts_scope(state, ts_scope_item.nesting)
            state.ts_inner_scope.element = ts_scope_item.element
            state.ts_inner_scope.range = ts_scope_item.range
            state_handle_scope_event(state, .Just_Entered)
            state.ts_mode = .Replaying_Ongoing
        case .Replaying_Ongoing:
            ts_scope_item := state_next_ts_scope_item(state)
            switch ts_scope_item.type {
            case .Done:
                od_tok, _ := sexpat_next_token(&state.od)
                if od_tok.type != .EOF {
                    fail(state, "there is more data in Odin dumper's output, got %v", od_tok.type)
                }
                return
            case .Open_Scope:
                ts_scope_item = state_next_ts_scope_item(state)
                if ts_scope_item.type != .AST {
                    fail(state, "expected an AST, not %v", ts_scope_item.type)
                }
                state.ts_inner_scope.child_element = ts_scope_item.element
                state_handle_scope_event(state, .About_To_Switch_To_Child)
                state_push_ts_scope(state, ts_scope_item.nesting)
                state.ts_inner_scope.element = ts_scope_item.element
                state.ts_inner_scope.range = ts_scope_item.range
                state_handle_scope_event(state, .Just_Entered)
            case .Close_Scope:
                state_handle_scope_event(state, .About_To_Leave)
                state_pop_ts_scope(state)
                recorded_read_state := state_peek_recorded_read_state(state)
                if recorded_read_state.end == state.ts.read_state {
                    state_pop_recorded_read_state(state)
                    recorded_read_state = state_peek_recorded_read_state(state)
                    if recorded_read_state.element == state.rr_element {
                        state.ts.read_state = recorded_read_state.begin
                        state.ts_mode = .Replaying_Initialized
                    } else {
                        state.ts.read_state = state.saved_ts_read_state
                        state.ts_mode = .Reading_From_State
                    }
                }
                state_handle_scope_event(state, .Just_Returned_From_Child)
            case .AST:
                fail(state, "expected either an opening of a scope or closing, got AST")
            }
        }
    }
}

main :: proc() {
    state : State
    {
        opts : Options
        flags.parse_or_exit(&opts, os.args, .Unix)
        state_init(&state, &opts)
        os.close(opts.tree_sitter_ast)
        os.close(opts.odin_dumper_ast)
    }
    defer state_destroy(&state)

    state_loop(&state)
}
