/* ANSI-C code produced by gperf version 3.3 */
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
struct OdinKwad { int kwad_offset; uint16_t valid_symbols_idx; uint8_t is_a_keyword; };

#define ODIN_KWAD_TOTAL_KEYWORDS 157
#define ODIN_KWAD_MIN_WORD_LENGTH 2
#define ODIN_KWAD_MAX_WORD_LENGTH 26
#define ODIN_KWAD_MIN_HASH_VALUE 13
#define ODIN_KWAD_MAX_HASH_VALUE 288
/* maximum key range = 276, duplicates = 0 */

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
  static const unsigned short asso_values[] =
    {
      289, 289, 289, 289, 289, 289, 289, 289, 289, 289,
      289, 289, 289, 289, 289, 289, 289, 289, 289, 289,
      289, 289, 289, 289, 289, 289, 289, 289, 289, 289,
      289, 289, 289, 289, 289, 289, 289, 289, 289, 289,
      289, 289, 289, 289, 289, 289, 289, 289, 289, 289,
      289, 289, 289, 289, 289, 289, 289, 289, 289, 289,
      289, 289, 289, 289, 289, 289, 289, 289, 289, 289,
      289, 289, 289, 289, 289, 289, 289, 289, 289, 289,
      289, 289, 289, 289, 289, 289, 289, 289, 289, 289,
      289, 289, 289, 289, 289,  85, 289,  69,  62,  39,
       14,   7,  31, 111,  41,  85,  23,  16,  44,  94,
       10, 108,   8,   9,   4,   3,   3,  87,   3,  22,
       60, 128, 289, 289, 289, 289, 289, 289
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
    char odin_kwad_string_pool_str13[sizeof("test")];
    char odin_kwad_string_pool_str18[sizeof("post")];
    char odin_kwad_string_pool_str19[sizeof("struct")];
    char odin_kwad_string_pool_str21[sizeof("else")];
    char odin_kwad_string_pool_str22[sizeof("type")];
    char odin_kwad_string_pool_str23[sizeof("pure")];
    char odin_kwad_string_pool_str24[sizeof("reverse")];
    char odin_kwad_string_pool_str25[sizeof("pre")];
    char odin_kwad_string_pool_str27[sizeof("export")];
    char odin_kwad_string_pool_str29[sizeof("nop")];
    char odin_kwad_string_pool_str31[sizeof("require")];
    char odin_kwad_string_pool_str32[sizeof("synchronizes")];
    char odin_kwad_string_pool_str33[sizeof("return")];
    char odin_kwad_string_pool_str34[sizeof("preserve")];
    char odin_kwad_string_pool_str35[sizeof("require_results")];
    char odin_kwad_string_pool_str38[sizeof("distinct")];
    char odin_kwad_string_pool_str39[sizeof("not_in")];
    char odin_kwad_string_pool_str41[sizeof("where")];
    char odin_kwad_string_pool_str42[sizeof("for")];
    char odin_kwad_string_pool_str43[sizeof("when")];
    char odin_kwad_string_pool_str45[sizeof("typeid")];
    char odin_kwad_string_pool_str46[sizeof("require_target_feature")];
    char odin_kwad_string_pool_str49[sizeof("cast")];
    char odin_kwad_string_pool_str50[sizeof("synchronizes_shared")];
    char odin_kwad_string_pool_str53[sizeof("case")];
    char odin_kwad_string_pool_str54[sizeof("defer")];
    char odin_kwad_string_pool_str55[sizeof("raw_union")];
    char odin_kwad_string_pool_str57[sizeof("const")];
    char odin_kwad_string_pool_str62[sizeof("panic")];
    char odin_kwad_string_pool_str64[sizeof("deferred_out")];
    char odin_kwad_string_pool_str65[sizeof("line")];
    char odin_kwad_string_pool_str67[sizeof("deferred_in_out")];
    char odin_kwad_string_pool_str69[sizeof("deferred_none")];
    char odin_kwad_string_pool_str70[sizeof("deferred_in")];
    char odin_kwad_string_pool_str71[sizeof("deferred_in_by_ptr")];
    char odin_kwad_string_pool_str72[sizeof("deferred_out_by_ptr")];
    char odin_kwad_string_pool_str73[sizeof("defined")];
    char odin_kwad_string_pool_str74[sizeof("continue")];
    char odin_kwad_string_pool_str75[sizeof("deferred_in_out_by_ptr")];
    char odin_kwad_string_pool_str76[sizeof("byte")];
    char odin_kwad_string_pool_str77[sizeof("thread_local")];
    char odin_kwad_string_pool_str79[sizeof("link_section")];
    char odin_kwad_string_pool_str80[sizeof("link_name")];
    char odin_kwad_string_pool_str81[sizeof("packed")];
    char odin_kwad_string_pool_str82[sizeof("bit_set")];
    char odin_kwad_string_pool_str83[sizeof("disabled")];
    char odin_kwad_string_pool_str84[sizeof("assert")];
    char odin_kwad_string_pool_str85[sizeof("deprecated")];
    char odin_kwad_string_pool_str86[sizeof("file")];
    char odin_kwad_string_pool_str87[sizeof("subtype")];
    char odin_kwad_string_pool_str89[sizeof("hash")];
    char odin_kwad_string_pool_str90[sizeof("break")];
    char odin_kwad_string_pool_str92[sizeof("sparse")];
    char odin_kwad_string_pool_str94[sizeof("type_assert")];
    char odin_kwad_string_pool_str97[sizeof("in")];
    char odin_kwad_string_pool_str99[sizeof("futex")];
    char odin_kwad_string_pool_str100[sizeof("skip")];
    char odin_kwad_string_pool_str101[sizeof("cold")];
    char odin_kwad_string_pool_str104[sizeof("exists")];
    char odin_kwad_string_pool_str105[sizeof("import")];
    char odin_kwad_string_pool_str108[sizeof("row_major")];
    char odin_kwad_string_pool_str109[sizeof("column_major")];
    char odin_kwad_string_pool_str110[sizeof("private")];
    char odin_kwad_string_pool_str111[sizeof("enable_target_feature")];
    char odin_kwad_string_pool_str112[sizeof("caller_location")];
    char odin_kwad_string_pool_str113[sizeof("map")];
    char odin_kwad_string_pool_str114[sizeof("caller_expression")];
    char odin_kwad_string_pool_str115[sizeof("simd")];
    char odin_kwad_string_pool_str116[sizeof("extra_linker_flags")];
    char odin_kwad_string_pool_str117[sizeof("simple")];
    char odin_kwad_string_pool_str118[sizeof("if")];
    char odin_kwad_string_pool_str119[sizeof("context")];
    char odin_kwad_string_pool_str120[sizeof("no_type_assert")];
    char odin_kwad_string_pool_str122[sizeof("ignore_duplicates")];
    char odin_kwad_string_pool_str123[sizeof("auto_cast")];
    char odin_kwad_string_pool_str124[sizeof("do")];
    char odin_kwad_string_pool_str125[sizeof("default_calling_convention")];
    char odin_kwad_string_pool_str126[sizeof("no_instrumentation")];
    char odin_kwad_string_pool_str127[sizeof("no_sanitize_address")];
    char odin_kwad_string_pool_str128[sizeof("link_suffix")];
    char odin_kwad_string_pool_str130[sizeof("fini")];
    char odin_kwad_string_pool_str131[sizeof("load")];
    char odin_kwad_string_pool_str132[sizeof("partial")];
    char odin_kwad_string_pool_str133[sizeof("link_prefix")];
    char odin_kwad_string_pool_str135[sizeof("all_or_none")];
    char odin_kwad_string_pool_str137[sizeof("no_sanitize_thread")];
    char odin_kwad_string_pool_str138[sizeof("futex_parameter")];
    char odin_kwad_string_pool_str139[sizeof("force_inline")];
    char odin_kwad_string_pool_str140[sizeof("shared_nil")];
    char odin_kwad_string_pool_str142[sizeof("force_no_inline")];
    char odin_kwad_string_pool_str144[sizeof("soa")];
    char odin_kwad_string_pool_str146[sizeof("procedure")];
    char odin_kwad_string_pool_str147[sizeof("volatile")];
    char odin_kwad_string_pool_str148[sizeof("optional_ok")];
    char odin_kwad_string_pool_str149[sizeof("optional_allocator_error")];
    char odin_kwad_string_pool_str150[sizeof("objc_type")];
    char odin_kwad_string_pool_str151[sizeof("objc_selector")];
    char odin_kwad_string_pool_str152[sizeof("objc_superclass")];
    char odin_kwad_string_pool_str153[sizeof("must_tail")];
    char odin_kwad_string_pool_str155[sizeof("dynamic")];
    char odin_kwad_string_pool_str156[sizeof("static")];
    char odin_kwad_string_pool_str157[sizeof("objc_name")];
    char odin_kwad_string_pool_str158[sizeof("directory")];
    char odin_kwad_string_pool_str159[sizeof("proc")];
    char odin_kwad_string_pool_str161[sizeof("by_ptr")];
    char odin_kwad_string_pool_str162[sizeof("rodata")];
    char odin_kwad_string_pool_str163[sizeof("foreign")];
    char odin_kwad_string_pool_str165[sizeof("clobber")];
    char odin_kwad_string_pool_str167[sizeof("raddbg_type_view")];
    char odin_kwad_string_pool_str168[sizeof("fallthrough")];
    char odin_kwad_string_pool_str169[sizeof("align")];
    char odin_kwad_string_pool_str172[sizeof("package")];
    char odin_kwad_string_pool_str173[sizeof("bit_field")];
    char odin_kwad_string_pool_str176[sizeof("switch")];
    char odin_kwad_string_pool_str177[sizeof("init")];
    char odin_kwad_string_pool_str178[sizeof("fast_math")];
    char odin_kwad_string_pool_str179[sizeof("linkage")];
    char odin_kwad_string_pool_str180[sizeof("bounds_check")];
    char odin_kwad_string_pool_str182[sizeof("transmute")];
    char odin_kwad_string_pool_str183[sizeof("objc_class")];
    char odin_kwad_string_pool_str185[sizeof("unroll")];
    char odin_kwad_string_pool_str186[sizeof("location")];
    char odin_kwad_string_pool_str187[sizeof("union")];
    char odin_kwad_string_pool_str189[sizeof("no_nil")];
    char odin_kwad_string_pool_str190[sizeof("no_init")];
    char odin_kwad_string_pool_str191[sizeof("no_alias")];
    char odin_kwad_string_pool_str192[sizeof("enum")];
    char odin_kwad_string_pool_str195[sizeof("objc_context_provider")];
    char odin_kwad_string_pool_str197[sizeof("branch_location")];
    char odin_kwad_string_pool_str198[sizeof("instrumentation_exit")];
    char odin_kwad_string_pool_str200[sizeof("instrumentation_enter")];
    char odin_kwad_string_pool_str204[sizeof("load_hash")];
    char odin_kwad_string_pool_str210[sizeof("or_else")];
    char odin_kwad_string_pool_str213[sizeof("no_bounds_check")];
    char odin_kwad_string_pool_str214[sizeof("min_field_align")];
    char odin_kwad_string_pool_str215[sizeof("or_return")];
    char odin_kwad_string_pool_str217[sizeof("any_int")];
    char odin_kwad_string_pool_str218[sizeof("no_broadcast")];
    char odin_kwad_string_pool_str220[sizeof("optimization_mode")];
    char odin_kwad_string_pool_str221[sizeof("or_continue")];
    char odin_kwad_string_pool_str223[sizeof("matrix")];
    char odin_kwad_string_pool_str224[sizeof("or_break")];
    char odin_kwad_string_pool_str228[sizeof("tag")];
    char odin_kwad_string_pool_str229[sizeof("objc_ivar")];
    char odin_kwad_string_pool_str230[sizeof("c_vararg")];
    char odin_kwad_string_pool_str233[sizeof("objc_implement")];
    char odin_kwad_string_pool_str239[sizeof("entry_point_only")];
    char odin_kwad_string_pool_str249[sizeof("builtin")];
    char odin_kwad_string_pool_str250[sizeof("objc_is_class_method")];
    char odin_kwad_string_pool_str251[sizeof("no_sanitize_memory")];
    char odin_kwad_string_pool_str252[sizeof("priority_index")];
    char odin_kwad_string_pool_str260[sizeof("asm")];
    char odin_kwad_string_pool_str264[sizeof("max_field_align")];
    char odin_kwad_string_pool_str266[sizeof("align_stack")];
    char odin_kwad_string_pool_str269[sizeof("load_directory")];
    char odin_kwad_string_pool_str277[sizeof("config")];
    char odin_kwad_string_pool_str288[sizeof("using")];
  };
