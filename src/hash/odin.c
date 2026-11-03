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

#define ODIN_KWAD_TOTAL_KEYWORDS 171
#define ODIN_KWAD_MIN_WORD_LENGTH 2
#define ODIN_KWAD_MAX_WORD_LENGTH 26
#define ODIN_KWAD_MIN_HASH_VALUE 16
#define ODIN_KWAD_MAX_HASH_VALUE 331
/* maximum key range = 316, duplicates = 0 */

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
      332, 332, 332, 332, 332, 332, 332, 332, 332, 332,
      332, 332, 332, 332, 332, 332, 332, 332, 332, 332,
      332, 332, 332, 332, 332, 332, 332, 332, 332, 332,
      332, 332, 332, 332, 332, 332, 332, 332, 332, 332,
      332, 332, 332, 332, 332, 332, 332, 332, 332, 332,
      332, 332,   8, 332, 332, 332, 332, 332, 332, 332,
      332, 332, 332, 332, 332, 332, 332, 332, 332, 332,
      332, 332, 332, 332, 332, 332, 332, 332, 332, 332,
      332, 332, 332, 332, 332, 332, 332, 332, 332, 332,
      332, 332, 332, 332, 332,  95, 332,  83,  49,  32,
       26,   8,  57, 109,  46, 113,  50,  16,  24, 122,
       11, 122,   9, 174,   8,   4,   4,  57,  37,  12,
       25,  76, 332, 332, 332, 332, 332, 332
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
    char odin_kwad_string_pool_str16[sizeof("test")];
    char odin_kwad_string_pool_str21[sizeof("post")];
    char odin_kwad_string_pool_str24[sizeof("else")];
    char odin_kwad_string_pool_str25[sizeof("type")];
    char odin_kwad_string_pool_str26[sizeof("struct")];
    char odin_kwad_string_pool_str28[sizeof("pre")];
    char odin_kwad_string_pool_str29[sizeof("pure")];
    char odin_kwad_string_pool_str31[sizeof("export")];
    char odin_kwad_string_pool_str32[sizeof("nop")];
    char odin_kwad_string_pool_str33[sizeof("where")];
    char odin_kwad_string_pool_str34[sizeof("none")];
    char odin_kwad_string_pool_str35[sizeof("when")];
    char odin_kwad_string_pool_str36[sizeof("win64")];
    char odin_kwad_string_pool_str39[sizeof("synchronizes")];
    char odin_kwad_string_pool_str40[sizeof("return")];
    char odin_kwad_string_pool_str41[sizeof("preserve")];
    char odin_kwad_string_pool_str42[sizeof("preserve/most")];
    char odin_kwad_string_pool_str43[sizeof("not_in")];
    char odin_kwad_string_pool_str44[sizeof("cast")];
    char odin_kwad_string_pool_str46[sizeof("preserve/none")];
    char odin_kwad_string_pool_str47[sizeof("line")];
    char odin_kwad_string_pool_str48[sizeof("case")];
    char odin_kwad_string_pool_str49[sizeof("sysv")];
    char odin_kwad_string_pool_str51[sizeof("raw_union")];
    char odin_kwad_string_pool_str52[sizeof("const")];
    char odin_kwad_string_pool_str53[sizeof("distinct")];
    char odin_kwad_string_pool_str57[sizeof("panic")];
    char odin_kwad_string_pool_str58[sizeof("naked")];
    char odin_kwad_string_pool_str61[sizeof("preserve/all")];
    char odin_kwad_string_pool_str62[sizeof("link_section")];
    char odin_kwad_string_pool_str63[sizeof("link_name")];
    char odin_kwad_string_pool_str64[sizeof("reverse")];
    char odin_kwad_string_pool_str65[sizeof("byte")];
    char odin_kwad_string_pool_str68[sizeof("synchronizes_shared")];
    char odin_kwad_string_pool_str69[sizeof("cdecl")];
    char odin_kwad_string_pool_str70[sizeof("continue")];
    char odin_kwad_string_pool_str71[sizeof("typeid")];
    char odin_kwad_string_pool_str72[sizeof("bit_set")];
    char odin_kwad_string_pool_str74[sizeof("thread_local")];
    char odin_kwad_string_pool_str75[sizeof("link_suffix")];
    char odin_kwad_string_pool_str76[sizeof("for")];
    char odin_kwad_string_pool_str77[sizeof("subtype")];
    char odin_kwad_string_pool_str78[sizeof("break")];
    char odin_kwad_string_pool_str79[sizeof("context")];
    char odin_kwad_string_pool_str80[sizeof("link_prefix")];
    char odin_kwad_string_pool_str83[sizeof("contextless")];
    char odin_kwad_string_pool_str85[sizeof("stdcall")];
    char odin_kwad_string_pool_str86[sizeof("cold")];
    char odin_kwad_string_pool_str87[sizeof("column_major")];
    char odin_kwad_string_pool_str88[sizeof("disabled")];
    char odin_kwad_string_pool_str90[sizeof("caller_location")];
    char odin_kwad_string_pool_str91[sizeof("futex")];
    char odin_kwad_string_pool_str92[sizeof("caller_expression")];
    char odin_kwad_string_pool_str93[sizeof("file")];
    char odin_kwad_string_pool_str96[sizeof("defer")];
    char odin_kwad_string_pool_str99[sizeof("packed")];
    char odin_kwad_string_pool_str100[sizeof("hash")];
    char odin_kwad_string_pool_str101[sizeof("assert")];
    char odin_kwad_string_pool_str103[sizeof("deprecated")];
    char odin_kwad_string_pool_str107[sizeof("deferred_out")];
    char odin_kwad_string_pool_str109[sizeof("sparse")];
    char odin_kwad_string_pool_str110[sizeof("deferred_in_out")];
    char odin_kwad_string_pool_str111[sizeof("type_assert")];
    char odin_kwad_string_pool_str112[sizeof("deferred_none")];
    char odin_kwad_string_pool_str113[sizeof("deferred_in")];
    char odin_kwad_string_pool_str117[sizeof("deferred_in_by_ptr")];
    char odin_kwad_string_pool_str118[sizeof("deferred_out_by_ptr")];
    char odin_kwad_string_pool_str119[sizeof("unroll")];
    char odin_kwad_string_pool_str120[sizeof("row_major")];
    char odin_kwad_string_pool_str121[sizeof("deferred_in_out_by_ptr")];
    char odin_kwad_string_pool_str123[sizeof("directory")];
    char odin_kwad_string_pool_str124[sizeof("defined")];
    char odin_kwad_string_pool_str126[sizeof("in")];
    char odin_kwad_string_pool_str128[sizeof("enable_target_feature")];
    char odin_kwad_string_pool_str129[sizeof("extra_linker_flags")];
    char odin_kwad_string_pool_str130[sizeof("skip")];
    char odin_kwad_string_pool_str131[sizeof("partial")];
    char odin_kwad_string_pool_str132[sizeof("auto_cast")];
    char odin_kwad_string_pool_str133[sizeof("no_type_assert")];
    char odin_kwad_string_pool_str134[sizeof("all_or_none")];
    char odin_kwad_string_pool_str135[sizeof("exists")];
    char odin_kwad_string_pool_str136[sizeof("import")];
    char odin_kwad_string_pool_str137[sizeof("load")];
    char odin_kwad_string_pool_str138[sizeof("bounds_check")];
    char odin_kwad_string_pool_str139[sizeof("no_instrumentation")];
    char odin_kwad_string_pool_str140[sizeof("no_sanitize_address")];
    char odin_kwad_string_pool_str141[sizeof("private")];
    char odin_kwad_string_pool_str143[sizeof("map")];
    char odin_kwad_string_pool_str144[sizeof("default_calling_convention")];
    char odin_kwad_string_pool_str147[sizeof("shared_nil")];
    char odin_kwad_string_pool_str148[sizeof("simple")];
    char odin_kwad_string_pool_str150[sizeof("do")];
    char odin_kwad_string_pool_str153[sizeof("ignore_duplicates")];
    char odin_kwad_string_pool_str156[sizeof("simd")];
    char odin_kwad_string_pool_str157[sizeof("static")];
    char odin_kwad_string_pool_str159[sizeof("linkage")];
    char odin_kwad_string_pool_str160[sizeof("no_nil")];
    char odin_kwad_string_pool_str161[sizeof("no_sanitize_thread")];
    char odin_kwad_string_pool_str163[sizeof("must_tail")];
    char odin_kwad_string_pool_str164[sizeof("optional_ok")];
    char odin_kwad_string_pool_str165[sizeof("package")];
    char odin_kwad_string_pool_str166[sizeof("by_ptr")];
    char odin_kwad_string_pool_str167[sizeof("proc")];
    char odin_kwad_string_pool_str169[sizeof("optional_allocator_error")];
    char odin_kwad_string_pool_str171[sizeof("raddbg_type_view")];
    char odin_kwad_string_pool_str172[sizeof("if")];
    char odin_kwad_string_pool_str173[sizeof("soa")];
    char odin_kwad_string_pool_str174[sizeof("procedure")];
    char odin_kwad_string_pool_str176[sizeof("fastcall")];
    char odin_kwad_string_pool_str177[sizeof("clobber")];
    char odin_kwad_string_pool_str179[sizeof("futex_parameter")];
    char odin_kwad_string_pool_str180[sizeof("force_inline")];
    char odin_kwad_string_pool_str181[sizeof("any_int")];
    char odin_kwad_string_pool_str182[sizeof("matrix")];
    char odin_kwad_string_pool_str183[sizeof("force_no_inline")];
    char odin_kwad_string_pool_str184[sizeof("fallthrough")];
    char odin_kwad_string_pool_str185[sizeof("fini")];
    char odin_kwad_string_pool_str186[sizeof("union")];
    char odin_kwad_string_pool_str188[sizeof("location")];
    char odin_kwad_string_pool_str189[sizeof("dynamic")];
    char odin_kwad_string_pool_str190[sizeof("volatile")];
    char odin_kwad_string_pool_str191[sizeof("enum")];
    char odin_kwad_string_pool_str192[sizeof("foreign")];
    char odin_kwad_string_pool_str193[sizeof("objc_type")];
    char odin_kwad_string_pool_str194[sizeof("no_bounds_check")];
    char odin_kwad_string_pool_str195[sizeof("objc_superclass")];
    char odin_kwad_string_pool_str197[sizeof("objc_selector")];
    char odin_kwad_string_pool_str198[sizeof("instrumentation_exit")];
    char odin_kwad_string_pool_str199[sizeof("entry_point_only")];
    char odin_kwad_string_pool_str200[sizeof("objc_name")];
    char odin_kwad_string_pool_str201[sizeof("bit_field")];
    char odin_kwad_string_pool_str203[sizeof("instrumentation_enter")];
    char odin_kwad_string_pool_str204[sizeof("branch_location")];
    char odin_kwad_string_pool_str205[sizeof("require")];
    char odin_kwad_string_pool_str206[sizeof("rodata")];
    char odin_kwad_string_pool_str208[sizeof("load_hash")];
    char odin_kwad_string_pool_str209[sizeof("require_results")];
    char odin_kwad_string_pool_str211[sizeof("no_sanitize_memory")];
    char odin_kwad_string_pool_str212[sizeof("align")];
    char odin_kwad_string_pool_str215[sizeof("switch")];
    char odin_kwad_string_pool_str218[sizeof("objc_class")];
    char odin_kwad_string_pool_str220[sizeof("require_target_feature")];
    char odin_kwad_string_pool_str223[sizeof("load_directory")];
    char odin_kwad_string_pool_str225[sizeof("tag")];
    char odin_kwad_string_pool_str226[sizeof("transmute")];
    char odin_kwad_string_pool_str230[sizeof("no_init")];
    char odin_kwad_string_pool_str231[sizeof("no_alias")];
    char odin_kwad_string_pool_str233[sizeof("objc_context_provider")];
    char odin_kwad_string_pool_str234[sizeof("init")];
    char odin_kwad_string_pool_str236[sizeof("or_else")];
    char odin_kwad_string_pool_str238[sizeof("fast_math")];
    char odin_kwad_string_pool_str241[sizeof("or_return")];
    char odin_kwad_string_pool_str244[sizeof("no_broadcast")];
    char odin_kwad_string_pool_str247[sizeof("or_continue")];
    char odin_kwad_string_pool_str249[sizeof("or_break")];
    char odin_kwad_string_pool_str250[sizeof("odin")];
    char odin_kwad_string_pool_str258[sizeof("system")];
    char odin_kwad_string_pool_str264[sizeof("optimization_mode")];
    char odin_kwad_string_pool_str267[sizeof("config")];
    char odin_kwad_string_pool_str269[sizeof("c_vararg")];
    char odin_kwad_string_pool_str272[sizeof("min_field_align")];
    char odin_kwad_string_pool_str274[sizeof("priority_index")];
    char odin_kwad_string_pool_str276[sizeof("inlineasm")];
    char odin_kwad_string_pool_str284[sizeof("using")];
    char odin_kwad_string_pool_str286[sizeof("max_field_align")];
    char odin_kwad_string_pool_str293[sizeof("builtin")];
    char odin_kwad_string_pool_str302[sizeof("objc_ivar")];
    char odin_kwad_string_pool_str303[sizeof("objc_implement")];
    char odin_kwad_string_pool_str318[sizeof("align_stack")];
    char odin_kwad_string_pool_str330[sizeof("asm")];
    char odin_kwad_string_pool_str331[sizeof("objc_is_class_method")];
  };
