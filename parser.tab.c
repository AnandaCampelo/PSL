/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"

void yyerror(const char *s);
int yylex(void);
extern FILE *yyin;
extern int yylineno;

// For debugging
void debug_msg(const char* msg) {
    fprintf(stderr, "DEBUG: %s\n", msg);
}

// Global variables for state tracking
char *saved_alt_text = NULL;
char *paragraph_text = NULL;
char *link_text = NULL;
char *link_url = NULL;

// For handling code blocks
char *code_lines[100];  // Store up to 100 lines of code
int code_line_count = 0;
char *code_lang = NULL;

// For conditional processing
char *condition_var = NULL;
char *condition_value = NULL;
int condition_op = OP_IGUAL;

// Global flags
int enum_count = 1;

#line 108 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INDENTED_TEXT = 3,              /* INDENTED_TEXT  */
  YYSYMBOL_CODIGO = 4,                     /* CODIGO  */
  YYSYMBOL_CABECALHO = 5,                  /* CABECALHO  */
  YYSYMBOL_ALT = 6,                        /* ALT  */
  YYSYMBOL_SRC = 7,                        /* SRC  */
  YYSYMBOL_STATUS_S = 8,                   /* STATUS_S  */
  YYSYMBOL_STATUS_N = 9,                   /* STATUS_N  */
  YYSYMBOL_TEXTO = 10,                     /* TEXTO  */
  YYSYMBOL_URL = 11,                       /* URL  */
  YYSYMBOL_STATUS_SIM = 12,                /* STATUS_SIM  */
  YYSYMBOL_STATUS_NAO = 13,                /* STATUS_NAO  */
  YYSYMBOL_REPETIR = 14,                   /* REPETIR  */
  YYSYMBOL_OP_REL = 15,                    /* OP_REL  */
  YYSYMBOL_TITULO = 16,                    /* TITULO  */
  YYSYMBOL_SUBTITULO = 17,                 /* SUBTITULO  */
  YYSYMBOL_PARAGRAFO = 18,                 /* PARAGRAFO  */
  YYSYMBOL_LISTA = 19,                     /* LISTA  */
  YYSYMBOL_ENUMERAR = 20,                  /* ENUMERAR  */
  YYSYMBOL_TAREFAS = 21,                   /* TAREFAS  */
  YYSYMBOL_IMAGEM = 22,                    /* IMAGEM  */
  YYSYMBOL_DIVISOR = 23,                   /* DIVISOR  */
  YYSYMBOL_TABELA = 24,                    /* TABELA  */
  YYSYMBOL_LINK = 25,                      /* LINK  */
  YYSYMBOL_NOTA = 26,                      /* NOTA  */
  YYSYMBOL_CITACAO = 27,                   /* CITACAO  */
  YYSYMBOL_ENTAO = 28,                     /* ENTAO  */
  YYSYMBOL_SENAO = 29,                     /* SENAO  */
  YYSYMBOL_NEWLINE = 30,                   /* NEWLINE  */
  YYSYMBOL_SE = 31,                        /* SE  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_document = 33,                  /* document  */
  YYSYMBOL_blocks = 34,                    /* blocks  */
  YYSYMBOL_block = 35,                     /* block  */
  YYSYMBOL_titulo_block = 36,              /* titulo_block  */
  YYSYMBOL_subtitulo_block = 37,           /* subtitulo_block  */
  YYSYMBOL_paragrafo_block = 38,           /* paragrafo_block  */
  YYSYMBOL_indented_lines = 39,            /* indented_lines  */
  YYSYMBOL_lista_block = 40,               /* lista_block  */
  YYSYMBOL_lista_items = 41,               /* lista_items  */
  YYSYMBOL_enumerar_block = 42,            /* enumerar_block  */
  YYSYMBOL_43_1 = 43,                      /* $@1  */
  YYSYMBOL_enumerar_items = 44,            /* enumerar_items  */
  YYSYMBOL_tarefas_block = 45,             /* tarefas_block  */
  YYSYMBOL_tarefas_items = 46,             /* tarefas_items  */
  YYSYMBOL_codigo_block = 47,              /* codigo_block  */
  YYSYMBOL_48_2 = 48,                      /* $@2  */
  YYSYMBOL_codigo_content = 49,            /* codigo_content  */
  YYSYMBOL_codigo_lines = 50,              /* codigo_lines  */
  YYSYMBOL_imagem_block = 51,              /* imagem_block  */
  YYSYMBOL_alt_line = 52,                  /* alt_line  */
  YYSYMBOL_src_line = 53,                  /* src_line  */
  YYSYMBOL_link_block = 54,                /* link_block  */
  YYSYMBOL_texto_line = 55,                /* texto_line  */
  YYSYMBOL_url_line = 56,                  /* url_line  */
  YYSYMBOL_nota_block = 57,                /* nota_block  */
  YYSYMBOL_citacao_block = 58,             /* citacao_block  */
  YYSYMBOL_divisor_block = 59,             /* divisor_block  */
  YYSYMBOL_tabela_block = 60,              /* tabela_block  */
  YYSYMBOL_cabecalho_line = 61,            /* cabecalho_line  */
  YYSYMBOL_tabela_rows = 62,               /* tabela_rows  */
  YYSYMBOL_se_block = 63,                  /* se_block  */
  YYSYMBOL_repetir_block = 64              /* repetir_block  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   91

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    62,    64,    65,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    88,    93,    98,   110,   119,   130,   135,   137,
     142,   142,   147,   149,   154,   159,   161,   163,   165,   167,
     169,   171,   173,   179,   178,   208,   212,   217,   225,   229,
     237,   248,   252,   260,   271,   282,   293,   298,   303,   331,
     346,   361,   379,   387
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INDENTED_TEXT",
  "CODIGO", "CABECALHO", "ALT", "SRC", "STATUS_S", "STATUS_N", "TEXTO",
  "URL", "STATUS_SIM", "STATUS_NAO", "REPETIR", "OP_REL", "TITULO",
  "SUBTITULO", "PARAGRAFO", "LISTA", "ENUMERAR", "TAREFAS", "IMAGEM",
  "DIVISOR", "TABELA", "LINK", "NOTA", "CITACAO", "ENTAO", "SENAO",
  "NEWLINE", "SE", "$accept", "document", "blocks", "block",
  "titulo_block", "subtitulo_block", "paragrafo_block", "indented_lines",
  "lista_block", "lista_items", "enumerar_block", "$@1", "enumerar_items",
  "tarefas_block", "tarefas_items", "codigo_block", "$@2",
  "codigo_content", "codigo_lines", "imagem_block", "alt_line", "src_line",
  "link_block", "texto_line", "url_line", "nota_block", "citacao_block",
  "divisor_block", "tabela_block", "cabecalho_line", "tabela_rows",
  "se_block", "repetir_block", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-8)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -8,     9,    -4,    -8,    -8,    -8,     8,    22,    27,    28,
      -8,    -7,    26,     3,    30,    38,    27,    27,    20,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    46,    23,    24,    25,
      49,    29,    53,    54,    31,    32,    33,    34,    -5,    35,
      51,    -8,    36,    57,    37,    58,    49,    49,    -8,    -8,
      40,    -8,    65,    -8,    -8,    -8,    41,    -8,    42,    43,
      71,    -8,    -8,    -8,    -8,    45,    47,    48,    50,    -8,
      52,    -8,    -8,    55,    73,    -8,    56,    -8,    -8,    59,
      -8,    -8,    -8,    60,    -8,    -8,    -8,    -8,    -8,    -8,
      61,    -8,    -8,    -8,    -8
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,    43,    63,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,    21,    62,
       4,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
      24,     0,    27,     0,     0,     0,     0,     0,    34,     0,
       0,    56,     0,     0,     0,     0,    54,    55,    21,     5,
       0,    44,    45,    22,    23,    25,     0,    28,     0,     0,
      31,    35,    36,    37,    38,     0,     0,     0,     0,    49,
       0,    48,    58,     0,    57,    52,     0,    51,    46,     0,
      26,    29,    32,     0,    39,    40,    41,    42,    50,    59,
      61,    53,    47,    33,    60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
      -8,    -8,    -8,    63,    -8,    -8,    -8,    12,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    20,    21,    22,    23,    40,    24,    42,
      25,    43,    70,    26,    48,    27,    36,    61,    62,    28,
      50,    81,    29,    55,    87,    30,    31,    32,    33,    53,
      84,    34,    35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       4,    44,    45,    75,    76,    46,    47,    77,    78,     3,
       5,    37,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     4,    38,    18,    19,    56,    57,
      39,    41,    49,    51,     5,    52,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    54,    60,
      58,    19,    66,    63,    64,    65,    68,    69,    80,    67,
      83,    71,    72,    73,    74,    79,    82,    85,    89,    86,
      88,    90,    91,    92,    93,    94,   100,    95,    96,     0,
      97,    59,    98,     0,     0,    99,   101,     0,     0,   102,
     103,   104
};

static const yytype_int8 yycheck[] =
{
       4,     8,     9,     8,     9,    12,    13,    12,    13,     0,
      14,     3,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     4,     3,    30,    31,    16,    17,
       3,     3,     6,    30,    14,     5,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    10,     3,
      30,    31,     3,    30,    30,    30,     3,     3,     7,    30,
       3,    30,    30,    30,    30,    30,    30,    30,     3,    11,
      30,    30,    30,    30,     3,    30,     3,    30,    30,    -1,
      30,    18,    30,    -1,    -1,    30,    30,    -1,    -1,    30,
      30,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    34,     0,     4,    14,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    30,    31,
      35,    36,    37,    38,    40,    42,    45,    47,    51,    54,
      57,    58,    59,    60,    63,    64,    48,     3,     3,     3,
      39,     3,    41,    43,     8,     9,    12,    13,    46,     6,
      52,    30,     5,    61,    10,    55,    39,    39,    30,    35,
       3,    49,    50,    30,    30,    30,     3,    30,     3,     3,
      44,    30,    30,    30,    30,     8,     9,    12,    13,    30,
       7,    53,    30,     3,    62,    30,    11,    56,    30,     3,
      30,    30,    30,     3,    30,    30,    30,    30,    30,    30,
       3,    30,    30,    30,    30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    34,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    36,    37,    38,    39,    39,    40,    41,    41,
      43,    42,    44,    44,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    48,    47,    49,    50,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      62,    62,    63,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     2,     2,     3,     2,     2,     3,
       0,     3,     2,     3,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     0,     3,     1,     2,     3,     3,     2,
       2,     3,     2,     2,     2,     2,     2,     3,     2,     2,
       3,     2,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 22: /* titulo_block: TITULO INDENTED_TEXT NEWLINE  */
