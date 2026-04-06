// THIS FILE IS GENERATED, DO NOT EDIT

package ac

TS_Element :: enum {
    Nil_Element,
    Assign_Statement,
    Attribute,
    Attribute_Statement,
    Attributes,
    Bit_Field_Entry,
    Bit_Field_Type,
    Bit_Set_Type,
    Block_Statement,
    Break_Statement,
    Call_Atom_Expression,
    Call_Atom_Expression_Nlve,
    Call_Directive_Statement,
    Call_Selector_Atom_Expression,
    Call_Selector_Atom_Expression_Nlve,
    Calling_Convention,
    Case_Clause,
    Cast_Part,
    Comment,
    Common_Atom_Subexpressions,
    Common_Atom_Subexpressions_Nlve,
    Const_Declaration,
    Continue_Statement,
    Default_Value,
    Defer_Statement,
    Dereference_Atom_Expression,
    Dereference_Atom_Expression_Nlve,
    Directive_Call,
    Directive_Statement,
    Directive_With_Type,
    Distinct_Type,
    Diverging,
    Do_Statement,
    Enum_Field_Entries,
    Enum_Field_Entry,
    Enum_Type,
    Expression_Statement,
    Fallthrough_Statement,
    Field,
    Field_Prefix,
    File_Tag,
    Float,
    For_Init,
    For_Post,
    For_Statement,
    Foreign_Block_Declaration,
    Foreign_Import_Declaration,
    Identifier,
    Identifier_Struct_Field_List,
    If_Statement,
    Imag,
    Implicit_Selector_Expression,
    Import_Declaration,
    In_Statement_Nfs_Cc_Nie,
    Init_Only_Switch_Control,
    Init_Tag_Switch_Control,
    Inline_Asm,
    Inline_Asm_Directive,
    Inline_Asm_Parameters_And_Results,
    Inline_Directive,
    Inline_Directive_Expression,
    Inline_Directive_Expression_Nlve,
    Inline_Directive_Nlve,
    Inline_Directive_Or_Branch_Expression,
    Inline_Directive_Or_Branch_Expression_Nlve,
    Inline_Directive_Paren_Expression,
    Inline_Directive_Statement,
    Instantiated_Package_Type,
    Instatiated_Type,
    Integer,
    Invalid,
    Just_Directive,
    Key_Value,
    Key_Value_List_Trailing,
    Label,
    Label_Statement,
    Labeled_Block_Statement,
    Labeled_For_Statement,
    Labeled_If_Statement,
    Labeled_Partial_Switch_Directive_Statement,
    Labeled_Reverse_For_Directive_Statement,
    Labeled_Switch_Statement,
    Lhs_Auto_Cast_Expression,
    Lhs_Auto_Cast_Expression_Cc,
    Lhs_Binary_Expression,
    Lhs_Binary_Expression_Cc,
    Lhs_Binary_Expression_Cc_Nie,
    Lhs_Cast_Expression,
    Lhs_Cast_Expression_Cc,
    Lhs_Prefix_Unary_Expression,
    Lhs_Prefix_Unary_Expression_Cc,
    Lhs_Ternary_Expression,
    Lhs_Ternary_Expression_Cc,
    Lhs_Ternary_Expression_Cc_Nie,
    Lhs_Transmute_Expression,
    Lhs_Transmute_Expression_Cc,
    Literal_Value,
    Literal_Value_Atom_Expression,
    Map_Type,
    Matrix_Index_Atom_Expression,
    Matrix_Index_Atom_Expression_Nlve,
    Matrix_Index_Part,
    Matrix_Type,
    Must_Tail_Directive,
    Must_Tail_Directive_Expression,
    Must_Tail_Directive_Expression_Nlve,
    Must_Tail_Directive_Nlve,
    Must_Tail_Directive_Statement,
    Names,
    Number,
    Operand,
    Or_Break_Atom_Expression,
    Or_Break_Atom_Expression_Nlve,
    Or_Continue_Atom_Expression,
    Or_Continue_Atom_Expression_Nlve,
    Or_Return_Atom_Expression,
    Or_Return_Atom_Expression_Nlve,
    Package,
    Package_Name,
    Package_Type,
    Parameter_Pack,
    Parameters,
    Paren_Literal_Value,
    Paren_Literal_Value_Nlve,
    Parentheses_Expression,
    Partial_Directive_Literal_Value,
    Partial_Directive_Literal_Value_Nlve,
    Partial_Switch_Directive_Statement,
    Pointer_Type,
    Poly_Type,
    Procedure_Group,
    Procedure_Literal,
    Procedure_Result,
    Procedure_Trailing_Directive,
    Procedure_Type,
    Return_Statement,
    Reverse_For_Directive_Statement,
    Rhs_Auto_Cast_Expression,
    Rhs_Auto_Cast_Expression_Cc,
    Rhs_Binary_Expression,
    Rhs_Binary_Expression_Cc,
    Rhs_Binary_Expression_Cc_Nie,
    Rhs_Cast_Expression,
    Rhs_Cast_Expression_Cc,
    Rhs_Prefix_Unary_Expression,
    Rhs_Prefix_Unary_Expression_Cc,
    Rhs_Ternary_Expression,
    Rhs_Ternary_Expression_Cc,
    Rhs_Ternary_Expression_Cc_Nie,
    Rhs_Transmute_Expression,
    Rhs_Transmute_Expression_Cc,
    Rune,
    Selector_Atom_Expression,
    Selector_Atom_Expression_Nlve,
    Shebang,
    Simple_Attribute,
    Simple_Statement_Nfs_Cc,
    Simple_Statement_Nfs_Cc_Nie,
    Slice_Atom_Expression,
    Slice_Atom_Expression_Nlve,
    Slice_Index_Atom_Expression,
    Slice_Index_Atom_Expression_Nlve,
    Slice_Part,
    Slicelike_Type,
    Source_File,
    Statement_Directive_Statement,
    String,
    Struct_Directive,
    Struct_Field_List,
    Struct_Type,
    Struct_Union_Polyparam_Field,
    Struct_Union_Polyparam_Field_List,
    Struct_Union_Polyparams,
    Switch_Control,
    Switch_Statement,
    Tag,
    Tag_Only_Switch_Control,
    Ternary_Type,
    Transmute_Part,
    Type,
    Type_Assertion_Atom_Expression,
    Type_Assertion_Atom_Expression_Nlve,
    Type_Assertion_Part,
    Type_Inference_Atom_Expression,
    Type_Inference_Atom_Expression_Nlve,
    Type_Switch_Control,
    Union_Directive,
    Union_Field_List,
    Union_Type,
    Unroll_For_Directive_Statement,
    Unroll_Parameter,
    Unroll_Parameter_List,
    Unroll_Parameters,
    Using_Statement,
    Value,
    Value_Attribute,
    Value_List_Trailing,
    Values,
    Var_Declaration,
    Variadic_Type,
    When_Statement,
    Where_Clauses,
}

