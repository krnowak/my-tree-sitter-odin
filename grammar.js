/**
 * @file Odin grammar for tree-sitter
 * @author Krzesimir Nowak <qdlacz@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

// Abbreviations used below:
//
// nfs - no final semicolon
//
// nie - no "in" expression
//
// lhs - left hand side
//
// rhs - right hand side
//
// nlve - no literal value expression
//
// cc - control clause (means - no type literals allowed, uses the
//      nlve stuff)

// file_allow_newline is always true
//
// allow_field_separator returns true if got a comma, or an implicit
// semicolon followed by a closing brace/paren
//
// token_is_newline - implicit semicolon
//
// skip_possible_newline_for_literal - returns true if implicit semicolon was followed by t_openbrace, kw_else or kw_where
//
// parse_control_statement_semicolon_separator - returns true current token is t_semicolon
//
// expr_level:
//
// <0 - "in" and "not_in" not allowed in binary expression, compound literals not allowed in atom expressions (if allow_in_expr is also false)
//
// =0 - "in" and "not_in" allowed in binary expressions, compound literals allowed in atom expressions (if rhs and operand was a literal type)
//
// >0 - implicit semicolons ignored, "in" and "not_in" allowed in binary expressions, compound literals allowed in atom expressions (if rhs and operand was a literal type), "return" not allowed
//
// allow_range - allows range operators (.., ..< and ..=) in binary expressions
//
// allow_in_expr - allows "in" and "not_in" in binary expressions (even if expr_level is <0)
//
// allow_type - used only in parse_type_or_ident, basically allows nil operand and nil atom expressions, and cuts short parsing of procedure type in parse_operand
//
// this cutting short of procedure parsing may be important in cases like:
//
// foo : proc()
// { /* this is just a block, not a proc body */ }
//
// parse_type_or_ident can return nil, this seems to be only valid in parse_value_decl to make type optional in "foo : type [:=] value"
//
// About in and not_in - they are banned in expressions with
// expr_level being less than 0 (like in control statements) and if
// allow_in_expr is false. Or on other way: in and not_in are allowed
// in expressions with expr_level being zero or more, and in control
// expressions which set allow_in_expr to true. But note that above
// was only about in and not_in in expressions, but not about the
// statements - there is a flag (StmtAllowFlag_In) that controls if a
// statement can be an "in" statement.
//
// Currently expr_level being set to -1 exists in:
//
// - where clause of proc type
// - bit_field backing type and fields
// - struct directives and where clauses
// - union where clauses
// - parse_type_or_ident
// - if control statements (both init and cond)
// - when control statement
// - for control statements (all of init, cond and post)
// - switch control statements (type switch, init and tag)
//
// Currently allow_in_expr is set in following places:
//
// - if control statements (both init and cond) to true
// - when control statement to true
// - case clauses to true (not really, but we set it to true)
//
// Currently StmtAllowFlag_In is used in followed places:
//
// - range-based for
// - type switch
//
// Currently allow_range is set up in:
//
// - parse_value to true
// - bit_set elem type to true
// - slice expression, matrix index expression and index expression to false
// - in statement's rhs expression to true
// - case clauses to true (not really, but we set it to true)
//
// Or per item:
// - where clauses (proc, struct and union) - expr_level -1, DONE
// - bit_field fields - expr_level -1, DONE (types?)
// - struct directives - expr_level -1, DONE
// - if control statements - expr_level -1, allow_in_expr true, DONE
// - when control statement - expr_level -1, allow_in_expr true, DONE
// - for control statements - expr_level -1, StmtAllowFlag_In (range for), DONE
// - switch control statements - expr_level -1, StmtAllowFlag_In (type switch), DONE
// - value - allow_range true
// - bit_set elem type - allow_range true
// - slice, matrix index and index expressions - allow_range FALSE
// - "in" statement - allow_range true
// - case clause - allow_in_expr true, allow_range true


// Currently expr_level being -1 and allow_in_expr being set to true
// exist only for "if" and "when".
//
// Currently StmtAllowFlag_In is set for "range for" statements and
// for "type switch" statements.

const ALL_OPERATORS = 0;
const NO_IN_OPERATORS = 1;