static const struct odin_kwad_string_pool_t odin_kwad_string_pool_contents =
  {
    "test",
    "post",
    "struct",
    "else",
    "type",
    "pure",
    "reverse",
    "pre",
    "export",
    "nop",
    "require",
    "synchronizes",
    "return",
    "preserve",
    "require_results",
    "distinct",
    "not_in",
    "where",
    "for",
    "when",
    "typeid",
    "require_target_feature",
    "cast",
    "synchronizes_shared",
    "case",
    "defer",
    "raw_union",
    "const",
    "panic",
    "deferred_out",
    "line",
    "deferred_in_out",
    "deferred_none",
    "deferred_in",
    "deferred_in_by_ptr",
    "deferred_out_by_ptr",
    "defined",
    "continue",
    "deferred_in_out_by_ptr",
    "byte",
    "thread_local",
    "link_section",
    "link_name",
    "packed",
    "bit_set",
    "disabled",
    "assert",
    "deprecated",
    "file",
    "subtype",
    "hash",
    "break",
    "sparse",
    "type_assert",
    "in",
    "futex",
    "skip",
    "cold",
    "exists",
    "import",
    "row_major",
    "column_major",
    "private",
    "enable_target_feature",
    "caller_location",
    "map",
    "caller_expression",
    "simd",
    "extra_linker_flags",
    "simple",
    "if",
    "context",
    "no_type_assert",
    "ignore_duplicates",
    "auto_cast",
    "do",
    "default_calling_convention",
    "no_instrumentation",
    "no_sanitize_address",
    "link_suffix",
    "fini",
    "load",
    "partial",
    "link_prefix",
    "all_or_none",
    "no_sanitize_thread",
    "futex_parameter",
    "force_inline",
    "shared_nil",
    "force_no_inline",
    "soa",
    "procedure",
    "volatile",
    "optional_ok",
    "optional_allocator_error",
    "objc_type",
    "objc_selector",
    "objc_superclass",
    "must_tail",
    "dynamic",
    "static",
    "objc_name",
    "directory",
    "proc",
    "by_ptr",
    "rodata",
    "foreign",
    "clobber",
    "raddbg_type_view",
    "fallthrough",
    "align",
    "package",
    "bit_field",
    "switch",
    "init",
    "fast_math",
    "linkage",
    "bounds_check",
    "transmute",
    "objc_class",
    "unroll",
    "location",
    "union",
    "no_nil",
    "no_init",
    "no_alias",
    "enum",
    "objc_context_provider",
    "branch_location",
    "instrumentation_exit",
    "instrumentation_enter",
    "load_hash",
    "or_else",
    "no_bounds_check",
    "min_field_align",
    "or_return",
    "any_int",
    "no_broadcast",
    "optimization_mode",
    "or_continue",
    "matrix",
    "or_break",
    "tag",
    "objc_ivar",
    "c_vararg",
    "objc_implement",
    "entry_point_only",
    "builtin",
    "objc_is_class_method",
    "no_sanitize_memory",
    "priority_index",
    "asm",
    "max_field_align",
    "align_stack",
    "load_directory",
    "config",
    "using"
  };