#line 89 "parser.y"
    { printf("# %s\n\n", (yyvsp[-1].str)); }
#line 1231 "parser.tab.c"
    break;

  case 23: /* subtitulo_block: SUBTITULO INDENTED_TEXT NEWLINE  */
#line 94 "parser.y"
    { printf("## %s\n\n", (yyvsp[-1].str)); }
#line 1237 "parser.tab.c"
    break;

  case 24: /* paragrafo_block: PARAGRAFO indented_lines  */
#line 99 "parser.y"
    { 
        // Print accumulated paragraph text
        if (paragraph_text) {
            printf("%s\n\n", paragraph_text);
            free(paragraph_text);
            paragraph_text = NULL;
        }
    }
#line 1250 "parser.tab.c"
    break;

  case 25: /* indented_lines: INDENTED_TEXT NEWLINE  */
#line 111 "parser.y"
    { 
        if (paragraph_text) {
            free(paragraph_text);
            paragraph_text = NULL;
        }
        paragraph_text = strdup((yyvsp[-1].str));
        (yyval.str) = paragraph_text;
    }
#line 1263 "parser.tab.c"
    break;

  case 26: /* indented_lines: indented_lines INDENTED_TEXT NEWLINE  */
#line 120 "parser.y"
    { 
        char *new_text = malloc(strlen(paragraph_text) + strlen((yyvsp[-1].str)) + 2); // +2 for space and null terminator
        sprintf(new_text, "%s %s", paragraph_text, (yyvsp[-1].str));
        free(paragraph_text);
        paragraph_text = new_text;
        (yyval.str) = paragraph_text;
    }