make_ts_elements_map :: proc() -> map[string]TS_Element {
    m := make(map[string]TS_Element, 2 * (201 + 1))
    m[""] = .Nil_Element
    m["assign_statement"] = .Assign_Statement
    m["attribute"] = .Attribute
    m["attribute_statement"] = .Attribute_Statement
    m["attributes"] = .Attributes
    m["bit_field_entry"] = .Bit_Field_Entry
    m["bit_field_type"] = .Bit_Field_Type
    m["bit_set_type"] = .Bit_Set_Type
    m["block_statement"] = .Block_Statement
    m["break_statement"] = .Break_Statement
    m["call_atom_expression"] = .Call_Atom_Expression
    m["call_atom_expression_nlve"] = .Call_Atom_Expression_Nlve
    m["call_directive_statement"] = .Call_Directive_Statement
    m["call_selector_atom_expression"] = .Call_Selector_Atom_Expression
    m["call_selector_atom_expression_nlve"] = .Call_Selector_Atom_Expression_Nlve
    m["calling_convention"] = .Calling_Convention
    m["case_clause"] = .Case_Clause
    m["cast_part"] = .Cast_Part
    m["comment"] = .Comment
    m["common_atom_subexpressions"] = .Common_Atom_Subexpressions
    m["common_atom_subexpressions_nlve"] = .Common_Atom_Subexpressions_Nlve
    m["const_declaration"] = .Const_Declaration
    m["continue_statement"] = .Continue_Statement
    m["default_value"] = .Default_Value
    m["defer_statement"] = .Defer_Statement
    m["dereference_atom_expression"] = .Dereference_Atom_Expression
    m["dereference_atom_expression_nlve"] = .Dereference_Atom_Expression_Nlve
    m["directive_call"] = .Directive_Call
    m["directive_statement"] = .Directive_Statement
    m["directive_with_type"] = .Directive_With_Type
    m["distinct_type"] = .Distinct_Type
    m["diverging"] = .Diverging
    m["do_statement"] = .Do_Statement
    m["enum_field_entries"] = .Enum_Field_Entries
    m["enum_field_entry"] = .Enum_Field_Entry
    m["enum_type"] = .Enum_Type
    m["expression_statement"] = .Expression_Statement
    m["fallthrough_statement"] = .Fallthrough_Statement
    m["field"] = .Field
    m["field_prefix"] = .Field_Prefix
    m["file_tag"] = .File_Tag
    m["float"] = .Float
    m["for_init"] = .For_Init
    m["for_post"] = .For_Post
    m["for_statement"] = .For_Statement
    m["foreign_block_declaration"] = .Foreign_Block_Declaration
    m["foreign_import_declaration"] = .Foreign_Import_Declaration
    m["identifier"] = .Identifier
    m["identifier_struct_field_list"] = .Identifier_Struct_Field_List
    m["if_statement"] = .If_Statement
    m["imag"] = .Imag
    m["implicit_selector_expression"] = .Implicit_Selector_Expression
    m["import_declaration"] = .Import_Declaration
    m["in_statement_nfs_cc_nie"] = .In_Statement_Nfs_Cc_Nie
    m["init_only_switch_control"] = .Init_Only_Switch_Control
    m["init_tag_switch_control"] = .Init_Tag_Switch_Control
    m["inline_asm"] = .Inline_Asm
    m["inline_asm_directive"] = .Inline_Asm_Directive
    m["inline_asm_parameters_and_results"] = .Inline_Asm_Parameters_And_Results
    m["inline_directive"] = .Inline_Directive
    m["inline_directive_expression"] = .Inline_Directive_Expression
    m["inline_directive_expression_nlve"] = .Inline_Directive_Expression_Nlve
    m["inline_directive_nlve"] = .Inline_Directive_Nlve
    m["inline_directive_or_branch_expression"] = .Inline_Directive_Or_Branch_Expression
    m["inline_directive_or_branch_expression_nlve"] = .Inline_Directive_Or_Branch_Expression_Nlve
    m["inline_directive_paren_expression"] = .Inline_Directive_Paren_Expression
    m["inline_directive_statement"] = .Inline_Directive_Statement
    m["instantiated_package_type"] = .Instantiated_Package_Type
    m["instatiated_type"] = .Instatiated_Type
    m["integer"] = .Integer
    m["invalid"] = .Invalid
    m["just_directive"] = .Just_Directive
    m["key_value"] = .Key_Value
    m["key_value_list_trailing"] = .Key_Value_List_Trailing
    m["label"] = .Label
    m["label_statement"] = .Label_Statement
    m["labeled_block_statement"] = .Labeled_Block_Statement
    m["labeled_for_statement"] = .Labeled_For_Statement
    m["labeled_if_statement"] = .Labeled_If_Statement
    m["labeled_partial_switch_directive_statement"] = .Labeled_Partial_Switch_Directive_Statement
    m["labeled_reverse_for_directive_statement"] = .Labeled_Reverse_For_Directive_Statement
    m["labeled_switch_statement"] = .Labeled_Switch_Statement
    m["lhs_auto_cast_expression"] = .Lhs_Auto_Cast_Expression
    m["lhs_auto_cast_expression_cc"] = .Lhs_Auto_Cast_Expression_Cc
    m["lhs_binary_expression"] = .Lhs_Binary_Expression
    m["lhs_binary_expression_cc"] = .Lhs_Binary_Expression_Cc
    m["lhs_binary_expression_cc_nie"] = .Lhs_Binary_Expression_Cc_Nie
    m["lhs_cast_expression"] = .Lhs_Cast_Expression
    m["lhs_cast_expression_cc"] = .Lhs_Cast_Expression_Cc
    m["lhs_prefix_unary_expression"] = .Lhs_Prefix_Unary_Expression
    m["lhs_prefix_unary_expression_cc"] = .Lhs_Prefix_Unary_Expression_Cc
    m["lhs_ternary_expression"] = .Lhs_Ternary_Expression
    m["lhs_ternary_expression_cc"] = .Lhs_Ternary_Expression_Cc
    m["lhs_ternary_expression_cc_nie"] = .Lhs_Ternary_Expression_Cc_Nie
    m["lhs_transmute_expression"] = .Lhs_Transmute_Expression
    m["lhs_transmute_expression_cc"] = .Lhs_Transmute_Expression_Cc
    m["literal_value"] = .Literal_Value
    m["literal_value_atom_expression"] = .Literal_Value_Atom_Expression
    m["map_type"] = .Map_Type
    m["matrix_index_atom_expression"] = .Matrix_Index_Atom_Expression
    m["matrix_index_atom_expression_nlve"] = .Matrix_Index_Atom_Expression_Nlve
    m["matrix_index_part"] = .Matrix_Index_Part
    m["matrix_type"] = .Matrix_Type
    m["must_tail_directive"] = .Must_Tail_Directive
    m["must_tail_directive_expression"] = .Must_Tail_Directive_Expression
    m["must_tail_directive_expression_nlve"] = .Must_Tail_Directive_Expression_Nlve
    m["must_tail_directive_nlve"] = .Must_Tail_Directive_Nlve
    m["must_tail_directive_statement"] = .Must_Tail_Directive_Statement
    m["names"] = .Names
    m["number"] = .Number
    m["operand"] = .Operand
    m["or_break_atom_expression"] = .Or_Break_Atom_Expression
    m["or_break_atom_expression_nlve"] = .Or_Break_Atom_Expression_Nlve
    m["or_continue_atom_expression"] = .Or_Continue_Atom_Expression
    m["or_continue_atom_expression_nlve"] = .Or_Continue_Atom_Expression_Nlve
    m["or_return_atom_expression"] = .Or_Return_Atom_Expression
    m["or_return_atom_expression_nlve"] = .Or_Return_Atom_Expression_Nlve
    m["package"] = .Package
    m["package_name"] = .Package_Name
    m["package_type"] = .Package_Type
    m["parameter_pack"] = .Parameter_Pack
    m["parameters"] = .Parameters
    m["paren_literal_value"] = .Paren_Literal_Value
    m["paren_literal_value_nlve"] = .Paren_Literal_Value_Nlve
    m["parentheses_expression"] = .Parentheses_Expression
    m["partial_directive_literal_value"] = .Partial_Directive_Literal_Value
    m["partial_directive_literal_value_nlve"] = .Partial_Directive_Literal_Value_Nlve
    m["partial_switch_directive_statement"] = .Partial_Switch_Directive_Statement
    m["pointer_type"] = .Pointer_Type
    m["poly_type"] = .Poly_Type
    m["procedure_group"] = .Procedure_Group
    m["procedure_literal"] = .Procedure_Literal
    m["procedure_result"] = .Procedure_Result
    m["procedure_trailing_directive"] = .Procedure_Trailing_Directive
    m["procedure_type"] = .Procedure_Type
    m["return_statement"] = .Return_Statement
    m["reverse_for_directive_statement"] = .Reverse_For_Directive_Statement
    m["rhs_auto_cast_expression"] = .Rhs_Auto_Cast_Expression
    m["rhs_auto_cast_expression_cc"] = .Rhs_Auto_Cast_Expression_Cc
    m["rhs_binary_expression"] = .Rhs_Binary_Expression
    m["rhs_binary_expression_cc"] = .Rhs_Binary_Expression_Cc
    m["rhs_binary_expression_cc_nie"] = .Rhs_Binary_Expression_Cc_Nie
    m["rhs_cast_expression"] = .Rhs_Cast_Expression
    m["rhs_cast_expression_cc"] = .Rhs_Cast_Expression_Cc
    m["rhs_prefix_unary_expression"] = .Rhs_Prefix_Unary_Expression
    m["rhs_prefix_unary_expression_cc"] = .Rhs_Prefix_Unary_Expression_Cc
    m["rhs_ternary_expression"] = .Rhs_Ternary_Expression
    m["rhs_ternary_expression_cc"] = .Rhs_Ternary_Expression_Cc
    m["rhs_ternary_expression_cc_nie"] = .Rhs_Ternary_Expression_Cc_Nie
    m["rhs_transmute_expression"] = .Rhs_Transmute_Expression
    m["rhs_transmute_expression_cc"] = .Rhs_Transmute_Expression_Cc
    m["rune"] = .Rune
    m["selector_atom_expression"] = .Selector_Atom_Expression
    m["selector_atom_expression_nlve"] = .Selector_Atom_Expression_Nlve
    m["shebang"] = .Shebang
    m["simple_attribute"] = .Simple_Attribute
    m["simple_statement_nfs_cc"] = .Simple_Statement_Nfs_Cc
    m["simple_statement_nfs_cc_nie"] = .Simple_Statement_Nfs_Cc_Nie
    m["slice_atom_expression"] = .Slice_Atom_Expression
    m["slice_atom_expression_nlve"] = .Slice_Atom_Expression_Nlve
    m["slice_index_atom_expression"] = .Slice_Index_Atom_Expression
    m["slice_index_atom_expression_nlve"] = .Slice_Index_Atom_Expression_Nlve
    m["slice_part"] = .Slice_Part
    m["slicelike_type"] = .Slicelike_Type
    m["source_file"] = .Source_File
    m["statement_directive_statement"] = .Statement_Directive_Statement
    m["string"] = .String
    m["struct_directive"] = .Struct_Directive
    m["struct_field_list"] = .Struct_Field_List
    m["struct_type"] = .Struct_Type
    m["struct_union_polyparam_field"] = .Struct_Union_Polyparam_Field
    m["struct_union_polyparam_field_list"] = .Struct_Union_Polyparam_Field_List
    m["struct_union_polyparams"] = .Struct_Union_Polyparams
    m["switch_control"] = .Switch_Control
    m["switch_statement"] = .Switch_Statement
    m["tag"] = .Tag
    m["tag_only_switch_control"] = .Tag_Only_Switch_Control
    m["ternary_type"] = .Ternary_Type
    m["transmute_part"] = .Transmute_Part
    m["type"] = .Type
    m["type_assertion_atom_expression"] = .Type_Assertion_Atom_Expression
    m["type_assertion_atom_expression_nlve"] = .Type_Assertion_Atom_Expression_Nlve
    m["type_assertion_part"] = .Type_Assertion_Part
    m["type_inference_atom_expression"] = .Type_Inference_Atom_Expression
    m["type_inference_atom_expression_nlve"] = .Type_Inference_Atom_Expression_Nlve
    m["type_switch_control"] = .Type_Switch_Control
    m["union_directive"] = .Union_Directive
    m["union_field_list"] = .Union_Field_List
    m["union_type"] = .Union_Type
    m["unroll_for_directive_statement"] = .Unroll_For_Directive_Statement
    m["unroll_parameter"] = .Unroll_Parameter
    m["unroll_parameter_list"] = .Unroll_Parameter_List
    m["unroll_parameters"] = .Unroll_Parameters
    m["using_statement"] = .Using_Statement
    m["value"] = .Value
    m["value_attribute"] = .Value_Attribute
    m["value_list_trailing"] = .Value_List_Trailing
    m["values"] = .Values
    m["var_declaration"] = .Var_Declaration
    m["variadic_type"] = .Variadic_Type
    m["when_statement"] = .When_Statement
    m["where_clauses"] = .Where_Clauses
    return m
}

