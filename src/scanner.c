#include "tree_sitter/alloc.h"
#include "tree_sitter/parser.h"

#include <ctype.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <wctype.h>

// TODO: keep it and document it or drop it
#ifdef _MSC_VER
#pragma warning(disable : 4100)
#elif defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

//
// krnowak: stuff stolen from gb.h in odin project
//

#ifndef GB_STATIC_ASSERT
	#define GB_STATIC_ASSERT3(cond, msg) typedef char static_assertion_##msg[(!!(cond))*2-1]
	// NOTE(bill): Token pasting madness!!
	#define GB_STATIC_ASSERT2(cond, line) GB_STATIC_ASSERT3(cond, static_assertion_at_line_##line)
	#define GB_STATIC_ASSERT1(cond, line) GB_STATIC_ASSERT2(cond, line)
	#define GB_STATIC_ASSERT(cond)        GB_STATIC_ASSERT1(cond, __LINE__)
#endif

//
// krnowak: tokens
//

typedef enum {
  OdinTokenInvalid,
  OdinTokenKeyword,
  OdinTokenAttribute,
  OdinTokenDirective,
} OdinTokenType;

#define ODIN_SPECIAL_SYMBOLS \
  ODIN_SYMBOL(INVALID), \
  ODIN_SYMBOL(ML_COMMENT), \
  ODIN_SYMBOL(SL_COMMENT), \
  ODIN_SYMBOL(IMPLICIT_SEMICOLON), \
  ODIN_SYMBOL(WIDE_IMPLICIT_SEMICOLON), \
  ODIN_SYMBOL(IDENTIFIER)

// keywords that may add a semicolon
#define ODIN_SEMICOLON_KW_SYMBOLS \
  ODIN_SYMBOL(KWAD_BREAK), \
  ODIN_SYMBOL(KWAD_CONTEXT), \
  ODIN_SYMBOL(KWAD_CONTINUE), \
  ODIN_SYMBOL(KWAD_FALLTHROUGH), \
  ODIN_SYMBOL(KWAD_OR_BREAK), \
  ODIN_SYMBOL(KWAD_OR_CONTINUE), \
  ODIN_SYMBOL(KWAD_OR_RETURN), \
  ODIN_SYMBOL(KWAD_RETURN), \
  ODIN_SYMBOL(KWAD_TYPEID)

// keywords that do not add a semicolon
#define ODIN_NO_SEMICOLON_KW_SYMBOLS \
  ODIN_SYMBOL(KWAD_ASM), \
  ODIN_SYMBOL(KWAD_AUTO_CAST), \
  ODIN_SYMBOL(KWAD_BIT_FIELD), \
  ODIN_SYMBOL(KWAD_BIT_SET), \
  ODIN_SYMBOL(KWAD_CASE), \
  ODIN_SYMBOL(KWAD_CAST), \
  ODIN_SYMBOL(KWAD_DEFER), \
  ODIN_SYMBOL(KWAD_DISTINCT), \
  ODIN_SYMBOL(KWAD_DO), \
  ODIN_SYMBOL(KWAD_DYNAMIC), \
  ODIN_SYMBOL(KWAD_ELSE), \
  ODIN_SYMBOL(KWAD_ENUM), \
  ODIN_SYMBOL(KWAD_FOR), \
  ODIN_SYMBOL(KWAD_FOREIGN), \
  ODIN_SYMBOL(KWAD_IF), \
  ODIN_SYMBOL(KWAD_IMPORT), \
  ODIN_SYMBOL(KWAD_IN), \
  ODIN_SYMBOL(KWAD_MAP), \
  ODIN_SYMBOL(KWAD_MATRIX), \
  ODIN_SYMBOL(KWAD_NOT_IN), \
  ODIN_SYMBOL(KWAD_OR_ELSE), \
  ODIN_SYMBOL(KWAD_PACKAGE), \
  ODIN_SYMBOL(KWAD_PROC), \
  ODIN_SYMBOL(KWAD_STRUCT), \
  ODIN_SYMBOL(KWAD_SWITCH), \
  ODIN_SYMBOL(KWAD_TRANSMUTE), \
  ODIN_SYMBOL(KWAD_UNION), \
  ODIN_SYMBOL(KWAD_USING), \
  ODIN_SYMBOL(KWAD_WHEN), \
  ODIN_SYMBOL(KWAD_WHERE)

// attributes
#define ODIN_ATTRIBUTE_SYMBOLS \
  ODIN_SYMBOL(KWAD_BUILTIN), \
  ODIN_SYMBOL(KWAD_COLD), \
  ODIN_SYMBOL(KWAD_DEFAULT_CALLING_CONVENTION), \
  ODIN_SYMBOL(KWAD_DEFERRED_IN), \
  ODIN_SYMBOL(KWAD_DEFERRED_IN_BY_PTR), \
  ODIN_SYMBOL(KWAD_DEFERRED_IN_OUT), \
  ODIN_SYMBOL(KWAD_DEFERRED_IN_OUT_BY_PTR), \
  ODIN_SYMBOL(KWAD_DEFERRED_NONE), \
  ODIN_SYMBOL(KWAD_DEFERRED_OUT), \
  ODIN_SYMBOL(KWAD_DEFERRED_OUT_BY_PTR), \
  ODIN_SYMBOL(KWAD_DEPRECATED), \
  ODIN_SYMBOL(KWAD_DISABLED), \
  ODIN_SYMBOL(KWAD_ENABLE_TARGET_FEATURE), \
  ODIN_SYMBOL(KWAD_ENTRY_POINT_ONLY), \
  ODIN_SYMBOL(KWAD_EXPORT), \
  ODIN_SYMBOL(KWAD_EXTRA_LINKER_FLAGS), \
  ODIN_SYMBOL(KWAD_FINI), \
  ODIN_SYMBOL(KWAD_IGNORE_DUPLICATES), \
  ODIN_SYMBOL(KWAD_INIT), \
  ODIN_SYMBOL(KWAD_INSTRUMENTATION_ENTER), \
  ODIN_SYMBOL(KWAD_INSTRUMENTATION_EXIT), \
  ODIN_SYMBOL(KWAD_LINKAGE), \
  ODIN_SYMBOL(KWAD_LINK_NAME), \
  ODIN_SYMBOL(KWAD_LINK_PREFIX), \
  ODIN_SYMBOL(KWAD_LINK_SECTION), \
  ODIN_SYMBOL(KWAD_LINK_SUFFIX), \
  ODIN_SYMBOL(KWAD_NO_INSTRUMENTATION), \
  ODIN_SYMBOL(KWAD_NO_SANITIZE_ADDRESS), \
  ODIN_SYMBOL(KWAD_NO_SANITIZE_MEMORY), \
  ODIN_SYMBOL(KWAD_OBJC_CLASS), \
  ODIN_SYMBOL(KWAD_OBJC_CONTEXT_PROVIDER), \
  ODIN_SYMBOL(KWAD_OBJC_IMPLEMENT), \
  ODIN_SYMBOL(KWAD_OBJC_IS_CLASS_METHOD), \
  ODIN_SYMBOL(KWAD_OBJC_IVAR), \
  ODIN_SYMBOL(KWAD_OBJC_NAME), \
  ODIN_SYMBOL(KWAD_OBJC_SELECTOR), \
  ODIN_SYMBOL(KWAD_OBJC_SUPERCLASS), \
  ODIN_SYMBOL(KWAD_OBJC_TYPE), \
  ODIN_SYMBOL(KWAD_OPTIMIZATION_MODE), \
  ODIN_SYMBOL(KWAD_PRIORITY_INDEX), \
  ODIN_SYMBOL(KWAD_PRIVATE), \
  ODIN_SYMBOL(KWAD_RADDBG_TYPE_VIEW), \
  ODIN_SYMBOL(KWAD_REQUIRE), \
  ODIN_SYMBOL(KWAD_REQUIRE_RESULTS), \
  ODIN_SYMBOL(KWAD_REQUIRE_TARGET_FEATURE), \
  ODIN_SYMBOL(KWAD_RODATA), \
  ODIN_SYMBOL(KWAD_STATIC), \
  ODIN_SYMBOL(KWAD_TAG), \
  ODIN_SYMBOL(KWAD_TEST), \
  ODIN_SYMBOL(KWAD_THREAD_LOCAL)

// directives
#define ODIN_DIRECTIVE_SYMBOLS \
  ODIN_SYMBOL(KWAD_ALIGN), \
  ODIN_SYMBOL(KWAD_ALIGN_STACK), \
  ODIN_SYMBOL(KWAD_ALL_OR_NONE), \
  ODIN_SYMBOL(KWAD_ANY_INT), \
  ODIN_SYMBOL(KWAD_ATT), \
  ODIN_SYMBOL(KWAD_ASSERT), \
  ODIN_SYMBOL(KWAD_BOUNDS_CHECK), \
  ODIN_SYMBOL(KWAD_BRANCH_LOCATION), \
  ODIN_SYMBOL(KWAD_BY_PTR), \
  ODIN_SYMBOL(KWAD_CALLER_EXPRESSION), \
  ODIN_SYMBOL(KWAD_CALLER_LOCATION), \
  ODIN_SYMBOL(KWAD_COLUMN_MAJOR), \
  ODIN_SYMBOL(KWAD_CONFIG), \
  ODIN_SYMBOL(KWAD_CONST), \
  ODIN_SYMBOL(KWAD_C_VARARG), \
  ODIN_SYMBOL(KWAD_DEFINED), \
  ODIN_SYMBOL(KWAD_DIRECTORY), \
  ODIN_SYMBOL(KWAD_EXISTS), \
  ODIN_SYMBOL(KWAD_FILE), \
  ODIN_SYMBOL(KWAD_FORCE_INLINE), \
  ODIN_SYMBOL(KWAD_FORCE_NO_INLINE), \
  ODIN_SYMBOL(KWAD_HASH), \
  ODIN_SYMBOL(KWAD_INTEL), \
  ODIN_SYMBOL(KWAD_LINE), \
  ODIN_SYMBOL(KWAD_LOAD), \
  ODIN_SYMBOL(KWAD_LOAD_DIRECTORY), \
  ODIN_SYMBOL(KWAD_LOAD_HASH), \
  ODIN_SYMBOL(KWAD_LOCATION), \
  ODIN_SYMBOL(KWAD_MAX_FIELD_ALIGN), \
  ODIN_SYMBOL(KWAD_MIN_FIELD_ALIGN), \
  ODIN_SYMBOL(KWAD_MUST_TAIL), \
  ODIN_SYMBOL(KWAD_NO_ALIAS), \
  ODIN_SYMBOL(KWAD_NO_BOUNDS_CHECK), \
  ODIN_SYMBOL(KWAD_NO_BROADCAST), \
  ODIN_SYMBOL(KWAD_NO_NIL), \
  ODIN_SYMBOL(KWAD_NO_TYPE_ASSERT), \
  ODIN_SYMBOL(KWAD_OPTIONAL_ALLOCATOR_ERROR), \
  ODIN_SYMBOL(KWAD_OPTIONAL_OK), \
  ODIN_SYMBOL(KWAD_PACKED), \
  ODIN_SYMBOL(KWAD_PANIC), \
  ODIN_SYMBOL(KWAD_PARTIAL), \
  ODIN_SYMBOL(KWAD_PROCEDURE), \
  ODIN_SYMBOL(KWAD_RAW_UNION), \
  ODIN_SYMBOL(KWAD_REVERSE), \
  ODIN_SYMBOL(KWAD_ROW_MAJOR), \
  ODIN_SYMBOL(KWAD_SHARED_NIL), \
  ODIN_SYMBOL(KWAD_SIDE_EFFECTS), \
  ODIN_SYMBOL(KWAD_SIMD), \
  ODIN_SYMBOL(KWAD_SIMPLE), \
  ODIN_SYMBOL(KWAD_SOA), \
  ODIN_SYMBOL(KWAD_SPARSE), \
  ODIN_SYMBOL(KWAD_SUBTYPE), \
  ODIN_SYMBOL(KWAD_TYPE), \
  ODIN_SYMBOL(KWAD_TYPE_ASSERT), \
  ODIN_SYMBOL(KWAD_UNROLL)

// other terminals that may add a semicolon
#define ODIN_SEMICOLON_TERMINAL_SYMBOLS \
  ODIN_SYMBOL(INTEGER), \
  ODIN_SYMBOL(FLOAT), \
  ODIN_SYMBOL(IMAG), \
  ODIN_SYMBOL(RUNE), \
  ODIN_SYMBOL(STRING), \
  ODIN_SYMBOL(QUESTION), \
  ODIN_SYMBOL(POINTER), \
  ODIN_SYMBOL(CLOSEPAREN), \
  ODIN_SYMBOL(CLOSEBRACKET), \
  ODIN_SYMBOL(CLOSEBRACE), \
  ODIN_SYMBOL(NOT), \
  ODIN_SYMBOL(UNINIT)