#line 1275 "parser.tab.c"
    break;

  case 27: /* lista_block: LISTA lista_items  */
#line 131 "parser.y"
    { printf("\n"); }
#line 1281 "parser.tab.c"
    break;

  case 28: /* lista_items: INDENTED_TEXT NEWLINE  */
#line 136 "parser.y"
    { printf("- %s\n", (yyvsp[-1].str)); }
#line 1287 "parser.tab.c"
    break;

  case 29: /* lista_items: lista_items INDENTED_TEXT NEWLINE  */
#line 138 "parser.y"
    { printf("- %s\n", (yyvsp[-1].str)); }
#line 1293 "parser.tab.c"
    break;

  case 30: /* $@1: %empty  */
#line 142 "parser.y"
             { enum_count = 1; }
#line 1299 "parser.tab.c"
    break;

  case 31: /* enumerar_block: ENUMERAR $@1 enumerar_items  */
#line 143 "parser.y"
    { printf("\n"); }
#line 1305 "parser.tab.c"
    break;

  case 32: /* enumerar_items: INDENTED_TEXT NEWLINE  */
#line 148 "parser.y"
    { printf("1. %s\n", (yyvsp[-1].str)); enum_count = 2; }
#line 1311 "parser.tab.c"
    break;

  case 33: /* enumerar_items: enumerar_items INDENTED_TEXT NEWLINE  */