OD_Element :: enum {
    Nil_Element,
    Array_Type,
    Assign_Statement,
    Attribute,
    Auto_cast,
    Bad_Declaration,
    Bad_Expression,
    Bad_Statement,
    Basic_Directive,
    Basic_Literal,
    Binary_Expression,
    Bit_Field_Field,
    Bit_Field_Type,
    Bit_Set_Type,
    Block_Statement,
    Branch_Statement,
    Call_Expression,
    Case_Clause,
    Compound_Literal,
    Defer_Statement,
    Dereference_Expression,
    Distinct_Type,
    Dynamic_Array_Type,
    Ellipsis,
    Empty_Statement,
    Enum_Field_Value,
    Enum_Type,
    Expression_Statement,
    Field,
    Field_List,
    Field_Value,
    Fixed_Capacity_Dynamic_Array_Type,
    For_Statement,
    Foreign_Block_Declaration,
    Foreign_Import_Declaration,
    Helper_Type,
    Identifier,
    If_Statement,
    Implicit,
    Implicit_Selector_Expression,
    Import_Declaration,
    Index_Expression,
    Inline_Asm_Expression,
    Label,
    Map_Type,
    Matrix_Index_Expression,
    Matrix_Type,
    Multi_Pointer_Type,
    Or_Branch_Expression,
    Or_else_Expression,
    Or_return_Expression,
    Package_Declaration,
    Parentheses_Expression,
    Pointer_Type,
    Polymorphic_Type,
    Procedure_Group,
    Procedure_Literal,
    Procedure_Type,
    Range_Statement,
    Relative_Type,
    Return_Statement,
    Selector_Call_Expression,
    Selector_Expression,
    Slice_Expression,
    Source_File,
    Struct_Type,
    Switch_Statement,
    Tag_Expression,
    Ternary_If_Expression,
    Ternary_When_Expression,
    Type_Assertion,
    Type_Cast,
    Type_Switch_Statement,
    Typeid,
    Unary_Expression,
    Uninitialized_Value,
    Union_Type,
    Unroll_Range_Statement,
    Using_Statement,
    Value_Declaration,
    When_Statement,
}