#define odin_kwad_string_pool ((const char *) &odin_kwad_string_pool_contents)

static const unsigned char odin_kwad_lengths[] =
  {
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,
     0,  0,  0,  0,  4,  6,  0,  4,  4,  4,  7,  3,  0,  6,
     0,  3,  0,  7, 12,  6,  8, 15,  0,  0,  8,  6,  0,  5,
     3,  4,  0,  6, 22,  0,  0,  4, 19,  0,  0,  4,  5,  9,
     0,  5,  0,  0,  0,  0,  5,  0, 12,  4,  0, 15,  0, 13,
    11, 18, 19,  7,  8, 22,  4, 12,  0, 12,  9,  6,  7,  8,
     6, 10,  4,  7,  0,  4,  5,  0,  6,  0, 11,  0,  0,  2,
     0,  5,  4,  4,  0,  0,  6,  6,  0,  0,  9, 12,  7, 21,
    15,  3, 17,  4, 18,  6,  2,  7, 14,  0, 17,  9,  2, 26,
    18, 19, 11,  0,  4,  4,  7, 11,  0, 11,  0, 18, 15, 12,
    10,  0, 15,  0,  3,  0,  9,  8, 11, 24,  9, 13, 15,  9,
     0,  7,  6,  9,  9,  4,  0,  6,  6,  7,  0,  7,  0, 16,
    11,  5,  0,  0,  7,  9,  0,  0,  6,  4,  9,  7, 12,  0,
     9, 10,  0,  6,  8,  5,  0,  6,  7,  8,  4,  0,  0, 21,
     0, 15, 20,  0, 21,  0,  0,  0,  9,  0,  0,  0,  0,  0,
     7,  0,  0, 15, 15,  9,  0,  7, 12,  0, 17, 11,  0,  6,
     8,  0,  0,  0,  3,  9,  8,  0,  0, 14,  0,  0,  0,  0,
     0, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7, 20, 18,
    14,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0, 15,  0,
    11,  0,  0, 14,  0,  0,  0,  0,  0,  0,  0,  6,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  5
  };

