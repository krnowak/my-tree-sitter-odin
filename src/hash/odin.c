/* ANSI-C code produced by gperf version 3.3 */
/* Command-line: gperf --multiple-iterations=100 src/hash/word-list  */
/* Computed positions: -k'1-2,$' */

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

#define ODIN_KWAD_TOTAL_KEYWORDS 102
#define ODIN_KWAD_MIN_WORD_LENGTH 2
#define ODIN_KWAD_MAX_WORD_LENGTH 24
#define ODIN_KWAD_MIN_HASH_VALUE 3
#define ODIN_KWAD_MAX_HASH_VALUE 213
/* maximum key range = 211, duplicates = 0 */

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
      214, 214, 214, 214, 214, 214, 214, 214, 214, 214,
      214, 214, 214, 214, 214, 214, 214, 214, 214, 214,
      214, 214, 214, 214, 214, 214, 214, 214, 214, 214,
      214, 214, 214, 214, 214, 214, 214, 214, 214, 214,
      214, 214, 214, 214, 214, 214, 214, 214, 214, 214,
      214, 214, 214, 214, 214, 214, 214, 214, 214, 214,
      214, 214, 214, 214, 214, 214, 214, 214, 214, 214,
      214, 214, 214, 214, 214, 214, 214, 214, 214, 214,
      214, 214, 214, 214, 214, 214, 214, 214, 214, 214,
      214, 214, 214, 214, 214,   3, 214,  38,  69,  13,
       29,   7,  71,   0,  36,   1, 214,  60,  32,  90,
        0,  19,   0, 214,   2,  51,   3,  82,   3,  31,
       10,  53, 214, 214, 214, 214, 214, 214
    };
  return len + asso_values[(unsigned char)str[1]] + asso_values[(unsigned char)str[0]] + asso_values[(unsigned char)str[len - 1]];
}