module.exports = grammar({
  name : "odin",

  externals : $ => [
    $.invalid,
    // Multi-line comments can be nested, regexp can't handle
    // counting.
    //
    // Multi-line comment also preserves semicolon status in a useful
    // way - you can type a semicolon-inserting-token (like closing
    // bracket), insert a multi-line comment, close it and add a
    // backslash at the end of the line. This can't be done for
    // single-line comments - they will strip the backslash of the
    // special meaning, which means that typing comment after a
    // closing bracket may cause compilation error anyway. To
    // visualize, this compiles fine:
    //
    // M :: matrix[2, 3] /* a comment
    // for multiple
    // lines. */ \
    // f32
    //
    // Whereas there's no chance this will work:
    //
    // M :: matrix[2, 3] // comment eats this backslash -> \
    // f32
    $._ml_comment,
    $._sl_comment,
    // This is a newline or eof serving as a semicolon.
    $._implicit_semicolon,
    // Similar to implicit semicolon, but followed by an empty line.
    $._wide_implicit_semicolon,
    $.identifier,

    // keywords that may add a semicolon
    $._kw_break,
    $._kw_context,
    $._kw_continue,
    $._kw_fallthrough,
    $._kw_or_break,
    $._kw_or_continue,
    $._kw_or_return,
    $._kw_return,
    $._kw_typeid,
    // keywords that do not add a semicolon
    $._kw_asm,
    $._kw_auto_cast,
    $._kw_bit_field,
    $._kw_bit_set,
    $._kw_case,
    $._kw_cast,
    $._kw_defer,
    $._kw_distinct,
    $._kw_do,
    $._kw_dynamic,
    $._kw_else,
    $._kw_enum,
    $._kw_for,
    $._kw_foreign,
    $._kw_if,
    $._kw_import,
    $._kw_in,
    $._kw_map,
    $._kw_matrix,
    $._kw_not_in,
    $._kw_or_else,
    $._kw_package,
    $._kw_proc,
    $._kw_struct,
    $._kw_switch,
    $._kw_transmute,
    $._kw_union,
    $._kw_using,
    $._kw_when,
    $._kw_where,
    // attributes
    $._a_builtin, // nothing
    $._a_cold, // nothing or bool
    $._a_default_calling_convention, // string
    $._a_deferred_in, // identifier
    $._a_deferred_in_by_ptr, // identifier
    $._a_deferred_in_out, // identifier
    $._a_deferred_in_out_by_ptr, // identifier
    $._a_deferred_none, // identifier
    $._a_deferred_out, // identifier
    $._a_deferred_out_by_ptr, // identifier
    $._a_deprecated, // string
    $._a_disabled, // bool
    $._a_enable_target_feature, // string
    $._a_entry_point_only, // nothing
    $._a_export, // nothing or bool
    $._a_extra_linker_flags, // string
    $._a_fini, // nothing
    $._a_ignore_duplicates, // nothing
    $._a_init, // nothing
    $._a_instrumentation_enter, // nothing
    $._a_instrumentation_exit, // nothing
    $._a_linkage, // string
    $._a_link_name, // string
    $._a_link_prefix, // string
    $._a_link_section, // string
    $._a_link_suffix, // string
    $._a_no_instrumentation, // nothing or bool
    $._a_no_sanitize_address, // nothing
    $._a_no_sanitize_memory, // nothing
    $._a_objc_class, // string
    $._a_objc_context_provider, // identifier
    $._a_objc_implement, // nothing or bool
    $._a_objc_is_class_method, // bool
    $._a_objc_ivar, // identifier
    $._a_objc_name, // string
    $._a_objc_selector, // string
    $._a_objc_superclass, // identifier
    $._a_objc_type, // identifier
    $._a_optimization_mode, // string
    $._a_priority_index, // integer
    $._a_private, // nothing or string
    $._a_raddbg_type_view, // nothing or string
    $._a_require, // nothing or bool
    $._a_require_results, // nothing
    $._a_require_target_feature, // string
    $._a_rodata, // nothing
    $._a_static, // nothing
    $._a_tag, // string
    $._a_test, // nothing
    $._a_thread_local, // nothing or string
    // directives
    $._d_align, // call
    $._d_align_stack, // simple
    $._d_all_or_none, // simple
    $._d_any_int, // simple
    $._d_att, // simple
    $._d_assert, // call
    $._d_bounds_check, // simple
    $._d_branch_location, // simple
    $._d_by_ptr, // simple
    $._d_caller_expression, // simple or call
    $._d_caller_location, // simple
    $._d_column_major, // simple
    $._d_config, // call
    $._d_const, // simple
    $._d_c_vararg, // simple
    $._d_defined, // call
    $._d_directory, // simple
    $._d_exists, // call
    $._d_file, // simple
    $._d_force_inline, // simple
    $._d_force_no_inline, // simple
    $._d_hash, // call
    $._d_intel, // simple
    $._d_line, // simple
    $._d_load, // call
    $._d_load_directory, // call
    $._d_load_hash, // call
    $._d_location, // call
    $._d_max_field_align, // call
    $._d_min_field_align, // call
    $._d_must_tail, // simple
    $._d_no_alias, // simple
    $._d_no_bounds_check, // simple
    $._d_no_broadcast, // simple
    $._d_no_nil, // simple
    $._d_no_type_assert, // simple
    $._d_optional_allocator_error, // simple
    $._d_optional_ok, // simple
    $._d_packed, // simple
    $._d_panic, // call
    $._d_partial, // simple
    $._d_procedure, // simple
    $._d_raw_union, // simple
    $._d_reverse, // simple
    $._d_row_major, // simple
    $._d_shared_nil, // simple
    $._d_side_effects, // simple
    $._d_simd, // simple? #simd[N]T
    $._d_simple, // simple
    $._d_soa, // simple? #soa[N]T
    $._d_sparse, // simple? #sparse[Key]T
    $._d_subtype, // simple
    $._d_type, // simple
    $._d_type_assert, // simple
    $._d_unroll, // simple or call
    // other terminals that may add a semicolon
    $.integer,
    $.float,
    $.imag,
    $.rune,
    $.string,
    $._t_question,
    $._t_pointer,
    $._t_closeparen,
    $._t_closebracket,
    $._t_closebrace,
    $._t_not,
    $._t_uninit, // this differs from Odin parser
    // other terminals that do not add a semicolon
    $._t_add,
    $._t_addeq,
    $._t_and,
    $._t_andeq,
    $._t_andnot,
    $._t_andnoteq,
    $._t_arrowright,
    $._t_at,
    $._t_cmpand,
    $._t_cmpandeq,
    $._t_cmpeq,
    $._t_cmpor,
    $._t_cmporeq,
    $._t_colon,
    $._t_comma,
    $._t_dollar,
    $._t_ellipsis,
    $._t_eq,
    $.file_tag,
    $._t_gt,
    $._t_gteq,
    $._t_hash,
    $._t_lt,
    $._t_lteq,
    $._t_mod,
    $._t_modeq,
    $._t_modmod,
    $._t_modmodeq,
    $._t_mul,
    $._t_muleq,
    $._t_noteq,
    $._t_openbrace,
    $._t_openbracket,
    $._t_openparen,
    $._t_or,
    $._t_oreq,
    $._t_period,
    $._t_quo,
    $._t_quoeq,
    $._t_rangefull,
    $._t_rangehalf,
    $._t_semicolon,
    $.shebang,
    $._t_shl,
    $._t_shleq,
    $._t_shr,
    $._t_shreq,
    $._t_sub,
    $._t_subeq,
    $._t_xor,
    $._t_xoreq,
  ],

  extras : $ => [
    '\\\n',
    /[\s]/,
    $.comment,
  ],

  supertypes : $ => [
    $.statement,
    $.rhs_expression,
    $.lhs_expression,
    $.rhs_expression_cc,
    $.lhs_expression_cc,
    $.rhs_expression_cc_nie,
    $.lhs_expression_cc_nie,
    $.atom_expression,
    $.atom_expression_nlve,
    $.rhs_unary_expression,
    $.lhs_unary_expression,
    $.rhs_unary_expression_cc,
    $.lhs_unary_expression_cc,
  ],

  conflicts : $ => [
    //    Unresolved conflict for symbol sequence:
    //
    //      package  identifier  •  _t_comma  …
    //
    //    Possible interpretations:
    //
    //      1:  package  (_identifier_list  identifier  •  _identifier_list_repeat1)
    //      2:  package  (operand  identifier)  •  _t_comma  …
    //
    [$.operand, $._identifier_list],
    //    Unresolved conflict for symbol sequence:
    //
    //      package  inline_directive  •  _implicit_semicolon  …
    //
    //    Possible interpretations:
    //
    //      1:  package  (atom_expression  inline_directive)  •  _implicit_semicolon  …
    //      2:  package  (inline_directive_statement  inline_directive  •  _statement_separator)
    //
    // TODO(krnowak): not sure about this one, whether this should be
    // a conflict or some precedence stuff
    [$.inline_directive_statement, $.atom_expression],
    //    Unresolved conflict for symbol sequence:
    //
    //      package  must_tail_directive  •  _implicit_semicolon  …
    //
    //    Possible interpretations:
    //
    //      1:  package  (atom_expression  must_tail_directive)  •  _implicit_semicolon  …
    //      2:  package  (must_tail_directive_statement  must_tail_directive  •  _statement_separator)
    //
    // TODO(krnowak): not sure about this one, whether this should be
    // a conflict or some precedence stuff
    [$.must_tail_directive_statement, $.atom_expression],
    //    Unresolved conflict for symbol sequence:
    //
    //      package  _kw_for  procedure_type  •  _kw_do  …
    //
    //    Possible interpretations:
    //
    //      1:  package  _kw_for  (operand  procedure_type)  •  _kw_do  …
    //      2:  package  _kw_for  (procedure_literal  procedure_type  •  do_statement)
    //
    [$.operand, $.procedure_literal],
    //    Unresolved conflict for symbol sequence:
    //
    //      package  _kw_if  implicit_selector_expression  •  _kw_if  …
    //
    //    Possible interpretations:
    //
    //      1:  package  _kw_if  (lhs_unary_expression_cc  implicit_selector_expression)  •  _kw_if  …  (precedence: 'unary', associativity: Right)
    //      2:  package  _kw_if  (rhs_unary_expression_cc  implicit_selector_expression)  •  _kw_if  …  (precedence: 'unary', associativity: Right)
    //
    [$.lhs_unary_expression_cc, $.rhs_unary_expression_cc],
    //    Unresolved conflict for symbol sequence:
    //
    //      package  procedure_literal  _t_openparen  identifier  •  _t_closeparen  …
    //
    //    Possible interpretations:
    //
    //      1:  package  procedure_literal  _t_openparen  (_call_arg  identifier)  •  _t_closeparen  …
    //      2:  package  procedure_literal  _t_openparen  (operand  identifier)  •  _t_closeparen  …
    //
    [$.operand, $._call_arg],
    //    Unresolved conflict for symbol sequence:
    //
    //      package  identifier  •  _t_colon  …
    //
    //    Possible interpretations:
    //
    //      1:  package  (_identifier_list  identifier)  •  _t_colon  …
    //      2:  package  (label  identifier  •  _t_colon)
    //
    [$._identifier_list, $.label],
    //    Unresolved conflict for symbol sequence:
    //
    //      package  _kw_proc  _t_openparen  identifier  •  _t_comma  …
    //
    //    Possible interpretations:
    //
    //      1:  package  _kw_proc  _t_openparen  (field  identifier)  •  _t_comma  …
    //      2:  package  _kw_proc  _t_openparen  (type  identifier)  •  _t_comma  …
    //
    [$.type, $.field],
    //    Unresolved conflict for symbol sequence:
    //
    //      package  _kw_struct  _t_openbrace  identifier  •  _t_comma  …
    //
    //    Possible interpretations:
    //
    //      1:  package  _kw_struct  _t_openbrace  (_identifier_list  identifier  •  _identifier_list_repeat1)
    //      2:  package  _kw_struct  _t_openbrace  (type  identifier)  •  _t_comma  …
    //
    [$.type, $._identifier_list],
    //    Unresolved conflict for symbol sequence:
    //
    //      package  _kw_return  _t_hash  _d_partial  _t_openparen  literal_value_atom_expression  •  _t_closeparen  …
    //
    //    Possible interpretations:
    //
    //      1:  package  _kw_return  _t_hash  _d_partial  _t_openparen  (atom_expression  literal_value_atom_expression)  •  _t_closeparen  …      (precedence: 'atom_expression')
    //      2:  package  _kw_return  _t_hash  _d_partial  _t_openparen  (paren_literal_value  literal_value_atom_expression)  •  _t_closeparen  …
    //
    // I don't have a clear idea yet where does the first
    // interpretation come from. Possibly from
    // selector_atom_expression?
    [$.paren_literal_value, $.atom_expression],
    //    Unresolved conflict for symbol sequence:
    //
    //      package  _kw_return  _t_hash  _d_partial  _t_openparen  literal_value  •  _t_closeparen  …
    //
    //    Possible interpretations:
    //
    //      1:  package  _kw_return  _t_hash  _d_partial  _t_openparen  (paren_literal_value  literal_value)  •  _t_closeparen  …
    //      2:  package  _kw_return  _t_hash  _d_partial  _t_openparen  (rhs_unary_expression  literal_value)  •  _t_closeparen  …  (precedence: 'unary', associativity: Right)
    //
    // Same shit as above, God I hate it.
    [$.rhs_unary_expression, $.paren_literal_value]
  ],

  precedences : $ => [
    // for expressions
    [
      'unary',
      'binary',
    ],
    //
    //    Unresolved conflict for symbol sequence:
    //
    //      package  _kw_for  _t_semicolon  •  identifier  …
    //
    //    Possible interpretations:
    //
    //      1:  package  _kw_for  (for_init  _t_semicolon)  •  identifier  …
    //      2:  package  _kw_for  (for_post  _t_semicolon  •  simple_statement_nfs_nlv_nie)  (precedence: 0, associativity: Left)
    //
    [
      'for_init',
      'for_post',
    ],
    //    Unresolved conflict for symbol sequence:
    //
    //      package  _t_hash  _d_force_inline  _t_openparen  call_atom_expression  •  _kw_or_break  …
    //
    //    Possible interpretations:
    //
    //      1:  package  _t_hash  _d_force_inline  _t_openparen  (common_atom_subexpressions  call_atom_expression)  •  _kw_or_break  …
    //      2:  package  _t_hash  _d_force_inline  _t_openparen  (inline_directive_or_branch_expression  call_atom_expression  •  _kw_or_break  identifier)
    //      3:  package  _t_hash  _d_force_inline  _t_openparen  (inline_directive_or_branch_expression  call_atom_expression  •  _kw_or_break)
    //
    // and
    //
    //    Unresolved conflict for symbol sequence:
    //
    //      package  _t_hash  _d_force_inline  _t_openparen  call_atom_expression  •  _t_closeparen  …
    //
    //    Possible interpretations:
    //
    //      1:  package  _t_hash  _d_force_inline  (inline_directive_paren_expression  _t_openparen  call_atom_expression  •  _t_closeparen)
    //      2:  package  _t_hash  _d_force_inline  _t_openparen  (atom_expression  call_atom_expression)  •  _t_closeparen  …
    //
    // krnowak: Yeah, all intepretations in the first conflict start
    // with inline_directive (consumes _t_hash and _d_force_inline)
    // followed by inline_directive_expression, and then they
    // diverge. Intepretation one goes like:
    //
    // call_atom_expression -> common_atom_subexpressions ->
    // parentheses_expression (consumes _t_openparen) ->
    // rhs_expression -> unary_expression -> atom_expression ->
    // call_atom_expression
    //
    // Interpretations two and three go like:
    //
    // inline_directive_paren_expression (consumes _t_openparen) ->
    // call_atom_expression
    //
    // We want to prefer the interpretations two and three, thus we
    // specify the precedences. The second conflict is similar, but
    // with a different rule pair (inline_directive_paren_expression
    // and atom_expression).
    //
    // TODO(krnowak): Possibly treat or_branch expressions (or_return,
    // or_break and or_continue) in a separate way instead of atom
    // expressions. Maybe a part of unary expressions? Then the
    // inline_directive could be something like:
    //
    // seq(
    //   hash,
    //   force_inline,
    //   choice(
    //     those_or_branch_expressions,
    //     call_expression?
    //   ),
    // ),
    [
      'inline_or_branch',
      'atom_expression',
    ],
    //    Unresolved conflict for symbol sequence:
    //
    //      package  directive_call  •  _implicit_semicolon  …
    //
    //    Possible interpretations:
    //
    //      1:  package  (call_directive_statement  directive_call  •  _statement_separator)
    //      2:  package  (operand  directive_call)  •  _implicit_semicolon  …
    //
    // Prefer the statement over the lone operand.
    [
      'call_statement',
      'operand',
    ],
  ],

  rules : {
    source_file : $ => seq(
      optional($.shebang),
      repeat($.file_tag),
      $.package,
      repeat($.statement)
    ),

    package : $ => seq(
      $._kw_package,
      alias($.identifier, $.package_name),
      $._statement_separator,
    ),

    //
    // krnowak: statements
    //

    statement : $ => choice(
      $.assign_statement,
      $.attribute_statement,
      $.block_statement,
      $.break_statement,
      $.const_declaration,
      $.continue_statement,
      $.defer_statement,
      $.directive_statement,
      $.fallthrough_statement,
      $.for_statement,
      $.foreign_block_declaration,
      $.foreign_import_declaration,
      $.if_statement,
      $.import_declaration,
      $.label_statement,
      $.return_statement,
      $.switch_statement,
      $.using_statement,
      $.var_declaration,
      $.when_statement,
      $.expression_statement,
    ),

    // krnowak: assign statement

    assign_statement : $ => seq(
      $._assign_statement_nfs,
      $._statement_separator
    ),

    _assign_statement_nfs : $ => seq(
      $._lhs_expression_list,
      $._assign_operator,
      $._rhs_expression_list,
    ),

    _assign_statement_nfs_cc : $ => seq(
      $._lhs_expression_cc_list,
      $._assign_operator,
      $._rhs_expression_cc_list,
    ),

    _assign_statement_nfs_cc_nie : $ => seq(
      $._lhs_expression_cc_nie_list,
      $._assign_operator,
      $._rhs_expression_cc_nie_list,
    ),

    _assign_operator : $ => choice(
      $._t_addeq,
      $._t_andeq,
      $._t_andnoteq,
      $._t_cmpandeq,
      $._t_cmporeq,
      $._t_eq,
      $._t_modeq,
      $._t_modmodeq,
      $._t_muleq,
      $._t_oreq,
      $._t_quoeq,
      $._t_shleq,
      $._t_shreq,
      $._t_subeq,
      $._t_xoreq,
    ),

    // krnowak: attribute statement

    attribute_statement : $ => seq(
      $._t_at,
      $.attributes,
      $.statement,
    ),

    attributes : $ => choice(
      choice(
        alias($._simple_attribute_wrapper, $.attribute),
        seq(
          $._t_openparen,
          repeatCommaTrailing($, choice(
            alias($._simple_attribute_wrapper, $.attribute),
            alias($._attribute_with_value, $.attribute),
          )),
          $._t_closeparen,
        ),
      ),
    ),

    _simple_attribute_wrapper : $ => seq(
      alias($.simple_attribute, $.identifier),
    ),

    _attribute_with_value : $ => seq(
      alias($.value_attribute, $.identifier),
      $._t_eq,
      $.value,
    ),

    simple_attribute : $ => choice(
      $._a_builtin, // nothing
      $._a_cold, // nothing or bool
      $._a_entry_point_only, // nothing
      $._a_export, // nothing or bool
      $._a_fini, // nothing
      $._a_ignore_duplicates, // nothing
      $._a_init, // nothing
      $._a_instrumentation_enter, // nothing
      $._a_instrumentation_exit, // nothing
      $._a_no_instrumentation, // nothing or bool
      $._a_no_sanitize_address, // nothing
      $._a_no_sanitize_memory, // nothing
      $._a_objc_implement, // nothing or bool
      $._a_private, // nothing or string
      $._a_raddbg_type_view, // nothing or string
      $._a_require, // nothing or bool
      $._a_require_results, // nothing
      $._a_rodata, // nothing
      $._a_static, // nothing
      $._a_test, // nothing
      $._a_thread_local, // nothing or string
    ),

    value_attribute : $ => choice(
      $._a_default_calling_convention, // string
      $._a_deprecated, // string
      $._a_enable_target_feature, // string
      $._a_extra_linker_flags, // string
      $._a_linkage, // string
      $._a_link_name, // string
      $._a_link_prefix, // string
      $._a_link_section, // string
      $._a_link_suffix, // string
      $._a_objc_class, // string
      $._a_objc_name, // string
      $._a_objc_selector, // string
      $._a_optimization_mode, // string
      $._a_private, // nothing or string
      $._a_raddbg_type_view, // nothing or string
      $._a_require_target_feature, // string
      $._a_tag, // string
      $._a_thread_local, // nothing or string

      $._a_deferred_in, // identifier
      $._a_deferred_in_by_ptr, // identifier
      $._a_deferred_in_out, // identifier
      $._a_deferred_in_out_by_ptr, // identifier
      $._a_deferred_none, // identifier
      $._a_deferred_out, // identifier
      $._a_deferred_out_by_ptr, // identifier
      $._a_objc_context_provider, // identifier
      $._a_objc_ivar, // identifier
      $._a_objc_superclass, // identifier
      $._a_objc_type, // identifier

      $._a_cold, // nothing or bool
      $._a_disabled, // bool
      $._a_export, // nothing or bool
      $._a_no_instrumentation, // nothing or bool
      $._a_objc_implement, // nothing or bool
      $._a_objc_is_class_method, // bool
      $._a_require, // nothing or bool

      $._a_priority_index, // integer
    ),

    // krnowak: block statement

    block_statement : $ => seq(
      $._t_openbrace,
      // TODO: expr_level = 0
      repeat($.statement),
      $._t_closebrace,
    ),

    // krnowak: break statement

    break_statement : $ => seq(
      $._kw_break,
      optional($.identifier),
      $._statement_separator,
    ),

    // krnowak: const declaration

    const_declaration : $ => seq(
      $._const_declaration_nfs,
      $._statement_separator
    ),

    _const_declaration_nfs : $ => seq(
      $._identifier_list,
      $._t_colon,
      optional($.type),
      $._t_colon,
      $._rhs_expression_list,
    ),

    _const_declaration_nfs_cc : $ => seq(
      $._identifier_list,
      $._t_colon,
      optional($.type),
      $._t_colon,
      $._rhs_expression_cc_list,
    ),

    // krnowak: continue statement

    continue_statement : $ => seq(
      $._kw_continue,
      optional($.identifier),
      $._statement_separator,
    ),

    // krnowak: defer statement

    defer_statement : $ => seq(
      $._kw_defer,
      $.statement,
    ),

    // krnowak: directive statement

    directive_statement : $ => choice(
      $.statement_directive_statement, // ends with a closing brace, $.statement, $.do_statement or $._statement_separator
      $.unroll_for_directive_statement, // ends with a closing brace or $.do_statement
      $.partial_switch_directive_statement, // ends with a closing brace
      $.reverse_for_directive_statement, // ends with a closing brace or $.do_statement
      $.call_directive_statement, // ends with $._statement_separator
      $.inline_directive_statement, // ends with $._statement_separator
      $.must_tail_directive_statement, // ends with $._statement_separator
    ),

    statement_directive_statement : $ => seq(
      $._t_hash,
      choice(
        seq(
          choice(
            $._d_bounds_check,
            $._d_no_bounds_check,
            $._d_no_type_assert,
            $._d_type_assert,
          ),
          choice(
            $.block_statement,
            $.if_statement,
            $.when_statement,
            $.for_statement,
            $.unroll_for_directive_statement,
            $.switch_statement,
            $.return_statement,
            $.defer_statement,
            $.assign_statement,
            $.var_declaration,
          ),
        ),
      ),
    ),

    unroll_for_directive_statement : $ => seq(
      $._t_hash,
      $._d_unroll,
      optional($.unroll_parameters),
      $.for_statement,
    ),

    unroll_parameters : $ => seq(
      $._t_openparen,
      $.unroll_parameter_list,
      $._t_closeparen,
    ),

    unroll_parameter_list : $ => repeatComma1Trailing($, $.unroll_parameter),

    unroll_parameter : $ => choice(
      seq(
        $.identifier,
        $._t_eq,
        $.value,
      ),
      $.value,
    ),

    partial_switch_directive_statement : $ => seq(
      $._t_hash,
      $._d_partial,
      choice(
        $.labeled_switch_statement,
        $.switch_statement,
      ),
    ),

    reverse_for_directive_statement : $ => seq(
      $._t_hash,
      $._d_reverse,
      choice(
        $.labeled_for_statement,
        $.for_statement,
      ),
    ),

    call_directive_statement : $ => prec('call_statement', seq(
      $.directive_call,
      /*$._t_hash,
      choice(
        $._d_assert,
        $._d_panic,
      ),
      $._call_paren_part,*/
      $._statement_separator,
    )),

    inline_directive_statement : $ => seq(
      $.inline_directive,
      $._statement_separator,
    ),

    inline_directive : $ => seq(
      $._t_hash,
      choice(
        $._d_force_inline,
        $._d_force_no_inline,
      ),
      $.inline_directive_expression,
    ),

    inline_directive_expression : $ => choice(
      $.inline_directive_or_branch_expression,
      $.inline_directive_paren_expression,
      $.procedure_literal,
      $.call_atom_expression,
    ),

    inline_directive_or_branch_expression : $ => prec('inline_or_branch', seq(
      choice(
        $.inline_directive_paren_expression,
        $.call_atom_expression,
      ),
      choice(
        $._kw_or_return,
        seq($._kw_or_break, optional($.identifier)),
        seq($._kw_or_continue, optional($.identifier)),
      ),
    )),

    inline_directive_paren_expression : $ => prec('inline_or_branch', seq(
      $._t_openparen,
      choice(
        $.inline_directive_or_branch_expression,
        $.call_atom_expression,
      ),
      $._t_closeparen,
    )),

    must_tail_directive_statement : $ => seq(
      $.must_tail_directive,
      $._statement_separator,
    ),

    must_tail_directive : $ => seq(
      $._t_hash,
      $._d_must_tail,
      $.must_tail_directive_expression,
    ),

    must_tail_directive_expression : $ => choice(
      $.inline_directive_or_branch_expression,
      $.inline_directive_paren_expression,
      $.call_atom_expression,
    ),

    inline_directive_nlve : $ => seq(
      $._t_hash,
      choice(
        $._d_force_inline,
        $._d_force_no_inline,
      ),
      $.inline_directive_expression_nlve,
    ),

    inline_directive_expression_nlve : $ => choice(
      $.inline_directive_or_branch_expression_nlve,
      $.inline_directive_paren_expression,
      $.procedure_literal,
      $.call_atom_expression_nlve,
    ),

    inline_directive_or_branch_expression_nlve : $ => /*prec('inline_or_branch', */seq(
      choice(
        $.inline_directive_paren_expression,
        $.call_atom_expression_nlve,
      ),
      choice(
        $._kw_or_return,
        seq($._kw_or_break, optional($.identifier)),
        seq($._kw_or_continue, optional($.identifier)),
      ),
    )/*)*/,

    must_tail_directive_nlve : $ => seq(
      $._t_hash,
      $._d_must_tail,
      $.must_tail_directive_expression_nlve,
    ),

    must_tail_directive_expression_nlve : $ => choice(
      $.inline_directive_or_branch_expression_nlve,
      $.inline_directive_paren_expression,
      $.call_atom_expression_nlve,
    ),

    // krnowak: fallthrough statement

    fallthrough_statement : $ => seq(
      $._kw_fallthrough,
      $._statement_separator,
    ),

    // krnowak: for statement

    // for {…} - forever loop
    // for ;; {…} - forever loop
    // for a in range - range-based for loop
    // for cond {…} - "while" loop
    // c-like loops:
    // for ; cond; {…}
    // for init; cond {…}
    // for init; cond; {…}
    // for init; cond; post {…}
    // for ; cond; post {…}
    for_statement : $ => seq(
      $._kw_for,
      optional(choice(
        seq(
          optional($.for_init),
          // TODO: expr_level -1
          optional($.simple_statement_nfs_cc_nie),
          optional($.for_post),
        ),
        // TODO: expr_level -1
        $.in_statement_nfs_cc_nie,
      )),
      choice(
        $.block_statement,
        $.do_statement,
      ),
    ),

    for_init : $ => prec('for_init', seq(
      // TODO: expr_level -1
      optional($.simple_statement_nfs_cc_nie),
      $._t_semicolon,
    )),

    // TODO: the precedence and associativity is here only because the
    // grammar currently allows literal values lhs expressions in
    // simple statements, whereas in Odin literal values are only
    // allowed in rhs expressions.
    for_post : $ => prec('for_post', seq(
      $._t_semicolon,
      // TODO: expr_level -1
      optional($.simple_statement_nfs_cc_nie),
    )),

    // krnowak: foreign block declaration

    foreign_block_declaration : $ => seq(
      $._kw_foreign,
      optional($.identifier),
      //optional($._implicit_semicolon),
      $.block_statement,
      //$._t_openbrace,
      //repeat(choice(
      //  $.const_declaration,
      //  $.var_declaration,
      //  $.when_statement,
      //)),
      //$._t_closebrace,
      $._statement_separator,
    ),

    // krnowak: foreign import declaration

    foreign_import_declaration : $ => seq(
      $._kw_foreign,
      $._kw_import,
      optional($.identifier),
      choice(
        seq(
          $._t_openbrace,
          $._rhs_expression_list_trailing,
          $._t_closebrace,
        ),
        $.string,
      ),
      $._statement_separator,
    ),

    // krnowak: if statement

    // Right associativity set because of issues with assigning the
    // else clause (inner if vs outer if).
    //
    //    Unresolved conflict for symbol sequence:
    //
    //      package  _kw_if  rhs_expression  _kw_do  _kw_if  rhs_expression  block_statement  •  _kw_else  …
    //
    //    Possible interpretations:
    //
    //      1:  package  _kw_if  rhs_expression  _kw_do  (if_statement  _kw_if  rhs_expression  block_statement  •  _kw_else  block_statement)
    //      2:  package  _kw_if  rhs_expression  _kw_do  (if_statement  _kw_if  rhs_expression  block_statement  •  _kw_else  do_statement)
    //      3:  package  _kw_if  rhs_expression  _kw_do  (if_statement  _kw_if  rhs_expression  block_statement  •  _kw_else  if_statement)
    //      4:  package  _kw_if  rhs_expression  _kw_do  (if_statement  _kw_if  rhs_expression  block_statement)  •  _kw_else  …
    //
    if_statement : $ => prec.right(seq(
      $._kw_if,
      // TODO: expr_level -1
      // TODO: allow_in_expr = true
      optional(seq(
        // but "in" or "not_in" not allowed in the statement itself
        optional(
          $.simple_statement_nfs_cc,
        ),
        $._t_semicolon,
      )),
      // TODO: expr_level -1
      $.rhs_expression_cc,
      choice(
        $.do_statement,
        $.block_statement,
      ),
      //optional($._implicit_semicolon),
      optional(seq(
        $._kw_else,
        choice(
          $.if_statement,
          $.block_statement,
          $.do_statement,
        ),
      )),
    )),

    // krnowak: import declaration

    import_declaration : $ => seq(
      $._kw_import,
      optional(field('alias', alias($.identifier, $.package_name))),
      $.string,
      $._statement_separator,
    ),

    // krnowak: label statement

    label_statement : $ => choice(
      $.labeled_partial_switch_directive_statement,
      $.labeled_reverse_for_directive_statement,
      $.labeled_switch_statement,
      $.labeled_for_statement,
      $.labeled_block_statement,
      $.labeled_if_statement,
    ),

    label : $ => seq(
      $.identifier,
      $._t_colon,
    ),

    labeled_partial_switch_directive_statement : $ => seq(
      $.label,
      $.partial_switch_directive_statement,
    ),

    labeled_reverse_for_directive_statement : $ => seq(
      $.label,
      $.reverse_for_directive_statement,
    ),

    labeled_switch_statement : $ => seq(
      $.label,
      $.switch_statement,
    ),

    labeled_for_statement : $ => seq(
      $.label,
      $.for_statement,
    ),

    labeled_block_statement : $ => seq(
      $.label,
      $.block_statement,
    ),

    labeled_if_statement : $ => seq(
      $.label,
      $.if_statement,
    ),

    // krnowak: return statement

    return_statement : $ => seq(
      $._kw_return,
      optional($._rhs_expression_list_trailing),
      $._statement_separator,
    ),

    // krnowak: switch statement

    switch_statement : $ => seq(
      $._kw_switch,
      optional($.switch_control),
      //optional($._implicit_semicolon),
      $._t_openbrace,
      repeat($.case_clause),
      $._t_closebrace,
    ),

    switch_control : $ => choice(
      $.type_switch_control,
      $.init_tag_switch_control,
      $.init_only_switch_control,
      $.tag_only_switch_control,
    ),

    // switch v in value {…}
    // TODO: expr_level -1
    type_switch_control : $ => $.in_statement_nfs_cc_nie,

    // switch init; tag {…}
    // TODO: expr_level -1
    init_tag_switch_control : $ => seq(
      $.simple_statement_nfs_cc_nie,
      $._t_semicolon,
      $.simple_statement_nfs_cc_nie,
    ),

    // switch init; {…}
    // TODO: expr_level -1
    init_only_switch_control : $ => seq(
      $.simple_statement_nfs_cc_nie,
      $._t_semicolon,
    ),

    // switch tag {…}
    // TODO: expr_level -1
    tag_only_switch_control : $ => $.simple_statement_nfs_cc_nie,

    case_clause : $ => seq(
      $._kw_case,
      // TODO: allow_range = !is_type_switch, but we will allow it anyway
      // TODO: allow_in_expr = !is_type_switch, but we will allow it anyway
      optional($._rhs_expression_list),
      $._t_colon,
      repeat($.statement),
    ),

    // krnowak: using statement

    using_statement : $ => seq(
      $._kw_using,
      choice(
        $._lhs_expression_list,
        $._var_declaration_nfs,
      ),
      $._statement_separator,
    ),

    // krnowak: var declaration

    var_declaration : $ => seq(
      $._var_declaration_nfs,
      $._statement_separator,
    ),

    _var_declaration_nfs : $ => seq(
      $._identifier_list,
      $._t_colon,
      choice(
        $.type,
        seq(
          optional($.type),
          $._t_eq,
          $._rhs_expression_list,
        ),
      ),
    ),

    _var_declaration_nfs_cc : $ => seq(
      $._identifier_list,
      $._t_colon,
      choice(
        $.type,
        seq(
          optional($.type),
          $._t_eq,
          $._rhs_expression_cc_list,
        ),
      ),
    ),

    // krnowak: when statement

    when_statement : $ => prec.right(seq(
      $._kw_when,
      // TODO: expr level -1
      // TODO: allow_in_expr = true
      $.rhs_expression_cc,
      choice(
        $.do_statement,
        $.block_statement,
      ),
      //optional($._implicit_semicolon),
      optional(seq(
        $._kw_else,
        choice(
          $.when_statement,
          $.block_statement,
          $.do_statement,
        ),
      )),
    )),

    // krnowak: expression statement

    expression_statement : $ => seq(
      $.lhs_expression,
      $._statement_separator,
    ),

    // krnowak: statement helpers

    in_statement_nfs_cc_nie : $ => seq(
      $._lhs_expression_cc_nie_list,
      $._kw_in,
      // TODO: allow_range = true
      $.rhs_expression_cc_nie,
    ),

    do_statement : $ => seq(
      $._kw_do,
      // TODO: expr_level = 0
      $.statement,
    ),

    simple_statement_nfs_cc : $ => choice(
      $._assign_statement_nfs_cc,
      $._const_declaration_nfs_cc,
      $._var_declaration_nfs_cc,
      $.lhs_expression_cc, // expression_statement_nfs_cc
    ),

    simple_statement_nfs_cc_nie : $ => choice(
      $._assign_statement_nfs_cc_nie,
      $._const_declaration_nfs_cc,
      $._var_declaration_nfs_cc,
      $.lhs_expression_cc_nie, // expression_statement_nfs_cc_nie
    ),

    //
    // krnowak: expressions
    //

    lhs_expression : $ => choice(
      $.lhs_unary_expression,
      $.lhs_binary_expression,
      $.lhs_ternary_expression,
    ),

    rhs_expression : $ => choice(
      $.rhs_unary_expression,
      $.rhs_binary_expression,
      $.rhs_ternary_expression,
    ),

    lhs_expression_cc : $ => choice(
      $.lhs_unary_expression_cc,
      $.lhs_binary_expression_cc,
      $.lhs_ternary_expression_cc,
    ),

    rhs_expression_cc : $ => choice(
      $.rhs_unary_expression_cc,
      $.rhs_binary_expression_cc,
      $.rhs_ternary_expression_cc,
    ),

    lhs_expression_cc_nie : $ => choice(
      $.lhs_unary_expression_cc,
      $.lhs_binary_expression_cc_nie,
      $.lhs_ternary_expression_cc_nie,
    ),

    rhs_expression_cc_nie : $ => choice(
      $.rhs_unary_expression_cc,
      $.rhs_binary_expression_cc_nie,
      $.rhs_ternary_expression_cc_nie,
    ),

    // ternary expressions

    lhs_ternary_expression : $ => prec.right('binary', choice(
      seq(
        $.lhs_expression,
        choice($._kw_if, $._kw_when),
        $.lhs_expression,
        $._kw_else,
        $.lhs_expression,
      ),
      seq(
        $.lhs_expression,
        $._t_question,
        $.lhs_expression,
        $._t_colon,
        $.lhs_expression,
      ),
    )),

    rhs_ternary_expression : $ => prec.right('binary', choice(
      seq(
        $.rhs_expression,
        choice($._kw_if, $._kw_when),
        $.rhs_expression,
        $._kw_else,
        $.rhs_expression,
      ),
      seq(
        $.rhs_expression,
        $._t_question,
        $.rhs_expression,
        $._t_colon,
        $.rhs_expression,
      ),
    )),

    lhs_ternary_expression_cc : $ => prec.right('binary', choice(
      seq(
        $.lhs_expression_cc,
        choice($._kw_if, $._kw_when),
        $.lhs_expression_cc,
        $._kw_else,
        $.lhs_expression_cc,
      ),
      seq(
        $.lhs_expression_cc,
        $._t_question,
        $.lhs_expression_cc,
        $._t_colon,
        $.lhs_expression_cc,
      ),
    )),

    rhs_ternary_expression_cc : $ => prec.right('binary', choice(
      seq(
        $.rhs_expression_cc,
        choice($._kw_if, $._kw_when),
        $.rhs_expression_cc,
        $._kw_else,
        $.rhs_expression_cc,
      ),
      seq(
        $.rhs_expression_cc,
        $._t_question,
        $.rhs_expression_cc,
        $._t_colon,
        $.rhs_expression_cc,
      ),
    )),

    lhs_ternary_expression_cc_nie : $ => prec.right('binary', choice(
      seq(
        $.lhs_expression_cc_nie,
        choice($._kw_if, $._kw_when),
        $.lhs_expression_cc_nie,
        $._kw_else,
        $.lhs_expression_cc_nie,
      ),
      seq(
        $.lhs_expression_cc_nie,
        $._t_question,
        $.lhs_expression_cc_nie,
        $._t_colon,
        $.lhs_expression_cc_nie,
      ),
    )),

    rhs_ternary_expression_cc_nie : $ => prec.right('binary', choice(
      seq(
        $.rhs_expression_cc_nie,
        choice($._kw_if, $._kw_when),
        $.rhs_expression_cc_nie,
        $._kw_else,
        $.rhs_expression_cc_nie,
      ),
      seq(
        $.rhs_expression_cc_nie,
        $._t_question,
        $.rhs_expression_cc_nie,
        $._t_colon,
        $.rhs_expression_cc_nie,
      ),
    )),

    // binary expressions

    lhs_binary_expression : $ => {
      return choice(...binOpPrecs($, ALL_OPERATORS).map(([an_op, a_prec]) => {
        return prec.left(a_prec, seq(
          $.lhs_expression,
          an_op,
          $.rhs_expression,
        ));
      }));
    },

    rhs_binary_expression : $ => {
      return choice(...binOpPrecs($, ALL_OPERATORS).map(([an_op, a_prec]) => {
        return prec.left(a_prec, seq(
          $.rhs_expression,
          an_op,
          $.rhs_expression,
        ));
      }));
    },

    lhs_binary_expression_cc : $ => {
      return choice(...binOpPrecs($, ALL_OPERATORS).map(([an_op, a_prec]) => {
        return prec.left(a_prec, seq(
          $.lhs_expression_cc,
          an_op,
          $.rhs_expression_cc,
        ));
      }));
    },

    rhs_binary_expression_cc : $ => {
      return choice(...binOpPrecs($, ALL_OPERATORS).map(([an_op, a_prec]) => {
        return prec.left(a_prec, seq(
          $.rhs_expression_cc,
          an_op,
          $.rhs_expression_cc,
        ));
      }));
    },

    lhs_binary_expression_cc_nie : $ => {
      return choice(...binOpPrecs($, NO_IN_OPERATORS).map(([an_op, a_prec]) => {
        return prec.left(a_prec, seq(
          $.lhs_expression_cc_nie,
          an_op,
          $.rhs_expression_cc_nie,
        ));
      }));
    },

    rhs_binary_expression_cc_nie : $ => {
      return choice(...binOpPrecs($, NO_IN_OPERATORS).map(([an_op, a_prec]) => {
        return prec.left(a_prec, seq(
          $.rhs_expression_cc_nie,
          an_op,
          $.rhs_expression_cc_nie,
        ));
      }));
    },

    // unary expressions

    lhs_unary_expression : $ => prec.right('unary', choice(
      $.lhs_cast_expression,
      $.lhs_transmute_expression,
      $.lhs_auto_cast_expression,
      $.lhs_prefix_unary_expression,
      $.implicit_selector_expression,
      $.atom_expression,
    )),

    rhs_unary_expression : $ => prec.right('unary', choice(
      $.rhs_cast_expression,
      $.rhs_transmute_expression,
      $.rhs_auto_cast_expression,
      $.rhs_prefix_unary_expression,
      $.implicit_selector_expression,
      $.atom_expression,
      $.literal_value,
      $.partial_directive_literal_value,
    )),

    lhs_unary_expression_cc : $ => prec.right('unary', choice(
      $.lhs_cast_expression_cc,
      $.lhs_transmute_expression_cc,
      $.lhs_auto_cast_expression_cc,
      $.lhs_prefix_unary_expression_cc,
      $.implicit_selector_expression,
      $.atom_expression_nlve,
    )),

    rhs_unary_expression_cc : $ => prec.right('unary', choice(
      $.rhs_cast_expression_cc,
      $.rhs_transmute_expression_cc,
      $.rhs_auto_cast_expression_cc,
      $.rhs_prefix_unary_expression_cc,
      $.implicit_selector_expression,
      $.atom_expression_nlve,
      $.literal_value,
      $.partial_directive_literal_value_nlve,
    )),

    // TODO: move to unary expression helpers
    partial_directive_literal_value : $ => seq(
      $._t_hash,
      $._d_partial,
      $.paren_literal_value,
    ),

    // TODO: move to unary expression helpers
    partial_directive_literal_value_nlve : $ => seq(
      $._t_hash,
      $._d_partial,
      $.paren_literal_value_nlve,
    ),

    // TODO: move to unary expression helpers
    paren_literal_value : $ => choice(
      seq(
        $._t_openparen,
        $.paren_literal_value,
        $._t_closeparen,
      ),
      $.literal_value,
      $.literal_value_atom_expression,
    ),

    // TODO: move to unary expression helpers
    paren_literal_value_nlve : $ => choice(
      seq(
        $._t_openparen,
        $.paren_literal_value,
        $._t_closeparen,
      ),
      $.literal_value,
    ),

    // krnowak: unary cast expressions

    lhs_cast_expression : $ => seq(
      $.cast_part,
      $.lhs_unary_expression,
    ),

    rhs_cast_expression : $ => seq(
      $.cast_part,
      $.rhs_unary_expression,
    ),

    lhs_cast_expression_cc : $ => seq(
      $.cast_part,
      $.lhs_unary_expression_cc,
    ),

    rhs_cast_expression_cc : $ => seq(
      $.cast_part,
      $.rhs_unary_expression_cc,
    ),

    // TODO: move to unary expression helpers
    cast_part : $ => seq(
      $._kw_cast,
      $._t_openparen,
      $._type_maybe_in_parentheses,
      $._t_closeparen,
    ),

    // krnowak: unary transmute expressions

    lhs_transmute_expression : $ => seq(
      $.transmute_part,
      $.lhs_unary_expression,
    ),

    rhs_transmute_expression : $ => seq(
      $.transmute_part,
      $.rhs_unary_expression,
    ),

    lhs_transmute_expression_cc : $ => seq(
      $.transmute_part,
      $.lhs_unary_expression_cc,
    ),

    rhs_transmute_expression_cc : $ => seq(
      $.transmute_part,
      $.rhs_unary_expression_cc,
    ),

    // TODO: move to unary expression helpers
    transmute_part : $ => seq(
      $._kw_transmute,
      $._t_openparen,
      $._type_maybe_in_parentheses,
      $._t_closeparen,
    ),

    // krnowak: unary auto_cast expressions

    lhs_auto_cast_expression : $ => seq(
      $._kw_auto_cast,
      $.lhs_unary_expression,
    ),

    rhs_auto_cast_expression : $ => seq(
      $._kw_auto_cast,
      $.rhs_unary_expression,
    ),

    lhs_auto_cast_expression_cc : $ => seq(
      $._kw_auto_cast,
      $.lhs_unary_expression_cc,
    ),

    rhs_auto_cast_expression_cc : $ => seq(
      $._kw_auto_cast,
      $.rhs_unary_expression_cc,
    ),

    // krnowak: unary prefix expressions

    lhs_prefix_unary_expression : $ => seq(
      $._unary_prefix_operator,
      $.lhs_unary_expression,
    ),

    rhs_prefix_unary_expression : $ => seq(
      $._unary_prefix_operator,
      $.rhs_unary_expression,
    ),

    lhs_prefix_unary_expression_cc : $ => seq(
      $._unary_prefix_operator,
      $.lhs_unary_expression_cc,
    ),

    rhs_prefix_unary_expression_cc : $ => seq(
      $._unary_prefix_operator,
      $.rhs_unary_expression_cc,
    ),

    // TODO: move to unary expression helpers
    _unary_prefix_operator : $ => choice(
      $._t_add,
      $._t_sub,
      $._t_xor,
      $._t_and,
      seq($._t_not, optional($._implicit_semicolon)),
    ),

    // krnowak: unary implicit selector expressions

    implicit_selector_expression : $ => seq(
      $._t_period,
      $.identifier,
    ),

    // krnowak: atom expressions

    atom_expression : $ => prec('atom_expression', choice(
      $.operand,
      $.call_atom_expression,
      $.selector_atom_expression,
      $.type_assertion_atom_expression,
      $.type_inference_atom_expression,
      $.slice_index_atom_expression,
      $.matrix_index_atom_expression,
      $.slice_atom_expression,
      $.dereference_atom_expression,
      $.or_return_atom_expression,
      $.or_continue_atom_expression,
      $.or_break_atom_expression,
      $.inline_directive,
      $.must_tail_directive,
      $.literal_value_atom_expression,
    )),

    atom_expression_nlve : $ => choice(
      $.operand,
      $.call_atom_expression_nlve,
      $.selector_atom_expression_nlve,
      $.type_assertion_atom_expression_nlve,
      $.type_inference_atom_expression_nlve,
      $.slice_index_atom_expression_nlve,
      $.matrix_index_atom_expression_nlve,
      $.slice_atom_expression_nlve,
      $.dereference_atom_expression_nlve,
      $.or_return_atom_expression_nlve,
      $.or_continue_atom_expression_nlve,
      $.or_break_atom_expression_nlve,
      $.inline_directive_nlve,
      $.must_tail_directive_nlve,
    ),

    // operands

    operand : $ => prec('operand', choice(
      $.identifier,
      $._kw_context,
      $._t_uninit,
      $.number,
      $.rune,
      $.string,
      $.parentheses_expression,
      $.distinct_type,
      $.just_directive,
      $.directive_call,
      $.procedure_literal,
      $.procedure_group,
      // TODO: should this be just $.type? the problem is trying to
      // differentiate the identifier as a variable or type
      $.directive_with_type,
      $.procedure_type,
      $.poly_type,
      $.pointer_type,
      $.slicelike_type,
      $.map_type,
      $.matrix_type,
      $.bit_field_type,
      $.enum_type,
      $.bit_set_type,
      $.struct_type,
      $.union_type,
      $.inline_asm,
    )),

    parentheses_expression : $ => seq(
      $._t_openparen,
      // expr_level > 0
      $.rhs_expression,
      $._t_closeparen,
    ),

    distinct_type : $ => seq(
      $._kw_distinct,
      $._type_maybe_in_parentheses,
    ),

    directive_with_type : $ => seq(
      $._t_hash,
      choice(
        $._d_type,
        $._d_column_major,
        $._d_row_major,
        $._d_simd,
        $._d_soa,
        $._d_sparse,
      ),
      $._type_maybe_in_parentheses,
    ),

    just_directive : $ => seq(
      $._t_hash,
      choice(
        $._d_file,
        $._d_directory,
        $._d_line,
        $._d_procedure,
        $._d_caller_location,
        $._d_caller_expression,
        $._d_branch_location,
      ),
    ),

    directive_call : $ => seq(
      $._t_hash,
      choice(
        $._d_location,
        $._d_config,
        $._d_defined,
        $._d_exists,
        $._d_hash,
        $._d_load,
        $._d_load_directory,
        $._d_load_hash,
        $._d_panic,
        $._d_assert,
      ),
      $._call_paren_part,
    ),

    procedure_literal : $ => seq(
      $.procedure_type,
      optional($._implicit_semicolon),
      optional($.where_clauses),
      repeat($.procedure_trailing_directive),
      //optional($._implicit_semicolon),
      choice(
        $._t_uninit,
        $.block_statement,
        $.do_statement,
      ),
    ),

    // TODO: move to operator helpers
    where_clauses : $ => seq(
      $._kw_where,
      // TODO: expr_level -1
      $._rhs_expression_cc_list,
    ),

    // TODO: move to operator helpers
    procedure_trailing_directive : $ => seq(
      $._t_hash,
      choice(
        $._d_optional_ok,
        $._d_optional_allocator_error,
        $._d_bounds_check,
        $._d_no_bounds_check,
        $._d_type_assert,
        $._d_no_type_assert,
      ),
    ),

    procedure_type : $ => seq(
      $._kw_proc,
      optional(alias($.string, 'calling_convention')),
      $._t_openparen,
      optional(alias($._procedure_field_list, $.parameters)),
      $._t_closeparen,
      optional($.procedure_result),
      //optional($._implicit_semicolon),
    ),

    // TODO: move to operator helpers
    _procedure_field_list : $ => choice(
      $._type_procedure_field_list,
      repeatComma1Trailing($, alias($._procedure_parameter_pack, $.parameter_pack)),
    ),

    // TODO: move to operator helpers
    _type_procedure_field_list : $ => seq(
      repeatComma1Trailing($, seq(
        repeat($.field_prefix),
        // Variadic type is normally only acceptable for the last
        // parameter, but accepting it for any parameter makes it a
        // slightly simpler grammar.
        choice(
          $.variadic_type,
          $._type_maybe_in_parentheses,
        ),
      )),
    ),

    // TODO: move to operator helpers
    variadic_type : $ => seq(
      $._t_ellipsis,
      $._type_maybe_in_parentheses,
    ),

    // TODO: move to operator helpers
    _procedure_parameter_pack : $ => seq(
      $._identifier_or_poly_type_list,
      $._t_colon,
      // Variadic type is normally only acceptable for the last
      // parameter, but accepting it for any parameter makes it
      // a slightly simpler grammar.
      choice(
        $.variadic_type,
        $._type_maybe_in_parentheses,
        seq(
          optional($._type_maybe_in_parentheses),
          $._t_eq,
          alias($.rhs_expression, $.default_value),
        ),
      ),
    ),

    // TODO: move to operator helpers
    procedure_result : $ => seq(
      $._t_arrowright,
      choice(
        alias($._t_not, $.diverging),
        $.type,
        seq(
          $._t_openparen,
          optional($._result_field_list),
          $._t_closeparen,
        ),
      ),
    ),

    // this is what is inside the parentheses of a result, this can
    // be either a list of types, so:
    //
    // type1, type2, type3, …
    //
    // or it can be a list of return value packs, where a return value
    // pack is:
    //
    // name1, name2, name3, …, nameX : type
    //
    // or:
    //
    // name : type = value
    //
    // or:
    //
    // name := value
    //
    // TODO: move to operator helpers
    _result_field_list : $ => choice(
      // type, type, type, …
      repeatComma1Trailing($, seq(
        repeat($.field_prefix),
        $._type_maybe_in_parentheses,
      )),
      // name, name, … : type, name, name, … : type
      //
      // with default values too
      repeatComma1Trailing($, $._result_single_pack),
    ),

    // TODO: move to operator helpers
    _result_single_pack : $ => seq(
      repeat($.field_prefix),
      $._identifier_list,
      $._t_colon,
      choice(
        $._type_maybe_in_parentheses,
        seq(
          optional($._type_maybe_in_parentheses),
          $._t_eq,
          alias($.rhs_expression, $.default_value),
        ),
      ),
    ),

    procedure_group : $ => seq(
      $._kw_proc,
      $._t_openbrace,
      $._rhs_expression_list_trailing,
      $._t_closebrace,
    ),

    poly_type : $ => prec.right(seq(
      choice(
        seq(
          $._t_dollar,
          $.identifier,
        ),
        $._kw_typeid,
      ),
      optional(seq(
        $._t_quo,
        $._type_maybe_in_parentheses,
      )),
    )),

    pointer_type : $ => seq(
      $._t_pointer,
      $._type_maybe_in_parentheses,
    ),

    slicelike_type : $ => seq(
      $._t_openbracket,
      optional(choice(
        $._t_pointer,
        $._t_question,
        $._kw_dynamic,
        $.rhs_expression,
      )),
      $._t_closebracket,
      $._type_maybe_in_parentheses,
    ),

    map_type : $ => seq(
      $._kw_map,
      $._t_openbracket,
      $.lhs_expression,
      $._t_closebracket,
      $._type_maybe_in_parentheses,
    ),

    matrix_type : $ => seq(
      $._kw_matrix,
      $._t_openbracket,
      $.lhs_expression,
      $._t_comma,
      $.lhs_expression,
      $._t_closebracket,
      $._type_maybe_in_parentheses,
    ),

    bit_field_type : $ => seq(
      $._kw_bit_field,
      $.type,
      //optional($._implicit_semicolon),
      $._t_openbrace,
      repeatCommaTrailing($, $.bit_field_entry),
      $._t_closebrace,
    ),

    bit_field_entry : $ => seq(
      $.identifier,
      $._t_colon,
      $._type_maybe_in_parentheses,
      $._t_or,
      // TODO: expr_level -1
      $.lhs_expression_cc,
      optional($.string),
    ),

    enum_type : $ => seq(
      $._kw_enum,
      optional($._type_maybe_in_parentheses),
      //optional($._implicit_semicolon),
      $.enum_field_entries,
    ),

    // TODO: move to operator helpers
    enum_field_entries : $ => seq(
      $._t_openbrace,
      repeatCommaTrailing($, $.enum_field_entry),
      $._t_closebrace,
    ),

    // TODO: move to operator helpers
    enum_field_entry : $ => seq(
      $.identifier,
      optional(seq(
        $._t_eq,
        $.value,
      )),
    ),

    bit_set_type : $ => seq(
      $._kw_bit_set,
      $._t_openbracket,
      // TODO: allow_range = true
      $.lhs_expression,
      optional(seq(
        $._t_semicolon,
        $._type_maybe_in_parentheses,
      )),
      $._t_closebracket,
    ),

    struct_type : $ => seq(
      $._kw_struct,
      optional($.struct_union_polyparams),
      repeat($.struct_directive),
      //optional($._implicit_semicolon),
      optional($.where_clauses),
      //optional($._implicit_semicolon),
      $._t_openbrace,
      optional($.struct_field_list),
      $._t_closebrace,
    ),

    // TODO: move to operator helpers
    struct_directive : $ => seq(
      $._t_hash,
      choice(
        $._d_all_or_none,
        $._d_packed,
        $._d_raw_union,
        $._d_simple,
        seq(
          choice(
            $._d_align,
            $._d_min_field_align,
            $._d_max_field_align,
          ),
          // TODO: expr_level -1
          '(',
          $.rhs_expression_cc,
          ')',
        ),
      ),
    ),

    // TODO: move to operator helpers
    struct_field_list : $ => choice(
      repeatComma1Trailing($, seq(
        repeat($.field_prefix),
        $._type_maybe_in_parentheses,
      )),
      $.identifier_struct_field_list,
    ),

    // TODO: move to operator helpers
    identifier_struct_field_list : $ => repeatComma1Trailing($, seq(
      repeat($.field_prefix),
      $._identifier_list,
      $._t_colon,
      $._type_maybe_in_parentheses,
      optional(alias($.string, $.tag)),
    )),

    union_type : $ => seq(
      $._kw_union,
      optional($.struct_union_polyparams),
      repeat($.union_directive),
      //optional($._implicit_semicolon),
      optional($.where_clauses),
      //optional($._implicit_semicolon),
      $._t_openbrace,
      optional($.union_field_list),
      $._t_closebrace,
    ),

    // TODO: move to operator helpers
    struct_union_polyparams : $ => seq(
      $._t_openparen,
      $.struct_union_polyparam_field_list,
      $._t_closeparen,
    ),

    // only "ident, ident : type" list
    //
    // TODO: move to operator helpers
    struct_union_polyparam_field_list : $ => repeatComma1Trailing($, $.struct_union_polyparam_field),

    // TODO: move to operator helpers
    struct_union_polyparam_field : $ => seq(
      $._identifier_or_poly_type_list,
      $._t_colon,
      optional($._type_maybe_in_parentheses),
      optional(seq(
        $._t_eq,
        alias($.rhs_expression, $.default_value),
      )),
    ),

    // TODO: move to operator helpers
    union_directive : $ => seq(
      $._t_hash,
      choice(
        $._d_no_nil,
        $._d_shared_nil,
        seq(
          $._d_align,
          $.parentheses_expression,
        ),
      ),
    ),

    // TODO: move to operator helpers
    union_field_list : $ => repeatComma1Trailing($,
      $._type_maybe_in_parentheses,
    ),

    inline_asm : $ => seq(
      $._kw_asm,
      optional($.inline_asm_parameters_and_results),
      repeat($.inline_asm_directive),
      //optional($._implicit_semicolon),
      $._t_openbrace,
      $.rhs_expression, // asm string
      $._t_comma,
      $.rhs_expression, // constraints string
      optional($._t_comma),
      $._t_closebrace,
    ),

    // TODO: move to operator helpers
    inline_asm_parameters_and_results : $ => seq(
      $._t_openparen,
      repeatCommaTrailing($, $._type_maybe_in_parentheses),
      $._t_closeparen,
      optional(seq(
        $._t_arrowright,
        $._type_maybe_in_parentheses,
      )),
    ),

    // TODO: move to operator helpers
    inline_asm_directive : $ => seq(
      $._t_hash,
      choice(
        $._d_align_stack,
        $._d_att,
        $._d_intel,
        $._d_side_effects,
      ),
    ),

    // atom sub expressions

    common_atom_subexpressions : $ => prec('atom_expression', choice(
      // operands
      $.identifier,
      $.parentheses_expression,
      $.just_directive,
      $.directive_call,
      // atom expressions
      $.call_atom_expression,
      $.selector_atom_expression,
      $.type_assertion_atom_expression,
      $.type_inference_atom_expression,
      $.slice_index_atom_expression,
      $.slice_atom_expression,
      $.dereference_atom_expression,
    )),

    common_atom_subexpressions_nlve : $ => choice(
      // operands
      $.identifier,
      $.parentheses_expression,
      $.just_directive,
      // atom expressions
      $.call_atom_expression_nlve,
      $.selector_atom_expression_nlve,
      $.type_assertion_atom_expression_nlve,
      $.type_inference_atom_expression_nlve,
      $.slice_index_atom_expression_nlve,
      $.slice_atom_expression_nlve,
      $.dereference_atom_expression_nlve,
    ),

    call_atom_expression : $ => seq(
      choice(
        $.common_atom_subexpressions,
        // operands
        $.procedure_literal,
        $.inline_asm,
        // atom expressions
        $.call_selector_atom_expression,
      ),
      $._call_paren_part,
    ),

    call_atom_expression_nlve : $ => seq(
      choice(
        $.common_atom_subexpressions_nlve,
        // operands
        $.procedure_literal,
        $.inline_asm,
        // atom expressions
        $.call_selector_atom_expression_nlve,
      ),
      $._call_paren_part,
    ),

    call_selector_atom_expression : $ => seq(
      choice(
        $.common_atom_subexpressions,
        // atom expressions
        $.literal_value_atom_expression,
      ),
      $._t_arrowright,
      $.identifier,
    ),

    call_selector_atom_expression_nlve : $ => seq(
      $.common_atom_subexpressions_nlve,
      $._t_arrowright,
      $.identifier,
    ),

    selector_atom_expression : $ => seq(
      choice(
        $.common_atom_subexpressions,
        // operands
        $._kw_context,
        // atom expressions
        $.literal_value_atom_expression,
      ),
      $._t_period,
      $.identifier,
    ),

    selector_atom_expression_nlve : $ => seq(
      choice(
        $.common_atom_subexpressions_nlve,
        // operands
        $._kw_context,
      ),
      $._t_period,
      $.identifier,
    ),

    type_assertion_atom_expression : $ => seq(
      choice(
        $.common_atom_subexpressions,
        // atom expressions
        $.literal_value_atom_expression,
      ),
      $.type_assertion_part,
    ),

    type_assertion_atom_expression_nlve : $ => seq(
      $.common_atom_subexpressions_nlve,
      $.type_assertion_part,
    ),

    // TODO: move to atom expression helpers
    type_assertion_part : $ => seq(
      $._t_period,
      $._t_openparen,
      $._type_maybe_in_parentheses,
      $._t_closeparen,
    ),

    type_inference_atom_expression : $ => seq(
      choice(
        $.common_atom_subexpressions,
        // atom expressions
        $.literal_value_atom_expression,
      ),
      $._t_period,
      $._t_question,
    ),

    type_inference_atom_expression_nlve : $ => seq(
      $.common_atom_subexpressions_nlve,
      $._t_period,
      $._t_question,
    ),

    slice_index_atom_expression : $ => seq(
      choice(
        $.common_atom_subexpressions,
        // operands
        $.string,
        // atom expressions
        $.literal_value_atom_expression,
      ),
      $._t_openbracket,
      // TODO: allow_range = false
      $.rhs_expression,
      $._t_closebracket,
    ),

    slice_index_atom_expression_nlve : $ => seq(
      choice(
        $.common_atom_subexpressions_nlve,
        // operands
        $.string,
      ),
      $._t_openbracket,
      // TODO: allow_range = false
      $.rhs_expression,
      $._t_closebracket,
    ),

    matrix_index_atom_expression : $ => seq(
      choice(
        $.common_atom_subexpressions,
        // atom expressions
        $.literal_value_atom_expression,
      ),
      $.matrix_index_part,
    ),

    matrix_index_atom_expression_nlve : $ => seq(
      $.common_atom_subexpressions_nlve,
      $.matrix_index_part,
    ),

    // TODO: move to atom expression helpers
    matrix_index_part : $ => seq(
      $._t_openbracket,
      // TODO: allow_range = false
      $.rhs_expression,
      $._t_comma,
      // TODO: allow_range = false
      $.rhs_expression,
      $._t_closebracket,
    ),

    slice_atom_expression : $ => seq(
      choice(
        $.common_atom_subexpressions,
        // atom expressions
        $.literal_value_atom_expression,
      ),
      $.slice_part,
    ),

    slice_atom_expression_nlve : $ => seq(
      $.common_atom_subexpressions_nlve,
      $.slice_part,
    ),

    // TODO: move to atom expression helpers
    slice_part : $ => seq(
      $._t_openbracket,
      // TODO: allow_range = false
      optional($.rhs_expression),
      $._t_colon,
      // TODO: allow_range = false
      optional($.rhs_expression),
      $._t_closebracket,
    ),

    dereference_atom_expression : $ => seq(
      $.common_atom_subexpressions,
      $._t_pointer
    ),

    dereference_atom_expression_nlve : $ => seq(
      $.common_atom_subexpressions_nlve,
      $._t_pointer
    ),

    or_return_atom_expression : $ => /*prec('not_inline_or_branch', */seq(
      choice(
        $.common_atom_subexpressions,
        // operands
        $.number,
        $.rune,
        // atom expressions
        $.matrix_index_atom_expression,
      ),
      $._kw_or_return,
    )/*)*/,

    or_return_atom_expression_nlve : $ => /*prec('not_inline_or_branch', */seq(
      choice(
        $.common_atom_subexpressions_nlve,
        // operands
        $.number,
        $.rune,
        // atom expressions
        $.matrix_index_atom_expression_nlve,
      ),
      $._kw_or_return,
    )/*)*/,

    or_continue_atom_expression : $ => /*prec('not_inline_or_branch', */seq(
      choice(
        $.common_atom_subexpressions,
        // operands
        $.number,
        $.rune,
        // atom expressions
        $.matrix_index_atom_expression,
      ),
      $._kw_or_continue,
      optional($.identifier),
    )/*)*/,

    or_continue_atom_expression_nlve : $ => /*prec('not_inline_or_branch', */seq(
      choice(
        $.common_atom_subexpressions_nlve,
        // operands
        $.number,
        $.rune,
        // atom expressions
        $.matrix_index_atom_expression_nlve,
      ),
      $._kw_or_continue,
      optional($.identifier),
    )/*)*/,

    or_break_atom_expression : $ => /*prec('not_inline_or_branch', */seq(
      choice(
        $.common_atom_subexpressions,
        // operands
        $.number,
        $.rune,
        // atom expressions
        $.matrix_index_atom_expression,
      ),
      $._kw_or_break,
      optional($.identifier),
    )/*)*/,

    or_break_atom_expression_nlve : $ => /*prec('not_inline_or_branch', */seq(
      choice(
        $.common_atom_subexpressions_nlve,
        // operands
        $.number,
        $.rune,
        // atom expressions
        $.matrix_index_atom_expression_nlve,
      ),
      $._kw_or_break,
      optional($.identifier),
    )/*)*/,

    literal_value_atom_expression : $ => seq(
      // TODO: this probably should just be
      // $._type_maybe_in_parentheses, but probably without the procedure type and poly_type
      choice(
        // operands
        $.identifier,
        $.parentheses_expression,
        $.directive_with_type,
        $.pointer_type,
        $.slicelike_type,
        $.map_type,
        $.matrix_type,
        $.bit_field_type,
        $.struct_type,
        $.union_type,
        $.enum_type,
        $.bit_set_type,
        // atom expressions
        $.selector_atom_expression, // type like "package.Some_Type"
        $.call_atom_expression, // type like "Some_Poly_Type(int)"
      ),
      $.literal_value,
    ),

    // krnowak: helpers for operands
    //
    // TODO: move it to be above atom sub expressions, but below
    // operands

    field_prefix : $ => choice(
      $._kw_using,
      seq(
        $._t_hash,
        choice(
          $._d_by_ptr,
          $._d_any_int,
          $._d_c_vararg,
          $._d_const,
          $._d_no_alias,
          $._d_no_broadcast,
          $._d_subtype,
        ),
      ),
    ),

    //
    // krnowak: types
    //

    // parse_type_or_ident, a subset of atom expression
    type : $ => choice(
      $.identifier,
      $.package_type,
      $.instatiated_type,
      $.instantiated_package_type,
      $.directive_with_type,
      $.procedure_type,
      $.poly_type,
      $.pointer_type,
      $.slicelike_type,
      $.map_type,
      $.matrix_type,
      $.bit_field_type,
      $.enum_type,
      $.bit_set_type,
      $.struct_type,
      $.union_type,
      $.ternary_type,
    ),

    package_type : $ => seq(
      $.identifier,
      $._t_period,
      $.identifier,
    ),

    instatiated_type : $ => seq(
      $.identifier,
      $._t_openparen,
      $._rhs_expression_list_trailing,
      $._t_closeparen,
    ),

    instantiated_package_type : $ => seq(
      $.identifier,
      $._t_period,
      $.identifier,
      $._t_openparen,
      $._rhs_expression_list_trailing,
      $._t_closeparen,
    ),

    ternary_type : $ => seq(
      $._t_openparen,
      $.type,
      $._kw_when,
      // expr_level > 0
      $.rhs_expression,
      $._kw_else,
      $.type,
      $._t_closeparen
    ),

    // parse_type
    _type_maybe_in_parentheses : $ => choice(
      seq(
        $._t_openparen,
        $._type_maybe_in_parentheses,
        $._t_closeparen
      ),
      $.type,
    ),

    // krnowak: values

    literal_value : $ => seq(
      $._t_openbrace,
      // TODO: expr_level = 0
      optional(choice(
        $.value_list_trailing,
        $.key_value_list_trailing,
      )),
      $._t_closebrace,
    ),

    value_list_trailing : $ => repeatComma1Trailing($, $.value),

    key_value_list_trailing : $ => repeatComma1Trailing($, $.key_value)
,
    key_value : $ => seq(
      $.value,
      $._t_eq,
      $.value,
    ),

    // parse_value
    value : $ => choice(
      // TODO: allow range = true
      $.rhs_expression,
    ),

    number : $ => choice(
      $.integer,
      $.float,
      $.imag,
    ),

    // krnowak: lists

    _lhs_expression_list : $ => repeatComma1($, $.lhs_expression),

    _lhs_expression_cc_list : $ => repeatComma1($, $.lhs_expression_cc),

    _lhs_expression_cc_nie_list : $ => repeatComma1($, $.lhs_expression_cc_nie),

    _rhs_expression_list : $ => repeatComma1($, $.rhs_expression),

    _rhs_expression_list_trailing : $ => repeatComma1Trailing($, $.rhs_expression),

    _rhs_expression_cc_list : $ => repeatComma1($, $.rhs_expression_cc),

    _rhs_expression_cc_nie_list : $ => repeatComma1($, $.rhs_expression_cc_nie),

    _identifier_list : $ => repeatComma1($, $.identifier),

    _identifier_or_poly_type_list : $ => repeatComma1($, $.field),

    field : $ => seq(
      repeat($.field_prefix),
      choice(
        $.identifier,
        $.poly_type,
      ),
    ),

    // krnowak: misc

    _call_paren_part : $ => seq(
      $._t_openparen,
      optional($._call_arg_list),
      $._t_closeparen,
    ),

    _call_arg_list : $ => repeatComma1Trailing($, $._call_arg),

    _call_arg : $ => choice(
      seq(
        optional($._t_ellipsis),
        // TODO: expr_level = 0
        $.rhs_expression,
      ),
      seq(
        $.identifier,
        optional(seq(
          $._t_eq,
          $.value,
        )),
      ),
    ),

    _statement_separator : $ => choice(
      $._t_semicolon,
      $._implicit_semicolon,
      $._wide_implicit_semicolon,
    ),

    comment : $ => choice(
      $._ml_comment,
      $._sl_comment,
    ),
  }
});