static const struct OdinKwad odin_kwads[] =
  {
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0},
#line 117 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str13, ODIN_KWAD_TEST, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 164 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str18, ODIN_KWAD_POST, 0},
#line 53 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str19, ODIN_KWAD_STRUCT, 1},
    {-1,ODIN_INVALID,0},
#line 40 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str21, ODIN_KWAD_ELSE, 1},
#line 179 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str22, ODIN_KWAD_TYPE, 0},
#line 168 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str23, ODIN_KWAD_PURE, 0},
#line 170 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str24, ODIN_KWAD_REVERSE, 0},
#line 165 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str25, ODIN_KWAD_PRE, 0},
    {-1,ODIN_INVALID,0},
#line 77 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str27, ODIN_KWAD_EXPORT, 0},
    {-1,ODIN_INVALID,0},
#line 158 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str29, ODIN_KWAD_NOP, 0,},
    {-1,ODIN_INVALID,0},
#line 109 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str31, ODIN_KWAD_REQUIRE, 0},
#line 114 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str32, ODIN_KWAD_SYNCHRONIZES, 0},
#line 28 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str33, ODIN_KWAD_RETURN, 1},
#line 166 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str34, ODIN_KWAD_PRESERVE, 0},
#line 110 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str35, ODIN_KWAD_REQUIRE_RESULTS, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 37 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str38, ODIN_KWAD_DISTINCT, 1},
#line 49 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str39, ODIN_KWAD_NOT_IN, 1},
    {-1,ODIN_INVALID,0},