make_od_elements_map :: proc() -> map[string]OD_Element {
    m := make(map[string]OD_Element, 2 * (80 + 1))
    m[""] = .Nil_Element
    m["array-type"] = .Array_Type
    m["assign-statement"] = .Assign_Statement
    m["attribute"] = .Attribute
    m["auto_cast"] = .Auto_cast
    m["bad-declaration"] = .Bad_Declaration
    m["bad-expression"] = .Bad_Expression
    m["bad-statement"] = .Bad_Statement
    m["basic-directive"] = .Basic_Directive
    m["basic-literal"] = .Basic_Literal
    m["binary-expression"] = .Binary_Expression
    m["bit-field-field"] = .Bit_Field_Field
    m["bit-field-type"] = .Bit_Field_Type
    m["bit-set-type"] = .Bit_Set_Type
    m["block-statement"] = .Block_Statement
    m["branch-statement"] = .Branch_Statement
    m["call-expression"] = .Call_Expression
    m["case-clause"] = .Case_Clause
    m["compound-literal"] = .Compound_Literal
    m["defer-statement"] = .Defer_Statement
    m["dereference-expression"] = .Dereference_Expression
    m["distinct-type"] = .Distinct_Type
    m["dynamic-array-type"] = .Dynamic_Array_Type
    m["ellipsis"] = .Ellipsis
    m["empty-statement"] = .Empty_Statement
    m["enum-field-value"] = .Enum_Field_Value
    m["enum-type"] = .Enum_Type
    m["expression-statement"] = .Expression_Statement
    m["field"] = .Field
    m["field-list"] = .Field_List
    m["field-value"] = .Field_Value
    m["fixed-capacity-dynamic-array-type"] = .Fixed_Capacity_Dynamic_Array_Type
    m["for-statement"] = .For_Statement
    m["foreign-block-declaration"] = .Foreign_Block_Declaration
    m["foreign-import-declaration"] = .Foreign_Import_Declaration
    m["helper-type"] = .Helper_Type
    m["identifier"] = .Identifier
    m["if-statement"] = .If_Statement
    m["implicit"] = .Implicit
    m["implicit-selector-expression"] = .Implicit_Selector_Expression
    m["import-declaration"] = .Import_Declaration
    m["index-expression"] = .Index_Expression
    m["inline-asm-expression"] = .Inline_Asm_Expression
    m["label"] = .Label
    m["map-type"] = .Map_Type
    m["matrix-index-expression"] = .Matrix_Index_Expression
    m["matrix-type"] = .Matrix_Type
    m["multi-pointer-type"] = .Multi_Pointer_Type
    m["or-branch-expression"] = .Or_Branch_Expression
    m["or_else-expression"] = .Or_else_Expression
    m["or_return-expression"] = .Or_return_Expression
    m["package-declaration"] = .Package_Declaration
    m["parentheses-expression"] = .Parentheses_Expression
    m["pointer-type"] = .Pointer_Type
    m["polymorphic-type"] = .Polymorphic_Type
    m["procedure-group"] = .Procedure_Group
    m["procedure-literal"] = .Procedure_Literal
    m["procedure-type"] = .Procedure_Type
    m["range-statement"] = .Range_Statement
    m["relative-type"] = .Relative_Type
    m["return-statement"] = .Return_Statement
    m["selector-call-expression"] = .Selector_Call_Expression
    m["selector-expression"] = .Selector_Expression
    m["slice-expression"] = .Slice_Expression
    m["source-file"] = .Source_File
    m["struct-type"] = .Struct_Type
    m["switch-statement"] = .Switch_Statement
    m["tag-expression"] = .Tag_Expression
    m["ternary-if-expression"] = .Ternary_If_Expression
    m["ternary-when-expression"] = .Ternary_When_Expression
    m["type-assertion"] = .Type_Assertion
    m["type-cast"] = .Type_Cast
    m["type-switch-statement"] = .Type_Switch_Statement
    m["typeid"] = .Typeid
    m["unary-expression"] = .Unary_Expression
    m["uninitialized-value"] = .Uninitialized_Value
    m["union-type"] = .Union_Type
    m["unroll-range-statement"] = .Unroll_Range_Statement
    m["using-statement"] = .Using_Statement
    m["value-declaration"] = .Value_Declaration
    m["when-statement"] = .When_Statement
    return m
}
