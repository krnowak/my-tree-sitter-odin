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

#define ODIN_KWAD_TOTAL_KEYWORDS 161
#define ODIN_KWAD_MIN_WORD_LENGTH 2
#define ODIN_KWAD_MAX_WORD_LENGTH 26
#define ODIN_KWAD_MIN_HASH_VALUE 44
#define ODIN_KWAD_MAX_HASH_VALUE 311
/* maximum key range = 268, duplicates = 0 */

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
      312, 312, 312, 312, 312, 312, 312, 312, 312, 312,
      312, 312, 312, 312, 312, 312, 312, 312, 312, 312,
      312, 312, 312, 312, 312, 312, 312, 312, 312, 312,
      312, 312, 312, 312, 312, 312, 312, 312, 312, 312,
      312, 312, 312, 312, 312, 312, 312, 312, 312, 312,
      312, 312,  13, 312, 312, 312, 312, 312, 312, 312,
      312, 312, 312, 312, 312, 312, 312, 312, 312, 312,
      312, 312, 312, 312, 312, 312, 312, 312, 312, 312,
      312, 312, 312, 312, 312, 312, 312, 312, 312, 312,
      312, 312, 312, 312, 312,  99, 312,  40,  59,  21,
       38,  19,  65, 104,  78,  95,  31,  39,  18, 129,
       12, 121,  31,  13,  11,  14,  13,  60, 138,  80,
       59, 149, 312, 312, 312, 312, 312, 312
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
    char odin_kwad_string_pool_str44[sizeof("test")];
    char odin_kwad_string_pool_str47[sizeof("none")];
    char odin_kwad_string_pool_str51[sizeof("const")];
    char odin_kwad_string_pool_str52[sizeof("cast")];
    char odin_kwad_string_pool_str53[sizeof("line")];
    char odin_kwad_string_pool_str54[sizeof("return")];
    char odin_kwad_string_pool_str55[sizeof("not_in")];
    char odin_kwad_string_pool_str56[sizeof("else")];
    char odin_kwad_string_pool_str57[sizeof("struct")];
    char odin_kwad_string_pool_str58[sizeof("case")];
    char odin_kwad_string_pool_str61[sizeof("require")];
    char odin_kwad_string_pool_str63[sizeof("cdecl")];
    char odin_kwad_string_pool_str64[sizeof("require_results")];
    char odin_kwad_string_pool_str65[sizeof("pure")];
    char odin_kwad_string_pool_str67[sizeof("type")];
    char odin_kwad_string_pool_str68[sizeof("link_section")];
    char odin_kwad_string_pool_str69[sizeof("panic")];
    char odin_kwad_string_pool_str70[sizeof("link_name")];
    char odin_kwad_string_pool_str72[sizeof("continue")];
    char odin_kwad_string_pool_str74[sizeof("column_major")];
    char odin_kwad_string_pool_str76[sizeof("require_target_feature")];
    char odin_kwad_string_pool_str77[sizeof("caller_location")];
    char odin_kwad_string_pool_str79[sizeof("caller_expression")];
    char odin_kwad_string_pool_str81[sizeof("cold")];
    char odin_kwad_string_pool_str82[sizeof("export")];
    char odin_kwad_string_pool_str85[sizeof("distinct")];
    char odin_kwad_string_pool_str86[sizeof("assert")];
    char odin_kwad_string_pool_str87[sizeof("preserve/most")];
    char odin_kwad_string_pool_str88[sizeof("preserve")];
    char odin_kwad_string_pool_str90[sizeof("for")];
    char odin_kwad_string_pool_str91[sizeof("preserve/all")];
    char odin_kwad_string_pool_str92[sizeof("thread_local")];
    char odin_kwad_string_pool_str93[sizeof("preserve/none")];
    char odin_kwad_string_pool_str94[sizeof("naked")];
    char odin_kwad_string_pool_str95[sizeof("stdcall")];
    char odin_kwad_string_pool_str96[sizeof("auto_cast")];
    char odin_kwad_string_pool_str97[sizeof("soa")];
    char odin_kwad_string_pool_str98[sizeof("sparse")];
    char odin_kwad_string_pool_str99[sizeof("all_or_none")];
    char odin_kwad_string_pool_str100[sizeof("load")];
    char odin_kwad_string_pool_str102[sizeof("static")];
    char odin_kwad_string_pool_str106[sizeof("file")];
    char odin_kwad_string_pool_str107[sizeof("partial")];
    char odin_kwad_string_pool_str108[sizeof("type_assert")];
    char odin_kwad_string_pool_str109[sizeof("in")];
    char odin_kwad_string_pool_str110[sizeof("win64")];
    char odin_kwad_string_pool_str111[sizeof("bit_set")];
    char odin_kwad_string_pool_str112[sizeof("context")];
    char odin_kwad_string_pool_str113[sizeof("unroll")];
    char odin_kwad_string_pool_str114[sizeof("link_suffix")];
    char odin_kwad_string_pool_str115[sizeof("when")];
    char odin_kwad_string_pool_str116[sizeof("disabled")];
    char odin_kwad_string_pool_str117[sizeof("contextless")];
    char odin_kwad_string_pool_str118[sizeof("enable_target_feature")];
    char odin_kwad_string_pool_str119[sizeof("defer")];
    char odin_kwad_string_pool_str120[sizeof("shared_nil")];
    char odin_kwad_string_pool_str122[sizeof("break")];
    char odin_kwad_string_pool_str123[sizeof("where")];
    char odin_kwad_string_pool_str124[sizeof("raw_union")];
    char odin_kwad_string_pool_str126[sizeof("typeid")];
    char odin_kwad_string_pool_str130[sizeof("subtype")];
    char odin_kwad_string_pool_str131[sizeof("link_prefix")];
    char odin_kwad_string_pool_str134[sizeof("packed")];
    char odin_kwad_string_pool_str135[sizeof("rodata")];
    char odin_kwad_string_pool_str137[sizeof("deferred_in")];
    char odin_kwad_string_pool_str138[sizeof("deprecated")];
    char odin_kwad_string_pool_str139[sizeof("deferred_out")];
    char odin_kwad_string_pool_str142[sizeof("deferred_in_out")];
    char odin_kwad_string_pool_str143[sizeof("deferred_in_by_ptr")];
    char odin_kwad_string_pool_str144[sizeof("deferred_out_by_ptr")];
    char odin_kwad_string_pool_str145[sizeof("fastcall")];
    char odin_kwad_string_pool_str146[sizeof("deferred_none")];
    char odin_kwad_string_pool_str147[sizeof("deferred_in_out_by_ptr")];
    char odin_kwad_string_pool_str148[sizeof("exists")];
    char odin_kwad_string_pool_str151[sizeof("row_major")];
    char odin_kwad_string_pool_str152[sizeof("align")];
    char odin_kwad_string_pool_str153[sizeof("no_nil")];
    char odin_kwad_string_pool_str154[sizeof("location")];
    char odin_kwad_string_pool_str155[sizeof("no_instrumentation")];
    char odin_kwad_string_pool_str156[sizeof("no_sanitize_address")];
    char odin_kwad_string_pool_str157[sizeof("ignore_duplicates")];
    char odin_kwad_string_pool_str158[sizeof("import")];
    char odin_kwad_string_pool_str159[sizeof("default_calling_convention")];
    char odin_kwad_string_pool_str160[sizeof("linkage")];
    char odin_kwad_string_pool_str161[sizeof("do")];
    char odin_kwad_string_pool_str162[sizeof("if")];
    char odin_kwad_string_pool_str163[sizeof("extra_linker_flags")];
    char odin_kwad_string_pool_str165[sizeof("private")];
    char odin_kwad_string_pool_str167[sizeof("defined")];
    char odin_kwad_string_pool_str169[sizeof("no_type_assert")];
    char odin_kwad_string_pool_str170[sizeof("sysv")];
    char odin_kwad_string_pool_str172[sizeof("union")];
    char odin_kwad_string_pool_str173[sizeof("dynamic")];
    char odin_kwad_string_pool_str174[sizeof("hash")];
    char odin_kwad_string_pool_str176[sizeof("fini")];
    char odin_kwad_string_pool_str177[sizeof("proc")];
    char odin_kwad_string_pool_str179[sizeof("clobber")];
    char odin_kwad_string_pool_str181[sizeof("optional_allocator_error")];
    char odin_kwad_string_pool_str182[sizeof("package")];
    char odin_kwad_string_pool_str183[sizeof("must_tail")];
    char odin_kwad_string_pool_str184[sizeof("bounds_check")];
    char odin_kwad_string_pool_str185[sizeof("simd")];
    char odin_kwad_string_pool_str186[sizeof("by_ptr")];
    char odin_kwad_string_pool_str187[sizeof("simple")];
    char odin_kwad_string_pool_str189[sizeof("reverse")];
    char odin_kwad_string_pool_str190[sizeof("objc_selector")];
    char odin_kwad_string_pool_str192[sizeof("objc_name")];
    char odin_kwad_string_pool_str193[sizeof("objc_type")];
    char odin_kwad_string_pool_str194[sizeof("map")];
    char odin_kwad_string_pool_str195[sizeof("objc_superclass")];
    char odin_kwad_string_pool_str196[sizeof("optional_ok")];
    char odin_kwad_string_pool_str197[sizeof("objc_class")];
    char odin_kwad_string_pool_str199[sizeof("foreign")];
    char odin_kwad_string_pool_str201[sizeof("instrumentation_enter")];
    char odin_kwad_string_pool_str202[sizeof("instrumentation_exit")];
    char odin_kwad_string_pool_str204[sizeof("branch_location")];
    char odin_kwad_string_pool_str205[sizeof("objc_context_provider")];
    char odin_kwad_string_pool_str206[sizeof("force_inline")];
    char odin_kwad_string_pool_str207[sizeof("init")];
    char odin_kwad_string_pool_str209[sizeof("force_no_inline")];
    char odin_kwad_string_pool_str210[sizeof("transmute")];
    char odin_kwad_string_pool_str212[sizeof("enum")];
    char odin_kwad_string_pool_str214[sizeof("bit_field")];
    char odin_kwad_string_pool_str218[sizeof("procedure")];
    char odin_kwad_string_pool_str220[sizeof("directory")];
    char odin_kwad_string_pool_str221[sizeof("any_int")];
    char odin_kwad_string_pool_str223[sizeof("load_hash")];
    char odin_kwad_string_pool_str224[sizeof("tag")];
    char odin_kwad_string_pool_str225[sizeof("no_bounds_check")];
    char odin_kwad_string_pool_str226[sizeof("no_init")];
    char odin_kwad_string_pool_str228[sizeof("no_alias")];
    char odin_kwad_string_pool_str232[sizeof("odin")];
    char odin_kwad_string_pool_str247[sizeof("config")];
    char odin_kwad_string_pool_str249[sizeof("raddbg_type_view")];
    char odin_kwad_string_pool_str250[sizeof("fallthrough")];
    char odin_kwad_string_pool_str254[sizeof("or_return")];
    char odin_kwad_string_pool_str257[sizeof("no_broadcast")];
    char odin_kwad_string_pool_str259[sizeof("load_directory")];
    char odin_kwad_string_pool_str260[sizeof("or_else")];
    char odin_kwad_string_pool_str262[sizeof("or_continue")];
    char odin_kwad_string_pool_str263[sizeof("min_field_align")];
    char odin_kwad_string_pool_str264[sizeof("using")];
    char odin_kwad_string_pool_str265[sizeof("optimization_mode")];
    char odin_kwad_string_pool_str266[sizeof("matrix")];
    char odin_kwad_string_pool_str267[sizeof("objc_ivar")];
    char odin_kwad_string_pool_str268[sizeof("builtin")];
    char odin_kwad_string_pool_str270[sizeof("inlineasm")];
    char odin_kwad_string_pool_str271[sizeof("switch")];
    char odin_kwad_string_pool_str274[sizeof("objc_implement")];
    char odin_kwad_string_pool_str278[sizeof("volatile")];
    char odin_kwad_string_pool_str284[sizeof("align_stack")];
    char odin_kwad_string_pool_str286[sizeof("or_break")];
    char odin_kwad_string_pool_str290[sizeof("no_sanitize_memory")];
    char odin_kwad_string_pool_str292[sizeof("system")];
    char odin_kwad_string_pool_str294[sizeof("priority_index")];
    char odin_kwad_string_pool_str295[sizeof("fast_math")];
    char odin_kwad_string_pool_str296[sizeof("entry_point_only")];
    char odin_kwad_string_pool_str301[sizeof("asm")];
    char odin_kwad_string_pool_str305[sizeof("objc_is_class_method")];
    char odin_kwad_string_pool_str310[sizeof("max_field_align")];
    char odin_kwad_string_pool_str311[sizeof("c_vararg")];
  };