// other terminals that do not add a semicolon
#define ODIN_NO_SEMICOLON_TERMINAL_SYMBOLS \
  ODIN_SYMBOL(ADD), \
  ODIN_SYMBOL(ADDEQ), \
  ODIN_SYMBOL(AND), \
  ODIN_SYMBOL(ANDEQ), \
  ODIN_SYMBOL(ANDNOT), \
  ODIN_SYMBOL(ANDNOTEQ), \
  ODIN_SYMBOL(ARROWRIGHT), \
  ODIN_SYMBOL(AT), \
  ODIN_SYMBOL(CMPAND), \
  ODIN_SYMBOL(CMPANDEQ), \
  ODIN_SYMBOL(CMPEQ), \
  ODIN_SYMBOL(CMPOR), \
  ODIN_SYMBOL(CMPOREQ), \
  ODIN_SYMBOL(COLON), \
  ODIN_SYMBOL(COMMA), \
  ODIN_SYMBOL(DOLLAR), \
  ODIN_SYMBOL(ELLIPSIS), \
  ODIN_SYMBOL(EQ), \
  ODIN_SYMBOL(FILETAG), \
  ODIN_SYMBOL(GT), \
  ODIN_SYMBOL(GTEQ), \
  ODIN_SYMBOL(HASH), \
  ODIN_SYMBOL(LT), \
  ODIN_SYMBOL(LTEQ), \
  ODIN_SYMBOL(MOD), \
  ODIN_SYMBOL(MODEQ), \
  ODIN_SYMBOL(MODMOD), \
  ODIN_SYMBOL(MODMODEQ), \
  ODIN_SYMBOL(MUL), \
  ODIN_SYMBOL(MULEQ), \
  ODIN_SYMBOL(NOTEQ), \
  ODIN_SYMBOL(OPENBRACE), \
  ODIN_SYMBOL(OPENBRACKET), \
  ODIN_SYMBOL(OPENPAREN), \
  ODIN_SYMBOL(OR), \
  ODIN_SYMBOL(OREQ), \
  ODIN_SYMBOL(PERIOD), \
  ODIN_SYMBOL(QUO), \
  ODIN_SYMBOL(QUOEQ), \
  ODIN_SYMBOL(RANGEFULL), \
  ODIN_SYMBOL(RANGEHALF), \
  ODIN_SYMBOL(SEMICOLON), \
  ODIN_SYMBOL(SHEBANG), \
  ODIN_SYMBOL(SHL), \
  ODIN_SYMBOL(SHLEQ), \
  ODIN_SYMBOL(SHR), \
  ODIN_SYMBOL(SHREQ), \
  ODIN_SYMBOL(SUB), \
  ODIN_SYMBOL(SUBEQ), \
  ODIN_SYMBOL(XOR), \
  ODIN_SYMBOL(XOREQ)

#define ODIN_ALL_SYMBOLS \
  ODIN_SPECIAL_SYMBOLS, \
  ODIN_SEMICOLON_KW_SYMBOLS, \
  ODIN_NO_SEMICOLON_KW_SYMBOLS, \
  ODIN_ATTRIBUTE_SYMBOLS, \
  ODIN_DIRECTIVE_SYMBOLS, \
  ODIN_SEMICOLON_TERMINAL_SYMBOLS, \
  ODIN_NO_SEMICOLON_TERMINAL_SYMBOLS

enum {
#define ODIN_SYMBOL(s) ODIN_ ## s
  ODIN_ALL_SYMBOLS,
#undef ODIN_SYMBOL

  ODIN_LAST_SYMBOL,

  ODIN_FIRST_SEMICOLON_KEYWORD = ODIN_KWAD_BREAK,
  ODIN_LAST_SEMICOLON_KEYWORD = ODIN_KWAD_TYPEID,
  ODIN_FIRST_SEMICOLON_OTHER_TERMINAL = ODIN_INTEGER,
  ODIN_LAST_SEMICOLON_OTHER_TERMINAL = ODIN_UNINIT,
};

static const char *odin_symbol_strings[] = {
#define ODIN_SYMBOL(e) #e
  ODIN_ALL_SYMBOLS
#undef ODIN_SYMBOL
};

GB_STATIC_ASSERT(ODIN_FIRST_SEMICOLON_KEYWORD < ODIN_LAST_SEMICOLON_KEYWORD);
GB_STATIC_ASSERT(ODIN_FIRST_SEMICOLON_OTHER_TERMINAL < ODIN_LAST_SEMICOLON_OTHER_TERMINAL);

//
// krnowak: character sets used with set_contains
//

