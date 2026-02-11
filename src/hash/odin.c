/* ANSI-C code produced by gperf version 3.2.1 */
/* Command-line: gperf --multiple-iterations=100 src/hash/word-list  */
/* Computed positions: -k'1,3,6,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif

#line 16 "src/hash/word-list"
struct OdinKwad { int kwad_offset; uint16_t valid_symbols_idx; uint8_t type; };

#define ODIN_KWAD_TOTAL_KEYWORDS 144
#define ODIN_KWAD_MIN_WORD_LENGTH 2
#define ODIN_KWAD_MAX_WORD_LENGTH 26
#define ODIN_KWAD_MIN_HASH_VALUE 14
#define ODIN_KWAD_MAX_HASH_VALUE 248
/* maximum key range = 235, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
odin_kwad_hash (register const char *str, register size_t len)
{
  static const unsigned char asso_values[] =
    {
      249, 249, 249, 249, 249, 249, 249, 249, 249, 249,
      249, 249, 249, 249, 249, 249, 249, 249, 249, 249,
      249, 249, 249, 249, 249, 249, 249, 249, 249, 249,
      249, 249, 249, 249, 249, 249, 249, 249, 249, 249,
      249, 249, 249, 249, 249, 249, 249, 249, 249, 249,
      249, 249, 249, 249, 249, 249, 249, 249, 249, 249,
      249, 249, 249, 249, 249, 249, 249, 249, 249, 249,
      249, 249, 249, 249, 249, 249, 249, 249, 249, 249,
      249, 249, 249, 249, 249, 249, 249, 249, 249, 249,
      249, 249, 249, 249, 249,  75, 249,  36, 116,  53,
        2,   4,  23,  10,  63,  61,  27,  10,   6,  99,
        3,  70,  43,   6,   1,   9,   1,  68,  14,  72,
       39, 127, 249, 249, 249, 249, 249, 249
    };
  register unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[5]];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 5:
      case 4:
      case 3:
        hval += asso_values[(unsigned char)str[2]];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 2:
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}

struct odin_kwad_string_pool_t
  {
    char odin_kwad_string_pool_str14[sizeof("return")];
    char odin_kwad_string_pool_str15[sizeof("test")];
    char odin_kwad_string_pool_str16[sizeof("not_in")];
    char odin_kwad_string_pool_str17[sizeof("line")];
    char odin_kwad_string_pool_str18[sizeof("struct")];
    char odin_kwad_string_pool_str19[sizeof("require")];
    char odin_kwad_string_pool_str21[sizeof("else")];
    char odin_kwad_string_pool_str22[sizeof("thread_local")];
    char odin_kwad_string_pool_str23[sizeof("distinct")];
    char odin_kwad_string_pool_str24[sizeof("tag")];
    char odin_kwad_string_pool_str25[sizeof("link_name")];
    char odin_kwad_string_pool_str27[sizeof("disabled")];
    char odin_kwad_string_pool_str28[sizeof("for")];
    char odin_kwad_string_pool_str30[sizeof("linkage")];
    char odin_kwad_string_pool_str31[sizeof("defer")];
    char odin_kwad_string_pool_str32[sizeof("require_results")];
    char odin_kwad_string_pool_str33[sizeof("link_section")];
    char odin_kwad_string_pool_str34[sizeof("require_target_feature")];
    char odin_kwad_string_pool_str35[sizeof("reverse")];
    char odin_kwad_string_pool_str36[sizeof("side_effects")];
    char odin_kwad_string_pool_str37[sizeof("file")];
    char odin_kwad_string_pool_str38[sizeof("defined")];
    char odin_kwad_string_pool_str39[sizeof("deferred_out")];
    char odin_kwad_string_pool_str40[sizeof("deferred_in")];
    char odin_kwad_string_pool_str41[sizeof("att")];
    char odin_kwad_string_pool_str42[sizeof("deferred_in_out")];
    char odin_kwad_string_pool_str43[sizeof("deferred_none")];
    char odin_kwad_string_pool_str44[sizeof("foreign")];
    char odin_kwad_string_pool_str45[sizeof("deferred_in_by_ptr")];
    char odin_kwad_string_pool_str46[sizeof("deferred_out_by_ptr")];
    char odin_kwad_string_pool_str48[sizeof("load")];
    char odin_kwad_string_pool_str49[sizeof("deferred_in_out_by_ptr")];
    char odin_kwad_string_pool_str52[sizeof("type")];
    char odin_kwad_string_pool_str53[sizeof("assert")];
    char odin_kwad_string_pool_str54[sizeof("typeid")];
    char odin_kwad_string_pool_str55[sizeof("export")];
    char odin_kwad_string_pool_str58[sizeof("all_or_none")];
    char odin_kwad_string_pool_str59[sizeof("sparse")];
    char odin_kwad_string_pool_str60[sizeof("default_calling_convention")];
    char odin_kwad_string_pool_str62[sizeof("const")];
    char odin_kwad_string_pool_str63[sizeof("shared_nil")];
    char odin_kwad_string_pool_str65[sizeof("cold")];
    char odin_kwad_string_pool_str66[sizeof("in")];
    char odin_kwad_string_pool_str67[sizeof("cast")];
    char odin_kwad_string_pool_str68[sizeof("link_suffix")];
    char odin_kwad_string_pool_str69[sizeof("enable_target_feature")];
    char odin_kwad_string_pool_str70[sizeof("case")];
    char odin_kwad_string_pool_str71[sizeof("continue")];
    char odin_kwad_string_pool_str73[sizeof("intel")];
    char odin_kwad_string_pool_str74[sizeof("do")];
    char odin_kwad_string_pool_str75[sizeof("column_major")];
    char odin_kwad_string_pool_str78[sizeof("caller_location")];
    char odin_kwad_string_pool_str80[sizeof("caller_expression")];
    char odin_kwad_string_pool_str81[sizeof("rodata")];
    char odin_kwad_string_pool_str82[sizeof("config")];
    char odin_kwad_string_pool_str83[sizeof("when")];
    char odin_kwad_string_pool_str84[sizeof("soa")];
    char odin_kwad_string_pool_str85[sizeof("where")];
    char odin_kwad_string_pool_str86[sizeof("if")];
    char odin_kwad_string_pool_str87[sizeof("unroll")];
    char odin_kwad_string_pool_str88[sizeof("raw_union")];
    char odin_kwad_string_pool_str89[sizeof("exists")];
    char odin_kwad_string_pool_str91[sizeof("fini")];
    char odin_kwad_string_pool_str92[sizeof("type_assert")];
    char odin_kwad_string_pool_str93[sizeof("partial")];
    char odin_kwad_string_pool_str94[sizeof("ignore_duplicates")];
    char odin_kwad_string_pool_str95[sizeof("optional_ok")];
    char odin_kwad_string_pool_str96[sizeof("no_nil")];
    char odin_kwad_string_pool_str99[sizeof("optional_allocator_error")];
    char odin_kwad_string_pool_str100[sizeof("auto_cast")];
    char odin_kwad_string_pool_str101[sizeof("raddbg_type_view")];
    char odin_kwad_string_pool_str102[sizeof("link_prefix")];
    char odin_kwad_string_pool_str103[sizeof("context")];
    char odin_kwad_string_pool_str104[sizeof("panic")];
    char odin_kwad_string_pool_str105[sizeof("align")];
    char odin_kwad_string_pool_str106[sizeof("packed")];
    char odin_kwad_string_pool_str107[sizeof("extra_linker_flags")];
    char odin_kwad_string_pool_str108[sizeof("no_instrumentation")];
    char odin_kwad_string_pool_str109[sizeof("no_sanitize_address")];
    char odin_kwad_string_pool_str110[sizeof("deprecated")];
    char odin_kwad_string_pool_str111[sizeof("objc_type")];
    char odin_kwad_string_pool_str112[sizeof("import")];
    char odin_kwad_string_pool_str113[sizeof("objc_name")];
    char odin_kwad_string_pool_str114[sizeof("simd")];
    char odin_kwad_string_pool_str115[sizeof("force_inline")];
    char odin_kwad_string_pool_str116[sizeof("private")];
    char odin_kwad_string_pool_str117[sizeof("package")];
    char odin_kwad_string_pool_str118[sizeof("force_no_inline")];
    char odin_kwad_string_pool_str119[sizeof("row_major")];
    char odin_kwad_string_pool_str120[sizeof("objc_selector")];
    char odin_kwad_string_pool_str121[sizeof("c_vararg")];
    char odin_kwad_string_pool_str122[sizeof("simple")];
    char odin_kwad_string_pool_str124[sizeof("must_tail")];
    char odin_kwad_string_pool_str126[sizeof("dynamic")];
    char odin_kwad_string_pool_str127[sizeof("init")];
    char odin_kwad_string_pool_str128[sizeof("procedure")];
    char odin_kwad_string_pool_str129[sizeof("bit_set")];
    char odin_kwad_string_pool_str130[sizeof("objc_superclass")];
    char odin_kwad_string_pool_str131[sizeof("location")];
    char odin_kwad_string_pool_str135[sizeof("break")];
    char odin_kwad_string_pool_str136[sizeof("no_type_assert")];
    char odin_kwad_string_pool_str137[sizeof("union")];
    char odin_kwad_string_pool_str139[sizeof("hash")];
    char odin_kwad_string_pool_str140[sizeof("directory")];
    char odin_kwad_string_pool_str144[sizeof("using")];
    char odin_kwad_string_pool_str149[sizeof("transmute")];
    char odin_kwad_string_pool_str153[sizeof("optimization_mode")];
    char odin_kwad_string_pool_str156[sizeof("no_alias")];
    char odin_kwad_string_pool_str157[sizeof("static")];
    char odin_kwad_string_pool_str158[sizeof("or_return")];
    char odin_kwad_string_pool_str159[sizeof("instrumentation_exit")];
    char odin_kwad_string_pool_str160[sizeof("instrumentation_enter")];
    char odin_kwad_string_pool_str161[sizeof("no_broadcast")];
    char odin_kwad_string_pool_str163[sizeof("or_continue")];
    char odin_kwad_string_pool_str165[sizeof("or_else")];
    char odin_kwad_string_pool_str166[sizeof("fallthrough")];
    char odin_kwad_string_pool_str167[sizeof("or_break")];
    char odin_kwad_string_pool_str168[sizeof("objc_ivar")];
    char odin_kwad_string_pool_str169[sizeof("objc_class")];
    char odin_kwad_string_pool_str170[sizeof("proc")];
    char odin_kwad_string_pool_str171[sizeof("no_bounds_check")];
    char odin_kwad_string_pool_str172[sizeof("objc_context_provider")];
    char odin_kwad_string_pool_str173[sizeof("objc_implement")];
    char odin_kwad_string_pool_str174[sizeof("any_int")];
    char odin_kwad_string_pool_str175[sizeof("enum")];
    char odin_kwad_string_pool_str177[sizeof("load_hash")];
    char odin_kwad_string_pool_str179[sizeof("subtype")];
    char odin_kwad_string_pool_str180[sizeof("objc_is_class_method")];
    char odin_kwad_string_pool_str181[sizeof("min_field_align")];
    char odin_kwad_string_pool_str184[sizeof("matrix")];
    char odin_kwad_string_pool_str185[sizeof("load_directory")];
    char odin_kwad_string_pool_str188[sizeof("map")];
    char odin_kwad_string_pool_str189[sizeof("bit_field")];
    char odin_kwad_string_pool_str193[sizeof("align_stack")];
    char odin_kwad_string_pool_str199[sizeof("by_ptr")];
    char odin_kwad_string_pool_str202[sizeof("switch")];
    char odin_kwad_string_pool_str215[sizeof("bounds_check")];
    char odin_kwad_string_pool_str217[sizeof("max_field_align")];
    char odin_kwad_string_pool_str218[sizeof("priority_index")];
    char odin_kwad_string_pool_str223[sizeof("entry_point_only")];
    char odin_kwad_string_pool_str226[sizeof("no_sanitize_memory")];
    char odin_kwad_string_pool_str233[sizeof("branch_location")];
    char odin_kwad_string_pool_str237[sizeof("asm")];
    char odin_kwad_string_pool_str248[sizeof("builtin")];
  };
static const struct odin_kwad_string_pool_t odin_kwad_string_pool_contents =
  {
    "return",
    "test",
    "not_in",
    "line",
    "struct",
    "require",
    "else",
    "thread_local",
    "distinct",
    "tag",
    "link_name",
    "disabled",
    "for",
    "linkage",
    "defer",
    "require_results",
    "link_section",
    "require_target_feature",
    "reverse",
    "side_effects",
    "file",
    "defined",
    "deferred_out",
    "deferred_in",
    "att",
    "deferred_in_out",
    "deferred_none",
    "foreign",
    "deferred_in_by_ptr",
    "deferred_out_by_ptr",
    "load",
    "deferred_in_out_by_ptr",
    "type",
    "assert",
    "typeid",
    "export",
    "all_or_none",
    "sparse",
    "default_calling_convention",
    "const",
    "shared_nil",
    "cold",
    "in",
    "cast",
    "link_suffix",
    "enable_target_feature",
    "case",
    "continue",
    "intel",
    "do",
    "column_major",
    "caller_location",
    "caller_expression",
    "rodata",
    "config",
    "when",
    "soa",
    "where",
    "if",
    "unroll",
    "raw_union",
    "exists",
    "fini",
    "type_assert",
    "partial",
    "ignore_duplicates",
    "optional_ok",
    "no_nil",
    "optional_allocator_error",
    "auto_cast",
    "raddbg_type_view",
    "link_prefix",
    "context",
    "panic",
    "align",
    "packed",
    "extra_linker_flags",
    "no_instrumentation",
    "no_sanitize_address",
    "deprecated",
    "objc_type",
    "import",
    "objc_name",
    "simd",
    "force_inline",
    "private",
    "package",
    "force_no_inline",
    "row_major",
    "objc_selector",
    "c_vararg",
    "simple",
    "must_tail",
    "dynamic",
    "init",
    "procedure",
    "bit_set",
    "objc_superclass",
    "location",
    "break",
    "no_type_assert",
    "union",
    "hash",
    "directory",
    "using",
    "transmute",
    "optimization_mode",
    "no_alias",
    "static",
    "or_return",
    "instrumentation_exit",
    "instrumentation_enter",
    "no_broadcast",
    "or_continue",
    "or_else",
    "fallthrough",
    "or_break",
    "objc_ivar",
    "objc_class",
    "proc",
    "no_bounds_check",
    "objc_context_provider",
    "objc_implement",
    "any_int",
    "enum",
    "load_hash",
    "subtype",
    "objc_is_class_method",
    "min_field_align",
    "matrix",
    "load_directory",
    "map",
    "bit_field",
    "align_stack",
    "by_ptr",
    "switch",
    "bounds_check",
    "max_field_align",
    "priority_index",
    "entry_point_only",
    "no_sanitize_memory",
    "branch_location",
    "asm",
    "builtin"
  };
#define odin_kwad_string_pool ((const char *) &odin_kwad_string_pool_contents)

static const unsigned char odin_kwad_lengths[] =
  {
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     6,  4,  6,  4,  6,  7,  0,  4, 12,  8,  3,  9,  0,  8,
     3,  0,  7,  5, 15, 12, 22,  7, 12,  4,  7, 12, 11,  3,
    15, 13,  7, 18, 19,  0,  4, 22,  0,  0,  4,  6,  6,  6,
     0,  0, 11,  6, 26,  0,  5, 10,  0,  4,  2,  4, 11, 21,
     4,  8,  0,  5,  2, 12,  0,  0, 15,  0, 17,  6,  6,  4,
     3,  5,  2,  6,  9,  6,  0,  4, 11,  7, 17, 11,  6,  0,
     0, 24,  9, 16, 11,  7,  5,  5,  6, 18, 18, 19, 10,  9,
     6,  9,  4, 12,  7,  7, 15,  9, 13,  8,  6,  0,  9,  0,
     7,  4,  9,  7, 15,  8,  0,  0,  0,  5, 14,  5,  0,  4,
     9,  0,  0,  0,  5,  0,  0,  0,  0,  9,  0,  0,  0, 17,
     0,  0,  8,  6,  9, 20, 21, 12,  0, 11,  0,  7, 11,  8,
     9, 10,  4, 15, 21, 14,  7,  4,  0,  9,  0,  7, 20, 15,
     0,  0,  6, 14,  0,  0,  3,  9,  0,  0,  0, 11,  0,  0,
     0,  0,  0,  6,  0,  0,  6,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0, 12,  0, 15, 14,  0,  0,  0,  0, 16,
     0,  0, 18,  0,  0,  0,  0,  0,  0, 15,  0,  0,  0,  3,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7
  };

static const struct OdinKwad odin_kwads[] =
  {
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 25 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str14, ODIN_KWAD_RETURN, OdinTokenKeyword},
#line 105 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str15, ODIN_KWAD_TEST, OdinTokenAttribute},
#line 46 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str16, ODIN_KWAD_NOT_IN, OdinTokenKeyword},
#line 130 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str17, ODIN_KWAD_LINE, OdinTokenDirective},
#line 50 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str18, ODIN_KWAD_STRUCT, OdinTokenKeyword},
#line 99 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str19, ODIN_KWAD_REQUIRE, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 37 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str21, ODIN_KWAD_ELSE, OdinTokenKeyword},
#line 106 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str22, ODIN_KWAD_THREAD_LOCAL, OdinTokenAttribute},
#line 34 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str23, ODIN_KWAD_DISTINCT, OdinTokenKeyword},
#line 104 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str24, ODIN_KWAD_TAG, OdinTokenAttribute},
#line 79 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str25, ODIN_KWAD_LINK_NAME, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 68 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str27, ODIN_KWAD_DISABLED, OdinTokenAttribute},
#line 39 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str28, ODIN_KWAD_FOR, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 78 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str30, ODIN_KWAD_LINKAGE, OdinTokenAttribute},
#line 33 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str31, ODIN_KWAD_DEFER, OdinTokenKeyword},
#line 100 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str32, ODIN_KWAD_REQUIRE_RESULTS, OdinTokenAttribute},
#line 81 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str33, ODIN_KWAD_LINK_SECTION, OdinTokenAttribute},
#line 101 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str34, ODIN_KWAD_REQUIRE_TARGET_FEATURE, OdinTokenAttribute},
#line 150 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str35, ODIN_KWAD_REVERSE, OdinTokenDirective},
#line 153 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str36, ODIN_KWAD_SIDE_EFFECTS, OdinTokenDirective},
#line 125 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str37, ODIN_KWAD_FILE, OdinTokenDirective},
#line 122 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str38, ODIN_KWAD_DEFINED, OdinTokenDirective},
#line 65 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str39, ODIN_KWAD_DEFERRED_OUT, OdinTokenAttribute},
#line 60 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str40, ODIN_KWAD_DEFERRED_IN, OdinTokenAttribute},
#line 111 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str41, ODIN_KWAD_ATT, OdinTokenDirective},
#line 62 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str42, ODIN_KWAD_DEFERRED_IN_OUT, OdinTokenAttribute},
#line 64 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str43, ODIN_KWAD_DEFERRED_NONE, OdinTokenAttribute},
#line 40 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str44, ODIN_KWAD_FOREIGN, OdinTokenKeyword},
#line 61 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str45, ODIN_KWAD_DEFERRED_IN_BY_PTR, OdinTokenAttribute},
#line 66 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str46, ODIN_KWAD_DEFERRED_OUT_BY_PTR, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 131 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str48, ODIN_KWAD_LOAD, OdinTokenDirective},
#line 63 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str49, ODIN_KWAD_DEFERRED_IN_OUT_BY_PTR, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 159 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str52, ODIN_KWAD_TYPE, OdinTokenDirective},
#line 112 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str53, ODIN_KWAD_ASSERT, OdinTokenDirective},
#line 26 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str54, ODIN_KWAD_TYPEID, OdinTokenKeyword},
#line 71 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str55, ODIN_KWAD_EXPORT, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 109 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str58, ODIN_KWAD_ALL_OR_NONE, OdinTokenDirective},
#line 157 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str59, ODIN_KWAD_SPARSE, OdinTokenDirective},
#line 59 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str60, ODIN_KWAD_DEFAULT_CALLING_CONVENTION, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 120 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str62, ODIN_KWAD_CONST, OdinTokenDirective},
#line 152 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str63, ODIN_KWAD_SHARED_NIL, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 58 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str65, ODIN_KWAD_COLD, OdinTokenAttribute},
#line 43 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str66, ODIN_KWAD_IN, OdinTokenKeyword},
#line 32 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str67, ODIN_KWAD_CAST, OdinTokenKeyword},
#line 82 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str68, ODIN_KWAD_LINK_SUFFIX, OdinTokenAttribute},
#line 69 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str69, ODIN_KWAD_ENABLE_TARGET_FEATURE, OdinTokenAttribute},
#line 31 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str70, ODIN_KWAD_CASE, OdinTokenKeyword},
#line 20 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str71, ODIN_KWAD_CONTINUE, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 129 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str73, ODIN_KWAD_INTEL, OdinTokenDirective},
#line 35 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str74, ODIN_KWAD_DO, OdinTokenKeyword},
#line 118 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str75, ODIN_KWAD_COLUMN_MAJOR, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 117 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str78, ODIN_KWAD_CALLER_LOCATION, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 116 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str80, ODIN_KWAD_CALLER_EXPRESSION, OdinTokenDirective},
#line 102 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str81, ODIN_KWAD_RODATA, OdinTokenAttribute},
#line 119 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str82, ODIN_KWAD_CONFIG, OdinTokenDirective},
#line 55 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str83, ODIN_KWAD_WHEN, OdinTokenKeyword},
#line 156 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str84, ODIN_KWAD_SOA, OdinTokenDirective},
#line 56 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str85, ODIN_KWAD_WHERE, OdinTokenKeyword},
#line 41 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str86, ODIN_KWAD_IF, OdinTokenKeyword},
#line 161 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str87, ODIN_KWAD_UNROLL, OdinTokenDirective},
#line 149 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str88, ODIN_KWAD_RAW_UNION, OdinTokenDirective},
#line 124 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str89, ODIN_KWAD_EXISTS, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 73 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str91, ODIN_KWAD_FINI, OdinTokenAttribute},
#line 160 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str92, ODIN_KWAD_TYPE_ASSERT, OdinTokenDirective},
#line 147 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str93, ODIN_KWAD_PARTIAL, OdinTokenDirective},
#line 74 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str94, ODIN_KWAD_IGNORE_DUPLICATES, OdinTokenAttribute},
#line 144 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str95, ODIN_KWAD_OPTIONAL_OK, OdinTokenDirective},
#line 141 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str96, ODIN_KWAD_NO_NIL, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 143 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str99, ODIN_KWAD_OPTIONAL_ALLOCATOR_ERROR, OdinTokenDirective},
#line 28 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str100, ODIN_KWAD_AUTO_CAST, OdinTokenKeyword},
#line 98 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str101, ODIN_KWAD_RADDBG_TYPE_VIEW, OdinTokenAttribute},
#line 80 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str102, ODIN_KWAD_LINK_PREFIX, OdinTokenAttribute},
#line 19 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str103, ODIN_KWAD_CONTEXT, OdinTokenKeyword},
#line 146 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str104, ODIN_KWAD_PANIC, OdinTokenDirective},
#line 107 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str105, ODIN_KWAD_ALIGN, OdinTokenDirective},
#line 145 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str106, ODIN_KWAD_PACKED, OdinTokenDirective},
#line 72 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str107, ODIN_KWAD_EXTRA_LINKER_FLAGS, OdinTokenAttribute},
#line 83 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str108, ODIN_KWAD_NO_INSTRUMENTATION, OdinTokenAttribute},
#line 84 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str109, ODIN_KWAD_NO_SANITIZE_ADDRESS, OdinTokenAttribute},
#line 67 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str110, ODIN_KWAD_DEPRECATED, OdinTokenAttribute},
#line 94 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str111, ODIN_KWAD_OBJC_TYPE, OdinTokenAttribute},
#line 42 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str112, ODIN_KWAD_IMPORT, OdinTokenKeyword},
#line 91 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str113, ODIN_KWAD_OBJC_NAME, OdinTokenAttribute},
#line 154 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str114, ODIN_KWAD_SIMD, OdinTokenDirective},
#line 126 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str115, ODIN_KWAD_FORCE_INLINE, OdinTokenDirective},
#line 97 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str116, ODIN_KWAD_PRIVATE, OdinTokenAttribute},
#line 48 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str117, ODIN_KWAD_PACKAGE, OdinTokenKeyword},
#line 127 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str118, ODIN_KWAD_FORCE_NO_INLINE, OdinTokenDirective},
#line 151 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str119, ODIN_KWAD_ROW_MAJOR, OdinTokenDirective},
#line 92 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str120, ODIN_KWAD_OBJC_SELECTOR, OdinTokenAttribute},
#line 121 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str121, ODIN_KWAD_C_VARARG, OdinTokenDirective},
#line 155 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str122, ODIN_KWAD_SIMPLE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 137 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str124, ODIN_KWAD_MUST_TAIL, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 36 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str126, ODIN_KWAD_DYNAMIC, OdinTokenKeyword},
#line 75 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str127, ODIN_KWAD_INIT, OdinTokenAttribute},
#line 148 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str128, ODIN_KWAD_PROCEDURE, OdinTokenDirective},
#line 30 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str129, ODIN_KWAD_BIT_SET, OdinTokenKeyword},
#line 93 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str130, ODIN_KWAD_OBJC_SUPERCLASS, OdinTokenAttribute},
#line 134 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str131, ODIN_KWAD_LOCATION, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 18 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str135, ODIN_KWAD_BREAK, OdinTokenKeyword},
#line 142 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str136, ODIN_KWAD_NO_TYPE_ASSERT, OdinTokenDirective},
#line 53 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str137, ODIN_KWAD_UNION, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 128 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str139, ODIN_KWAD_HASH, OdinTokenDirective},
#line 123 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str140, ODIN_KWAD_DIRECTORY, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 54 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str144, ODIN_KWAD_USING, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 52 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str149, ODIN_KWAD_TRANSMUTE, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 95 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str153, ODIN_KWAD_OPTIMIZATION_MODE, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 138 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str156, ODIN_KWAD_NO_ALIAS, OdinTokenDirective},
#line 103 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str157, ODIN_KWAD_STATIC, OdinTokenAttribute},
#line 24 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str158, ODIN_KWAD_OR_RETURN, OdinTokenKeyword},
#line 77 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str159, ODIN_KWAD_INSTRUMENTATION_EXIT, OdinTokenAttribute},
#line 76 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str160, ODIN_KWAD_INSTRUMENTATION_ENTER, OdinTokenAttribute},
#line 140 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str161, ODIN_KWAD_NO_BROADCAST, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 23 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str163, ODIN_KWAD_OR_CONTINUE, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 47 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str165, ODIN_KWAD_OR_ELSE, OdinTokenKeyword},
#line 21 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str166, ODIN_KWAD_FALLTHROUGH, OdinTokenKeyword},
#line 22 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str167, ODIN_KWAD_OR_BREAK, OdinTokenKeyword},
#line 90 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str168, ODIN_KWAD_OBJC_IVAR, OdinTokenAttribute},
#line 86 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str169, ODIN_KWAD_OBJC_CLASS, OdinTokenAttribute},
#line 49 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str170, ODIN_KWAD_PROC, OdinTokenKeyword},
#line 139 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str171, ODIN_KWAD_NO_BOUNDS_CHECK, OdinTokenDirective},
#line 87 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str172, ODIN_KWAD_OBJC_CONTEXT_PROVIDER, OdinTokenAttribute},
#line 88 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str173, ODIN_KWAD_OBJC_IMPLEMENT, OdinTokenAttribute},
#line 110 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str174, ODIN_KWAD_ANY_INT, OdinTokenDirective},
#line 38 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str175, ODIN_KWAD_ENUM, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 133 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str177, ODIN_KWAD_LOAD_HASH, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 158 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str179, ODIN_KWAD_SUBTYPE, OdinTokenDirective},
#line 89 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str180, ODIN_KWAD_OBJC_IS_CLASS_METHOD, OdinTokenAttribute},
#line 136 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str181, ODIN_KWAD_MIN_FIELD_ALIGN, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 45 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str184, ODIN_KWAD_MATRIX, OdinTokenKeyword},
#line 132 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str185, ODIN_KWAD_LOAD_DIRECTORY, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 44 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str188, ODIN_KWAD_MAP, OdinTokenKeyword},
#line 29 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str189, ODIN_KWAD_BIT_FIELD, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 108 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str193, ODIN_KWAD_ALIGN_STACK, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 115 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str199, ODIN_KWAD_BY_PTR, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 51 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str202, ODIN_KWAD_SWITCH, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 113 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str215, ODIN_KWAD_BOUNDS_CHECK, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 135 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str217, ODIN_KWAD_MAX_FIELD_ALIGN, OdinTokenDirective},
#line 96 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str218, ODIN_KWAD_PRIORITY_INDEX, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 70 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str223, ODIN_KWAD_ENTRY_POINT_ONLY, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 85 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str226, ODIN_KWAD_NO_SANITIZE_MEMORY, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 114 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str233, ODIN_KWAD_BRANCH_LOCATION, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 27 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str237, ODIN_KWAD_ASM, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 57 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str248, ODIN_KWAD_BUILTIN, OdinTokenAttribute}
  };

static const struct OdinKwad *
odin_kwad_lookup (register const char *str, register size_t len)
{
  if (len <= ODIN_KWAD_MAX_WORD_LENGTH && len >= ODIN_KWAD_MIN_WORD_LENGTH)
    {
      register unsigned int key = odin_kwad_hash (str, len);

      if (key <= ODIN_KWAD_MAX_HASH_VALUE)
        if (len == odin_kwad_lengths[key])
          {
            register const char *s = odin_kwads[key].kwad_offset + odin_kwad_string_pool;

            if (*str == *s && !memcmp (str + 1, s + 1, len - 1))
              return &odin_kwads[key];
          }
    }
  return (struct OdinKwad *) 0;
}