static const struct odin_kwad_string_pool_t odin_kwad_string_pool_contents =
  {
    "test",
    "none",
    "const",
    "cast",
    "line",
    "return",
    "not_in",
    "else",
    "struct",
    "case",
    "require",
    "cdecl",
    "require_results",
    "pure",
    "type",
    "link_section",
    "panic",
    "link_name",
    "continue",
    "column_major",
    "require_target_feature",
    "caller_location",
    "caller_expression",
    "cold",
    "export",
    "distinct",
    "assert",
    "preserve/most",
    "preserve",
    "for",
    "preserve/all",
    "thread_local",
    "preserve/none",
    "naked",
    "stdcall",
    "auto_cast",
    "soa",
    "sparse",
    "all_or_none",
    "load",
    "static",
    "file",
    "partial",
    "type_assert",
    "in",
    "win64",
    "bit_set",
    "context",
    "unroll",
    "link_suffix",
    "when",
    "disabled",
    "contextless",
    "enable_target_feature",
    "defer",
    "shared_nil",
    "break",
    "where",
    "raw_union",
    "typeid",
    "subtype",
    "link_prefix",
    "packed",
    "rodata",
    "deferred_in",
    "deprecated",
    "deferred_out",
    "deferred_in_out",
    "deferred_in_by_ptr",
    "deferred_out_by_ptr",
    "fastcall",
    "deferred_none",
    "deferred_in_out_by_ptr",
    "exists",
    "row_major",
    "align",
    "no_nil",
    "location",
    "no_instrumentation",
    "no_sanitize_address",
    "ignore_duplicates",
    "import",
    "default_calling_convention",
    "linkage",
    "do",
    "if",
    "extra_linker_flags",
    "private",
    "defined",
    "no_type_assert",
    "sysv",
    "union",
    "dynamic",
    "hash",
    "fini",
    "proc",
    "clobber",
    "optional_allocator_error",
    "package",
    "must_tail",
    "bounds_check",
    "simd",
    "by_ptr",
    "simple",
    "reverse",
    "objc_selector",
    "objc_name",
    "objc_type",
    "map",
    "objc_superclass",
    "optional_ok",
    "objc_class",
    "foreign",
    "instrumentation_enter",
    "instrumentation_exit",
    "branch_location",
    "objc_context_provider",
    "force_inline",
    "init",
    "force_no_inline",
    "transmute",
    "enum",
    "bit_field",
    "procedure",
    "directory",
    "any_int",
    "load_hash",
    "tag",
    "no_bounds_check",
    "no_init",
    "no_alias",
    "odin",
    "config",
    "raddbg_type_view",
    "fallthrough",
    "or_return",
    "no_broadcast",
    "load_directory",
    "or_else",
    "or_continue",
    "min_field_align",
    "using",
    "optimization_mode",
    "matrix",
    "objc_ivar",
    "builtin",
    "inlineasm",
    "switch",
    "objc_implement",
    "volatile",
    "align_stack",
    "or_break",
    "no_sanitize_memory",
    "system",
    "priority_index",
    "fast_math",
    "entry_point_only",
    "asm",
    "objc_is_class_method",
    "max_field_align",
    "c_vararg"
  };