#line 59 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str41, ODIN_KWAD_WHERE, 1},
#line 42 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str42, ODIN_KWAD_FOR, 1},
#line 58 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str43, ODIN_KWAD_WHEN, 1},
    {-1,ODIN_INVALID,0},
#line 29 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str45, ODIN_KWAD_TYPEID, 1},
#line 111 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str46, ODIN_KWAD_REQUIRE_TARGET_FEATURE, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 35 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str49, ODIN_KWAD_CAST, 1},
#line 115 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str50, ODIN_KWAD_SYNCHRONIZES_SHARED, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 34 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str53, ODIN_KWAD_CASE, 1},
#line 36 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str54, ODIN_KWAD_DEFER, 1},
#line 169 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str55, ODIN_KWAD_RAW_UNION, 0},
    {-1,ODIN_INVALID,0},
#line 135 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str57, ODIN_KWAD_CONST, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 162 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str62, ODIN_KWAD_PANIC, 0},
    {-1,ODIN_INVALID,0},
#line 71 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str64, ODIN_KWAD_DEFERRED_OUT, 0},
#line 144 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str65, ODIN_KWAD_LINE, 0},
    {-1,ODIN_INVALID,0},
#line 68 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str67, ODIN_KWAD_DEFERRED_IN_OUT, 0},
    {-1,ODIN_INVALID,0},