static const struct odin_kwad_string_pool_t odin_kwad_string_pool_contents =
  {
    "test",
    "post",
    "else",
    "type",
    "struct",
    "pre",
    "pure",
    "export",
    "nop",
    "where",
    "none",
    "when",
    "win64",
    "synchronizes",
    "return",
    "preserve",
    "preserve/most",
    "not_in",
    "cast",
    "preserve/none",
    "line",
    "case",
    "sysv",
    "raw_union",
    "const",
    "distinct",
    "panic",
    "naked",
    "preserve/all",
    "link_section",
    "link_name",
    "reverse",
    "byte",
    "synchronizes_shared",
    "cdecl",
    "continue",
    "typeid",
    "bit_set",
    "thread_local",
    "link_suffix",
    "for",
    "subtype",
    "break",
    "context",
    "link_prefix",
    "contextless",
    "stdcall",
    "cold",
    "column_major",
    "disabled",
    "caller_location",
    "futex",
    "caller_expression",
    "file",
    "defer",
    "packed",
    "hash",
    "assert",
    "deprecated",
    "deferred_out",
    "sparse",
    "deferred_in_out",
    "type_assert",
    "deferred_none",
    "deferred_in",
    "deferred_in_by_ptr",
    "deferred_out_by_ptr",
    "unroll",
    "row_major",
    "deferred_in_out_by_ptr",
    "directory",
    "defined",
    "in",
    "enable_target_feature",
    "extra_linker_flags",
    "skip",
    "partial",
    "auto_cast",
    "no_type_assert",
    "all_or_none",
    "exists",
    "import",
    "load",
    "bounds_check",
    "no_instrumentation",
    "no_sanitize_address",
    "private",
    "map",
    "default_calling_convention",
    "shared_nil",
    "simple",
    "do",
    "ignore_duplicates",
    "simd",
    "static",
    "linkage",
    "no_nil",
    "no_sanitize_thread",
    "must_tail",
    "optional_ok",
    "package",
    "by_ptr",
    "proc",
    "optional_allocator_error",
    "raddbg_type_view",
    "if",
    "soa",
    "procedure",
    "fastcall",
    "clobber",
    "futex_parameter",
    "force_inline",
    "any_int",
    "matrix",
    "force_no_inline",
    "fallthrough",
    "fini",
    "union",
    "location",
    "dynamic",
    "volatile",
    "enum",
    "foreign",
    "objc_type",
    "no_bounds_check",
    "objc_superclass",
    "objc_selector",
    "instrumentation_exit",
    "entry_point_only",
    "objc_name",
    "bit_field",
    "instrumentation_enter",
    "branch_location",
    "require",
    "rodata",
    "load_hash",
    "require_results",
    "no_sanitize_memory",
    "align",
    "switch",
    "objc_class",
    "require_target_feature",
    "load_directory",
    "tag",
    "transmute",
    "no_init",
    "no_alias",
    "objc_context_provider",
    "init",
    "or_else",
    "fast_math",
    "or_return",
    "no_broadcast",
    "or_continue",
    "or_break",
    "odin",
    "system",
    "optimization_mode",
    "config",
    "c_vararg",
    "min_field_align",
    "priority_index",
    "inlineasm",
    "using",
    "max_field_align",
    "builtin",
    "objc_ivar",
    "objc_implement",
    "align_stack",
    "asm",
    "objc_is_class_method"
  };