// stolen from generated parser.c, matches [a-zA-Z_\p{Letter}]
#define ODIN_IDENTIFIER_SET_LETTERS_LEN (678)
static const TSCharacterRange odin_identifier_set_letters[] = {
  {'A', 'Z'}, {'_', '_'}, {'a', 'z'}, {0xaa, 0xaa}, {0xb5, 0xb5}, {0xba, 0xba}, {0xc0, 0xd6}, {0xd8, 0xf6},
  {0xf8, 0x2c1}, {0x2c6, 0x2d1}, {0x2e0, 0x2e4}, {0x2ec, 0x2ec}, {0x2ee, 0x2ee}, {0x370, 0x374}, {0x376, 0x377}, {0x37a, 0x37d},
  {0x37f, 0x37f}, {0x386, 0x386}, {0x388, 0x38a}, {0x38c, 0x38c}, {0x38e, 0x3a1}, {0x3a3, 0x3f5}, {0x3f7, 0x481}, {0x48a, 0x52f},
  {0x531, 0x556}, {0x559, 0x559}, {0x560, 0x588}, {0x5d0, 0x5ea}, {0x5ef, 0x5f2}, {0x620, 0x64a}, {0x66e, 0x66f}, {0x671, 0x6d3},
  {0x6d5, 0x6d5}, {0x6e5, 0x6e6}, {0x6ee, 0x6ef}, {0x6fa, 0x6fc}, {0x6ff, 0x6ff}, {0x710, 0x710}, {0x712, 0x72f}, {0x74d, 0x7a5},
  {0x7b1, 0x7b1}, {0x7ca, 0x7ea}, {0x7f4, 0x7f5}, {0x7fa, 0x7fa}, {0x800, 0x815}, {0x81a, 0x81a}, {0x824, 0x824}, {0x828, 0x828},
  {0x840, 0x858}, {0x860, 0x86a}, {0x870, 0x887}, {0x889, 0x88e}, {0x8a0, 0x8c9}, {0x904, 0x939}, {0x93d, 0x93d}, {0x950, 0x950},
  {0x958, 0x961}, {0x971, 0x980}, {0x985, 0x98c}, {0x98f, 0x990}, {0x993, 0x9a8}, {0x9aa, 0x9b0}, {0x9b2, 0x9b2}, {0x9b6, 0x9b9},
  {0x9bd, 0x9bd}, {0x9ce, 0x9ce}, {0x9dc, 0x9dd}, {0x9df, 0x9e1}, {0x9f0, 0x9f1}, {0x9fc, 0x9fc}, {0xa05, 0xa0a}, {0xa0f, 0xa10},
  {0xa13, 0xa28}, {0xa2a, 0xa30}, {0xa32, 0xa33}, {0xa35, 0xa36}, {0xa38, 0xa39}, {0xa59, 0xa5c}, {0xa5e, 0xa5e}, {0xa72, 0xa74},
  {0xa85, 0xa8d}, {0xa8f, 0xa91}, {0xa93, 0xaa8}, {0xaaa, 0xab0}, {0xab2, 0xab3}, {0xab5, 0xab9}, {0xabd, 0xabd}, {0xad0, 0xad0},
  {0xae0, 0xae1}, {0xaf9, 0xaf9}, {0xb05, 0xb0c}, {0xb0f, 0xb10}, {0xb13, 0xb28}, {0xb2a, 0xb30}, {0xb32, 0xb33}, {0xb35, 0xb39},
  {0xb3d, 0xb3d}, {0xb5c, 0xb5d}, {0xb5f, 0xb61}, {0xb71, 0xb71}, {0xb83, 0xb83}, {0xb85, 0xb8a}, {0xb8e, 0xb90}, {0xb92, 0xb95},
  {0xb99, 0xb9a}, {0xb9c, 0xb9c}, {0xb9e, 0xb9f}, {0xba3, 0xba4}, {0xba8, 0xbaa}, {0xbae, 0xbb9}, {0xbd0, 0xbd0}, {0xc05, 0xc0c},
  {0xc0e, 0xc10}, {0xc12, 0xc28}, {0xc2a, 0xc39}, {0xc3d, 0xc3d}, {0xc58, 0xc5a}, {0xc5d, 0xc5d}, {0xc60, 0xc61}, {0xc80, 0xc80},
  {0xc85, 0xc8c}, {0xc8e, 0xc90}, {0xc92, 0xca8}, {0xcaa, 0xcb3}, {0xcb5, 0xcb9}, {0xcbd, 0xcbd}, {0xcdd, 0xcde}, {0xce0, 0xce1},
  {0xcf1, 0xcf2}, {0xd04, 0xd0c}, {0xd0e, 0xd10}, {0xd12, 0xd3a}, {0xd3d, 0xd3d}, {0xd4e, 0xd4e}, {0xd54, 0xd56}, {0xd5f, 0xd61},
  {0xd7a, 0xd7f}, {0xd85, 0xd96}, {0xd9a, 0xdb1}, {0xdb3, 0xdbb}, {0xdbd, 0xdbd}, {0xdc0, 0xdc6}, {0xe01, 0xe30}, {0xe32, 0xe33},
  {0xe40, 0xe46}, {0xe81, 0xe82}, {0xe84, 0xe84}, {0xe86, 0xe8a}, {0xe8c, 0xea3}, {0xea5, 0xea5}, {0xea7, 0xeb0}, {0xeb2, 0xeb3},
  {0xebd, 0xebd}, {0xec0, 0xec4}, {0xec6, 0xec6}, {0xedc, 0xedf}, {0xf00, 0xf00}, {0xf40, 0xf47}, {0xf49, 0xf6c}, {0xf88, 0xf8c},
  {0x1000, 0x102a}, {0x103f, 0x103f}, {0x1050, 0x1055}, {0x105a, 0x105d}, {0x1061, 0x1061}, {0x1065, 0x1066}, {0x106e, 0x1070}, {0x1075, 0x1081},
  {0x108e, 0x108e}, {0x10a0, 0x10c5}, {0x10c7, 0x10c7}, {0x10cd, 0x10cd}, {0x10d0, 0x10fa}, {0x10fc, 0x1248}, {0x124a, 0x124d}, {0x1250, 0x1256},
  {0x1258, 0x1258}, {0x125a, 0x125d}, {0x1260, 0x1288}, {0x128a, 0x128d}, {0x1290, 0x12b0}, {0x12b2, 0x12b5}, {0x12b8, 0x12be}, {0x12c0, 0x12c0},
  {0x12c2, 0x12c5}, {0x12c8, 0x12d6}, {0x12d8, 0x1310}, {0x1312, 0x1315}, {0x1318, 0x135a}, {0x1380, 0x138f}, {0x13a0, 0x13f5}, {0x13f8, 0x13fd},
  {0x1401, 0x166c}, {0x166f, 0x167f}, {0x1681, 0x169a}, {0x16a0, 0x16ea}, {0x16f1, 0x16f8}, {0x1700, 0x1711}, {0x171f, 0x1731}, {0x1740, 0x1751},
  {0x1760, 0x176c}, {0x176e, 0x1770}, {0x1780, 0x17b3}, {0x17d7, 0x17d7}, {0x17dc, 0x17dc}, {0x1820, 0x1878}, {0x1880, 0x1884}, {0x1887, 0x18a8},
  {0x18aa, 0x18aa}, {0x18b0, 0x18f5}, {0x1900, 0x191e}, {0x1950, 0x196d}, {0x1970, 0x1974}, {0x1980, 0x19ab}, {0x19b0, 0x19c9}, {0x1a00, 0x1a16},
  {0x1a20, 0x1a54}, {0x1aa7, 0x1aa7}, {0x1b05, 0x1b33}, {0x1b45, 0x1b4c}, {0x1b83, 0x1ba0}, {0x1bae, 0x1baf}, {0x1bba, 0x1be5}, {0x1c00, 0x1c23},
  {0x1c4d, 0x1c4f}, {0x1c5a, 0x1c7d}, {0x1c80, 0x1c8a}, {0x1c90, 0x1cba}, {0x1cbd, 0x1cbf}, {0x1ce9, 0x1cec}, {0x1cee, 0x1cf3}, {0x1cf5, 0x1cf6},
  {0x1cfa, 0x1cfa}, {0x1d00, 0x1dbf}, {0x1e00, 0x1f15}, {0x1f18, 0x1f1d}, {0x1f20, 0x1f45}, {0x1f48, 0x1f4d}, {0x1f50, 0x1f57}, {0x1f59, 0x1f59},
  {0x1f5b, 0x1f5b}, {0x1f5d, 0x1f5d}, {0x1f5f, 0x1f7d}, {0x1f80, 0x1fb4}, {0x1fb6, 0x1fbc}, {0x1fbe, 0x1fbe}, {0x1fc2, 0x1fc4}, {0x1fc6, 0x1fcc},
  {0x1fd0, 0x1fd3}, {0x1fd6, 0x1fdb}, {0x1fe0, 0x1fec}, {0x1ff2, 0x1ff4}, {0x1ff6, 0x1ffc}, {0x2071, 0x2071}, {0x207f, 0x207f}, {0x2090, 0x209c},
  {0x2102, 0x2102}, {0x2107, 0x2107}, {0x210a, 0x2113}, {0x2115, 0x2115}, {0x2119, 0x211d}, {0x2124, 0x2124}, {0x2126, 0x2126}, {0x2128, 0x2128},
  {0x212a, 0x212d}, {0x212f, 0x2139}, {0x213c, 0x213f}, {0x2145, 0x2149}, {0x214e, 0x214e}, {0x2183, 0x2184}, {0x2c00, 0x2ce4}, {0x2ceb, 0x2cee},
  {0x2cf2, 0x2cf3}, {0x2d00, 0x2d25}, {0x2d27, 0x2d27}, {0x2d2d, 0x2d2d}, {0x2d30, 0x2d67}, {0x2d6f, 0x2d6f}, {0x2d80, 0x2d96}, {0x2da0, 0x2da6},
  {0x2da8, 0x2dae}, {0x2db0, 0x2db6}, {0x2db8, 0x2dbe}, {0x2dc0, 0x2dc6}, {0x2dc8, 0x2dce}, {0x2dd0, 0x2dd6}, {0x2dd8, 0x2dde}, {0x2e2f, 0x2e2f},
  {0x3005, 0x3006}, {0x3031, 0x3035}, {0x303b, 0x303c}, {0x3041, 0x3096}, {0x309d, 0x309f}, {0x30a1, 0x30fa}, {0x30fc, 0x30ff}, {0x3105, 0x312f},
  {0x3131, 0x318e}, {0x31a0, 0x31bf}, {0x31f0, 0x31ff}, {0x3400, 0x4dbf}, {0x4e00, 0xa48c}, {0xa4d0, 0xa4fd}, {0xa500, 0xa60c}, {0xa610, 0xa61f},
  {0xa62a, 0xa62b}, {0xa640, 0xa66e}, {0xa67f, 0xa69d}, {0xa6a0, 0xa6e5}, {0xa717, 0xa71f}, {0xa722, 0xa788}, {0xa78b, 0xa7cd}, {0xa7d0, 0xa7d1},
  {0xa7d3, 0xa7d3}, {0xa7d5, 0xa7dc}, {0xa7f2, 0xa801}, {0xa803, 0xa805}, {0xa807, 0xa80a}, {0xa80c, 0xa822}, {0xa840, 0xa873}, {0xa882, 0xa8b3},
  {0xa8f2, 0xa8f7}, {0xa8fb, 0xa8fb}, {0xa8fd, 0xa8fe}, {0xa90a, 0xa925}, {0xa930, 0xa946}, {0xa960, 0xa97c}, {0xa984, 0xa9b2}, {0xa9cf, 0xa9cf},
  {0xa9e0, 0xa9e4}, {0xa9e6, 0xa9ef}, {0xa9fa, 0xa9fe}, {0xaa00, 0xaa28}, {0xaa40, 0xaa42}, {0xaa44, 0xaa4b}, {0xaa60, 0xaa76}, {0xaa7a, 0xaa7a},
  {0xaa7e, 0xaaaf}, {0xaab1, 0xaab1}, {0xaab5, 0xaab6}, {0xaab9, 0xaabd}, {0xaac0, 0xaac0}, {0xaac2, 0xaac2}, {0xaadb, 0xaadd}, {0xaae0, 0xaaea},
  {0xaaf2, 0xaaf4}, {0xab01, 0xab06}, {0xab09, 0xab0e}, {0xab11, 0xab16}, {0xab20, 0xab26}, {0xab28, 0xab2e}, {0xab30, 0xab5a}, {0xab5c, 0xab69},
  {0xab70, 0xabe2}, {0xac00, 0xd7a3}, {0xd7b0, 0xd7c6}, {0xd7cb, 0xd7fb}, {0xf900, 0xfa6d}, {0xfa70, 0xfad9}, {0xfb00, 0xfb06}, {0xfb13, 0xfb17},
  {0xfb1d, 0xfb1d}, {0xfb1f, 0xfb28}, {0xfb2a, 0xfb36}, {0xfb38, 0xfb3c}, {0xfb3e, 0xfb3e}, {0xfb40, 0xfb41}, {0xfb43, 0xfb44}, {0xfb46, 0xfbb1},
  {0xfbd3, 0xfd3d}, {0xfd50, 0xfd8f}, {0xfd92, 0xfdc7}, {0xfdf0, 0xfdfb}, {0xfe70, 0xfe74}, {0xfe76, 0xfefc}, {0xff21, 0xff3a}, {0xff41, 0xff5a},
  {0xff66, 0xffbe}, {0xffc2, 0xffc7}, {0xffca, 0xffcf}, {0xffd2, 0xffd7}, {0xffda, 0xffdc}, {0x10000, 0x1000b}, {0x1000d, 0x10026}, {0x10028, 0x1003a},
  {0x1003c, 0x1003d}, {0x1003f, 0x1004d}, {0x10050, 0x1005d}, {0x10080, 0x100fa}, {0x10280, 0x1029c}, {0x102a0, 0x102d0}, {0x10300, 0x1031f}, {0x1032d, 0x10340},
  {0x10342, 0x10349}, {0x10350, 0x10375}, {0x10380, 0x1039d}, {0x103a0, 0x103c3}, {0x103c8, 0x103cf}, {0x10400, 0x1049d}, {0x104b0, 0x104d3}, {0x104d8, 0x104fb},
  {0x10500, 0x10527}, {0x10530, 0x10563}, {0x10570, 0x1057a}, {0x1057c, 0x1058a}, {0x1058c, 0x10592}, {0x10594, 0x10595}, {0x10597, 0x105a1}, {0x105a3, 0x105b1},
  {0x105b3, 0x105b9}, {0x105bb, 0x105bc}, {0x105c0, 0x105f3}, {0x10600, 0x10736}, {0x10740, 0x10755}, {0x10760, 0x10767}, {0x10780, 0x10785}, {0x10787, 0x107b0},
  {0x107b2, 0x107ba}, {0x10800, 0x10805}, {0x10808, 0x10808}, {0x1080a, 0x10835}, {0x10837, 0x10838}, {0x1083c, 0x1083c}, {0x1083f, 0x10855}, {0x10860, 0x10876},
  {0x10880, 0x1089e}, {0x108e0, 0x108f2}, {0x108f4, 0x108f5}, {0x10900, 0x10915}, {0x10920, 0x10939}, {0x10980, 0x109b7}, {0x109be, 0x109bf}, {0x10a00, 0x10a00},
  {0x10a10, 0x10a13}, {0x10a15, 0x10a17}, {0x10a19, 0x10a35}, {0x10a60, 0x10a7c}, {0x10a80, 0x10a9c}, {0x10ac0, 0x10ac7}, {0x10ac9, 0x10ae4}, {0x10b00, 0x10b35},
  {0x10b40, 0x10b55}, {0x10b60, 0x10b72}, {0x10b80, 0x10b91}, {0x10c00, 0x10c48}, {0x10c80, 0x10cb2}, {0x10cc0, 0x10cf2}, {0x10d00, 0x10d23}, {0x10d4a, 0x10d65},
  {0x10d6f, 0x10d85}, {0x10e80, 0x10ea9}, {0x10eb0, 0x10eb1}, {0x10ec2, 0x10ec4}, {0x10f00, 0x10f1c}, {0x10f27, 0x10f27}, {0x10f30, 0x10f45}, {0x10f70, 0x10f81},
  {0x10fb0, 0x10fc4}, {0x10fe0, 0x10ff6}, {0x11003, 0x11037}, {0x11071, 0x11072}, {0x11075, 0x11075}, {0x11083, 0x110af}, {0x110d0, 0x110e8}, {0x11103, 0x11126},
  {0x11144, 0x11144}, {0x11147, 0x11147}, {0x11150, 0x11172}, {0x11176, 0x11176}, {0x11183, 0x111b2}, {0x111c1, 0x111c4}, {0x111da, 0x111da}, {0x111dc, 0x111dc},
  {0x11200, 0x11211}, {0x11213, 0x1122b}, {0x1123f, 0x11240}, {0x11280, 0x11286}, {0x11288, 0x11288}, {0x1128a, 0x1128d}, {0x1128f, 0x1129d}, {0x1129f, 0x112a8},
  {0x112b0, 0x112de}, {0x11305, 0x1130c}, {0x1130f, 0x11310}, {0x11313, 0x11328}, {0x1132a, 0x11330}, {0x11332, 0x11333}, {0x11335, 0x11339}, {0x1133d, 0x1133d},
  {0x11350, 0x11350}, {0x1135d, 0x11361}, {0x11380, 0x11389}, {0x1138b, 0x1138b}, {0x1138e, 0x1138e}, {0x11390, 0x113b5}, {0x113b7, 0x113b7}, {0x113d1, 0x113d1},
  {0x113d3, 0x113d3}, {0x11400, 0x11434}, {0x11447, 0x1144a}, {0x1145f, 0x11461}, {0x11480, 0x114af}, {0x114c4, 0x114c5}, {0x114c7, 0x114c7}, {0x11580, 0x115ae},
  {0x115d8, 0x115db}, {0x11600, 0x1162f}, {0x11644, 0x11644}, {0x11680, 0x116aa}, {0x116b8, 0x116b8}, {0x11700, 0x1171a}, {0x11740, 0x11746}, {0x11800, 0x1182b},
  {0x118a0, 0x118df}, {0x118ff, 0x11906}, {0x11909, 0x11909}, {0x1190c, 0x11913}, {0x11915, 0x11916}, {0x11918, 0x1192f}, {0x1193f, 0x1193f}, {0x11941, 0x11941},
  {0x119a0, 0x119a7}, {0x119aa, 0x119d0}, {0x119e1, 0x119e1}, {0x119e3, 0x119e3}, {0x11a00, 0x11a00}, {0x11a0b, 0x11a32}, {0x11a3a, 0x11a3a}, {0x11a50, 0x11a50},
  {0x11a5c, 0x11a89}, {0x11a9d, 0x11a9d}, {0x11ab0, 0x11af8}, {0x11bc0, 0x11be0}, {0x11c00, 0x11c08}, {0x11c0a, 0x11c2e}, {0x11c40, 0x11c40}, {0x11c72, 0x11c8f},
  {0x11d00, 0x11d06}, {0x11d08, 0x11d09}, {0x11d0b, 0x11d30}, {0x11d46, 0x11d46}, {0x11d60, 0x11d65}, {0x11d67, 0x11d68}, {0x11d6a, 0x11d89}, {0x11d98, 0x11d98},
  {0x11ee0, 0x11ef2}, {0x11f02, 0x11f02}, {0x11f04, 0x11f10}, {0x11f12, 0x11f33}, {0x11fb0, 0x11fb0}, {0x12000, 0x12399}, {0x12480, 0x12543}, {0x12f90, 0x12ff0},
  {0x13000, 0x1342f}, {0x13441, 0x13446}, {0x13460, 0x143fa}, {0x14400, 0x14646}, {0x16100, 0x1611d}, {0x16800, 0x16a38}, {0x16a40, 0x16a5e}, {0x16a70, 0x16abe},
  {0x16ad0, 0x16aed}, {0x16b00, 0x16b2f}, {0x16b40, 0x16b43}, {0x16b63, 0x16b77}, {0x16b7d, 0x16b8f}, {0x16d40, 0x16d6c}, {0x16e40, 0x16e7f}, {0x16f00, 0x16f4a},
  {0x16f50, 0x16f50}, {0x16f93, 0x16f9f}, {0x16fe0, 0x16fe1}, {0x16fe3, 0x16fe3}, {0x17000, 0x187f7}, {0x18800, 0x18cd5}, {0x18cff, 0x18d08}, {0x1aff0, 0x1aff3},
  {0x1aff5, 0x1affb}, {0x1affd, 0x1affe}, {0x1b000, 0x1b122}, {0x1b132, 0x1b132}, {0x1b150, 0x1b152}, {0x1b155, 0x1b155}, {0x1b164, 0x1b167}, {0x1b170, 0x1b2fb},
  {0x1bc00, 0x1bc6a}, {0x1bc70, 0x1bc7c}, {0x1bc80, 0x1bc88}, {0x1bc90, 0x1bc99}, {0x1d400, 0x1d454}, {0x1d456, 0x1d49c}, {0x1d49e, 0x1d49f}, {0x1d4a2, 0x1d4a2},
  {0x1d4a5, 0x1d4a6}, {0x1d4a9, 0x1d4ac}, {0x1d4ae, 0x1d4b9}, {0x1d4bb, 0x1d4bb}, {0x1d4bd, 0x1d4c3}, {0x1d4c5, 0x1d505}, {0x1d507, 0x1d50a}, {0x1d50d, 0x1d514},
  {0x1d516, 0x1d51c}, {0x1d51e, 0x1d539}, {0x1d53b, 0x1d53e}, {0x1d540, 0x1d544}, {0x1d546, 0x1d546}, {0x1d54a, 0x1d550}, {0x1d552, 0x1d6a5}, {0x1d6a8, 0x1d6c0},
  {0x1d6c2, 0x1d6da}, {0x1d6dc, 0x1d6fa}, {0x1d6fc, 0x1d714}, {0x1d716, 0x1d734}, {0x1d736, 0x1d74e}, {0x1d750, 0x1d76e}, {0x1d770, 0x1d788}, {0x1d78a, 0x1d7a8},
  {0x1d7aa, 0x1d7c2}, {0x1d7c4, 0x1d7cb}, {0x1df00, 0x1df1e}, {0x1df25, 0x1df2a}, {0x1e030, 0x1e06d}, {0x1e100, 0x1e12c}, {0x1e137, 0x1e13d}, {0x1e14e, 0x1e14e},
  {0x1e290, 0x1e2ad}, {0x1e2c0, 0x1e2eb}, {0x1e4d0, 0x1e4eb}, {0x1e5d0, 0x1e5ed}, {0x1e5f0, 0x1e5f0}, {0x1e7e0, 0x1e7e6}, {0x1e7e8, 0x1e7eb}, {0x1e7ed, 0x1e7ee},
  {0x1e7f0, 0x1e7fe}, {0x1e800, 0x1e8c4}, {0x1e900, 0x1e943}, {0x1e94b, 0x1e94b}, {0x1ee00, 0x1ee03}, {0x1ee05, 0x1ee1f}, {0x1ee21, 0x1ee22}, {0x1ee24, 0x1ee24},
  {0x1ee27, 0x1ee27}, {0x1ee29, 0x1ee32}, {0x1ee34, 0x1ee37}, {0x1ee39, 0x1ee39}, {0x1ee3b, 0x1ee3b}, {0x1ee42, 0x1ee42}, {0x1ee47, 0x1ee47}, {0x1ee49, 0x1ee49},
  {0x1ee4b, 0x1ee4b}, {0x1ee4d, 0x1ee4f}, {0x1ee51, 0x1ee52}, {0x1ee54, 0x1ee54}, {0x1ee57, 0x1ee57}, {0x1ee59, 0x1ee59}, {0x1ee5b, 0x1ee5b}, {0x1ee5d, 0x1ee5d},
  {0x1ee5f, 0x1ee5f}, {0x1ee61, 0x1ee62}, {0x1ee64, 0x1ee64}, {0x1ee67, 0x1ee6a}, {0x1ee6c, 0x1ee72}, {0x1ee74, 0x1ee77}, {0x1ee79, 0x1ee7c}, {0x1ee7e, 0x1ee7e},
  {0x1ee80, 0x1ee89}, {0x1ee8b, 0x1ee9b}, {0x1eea1, 0x1eea3}, {0x1eea5, 0x1eea9}, {0x1eeab, 0x1eebb}, {0x20000, 0x2a6df}, {0x2a700, 0x2b739}, {0x2b740, 0x2b81d},
  {0x2b820, 0x2cea1}, {0x2ceb0, 0x2ebe0}, {0x2ebf0, 0x2ee5d}, {0x2f800, 0x2fa1d}, {0x30000, 0x3134a}, {0x31350, 0x323af},
};