struct odin_kwad_string_pool_t
  {
    char odin_kwad_string_pool_str3[sizeof("in")];
    char odin_kwad_string_pool_str12[sizeof("pre")];
    char odin_kwad_string_pool_str15[sizeof("return")];
    char odin_kwad_string_pool_str17[sizeof("preserve")];
    char odin_kwad_string_pool_str18[sizeof("procedure")];
    char odin_kwad_string_pool_str19[sizeof("proc")];
    char odin_kwad_string_pool_str21[sizeof("transmute")];
    char odin_kwad_string_pool_str22[sizeof("nop")];
    char odin_kwad_string_pool_str23[sizeof("reverse")];
    char odin_kwad_string_pool_str24[sizeof("c_vararg")];
    char odin_kwad_string_pool_str25[sizeof("not_in")];
    char odin_kwad_string_pool_str26[sizeof("post")];
    char odin_kwad_string_pool_str29[sizeof("no_init")];
    char odin_kwad_string_pool_str30[sizeof("or_return")];
    char odin_kwad_string_pool_str32[sizeof("row_major")];
    char odin_kwad_string_pool_str34[sizeof("no_broadcast")];
    char odin_kwad_string_pool_str35[sizeof("or_else")];
    char odin_kwad_string_pool_str36[sizeof("no_type_assert")];
    char odin_kwad_string_pool_str37[sizeof("volatile")];
    char odin_kwad_string_pool_str38[sizeof("config")];
    char odin_kwad_string_pool_str39[sizeof("or_continue")];
    char odin_kwad_string_pool_str40[sizeof("const")];
    char odin_kwad_string_pool_str41[sizeof("distinct")];
    char odin_kwad_string_pool_str42[sizeof("context")];
    char odin_kwad_string_pool_str43[sizeof("defer")];
    char odin_kwad_string_pool_str44[sizeof("line")];
    char odin_kwad_string_pool_str45[sizeof("optional_allocator_error")];
    char odin_kwad_string_pool_str46[sizeof("column_major")];
    char odin_kwad_string_pool_str47[sizeof("continue")];
    char odin_kwad_string_pool_str48[sizeof("any_int")];
    char odin_kwad_string_pool_str49[sizeof("raw_union")];
    char odin_kwad_string_pool_str50[sizeof("else")];
    char odin_kwad_string_pool_str52[sizeof("package")];
    char odin_kwad_string_pool_str54[sizeof("clobber")];
    char odin_kwad_string_pool_str56[sizeof("panic")];
    char odin_kwad_string_pool_str57[sizeof("no_nil")];
    char odin_kwad_string_pool_str58[sizeof("cast")];
    char odin_kwad_string_pool_str59[sizeof("location")];
    char odin_kwad_string_pool_str62[sizeof("case")];
    char odin_kwad_string_pool_str63[sizeof("struct")];
    char odin_kwad_string_pool_str64[sizeof("sparse")];
    char odin_kwad_string_pool_str65[sizeof("simple")];
    char odin_kwad_string_pool_str66[sizeof("caller_location")];
    char odin_kwad_string_pool_str67[sizeof("type")];
    char odin_kwad_string_pool_str68[sizeof("caller_expression")];
    char odin_kwad_string_pool_str69[sizeof("do")];
    char odin_kwad_string_pool_str70[sizeof("type_assert")];
    char odin_kwad_string_pool_str71[sizeof("when")];
    char odin_kwad_string_pool_str72[sizeof("defined")];
    char odin_kwad_string_pool_str73[sizeof("packed")];
    char odin_kwad_string_pool_str74[sizeof("exists")];
    char odin_kwad_string_pool_str75[sizeof("align")];
    char odin_kwad_string_pool_str77[sizeof("partial")];
    char odin_kwad_string_pool_str78[sizeof("no_alias")];
    char odin_kwad_string_pool_str79[sizeof("where")];
    char odin_kwad_string_pool_str80[sizeof("bit_set")];
    char odin_kwad_string_pool_str82[sizeof("soa_split")];
    char odin_kwad_string_pool_str83[sizeof("file")];
    char odin_kwad_string_pool_str84[sizeof("load")];
    char odin_kwad_string_pool_str85[sizeof("simd")];
    char odin_kwad_string_pool_str86[sizeof("branch_location")];
    char odin_kwad_string_pool_str87[sizeof("union")];
    char odin_kwad_string_pool_str88[sizeof("all_or_none")];
    char odin_kwad_string_pool_str89[sizeof("or_break")];
    char odin_kwad_string_pool_str90[sizeof("optional_ok")];
    char odin_kwad_string_pool_str91[sizeof("typeid")];
    char odin_kwad_string_pool_str92[sizeof("directory")];
    char odin_kwad_string_pool_str93[sizeof("pure")];
    char odin_kwad_string_pool_str94[sizeof("no_bounds_check")];
    char odin_kwad_string_pool_str95[sizeof("for")];
    char odin_kwad_string_pool_str96[sizeof("load_hash")];
    char odin_kwad_string_pool_str97[sizeof("foreign")];
    char odin_kwad_string_pool_str98[sizeof("assert")];
    char odin_kwad_string_pool_str100[sizeof("import")];
    char odin_kwad_string_pool_str101[sizeof("enum")];
    char odin_kwad_string_pool_str102[sizeof("dynamic")];
    char odin_kwad_string_pool_str106[sizeof("min_field_align")];
    char odin_kwad_string_pool_str108[sizeof("bit_field")];
    char odin_kwad_string_pool_str109[sizeof("force_inline")];
    char odin_kwad_string_pool_str111[sizeof("soa")];
    char odin_kwad_string_pool_str112[sizeof("force_no_inline")];
    char odin_kwad_string_pool_str114[sizeof("hash")];
    char odin_kwad_string_pool_str115[sizeof("skip")];
    char odin_kwad_string_pool_str118[sizeof("load_directory")];
    char odin_kwad_string_pool_str120[sizeof("unroll")];
    char odin_kwad_string_pool_str124[sizeof("switch")];
    char odin_kwad_string_pool_str129[sizeof("shared_nil")];
    char odin_kwad_string_pool_str130[sizeof("by_ptr")];
    char odin_kwad_string_pool_str131[sizeof("map")];
    char odin_kwad_string_pool_str132[sizeof("auto_cast")];
    char odin_kwad_string_pool_str133[sizeof("byte")];
    char odin_kwad_string_pool_str136[sizeof("break")];
    char odin_kwad_string_pool_str138[sizeof("using")];
    char odin_kwad_string_pool_str141[sizeof("align_stack")];
    char odin_kwad_string_pool_str143[sizeof("max_field_align")];
    char odin_kwad_string_pool_str144[sizeof("matrix")];
    char odin_kwad_string_pool_str145[sizeof("if")];
    char odin_kwad_string_pool_str147[sizeof("subtype")];
    char odin_kwad_string_pool_str156[sizeof("fallthrough")];
    char odin_kwad_string_pool_str160[sizeof("bounds_check")];
    char odin_kwad_string_pool_str182[sizeof("asm")];
    char odin_kwad_string_pool_str213[sizeof("must_tail")];
  };
