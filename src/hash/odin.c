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
struct OdinKwad { int kwad_offset; uint16_t valid_symbols_idx; uint8_t type; };

#define ODIN_KWAD_TOTAL_KEYWORDS 166
#define ODIN_KWAD_MIN_WORD_LENGTH 2
#define ODIN_KWAD_MAX_WORD_LENGTH 26
#define ODIN_KWAD_MIN_HASH_VALUE 17
#define ODIN_KWAD_MAX_HASH_VALUE 287
/* maximum key range = 271, duplicates = 0 */

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
      288, 288, 288, 288, 288, 288, 288, 288, 288, 288,
      288, 288, 288, 288, 288, 288, 288, 288, 288, 288,
      288, 288, 288, 288, 288, 288, 288, 288, 288, 288,
      288, 288, 288, 288, 288, 288, 288, 288, 288, 288,
      288, 288, 288, 288, 288, 288, 288, 288, 288, 288,
      288, 288,   5, 288, 288, 288, 288, 288, 288, 288,
      288, 288, 288, 288, 288, 288, 288, 288, 288, 288,
      288, 288, 288, 288, 288, 288, 288, 288, 288, 288,
      288, 288, 288, 288, 288, 288, 288, 288, 288, 288,
      288, 288, 288, 288, 288,  44, 288,  55,   4,  33,
       23,   7,  67,  81,  92,  90,  28,  74,  17, 114,
       10, 120,   7,  18,  14,   5,   4,  72, 100,  64,
       13, 136, 288, 288, 288, 288, 288, 288
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
    char odin_kwad_string_pool_str17[sizeof("test")];
    char odin_kwad_string_pool_str19[sizeof("byte")];
    char odin_kwad_string_pool_str20[sizeof("post")];
    char odin_kwad_string_pool_str22[sizeof("type")];
    char odin_kwad_string_pool_str23[sizeof("else")];
    char odin_kwad_string_pool_str24[sizeof("pre")];
    char odin_kwad_string_pool_str26[sizeof("bit_set")];
    char odin_kwad_string_pool_str27[sizeof("nop")];
    char odin_kwad_string_pool_str28[sizeof("export")];
    char odin_kwad_string_pool_str30[sizeof("subtype")];
    char odin_kwad_string_pool_str31[sizeof("none")];
    char odin_kwad_string_pool_str32[sizeof("pure")];
    char odin_kwad_string_pool_str33[sizeof("struct")];
    char odin_kwad_string_pool_str38[sizeof("line")];
    char odin_kwad_string_pool_str40[sizeof("not_in")];
    char odin_kwad_string_pool_str43[sizeof("preserve")];
    char odin_kwad_string_pool_str44[sizeof("return")];
    char odin_kwad_string_pool_str45[sizeof("preserve/most")];
    char odin_kwad_string_pool_str46[sizeof("cast")];
    char odin_kwad_string_pool_str48[sizeof("preserve/none")];
    char odin_kwad_string_pool_str49[sizeof("case")];
    char odin_kwad_string_pool_str50[sizeof("distinct")];
    char odin_kwad_string_pool_str52[sizeof("const")];
    char odin_kwad_string_pool_str53[sizeof("link_name")];
    char odin_kwad_string_pool_str54[sizeof("link_section")];
    char odin_kwad_string_pool_str55[sizeof("panic")];
    char odin_kwad_string_pool_str56[sizeof("link_suffix")];
    char odin_kwad_string_pool_str57[sizeof("preserve/all")];
    char odin_kwad_string_pool_str58[sizeof("link_prefix")];
    char odin_kwad_string_pool_str60[sizeof("require")];
    char odin_kwad_string_pool_str62[sizeof("cdecl")];
    char odin_kwad_string_pool_str63[sizeof("typeid")];
    char odin_kwad_string_pool_str66[sizeof("require_results")];
    char odin_kwad_string_pool_str67[sizeof("context")];
    char odin_kwad_string_pool_str68[sizeof("continue")];
    char odin_kwad_string_pool_str69[sizeof("stdcall")];
    char odin_kwad_string_pool_str70[sizeof("thread_local")];
    char odin_kwad_string_pool_str72[sizeof("contextless")];
    char odin_kwad_string_pool_str74[sizeof("assert")];
    char odin_kwad_string_pool_str75[sizeof("require_target_feature")];
    char odin_kwad_string_pool_str76[sizeof("disabled")];
    char odin_kwad_string_pool_str77[sizeof("cold")];
    char odin_kwad_string_pool_str78[sizeof("extra_linker_flags")];
    char odin_kwad_string_pool_str79[sizeof("no_type_assert")];
    char odin_kwad_string_pool_str80[sizeof("sparse")];
    char odin_kwad_string_pool_str81[sizeof("type_assert")];
    char odin_kwad_string_pool_str82[sizeof("by_ptr")];
    char odin_kwad_string_pool_str83[sizeof("where")];
    char odin_kwad_string_pool_str84[sizeof("win64")];
    char odin_kwad_string_pool_str85[sizeof("when")];
    char odin_kwad_string_pool_str86[sizeof("column_major")];
    char odin_kwad_string_pool_str87[sizeof("no_instrumentation")];
    char odin_kwad_string_pool_str88[sizeof("no_sanitize_address")];
    char odin_kwad_string_pool_str89[sizeof("caller_location")];
    char odin_kwad_string_pool_str90[sizeof("break")];
    char odin_kwad_string_pool_str91[sizeof("caller_expression")];
    char odin_kwad_string_pool_str92[sizeof("packed")];
    char odin_kwad_string_pool_str94[sizeof("no_nil")];
    char odin_kwad_string_pool_str95[sizeof("file")];
    char odin_kwad_string_pool_str96[sizeof("deprecated")];
    char odin_kwad_string_pool_str97[sizeof("enable_target_feature")];
    char odin_kwad_string_pool_str98[sizeof("for")];
    char odin_kwad_string_pool_str99[sizeof("load")];
    char odin_kwad_string_pool_str100[sizeof("partial")];
    char odin_kwad_string_pool_str102[sizeof("in")];
    char odin_kwad_string_pool_str104[sizeof("all_or_none")];
    char odin_kwad_string_pool_str105[sizeof("auto_cast")];
    char odin_kwad_string_pool_str106[sizeof("skip")];
    char odin_kwad_string_pool_str107[sizeof("raw_union")];
    char odin_kwad_string_pool_str109[sizeof("defer")];
    char odin_kwad_string_pool_str110[sizeof("shared_nil")];
    char odin_kwad_string_pool_str111[sizeof("import")];
    char odin_kwad_string_pool_str112[sizeof("naked")];
    char odin_kwad_string_pool_str113[sizeof("exists")];
    char odin_kwad_string_pool_str114[sizeof("sysv")];
    char odin_kwad_string_pool_str115[sizeof("private")];
    char odin_kwad_string_pool_str118[sizeof("soa")];
    char odin_kwad_string_pool_str120[sizeof("deferred_out")];
    char odin_kwad_string_pool_str122[sizeof("linkage")];
    char odin_kwad_string_pool_str123[sizeof("deferred_in_out")];
    char odin_kwad_string_pool_str124[sizeof("deferred_none")];
    char odin_kwad_string_pool_str125[sizeof("deferred_in")];
    char odin_kwad_string_pool_str126[sizeof("unroll")];
    char odin_kwad_string_pool_str127[sizeof("defined")];
    char odin_kwad_string_pool_str129[sizeof("ignore_duplicates")];
    char odin_kwad_string_pool_str130[sizeof("bit_field")];
    char odin_kwad_string_pool_str131[sizeof("map")];
    char odin_kwad_string_pool_str132[sizeof("static")];
    char odin_kwad_string_pool_str133[sizeof("reverse")];
    char odin_kwad_string_pool_str135[sizeof("package")];
    char odin_kwad_string_pool_str136[sizeof("deferred_in_by_ptr")];
    char odin_kwad_string_pool_str137[sizeof("deferred_out_by_ptr")];
    char odin_kwad_string_pool_str139[sizeof("simple")];
    char odin_kwad_string_pool_str140[sizeof("deferred_in_out_by_ptr")];
    char odin_kwad_string_pool_str143[sizeof("default_calling_convention")];
    char odin_kwad_string_pool_str144[sizeof("force_inline")];
    char odin_kwad_string_pool_str145[sizeof("do")];
    char odin_kwad_string_pool_str146[sizeof("simd")];
    char odin_kwad_string_pool_str147[sizeof("force_no_inline")];
    char odin_kwad_string_pool_str149[sizeof("must_tail")];
    char odin_kwad_string_pool_str150[sizeof("matrix")];
    char odin_kwad_string_pool_str152[sizeof("fastcall")];
    char odin_kwad_string_pool_str153[sizeof("rodata")];
    char odin_kwad_string_pool_str155[sizeof("no_init")];
    char odin_kwad_string_pool_str156[sizeof("row_major")];
    char odin_kwad_string_pool_str157[sizeof("no_alias")];
    char odin_kwad_string_pool_str158[sizeof("location")];
    char odin_kwad_string_pool_str159[sizeof("if")];
    char odin_kwad_string_pool_str160[sizeof("align")];
    char odin_kwad_string_pool_str163[sizeof("dynamic")];
    char odin_kwad_string_pool_str164[sizeof("proc")];
    char odin_kwad_string_pool_str166[sizeof("procedure")];
    char odin_kwad_string_pool_str167[sizeof("bounds_check")];
    char odin_kwad_string_pool_str168[sizeof("objc_type")];
    char odin_kwad_string_pool_str169[sizeof("tag")];
    char odin_kwad_string_pool_str171[sizeof("fini")];
    char odin_kwad_string_pool_str172[sizeof("optional_allocator_error")];
    char odin_kwad_string_pool_str173[sizeof("objc_superclass")];
    char odin_kwad_string_pool_str174[sizeof("objc_name")];
    char odin_kwad_string_pool_str176[sizeof("branch_location")];
    char odin_kwad_string_pool_str177[sizeof("union")];
    char odin_kwad_string_pool_str179[sizeof("foreign")];
    char odin_kwad_string_pool_str180[sizeof("objc_selector")];
    char odin_kwad_string_pool_str181[sizeof("clobber")];
    char odin_kwad_string_pool_str183[sizeof("or_else")];
    char odin_kwad_string_pool_str186[sizeof("directory")];
    char odin_kwad_string_pool_str187[sizeof("or_return")];
    char odin_kwad_string_pool_str188[sizeof("init")];
    char odin_kwad_string_pool_str189[sizeof("transmute")];
    char odin_kwad_string_pool_str190[sizeof("no_broadcast")];
    char odin_kwad_string_pool_str191[sizeof("instrumentation_exit")];
    char odin_kwad_string_pool_str192[sizeof("or_continue")];
    char odin_kwad_string_pool_str193[sizeof("hash")];
    char odin_kwad_string_pool_str196[sizeof("objc_class")];
    char odin_kwad_string_pool_str197[sizeof("enum")];
    char odin_kwad_string_pool_str198[sizeof("raddbg_type_view")];
    char odin_kwad_string_pool_str201[sizeof("builtin")];
    char odin_kwad_string_pool_str202[sizeof("instrumentation_enter")];
    char odin_kwad_string_pool_str207[sizeof("entry_point_only")];
    char odin_kwad_string_pool_str211[sizeof("config")];
    char odin_kwad_string_pool_str212[sizeof("any_int")];
    char odin_kwad_string_pool_str214[sizeof("priority_index")];
    char odin_kwad_string_pool_str215[sizeof("no_bounds_check")];
    char odin_kwad_string_pool_str216[sizeof("objc_context_provider")];
    char odin_kwad_string_pool_str218[sizeof("no_sanitize_memory")];
    char odin_kwad_string_pool_str219[sizeof("optional_ok")];
    char odin_kwad_string_pool_str222[sizeof("volatile")];
    char odin_kwad_string_pool_str224[sizeof("odin")];
    char odin_kwad_string_pool_str237[sizeof("inlineasm")];
    char odin_kwad_string_pool_str238[sizeof("optimization_mode")];
    char odin_kwad_string_pool_str239[sizeof("min_field_align")];
    char odin_kwad_string_pool_str242[sizeof("max_field_align")];
    char odin_kwad_string_pool_str244[sizeof("system")];
    char odin_kwad_string_pool_str245[sizeof("load_directory")];
    char odin_kwad_string_pool_str248[sizeof("using")];
    char odin_kwad_string_pool_str253[sizeof("or_break")];
    char odin_kwad_string_pool_str256[sizeof("objc_implement")];
    char odin_kwad_string_pool_str261[sizeof("objc_ivar")];
    char odin_kwad_string_pool_str265[sizeof("load_hash")];
    char odin_kwad_string_pool_str274[sizeof("align_stack")];
    char odin_kwad_string_pool_str277[sizeof("c_vararg")];
    char odin_kwad_string_pool_str279[sizeof("fallthrough")];
    char odin_kwad_string_pool_str281[sizeof("objc_is_class_method")];
    char odin_kwad_string_pool_str285[sizeof("switch")];
    char odin_kwad_string_pool_str286[sizeof("asm")];
    char odin_kwad_string_pool_str287[sizeof("fast_math")];
  };
static const struct odin_kwad_string_pool_t odin_kwad_string_pool_contents =
  {
    "test",
    "byte",
    "post",
    "type",
    "else",
    "pre",
    "bit_set",
    "nop",
    "export",
    "subtype",
    "none",
    "pure",
    "struct",
    "line",
    "not_in",
    "preserve",
    "return",
    "preserve/most",
    "cast",
    "preserve/none",
    "case",
    "distinct",
    "const",
    "link_name",
    "link_section",
    "panic",
    "link_suffix",
    "preserve/all",
    "link_prefix",
    "require",
    "cdecl",
    "typeid",
    "require_results",
    "context",
    "continue",
    "stdcall",
    "thread_local",
    "contextless",
    "assert",
    "require_target_feature",
    "disabled",
    "cold",
    "extra_linker_flags",
    "no_type_assert",
    "sparse",
    "type_assert",
    "by_ptr",
    "where",
    "win64",
    "when",
    "column_major",
    "no_instrumentation",
    "no_sanitize_address",
    "caller_location",
    "break",
    "caller_expression",
    "packed",
    "no_nil",
    "file",
    "deprecated",
    "enable_target_feature",
    "for",
    "load",
    "partial",
    "in",
    "all_or_none",
    "auto_cast",
    "skip",
    "raw_union",
    "defer",
    "shared_nil",
    "import",
    "naked",
    "exists",
    "sysv",
    "private",
    "soa",
    "deferred_out",
    "linkage",
    "deferred_in_out",
    "deferred_none",
    "deferred_in",
    "unroll",
    "defined",
    "ignore_duplicates",
    "bit_field",
    "map",
    "static",
    "reverse",
    "package",
    "deferred_in_by_ptr",
    "deferred_out_by_ptr",
    "simple",
    "deferred_in_out_by_ptr",
    "default_calling_convention",
    "force_inline",
    "do",
    "simd",
    "force_no_inline",
    "must_tail",
    "matrix",
    "fastcall",
    "rodata",
    "no_init",
    "row_major",
    "no_alias",
    "location",
    "if",
    "align",
    "dynamic",
    "proc",
    "procedure",
    "bounds_check",
    "objc_type",
    "tag",
    "fini",
    "optional_allocator_error",
    "objc_superclass",
    "objc_name",
    "branch_location",
    "union",
    "foreign",
    "objc_selector",
    "clobber",
    "or_else",
    "directory",
    "or_return",
    "init",
    "transmute",
    "no_broadcast",
    "instrumentation_exit",
    "or_continue",
    "hash",
    "objc_class",
    "enum",
    "raddbg_type_view",
    "builtin",
    "instrumentation_enter",
    "entry_point_only",
    "config",
    "any_int",
    "priority_index",
    "no_bounds_check",
    "objc_context_provider",
    "no_sanitize_memory",
    "optional_ok",
    "volatile",
    "odin",
    "inlineasm",
    "optimization_mode",
    "min_field_align",
    "max_field_align",
    "system",
    "load_directory",
    "using",
    "or_break",
    "objc_implement",
    "objc_ivar",
    "load_hash",
    "align_stack",
    "c_vararg",
    "fallthrough",
    "objc_is_class_method",
    "switch",
    "asm",
    "fast_math"
  };
