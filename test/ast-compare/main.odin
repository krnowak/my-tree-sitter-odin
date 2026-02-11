package ac

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

sexpat_init :: proc(s : ^Sexpat, file: ^os.File) {
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

is_symbol_rune :: proc(r : rune) -> bool {
    switch r {
    case 'a'..='z', 'A'..='Z', '0'..='9', '-', '_':
        return true
    }
    return false
}

is_number_rune :: proc(r : rune) -> bool {
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
        in_matching_set = is_number_rune
    case:
        tok.type = .Symbol
        token_mode = .Matching_Set
        in_matching_set = is_symbol_rune
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

fill_ts_range :: proc(state : ^State, range : ^TS_Range) {
    fill_ts_location(state, &range.begin)
    _, _ = next_ts_token_assert(state, .Dash, -1, "between tree sitter locations in tree-sitter range")
    fill_ts_location(state, &range.end)
}

fill_ts_location :: proc(state : ^State, location : ^TS_Location) {
    _, _ = next_ts_token_assert(state, .Open_Bracket, -1, "opening tree-sitter location")
    tok, _ := next_ts_token_assert(state, .Number, -1, "tree-sitter location line")
    ok : bool
    location.line, ok = strconv.parse_int(tok.string, 10)
    if !ok {
        fail(state, "%s is not a number for line", tok.string)
    }
    _, _ = next_ts_token_assert(state, .Comma, -1, "between tree-sitter line and column")
    tok, _ = next_ts_token_assert(state, .Number, -1, "tree-sitter location column")
    location.column, ok = strconv.parse_int(tok.string, 10)
    if !ok {
        fail(state, "%s is not a number for column", tok.string)
    }
    _, _ = next_ts_token_assert(state, .Close_Bracket, -1, "closing tree-sitter location")
    // make them 1-based
    location.line += 1
    location.column += 1
}

TS_Scope :: struct {
    nesting : int,
    element : TS_Element,
    element_state : int,
    range : TS_Range,
}

OD_Scope :: struct {
    nesting : int,
    element : Maybe(OD_Element),
    string : string,
    ts_element : TS_Element,
}

State :: struct {
    od, ts: Sexpat,
    str_to_od : map[string]OD_Element,
    str_to_ts : map[string]TS_Element,
    ts_scopes : [dynamic]TS_Scope,
    od_scopes : [dynamic]OD_Scope,
    ts_inner_scope : ^TS_Scope,
    od_inner_scope : ^OD_Scope,
}

state_init :: proc(state : ^State, opts : ^Options) {
    sexpat_init(&state.od, opts.odin_dumper_ast)
    sexpat_init(&state.ts, opts.tree_sitter_ast)
    state.str_to_od = make_od_elements_map()
    state.str_to_ts = make_ts_elements_map()
    // TODO: figure out a good enough capacity to avoid grows in most cases
    state.ts_scopes = make([dynamic]TS_Scope, 0, 50)
    state.od_scopes = make([dynamic]OD_Scope, 0, 50)
    n, err := append_nothing(&state.ts_scopes)
    if n == 0 || err != nil {
        fail("could not add empty tree-sitter scope: %v", err)
    }
    n, err = append_nothing(&state.od_scopes)
    if n == 0 || err != nil {
        fail("could not add empty Odin dumper scope: %v", err)
    }
    state.ts_inner_scope = &state.ts_scopes[0]
    state.od_inner_scope = &state.od_scopes[0]
}

state_destroy :: proc(state : ^State) {
    delete(state.od_scopes)
    delete(state.ts_scopes)
    delete(state.str_to_ts)
    delete(state.str_to_od)
    sexpat_destroy(&state.ts)
    sexpat_destroy(&state.od)
}

fail_no_state :: proc(format : string, args : ..any) -> ! {
    fmt.eprintf("FAIL: ", flush=false)
    fmt.eprintfln(format, ..args)
    os.exit(1)
}

fail_with_state :: proc(state : ^State, format : string, args : ..any) -> ! {
    tsrs := state.ts.read_state
    odrs := state.od.read_state
    fmt.eprintf("FAIL (ts: [l: %d, c: %d], od: [l: %d, c: %d]): ", tsrs.line, tsrs.column, odrs.line, odrs.column, flush=false)
    fmt.eprintfln(format, ..args)
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

ts_next_scope_item :: proc(state : ^State) -> (item : TS_Scope_Item) {
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
            fail(state, "unexpected tree sitter element received: %s", tok.string)
        }
        item.element = ts_e
        fill_ts_range(state, &item.range)
    case .Open_Bracket, .Close_Bracket, .Comma, .Dash, .Number, .String, .Garbage:
        fail(state, "unexpected tree-sitter sexp token when getting next scope item, expected a EOF or open paren or close paren or a symbol, got %v", tok.type)
    case:
        fail(state, "aieee!")
    }
    item.nesting = nesting
    return
}

push_ts_scope :: proc(state : ^State, nesting : int) {
    idx := len(state.ts_scopes)
    n, err := append(&state.ts_scopes, TS_Scope {
        nesting = nesting,
    })
    if n == 0 || err != nil {
        fail(state, "could not append tree-sitter scope: %v", err)
    }
    state.ts_inner_scope = &state.ts_scopes[idx]
}

pop_ts_scope :: proc(state : ^State) {
    if len(state.ts_scopes) < 2 {
        fail(state, "no tree-sitter scopes to pop")
    }
    pop(&state.ts_scopes)
    state.ts_inner_scope = &state.ts_scopes[len(state.ts_scopes) - 1]
}

od_expect_open :: proc(state : ^State, element : OD_Element, expected_nesting : int = -1) {
    expected_nesting := fix_od_expected_nesting(state, expected_nesting, "open scope")
    _, _ = next_od_token_assert(state, .Open_Paren, expected_nesting, "open scope")
    tok, nesting := next_od_token_assert(state, .Symbol, expected_nesting, "open scope symbol")
    od_element, ok := state.str_to_od[tok.string]
    if !ok {
        fail(state, "unexpected Odin dumper element received: %s", tok.string)
    }
    if element != od_element {
        fail(state, "syntax tree mismatch, for tree-sitter's %v we expected odin dumper's %v, got %v", state.ts_inner_scope.element, element, od_element)
    }
    push_od_scope(state, nesting)
    state.od_inner_scope.ts_element = state.ts_inner_scope.element
    state.od_inner_scope.element = element
    state.od_inner_scope.string = tok.string
}

push_od_scope :: proc(state : ^State, nesting : int) {
    idx := len(state.od_scopes)
    n, err := append(&state.od_scopes, OD_Scope {
        nesting = nesting,
    })
    if n == 0 || err != nil {
        fail(state, "could not append Odin dumper scope: %v", err)
    }
    state.od_inner_scope = &state.od_scopes[idx]
}

od_expect_open_sub :: proc(state : ^State, name : string, expected_nesting : int = -1) {
    expected_nesting := fix_od_expected_nesting(state, expected_nesting, "open sub scope")
    _, _ = next_od_token_assert(state, .Open_Paren, expected_nesting, "open sub scope")
    tok, nesting := next_od_token_assert(state, .Symbol, expected_nesting, "open sub scope symbol")
    if tok.string != name {
        fail(state, "syntax tree mismatch, inside Odin dumper's %v we expected %s, got %s", state.od_inner_scope.element, name, tok.string)
    }
    push_od_scope(state, nesting)
    state.od_inner_scope.ts_element = state.od_inner_scope.ts_element
    state.od_inner_scope.string = tok.string
}

od_expect_int :: proc(state : ^State) -> int {
    tok, _ := next_od_token_assert(state, .Number)
    n, ok := strconv.parse_int(tok.string, 10)
    if !ok {
        fail(state, "%s is not a valid number", tok.string)
    }
    return n
}

od_expect_close_sub :: proc(state : ^State, name : string) {
    tok, nesting := next_od_token_assert(state, .Close_Paren, state.od_inner_scope.nesting, "close sub scope")
    if state.od_inner_scope.string != name {
        fail(state, "mismatch in name of Odin dumper's closing sub scope, expected %s, innermost scope has %s", name, state.od_inner_scope.string)
    }
    pop_od_scope(state)
}

pop_od_scope :: proc(state : ^State) {
    if len(state.od_scopes) < 2 {
        fail(state, "no Odin dumper scopes to pop")
    }
    pop(&state.od_scopes)
    state.od_inner_scope = &state.od_scopes[len(state.od_scopes) - 1]
}

od_expect_array_begin :: proc(state : ^State, expected_nesting : int = -1) {
    expected_nesting := fix_od_expected_nesting(state, expected_nesting, "open array")
    _, nesting := next_od_token_assert(state, .Open_Paren, expected_nesting, "open array")
    push_od_scope(state, nesting)
    state.od_inner_scope.ts_element = state.od_inner_scope.ts_element
}

skip_od_id :: proc(state : ^State, expected_nesting : int = -1) {
    expected_nesting := fix_od_expected_nesting(state, expected_nesting, "id")
    _, _ = next_od_token_assert(state, .Open_Paren, expected_nesting, "open id")
    tok, _ := next_od_token_assert(state, .Symbol, expected_nesting, "id symbol")
    assert_od_tok_string(state, "id", tok.string, "id symbol")
    _, _ = next_od_token_assert(state, .Number, expected_nesting, "id number")
    _, _ = next_od_token_assert(state, .Close_Paren, expected_nesting, "close id")
}

assert_od_tok_string :: proc(state : ^State, expected, got : string, desc : string = "") {
    if expected != got {
        if len(desc) > 0 {
            fail(state, "expected %s in Odin dumper's output, got %s (%s)", expected, got, desc)
        } else {
            fail(state, "expected %s in Odin dumper's output, got %s", expected, got)
        }
    }
}

fix_od_expected_nesting :: proc(state : ^State, expected_nesting : int, desc : string = "") -> int {
    if expected_nesting < 0 {
        if state.od_inner_scope.nesting == 0 {
            if len(desc) > 0 {
                fail(state, "no Odin dumper inner scope available for next expected nesting (%s)", desc)
            } else {
                fail(state, "no Odin dumper inner scope available for next expected nesting")
            }
        }
        return state.od_inner_scope.nesting + 1
    }
    return expected_nesting
}

od_expect_token :: proc(state : ^State, name : string, expected_nesting : int = -1) {
    expected_nesting := fix_od_expected_nesting(state, expected_nesting, "token")
    _, _ = next_od_token_assert(state, .Open_Paren, expected_nesting, "open token")
    tok, _ := next_od_token_assert(state, .Symbol, expected_nesting, "token name")
    assert_od_tok_string(state, name, tok.string, "token name")
    _, _ = next_od_token_assert(state, .Open_Paren, expected_nesting + 1, "open token contents")
    tok, _ = next_od_token_assert(state, .Symbol, expected_nesting + 1, "token keyword")
    assert_od_tok_string(state, "token", tok.string, "token name")
    _, _ = next_od_token_assert(state, .Open_Paren, expected_nesting + 2, "open token string")
    tok, _ = next_od_token_assert(state, .Symbol, expected_nesting + 2, "token string keyword")
    assert_od_tok_string(state, "string", tok.string, "token string keyword")
    // probably there's no point in getting the string based on ts
    // ranges - as long the ts range and od line and column agree, we
    // can be sure that the token refers to the same string
    _, _ = next_od_token_assert(state, .String, expected_nesting + 2, "token string")
    _, _ = next_od_token_assert(state, .Close_Paren, expected_nesting + 2, "close token string")
    _ = expect_od_symbol_number(state, "offset", expected_nesting + 2)
    line := expect_od_symbol_number(state, "line", expected_nesting + 2)
    column := expect_od_symbol_number(state, "column", expected_nesting + 2)
    _, _ = next_od_token_assert(state, .Close_Paren, expected_nesting + 1, "close token contents")
    _, _ = next_od_token_assert(state, .Close_Paren, expected_nesting, "close token")
    if line != state.ts_inner_scope.range.begin.line {
        fail(state, "unexpected location of the %q string, expected line %d, got %d", tok.string, line, state.ts_inner_scope.range.begin.line)
    }
    if column != state.ts_inner_scope.range.begin.column {
        fail(state, "unexpected location of the %q string, expected column %d, got %d", tok.string, column, state.ts_inner_scope.range.begin.column)
    }
}

expect_od_symbol_number :: proc(state : ^State, name : string, expected_nesting : int = -1) -> int {
    expected_nesting := fix_od_expected_nesting(state, expected_nesting, "symbol number pair")
    _, _ = next_od_token_assert(state, .Open_Paren, expected_nesting, "open symbol number pair")
    tok, _ := next_od_token_assert(state, .Symbol, expected_nesting, "symbol name")
    assert_od_tok_string(state, name, tok.string, "symbol name")
    tok, _ = next_od_token_assert(state, .Number, expected_nesting, "id number")
    number, ok := strconv.parse_int(tok.string, 10)
    if !ok {
        fail(state, "%s is not a number in symbol number pair", tok.string)
    }
    _, _ = next_od_token_assert(state, .Close_Paren, expected_nesting, "close symbol number pair")
    return number
}

Sexpat_Source :: enum {
    Odin_Dumper,
    Tree_Sitter,
}

next_ts_token_assert :: proc(state : ^State, expected_type : Sexpat_Token_Type, expected_nesting : int = -1, desc : string = "") -> (tok : Sexpat_Token, nesting : int) {
    tok, nesting = sexpat_next_token(&state.ts)
    assert_token(state, .Tree_Sitter, tok, expected_type, desc)
    assert_nesting(state, .Tree_Sitter, nesting, expected_nesting, desc)
    return
}

next_od_token_assert :: proc(state : ^State, expected_type : Sexpat_Token_Type, expected_nesting : int = -1, desc : string = "") -> (tok : Sexpat_Token, nesting : int) {
    tok, nesting = sexpat_next_token(&state.od)
    assert_token(state, .Odin_Dumper, tok, expected_type, desc)
    assert_nesting(state, .Odin_Dumper, nesting, expected_nesting, desc)
    return
}

assert_token :: proc(state : ^State, source : Sexpat_Source, tok : Sexpat_Token, type : Sexpat_Token_Type, desc : string = "") {
    if tok.type != type {
        if len(desc) > 0 {
            fail(state, "expected %v %v token (%s), got %v", type, source, desc, tok.type);
        } else {
            fail(state, "expected %v %v token, got %v", type, source, tok.type);
        }
    }
}

assert_nesting :: proc(state : ^State, source : Sexpat_Source, got_nesting, expected_nesting : int, desc : string = "") {
    if expected_nesting < 0 || got_nesting == expected_nesting {
        return
    }
    if len(desc) > 0 {
        fail(state, "expected nesting in %v (%s) to be %d, got %d", source, desc, expected_nesting, got_nesting)
    } else {
        fail(state, "expected nesting in %v to be %d, got %d", source, expected_nesting, got_nesting)
    }
}

ts_expect :: proc(state : ^State, expected_element : TS_Element) {
    ts_scope_item := ts_next_scope_item(state)
    if ts_scope_item.type != .Open_Scope {
        fail(state, "expected an opening of tree-sitter scope, got %v", ts_scope_item.type)
    }
    push_ts_scope(state, ts_scope_item.nesting)
    ts_scope_item = ts_next_scope_item(state)
    if ts_scope_item.type != .AST {
        fail(state, "expected a tree-sitter AST, got %v", ts_scope_item.type)
    }
    state.ts_inner_scope.element = ts_scope_item.element
    state.ts_inner_scope.range = ts_scope_item.range
}

od_skip_docs :: proc(state : ^State, name : string) {
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
            _, _ = next_od_token_assert(state, .String, -1, "docs string")
            _, _ = next_od_token_assert(state, .Close_Paren, -1, "docs string close")
        } else if tok.type == .Close_Paren {
            break
        } else {
            fail(state, "expected either open paren or close paren in docs, got %v", tok.type)
        }
    }
    _, _ = next_od_token_assert(state, .Close_Paren, -1, "close docs")
}