static const struct odin_kwad_string_pool_t odin_kwad_string_pool_contents =
  {
    "in",
    "pre",
    "return",
    "preserve",
    "procedure",
    "proc",
    "transmute",
    "nop",
    "reverse",
    "c_vararg",
    "not_in",
    "post",
    "no_init",
    "or_return",
    "row_major",
    "no_broadcast",
    "or_else",
    "no_type_assert",
    "volatile",
    "config",
    "or_continue",
    "const",
    "distinct",
    "context",
    "defer",
    "line",
    "optional_allocator_error",
    "column_major",
    "continue",
    "any_int",
    "raw_union",
    "else",
    "package",
    "clobber",
    "panic",
    "no_nil",
    "cast",
    "location",
    "case",
    "struct",
    "sparse",
    "simple",
    "caller_location",
    "type",
    "caller_expression",
    "do",
    "type_assert",
    "when",
    "defined",
    "packed",
    "exists",
    "align",
    "partial",
    "no_alias",
    "where",
    "bit_set",
    "soa_split",
    "file",
    "load",
    "simd",
    "branch_location",
    "union",
    "all_or_none",
    "or_break",
    "optional_ok",
    "typeid",
    "directory",
    "pure",
    "no_bounds_check",
    "for",
    "load_hash",
    "foreign",
    "assert",
    "import",
    "enum",
    "dynamic",
    "min_field_align",
    "bit_field",
    "force_inline",
    "soa",
    "force_no_inline",
    "hash",
    "skip",
    "load_directory",
    "unroll",
    "switch",
    "shared_nil",
    "by_ptr",
    "map",
    "auto_cast",
    "byte",
    "break",
    "using",
    "align_stack",
    "max_field_align",
    "matrix",
    "if",
    "subtype",
    "fallthrough",
    "bounds_check",
    "asm",
    "must_tail"
  };
#define odin_kwad_string_pool ((const char *) &odin_kwad_string_pool_contents)

static const unsigned char odin_kwad_lengths[] =
  {
     0,  0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0,
     0,  6,  0,  8,  9,  4,  0,  9,  3,  7,  8,  6,  4,  0,
     0,  7,  9,  0,  9,  0, 12,  7, 14,  8,  6, 11,  5,  8,
     7,  5,  4, 24, 12,  8,  7,  9,  4,  0,  7,  0,  7,  0,
     5,  6,  4,  8,  0,  0,  4,  6,  6,  6, 15,  4, 17,  2,
    11,  4,  7,  6,  6,  5,  0,  7,  8,  5,  7,  0,  9,  4,
     4,  4, 15,  5, 11,  8, 11,  6,  9,  4, 15,  3,  9,  7,
     6,  0,  6,  4,  7,  0,  0,  0, 15,  0,  9, 12,  0,  3,
    15,  0,  4,  4,  0,  0, 14,  0,  6,  0,  0,  0,  6,  0,
     0,  0,  0, 10,  6,  3,  9,  4,  0,  0,  5,  0,  5,  0,
     0, 11,  0, 15,  6,  2,  0,  7,  0,  0,  0,  0,  0,  0,
     0,  0, 11,  0,  0,  0, 12,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  9
  };

static const struct OdinKwad odin_kwads[] =
  {
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0},
#line 46 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str3, ODIN_KWAD_IN, 1},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 106 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str12, ODIN_KWAD_PRE, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 28 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str15, ODIN_KWAD_RETURN, 1},
    {-1,ODIN_INVALID,0},