#line 70 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str69, ODIN_KWAD_DEFERRED_NONE, 0},
#line 66 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str70, ODIN_KWAD_DEFERRED_IN, 0},
#line 67 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str71, ODIN_KWAD_DEFERRED_IN_BY_PTR, 0},
#line 72 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str72, ODIN_KWAD_DEFERRED_OUT_BY_PTR, 0},
#line 137 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str73, ODIN_KWAD_DEFINED, 0},
#line 23 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str74, ODIN_KWAD_CONTINUE, 1},
#line 69 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str75, ODIN_KWAD_DEFERRED_IN_OUT_BY_PTR, 0},
#line 129 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str76, ODIN_KWAD_BYTE, 0,},
#line 118 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str77, ODIN_KWAD_THREAD_LOCAL, 0},
    {-1,ODIN_INVALID,0},
#line 90 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str79, ODIN_KWAD_LINK_SECTION, 0},
#line 88 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str80, ODIN_KWAD_LINK_NAME, 0},
#line 161 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str81, ODIN_KWAD_PACKED, 0},
#line 33 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str82, ODIN_KWAD_BIT_SET, 1},
#line 74 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str83, ODIN_KWAD_DISABLED, 0},
#line 125 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str84, ODIN_KWAD_ASSERT, 0},
#line 73 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str85, ODIN_KWAD_DEPRECATED, 0},
#line 140 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str86, ODIN_KWAD_FILE, 0},
#line 178 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str87, ODIN_KWAD_SUBTYPE, 0},
    {-1,ODIN_INVALID,0},
#line 143 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str89, ODIN_KWAD_HASH, 0},
#line 21 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str90, ODIN_KWAD_BREAK, 1},
    {-1,ODIN_INVALID,0},
#line 177 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str92, ODIN_KWAD_SPARSE, 0},
    {-1,ODIN_INVALID,0},
#line 180 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str94, ODIN_KWAD_TYPE_ASSERT, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 46 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str97, ODIN_KWAD_IN, 1},
    {-1,ODIN_INVALID,0},
#line 81 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str99, ODIN_KWAD_FUTEX, 0},
#line 175 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str100, ODIN_KWAD_SKIP, 0,},
#line 64 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str101, ODIN_KWAD_COLD, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 139 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str104, ODIN_KWAD_EXISTS, 0},
#line 45 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str105, ODIN_KWAD_IMPORT, 1},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 171 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str108, ODIN_KWAD_ROW_MAJOR, 0},
#line 133 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str109, ODIN_KWAD_COLUMN_MAJOR, 0},
#line 107 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str110, ODIN_KWAD_PRIVATE, 0},
#line 75 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str111, ODIN_KWAD_ENABLE_TARGET_FEATURE, 0},
#line 131 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str112, ODIN_KWAD_CALLER_LOCATION, 0},
#line 47 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str113, ODIN_KWAD_MAP, 1},
#line 130 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str114, ODIN_KWAD_CALLER_EXPRESSION, 0},
#line 173 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str115, ODIN_KWAD_SIMD, 0},
#line 78 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str116, ODIN_KWAD_EXTRA_LINKER_FLAGS, 0},
#line 174 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str117, ODIN_KWAD_SIMPLE, 0},
#line 44 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str118, ODIN_KWAD_IF, 1},
#line 22 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str119, ODIN_KWAD_CONTEXT, 1},
#line 157 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str120, ODIN_KWAD_NO_TYPE_ASSERT, 0},
    {-1,ODIN_INVALID,0},