od_expect_close :: proc(state : ^State, element : OD_Element) {
    tok, nesting := next_od_token_assert(state, .Close_Paren, state.od_inner_scope.nesting, "close sub scope")
    if state.od_inner_scope.element != element {
        fail(state, "mismatch in name of Odin dumper's closing scope, expected %v, innermost scope has %v", element, state.od_inner_scope.element)
    }
    pop_od_scope(state)
}

state_loop :: proc(state : ^State) {
    for {
        ts_scope_item := ts_next_scope_item(state)
        switch ts_scope_item.type {
        case .Done:
            od_tok, _ := sexpat_next_token(&state.od)
            if od_tok.type != .EOF {
                fail(state, "there is more data in Odin dumper's output")
            }
            return
        case .Open_Scope:
            push_ts_scope(state, ts_scope_item.nesting)
        case .Close_Scope:
            pop_ts_scope(state)
        case .AST:
            state.ts_inner_scope.element = ts_scope_item.element
            state.ts_inner_scope.range = ts_scope_item.range
            #partial switch ts_scope_item.element {
            case .Comment:
                // just ignore it
            case .Source_File:
                od_expect_open(state, .Source_File, 1)
                od_expect_open_sub(state, "version")
                version := od_expect_int(state)
                if version != 1 {
                    fail(state, "unsupported odin dumper's syntax tree version: %d", version)
                }
                od_expect_close_sub(state, "version")
                od_expect_array_begin(state)
            case .Package:
                od_expect_open(state, .Package_Declaration)
                skip_od_id(state)
                od_expect_token(state, "token")
                // expect an open scope followed by given AST
                ts_expect(state, .Package_Name)
                od_expect_token(state, "name")
                od_skip_docs(state, "docs")
                od_skip_docs(state, "comment")
                od_expect_close(state, .Package_Declaration)
            case .Package_Name:
                fail("this should be handled as a part of .Package")
            case .Import_Declaration:
                od_expect_open(state, .Import_Declaration)
                skip_od_id(state)
                od_expect_token(state, "token")
                ts_expect(state, .String)
                od_expect_token(state, "relpath")
                od_expect_close(state, .Import_Declaration)
            case:
                fail(state, "unhandled tree-sitter AST %v", ts_scope_item.element)
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