#line 150 "parser.y"
    { printf("%d. %s\n", enum_count++, (yyvsp[-1].str)); }
#line 1317 "parser.tab.c"
    break;

  case 34: /* tarefas_block: TAREFAS tarefas_items  */
#line 155 "parser.y"
    { printf("\n"); }
#line 1323 "parser.tab.c"
    break;

  case 35: /* tarefas_items: STATUS_S NEWLINE  */
#line 160 "parser.y"
    { printf("- [x] %s\n", (yyvsp[-1].str)); }
#line 1329 "parser.tab.c"
    break;

  case 36: /* tarefas_items: STATUS_N NEWLINE  */
#line 162 "parser.y"
    { printf("- [ ] %s\n", (yyvsp[-1].str)); }
#line 1335 "parser.tab.c"
    break;

  case 37: /* tarefas_items: STATUS_SIM NEWLINE  */
#line 164 "parser.y"
    { printf("- [x] %s\n", (yyvsp[-1].str)); }
#line 1341 "parser.tab.c"
    break;

  case 38: /* tarefas_items: STATUS_NAO NEWLINE  */
#line 166 "parser.y"
    { printf("- [ ] %s\n", (yyvsp[-1].str)); }
#line 1347 "parser.tab.c"
    break;

  case 39: /* tarefas_items: tarefas_items STATUS_S NEWLINE  */
#line 168 "parser.y"
    { printf("- [x] %s\n", (yyvsp[-1].str)); }
#line 1353 "parser.tab.c"
    break;

  case 40: /* tarefas_items: tarefas_items STATUS_N NEWLINE  */
#line 170 "parser.y"
    { printf("- [ ] %s\n", (yyvsp[-1].str)); }
#line 1359 "parser.tab.c"
    break;

  case 41: /* tarefas_items: tarefas_items STATUS_SIM NEWLINE  */
#line 172 "parser.y"
    { printf("- [x] %s\n", (yyvsp[-1].str)); }
#line 1365 "parser.tab.c"
    break;

  case 42: /* tarefas_items: tarefas_items STATUS_NAO NEWLINE  */
#line 174 "parser.y"
    { printf("- [ ] %s\n", (yyvsp[-1].str)); }
#line 1371 "parser.tab.c"
    break;

  case 43: /* $@2: %empty  */
#line 179 "parser.y"
    { 
        // Reset code block state
        code_line_count = 0;
        if (code_lang) free(code_lang);
        code_lang = strdup((yyvsp[0].str));
        
        // Free any previous code lines
        for (int i = 0; i < 100; i++) {
            if (code_lines[i]) {
                free(code_lines[i]);
                code_lines[i] = NULL;
            }
        }
    }
#line 1390 "parser.tab.c"
    break;

  case 44: /* codigo_block: CODIGO $@2 codigo_content  */
#line 194 "parser.y"
    { 
        // Print the code block with proper formatting
        printf("```%s\n", code_lang);
        for (int i = 0; i < code_line_count; i++) {
            printf("%s\n", code_lines[i]);
            free(code_lines[i]);
            code_lines[i] = NULL;
        }
        printf("```\n\n");
        code_line_count = 0;
    }
#line 1406 "parser.tab.c"
    break;

  case 46: /* codigo_lines: INDENTED_TEXT NEWLINE  */
#line 213 "parser.y"
    { 
        // Store code line
        code_lines[code_line_count++] = strdup((yyvsp[-1].str));
    }
#line 1415 "parser.tab.c"
    break;

  case 47: /* codigo_lines: codigo_lines INDENTED_TEXT NEWLINE  */
#line 218 "parser.y"
    { 
        // Store additional code line
        code_lines[code_line_count++] = strdup((yyvsp[-1].str));
    }
#line 1424 "parser.tab.c"
    break;

  case 49: /* alt_line: ALT NEWLINE  */
#line 230 "parser.y"
    { 
        if (saved_alt_text) free(saved_alt_text);
        saved_alt_text = strdup((yyvsp[-1].str));
    }
#line 1433 "parser.tab.c"
    break;

  case 50: /* src_line: SRC NEWLINE  */
#line 238 "parser.y"
    { 
        printf("![%s](%s)\n\n", saved_alt_text ? saved_alt_text : "", (yyvsp[-1].str));
        if (saved_alt_text) {
            free(saved_alt_text);
            saved_alt_text = NULL;
        }
    }