#line 83 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str122, ODIN_KWAD_IGNORE_DUPLICATES, 0},
#line 31 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str123, ODIN_KWAD_AUTO_CAST, 1},
#line 38 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str124, ODIN_KWAD_DO, 1},
#line 65 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str125, ODIN_KWAD_DEFAULT_CALLING_CONVENTION, 0},
#line 92 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str126, ODIN_KWAD_NO_INSTRUMENTATION, 0},
#line 93 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str127, ODIN_KWAD_NO_SANITIZE_ADDRESS, 0},
#line 91 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str128, ODIN_KWAD_LINK_SUFFIX, 0},
    {-1,ODIN_INVALID,0},
#line 80 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str130, ODIN_KWAD_FINI, 0},
#line 145 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str131, ODIN_KWAD_LOAD, 0},
#line 163 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str132, ODIN_KWAD_PARTIAL, 0},
#line 89 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str133, ODIN_KWAD_LINK_PREFIX, 0},
    {-1,ODIN_INVALID,0},
#line 123 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str135, ODIN_KWAD_ALL_OR_NONE, 0},
    {-1,ODIN_INVALID,0},
#line 95 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str137, ODIN_KWAD_NO_SANITIZE_THREAD, 0},
#line 82 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str138, ODIN_KWAD_FUTEX_PARAMETER, 0},
#line 141 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str139, ODIN_KWAD_FORCE_INLINE, 0},
#line 172 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str140, ODIN_KWAD_SHARED_NIL, 0},
    {-1,ODIN_INVALID,0},
#line 142 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str142, ODIN_KWAD_FORCE_NO_INLINE, 0},
    {-1,ODIN_INVALID,0},
#line 176 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str144, ODIN_KWAD_SOA, 0},
    {-1,ODIN_INVALID,0},
#line 167 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str146, ODIN_KWAD_PROCEDURE, 0},
#line 182 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str147, ODIN_KWAD_VOLATILE, 0},
#line 160 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str148, ODIN_KWAD_OPTIONAL_OK, 0},
#line 159 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str149, ODIN_KWAD_OPTIONAL_ALLOCATOR_ERROR, 0},
#line 104 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str150, ODIN_KWAD_OBJC_TYPE, 0},
#line 102 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str151, ODIN_KWAD_OBJC_SELECTOR, 0},
#line 103 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str152, ODIN_KWAD_OBJC_SUPERCLASS, 0},
#line 151 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str153, ODIN_KWAD_MUST_TAIL, 0},
    {-1,ODIN_INVALID,0},
#line 39 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str155, ODIN_KWAD_DYNAMIC, 1},
#line 113 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str156, ODIN_KWAD_STATIC, 0},
#line 101 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str157, ODIN_KWAD_OBJC_NAME, 0},
#line 138 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str158, ODIN_KWAD_DIRECTORY, 0},
#line 52 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str159, ODIN_KWAD_PROC, 1},
    {-1,ODIN_INVALID,0},
#line 128 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str161, ODIN_KWAD_BY_PTR, 0},
#line 112 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str162, ODIN_KWAD_RODATA, 0},
#line 43 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str163, ODIN_KWAD_FOREIGN, 1},
    {-1,ODIN_INVALID,0},
#line 132 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str165, ODIN_KWAD_CLOBBER, 0},
    {-1,ODIN_INVALID,0},