function repeatComma1Trailing(dollar, rule) {
  return repeatSep1Trailing(
    rule,
    dollar._t_comma,
    dollar._t_comma,
  );
}

function repeatCommaTrailing(dollar, rule) {
  return repeatSepTrailing(
    rule,
    dollar._t_comma,
    dollar._t_comma,
  );
}

function repeatComma1(dollar, rule) {
  return repeatSep1(
    rule,
    dollar._t_comma,
  );
}

function repeatComma(dollar, rule) {
  return repeatSep(
    rule,
    dollar._t_comma,
  );
}

function repeatSepTrailing(rule, separator_rule, trailing_separator_rule) {
  return optional(repeatSep1Trailing(rule, separator_rule, trailing_separator_rule));
}

function repeatSep1Trailing(rule, separator_rule, trailing_separator_rule) {
  return seq(
    rule,
    repeat(seq(separator_rule, rule)),
    optional(trailing_separator_rule),
  );
}

function repeatSep(rule, separator_rule) {
  return optional(repeatSep1(rule, separator_rule));
}

function repeatSep1(rule, separator_rule) {
  return seq(
    rule,
    repeat(seq(separator_rule, rule)),
  );
}

function binOpPrecs(dollar, flags) {
  var bin_op_precs = [
    // ellipsis is never a valid operator
    //
    // we could make range operators optional, but it's so viral it's
    // a pita - basically would need to fork all the expressions, even
    // atom ones, so the parentheses_expression would keep the "no
    // range operators" flag.
    [dollar._t_rangefull, 2],
    [dollar._t_rangehalf, 2],
    [dollar._kw_or_else, 1],
    [dollar._t_add, 6],
    [dollar._t_and, 7],
    [dollar._t_andnot, 7],
    [dollar._t_cmpand, 4],
    [dollar._t_cmpeq, 5],
    [dollar._t_noteq, 5],
    [dollar._t_cmpor, 3],
    [dollar._t_gt, 5],
    [dollar._t_gteq, 5],
    [dollar._t_lt, 5],
    [dollar._t_lteq, 5],
    [dollar._t_mod, 7],
    [dollar._t_modmod, 7],
    [dollar._t_mul, 7],
    [dollar._t_or, 6],
    [dollar._t_quo, 7],
    [dollar._t_shl, 7],
    [dollar._t_shr, 7],
    [dollar._t_sub, 6],
    [dollar._t_xor, 6],
  ];
  if ((flags & NO_IN_OPERATORS) == 0) {
    bin_op_precs.push(
      [dollar._kw_in, 6],
      [dollar._kw_not_in, 6],
    );
  }
  return bin_op_precs;
}
