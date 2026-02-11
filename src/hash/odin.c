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

#define ODIN_KWAD_TOTAL_KEYWORDS 159
#define ODIN_KWAD_MIN_WORD_LENGTH 2
#define ODIN_KWAD_MAX_WORD_LENGTH 26
#define ODIN_KWAD_MIN_HASH_VALUE 9
#define ODIN_KWAD_MAX_HASH_VALUE 297
/* maximum key range = 289, duplicates = 0 */

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
      298, 298, 298, 298, 298, 298, 298, 298, 298, 298,
      298, 298, 298, 298, 298, 298, 298, 298, 298, 298,
      298, 298, 298, 298, 298, 298, 298, 298, 298, 298,
      298, 298, 298, 298, 298, 298, 298, 298, 298, 298,
      298, 298, 298, 298, 298, 298, 298, 298, 298, 298,
      298, 298,   3, 298, 298, 298, 298, 298, 298, 298,
      298, 298, 298, 298, 298, 298, 298, 298, 298, 298,
      298, 298, 298, 298, 298, 298, 298, 298, 298, 298,
      298, 298, 298, 298, 298, 298, 298, 298, 298, 298,
      298, 298, 298, 298, 298,  86, 298,  27,  20,  58,
        1,   5,  34,  79,  79,  81,  53,  92,   1,  57,
       10,  65,  70,  11,   1,   3,   1,  41,  11, 172,
       33, 133, 298, 298, 298, 298, 298, 298
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
    char odin_kwad_string_pool_str9[sizeof("test")];
    char odin_kwad_string_pool_str12[sizeof("struct")];
    char odin_kwad_string_pool_str13[sizeof("stdcall")];
    char odin_kwad_string_pool_str14[sizeof("disabled")];
    char odin_kwad_string_pool_str16[sizeof("thread_local")];
    char odin_kwad_string_pool_str17[sizeof("else")];
    char odin_kwad_string_pool_str20[sizeof("line")];
    char odin_kwad_string_pool_str21[sizeof("sysv")];
    char odin_kwad_string_pool_str23[sizeof("distinct")];
    char odin_kwad_string_pool_str24[sizeof("side_effects")];
    char odin_kwad_string_pool_str25[sizeof("require")];
    char odin_kwad_string_pool_str27[sizeof("reverse")];
    char odin_kwad_string_pool_str28[sizeof("return")];
    char odin_kwad_string_pool_str29[sizeof("none")];
    char odin_kwad_string_pool_str31[sizeof("require_results")];
    char odin_kwad_string_pool_str32[sizeof("att")];
    char odin_kwad_string_pool_str33[sizeof("load")];
    char odin_kwad_string_pool_str34[sizeof("bit_set")];
    char odin_kwad_string_pool_str35[sizeof("link_name")];
    char odin_kwad_string_pool_str36[sizeof("link_section")];
    char odin_kwad_string_pool_str37[sizeof("not_in")];
    char odin_kwad_string_pool_str38[sizeof("assert")];
    char odin_kwad_string_pool_str39[sizeof("for")];
    char odin_kwad_string_pool_str40[sizeof("require_target_feature")];
    char odin_kwad_string_pool_str41[sizeof("defer")];
    char odin_kwad_string_pool_str42[sizeof("shared_nil")];
    char odin_kwad_string_pool_str44[sizeof("file")];
    char odin_kwad_string_pool_str45[sizeof("all_or_none")];
    char odin_kwad_string_pool_str46[sizeof("sparse")];
    char odin_kwad_string_pool_str48[sizeof("defined")];
    char odin_kwad_string_pool_str49[sizeof("deferred_out")];
    char odin_kwad_string_pool_str50[sizeof("unroll")];
    char odin_kwad_string_pool_str52[sizeof("deferred_in_out")];
    char odin_kwad_string_pool_str54[sizeof("deferred_none")];
    char odin_kwad_string_pool_str55[sizeof("deferred_in_by_ptr")];
    char odin_kwad_string_pool_str56[sizeof("deferred_out_by_ptr")];
    char odin_kwad_string_pool_str57[sizeof("deferred_in")];
    char odin_kwad_string_pool_str58[sizeof("link_suffix")];
    char odin_kwad_string_pool_str59[sizeof("deferred_in_out_by_ptr")];
    char odin_kwad_string_pool_str60[sizeof("soa")];
    char odin_kwad_string_pool_str62[sizeof("rodata")];
    char odin_kwad_string_pool_str63[sizeof("enable_target_feature")];
    char odin_kwad_string_pool_str64[sizeof("cold")];
    char odin_kwad_string_pool_str65[sizeof("simd")];
    char odin_kwad_string_pool_str66[sizeof("cast")];
    char odin_kwad_string_pool_str68[sizeof("do")];
    char odin_kwad_string_pool_str69[sizeof("cdecl")];
    char odin_kwad_string_pool_str70[sizeof("case")];
    char odin_kwad_string_pool_str71[sizeof("must_tail")];
    char odin_kwad_string_pool_str72[sizeof("default_calling_convention")];
    char odin_kwad_string_pool_str73[sizeof("fastcall")];
    char odin_kwad_string_pool_str74[sizeof("const")];
    char odin_kwad_string_pool_str76[sizeof("simple")];
    char odin_kwad_string_pool_str79[sizeof("typeid")];
    char odin_kwad_string_pool_str80[sizeof("type")];
    char odin_kwad_string_pool_str82[sizeof("column_major")];
    char odin_kwad_string_pool_str83[sizeof("export")];
    char odin_kwad_string_pool_str85[sizeof("caller_location")];
    char odin_kwad_string_pool_str87[sizeof("caller_expression")];
    char odin_kwad_string_pool_str88[sizeof("intel")];
    char odin_kwad_string_pool_str89[sizeof("preserve/all")];
    char odin_kwad_string_pool_str90[sizeof("preserve/most")];
    char odin_kwad_string_pool_str91[sizeof("continue")];
    char odin_kwad_string_pool_str93[sizeof("in")];
    char odin_kwad_string_pool_str94[sizeof("preserve/none")];
    char odin_kwad_string_pool_str96[sizeof("auto_cast")];
    char odin_kwad_string_pool_str98[sizeof("exists")];
    char odin_kwad_string_pool_str99[sizeof("transmute")];
    char odin_kwad_string_pool_str101[sizeof("optional_allocator_error")];
    char odin_kwad_string_pool_str102[sizeof("linkage")];
    char odin_kwad_string_pool_str104[sizeof("no_nil")];
    char odin_kwad_string_pool_str105[sizeof("subtype")];
    char odin_kwad_string_pool_str106[sizeof("partial")];
    char odin_kwad_string_pool_str107[sizeof("enum")];
    char odin_kwad_string_pool_str108[sizeof("naked")];
    char odin_kwad_string_pool_str109[sizeof("context")];
    char odin_kwad_string_pool_str110[sizeof("type_assert")];
    char odin_kwad_string_pool_str112[sizeof("bit_field")];
    char odin_kwad_string_pool_str113[sizeof("extra_linker_flags")];
    char odin_kwad_string_pool_str114[sizeof("by_ptr")];
    char odin_kwad_string_pool_str115[sizeof("contextless")];
    char odin_kwad_string_pool_str116[sizeof("ignore_duplicates")];
    char odin_kwad_string_pool_str117[sizeof("if")];
    char odin_kwad_string_pool_str122[sizeof("break")];
    char odin_kwad_string_pool_str123[sizeof("align")];
    char odin_kwad_string_pool_str125[sizeof("link_prefix")];
    char odin_kwad_string_pool_str126[sizeof("system")];
    char odin_kwad_string_pool_str127[sizeof("no_instrumentation")];
    char odin_kwad_string_pool_str128[sizeof("no_sanitize_address")];
    char odin_kwad_string_pool_str129[sizeof("fini")];
    char odin_kwad_string_pool_str130[sizeof("matrix")];
    char odin_kwad_string_pool_str131[sizeof("foreign")];
    char odin_kwad_string_pool_str133[sizeof("objc_type")];
    char odin_kwad_string_pool_str135[sizeof("objc_selector")];
    char odin_kwad_string_pool_str136[sizeof("packed")];
    char odin_kwad_string_pool_str137[sizeof("union")];
    char odin_kwad_string_pool_str138[sizeof("force_inline")];
    char odin_kwad_string_pool_str139[sizeof("objc_superclass")];
    char odin_kwad_string_pool_str140[sizeof("deprecated")];
    char odin_kwad_string_pool_str141[sizeof("force_no_inline")];
    char odin_kwad_string_pool_str142[sizeof("objc_name")];
    char odin_kwad_string_pool_str143[sizeof("panic")];
    char odin_kwad_string_pool_str144[sizeof("asm")];
    char odin_kwad_string_pool_str145[sizeof("directory")];
    char odin_kwad_string_pool_str146[sizeof("instrumentation_exit")];
    char odin_kwad_string_pool_str147[sizeof("instrumentation_enter")];
    char odin_kwad_string_pool_str150[sizeof("procedure")];
    char odin_kwad_string_pool_str151[sizeof("branch_location")];
    char odin_kwad_string_pool_str152[sizeof("static")];
    char odin_kwad_string_pool_str153[sizeof("inlineasm")];
    char odin_kwad_string_pool_str157[sizeof("dynamic")];
    char odin_kwad_string_pool_str158[sizeof("location")];
    char odin_kwad_string_pool_str159[sizeof("import")];
    char odin_kwad_string_pool_str160[sizeof("odin")];
    char odin_kwad_string_pool_str162[sizeof("tag")];
    char odin_kwad_string_pool_str164[sizeof("private")];
    char odin_kwad_string_pool_str165[sizeof("hash")];
    char odin_kwad_string_pool_str166[sizeof("or_else")];
    char odin_kwad_string_pool_str167[sizeof("init")];
    char odin_kwad_string_pool_str168[sizeof("bounds_check")];
    char odin_kwad_string_pool_str169[sizeof("optimization_mode")];
    char odin_kwad_string_pool_str171[sizeof("or_return")];
    char odin_kwad_string_pool_str173[sizeof("min_field_align")];
    char odin_kwad_string_pool_str174[sizeof("no_broadcast")];
    char odin_kwad_string_pool_str176[sizeof("load_directory")];
    char odin_kwad_string_pool_str177[sizeof("or_continue")];
    char odin_kwad_string_pool_str178[sizeof("any_int")];
    char odin_kwad_string_pool_str179[sizeof("optional_ok")];
    char odin_kwad_string_pool_str181[sizeof("no_type_assert")];
    char odin_kwad_string_pool_str182[sizeof("fast_math")];
    char odin_kwad_string_pool_str183[sizeof("c_vararg")];
    char odin_kwad_string_pool_str187[sizeof("where")];
    char odin_kwad_string_pool_str188[sizeof("no_alias")];
    char odin_kwad_string_pool_str189[sizeof("objc_class")];
    char odin_kwad_string_pool_str190[sizeof("win64")];
    char odin_kwad_string_pool_str191[sizeof("when")];
    char odin_kwad_string_pool_str195[sizeof("load_hash")];
    char odin_kwad_string_pool_str196[sizeof("max_field_align")];
    char odin_kwad_string_pool_str197[sizeof("proc")];
    char odin_kwad_string_pool_str198[sizeof("objc_context_provider")];
    char odin_kwad_string_pool_str199[sizeof("builtin")];
    char odin_kwad_string_pool_str200[sizeof("map")];
    char odin_kwad_string_pool_str202[sizeof("raw_union")];
    char odin_kwad_string_pool_str204[sizeof("fallthrough")];
    char odin_kwad_string_pool_str206[sizeof("using")];
    char odin_kwad_string_pool_str209[sizeof("objc_ivar")];
    char odin_kwad_string_pool_str210[sizeof("row_major")];
    char odin_kwad_string_pool_str214[sizeof("objc_implement")];
    char odin_kwad_string_pool_str219[sizeof("package")];
    char odin_kwad_string_pool_str220[sizeof("objc_is_class_method")];
    char odin_kwad_string_pool_str232[sizeof("config")];
    char odin_kwad_string_pool_str241[sizeof("entry_point_only")];
    char odin_kwad_string_pool_str244[sizeof("no_bounds_check")];
    char odin_kwad_string_pool_str248[sizeof("switch")];
    char odin_kwad_string_pool_str256[sizeof("or_break")];
    char odin_kwad_string_pool_str257[sizeof("no_sanitize_memory")];
    char odin_kwad_string_pool_str269[sizeof("raddbg_type_view")];
    char odin_kwad_string_pool_str279[sizeof("priority_index")];
    char odin_kwad_string_pool_str297[sizeof("align_stack")];
  };