#line 108 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str167, ODIN_KWAD_RADDBG_TYPE_VIEW, 0},
#line 24 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str168, ODIN_KWAD_FALLTHROUGH, 1},
#line 186 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str169, ODIN_KWAD_ALIGN, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 51 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str172, ODIN_KWAD_PACKAGE, 1},
#line 32 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str173, ODIN_KWAD_BIT_FIELD, 1},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 54 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str176, ODIN_KWAD_SWITCH, 1},
#line 84 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str177, ODIN_KWAD_INIT, 0},
#line 79 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str178, ODIN_KWAD_FAST_MATH, 0},
#line 87 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str179, ODIN_KWAD_LINKAGE, 0},
#line 126 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str180, ODIN_KWAD_BOUNDS_CHECK, 0},
    {-1,ODIN_INVALID,0},
#line 55 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str182, ODIN_KWAD_TRANSMUTE, 1},
#line 96 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str183, ODIN_KWAD_OBJC_CLASS, 0},
    {-1,ODIN_INVALID,0},
#line 181 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str185, ODIN_KWAD_UNROLL, 0},
#line 148 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str186, ODIN_KWAD_LOCATION, 0},
#line 56 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str187, ODIN_KWAD_UNION, 1},
    {-1,ODIN_INVALID,0},
#line 156 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str189, ODIN_KWAD_NO_NIL, 0},
#line 155 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str190, ODIN_KWAD_NO_INIT, 0},
#line 152 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str191, ODIN_KWAD_NO_ALIAS, 0},
#line 41 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str192, ODIN_KWAD_ENUM, 1},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 97 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str195, ODIN_KWAD_OBJC_CONTEXT_PROVIDER, 0},
    {-1,ODIN_INVALID,0},
#line 127 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str197, ODIN_KWAD_BRANCH_LOCATION, 0},
#line 86 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str198, ODIN_KWAD_INSTRUMENTATION_EXIT, 0},
    {-1,ODIN_INVALID,0},
#line 85 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str200, ODIN_KWAD_INSTRUMENTATION_ENTER, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0},
#line 147 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str204, ODIN_KWAD_LOAD_HASH, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0},
#line 50 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str210, ODIN_KWAD_OR_ELSE, 1},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 153 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str213, ODIN_KWAD_NO_BOUNDS_CHECK, 0},
#line 150 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str214, ODIN_KWAD_MIN_FIELD_ALIGN, 0},
#line 27 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str215, ODIN_KWAD_OR_RETURN, 1},
    {-1,ODIN_INVALID,0},
#line 124 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str217, ODIN_KWAD_ANY_INT, 0},
#line 154 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str218, ODIN_KWAD_NO_BROADCAST, 0},
    {-1,ODIN_INVALID,0},
#line 105 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str220, ODIN_KWAD_OPTIMIZATION_MODE, 0},
#line 26 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str221, ODIN_KWAD_OR_CONTINUE, 1},
    {-1,ODIN_INVALID,0},
#line 48 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str223, ODIN_KWAD_MATRIX, 1},
#line 25 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str224, ODIN_KWAD_OR_BREAK, 1},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0},
#line 116 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str228, ODIN_KWAD_TAG, 0},
#line 100 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str229, ODIN_KWAD_OBJC_IVAR, 0},
#line 136 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str230, ODIN_KWAD_C_VARARG, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 98 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str233, ODIN_KWAD_OBJC_IMPLEMENT, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0},
#line 76 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str239, ODIN_KWAD_ENTRY_POINT_ONLY, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0},
#line 63 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str249, ODIN_KWAD_BUILTIN, 0},
#line 99 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str250, ODIN_KWAD_OBJC_IS_CLASS_METHOD, 0},
#line 94 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str251, ODIN_KWAD_NO_SANITIZE_MEMORY, 0},
#line 106 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str252, ODIN_KWAD_PRIORITY_INDEX, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0},
#line 30 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str260, ODIN_KWAD_ASM, 1},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0},
#line 149 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str264, ODIN_KWAD_MAX_FIELD_ALIGN, 0},
    {-1,ODIN_INVALID,0},
#line 122 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str266, ODIN_KWAD_ALIGN_STACK, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 146 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str269, ODIN_KWAD_LOAD_DIRECTORY, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0},
#line 134 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str277, ODIN_KWAD_CONFIG, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 57 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str288, ODIN_KWAD_USING, 1}
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