// stolen from generated parser.c, matches [a-zA-Z_\p{Letter}\pNd]
#define ODIN_IDENTIFIER_SET_LETTERS_DIGITS_LEN 771
static const TSCharacterRange odin_identifier_set_letters_digits[] = {
  {'0', '9'}, {'A', 'Z'}, {'_', '_'}, {'a', 'z'}, {0xaa, 0xaa}, {0xb2, 0xb3}, {0xb5, 0xb5}, {0xb9, 0xba},
  {0xbc, 0xbe}, {0xc0, 0xd6}, {0xd8, 0xf6}, {0xf8, 0x2c1}, {0x2c6, 0x2d1}, {0x2e0, 0x2e4}, {0x2ec, 0x2ec}, {0x2ee, 0x2ee},
  {0x370, 0x374}, {0x376, 0x377}, {0x37a, 0x37d}, {0x37f, 0x37f}, {0x386, 0x386}, {0x388, 0x38a}, {0x38c, 0x38c}, {0x38e, 0x3a1},
  {0x3a3, 0x3f5}, {0x3f7, 0x481}, {0x48a, 0x52f}, {0x531, 0x556}, {0x559, 0x559}, {0x560, 0x588}, {0x5d0, 0x5ea}, {0x5ef, 0x5f2},
  {0x620, 0x64a}, {0x660, 0x669}, {0x66e, 0x66f}, {0x671, 0x6d3}, {0x6d5, 0x6d5}, {0x6e5, 0x6e6}, {0x6ee, 0x6fc}, {0x6ff, 0x6ff},
  {0x710, 0x710}, {0x712, 0x72f}, {0x74d, 0x7a5}, {0x7b1, 0x7b1}, {0x7c0, 0x7ea}, {0x7f4, 0x7f5}, {0x7fa, 0x7fa}, {0x800, 0x815},
  {0x81a, 0x81a}, {0x824, 0x824}, {0x828, 0x828}, {0x840, 0x858}, {0x860, 0x86a}, {0x870, 0x887}, {0x889, 0x88e}, {0x8a0, 0x8c9},
  {0x904, 0x939}, {0x93d, 0x93d}, {0x950, 0x950}, {0x958, 0x961}, {0x966, 0x96f}, {0x971, 0x980}, {0x985, 0x98c}, {0x98f, 0x990},
  {0x993, 0x9a8}, {0x9aa, 0x9b0}, {0x9b2, 0x9b2}, {0x9b6, 0x9b9}, {0x9bd, 0x9bd}, {0x9ce, 0x9ce}, {0x9dc, 0x9dd}, {0x9df, 0x9e1},
  {0x9e6, 0x9f1}, {0x9f4, 0x9f9}, {0x9fc, 0x9fc}, {0xa05, 0xa0a}, {0xa0f, 0xa10}, {0xa13, 0xa28}, {0xa2a, 0xa30}, {0xa32, 0xa33},
  {0xa35, 0xa36}, {0xa38, 0xa39}, {0xa59, 0xa5c}, {0xa5e, 0xa5e}, {0xa66, 0xa6f}, {0xa72, 0xa74}, {0xa85, 0xa8d}, {0xa8f, 0xa91},
  {0xa93, 0xaa8}, {0xaaa, 0xab0}, {0xab2, 0xab3}, {0xab5, 0xab9}, {0xabd, 0xabd}, {0xad0, 0xad0}, {0xae0, 0xae1}, {0xae6, 0xaef},
  {0xaf9, 0xaf9}, {0xb05, 0xb0c}, {0xb0f, 0xb10}, {0xb13, 0xb28}, {0xb2a, 0xb30}, {0xb32, 0xb33}, {0xb35, 0xb39}, {0xb3d, 0xb3d},
  {0xb5c, 0xb5d}, {0xb5f, 0xb61}, {0xb66, 0xb6f}, {0xb71, 0xb77}, {0xb83, 0xb83}, {0xb85, 0xb8a}, {0xb8e, 0xb90}, {0xb92, 0xb95},
  {0xb99, 0xb9a}, {0xb9c, 0xb9c}, {0xb9e, 0xb9f}, {0xba3, 0xba4}, {0xba8, 0xbaa}, {0xbae, 0xbb9}, {0xbd0, 0xbd0}, {0xbe6, 0xbf2},
  {0xc05, 0xc0c}, {0xc0e, 0xc10}, {0xc12, 0xc28}, {0xc2a, 0xc39}, {0xc3d, 0xc3d}, {0xc58, 0xc5a}, {0xc5d, 0xc5d}, {0xc60, 0xc61},
  {0xc66, 0xc6f}, {0xc78, 0xc7e}, {0xc80, 0xc80}, {0xc85, 0xc8c}, {0xc8e, 0xc90}, {0xc92, 0xca8}, {0xcaa, 0xcb3}, {0xcb5, 0xcb9},
  {0xcbd, 0xcbd}, {0xcdd, 0xcde}, {0xce0, 0xce1}, {0xce6, 0xcef}, {0xcf1, 0xcf2}, {0xd04, 0xd0c}, {0xd0e, 0xd10}, {0xd12, 0xd3a},
  {0xd3d, 0xd3d}, {0xd4e, 0xd4e}, {0xd54, 0xd56}, {0xd58, 0xd61}, {0xd66, 0xd78}, {0xd7a, 0xd7f}, {0xd85, 0xd96}, {0xd9a, 0xdb1},
  {0xdb3, 0xdbb}, {0xdbd, 0xdbd}, {0xdc0, 0xdc6}, {0xde6, 0xdef}, {0xe01, 0xe30}, {0xe32, 0xe33}, {0xe40, 0xe46}, {0xe50, 0xe59},
  {0xe81, 0xe82}, {0xe84, 0xe84}, {0xe86, 0xe8a}, {0xe8c, 0xea3}, {0xea5, 0xea5}, {0xea7, 0xeb0}, {0xeb2, 0xeb3}, {0xebd, 0xebd},
  {0xec0, 0xec4}, {0xec6, 0xec6}, {0xed0, 0xed9}, {0xedc, 0xedf}, {0xf00, 0xf00}, {0xf20, 0xf33}, {0xf40, 0xf47}, {0xf49, 0xf6c},
  {0xf88, 0xf8c}, {0x1000, 0x102a}, {0x103f, 0x1049}, {0x1050, 0x1055}, {0x105a, 0x105d}, {0x1061, 0x1061}, {0x1065, 0x1066}, {0x106e, 0x1070},
  {0x1075, 0x1081}, {0x108e, 0x108e}, {0x1090, 0x1099}, {0x10a0, 0x10c5}, {0x10c7, 0x10c7}, {0x10cd, 0x10cd}, {0x10d0, 0x10fa}, {0x10fc, 0x1248},
  {0x124a, 0x124d}, {0x1250, 0x1256}, {0x1258, 0x1258}, {0x125a, 0x125d}, {0x1260, 0x1288}, {0x128a, 0x128d}, {0x1290, 0x12b0}, {0x12b2, 0x12b5},
  {0x12b8, 0x12be}, {0x12c0, 0x12c0}, {0x12c2, 0x12c5}, {0x12c8, 0x12d6}, {0x12d8, 0x1310}, {0x1312, 0x1315}, {0x1318, 0x135a}, {0x1369, 0x137c},
  {0x1380, 0x138f}, {0x13a0, 0x13f5}, {0x13f8, 0x13fd}, {0x1401, 0x166c}, {0x166f, 0x167f}, {0x1681, 0x169a}, {0x16a0, 0x16ea}, {0x16ee, 0x16f8},
  {0x1700, 0x1711}, {0x171f, 0x1731}, {0x1740, 0x1751}, {0x1760, 0x176c}, {0x176e, 0x1770}, {0x1780, 0x17b3}, {0x17d7, 0x17d7}, {0x17dc, 0x17dc},
  {0x17e0, 0x17e9}, {0x17f0, 0x17f9}, {0x1810, 0x1819}, {0x1820, 0x1878}, {0x1880, 0x1884}, {0x1887, 0x18a8}, {0x18aa, 0x18aa}, {0x18b0, 0x18f5},
  {0x1900, 0x191e}, {0x1946, 0x196d}, {0x1970, 0x1974}, {0x1980, 0x19ab}, {0x19b0, 0x19c9}, {0x19d0, 0x19da}, {0x1a00, 0x1a16}, {0x1a20, 0x1a54},
  {0x1a80, 0x1a89}, {0x1a90, 0x1a99}, {0x1aa7, 0x1aa7}, {0x1b05, 0x1b33}, {0x1b45, 0x1b4c}, {0x1b50, 0x1b59}, {0x1b83, 0x1ba0}, {0x1bae, 0x1be5},
  {0x1c00, 0x1c23}, {0x1c40, 0x1c49}, {0x1c4d, 0x1c7d}, {0x1c80, 0x1c8a}, {0x1c90, 0x1cba}, {0x1cbd, 0x1cbf}, {0x1ce9, 0x1cec}, {0x1cee, 0x1cf3},
  {0x1cf5, 0x1cf6}, {0x1cfa, 0x1cfa}, {0x1d00, 0x1dbf}, {0x1e00, 0x1f15}, {0x1f18, 0x1f1d}, {0x1f20, 0x1f45}, {0x1f48, 0x1f4d}, {0x1f50, 0x1f57},
  {0x1f59, 0x1f59}, {0x1f5b, 0x1f5b}, {0x1f5d, 0x1f5d}, {0x1f5f, 0x1f7d}, {0x1f80, 0x1fb4}, {0x1fb6, 0x1fbc}, {0x1fbe, 0x1fbe}, {0x1fc2, 0x1fc4},
  {0x1fc6, 0x1fcc}, {0x1fd0, 0x1fd3}, {0x1fd6, 0x1fdb}, {0x1fe0, 0x1fec}, {0x1ff2, 0x1ff4}, {0x1ff6, 0x1ffc}, {0x2070, 0x2071}, {0x2074, 0x2079},
  {0x207f, 0x2089}, {0x2090, 0x209c}, {0x2102, 0x2102}, {0x2107, 0x2107}, {0x210a, 0x2113}, {0x2115, 0x2115}, {0x2119, 0x211d}, {0x2124, 0x2124},
  {0x2126, 0x2126}, {0x2128, 0x2128}, {0x212a, 0x212d}, {0x212f, 0x2139}, {0x213c, 0x213f}, {0x2145, 0x2149}, {0x214e, 0x214e}, {0x2150, 0x2189},
  {0x2460, 0x249b}, {0x24ea, 0x24ff}, {0x2776, 0x2793}, {0x2c00, 0x2ce4}, {0x2ceb, 0x2cee}, {0x2cf2, 0x2cf3}, {0x2cfd, 0x2cfd}, {0x2d00, 0x2d25},
  {0x2d27, 0x2d27}, {0x2d2d, 0x2d2d}, {0x2d30, 0x2d67}, {0x2d6f, 0x2d6f}, {0x2d80, 0x2d96}, {0x2da0, 0x2da6}, {0x2da8, 0x2dae}, {0x2db0, 0x2db6},
  {0x2db8, 0x2dbe}, {0x2dc0, 0x2dc6}, {0x2dc8, 0x2dce}, {0x2dd0, 0x2dd6}, {0x2dd8, 0x2dde}, {0x2e2f, 0x2e2f}, {0x3005, 0x3007}, {0x3021, 0x3029},
  {0x3031, 0x3035}, {0x3038, 0x303c}, {0x3041, 0x3096}, {0x309d, 0x309f}, {0x30a1, 0x30fa}, {0x30fc, 0x30ff}, {0x3105, 0x312f}, {0x3131, 0x318e},
  {0x3192, 0x3195}, {0x31a0, 0x31bf}, {0x31f0, 0x31ff}, {0x3220, 0x3229}, {0x3248, 0x324f}, {0x3251, 0x325f}, {0x3280, 0x3289}, {0x32b1, 0x32bf},
  {0x3400, 0x4dbf}, {0x4e00, 0xa48c}, {0xa4d0, 0xa4fd}, {0xa500, 0xa60c}, {0xa610, 0xa62b}, {0xa640, 0xa66e}, {0xa67f, 0xa69d}, {0xa6a0, 0xa6ef},
  {0xa717, 0xa71f}, {0xa722, 0xa788}, {0xa78b, 0xa7cd}, {0xa7d0, 0xa7d1}, {0xa7d3, 0xa7d3}, {0xa7d5, 0xa7dc}, {0xa7f2, 0xa801}, {0xa803, 0xa805},
  {0xa807, 0xa80a}, {0xa80c, 0xa822}, {0xa830, 0xa835}, {0xa840, 0xa873}, {0xa882, 0xa8b3}, {0xa8d0, 0xa8d9}, {0xa8f2, 0xa8f7}, {0xa8fb, 0xa8fb},
  {0xa8fd, 0xa8fe}, {0xa900, 0xa925}, {0xa930, 0xa946}, {0xa960, 0xa97c}, {0xa984, 0xa9b2}, {0xa9cf, 0xa9d9}, {0xa9e0, 0xa9e4}, {0xa9e6, 0xa9fe},
  {0xaa00, 0xaa28}, {0xaa40, 0xaa42}, {0xaa44, 0xaa4b}, {0xaa50, 0xaa59}, {0xaa60, 0xaa76}, {0xaa7a, 0xaa7a}, {0xaa7e, 0xaaaf}, {0xaab1, 0xaab1},
  {0xaab5, 0xaab6}, {0xaab9, 0xaabd}, {0xaac0, 0xaac0}, {0xaac2, 0xaac2}, {0xaadb, 0xaadd}, {0xaae0, 0xaaea}, {0xaaf2, 0xaaf4}, {0xab01, 0xab06},
  {0xab09, 0xab0e}, {0xab11, 0xab16}, {0xab20, 0xab26}, {0xab28, 0xab2e}, {0xab30, 0xab5a}, {0xab5c, 0xab69}, {0xab70, 0xabe2}, {0xabf0, 0xabf9},
  {0xac00, 0xd7a3}, {0xd7b0, 0xd7c6}, {0xd7cb, 0xd7fb}, {0xf900, 0xfa6d}, {0xfa70, 0xfad9}, {0xfb00, 0xfb06}, {0xfb13, 0xfb17}, {0xfb1d, 0xfb1d},
  {0xfb1f, 0xfb28}, {0xfb2a, 0xfb36}, {0xfb38, 0xfb3c}, {0xfb3e, 0xfb3e}, {0xfb40, 0xfb41}, {0xfb43, 0xfb44}, {0xfb46, 0xfbb1}, {0xfbd3, 0xfd3d},
  {0xfd50, 0xfd8f}, {0xfd92, 0xfdc7}, {0xfdf0, 0xfdfb}, {0xfe70, 0xfe74}, {0xfe76, 0xfefc}, {0xff10, 0xff19}, {0xff21, 0xff3a}, {0xff41, 0xff5a},
  {0xff66, 0xffbe}, {0xffc2, 0xffc7}, {0xffca, 0xffcf}, {0xffd2, 0xffd7}, {0xffda, 0xffdc}, {0x10000, 0x1000b}, {0x1000d, 0x10026}, {0x10028, 0x1003a},
  {0x1003c, 0x1003d}, {0x1003f, 0x1004d}, {0x10050, 0x1005d}, {0x10080, 0x100fa}, {0x10107, 0x10133}, {0x10140, 0x10178}, {0x1018a, 0x1018b}, {0x10280, 0x1029c},
  {0x102a0, 0x102d0}, {0x102e1, 0x102fb}, {0x10300, 0x10323}, {0x1032d, 0x1034a}, {0x10350, 0x10375}, {0x10380, 0x1039d}, {0x103a0, 0x103c3}, {0x103c8, 0x103cf},
  {0x103d1, 0x103d5}, {0x10400, 0x1049d}, {0x104a0, 0x104a9}, {0x104b0, 0x104d3}, {0x104d8, 0x104fb}, {0x10500, 0x10527}, {0x10530, 0x10563}, {0x10570, 0x1057a},
  {0x1057c, 0x1058a}, {0x1058c, 0x10592}, {0x10594, 0x10595}, {0x10597, 0x105a1}, {0x105a3, 0x105b1}, {0x105b3, 0x105b9}, {0x105bb, 0x105bc}, {0x105c0, 0x105f3},
  {0x10600, 0x10736}, {0x10740, 0x10755}, {0x10760, 0x10767}, {0x10780, 0x10785}, {0x10787, 0x107b0}, {0x107b2, 0x107ba}, {0x10800, 0x10805}, {0x10808, 0x10808},
  {0x1080a, 0x10835}, {0x10837, 0x10838}, {0x1083c, 0x1083c}, {0x1083f, 0x10855}, {0x10858, 0x10876}, {0x10879, 0x1089e}, {0x108a7, 0x108af}, {0x108e0, 0x108f2},
  {0x108f4, 0x108f5}, {0x108fb, 0x1091b}, {0x10920, 0x10939}, {0x10980, 0x109b7}, {0x109bc, 0x109cf}, {0x109d2, 0x10a00}, {0x10a10, 0x10a13}, {0x10a15, 0x10a17},
  {0x10a19, 0x10a35}, {0x10a40, 0x10a48}, {0x10a60, 0x10a7e}, {0x10a80, 0x10a9f}, {0x10ac0, 0x10ac7}, {0x10ac9, 0x10ae4}, {0x10aeb, 0x10aef}, {0x10b00, 0x10b35},
  {0x10b40, 0x10b55}, {0x10b58, 0x10b72}, {0x10b78, 0x10b91}, {0x10ba9, 0x10baf}, {0x10c00, 0x10c48}, {0x10c80, 0x10cb2}, {0x10cc0, 0x10cf2}, {0x10cfa, 0x10d23},
  {0x10d30, 0x10d39}, {0x10d40, 0x10d65}, {0x10d6f, 0x10d85}, {0x10e60, 0x10e7e}, {0x10e80, 0x10ea9}, {0x10eb0, 0x10eb1}, {0x10ec2, 0x10ec4}, {0x10f00, 0x10f27},
  {0x10f30, 0x10f45}, {0x10f51, 0x10f54}, {0x10f70, 0x10f81}, {0x10fb0, 0x10fcb}, {0x10fe0, 0x10ff6}, {0x11003, 0x11037}, {0x11052, 0x1106f}, {0x11071, 0x11072},
  {0x11075, 0x11075}, {0x11083, 0x110af}, {0x110d0, 0x110e8}, {0x110f0, 0x110f9}, {0x11103, 0x11126}, {0x11136, 0x1113f}, {0x11144, 0x11144}, {0x11147, 0x11147},
  {0x11150, 0x11172}, {0x11176, 0x11176}, {0x11183, 0x111b2}, {0x111c1, 0x111c4}, {0x111d0, 0x111da}, {0x111dc, 0x111dc}, {0x111e1, 0x111f4}, {0x11200, 0x11211},
  {0x11213, 0x1122b}, {0x1123f, 0x11240}, {0x11280, 0x11286}, {0x11288, 0x11288}, {0x1128a, 0x1128d}, {0x1128f, 0x1129d}, {0x1129f, 0x112a8}, {0x112b0, 0x112de},
  {0x112f0, 0x112f9}, {0x11305, 0x1130c}, {0x1130f, 0x11310}, {0x11313, 0x11328}, {0x1132a, 0x11330}, {0x11332, 0x11333}, {0x11335, 0x11339}, {0x1133d, 0x1133d},
  {0x11350, 0x11350}, {0x1135d, 0x11361}, {0x11380, 0x11389}, {0x1138b, 0x1138b}, {0x1138e, 0x1138e}, {0x11390, 0x113b5}, {0x113b7, 0x113b7}, {0x113d1, 0x113d1},
  {0x113d3, 0x113d3}, {0x11400, 0x11434}, {0x11447, 0x1144a}, {0x11450, 0x11459}, {0x1145f, 0x11461}, {0x11480, 0x114af}, {0x114c4, 0x114c5}, {0x114c7, 0x114c7},
  {0x114d0, 0x114d9}, {0x11580, 0x115ae}, {0x115d8, 0x115db}, {0x11600, 0x1162f}, {0x11644, 0x11644}, {0x11650, 0x11659}, {0x11680, 0x116aa}, {0x116b8, 0x116b8},
  {0x116c0, 0x116c9}, {0x116d0, 0x116e3}, {0x11700, 0x1171a}, {0x11730, 0x1173b}, {0x11740, 0x11746}, {0x11800, 0x1182b}, {0x118a0, 0x118f2}, {0x118ff, 0x11906},
  {0x11909, 0x11909}, {0x1190c, 0x11913}, {0x11915, 0x11916}, {0x11918, 0x1192f}, {0x1193f, 0x1193f}, {0x11941, 0x11941}, {0x11950, 0x11959}, {0x119a0, 0x119a7},
  {0x119aa, 0x119d0}, {0x119e1, 0x119e1}, {0x119e3, 0x119e3}, {0x11a00, 0x11a00}, {0x11a0b, 0x11a32}, {0x11a3a, 0x11a3a}, {0x11a50, 0x11a50}, {0x11a5c, 0x11a89},
  {0x11a9d, 0x11a9d}, {0x11ab0, 0x11af8}, {0x11bc0, 0x11be0}, {0x11bf0, 0x11bf9}, {0x11c00, 0x11c08}, {0x11c0a, 0x11c2e}, {0x11c40, 0x11c40}, {0x11c50, 0x11c6c},
  {0x11c72, 0x11c8f}, {0x11d00, 0x11d06}, {0x11d08, 0x11d09}, {0x11d0b, 0x11d30}, {0x11d46, 0x11d46}, {0x11d50, 0x11d59}, {0x11d60, 0x11d65}, {0x11d67, 0x11d68},
  {0x11d6a, 0x11d89}, {0x11d98, 0x11d98}, {0x11da0, 0x11da9}, {0x11ee0, 0x11ef2}, {0x11f02, 0x11f02}, {0x11f04, 0x11f10}, {0x11f12, 0x11f33}, {0x11f50, 0x11f59},
  {0x11fb0, 0x11fb0}, {0x11fc0, 0x11fd4}, {0x12000, 0x12399}, {0x12400, 0x1246e}, {0x12480, 0x12543}, {0x12f90, 0x12ff0}, {0x13000, 0x1342f}, {0x13441, 0x13446},
  {0x13460, 0x143fa}, {0x14400, 0x14646}, {0x16100, 0x1611d}, {0x16130, 0x16139}, {0x16800, 0x16a38}, {0x16a40, 0x16a5e}, {0x16a60, 0x16a69}, {0x16a70, 0x16abe},
  {0x16ac0, 0x16ac9}, {0x16ad0, 0x16aed}, {0x16b00, 0x16b2f}, {0x16b40, 0x16b43}, {0x16b50, 0x16b59}, {0x16b5b, 0x16b61}, {0x16b63, 0x16b77}, {0x16b7d, 0x16b8f},
  {0x16d40, 0x16d6c}, {0x16d70, 0x16d79}, {0x16e40, 0x16e96}, {0x16f00, 0x16f4a}, {0x16f50, 0x16f50}, {0x16f93, 0x16f9f}, {0x16fe0, 0x16fe1}, {0x16fe3, 0x16fe3},
  {0x17000, 0x187f7}, {0x18800, 0x18cd5}, {0x18cff, 0x18d08}, {0x1aff0, 0x1aff3}, {0x1aff5, 0x1affb}, {0x1affd, 0x1affe}, {0x1b000, 0x1b122}, {0x1b132, 0x1b132},
  {0x1b150, 0x1b152}, {0x1b155, 0x1b155}, {0x1b164, 0x1b167}, {0x1b170, 0x1b2fb}, {0x1bc00, 0x1bc6a}, {0x1bc70, 0x1bc7c}, {0x1bc80, 0x1bc88}, {0x1bc90, 0x1bc99},
  {0x1ccf0, 0x1ccf9}, {0x1d2c0, 0x1d2d3}, {0x1d2e0, 0x1d2f3}, {0x1d360, 0x1d378}, {0x1d400, 0x1d454}, {0x1d456, 0x1d49c}, {0x1d49e, 0x1d49f}, {0x1d4a2, 0x1d4a2},
  {0x1d4a5, 0x1d4a6}, {0x1d4a9, 0x1d4ac}, {0x1d4ae, 0x1d4b9}, {0x1d4bb, 0x1d4bb}, {0x1d4bd, 0x1d4c3}, {0x1d4c5, 0x1d505}, {0x1d507, 0x1d50a}, {0x1d50d, 0x1d514},
  {0x1d516, 0x1d51c}, {0x1d51e, 0x1d539}, {0x1d53b, 0x1d53e}, {0x1d540, 0x1d544}, {0x1d546, 0x1d546}, {0x1d54a, 0x1d550}, {0x1d552, 0x1d6a5}, {0x1d6a8, 0x1d6c0},
  {0x1d6c2, 0x1d6da}, {0x1d6dc, 0x1d6fa}, {0x1d6fc, 0x1d714}, {0x1d716, 0x1d734}, {0x1d736, 0x1d74e}, {0x1d750, 0x1d76e}, {0x1d770, 0x1d788}, {0x1d78a, 0x1d7a8},
  {0x1d7aa, 0x1d7c2}, {0x1d7c4, 0x1d7cb}, {0x1d7ce, 0x1d7ff}, {0x1df00, 0x1df1e}, {0x1df25, 0x1df2a}, {0x1e030, 0x1e06d}, {0x1e100, 0x1e12c}, {0x1e137, 0x1e13d},
  {0x1e140, 0x1e149}, {0x1e14e, 0x1e14e}, {0x1e290, 0x1e2ad}, {0x1e2c0, 0x1e2eb}, {0x1e2f0, 0x1e2f9}, {0x1e4d0, 0x1e4eb}, {0x1e4f0, 0x1e4f9}, {0x1e5d0, 0x1e5ed},
  {0x1e5f0, 0x1e5fa}, {0x1e7e0, 0x1e7e6}, {0x1e7e8, 0x1e7eb}, {0x1e7ed, 0x1e7ee}, {0x1e7f0, 0x1e7fe}, {0x1e800, 0x1e8c4}, {0x1e8c7, 0x1e8cf}, {0x1e900, 0x1e943},
  {0x1e94b, 0x1e94b}, {0x1e950, 0x1e959}, {0x1ec71, 0x1ecab}, {0x1ecad, 0x1ecaf}, {0x1ecb1, 0x1ecb4}, {0x1ed01, 0x1ed2d}, {0x1ed2f, 0x1ed3d}, {0x1ee00, 0x1ee03},
  {0x1ee05, 0x1ee1f}, {0x1ee21, 0x1ee22}, {0x1ee24, 0x1ee24}, {0x1ee27, 0x1ee27}, {0x1ee29, 0x1ee32}, {0x1ee34, 0x1ee37}, {0x1ee39, 0x1ee39}, {0x1ee3b, 0x1ee3b},
  {0x1ee42, 0x1ee42}, {0x1ee47, 0x1ee47}, {0x1ee49, 0x1ee49}, {0x1ee4b, 0x1ee4b}, {0x1ee4d, 0x1ee4f}, {0x1ee51, 0x1ee52}, {0x1ee54, 0x1ee54}, {0x1ee57, 0x1ee57},
  {0x1ee59, 0x1ee59}, {0x1ee5b, 0x1ee5b}, {0x1ee5d, 0x1ee5d}, {0x1ee5f, 0x1ee5f}, {0x1ee61, 0x1ee62}, {0x1ee64, 0x1ee64}, {0x1ee67, 0x1ee6a}, {0x1ee6c, 0x1ee72},
  {0x1ee74, 0x1ee77}, {0x1ee79, 0x1ee7c}, {0x1ee7e, 0x1ee7e}, {0x1ee80, 0x1ee89}, {0x1ee8b, 0x1ee9b}, {0x1eea1, 0x1eea3}, {0x1eea5, 0x1eea9}, {0x1eeab, 0x1eebb},
  {0x1f100, 0x1f10c}, {0x1fbf0, 0x1fbf9}, {0x20000, 0x2a6df}, {0x2a700, 0x2b739}, {0x2b740, 0x2b81d}, {0x2b820, 0x2cea1}, {0x2ceb0, 0x2ebe0}, {0x2ebf0, 0x2ee5d},
  {0x2f800, 0x2fa1d}, {0x30000, 0x3134a}, {0x31350, 0x323af},
};