#define odin_kwad_string_pool ((const char *) &odin_kwad_string_pool_contents)

static const unsigned char odin_kwad_lengths[] =
  {
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  4,  0,  0,  0,  0,  4,  0,  0,  4,  4,  6,  0,
     3,  4,  0,  6,  3,  5,  4,  4,  5,  0,  0, 12,  6,  8,
    13,  6,  4,  0, 13,  4,  4,  4,  0,  9,  5,  8,  0,  0,
     0,  5,  5,  0,  0, 12, 12,  9,  7,  4,  0,  0, 19,  5,
     8,  6,  7,  0, 12, 11,  3,  7,  5,  7, 11,  0,  0, 11,
     0,  7,  4, 12,  8,  0, 15,  5, 17,  4,  0,  0,  5,  0,
     0,  6,  4,  6,  0, 10,  0,  0,  0, 12,  0,  6, 15, 11,
    13, 11,  0,  0,  0, 18, 19,  6,  9, 22,  0,  9,  7,  0,
     2,  0, 21, 18,  4,  7,  9, 14, 11,  6,  6,  4, 12, 18,
    19,  7,  0,  3, 26,  0,  0, 10,  6,  0,  2,  0,  0, 17,
     0,  0,  4,  6,  0,  7,  6, 18,  0,  9, 11,  7,  6,  4,
     0, 24,  0, 16,  2,  3,  9,  0,  8,  7,  0, 15, 12,  7,
     6, 15, 11,  4,  5,  0,  8,  7,  8,  4,  7,  9, 15, 15,
     0, 13, 20, 16,  9,  9,  0, 21, 15,  7,  6,  0,  9, 15,
     0, 18,  5,  0,  0,  6,  0,  0, 10,  0, 22,  0,  0, 14,
     0,  3,  9,  0,  0,  0,  7,  8,  0, 21,  4,  0,  7,  0,
     9,  0,  0,  9,  0,  0, 12,  0,  0, 11,  0,  8,  4,  0,
     0,  0,  0,  0,  0,  0,  6,  0,  0,  0,  0,  0, 17,  0,
     0,  6,  0,  8,  0,  0, 15,  0, 14,  0,  9,  0,  0,  0,
     0,  0,  0,  0,  5,  0, 15,  0,  0,  0,  0,  0,  0,  7,
     0,  0,  0,  0,  0,  0,  0,  0,  9, 14,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 11,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  3, 20
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
#line 111 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str16, ODIN_KWAD_TEST, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 156 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str21, ODIN_KWAD_POST, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 37 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str24, ODIN_KWAD_ELSE, OdinTokenKeyword},
#line 171 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str25, ODIN_KWAD_TYPE, OdinTokenDirective},
#line 50 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str26, ODIN_KWAD_STRUCT, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 157 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str28, ODIN_KWAD_PRE, OdinTokenDirective},
#line 160 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str29, ODIN_KWAD_PURE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 71 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str31, ODIN_KWAD_EXPORT, OdinTokenAttribute},
#line 150 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str32, ODIN_KWAD_NOP, OdinTokenDirective,},
#line 56 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str33, ODIN_KWAD_WHERE, OdinTokenKeyword},
#line 180 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str34, ODIN_KWAD_CC_NONE, OdinTokenCallingConvention},
#line 55 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str35, ODIN_KWAD_WHEN, OdinTokenKeyword},
#line 183 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str36, ODIN_KWAD_CC_WIN64, OdinTokenCallingConvention},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 108 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str39, ODIN_KWAD_SYNCHRONIZES, OdinTokenAttribute},
#line 25 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str40, ODIN_KWAD_RETURN, OdinTokenKeyword},
#line 158 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str41, ODIN_KWAD_PRESERVE, OdinTokenDirective},
#line 186 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str42, ODIN_KWAD_CC_PRESERVE_MOST, OdinTokenCallingConvention},
#line 46 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str43, ODIN_KWAD_NOT_IN, OdinTokenKeyword},
#line 32 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str44, ODIN_KWAD_CAST, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 185 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str46, ODIN_KWAD_CC_PRESERVE_NONE, OdinTokenCallingConvention},
#line 136 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str47, ODIN_KWAD_LINE, OdinTokenDirective},
#line 31 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str48, ODIN_KWAD_CASE, OdinTokenKeyword},
#line 184 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str49, ODIN_KWAD_CC_SYSV, OdinTokenCallingConvention},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 161 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str51, ODIN_KWAD_RAW_UNION, OdinTokenDirective},
#line 127 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str52, ODIN_KWAD_CONST, OdinTokenDirective},
#line 34 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str53, ODIN_KWAD_DISTINCT, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 154 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str57, ODIN_KWAD_PANIC, OdinTokenDirective},
#line 181 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str58, ODIN_KWAD_CC_NAKED, OdinTokenCallingConvention},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 187 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str61, ODIN_KWAD_CC_PRESERVE_ALL, OdinTokenCallingConvention},
#line 84 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str62, ODIN_KWAD_LINK_SECTION, OdinTokenAttribute},
#line 82 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str63, ODIN_KWAD_LINK_NAME, OdinTokenAttribute},
#line 162 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str64, ODIN_KWAD_REVERSE, OdinTokenDirective},
#line 121 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str65, ODIN_KWAD_BYTE, OdinTokenDirective,},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 109 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str68, ODIN_KWAD_SYNCHRONIZES_SHARED, OdinTokenAttribute},
#line 177 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str69, ODIN_KWAD_CC_CDECL, OdinTokenCallingConvention},
#line 20 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str70, ODIN_KWAD_CONTINUE, OdinTokenKeyword},
#line 26 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str71, ODIN_KWAD_TYPEID, OdinTokenKeyword},
#line 30 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str72, ODIN_KWAD_BIT_SET, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 112 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str74, ODIN_KWAD_THREAD_LOCAL, OdinTokenAttribute},
#line 85 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str75, ODIN_KWAD_LINK_SUFFIX, OdinTokenAttribute},
#line 39 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str76, ODIN_KWAD_FOR, OdinTokenKeyword},
#line 170 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str77, ODIN_KWAD_SUBTYPE, OdinTokenDirective},
#line 18 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str78, ODIN_KWAD_BREAK, OdinTokenKeyword},
#line 19 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str79, ODIN_KWAD_CONTEXT, OdinTokenKeyword},
#line 83 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str80, ODIN_KWAD_LINK_PREFIX, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 176 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str83, ODIN_KWAD_CC_CONTEXTLESS, OdinTokenCallingConvention},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 178 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str85, ODIN_KWAD_CC_STDCALL, OdinTokenCallingConvention},
#line 58 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str86, ODIN_KWAD_COLD, OdinTokenAttribute},
#line 125 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str87, ODIN_KWAD_COLUMN_MAJOR, OdinTokenDirective},
#line 68 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str88, ODIN_KWAD_DISABLED, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 123 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str90, ODIN_KWAD_CALLER_LOCATION, OdinTokenDirective},
#line 75 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str91, ODIN_KWAD_FUTEX, OdinTokenAttribute},
#line 122 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str92, ODIN_KWAD_CALLER_EXPRESSION, OdinTokenDirective},
#line 132 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str93, ODIN_KWAD_FILE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 33 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str96, ODIN_KWAD_DEFER, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 153 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str99, ODIN_KWAD_PACKED, OdinTokenDirective},
#line 135 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str100, ODIN_KWAD_HASH, OdinTokenDirective},
#line 117 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str101, ODIN_KWAD_ASSERT, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 67 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str103, ODIN_KWAD_DEPRECATED, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 65 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str107, ODIN_KWAD_DEFERRED_OUT, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 169 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str109, ODIN_KWAD_SPARSE, OdinTokenDirective},
#line 62 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str110, ODIN_KWAD_DEFERRED_IN_OUT, OdinTokenAttribute},
#line 172 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str111, ODIN_KWAD_TYPE_ASSERT, OdinTokenDirective},
#line 64 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str112, ODIN_KWAD_DEFERRED_NONE, OdinTokenAttribute},
#line 60 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str113, ODIN_KWAD_DEFERRED_IN, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 61 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str117, ODIN_KWAD_DEFERRED_IN_BY_PTR, OdinTokenAttribute},
#line 66 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str118, ODIN_KWAD_DEFERRED_OUT_BY_PTR, OdinTokenAttribute},
#line 173 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str119, ODIN_KWAD_UNROLL, OdinTokenDirective},
#line 163 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str120, ODIN_KWAD_ROW_MAJOR, OdinTokenDirective},
#line 63 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str121, ODIN_KWAD_DEFERRED_IN_OUT_BY_PTR, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 130 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str123, ODIN_KWAD_DIRECTORY, OdinTokenDirective},
#line 129 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str124, ODIN_KWAD_DEFINED, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 43 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str126, ODIN_KWAD_IN, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 69 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str128, ODIN_KWAD_ENABLE_TARGET_FEATURE, OdinTokenAttribute},
#line 72 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str129, ODIN_KWAD_EXTRA_LINKER_FLAGS, OdinTokenAttribute},
#line 167 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str130, ODIN_KWAD_SKIP, OdinTokenDirective,},
#line 155 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str131, ODIN_KWAD_PARTIAL, OdinTokenDirective},
#line 28 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str132, ODIN_KWAD_AUTO_CAST, OdinTokenKeyword},
#line 149 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str133, ODIN_KWAD_NO_TYPE_ASSERT, OdinTokenDirective},
#line 115 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str134, ODIN_KWAD_ALL_OR_NONE, OdinTokenDirective},
#line 131 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str135, ODIN_KWAD_EXISTS, OdinTokenDirective},
#line 42 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str136, ODIN_KWAD_IMPORT, OdinTokenKeyword},
#line 137 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str137, ODIN_KWAD_LOAD, OdinTokenDirective},
#line 118 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str138, ODIN_KWAD_BOUNDS_CHECK, OdinTokenDirective},
#line 86 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str139, ODIN_KWAD_NO_INSTRUMENTATION, OdinTokenAttribute},
#line 87 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str140, ODIN_KWAD_NO_SANITIZE_ADDRESS, OdinTokenAttribute},
#line 101 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str141, ODIN_KWAD_PRIVATE, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 44 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str143, ODIN_KWAD_MAP, OdinTokenKeyword},
#line 59 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str144, ODIN_KWAD_DEFAULT_CALLING_CONVENTION, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 164 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str147, ODIN_KWAD_SHARED_NIL, OdinTokenDirective},
#line 166 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str148, ODIN_KWAD_SIMPLE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 35 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str150, ODIN_KWAD_DO, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 77 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str153, ODIN_KWAD_IGNORE_DUPLICATES, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 165 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str156, ODIN_KWAD_SIMD, OdinTokenDirective},
#line 107 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str157, ODIN_KWAD_STATIC, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 81 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str159, ODIN_KWAD_LINKAGE, OdinTokenAttribute},
#line 148 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str160, ODIN_KWAD_NO_NIL, OdinTokenDirective},
#line 89 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str161, ODIN_KWAD_NO_SANITIZE_THREAD, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 143 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str163, ODIN_KWAD_MUST_TAIL, OdinTokenDirective},
#line 152 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str164, ODIN_KWAD_OPTIONAL_OK, OdinTokenDirective},
#line 48 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str165, ODIN_KWAD_PACKAGE, OdinTokenKeyword},
#line 120 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str166, ODIN_KWAD_BY_PTR, OdinTokenDirective},
#line 49 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str167, ODIN_KWAD_PROC, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 151 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str169, ODIN_KWAD_OPTIONAL_ALLOCATOR_ERROR, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 102 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str171, ODIN_KWAD_RADDBG_TYPE_VIEW, OdinTokenAttribute},
#line 41 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str172, ODIN_KWAD_IF, OdinTokenKeyword},
#line 168 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str173, ODIN_KWAD_SOA, OdinTokenDirective},
#line 159 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str174, ODIN_KWAD_PROCEDURE, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 179 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str176, ODIN_KWAD_CC_FASTCALL, OdinTokenCallingConvention},
#line 124 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str177, ODIN_KWAD_CLOBBER, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 76 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str179, ODIN_KWAD_FUTEX_PARAMETER, OdinTokenAttribute},
#line 133 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str180, ODIN_KWAD_FORCE_INLINE, OdinTokenDirective},
#line 116 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str181, ODIN_KWAD_ANY_INT, OdinTokenDirective},
#line 45 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str182, ODIN_KWAD_MATRIX, OdinTokenKeyword},
#line 134 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str183, ODIN_KWAD_FORCE_NO_INLINE, OdinTokenDirective},
#line 21 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str184, ODIN_KWAD_FALLTHROUGH, OdinTokenKeyword},
#line 74 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str185, ODIN_KWAD_FINI, OdinTokenAttribute},
#line 53 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str186, ODIN_KWAD_UNION, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 140 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str188, ODIN_KWAD_LOCATION, OdinTokenDirective},
#line 36 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str189, ODIN_KWAD_DYNAMIC, OdinTokenKeyword},
#line 174 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str190, ODIN_KWAD_VOLATILE, OdinTokenDirective},
#line 38 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str191, ODIN_KWAD_ENUM, OdinTokenKeyword},
#line 40 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str192, ODIN_KWAD_FOREIGN, OdinTokenKeyword},
#line 98 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str193, ODIN_KWAD_OBJC_TYPE, OdinTokenAttribute},
#line 145 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str194, ODIN_KWAD_NO_BOUNDS_CHECK, OdinTokenDirective},
#line 97 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str195, ODIN_KWAD_OBJC_SUPERCLASS, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 96 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str197, ODIN_KWAD_OBJC_SELECTOR, OdinTokenAttribute},
#line 80 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str198, ODIN_KWAD_INSTRUMENTATION_EXIT, OdinTokenAttribute},
#line 70 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str199, ODIN_KWAD_ENTRY_POINT_ONLY, OdinTokenAttribute},
#line 95 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str200, ODIN_KWAD_OBJC_NAME, OdinTokenAttribute},
#line 29 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str201, ODIN_KWAD_BIT_FIELD, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 79 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str203, ODIN_KWAD_INSTRUMENTATION_ENTER, OdinTokenAttribute},
#line 119 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str204, ODIN_KWAD_BRANCH_LOCATION, OdinTokenDirective},
#line 103 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str205, ODIN_KWAD_REQUIRE, OdinTokenAttribute},
#line 106 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str206, ODIN_KWAD_RODATA, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 139 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str208, ODIN_KWAD_LOAD_HASH, OdinTokenDirective},
#line 104 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str209, ODIN_KWAD_REQUIRE_RESULTS, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 88 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str211, ODIN_KWAD_NO_SANITIZE_MEMORY, OdinTokenAttribute},
#line 113 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str212, ODIN_KWAD_ALIGN, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 51 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str215, ODIN_KWAD_SWITCH, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 90 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str218, ODIN_KWAD_OBJC_CLASS, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 105 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str220, ODIN_KWAD_REQUIRE_TARGET_FEATURE, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 138 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str223, ODIN_KWAD_LOAD_DIRECTORY, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 110 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str225, ODIN_KWAD_TAG, OdinTokenAttribute},
#line 52 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str226, ODIN_KWAD_TRANSMUTE, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 147 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str230, ODIN_KWAD_NO_INIT, OdinTokenDirective},
#line 144 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str231, ODIN_KWAD_NO_ALIAS, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 91 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str233, ODIN_KWAD_OBJC_CONTEXT_PROVIDER, OdinTokenAttribute},
#line 78 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str234, ODIN_KWAD_INIT, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 47 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str236, ODIN_KWAD_OR_ELSE, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 73 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str238, ODIN_KWAD_FAST_MATH, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 24 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str241, ODIN_KWAD_OR_RETURN, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 146 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str244, ODIN_KWAD_NO_BROADCAST, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 23 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str247, ODIN_KWAD_OR_CONTINUE, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 22 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str249, ODIN_KWAD_OR_BREAK, OdinTokenKeyword},
#line 175 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str250, ODIN_KWAD_CC_ODIN, OdinTokenCallingConvention},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 188 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str258, ODIN_KWAD_CC_SYSTEM, OdinTokenCallingConvention},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 99 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str264, ODIN_KWAD_OPTIMIZATION_MODE, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 126 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str267, ODIN_KWAD_CONFIG, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 128 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str269, ODIN_KWAD_C_VARARG, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 142 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str272, ODIN_KWAD_MIN_FIELD_ALIGN, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 100 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str274, ODIN_KWAD_PRIORITY_INDEX, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 182 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str276, ODIN_KWAD_CC_INLINEASM, OdinTokenCallingConvention},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 54 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str284, ODIN_KWAD_USING, OdinTokenKeyword},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 141 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str286, ODIN_KWAD_MAX_FIELD_ALIGN, OdinTokenDirective},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 57 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str293, ODIN_KWAD_BUILTIN, OdinTokenAttribute},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
    {-1,ODIN_INVALID,OdinTokenInvalid},
#line 94 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str302, ODIN_KWAD_OBJC_IVAR, OdinTokenAttribute},
#line 92 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str303, ODIN_KWAD_OBJC_IMPLEMENT, OdinTokenAttribute},
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
#line 114 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str318, ODIN_KWAD_ALIGN_STACK, OdinTokenDirective},
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
#line 27 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str330, ODIN_KWAD_ASM, OdinTokenKeyword},
#line 93 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str331, ODIN_KWAD_OBJC_IS_CLASS_METHOD, OdinTokenAttribute}
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