#line 1445 "parser.tab.c"
    break;

  case 52: /* texto_line: TEXTO NEWLINE  */
#line 253 "parser.y"
    {
        if (link_text) free(link_text);
        link_text = strdup((yyvsp[-1].str));
    }
#line 1454 "parser.tab.c"
    break;

  case 53: /* url_line: URL NEWLINE  */
#line 261 "parser.y"
    {
        printf("[%s](%s)\n\n", link_text ? link_text : "", (yyvsp[-1].str));
        if (link_text) {
            free(link_text);
            link_text = NULL;
        }
    }
#line 1466 "parser.tab.c"
    break;

  case 54: /* nota_block: NOTA indented_lines  */
#line 272 "parser.y"
    {
        if (paragraph_text) {
            printf("> *Note:* %s\n\n", paragraph_text);
            free(paragraph_text);
            paragraph_text = NULL;
        }
    }
#line 1478 "parser.tab.c"
    break;

  case 55: /* citacao_block: CITACAO indented_lines  */
#line 283 "parser.y"
    {
        if (paragraph_text) {
            printf("> %s\n\n", paragraph_text);
            free(paragraph_text);
            paragraph_text = NULL;
        }
    }
#line 1490 "parser.tab.c"
    break;

  case 56: /* divisor_block: DIVISOR NEWLINE  */
#line 294 "parser.y"
    { printf("---\n\n"); }
#line 1496 "parser.tab.c"
    break;

  case 57: /* tabela_block: TABELA cabecalho_line tabela_rows  */
#line 299 "parser.y"
    { printf("\n"); }
#line 1502 "parser.tab.c"
    break;

  case 58: /* cabecalho_line: CABECALHO NEWLINE  */
#line 304 "parser.y"
    {
        char *s = strdup((yyvsp[-1].str));
        char *token, *saveptr;
        
        // Print header row
        printf("|");
        token = strtok_r(s, ",", &saveptr);
        while (token != NULL) {
            token = trim(token);
            printf(" %s |", token);
            token = strtok_r(NULL, ",", &saveptr);
        }
        printf("\n|");
        
        // Print separator row
        s = strdup((yyvsp[-1].str));
        token = strtok_r(s, ",", &saveptr);
        while (token != NULL) {
            printf(" --- |");
            token = strtok_r(NULL, ",", &saveptr);
        }
        printf("\n");
        free(s);
    }
#line 1531 "parser.tab.c"
    break;

  case 59: /* tabela_rows: INDENTED_TEXT NEWLINE  */
#line 332 "parser.y"
    {
        char *s = strdup((yyvsp[-1].str));
        char *token, *saveptr;
        
        printf("|");
        token = strtok_r(s, ",", &saveptr);
        while (token != NULL) {
            token = trim(token);
            printf(" %s |", token);
            token = strtok_r(NULL, ",", &saveptr);
        }
        printf("\n");
        free(s);
    }
#line 1550 "parser.tab.c"
    break;

  case 60: /* tabela_rows: tabela_rows INDENTED_TEXT NEWLINE  */
#line 347 "parser.y"
    {
        char *s = strdup((yyvsp[-1].str));
        char *token, *saveptr;
        
        printf("|");
        token = strtok_r(s, ",", &saveptr);
        while (token != NULL) {
            token = trim(token);
            printf(" %s |", token);
            token = strtok_r(NULL, ",", &saveptr);
        }
        printf("\n");
        free(s);
    }
#line 1569 "parser.tab.c"
    break;

  case 61: /* tabela_rows: tabela_rows INDENTED_TEXT  */
#line 362 "parser.y"
    {
        char *s = strdup((yyvsp[0].str));
        char *token, *saveptr;
        
        printf("|");
        token = strtok_r(s, ",", &saveptr);
        while (token != NULL) {
            token = trim(token);
            printf(" %s |", token);
            token = strtok_r(NULL, ",", &saveptr);
        }
        printf("\n");
        free(s);
    }
#line 1588 "parser.tab.c"
    break;

  case 62: /* se_block: SE  */
#line 380 "parser.y"
    {
        // Just output a comment for the conditional block
        printf("<!-- Conditional block (simplified) -->\n\n");
    }
#line 1597 "parser.tab.c"
    break;

  case 63: /* repetir_block: REPETIR  */
#line 388 "parser.y"
    {
        // Just output a comment for the repeat block
        printf("<!-- Repeat block %d times (simplified) -->\n\n", (yyvsp[0].num));
    }
#line 1606 "parser.tab.c"
    break;


#line 1610 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 394 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s na linha %d\n", s, yylineno);
}