// matches [0-9_]
#define ODIN_NUMBER_SET_DIGITS_LEN (2)
static const TSCharacterRange odin_number_set_digits[] = {
  {'0', '9'}, {'_', '_'},
};

// matches [0-9a-fA-F_]
#define ODIN_NUMBER_SET_ALL_DIGITS_LEN (4)
static const TSCharacterRange odin_number_set_all_digits[] = {
  {'0', '9'}, {'A', 'F'}, {'_', '_'}, {'a', 'f'},
};

// matches [a-z_]
#define ODIN_KEYWORD_SET_LETTERS_LEN (2)
static const TSCharacterRange odin_keyword_set_letters[] = {
  {'_', '_'}, {'a', 'z'},
};

//
// krnowak: hash map for keywords, attributes, directives
//
// Generated APIs: struct OdinKwad, odin_kwad_lookup,
// ODIN_KWAD_MAX_WORD_LENGTH.
//

#include "hash/odin.c"

#define ODIN_KWAD_LENGTH_POW_2 32
typedef struct OdinKwad OdinKwad;

// Power of 2 be at least max length + 1 for the null terminator.
GB_STATIC_ASSERT(ODIN_KWAD_LENGTH_POW_2 > ODIN_KWAD_MAX_WORD_LENGTH);

// Check if power of 2 is not excessive.
GB_STATIC_ASSERT((ODIN_KWAD_LENGTH_POW_2 >> 1) <= ODIN_KWAD_MAX_WORD_LENGTH);