#define odin_kwad_string_pool ((const char *) &odin_kwad_string_pool_contents)

static const unsigned char odin_kwad_lengths[] =
  {
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  4,  0,  0,  4,  0,  0,  0,  5,  4,  4,  6,  6,
     4,  6,  4,  0,  0,  7,  0,  5, 15,  4,  0,  4, 12,  5,
     9,  0,  8,  0, 12,  0, 22, 15,  0, 17,  0,  4,  6,  0,
     0,  8,  6, 13,  8,  0,  3, 12, 12, 13,  5,  7,  9,  3,
     6, 11,  4,  0,  6,  0,  0,  0,  4,  7, 11,  2,  5,  7,
     7,  6, 11,  4,  8, 11, 21,  5, 10,  0,  5,  5,  9,  0,
     6,  0,  0,  0,  7, 11,  0,  0,  6,  6,  0, 11, 10, 12,
     0,  0, 15, 18, 19,  8, 13, 22,  6,  0,  0,  9,  5,  6,
     8, 18, 19, 17,  6, 26,  7,  2,  2, 18,  0,  7,  0,  7,
     0, 14,  4,  0,  5,  7,  4,  0,  4,  4,  0,  7,  0, 24,
     7,  9, 12,  4,  6,  6,  0,  7, 13,  0,  9,  9,  3, 15,
    11, 10,  0,  7,  0, 21, 20,  0, 15, 21, 12,  4,  0, 15,
     9,  0,  4,  0,  9,  0,  0,  0,  9,  0,  9,  7,  0,  9,
     3, 15,  7,  0,  8,  0,  0,  0,  4,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  0, 16, 11,  0,
     0,  0,  9,  0,  0, 12,  0, 14,  7,  0, 11, 15,  5, 17,
     6,  9,  7,  0,  9,  6,  0,  0, 14,  0,  0,  0,  8,  0,
     0,  0,  0,  0, 11,  0,  8,  0,  0,  0, 18,  0,  6,  0,
    14,  9, 16,  0,  0,  0,  0,  3,  0,  0,  0, 20,  0,  0,
     0,  0, 15,  8
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
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 106 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str44, ODIN_KWAD_TEST, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 170 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str47, ODIN_KWAD_CC_NONE, OdinTokenCallingConvention},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 121 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str51, ODIN_KWAD_CONST, OdinTokenDirective},
#line 32 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str52, ODIN_KWAD_CAST, OdinTokenKeyword},
#line 130 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str53, ODIN_KWAD_LINE, OdinTokenDirective},
#line 25 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str54, ODIN_KWAD_RETURN, OdinTokenKeyword},
#line 46 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str55, ODIN_KWAD_NOT_IN, OdinTokenKeyword},
#line 37 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str56, ODIN_KWAD_ELSE, OdinTokenKeyword},
#line 50 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str57, ODIN_KWAD_STRUCT, OdinTokenKeyword},
#line 31 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str58, ODIN_KWAD_CASE, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 100 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str61, ODIN_KWAD_REQUIRE, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 167 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str63, ODIN_KWAD_CC_CDECL, OdinTokenCallingConvention},
#line 101 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str64, ODIN_KWAD_REQUIRE_RESULTS, OdinTokenAttribute},
#line 151 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str65, ODIN_KWAD_PURE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 161 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str67, ODIN_KWAD_TYPE, OdinTokenDirective},
#line 82 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str68, ODIN_KWAD_LINK_SECTION, OdinTokenAttribute},
#line 147 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str69, ODIN_KWAD_PANIC, OdinTokenDirective},
#line 80 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str70, ODIN_KWAD_LINK_NAME, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 20 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str72, ODIN_KWAD_CONTINUE, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 119 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str74, ODIN_KWAD_COLUMN_MAJOR, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 102 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str76, ODIN_KWAD_REQUIRE_TARGET_FEATURE, OdinTokenAttribute},
#line 117 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str77, ODIN_KWAD_CALLER_LOCATION, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 116 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str79, ODIN_KWAD_CALLER_EXPRESSION, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 58 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str81, ODIN_KWAD_COLD, OdinTokenAttribute},
#line 71 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str82, ODIN_KWAD_EXPORT, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 34 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str85, ODIN_KWAD_DISTINCT, OdinTokenKeyword},
#line 112 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str86, ODIN_KWAD_ASSERT, OdinTokenDirective},
#line 176 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str87, ODIN_KWAD_CC_PRESERVE_MOST, OdinTokenCallingConvention},
#line 149 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str88, ODIN_KWAD_PRESERVE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 39 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str90, ODIN_KWAD_FOR, OdinTokenKeyword},
#line 177 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str91, ODIN_KWAD_CC_PRESERVE_ALL, OdinTokenCallingConvention},
#line 107 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str92, ODIN_KWAD_THREAD_LOCAL, OdinTokenAttribute},
#line 175 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str93, ODIN_KWAD_CC_PRESERVE_NONE, OdinTokenCallingConvention},
#line 171 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str94, ODIN_KWAD_CC_NAKED, OdinTokenCallingConvention},
#line 168 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str95, ODIN_KWAD_CC_STDCALL, OdinTokenCallingConvention},
#line 28 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str96, ODIN_KWAD_AUTO_CAST, OdinTokenKeyword},
#line 158 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str97, ODIN_KWAD_SOA, OdinTokenDirective},
#line 159 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str98, ODIN_KWAD_SPARSE, OdinTokenDirective},
#line 110 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str99, ODIN_KWAD_ALL_OR_NONE, OdinTokenDirective},
#line 131 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str100, ODIN_KWAD_LOAD, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 104 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str102, ODIN_KWAD_STATIC, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 126 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str106, ODIN_KWAD_FILE, OdinTokenDirective},
#line 148 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str107, ODIN_KWAD_PARTIAL, OdinTokenDirective},
#line 162 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str108, ODIN_KWAD_TYPE_ASSERT, OdinTokenDirective},
#line 43 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str109, ODIN_KWAD_IN, OdinTokenKeyword},
#line 173 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str110, ODIN_KWAD_CC_WIN64, OdinTokenCallingConvention},
#line 30 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str111, ODIN_KWAD_BIT_SET, OdinTokenKeyword},
#line 19 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str112, ODIN_KWAD_CONTEXT, OdinTokenKeyword},
#line 163 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str113, ODIN_KWAD_UNROLL, OdinTokenDirective},
#line 83 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str114, ODIN_KWAD_LINK_SUFFIX, OdinTokenAttribute},
#line 55 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str115, ODIN_KWAD_WHEN, OdinTokenKeyword},
#line 68 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str116, ODIN_KWAD_DISABLED, OdinTokenAttribute},
#line 166 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str117, ODIN_KWAD_CC_CONTEXTLESS, OdinTokenCallingConvention},
#line 69 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str118, ODIN_KWAD_ENABLE_TARGET_FEATURE, OdinTokenAttribute},
#line 33 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str119, ODIN_KWAD_DEFER, OdinTokenKeyword},
#line 155 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str120, ODIN_KWAD_SHARED_NIL, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 18 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str122, ODIN_KWAD_BREAK, OdinTokenKeyword},
#line 56 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str123, ODIN_KWAD_WHERE, OdinTokenKeyword},
#line 152 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str124, ODIN_KWAD_RAW_UNION, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 26 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str126, ODIN_KWAD_TYPEID, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 160 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str130, ODIN_KWAD_SUBTYPE, OdinTokenDirective},
#line 81 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str131, ODIN_KWAD_LINK_PREFIX, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 146 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str134, ODIN_KWAD_PACKED, OdinTokenDirective},
#line 103 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str135, ODIN_KWAD_RODATA, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 60 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str137, ODIN_KWAD_DEFERRED_IN, OdinTokenAttribute},
#line 67 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str138, ODIN_KWAD_DEPRECATED, OdinTokenAttribute},
#line 65 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str139, ODIN_KWAD_DEFERRED_OUT, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 62 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str142, ODIN_KWAD_DEFERRED_IN_OUT, OdinTokenAttribute},
#line 61 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str143, ODIN_KWAD_DEFERRED_IN_BY_PTR, OdinTokenAttribute},
#line 66 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str144, ODIN_KWAD_DEFERRED_OUT_BY_PTR, OdinTokenAttribute},
#line 169 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str145, ODIN_KWAD_CC_FASTCALL, OdinTokenCallingConvention},
#line 64 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str146, ODIN_KWAD_DEFERRED_NONE, OdinTokenAttribute},
#line 63 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str147, ODIN_KWAD_DEFERRED_IN_OUT_BY_PTR, OdinTokenAttribute},
#line 125 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str148, ODIN_KWAD_EXISTS, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 154 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str151, ODIN_KWAD_ROW_MAJOR, OdinTokenDirective},
#line 108 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str152, ODIN_KWAD_ALIGN, OdinTokenDirective},
#line 142 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str153, ODIN_KWAD_NO_NIL, OdinTokenDirective},
#line 134 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str154, ODIN_KWAD_LOCATION, OdinTokenDirective},
#line 84 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str155, ODIN_KWAD_NO_INSTRUMENTATION, OdinTokenAttribute},
#line 85 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str156, ODIN_KWAD_NO_SANITIZE_ADDRESS, OdinTokenAttribute},
#line 75 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str157, ODIN_KWAD_IGNORE_DUPLICATES, OdinTokenAttribute},
#line 42 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str158, ODIN_KWAD_IMPORT, OdinTokenKeyword},
#line 59 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str159, ODIN_KWAD_DEFAULT_CALLING_CONVENTION, OdinTokenAttribute},
#line 79 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str160, ODIN_KWAD_LINKAGE, OdinTokenAttribute},
#line 35 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str161, ODIN_KWAD_DO, OdinTokenKeyword},
#line 41 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str162, ODIN_KWAD_IF, OdinTokenKeyword},
#line 72 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str163, ODIN_KWAD_EXTRA_LINKER_FLAGS, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 98 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str165, ODIN_KWAD_PRIVATE, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 123 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str167, ODIN_KWAD_DEFINED, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 143 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str169, ODIN_KWAD_NO_TYPE_ASSERT, OdinTokenDirective},
#line 174 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str170, ODIN_KWAD_CC_SYSV, OdinTokenCallingConvention},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 53 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str172, ODIN_KWAD_UNION, OdinTokenKeyword},
#line 36 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str173, ODIN_KWAD_DYNAMIC, OdinTokenKeyword},
#line 129 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str174, ODIN_KWAD_HASH, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 74 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str176, ODIN_KWAD_FINI, OdinTokenAttribute},
#line 49 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str177, ODIN_KWAD_PROC, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 118 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str179, ODIN_KWAD_CLOBBER, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 144 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str181, ODIN_KWAD_OPTIONAL_ALLOCATOR_ERROR, OdinTokenDirective},
#line 48 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str182, ODIN_KWAD_PACKAGE, OdinTokenKeyword},
#line 137 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str183, ODIN_KWAD_MUST_TAIL, OdinTokenDirective},
#line 113 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str184, ODIN_KWAD_BOUNDS_CHECK, OdinTokenDirective},
#line 156 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str185, ODIN_KWAD_SIMD, OdinTokenDirective},
#line 115 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str186, ODIN_KWAD_BY_PTR, OdinTokenDirective},
#line 157 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str187, ODIN_KWAD_SIMPLE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 153 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str189, ODIN_KWAD_REVERSE, OdinTokenDirective},
#line 93 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str190, ODIN_KWAD_OBJC_SELECTOR, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 92 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str192, ODIN_KWAD_OBJC_NAME, OdinTokenAttribute},
#line 95 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str193, ODIN_KWAD_OBJC_TYPE, OdinTokenAttribute},
#line 44 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str194, ODIN_KWAD_MAP, OdinTokenKeyword},
#line 94 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str195, ODIN_KWAD_OBJC_SUPERCLASS, OdinTokenAttribute},
#line 145 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str196, ODIN_KWAD_OPTIONAL_OK, OdinTokenDirective},
#line 87 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str197, ODIN_KWAD_OBJC_CLASS, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 40 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str199, ODIN_KWAD_FOREIGN, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 77 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str201, ODIN_KWAD_INSTRUMENTATION_ENTER, OdinTokenAttribute},
#line 78 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str202, ODIN_KWAD_INSTRUMENTATION_EXIT, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 114 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str204, ODIN_KWAD_BRANCH_LOCATION, OdinTokenDirective},
#line 88 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str205, ODIN_KWAD_OBJC_CONTEXT_PROVIDER, OdinTokenAttribute},
#line 127 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str206, ODIN_KWAD_FORCE_INLINE, OdinTokenDirective},
#line 76 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str207, ODIN_KWAD_INIT, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 128 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str209, ODIN_KWAD_FORCE_NO_INLINE, OdinTokenDirective},
#line 52 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str210, ODIN_KWAD_TRANSMUTE, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 38 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str212, ODIN_KWAD_ENUM, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 29 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str214, ODIN_KWAD_BIT_FIELD, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 150 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str218, ODIN_KWAD_PROCEDURE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 124 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str220, ODIN_KWAD_DIRECTORY, OdinTokenDirective},
#line 111 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str221, ODIN_KWAD_ANY_INT, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 133 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str223, ODIN_KWAD_LOAD_HASH, OdinTokenDirective},
#line 105 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str224, ODIN_KWAD_TAG, OdinTokenAttribute},
#line 139 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str225, ODIN_KWAD_NO_BOUNDS_CHECK, OdinTokenDirective},
#line 141 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str226, ODIN_KWAD_NO_INIT, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 138 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str228, ODIN_KWAD_NO_ALIAS, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 165 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str232, ODIN_KWAD_CC_ODIN, OdinTokenCallingConvention},
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
#line 120 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str247, ODIN_KWAD_CONFIG, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 99 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str249, ODIN_KWAD_RADDBG_TYPE_VIEW, OdinTokenAttribute},
#line 21 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str250, ODIN_KWAD_FALLTHROUGH, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 24 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str254, ODIN_KWAD_OR_RETURN, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 140 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str257, ODIN_KWAD_NO_BROADCAST, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 132 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str259, ODIN_KWAD_LOAD_DIRECTORY, OdinTokenDirective},
#line 47 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str260, ODIN_KWAD_OR_ELSE, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 23 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str262, ODIN_KWAD_OR_CONTINUE, OdinTokenKeyword},
#line 136 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str263, ODIN_KWAD_MIN_FIELD_ALIGN, OdinTokenDirective},
#line 54 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str264, ODIN_KWAD_USING, OdinTokenKeyword},
#line 96 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str265, ODIN_KWAD_OPTIMIZATION_MODE, OdinTokenAttribute},
#line 45 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str266, ODIN_KWAD_MATRIX, OdinTokenKeyword},
#line 91 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str267, ODIN_KWAD_OBJC_IVAR, OdinTokenAttribute},
#line 57 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str268, ODIN_KWAD_BUILTIN, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 172 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str270, ODIN_KWAD_CC_INLINEASM, OdinTokenCallingConvention},
#line 51 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str271, ODIN_KWAD_SWITCH, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 89 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str274, ODIN_KWAD_OBJC_IMPLEMENT, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 164 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str278, ODIN_KWAD_VOLATILE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 109 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str284, ODIN_KWAD_ALIGN_STACK, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 22 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str286, ODIN_KWAD_OR_BREAK, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 86 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str290, ODIN_KWAD_NO_SANITIZE_MEMORY, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 178 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str292, ODIN_KWAD_CC_SYSTEM, OdinTokenCallingConvention},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 97 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str294, ODIN_KWAD_PRIORITY_INDEX, OdinTokenAttribute},
#line 73 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str295, ODIN_KWAD_FAST_MATH, OdinTokenAttribute},
#line 70 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str296, ODIN_KWAD_ENTRY_POINT_ONLY, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 27 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str301, ODIN_KWAD_ASM, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 90 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str305, ODIN_KWAD_OBJC_IS_CLASS_METHOD, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 135 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str310, ODIN_KWAD_MAX_FIELD_ALIGN, OdinTokenDirective},
#line 122 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str311, ODIN_KWAD_C_VARARG, OdinTokenDirective}
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