static const struct odin_kwad_string_pool_t odin_kwad_string_pool_contents =
  {
    "test",
    "struct",
    "stdcall",
    "disabled",
    "thread_local",
    "else",
    "line",
    "sysv",
    "distinct",
    "side_effects",
    "require",
    "reverse",
    "return",
    "none",
    "require_results",
    "att",
    "load",
    "bit_set",
    "link_name",
    "link_section",
    "not_in",
    "assert",
    "for",
    "require_target_feature",
    "defer",
    "shared_nil",
    "file",
    "all_or_none",
    "sparse",
    "defined",
    "deferred_out",
    "unroll",
    "deferred_in_out",
    "deferred_none",
    "deferred_in_by_ptr",
    "deferred_out_by_ptr",
    "deferred_in",
    "link_suffix",
    "deferred_in_out_by_ptr",
    "soa",
    "rodata",
    "enable_target_feature",
    "cold",
    "simd",
    "cast",
    "do",
    "cdecl",
    "case",
    "must_tail",
    "default_calling_convention",
    "fastcall",
    "const",
    "simple",
    "typeid",
    "type",
    "column_major",
    "export",
    "caller_location",
    "caller_expression",
    "intel",
    "preserve/all",
    "preserve/most",
    "continue",
    "in",
    "preserve/none",
    "auto_cast",
    "exists",
    "transmute",
    "optional_allocator_error",
    "linkage",
    "no_nil",
    "subtype",
    "partial",
    "enum",
    "naked",
    "context",
    "type_assert",
    "bit_field",
    "extra_linker_flags",
    "by_ptr",
    "contextless",
    "ignore_duplicates",
    "if",
    "break",
    "align",
    "link_prefix",
    "system",
    "no_instrumentation",
    "no_sanitize_address",
    "fini",
    "matrix",
    "foreign",
    "objc_type",
    "objc_selector",
    "packed",
    "union",
    "force_inline",
    "objc_superclass",
    "deprecated",
    "force_no_inline",
    "objc_name",
    "panic",
    "asm",
    "directory",
    "instrumentation_exit",
    "instrumentation_enter",
    "procedure",
    "branch_location",
    "static",
    "inlineasm",
    "dynamic",
    "location",
    "import",
    "odin",
    "tag",
    "private",
    "hash",
    "or_else",
    "init",
    "bounds_check",
    "optimization_mode",
    "or_return",
    "min_field_align",
    "no_broadcast",
    "load_directory",
    "or_continue",
    "any_int",
    "optional_ok",
    "no_type_assert",
    "fast_math",
    "c_vararg",
    "where",
    "no_alias",
    "objc_class",
    "win64",
    "when",
    "load_hash",
    "max_field_align",
    "proc",
    "objc_context_provider",
    "builtin",
    "map",
    "raw_union",
    "fallthrough",
    "using",
    "objc_ivar",
    "row_major",
    "objc_implement",
    "package",
    "objc_is_class_method",
    "config",
    "entry_point_only",
    "no_bounds_check",
    "switch",
    "or_break",
    "no_sanitize_memory",
    "raddbg_type_view",
    "priority_index",
    "align_stack"
  };
#define odin_kwad_string_pool ((const char *) &odin_kwad_string_pool_contents)

static const unsigned char odin_kwad_lengths[] =
  {
     0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  6,  7,
     8,  0, 12,  4,  0,  0,  4,  4,  0,  8, 12,  7,  0,  7,
     6,  4,  0, 15,  3,  4,  7,  9, 12,  6,  6,  3, 22,  5,
    10,  0,  4, 11,  6,  0,  7, 12,  6,  0, 15,  0, 13, 18,
    19, 11, 11, 22,  3,  0,  6, 21,  4,  4,  4,  0,  2,  5,
     4,  9, 26,  8,  5,  0,  6,  0,  0,  6,  4,  0, 12,  6,
     0, 15,  0, 17,  5, 12, 13,  8,  0,  2, 13,  0,  9,  0,
     6,  9,  0, 24,  7,  0,  6,  7,  7,  4,  5,  7, 11,  0,
     9, 18,  6, 11, 17,  2,  0,  0,  0,  0,  5,  5,  0, 11,
     6, 18, 19,  4,  6,  7,  0,  9,  0, 13,  6,  5, 12, 15,
    10, 15,  9,  5,  3,  9, 20, 21,  0,  0,  9, 15,  6,  9,
     0,  0,  0,  7,  8,  6,  4,  0,  3,  0,  7,  4,  7,  4,
    12, 17,  0,  9,  0, 15, 12,  0, 14, 11,  7, 11,  0, 14,
     9,  8,  0,  0,  0,  5,  8, 10,  5,  4,  0,  0,  0,  9,
    15,  4, 21,  7,  3,  0,  9,  0, 11,  0,  5,  0,  0,  9,
     9,  0,  0,  0, 14,  0,  0,  0,  0,  7, 20,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  6,  0,  0,  0,  0,  0,
     0,  0,  0, 16,  0,  0, 15,  0,  0,  0,  6,  0,  0,  0,
     0,  0,  0,  0,  8, 18,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0, 14,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0, 11
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
#line 106 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str9, ODIN_KWAD_TEST, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 50 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str12, ODIN_KWAD_STRUCT, OdinTokenKeyword},
#line 166 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str13, ODIN_KWAD_CC_STDCALL, OdinTokenCallingConvention},
#line 68 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str14, ODIN_KWAD_DISABLED, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 107 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str16, ODIN_KWAD_THREAD_LOCAL, OdinTokenAttribute},
#line 37 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str17, ODIN_KWAD_ELSE, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 131 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str20, ODIN_KWAD_LINE, OdinTokenDirective},
#line 172 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str21, ODIN_KWAD_CC_SYSV, OdinTokenCallingConvention},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 34 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str23, ODIN_KWAD_DISTINCT, OdinTokenKeyword},
#line 154 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str24, ODIN_KWAD_SIDE_EFFECTS, OdinTokenDirective},
#line 100 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str25, ODIN_KWAD_REQUIRE, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 151 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str27, ODIN_KWAD_REVERSE, OdinTokenDirective},
#line 25 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str28, ODIN_KWAD_RETURN, OdinTokenKeyword},
#line 168 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str29, ODIN_KWAD_CC_NONE, OdinTokenCallingConvention},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 101 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str31, ODIN_KWAD_REQUIRE_RESULTS, OdinTokenAttribute},
#line 112 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str32, ODIN_KWAD_ATT, OdinTokenDirective},
#line 132 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str33, ODIN_KWAD_LOAD, OdinTokenDirective},
#line 30 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str34, ODIN_KWAD_BIT_SET, OdinTokenKeyword},
#line 80 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str35, ODIN_KWAD_LINK_NAME, OdinTokenAttribute},
#line 82 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str36, ODIN_KWAD_LINK_SECTION, OdinTokenAttribute},
#line 46 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str37, ODIN_KWAD_NOT_IN, OdinTokenKeyword},
#line 113 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str38, ODIN_KWAD_ASSERT, OdinTokenDirective},
#line 39 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str39, ODIN_KWAD_FOR, OdinTokenKeyword},
#line 102 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str40, ODIN_KWAD_REQUIRE_TARGET_FEATURE, OdinTokenAttribute},
#line 33 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str41, ODIN_KWAD_DEFER, OdinTokenKeyword},
#line 153 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str42, ODIN_KWAD_SHARED_NIL, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 126 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str44, ODIN_KWAD_FILE, OdinTokenDirective},
#line 110 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str45, ODIN_KWAD_ALL_OR_NONE, OdinTokenDirective},
#line 158 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str46, ODIN_KWAD_SPARSE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 123 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str48, ODIN_KWAD_DEFINED, OdinTokenDirective},
#line 65 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str49, ODIN_KWAD_DEFERRED_OUT, OdinTokenAttribute},
#line 162 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str50, ODIN_KWAD_UNROLL, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 62 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str52, ODIN_KWAD_DEFERRED_IN_OUT, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 64 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str54, ODIN_KWAD_DEFERRED_NONE, OdinTokenAttribute},
#line 61 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str55, ODIN_KWAD_DEFERRED_IN_BY_PTR, OdinTokenAttribute},
#line 66 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str56, ODIN_KWAD_DEFERRED_OUT_BY_PTR, OdinTokenAttribute},
#line 60 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str57, ODIN_KWAD_DEFERRED_IN, OdinTokenAttribute},
#line 83 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str58, ODIN_KWAD_LINK_SUFFIX, OdinTokenAttribute},
#line 63 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str59, ODIN_KWAD_DEFERRED_IN_OUT_BY_PTR, OdinTokenAttribute},
#line 157 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str60, ODIN_KWAD_SOA, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 103 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str62, ODIN_KWAD_RODATA, OdinTokenAttribute},
#line 69 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str63, ODIN_KWAD_ENABLE_TARGET_FEATURE, OdinTokenAttribute},
#line 58 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str64, ODIN_KWAD_COLD, OdinTokenAttribute},
#line 155 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str65, ODIN_KWAD_SIMD, OdinTokenDirective},
#line 32 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str66, ODIN_KWAD_CAST, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 35 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str68, ODIN_KWAD_DO, OdinTokenKeyword},
#line 165 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str69, ODIN_KWAD_CC_CDECL, OdinTokenCallingConvention},
#line 31 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str70, ODIN_KWAD_CASE, OdinTokenKeyword},
#line 138 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str71, ODIN_KWAD_MUST_TAIL, OdinTokenDirective},
#line 59 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str72, ODIN_KWAD_DEFAULT_CALLING_CONVENTION, OdinTokenAttribute},
#line 167 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str73, ODIN_KWAD_CC_FASTCALL, OdinTokenCallingConvention},
#line 121 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str74, ODIN_KWAD_CONST, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 156 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str76, ODIN_KWAD_SIMPLE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 26 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str79, ODIN_KWAD_TYPEID, OdinTokenKeyword},
#line 160 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str80, ODIN_KWAD_TYPE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 119 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str82, ODIN_KWAD_COLUMN_MAJOR, OdinTokenDirective},
#line 71 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str83, ODIN_KWAD_EXPORT, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 118 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str85, ODIN_KWAD_CALLER_LOCATION, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 117 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str87, ODIN_KWAD_CALLER_EXPRESSION, OdinTokenDirective},
#line 130 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str88, ODIN_KWAD_INTEL, OdinTokenDirective},
#line 175 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str89, ODIN_KWAD_CC_PRESERVE_ALL, OdinTokenCallingConvention},
#line 174 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str90, ODIN_KWAD_CC_PRESERVE_MOST, OdinTokenCallingConvention},
#line 20 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str91, ODIN_KWAD_CONTINUE, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 43 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str93, ODIN_KWAD_IN, OdinTokenKeyword},
#line 173 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str94, ODIN_KWAD_CC_PRESERVE_NONE, OdinTokenCallingConvention},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 28 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str96, ODIN_KWAD_AUTO_CAST, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 125 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str98, ODIN_KWAD_EXISTS, OdinTokenDirective},
#line 52 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str99, ODIN_KWAD_TRANSMUTE, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 144 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str101, ODIN_KWAD_OPTIONAL_ALLOCATOR_ERROR, OdinTokenDirective},
#line 79 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str102, ODIN_KWAD_LINKAGE, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 142 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str104, ODIN_KWAD_NO_NIL, OdinTokenDirective},
#line 159 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str105, ODIN_KWAD_SUBTYPE, OdinTokenDirective},
#line 148 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str106, ODIN_KWAD_PARTIAL, OdinTokenDirective},
#line 38 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str107, ODIN_KWAD_ENUM, OdinTokenKeyword},
#line 169 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str108, ODIN_KWAD_CC_NAKED, OdinTokenCallingConvention},
#line 19 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str109, ODIN_KWAD_CONTEXT, OdinTokenKeyword},
#line 161 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str110, ODIN_KWAD_TYPE_ASSERT, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 29 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str112, ODIN_KWAD_BIT_FIELD, OdinTokenKeyword},
#line 72 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str113, ODIN_KWAD_EXTRA_LINKER_FLAGS, OdinTokenAttribute},
#line 116 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str114, ODIN_KWAD_BY_PTR, OdinTokenDirective},
#line 164 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str115, ODIN_KWAD_CC_CONTEXTLESS, OdinTokenCallingConvention},
#line 75 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str116, ODIN_KWAD_IGNORE_DUPLICATES, OdinTokenAttribute},
#line 41 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str117, ODIN_KWAD_IF, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 18 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str122, ODIN_KWAD_BREAK, OdinTokenKeyword},
#line 108 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str123, ODIN_KWAD_ALIGN, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 81 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str125, ODIN_KWAD_LINK_PREFIX, OdinTokenAttribute},
#line 176 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str126, ODIN_KWAD_CC_SYSTEM, OdinTokenCallingConvention},
#line 84 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str127, ODIN_KWAD_NO_INSTRUMENTATION, OdinTokenAttribute},
#line 85 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str128, ODIN_KWAD_NO_SANITIZE_ADDRESS, OdinTokenAttribute},
#line 74 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str129, ODIN_KWAD_FINI, OdinTokenAttribute},
#line 45 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str130, ODIN_KWAD_MATRIX, OdinTokenKeyword},
#line 40 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str131, ODIN_KWAD_FOREIGN, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 95 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str133, ODIN_KWAD_OBJC_TYPE, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 93 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str135, ODIN_KWAD_OBJC_SELECTOR, OdinTokenAttribute},
#line 146 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str136, ODIN_KWAD_PACKED, OdinTokenDirective},
#line 53 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str137, ODIN_KWAD_UNION, OdinTokenKeyword},
#line 127 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str138, ODIN_KWAD_FORCE_INLINE, OdinTokenDirective},
#line 94 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str139, ODIN_KWAD_OBJC_SUPERCLASS, OdinTokenAttribute},
#line 67 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str140, ODIN_KWAD_DEPRECATED, OdinTokenAttribute},
#line 128 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str141, ODIN_KWAD_FORCE_NO_INLINE, OdinTokenDirective},
#line 92 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str142, ODIN_KWAD_OBJC_NAME, OdinTokenAttribute},
#line 147 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str143, ODIN_KWAD_PANIC, OdinTokenDirective},
#line 27 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str144, ODIN_KWAD_ASM, OdinTokenKeyword},
#line 124 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str145, ODIN_KWAD_DIRECTORY, OdinTokenDirective},
#line 78 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str146, ODIN_KWAD_INSTRUMENTATION_EXIT, OdinTokenAttribute},
#line 77 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str147, ODIN_KWAD_INSTRUMENTATION_ENTER, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 149 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str150, ODIN_KWAD_PROCEDURE, OdinTokenDirective},
#line 115 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str151, ODIN_KWAD_BRANCH_LOCATION, OdinTokenDirective},
#line 104 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str152, ODIN_KWAD_STATIC, OdinTokenAttribute},
#line 170 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str153, ODIN_KWAD_CC_INLINEASM, OdinTokenCallingConvention},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 36 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str157, ODIN_KWAD_DYNAMIC, OdinTokenKeyword},
#line 135 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str158, ODIN_KWAD_LOCATION, OdinTokenDirective},
#line 42 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str159, ODIN_KWAD_IMPORT, OdinTokenKeyword},
#line 163 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str160, ODIN_KWAD_CC_ODIN, OdinTokenCallingConvention},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 105 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str162, ODIN_KWAD_TAG, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 98 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str164, ODIN_KWAD_PRIVATE, OdinTokenAttribute},
#line 129 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str165, ODIN_KWAD_HASH, OdinTokenDirective},
#line 47 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str166, ODIN_KWAD_OR_ELSE, OdinTokenKeyword},
#line 76 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str167, ODIN_KWAD_INIT, OdinTokenAttribute},
#line 114 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str168, ODIN_KWAD_BOUNDS_CHECK, OdinTokenDirective},
#line 96 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str169, ODIN_KWAD_OPTIMIZATION_MODE, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 24 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str171, ODIN_KWAD_OR_RETURN, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 137 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str173, ODIN_KWAD_MIN_FIELD_ALIGN, OdinTokenDirective},
#line 141 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str174, ODIN_KWAD_NO_BROADCAST, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 133 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str176, ODIN_KWAD_LOAD_DIRECTORY, OdinTokenDirective},
#line 23 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str177, ODIN_KWAD_OR_CONTINUE, OdinTokenKeyword},
#line 111 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str178, ODIN_KWAD_ANY_INT, OdinTokenDirective},
#line 145 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str179, ODIN_KWAD_OPTIONAL_OK, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 143 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str181, ODIN_KWAD_NO_TYPE_ASSERT, OdinTokenDirective},
#line 73 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str182, ODIN_KWAD_FAST_MATH, OdinTokenAttribute},
#line 122 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str183, ODIN_KWAD_C_VARARG, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 56 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str187, ODIN_KWAD_WHERE, OdinTokenKeyword},
#line 139 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str188, ODIN_KWAD_NO_ALIAS, OdinTokenDirective},
#line 87 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str189, ODIN_KWAD_OBJC_CLASS, OdinTokenAttribute},
#line 171 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str190, ODIN_KWAD_CC_WIN64, OdinTokenCallingConvention},
#line 55 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str191, ODIN_KWAD_WHEN, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 134 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str195, ODIN_KWAD_LOAD_HASH, OdinTokenDirective},
#line 136 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str196, ODIN_KWAD_MAX_FIELD_ALIGN, OdinTokenDirective},
#line 49 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str197, ODIN_KWAD_PROC, OdinTokenKeyword},
#line 88 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str198, ODIN_KWAD_OBJC_CONTEXT_PROVIDER, OdinTokenAttribute},
#line 57 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str199, ODIN_KWAD_BUILTIN, OdinTokenAttribute},
#line 44 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str200, ODIN_KWAD_MAP, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 150 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str202, ODIN_KWAD_RAW_UNION, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 21 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str204, ODIN_KWAD_FALLTHROUGH, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 54 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str206, ODIN_KWAD_USING, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 91 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str209, ODIN_KWAD_OBJC_IVAR, OdinTokenAttribute},
#line 152 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str210, ODIN_KWAD_ROW_MAJOR, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 89 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str214, ODIN_KWAD_OBJC_IMPLEMENT, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 48 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str219, ODIN_KWAD_PACKAGE, OdinTokenKeyword},
#line 90 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str220, ODIN_KWAD_OBJC_IS_CLASS_METHOD, OdinTokenAttribute},
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
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str232, ODIN_KWAD_CONFIG, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 70 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str241, ODIN_KWAD_ENTRY_POINT_ONLY, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 140 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str244, ODIN_KWAD_NO_BOUNDS_CHECK, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 51 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str248, ODIN_KWAD_SWITCH, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 22 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str256, ODIN_KWAD_OR_BREAK, OdinTokenKeyword},
#line 86 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str257, ODIN_KWAD_NO_SANITIZE_MEMORY, OdinTokenAttribute},
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
#line 99 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str269, ODIN_KWAD_RADDBG_TYPE_VIEW, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 97 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str279, ODIN_KWAD_PRIORITY_INDEX, OdinTokenAttribute},
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
#line 109 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str297, ODIN_KWAD_ALIGN_STACK, OdinTokenDirective}
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