// krnowak: lexer helpers

static inline bool
odin_eof(TSLexer *lexer) {
  return lexer->eof(lexer);
}

static inline void
odin_mark_end(TSLexer *lexer) {
  lexer->mark_end(lexer);
}

static inline void
odin_advance(TSLexer *lexer, bool skip) {
  lexer->advance(lexer, skip);
}

static inline void
odin_consume(TSLexer *lexer) {
  odin_advance(lexer, false);
}

static inline void
odin_skip(TSLexer *lexer) {
  odin_advance(lexer, true);
}

#define ODIN_RET_ON_EOF(lexer, ret_val) \
  do { \
    if (odin_eof(lexer)) { return (ret_val); }\
  } while (0)

#define ODIN_RETF_ON_EOF(lexer) ODIN_RET_ON_EOF(lexer, false)
#define ODIN_RETT_ON_EOF(lexer) ODIN_RET_ON_EOF(lexer, true)

#define LOG_LEXER(lexer, ...) lexer->log((lexer), __VA_ARGS__)

//
// krnowak: whitespace skipping
//

typedef enum {
  ODIN_SKIP_NEWLINES,
  ODIN_NO_SKIP_NEWLINES,
} OdinSkipNewlines;

// Returns false on syntax error. This happens only when backslash is
// not followed by a newline.
static bool
odin_skip_whitespace(TSLexer *lexer, OdinSkipNewlines skip_newlines) {
  ODIN_RETT_ON_EOF(lexer);

  for (;;) {
    while (iswspace(lexer->lookahead)) {
      if (skip_newlines == ODIN_NO_SKIP_NEWLINES && lexer->lookahead == '\n') {
        return true;
      }
      odin_skip(lexer);
      ODIN_RETT_ON_EOF(lexer);
    }
    if (lexer->lookahead != '\\') {
      break;
    }
    odin_skip(lexer);
    if (odin_eof(lexer) || lexer->lookahead != '\n') {
      return false;
    }
    odin_skip(lexer);
    ODIN_RETT_ON_EOF(lexer);
    // This loop stinks - single backslash can consume an arbitrary
    // amount of newlines if newlines are consecutive or separated
    // only by another whitespaces. This is current odin's
    // behaviour. And apparently not a bug.
    while (iswspace(lexer->lookahead)) {
      odin_skip(lexer);
      ODIN_RETT_ON_EOF(lexer);
    }
  }
  return true;
}

#define ODIN_SKIP_WHITESPACE_OR_RETF(lexer, skip_newlines) \
  do { \
    if (!odin_skip_whitespace(lexer, skip_newlines)) { \
      return false;\
    } \
  } while (0)

//
// krnowak: scanner
//

typedef struct {
  bool prev_token_may_add_semicolon;
  bool added_semicolon_at_eof;
} OdinScanner;

static inline OdinScanner *
odin_scanner_create(void) {
  OdinScanner *scanner = ts_calloc(1, sizeof(OdinScanner));

  return scanner;
}

static inline void odin_scanner_destroy(OdinScanner *scanner) {
  ts_free(scanner);
}

#define ODIN_SERIALIZATION_BUFFER_SIZE 1
GB_STATIC_ASSERT(ODIN_SERIALIZATION_BUFFER_SIZE <= TREE_SITTER_SERIALIZATION_BUFFER_SIZE);

#define BOOL_TO_BIT(b, i) ((b) ? (1 << i) : 0)
#define VALUE_TO_BIT_FIELD_8(b, w, o) ((((uint8_t)(b)) & ((1 << w) - 1)) << o)

static inline unsigned
odin_scanner_serialize(OdinScanner *scanner, char *buffer) {
  buffer[0] = BOOL_TO_BIT(scanner->prev_token_may_add_semicolon, 0) |
              BOOL_TO_BIT(scanner->added_semicolon_at_eof, 1);
  return ODIN_SERIALIZATION_BUFFER_SIZE;
}

#undef VALUE_TO_BIT_FIELD_8
#undef BOOL_TO_BIT

#define BIT_TO_BOOL(b, i) (((b) & (1 << i)) == (1 << i))
#define BIT_FIELD_8_TO_VALUE(t, b, w, o) (t)((((uint8_t)(b)) >> o) & ((1 << w) - 1))

static inline void
odin_scanner_deserialize(OdinScanner *scanner, const char *buffer, unsigned length) {
  if (length >= ODIN_SERIALIZATION_BUFFER_SIZE) {
    scanner->prev_token_may_add_semicolon = BIT_TO_BOOL(buffer[0], 0);
    scanner->added_semicolon_at_eof = BIT_TO_BOOL(buffer[0], 1);
  } else {
    scanner->prev_token_may_add_semicolon = false;
    scanner->added_semicolon_at_eof = false;
  }
}

#undef BIT_FIELD_8_TO_VALUE
#undef BIT_TO_BOOL

static inline bool
odin_is_kwad_char(TSLexer *lexer) {
  return set_contains(odin_keyword_set_letters, ODIN_KEYWORD_SET_LETTERS_LEN, lexer->lookahead);
}

static bool
odin_handle_ml_comment_star(TSLexer *lexer, bool skip, int *level) {
  do {
    odin_advance(lexer, skip);
    ODIN_RETF_ON_EOF(lexer);
    if (lexer->lookahead == '/') {
      odin_advance(lexer, skip);
      (*level)--;
      break;
    }
  } while (lexer->lookahead == '*');
  return true;
}

static bool
odin_handle_ml_comment_slash(TSLexer *lexer, bool skip, int *level) {
  do {
    odin_advance(lexer, skip);
    ODIN_RETF_ON_EOF(lexer);
    if (lexer->lookahead == '*') {
      odin_advance(lexer, skip);
      (*level)++;
      break;
    }
  } while (lexer->lookahead == '/');
  return true;
}