#define odin_kwad_string_pool ((const char *) &odin_kwad_string_pool_contents)

static const unsigned char odin_kwad_lengths[] =
  {
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  4,  0,  4,  4,  0,  4,  4,  3,  0,  7,  3,
     6,  0,  7,  4,  4,  6,  0,  0,  0,  0,  4,  0,  6,  0,
     0,  8,  6, 13,  4,  0, 13,  4,  8,  0,  5,  9, 12,  5,
    11, 12, 11,  0,  7,  0,  5,  6,  0,  0, 15,  7,  8,  7,
    12,  0, 11,  0,  6, 22,  8,  4, 18, 14,  6, 11,  6,  5,
     5,  4, 12, 18, 19, 15,  5, 17,  6,  0,  6,  4, 10, 21,
     3,  4,  7,  0,  2,  0, 11,  9,  4,  9,  0,  5, 10,  6,
     5,  6,  4,  7,  0,  0,  3,  0, 12,  0,  7, 15, 13, 11,
     6,  7,  0, 17,  9,  3,  6,  7,  0,  7, 18, 19,  0,  6,
    22,  0,  0, 26, 12,  2,  4, 15,  0,  9,  6,  0,  8,  6,
     0,  7,  9,  8,  8,  2,  5,  0,  0,  7,  4,  0,  9, 12,
     9,  3,  0,  4, 24, 15,  9,  0, 15,  5,  0,  7, 13,  7,
     0,  7,  0,  0,  9,  9,  4,  9, 12, 20, 11,  4,  0,  0,
    10,  4, 16,  0,  0,  7, 21,  0,  0,  0,  0, 16,  0,  0,
     0,  6,  7,  0, 14, 15, 21,  0, 18, 11,  0,  0,  8,  0,
     4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,
    17, 15,  0,  0, 15,  0,  6, 14,  0,  0,  5,  0,  0,  0,
     0,  8,  0,  0, 14,  0,  0,  0,  0,  9,  0,  0,  0,  9,
     0,  0,  0,  0,  0,  0,  0,  0, 11,  0,  0,  8,  0, 11,
     0, 20,  0,  0,  0,  6,  3,  9
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
#line 106 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str17, ODIN_KWAD_TEST, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 116 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str19, ODIN_KWAD_BYTE, OdinTokenDirective,},
#line 151 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str20, ODIN_KWAD_POST, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 166 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str22, ODIN_KWAD_TYPE, OdinTokenDirective},
#line 37 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str23, ODIN_KWAD_ELSE, OdinTokenKeyword},
#line 152 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str24, ODIN_KWAD_PRE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 30 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str26, ODIN_KWAD_BIT_SET, OdinTokenKeyword},
#line 145 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str27, ODIN_KWAD_NOP, OdinTokenDirective,},
#line 71 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str28, ODIN_KWAD_EXPORT, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 165 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str30, ODIN_KWAD_SUBTYPE, OdinTokenDirective},
#line 175 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str31, ODIN_KWAD_CC_NONE, OdinTokenCallingConvention},
#line 155 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str32, ODIN_KWAD_PURE, OdinTokenDirective},
#line 50 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str33, ODIN_KWAD_STRUCT, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 131 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str38, ODIN_KWAD_LINE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 46 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str40, ODIN_KWAD_NOT_IN, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 153 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str43, ODIN_KWAD_PRESERVE, OdinTokenDirective},
#line 25 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str44, ODIN_KWAD_RETURN, OdinTokenKeyword},
#line 181 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str45, ODIN_KWAD_CC_PRESERVE_MOST, OdinTokenCallingConvention},
#line 32 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str46, ODIN_KWAD_CAST, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 180 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str48, ODIN_KWAD_CC_PRESERVE_NONE, OdinTokenCallingConvention},
#line 31 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str49, ODIN_KWAD_CASE, OdinTokenKeyword},
#line 34 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str50, ODIN_KWAD_DISTINCT, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 122 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str52, ODIN_KWAD_CONST, OdinTokenDirective},
#line 80 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str53, ODIN_KWAD_LINK_NAME, OdinTokenAttribute},
#line 82 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str54, ODIN_KWAD_LINK_SECTION, OdinTokenAttribute},
#line 149 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str55, ODIN_KWAD_PANIC, OdinTokenDirective},
#line 83 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str56, ODIN_KWAD_LINK_SUFFIX, OdinTokenAttribute},
#line 182 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str57, ODIN_KWAD_CC_PRESERVE_ALL, OdinTokenCallingConvention},
#line 81 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str58, ODIN_KWAD_LINK_PREFIX, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 100 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str60, ODIN_KWAD_REQUIRE, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 172 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str62, ODIN_KWAD_CC_CDECL, OdinTokenCallingConvention},
#line 26 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str63, ODIN_KWAD_TYPEID, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 101 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str66, ODIN_KWAD_REQUIRE_RESULTS, OdinTokenAttribute},
#line 19 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str67, ODIN_KWAD_CONTEXT, OdinTokenKeyword},
#line 20 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str68, ODIN_KWAD_CONTINUE, OdinTokenKeyword},
#line 173 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str69, ODIN_KWAD_CC_STDCALL, OdinTokenCallingConvention},
#line 107 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str70, ODIN_KWAD_THREAD_LOCAL, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 171 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str72, ODIN_KWAD_CC_CONTEXTLESS, OdinTokenCallingConvention},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 112 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str74, ODIN_KWAD_ASSERT, OdinTokenDirective},
#line 102 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str75, ODIN_KWAD_REQUIRE_TARGET_FEATURE, OdinTokenAttribute},
#line 68 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str76, ODIN_KWAD_DISABLED, OdinTokenAttribute},
#line 58 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str77, ODIN_KWAD_COLD, OdinTokenAttribute},
#line 72 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str78, ODIN_KWAD_EXTRA_LINKER_FLAGS, OdinTokenAttribute},
#line 144 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str79, ODIN_KWAD_NO_TYPE_ASSERT, OdinTokenDirective},
#line 164 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str80, ODIN_KWAD_SPARSE, OdinTokenDirective},
#line 167 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str81, ODIN_KWAD_TYPE_ASSERT, OdinTokenDirective},
#line 115 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str82, ODIN_KWAD_BY_PTR, OdinTokenDirective},
#line 56 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str83, ODIN_KWAD_WHERE, OdinTokenKeyword},
#line 178 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str84, ODIN_KWAD_CC_WIN64, OdinTokenCallingConvention},
#line 55 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str85, ODIN_KWAD_WHEN, OdinTokenKeyword},
#line 120 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str86, ODIN_KWAD_COLUMN_MAJOR, OdinTokenDirective},
#line 84 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str87, ODIN_KWAD_NO_INSTRUMENTATION, OdinTokenAttribute},
#line 85 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str88, ODIN_KWAD_NO_SANITIZE_ADDRESS, OdinTokenAttribute},
#line 118 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str89, ODIN_KWAD_CALLER_LOCATION, OdinTokenDirective},
#line 18 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str90, ODIN_KWAD_BREAK, OdinTokenKeyword},
#line 117 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str91, ODIN_KWAD_CALLER_EXPRESSION, OdinTokenDirective},
#line 148 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str92, ODIN_KWAD_PACKED, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 143 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str94, ODIN_KWAD_NO_NIL, OdinTokenDirective},
#line 127 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str95, ODIN_KWAD_FILE, OdinTokenDirective},
#line 67 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str96, ODIN_KWAD_DEPRECATED, OdinTokenAttribute},
#line 69 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str97, ODIN_KWAD_ENABLE_TARGET_FEATURE, OdinTokenAttribute},
#line 39 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str98, ODIN_KWAD_FOR, OdinTokenKeyword},
#line 132 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str99, ODIN_KWAD_LOAD, OdinTokenDirective},
#line 150 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str100, ODIN_KWAD_PARTIAL, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 43 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str102, ODIN_KWAD_IN, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 110 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str104, ODIN_KWAD_ALL_OR_NONE, OdinTokenDirective},
#line 28 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str105, ODIN_KWAD_AUTO_CAST, OdinTokenKeyword},
#line 162 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str106, ODIN_KWAD_SKIP, OdinTokenDirective,},
#line 156 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str107, ODIN_KWAD_RAW_UNION, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 33 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str109, ODIN_KWAD_DEFER, OdinTokenKeyword},
#line 159 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str110, ODIN_KWAD_SHARED_NIL, OdinTokenDirective},
#line 42 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str111, ODIN_KWAD_IMPORT, OdinTokenKeyword},
#line 176 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str112, ODIN_KWAD_CC_NAKED, OdinTokenCallingConvention},
#line 126 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str113, ODIN_KWAD_EXISTS, OdinTokenDirective},
#line 179 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str114, ODIN_KWAD_CC_SYSV, OdinTokenCallingConvention},
#line 98 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str115, ODIN_KWAD_PRIVATE, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 163 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str118, ODIN_KWAD_SOA, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 65 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str120, ODIN_KWAD_DEFERRED_OUT, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 79 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str122, ODIN_KWAD_LINKAGE, OdinTokenAttribute},
#line 62 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str123, ODIN_KWAD_DEFERRED_IN_OUT, OdinTokenAttribute},
#line 64 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str124, ODIN_KWAD_DEFERRED_NONE, OdinTokenAttribute},
#line 60 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str125, ODIN_KWAD_DEFERRED_IN, OdinTokenAttribute},
#line 168 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str126, ODIN_KWAD_UNROLL, OdinTokenDirective},
#line 124 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str127, ODIN_KWAD_DEFINED, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 75 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str129, ODIN_KWAD_IGNORE_DUPLICATES, OdinTokenAttribute},
#line 29 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str130, ODIN_KWAD_BIT_FIELD, OdinTokenKeyword},
#line 44 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str131, ODIN_KWAD_MAP, OdinTokenKeyword},
#line 104 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str132, ODIN_KWAD_STATIC, OdinTokenAttribute},
#line 157 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str133, ODIN_KWAD_REVERSE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 48 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str135, ODIN_KWAD_PACKAGE, OdinTokenKeyword},
#line 61 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str136, ODIN_KWAD_DEFERRED_IN_BY_PTR, OdinTokenAttribute},
#line 66 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str137, ODIN_KWAD_DEFERRED_OUT_BY_PTR, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 161 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str139, ODIN_KWAD_SIMPLE, OdinTokenDirective},
#line 63 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str140, ODIN_KWAD_DEFERRED_IN_OUT_BY_PTR, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 59 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str143, ODIN_KWAD_DEFAULT_CALLING_CONVENTION, OdinTokenAttribute},
#line 128 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str144, ODIN_KWAD_FORCE_INLINE, OdinTokenDirective},
#line 35 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str145, ODIN_KWAD_DO, OdinTokenKeyword},
#line 160 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str146, ODIN_KWAD_SIMD, OdinTokenDirective},
#line 129 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str147, ODIN_KWAD_FORCE_NO_INLINE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 138 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str149, ODIN_KWAD_MUST_TAIL, OdinTokenDirective},
#line 45 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str150, ODIN_KWAD_MATRIX, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 174 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str152, ODIN_KWAD_CC_FASTCALL, OdinTokenCallingConvention},
#line 103 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str153, ODIN_KWAD_RODATA, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 142 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str155, ODIN_KWAD_NO_INIT, OdinTokenDirective},
#line 158 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str156, ODIN_KWAD_ROW_MAJOR, OdinTokenDirective},
#line 139 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str157, ODIN_KWAD_NO_ALIAS, OdinTokenDirective},
#line 135 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str158, ODIN_KWAD_LOCATION, OdinTokenDirective},
#line 41 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str159, ODIN_KWAD_IF, OdinTokenKeyword},
#line 108 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str160, ODIN_KWAD_ALIGN, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 36 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str163, ODIN_KWAD_DYNAMIC, OdinTokenKeyword},
#line 49 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str164, ODIN_KWAD_PROC, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 154 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str166, ODIN_KWAD_PROCEDURE, OdinTokenDirective},
#line 113 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str167, ODIN_KWAD_BOUNDS_CHECK, OdinTokenDirective},
#line 95 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str168, ODIN_KWAD_OBJC_TYPE, OdinTokenAttribute},
#line 105 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str169, ODIN_KWAD_TAG, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 74 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str171, ODIN_KWAD_FINI, OdinTokenAttribute},
#line 146 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str172, ODIN_KWAD_OPTIONAL_ALLOCATOR_ERROR, OdinTokenDirective},
#line 94 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str173, ODIN_KWAD_OBJC_SUPERCLASS, OdinTokenAttribute},
#line 92 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str174, ODIN_KWAD_OBJC_NAME, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 114 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str176, ODIN_KWAD_BRANCH_LOCATION, OdinTokenDirective},
#line 53 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str177, ODIN_KWAD_UNION, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 40 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str179, ODIN_KWAD_FOREIGN, OdinTokenKeyword},
#line 93 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str180, ODIN_KWAD_OBJC_SELECTOR, OdinTokenAttribute},
#line 119 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str181, ODIN_KWAD_CLOBBER, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 47 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str183, ODIN_KWAD_OR_ELSE, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 125 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str186, ODIN_KWAD_DIRECTORY, OdinTokenDirective},
#line 24 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str187, ODIN_KWAD_OR_RETURN, OdinTokenKeyword},
#line 76 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str188, ODIN_KWAD_INIT, OdinTokenAttribute},
#line 52 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str189, ODIN_KWAD_TRANSMUTE, OdinTokenKeyword},
#line 141 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str190, ODIN_KWAD_NO_BROADCAST, OdinTokenDirective},
#line 78 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str191, ODIN_KWAD_INSTRUMENTATION_EXIT, OdinTokenAttribute},
#line 23 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str192, ODIN_KWAD_OR_CONTINUE, OdinTokenKeyword},
#line 130 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str193, ODIN_KWAD_HASH, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 87 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str196, ODIN_KWAD_OBJC_CLASS, OdinTokenAttribute},
#line 38 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str197, ODIN_KWAD_ENUM, OdinTokenKeyword},
#line 99 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str198, ODIN_KWAD_RADDBG_TYPE_VIEW, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 57 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str201, ODIN_KWAD_BUILTIN, OdinTokenAttribute},
#line 77 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str202, ODIN_KWAD_INSTRUMENTATION_ENTER, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 70 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str207, ODIN_KWAD_ENTRY_POINT_ONLY, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 121 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str211, ODIN_KWAD_CONFIG, OdinTokenDirective},
#line 111 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str212, ODIN_KWAD_ANY_INT, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 97 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str214, ODIN_KWAD_PRIORITY_INDEX, OdinTokenAttribute},
#line 140 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str215, ODIN_KWAD_NO_BOUNDS_CHECK, OdinTokenDirective},
#line 88 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str216, ODIN_KWAD_OBJC_CONTEXT_PROVIDER, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 86 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str218, ODIN_KWAD_NO_SANITIZE_MEMORY, OdinTokenAttribute},
#line 147 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str219, ODIN_KWAD_OPTIONAL_OK, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 169 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str222, ODIN_KWAD_VOLATILE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 170 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str224, ODIN_KWAD_CC_ODIN, OdinTokenCallingConvention},
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
#line 177 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str237, ODIN_KWAD_CC_INLINEASM, OdinTokenCallingConvention},
#line 96 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str238, ODIN_KWAD_OPTIMIZATION_MODE, OdinTokenAttribute},
#line 137 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str239, ODIN_KWAD_MIN_FIELD_ALIGN, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 136 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str242, ODIN_KWAD_MAX_FIELD_ALIGN, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 183 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str244, ODIN_KWAD_CC_SYSTEM, OdinTokenCallingConvention},
#line 133 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str245, ODIN_KWAD_LOAD_DIRECTORY, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 54 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str248, ODIN_KWAD_USING, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 22 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str253, ODIN_KWAD_OR_BREAK, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 89 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str256, ODIN_KWAD_OBJC_IMPLEMENT, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 91 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str261, ODIN_KWAD_OBJC_IVAR, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 134 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str265, ODIN_KWAD_LOAD_HASH, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 109 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str274, ODIN_KWAD_ALIGN_STACK, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 123 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str277, ODIN_KWAD_C_VARARG, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 21 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str279, ODIN_KWAD_FALLTHROUGH, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 90 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str281, ODIN_KWAD_OBJC_IS_CLASS_METHOD, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 51 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str285, ODIN_KWAD_SWITCH, OdinTokenKeyword},
#line 27 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str286, ODIN_KWAD_ASM, OdinTokenKeyword},
#line 73 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str287, ODIN_KWAD_FAST_MATH, OdinTokenAttribute}
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