#line 107 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str17, ODIN_KWAD_PRESERVE, 0},
#line 108 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str18, ODIN_KWAD_PROCEDURE, 0},
#line 52 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str19, ODIN_KWAD_PROC, 1},
    {-1,ODIN_INVALID,0},
#line 55 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str21, ODIN_KWAD_TRANSMUTE, 1},
#line 99 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str22, ODIN_KWAD_NOP, 0,},
#line 111 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str23, ODIN_KWAD_REVERSE, 0},
#line 77 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str24, ODIN_KWAD_C_VARARG, 0},
#line 49 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str25, ODIN_KWAD_NOT_IN, 1},
#line 105 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str26, ODIN_KWAD_POST, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 96 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str29, ODIN_KWAD_NO_INIT, 0},
#line 27 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str30, ODIN_KWAD_OR_RETURN, 1},
    {-1,ODIN_INVALID,0},
#line 112 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str32, ODIN_KWAD_ROW_MAJOR, 0},
    {-1,ODIN_INVALID,0},
#line 95 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str34, ODIN_KWAD_NO_BROADCAST, 0},
#line 50 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str35, ODIN_KWAD_OR_ELSE, 1},
#line 98 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str36, ODIN_KWAD_NO_TYPE_ASSERT, 0},
#line 124 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str37, ODIN_KWAD_VOLATILE, 0},
#line 75 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str38, ODIN_KWAD_CONFIG, 0},
#line 26 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str39, ODIN_KWAD_OR_CONTINUE, 1},
#line 76 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str40, ODIN_KWAD_CONST, 0},
#line 37 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str41, ODIN_KWAD_DISTINCT, 1},
#line 22 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str42, ODIN_KWAD_CONTEXT, 1},
#line 36 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str43, ODIN_KWAD_DEFER, 1},
#line 85 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str44, ODIN_KWAD_LINE, 0},
#line 100 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str45, ODIN_KWAD_OPTIONAL_ALLOCATOR_ERROR, 0},
#line 74 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str46, ODIN_KWAD_COLUMN_MAJOR, 0},
#line 23 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str47, ODIN_KWAD_CONTINUE, 1},
#line 65 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str48, ODIN_KWAD_ANY_INT, 0},
#line 110 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str49, ODIN_KWAD_RAW_UNION, 0},
#line 40 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str50, ODIN_KWAD_ELSE, 1},
    {-1,ODIN_INVALID,0},
#line 51 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str52, ODIN_KWAD_PACKAGE, 1},
    {-1,ODIN_INVALID,0},
#line 73 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str54, ODIN_KWAD_CLOBBER, 0},
    {-1,ODIN_INVALID,0},
#line 103 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str56, ODIN_KWAD_PANIC, 0},
#line 97 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str57, ODIN_KWAD_NO_NIL, 0},
#line 35 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str58, ODIN_KWAD_CAST, 1},
#line 89 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str59, ODIN_KWAD_LOCATION, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 34 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str62, ODIN_KWAD_CASE, 1},
#line 53 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str63, ODIN_KWAD_STRUCT, 1},
#line 119 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str64, ODIN_KWAD_SPARSE, 0},
#line 115 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str65, ODIN_KWAD_SIMPLE, 0},
#line 72 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str66, ODIN_KWAD_CALLER_LOCATION, 0},
#line 121 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str67, ODIN_KWAD_TYPE, 0},
#line 71 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str68, ODIN_KWAD_CALLER_EXPRESSION, 0},
#line 38 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str69, ODIN_KWAD_DO, 1},
#line 122 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str70, ODIN_KWAD_TYPE_ASSERT, 0},
#line 58 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str71, ODIN_KWAD_WHEN, 1},
#line 78 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str72, ODIN_KWAD_DEFINED, 0},
#line 102 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str73, ODIN_KWAD_PACKED, 0},
#line 80 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str74, ODIN_KWAD_EXISTS, 0},
#line 128 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str75, ODIN_KWAD_ALIGN, 0},
    {-1,ODIN_INVALID,0},
#line 104 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str77, ODIN_KWAD_PARTIAL, 0},
#line 93 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str78, ODIN_KWAD_NO_ALIAS, 0},
#line 59 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str79, ODIN_KWAD_WHERE, 1},
#line 33 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str80, ODIN_KWAD_BIT_SET, 1},
    {-1,ODIN_INVALID,0},
#line 118 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str82, ODIN_KWAD_SOA, 0},
#line 81 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str83, ODIN_KWAD_FILE, 0},
#line 86 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str84, ODIN_KWAD_LOAD, 0},
#line 114 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str85, ODIN_KWAD_SIMD, 0},
#line 68 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str86, ODIN_KWAD_BRANCH_LOCATION, 0},
#line 56 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str87, ODIN_KWAD_UNION, 1},
#line 64 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str88, ODIN_KWAD_ALL_OR_NONE, 0},
#line 25 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str89, ODIN_KWAD_OR_BREAK, 1},
#line 101 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str90, ODIN_KWAD_OPTIONAL_OK, 0},
#line 29 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str91, ODIN_KWAD_TYPEID, 1},
#line 79 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str92, ODIN_KWAD_DIRECTORY, 0},
#line 109 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str93, ODIN_KWAD_PURE, 0},
#line 94 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str94, ODIN_KWAD_NO_BOUNDS_CHECK, 0},
#line 42 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str95, ODIN_KWAD_FOR, 1},
#line 88 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str96, ODIN_KWAD_LOAD_HASH, 0},
#line 43 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str97, ODIN_KWAD_FOREIGN, 1},
#line 66 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str98, ODIN_KWAD_ASSERT, 0},
    {-1,ODIN_INVALID,0},
#line 45 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str100, ODIN_KWAD_IMPORT, 1},
#line 41 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str101, ODIN_KWAD_ENUM, 1},
#line 39 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str102, ODIN_KWAD_DYNAMIC, 1},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0},
#line 91 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str106, ODIN_KWAD_MIN_FIELD_ALIGN, 0},
    {-1,ODIN_INVALID,0},
#line 32 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str108, ODIN_KWAD_BIT_FIELD, 1},
#line 82 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str109, ODIN_KWAD_FORCE_INLINE, 0},
    {-1,ODIN_INVALID,0},
#line 117 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str111, ODIN_KWAD_SOA, 0},
#line 83 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str112, ODIN_KWAD_FORCE_NO_INLINE, 0},
    {-1,ODIN_INVALID,0},
#line 84 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str114, ODIN_KWAD_HASH, 0},
#line 116 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str115, ODIN_KWAD_SKIP, 0,},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 87 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str118, ODIN_KWAD_LOAD_DIRECTORY, 0},
    {-1,ODIN_INVALID,0},
#line 123 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str120, ODIN_KWAD_UNROLL, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0},
#line 54 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str124, ODIN_KWAD_SWITCH, 1},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 113 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str129, ODIN_KWAD_SHARED_NIL, 0},
#line 69 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str130, ODIN_KWAD_BY_PTR, 0},
#line 47 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str131, ODIN_KWAD_MAP, 1},
#line 31 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str132, ODIN_KWAD_AUTO_CAST, 1},
#line 70 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str133, ODIN_KWAD_BYTE, 0,},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 21 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str136, ODIN_KWAD_BREAK, 1},
    {-1,ODIN_INVALID,0},
#line 57 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str138, ODIN_KWAD_USING, 1},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 63 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str141, ODIN_KWAD_ALIGN_STACK, 0},
    {-1,ODIN_INVALID,0},
#line 90 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str143, ODIN_KWAD_MAX_FIELD_ALIGN, 0},
#line 48 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str144, ODIN_KWAD_MATRIX, 1},
#line 44 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str145, ODIN_KWAD_IF, 1},
    {-1,ODIN_INVALID,0},
#line 120 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str147, ODIN_KWAD_SUBTYPE, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 24 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str156, ODIN_KWAD_FALLTHROUGH, 1},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0},
#line 67 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str160, ODIN_KWAD_BOUNDS_CHECK, 0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0},
#line 30 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str182, ODIN_KWAD_ASM, 1},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
    {-1,ODIN_INVALID,0}, {-1,ODIN_INVALID,0},
#line 92 "src/hash/word-list"
    {(int)(size_t)&((struct odin_kwad_string_pool_t *)0)->odin_kwad_string_pool_str213, ODIN_KWAD_MUST_TAIL, 0}
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