static bool
odin_scanner_scan(OdinScanner *scanner, TSLexer *lexer, const bool *valid_symbols) {
  LOG_LEXER(lexer, "scanner state:");
  LOG_LEXER(lexer, "  prev_token_may_add_semicolon: %d", scanner->prev_token_may_add_semicolon ? 1 : 0);
  LOG_LEXER(lexer, "  added_semicolon_at_eof: %d", scanner->added_semicolon_at_eof);
  LOG_LEXER(lexer, "valid symbols:");
  if (valid_symbols[ODIN_INVALID]) {
    LOG_LEXER(lexer, "  all of them (error recovery)");
  } else {
    int idx;
    for (idx = 0; idx < ODIN_LAST_SYMBOL; idx++) {
      if (valid_symbols[idx]) {
        LOG_LEXER(lexer, "  %s", odin_symbol_strings[idx]);
      }
    }
  }

  {
    ODIN_SKIP_WHITESPACE_OR_RETF(lexer, ODIN_NO_SKIP_NEWLINES);
    if (odin_eof(lexer)) {
      if (scanner->prev_token_may_add_semicolon &&
          valid_symbols[ODIN_IMPLICIT_SEMICOLON] &&
          !scanner->added_semicolon_at_eof) {
        LOG_LEXER(lexer, "adding implicit semicolon at eof");
        lexer->result_symbol = ODIN_IMPLICIT_SEMICOLON;
        scanner->added_semicolon_at_eof = true;
        return true;
      }
      return false;
    }
    switch (lexer->lookahead) {
    case '\n':
      if (valid_symbols[ODIN_IMPLICIT_SEMICOLON] ||
          valid_symbols[ODIN_WIDE_IMPLICIT_SEMICOLON]) {
        if (scanner->prev_token_may_add_semicolon) {
          LOG_LEXER(lexer, "adding implicit semicolon at newline");
          odin_consume(lexer);
          if (!valid_symbols[ODIN_WIDE_IMPLICIT_SEMICOLON]) {
            // valid_symbols[ODIN_IMPLICIT_SEMICOLON] must be true
            // here
            lexer->result_symbol = ODIN_IMPLICIT_SEMICOLON;
            return true;
          }
          // valid_symbols[ODIN_WIDE_IMPLICIT_SEMICOLON] is true, the
          // same for ODIN_IMPLICIT_SEMICOLON might not be the case
          // here

#define ODIN_RET_I_S_IF_VALID(lexer) \
  do { \
    if (valid_symbols[ODIN_IMPLICIT_SEMICOLON]) { \
      lexer->result_symbol = ODIN_IMPLICIT_SEMICOLON; \
      return true; \
    } \
    return false; \
  } while (0)

          odin_mark_end(lexer);
          for (;;) {
            if (!odin_skip_whitespace(lexer, ODIN_NO_SKIP_NEWLINES) || odin_eof(lexer)) {
              ODIN_RET_I_S_IF_VALID(lexer);
            }

#define ODIN_I_S_RET_ON_EOF(lexer) \
  do { \
    if (odin_eof(lexer)) { \
      ODIN_RET_I_S_IF_VALID(lexer); \
    } \
  } while (0)

            switch (lexer->lookahead) {
            case '\n':
              lexer->result_symbol = ODIN_WIDE_IMPLICIT_SEMICOLON;
              return true;

            case '/':
              odin_skip(lexer);
              ODIN_I_S_RET_ON_EOF(lexer);
              switch (lexer->lookahead) {
              case '/':
                // not looking further, there will be a newline (or an
                // eof, does not matter), so it is a wide implicit
                // semicolon
                lexer->result_symbol = ODIN_WIDE_IMPLICIT_SEMICOLON;
                return true;

              case '*':
                {
                  // urgh, a possibly multiline comment, but could as well
                  // be a short comment like /* A */, as soon as we find a
                  // newline in the comment, we have a wide implicit
                  // semicolon
                  odin_skip(lexer);
                  int level = 1;
                  while (level > 0) {
                    ODIN_I_S_RET_ON_EOF(lexer);
                    switch (lexer->lookahead) {
                    case '*':
                      if (!odin_handle_ml_comment_star(lexer, true, &level)) {
                        ODIN_RET_I_S_IF_VALID(lexer);
                      }
                      break;
                    case '/':
                      if (!odin_handle_ml_comment_slash(lexer, true, &level)) {
                        ODIN_RET_I_S_IF_VALID(lexer);
                      }
                      break;
                    case '\n':
                      // not looking further, it is a multiline comment
                      // indeed, so it is enough for the wide implicit
                      // semicolon
                      lexer->result_symbol = ODIN_WIDE_IMPLICIT_SEMICOLON;
                      return true;
                    default:
                      odin_skip(lexer);
                      break;
                    }
                  }
                }
                break;
              default:
                // not a single line comment nor multi line comment,
                // looks like division or something, no wide implicit
                // semicolon
                ODIN_RET_I_S_IF_VALID(lexer);
              } // end maybe comment switch
              break;
            default:
              // not a newline, not a comment, no wide implicit
              // semicolon here
              ODIN_RET_I_S_IF_VALID(lexer);
            } // end next lookahead switch
          } // end for(;;)
        } // else newline is whitespace to ignore
      }
      break;
    case '}':
      // This is to allow the snippet below to be parsed as a return
      // statement inside the block statement:
      //
      // {
      //   return a, b,
      // }
      //
      // The last comma does not set the prev_token_may_add_semicolon,
      // so we don't check for it here.
      if (valid_symbols[ODIN_IMPLICIT_SEMICOLON]) {
        lexer->result_symbol = ODIN_IMPLICIT_SEMICOLON;
        return true;
      } else {
        // just a closing brace
      }
      break;
    }
  }

  // Rest of the handling can go here.

  ODIN_SKIP_WHITESPACE_OR_RETF(lexer, ODIN_SKIP_NEWLINES);
  ODIN_RETF_ON_EOF(lexer);

  // Identifiers, keywords, directives and attributes.
  if (valid_symbols[ODIN_IDENTIFIER]) {
    LOG_LEXER(lexer, "trying an identifier or either a keyword, attribute or directive");
    // Meh, convoluted case.
    ODIN_RETF_ON_EOF(lexer);
    // We assume that identifier's character set is a superset of
    // keyword's/attribute's/directive's character set.
    if (set_contains(odin_identifier_set_letters, ODIN_IDENTIFIER_SET_LETTERS_LEN, lexer->lookahead)) {
      if (!odin_is_kwad_char(lexer)) {
        LOG_LEXER(lexer, "Non keyword/attribute/directive lookahead found, only identifier possible at this point");
        odin_consume(lexer);
        while (!odin_eof(lexer) && set_contains(odin_identifier_set_letters_digits, ODIN_IDENTIFIER_SET_LETTERS_DIGITS_LEN, lexer->lookahead)) {
          odin_consume(lexer);
        }

        LOG_LEXER(lexer, "identifier found");
        lexer->result_symbol = ODIN_IDENTIFIER;
        lexer->mark_end(lexer);
        return true;
      }

      char kwad[ODIN_KWAD_LENGTH_POW_2];
      uint16_t kwad_idx = 0;
      // krnowak: Assigning i32 lookahead to char here is fine, we
      // know that current lookahead is a kwad char, which means
      // ascii.
      kwad[kwad_idx] = lexer->lookahead;
      kwad_idx++;
      odin_consume(lexer);
      while (!odin_eof(lexer) && set_contains(odin_identifier_set_letters_digits, ODIN_IDENTIFIER_SET_LETTERS_DIGITS_LEN, lexer->lookahead)) {
        if (kwad_idx < ODIN_KWAD_MAX_WORD_LENGTH) {
          if (odin_is_kwad_char(lexer)) {
            // krnowak: Assigning i32 lookahead to char here is fine,
            // we know that current lookahead is a kwad char, which
            // means ascii.
            kwad[kwad_idx] = lexer->lookahead;
            kwad_idx++;
          } else {
            LOG_LEXER(lexer, "Non keyword/attribute/directive lookahead found, only identifier possible at this point");
            kwad_idx = ODIN_KWAD_MAX_WORD_LENGTH;
          }
        }
        odin_consume(lexer);
      }

      if (kwad_idx <= ODIN_KWAD_MAX_WORD_LENGTH) {
        kwad[kwad_idx] = '\0';
        LOG_LEXER(lexer, "checking if %s is a keyword/attribute/directive", kwad);
        //uint16_t valid_symbols_idx;
        //OdinTokenType kwad_type;
        const OdinKwad *kwad_entry = odin_kwad_lookup(kwad, kwad_idx);
        //if (odin_kwad_hash_map_get(scanner->kwads, kwad, kwad_idx, &valid_symbols_idx, &kwad_type)) {
        if (kwad_entry != 0) {
          //if (!valid_symbols[valid_symbols_idx]) {
          if (!valid_symbols[kwad_entry->valid_symbols_idx]) {
            //if (kwad_type == OdinTokenKeyword) {
            if (kwad_entry->type == OdinTokenKeyword) {
              LOG_LEXER(lexer, "%s is a keyword, but not valid in this context", kwad);
              return false;
            }
            // attribute name or directive name can be an identifier
            // too
            LOG_LEXER(lexer, "%s is an attribute/directive, but no attributes or directives are valid in this context, so it is actually an identifier", kwad);
            lexer->result_symbol = ODIN_IDENTIFIER;
            lexer->mark_end(lexer);
            return true;
          }
          LOG_LEXER(lexer, "%s is a keyword/attribute/directive", kwad);

          lexer->result_symbol = kwad_entry->valid_symbols_idx;
          lexer->mark_end(lexer);
          return true;
        }
      }

      LOG_LEXER(lexer, "%s is not a keyword/attribute/directive, making it an identifier", kwad);
      lexer->result_symbol = ODIN_IDENTIFIER;
      odin_mark_end(lexer);
      return true;
    }
  } else {
    // Maybe only keyword/attribute/directive valid.
    LOG_LEXER(lexer, "trying for keyword/attribute/directive only");
    if (odin_is_kwad_char(lexer)) {
      char kwad[ODIN_KWAD_MAX_WORD_LENGTH];
      uint16_t kwad_idx = 0;
      // krnowak: Assigning i32 lookahead to char here is fine, we
      // know that current lookahead is a kwad char, which means
      // ascii.
      kwad[kwad_idx] = lexer->lookahead;
      kwad_idx++;
      odin_consume(lexer);
      while (!odin_eof(lexer) && odin_is_kwad_char(lexer)) {
        if (kwad_idx >= ODIN_KWAD_MAX_WORD_LENGTH) {
          return false;
        }
        // krnowak: Assigning i32 lookahead to char here is fine, we
        // know that current lookahead is a kwad char, which means
        // ascii.
        kwad[kwad_idx] = lexer->lookahead;
        kwad_idx++;
        odin_consume(lexer);
      }
      kwad[kwad_idx] = '\0';
      //uint16_t valid_symbols_idx;
      //OdinTokenType type;
      const OdinKwad *kwad_entry = odin_kwad_lookup(kwad, kwad_idx);
      if (kwad_entry == NULL) {
      //if (!odin_kwad_hash_map_get(scanner->kwads, kwad, kwad_idx, &valid_symbols_idx, &type)) {
        LOG_LEXER(lexer, "%s is not a keyword/attribute/directive", kwad);
        return false;
      }
      if (!valid_symbols[kwad_entry->valid_symbols_idx]) {
        LOG_LEXER(lexer, "%s is a keyword/attribute/directive, but not valid in this context", kwad);
        return false;
      }

      LOG_LEXER(lexer, "%s is a keyword/attribute/directive", kwad);
      lexer->result_symbol = kwad_entry->valid_symbols_idx;
      lexer->mark_end(lexer);
      return true;
    }
  }

  if (valid_symbols[ODIN_INTEGER] || valid_symbols[ODIN_FLOAT] || valid_symbols[ODIN_IMAG]) {
    TSSymbol symbol = ODIN_INVALID;
    if ((lexer->lookahead >= '0') && (lexer->lookahead <= '9')) {
      symbol = ODIN_INTEGER;
      // krnowak: Assigning i32 lookahead to char here is fine, we
      // know that current lookahead is a char between 0 and 9, which
      // means ascii.
      char digit = lexer->lookahead;
      odin_consume(lexer);
      if (odin_eof(lexer)) {
        goto number_submit_or_fail;
      }
      if (digit == '0') {
        switch (lexer->lookahead) {
        case 'b': case 'o': case 'd': case 'z': case 'x': case 'h':
          // base prefixed integer
          odin_consume(lexer);
          ODIN_RETF_ON_EOF(lexer);
          if (!set_contains(odin_number_set_all_digits, ODIN_NUMBER_SET_ALL_DIGITS_LEN, lexer->lookahead)) {
            return false;
          }
          odin_consume(lexer);
          if (!odin_eof(lexer)) {
            while (set_contains(odin_number_set_all_digits, ODIN_NUMBER_SET_ALL_DIGITS_LEN, lexer->lookahead)) {
              odin_consume(lexer);
              if (odin_eof(lexer)) {
                break;
              }
            }
          }
          goto number_submit_or_fail;
        }
      }
      while (set_contains(odin_number_set_digits, ODIN_NUMBER_SET_DIGITS_LEN, lexer->lookahead)) {
        odin_consume(lexer);
        if (odin_eof(lexer)) {
          goto number_submit_or_fail;
        }
      }
    }
    if (lexer->lookahead == '.') {
      if (symbol == ODIN_INVALID) {
        // Either a number that starts with a period, period itself or
        // ellipsis.
        odin_consume(lexer);
        if (odin_eof(lexer)) {
          if (valid_symbols[ODIN_PERIOD]) {
            lexer->result_symbol = ODIN_PERIOD;
            return true;
          }
          // Not valid in this context.
          return false;
        }
        switch (lexer->lookahead) {
        case '.':
          // Jump into the middle of ellipsis handling down below.
          goto second_dot_spotted;
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
          // A floating point number, we will parse it below.
          break;
        default:
          // Just a period.
          if (valid_symbols[ODIN_PERIOD]) {
            lexer->result_symbol = ODIN_PERIOD;
            return true;
          }
          // Not valid in this context.
          return false;
        }
      } else {
        // Let's keep it as an integer for now. It may turn into a
        // floating point number, or could remain an integer followed
        // by some range token.
        odin_mark_end(lexer);
        odin_consume(lexer);
        if (odin_eof(lexer)) {
          symbol = ODIN_FLOAT;
          odin_mark_end(lexer);
          goto number_submit_or_fail;
        }
        if (lexer->lookahead == '.') {
          // Integer followed by ellipsis.
          goto number_submit_or_fail;
        }
        odin_mark_end(lexer);
      }
      // At this point we expect to have an actual fractional part,
      // even if possibly empty.
      symbol = ODIN_FLOAT;
      while (set_contains(odin_number_set_digits, ODIN_NUMBER_SET_DIGITS_LEN, lexer->lookahead)) {
        odin_consume(lexer);
        odin_mark_end(lexer);
        if (odin_eof(lexer)) {
          goto number_submit_or_fail;
        }
      }
    }
    if (symbol != ODIN_INVALID) {
      if ((lexer->lookahead == 'e') || (lexer->lookahead == 'E')) {
        odin_consume(lexer);
        odin_mark_end(lexer);
        ODIN_RETF_ON_EOF(lexer);
        if ((lexer->lookahead == '-') || (lexer->lookahead == '+')) {
          odin_consume(lexer);
          odin_mark_end(lexer);
          ODIN_RETF_ON_EOF(lexer);
        }
        while (set_contains(odin_number_set_digits, ODIN_NUMBER_SET_DIGITS_LEN, lexer->lookahead)) {
          odin_consume(lexer);
          odin_mark_end(lexer);
          if (odin_eof(lexer)) {
            goto number_submit_or_fail;
          }
        }
      }
      if ((lexer->lookahead == 'i') ||
          (lexer->lookahead == 'j') ||
          (lexer->lookahead == 'k')) {
        odin_consume(lexer);
        odin_mark_end(lexer);
        symbol = ODIN_IMAG;
      }
    number_submit_or_fail:
      if (valid_symbols[symbol]) {
        lexer->result_symbol = symbol;
        return true;
      }
      return false;
    }
  }

#define ODIN_RET_SYMBOL(lexer, symbol) \
  do { \
    if (valid_symbols[symbol]) { \
      lexer->result_symbol = symbol; \
      return true; \
    } \
    return false; \
  } while (0)

  typedef enum {
    ODIN_CASE_INVALID,
    ODIN_CASE_STRING,
    ODIN_CASE_RUNE,
    ODIN_CASE_PERIODS,
    ODIN_CASE_DASH,
    ODIN_CASE_SLASH,
    ODIN_CASE_AMPERSAND,
    ODIN_CASE_HASH,
    ODIN_CASE_STANDALONE_TOKEN, // uses initial_lookahead, symbol
    ODIN_CASE_OP_WITH_EQ_ONLY, // uses initial_lookahead, symbol
    ODIN_CASE_OP_WITH_DUP_AND_EQ, // uses initial_lookahead, symbol
  } OdinCase;

  OdinCase odin_case = ODIN_CASE_INVALID;
  char initial_lookahead = 0;
  TSSymbol symbol = ODIN_INVALID;
  TSSymbol symbol2 = ODIN_INVALID;
  TSSymbol eq_symbol = ODIN_INVALID;
  TSSymbol eq_symbol2 = ODIN_INVALID;

  switch (lexer->lookahead) {
  case '`':
  case '"':
    odin_case = ODIN_CASE_STRING;
    break;

  case '\'':
    odin_case = ODIN_CASE_RUNE;
    break;

  case '.':
    odin_case = ODIN_CASE_PERIODS;
    break;

  case '-':
    odin_case = ODIN_CASE_DASH;
    break;

  case '/':
    odin_case = ODIN_CASE_SLASH;
    break;

  case '&':
    odin_case = ODIN_CASE_AMPERSAND;
    break;

  case '#':
    odin_case = ODIN_CASE_HASH;
    break;

  // standalone, all 1 chars: ODIN_QUESTION, ODIN_POINTER,
  // ODIN_CLOSEPAREN, ODIN_CLOSEBRACKET, ODIN_CLOSEBRACE, ODIN_AT,
  // ODIN_DOLLAR, ODIN_OPENPAREN, ODIN_OPENBRACKET, ODIN_OPENBRACE,
  // ODIN_COLON, ODIN_SEMICOLON
#define ODIN_CASE_STANDALONE_TOKEN_CASE(c, sym) \
  case c: \
    odin_case = ODIN_CASE_STANDALONE_TOKEN; \
    symbol = sym; \
    break
  ODIN_CASE_STANDALONE_TOKEN_CASE('?', ODIN_QUESTION);
  ODIN_CASE_STANDALONE_TOKEN_CASE('^', ODIN_POINTER);
  ODIN_CASE_STANDALONE_TOKEN_CASE(')', ODIN_CLOSEPAREN);
  ODIN_CASE_STANDALONE_TOKEN_CASE(']', ODIN_CLOSEBRACKET);
  ODIN_CASE_STANDALONE_TOKEN_CASE('}', ODIN_CLOSEBRACE);
  ODIN_CASE_STANDALONE_TOKEN_CASE('@', ODIN_AT);
  ODIN_CASE_STANDALONE_TOKEN_CASE('$', ODIN_DOLLAR);
  ODIN_CASE_STANDALONE_TOKEN_CASE('(', ODIN_OPENPAREN);
  ODIN_CASE_STANDALONE_TOKEN_CASE('[', ODIN_OPENBRACKET);
  ODIN_CASE_STANDALONE_TOKEN_CASE('{', ODIN_OPENBRACE);
  ODIN_CASE_STANDALONE_TOKEN_CASE(':', ODIN_COLON);
  ODIN_CASE_STANDALONE_TOKEN_CASE(';', ODIN_SEMICOLON);
  ODIN_CASE_STANDALONE_TOKEN_CASE(',', ODIN_COMMA);
#undef ODIN_CASE_STANDALONE_TOKEN_CASE

  // ODIN_EQ(=): ODIN_CMPEQ(==)
  // ODIN_NOT(!): ODIN_NOTEQ(!=)
  // ODIN_MUL(*): ODIN_MULEQ(*=)
  // ODIN_XOR(~): ODIN_XOREQ(~=)
  // ODIN_ADD(+): ODIN_ADDEQ(+=)
#define ODIN_CASE_OP_WITH_EQ_ONLY_CASE(c, sym, eq_sym) \
  case c: \
    odin_case = ODIN_CASE_OP_WITH_EQ_ONLY; \
    symbol = sym; \
    eq_symbol = eq_sym; \
    break
  ODIN_CASE_OP_WITH_EQ_ONLY_CASE('=', ODIN_EQ, ODIN_CMPEQ);
  ODIN_CASE_OP_WITH_EQ_ONLY_CASE('!', ODIN_NOT, ODIN_NOTEQ);
  ODIN_CASE_OP_WITH_EQ_ONLY_CASE('*', ODIN_MUL, ODIN_MULEQ);
  ODIN_CASE_OP_WITH_EQ_ONLY_CASE('~', ODIN_XOR, ODIN_XOREQ);
  ODIN_CASE_OP_WITH_EQ_ONLY_CASE('+', ODIN_ADD, ODIN_ADDEQ);
#undef ODIN_CASE_OP_WITH_EQ_ONLY_CASE

  // ODIN_MOD(%): ODIN_MODMOD(%%), ODIN_MODEQ(%=), ODIN_MODMODEQ(%%=)
  // ODIN_OR(|): ODIN_CMPOR(||), ODIN_OREQ(|=), ODIN_CMPOREQ(||=)
  // ODIN_LT(<): ODIN_SHL(<<), ODIN_LTEQ(<=), ODIN_SHLEQ(<<=)
  // ODIN_GT(>): ODIN_SHR(>>), ODIN_GTEQ(>=), ODIN_SHREQ(>>=)
#define ODIN_CASE_OP_WITH_DUP_AND_EQ_CASE(c, sym, sym2, eq_sym, eq_sym2) \
  case c: \
    odin_case = ODIN_CASE_OP_WITH_DUP_AND_EQ; \
    initial_lookahead = c; \
    symbol = sym; \
    symbol2 = sym2; \
    eq_symbol = eq_sym; \
    eq_symbol2 = eq_sym2; \
    break
  ODIN_CASE_OP_WITH_DUP_AND_EQ_CASE('%', ODIN_MOD, ODIN_MODMOD, ODIN_MODEQ, ODIN_MODMODEQ);
  ODIN_CASE_OP_WITH_DUP_AND_EQ_CASE('|', ODIN_OR, ODIN_CMPOR, ODIN_OREQ, ODIN_CMPOREQ);
  ODIN_CASE_OP_WITH_DUP_AND_EQ_CASE('<', ODIN_LT, ODIN_SHL, ODIN_LTEQ, ODIN_SHLEQ);
  ODIN_CASE_OP_WITH_DUP_AND_EQ_CASE('>', ODIN_GT, ODIN_SHR, ODIN_GTEQ, ODIN_SHREQ);
#undef ODIN_CASE_OP_WITH_DUP_AND_EQ_CASE
  }

  switch (odin_case) {
  case ODIN_CASE_INVALID:
    LOG_LEXER(lexer, "%c is not a valid character", lexer->lookahead);
    break;

  case ODIN_CASE_STRING:
    if (!valid_symbols[ODIN_STRING]) {
      return false;
    } else {
      // krnowak: Assigning i32 lookahead to char here is fine, we
      // know that current lookahead is either " or `, which means
      // ascii.
      char quote = lexer->lookahead;
      bool is_raw_string = (quote == '`');
      bool allow_newline = is_raw_string;
      bool backslash_escapes = !is_raw_string;
      int32_t c;
      odin_consume(lexer);
      for (;;) {
        ODIN_RETF_ON_EOF(lexer);
        c = lexer->lookahead;
        switch (c) {
        case '\n':
          if (!allow_newline) {
            return false;
          }
          odin_consume(lexer);
          break;
        case '\\':
          odin_consume(lexer);
          if (backslash_escapes) {
            // Make sure that there is one more char available to
            // consume and eat it, so we go past the possible escaped
            // quote.
            ODIN_RETF_ON_EOF(lexer);
            odin_consume(lexer);
          }
          break;
        case '"':
        case '`':
          odin_consume(lexer);
          if (c == quote) {
            lexer->result_symbol = ODIN_STRING;
            odin_mark_end(lexer);
            return true;
          }
          break;
        default:
          odin_consume(lexer);
          break;
        }
      }
    }
    break;

  case ODIN_CASE_RUNE:
    if (!valid_symbols[ODIN_RUNE]) {
      return false;
    } else {
      odin_consume(lexer);
      for (;;) {
        ODIN_RETF_ON_EOF(lexer);
        switch (lexer->lookahead) {
        case '\n':
          return false;

        case '\\':
          odin_consume(lexer);
          // Make sure that there is one more char available to
          // consume and eat it, so we go past the possible escaped
          // quote.
          ODIN_RETF_ON_EOF(lexer);
          odin_consume(lexer);
          break;

        case '\'':
          odin_consume(lexer);
          lexer->result_symbol = ODIN_RUNE;
          odin_mark_end(lexer);
          return true;

        default:
          odin_consume(lexer);
          break;
        }
      }
    }
    break;

  // ODIN_PERIOD(.): ODIN_ELLIPSIS(..), ODIN_RANGEHALF(..<), ODIN_RANGEFULL(..=)
  case ODIN_CASE_PERIODS:
    odin_consume(lexer);
    if (!odin_eof(lexer) &&
        (lexer->lookahead == '.')) {
    second_dot_spotted:
      odin_consume(lexer);
      if (!odin_eof(lexer)) {
        switch (lexer->lookahead) {
        case '<':
          odin_consume(lexer);
          ODIN_RET_SYMBOL(lexer, ODIN_RANGEHALF);
        case '=':
          odin_consume(lexer);
          ODIN_RET_SYMBOL(lexer, ODIN_RANGEFULL);
        }
      }
      ODIN_RET_SYMBOL(lexer, ODIN_ELLIPSIS);
    }
    ODIN_RET_SYMBOL(lexer, ODIN_PERIOD);

  // ODIN_SUB(-): ODIN_SUBEQ(-=), ODIN_ARROWRIGHT(->), ODIN_UNINIT(---)
  case ODIN_CASE_DASH:
    odin_consume(lexer);
    if (!odin_eof(lexer)) {
      switch (lexer->lookahead) {
      case '>':
        odin_consume(lexer);
        ODIN_RET_SYMBOL(lexer, ODIN_ARROWRIGHT);
      case '=':
        odin_consume(lexer);
        ODIN_RET_SYMBOL(lexer, ODIN_SUBEQ);
      case '-':
        odin_mark_end(lexer);
        odin_consume(lexer);
        if (!odin_eof(lexer) && lexer->lookahead == '-') {
          odin_consume(lexer);
          if (valid_symbols[ODIN_UNINIT]) {
            odin_mark_end(lexer);
            lexer->result_symbol = ODIN_UNINIT;
            return true;
          }
        }
      }
    }
    ODIN_RET_SYMBOL(lexer, ODIN_SUB);

  // ODIN_QUO(/): ODIN_SL_COMMENT(//), ODIN_ML_COMMENT(/*), ODIN_QUOEQ(/=)
  case ODIN_CASE_SLASH:
    odin_consume(lexer);
    if (!odin_eof(lexer)) {
      switch (lexer->lookahead) {
      case '=':
        odin_consume(lexer);
        ODIN_RET_SYMBOL(lexer, ODIN_QUOEQ);
      case '/':
        odin_consume(lexer);
        while (!odin_eof(lexer) && lexer->lookahead != '\n') {
          odin_consume(lexer);
        }
        ODIN_RET_SYMBOL(lexer, ODIN_SL_COMMENT);
      case '*':
        odin_consume(lexer);
        int level = 1;
        while (level > 0) {
          ODIN_RETF_ON_EOF(lexer);
          switch (lexer->lookahead) {
          case '*':
            if (!odin_handle_ml_comment_star(lexer, false, &level)) {
              return false;
            }
            break;
          case '/':
            if (!odin_handle_ml_comment_slash(lexer, false, &level)) {
              return false;
            }
            break;
          default:
            odin_consume(lexer);
            break;
          }
        }
        ODIN_RET_SYMBOL(lexer, ODIN_ML_COMMENT);
      }
    }
    ODIN_RET_SYMBOL(lexer, ODIN_QUO);

  // ODIN_AND(&): ODIN_ANDEQ(&=), ODIN_ANDNOT(&~), ODIN_ANDNOTEQ(&~=), ODIN_CMPAND(&&), ODIN_CMPANDEQ(&&=)
  case ODIN_CASE_AMPERSAND:
    odin_consume(lexer);
    if (!odin_eof(lexer)) {
      switch (lexer->lookahead) {
      case '=':
        odin_consume(lexer);
        ODIN_RET_SYMBOL(lexer, ODIN_ANDEQ);
      case '~':
        odin_consume(lexer);
        if (!odin_eof(lexer) && lexer->lookahead == '=') {
          odin_consume(lexer);
          ODIN_RET_SYMBOL(lexer, ODIN_ANDNOTEQ);
        }
        ODIN_RET_SYMBOL(lexer, ODIN_ANDNOT);
      case '&':
        odin_consume(lexer);
        if (!odin_eof(lexer) && lexer->lookahead == '=') {
          odin_consume(lexer);
          ODIN_RET_SYMBOL(lexer, ODIN_CMPANDEQ);
        }
        ODIN_RET_SYMBOL(lexer, ODIN_CMPAND);
      }
    }
    ODIN_RET_SYMBOL(lexer, ODIN_AND);

  // ODIN_HASH(#): ODIN_SHEBANG(#!), ODIN_FILETAG(#+)
  case ODIN_CASE_HASH:
    odin_consume(lexer);
    if (!odin_eof(lexer)) {
      switch (lexer->lookahead) {
      case '!':
        odin_consume(lexer);
        while (!odin_eof(lexer) && lexer->lookahead != '\n') {
          odin_consume(lexer);
        }
        ODIN_RET_SYMBOL(lexer, ODIN_SHEBANG);
      case '+':
        odin_consume(lexer);
        odin_mark_end(lexer);
        bool done = false;
        while (!done && !odin_eof(lexer)) {
          switch (lexer->lookahead) {
          case '\n':
            done = true;
            break;
          case '/':
            odin_consume(lexer);
            if (odin_eof(lexer) ||
                (lexer->lookahead == '\n')) {
              odin_mark_end(lexer);
              done = true;
            } else if ((lexer->lookahead == '/') ||
                       (lexer->lookahead == '*')) {
              done = true;
            } else {
              odin_consume(lexer);
              odin_mark_end(lexer);
            }
            break;
          default:
            odin_consume(lexer);
            odin_mark_end(lexer);
            break;
          }
        }
        ODIN_RET_SYMBOL(lexer, ODIN_FILETAG);
      }
    }
    ODIN_RET_SYMBOL(lexer, ODIN_HASH);

  case ODIN_CASE_STANDALONE_TOKEN:
    odin_consume(lexer);
    ODIN_RET_SYMBOL(lexer, symbol);

  case ODIN_CASE_OP_WITH_EQ_ONLY:
    odin_consume(lexer);
    if (!odin_eof(lexer) &&
        lexer->lookahead == '=') {
      odin_consume(lexer);
      ODIN_RET_SYMBOL(lexer, eq_symbol);
    }
    ODIN_RET_SYMBOL(lexer, symbol);

  case ODIN_CASE_OP_WITH_DUP_AND_EQ:
    odin_consume(lexer);
    if (!odin_eof(lexer)) {
      if (lexer->lookahead == initial_lookahead) {
        odin_consume(lexer);
        if (!odin_eof(lexer) && (lexer->lookahead == '=')) {
          odin_consume(lexer);
          ODIN_RET_SYMBOL(lexer, eq_symbol2);
        }
        ODIN_RET_SYMBOL(lexer, symbol2);
      } else if (lexer->lookahead == '=') {
        odin_consume(lexer);
        ODIN_RET_SYMBOL(lexer, eq_symbol);
      }
    }
    ODIN_RET_SYMBOL(lexer, symbol);
  }

#undef ODIN_RET_SYMBOL

  return false;
}

//
// krnowak: tree-sitter entry points
//

void *
tree_sitter_odin_external_scanner_create() {
  return odin_scanner_create();
}

unsigned
tree_sitter_odin_external_scanner_serialize(void *payload, char *buffer) {
  OdinScanner *scanner = (OdinScanner *)payload;

  return odin_scanner_serialize(scanner, buffer);
}

void
tree_sitter_odin_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
  OdinScanner *scanner = (OdinScanner *)payload;

  odin_scanner_deserialize(scanner, buffer, length);
}

bool
tree_sitter_odin_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
  OdinScanner *scanner = (OdinScanner *)payload;
  bool result = odin_scanner_scan(scanner, lexer, valid_symbols);

  if (result) {
    if ((lexer->result_symbol == ODIN_IDENTIFIER) ||
        ((lexer->result_symbol >= ODIN_FIRST_SEMICOLON_KEYWORD) && (lexer->result_symbol <= ODIN_LAST_SEMICOLON_KEYWORD)) ||
        ((lexer->result_symbol >= ODIN_FIRST_SEMICOLON_OTHER_TERMINAL) && (lexer->result_symbol <= ODIN_LAST_SEMICOLON_OTHER_TERMINAL))) {
      scanner->prev_token_may_add_semicolon = true;
      LOG_LEXER(lexer, "set 'may add semicolon' flag");
    } else if ((lexer->result_symbol == ODIN_SL_COMMENT) || (lexer->result_symbol == ODIN_ML_COMMENT)) {
      // preserve semicolon status
      LOG_LEXER(lexer, "preserve 'may add semicolon' flag at %d", scanner->prev_token_may_add_semicolon ? 1 : 0);
    } else {
      scanner->prev_token_may_add_semicolon = false;
      LOG_LEXER(lexer, "clear 'may add semicolon' flag");
    }
  }

  return result;
}

void tree_sitter_odin_external_scanner_destroy(void *payload) {
  OdinScanner *scanner = (OdinScanner *)payload;
  free(scanner);
}

// TODO: keep it and document it or drop it
#ifdef _MSC_VER
#pragma warning(default : 4100)
#elif defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif
