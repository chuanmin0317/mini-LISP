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
#line 1 "Mini_LISP.y"

    #include "AST.h"

    AST_Node* root;
    map<string, AST_Node*> global_var_map;
    stack<ASType> type_stack;

    extern "C"{
        extern int yylex(void);
        void yyerror(const char* messages);
    }


#line 85 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    number = 258,                  /* number  */
    boolval = 259,                 /* boolval  */
    id = 260,                      /* id  */
    mod = 261,                     /* mod  */
    andop = 262,                   /* andop  */
    orop = 263,                    /* orop  */
    notop = 264,                   /* notop  */
    printnum = 265,                /* printnum  */
    printbool = 266,               /* printbool  */
    define = 267,                  /* define  */
    fun = 268,                     /* fun  */
    ifop = 269                     /* ifop  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "Mini_LISP.y"

    int ival;
    bool boolval;
    char* id;
    AST_Node* node;

#line 156 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_number = 3,                     /* number  */
  YYSYMBOL_boolval = 4,                    /* boolval  */
  YYSYMBOL_id = 5,                         /* id  */
  YYSYMBOL_mod = 6,                        /* mod  */
  YYSYMBOL_andop = 7,                      /* andop  */
  YYSYMBOL_orop = 8,                       /* orop  */
  YYSYMBOL_notop = 9,                      /* notop  */
  YYSYMBOL_printnum = 10,                  /* printnum  */
  YYSYMBOL_printbool = 11,                 /* printbool  */
  YYSYMBOL_define = 12,                    /* define  */
  YYSYMBOL_fun = 13,                       /* fun  */
  YYSYMBOL_ifop = 14,                      /* ifop  */
  YYSYMBOL_15_ = 15,                       /* '>'  */
  YYSYMBOL_16_ = 16,                       /* '<'  */
  YYSYMBOL_17_ = 17,                       /* '='  */
  YYSYMBOL_18_ = 18,                       /* '+'  */
  YYSYMBOL_19_ = 19,                       /* '-'  */
  YYSYMBOL_20_ = 20,                       /* '*'  */
  YYSYMBOL_21_ = 21,                       /* '/'  */
  YYSYMBOL_22_ = 22,                       /* '('  */
  YYSYMBOL_23_ = 23,                       /* ')'  */
  YYSYMBOL_24_ = 24,                       /* '['  */
  YYSYMBOL_25_ = 25,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 26,                  /* $accept  */
  YYSYMBOL_PROGRAM = 27,                   /* PROGRAM  */
  YYSYMBOL_STMT_LIST = 28,                 /* STMT_LIST  */
  YYSYMBOL_STMT = 29,                      /* STMT  */
  YYSYMBOL_30_PRINT_STMT = 30,             /* PRINT-STMT  */
  YYSYMBOL_EXP_LIST = 31,                  /* EXP_LIST  */
  YYSYMBOL_EXP = 32,                       /* EXP  */
  YYSYMBOL_33_NUM_OP = 33,                 /* NUM-OP  */
  YYSYMBOL_PLUS = 34,                      /* PLUS  */
  YYSYMBOL_MINUS = 35,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 36,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 37,                    /* DIVIDE  */
  YYSYMBOL_MODULUS = 38,                   /* MODULUS  */
  YYSYMBOL_GREATER = 39,                   /* GREATER  */
  YYSYMBOL_SMALLER = 40,                   /* SMALLER  */
  YYSYMBOL_EQUAL = 41,                     /* EQUAL  */
  YYSYMBOL_42_LOGICAL_OP = 42,             /* LOGICAL-OP  */
  YYSYMBOL_43_AND_OP = 43,                 /* AND-OP  */
  YYSYMBOL_44_OR_OP = 44,                  /* OR-OP  */
  YYSYMBOL_45_NOT_OP = 45,                 /* NOT-OP  */
  YYSYMBOL_46_DEF_STMT = 46,               /* DEF-STMT  */
  YYSYMBOL_VARIABLE = 47,                  /* VARIABLE  */
  YYSYMBOL_48_FUN_EXP = 48,                /* FUN-EXP  */
  YYSYMBOL_49_FUN_IDs = 49,                /* FUN-IDs  */
  YYSYMBOL_FUN_STMT_LIST = 50,             /* FUN_STMT_LIST  */
  YYSYMBOL_FUN_STMT = 51,                  /* FUN_STMT  */
  YYSYMBOL_52_FUN_BODY = 52,               /* FUN-BODY  */
  YYSYMBOL_53_FUN_CALL = 53,               /* FUN-CALL  */
  YYSYMBOL_PARAM_LIST = 54,                /* PARAM_LIST  */
  YYSYMBOL_PARAM = 55,                     /* PARAM  */
  YYSYMBOL_56_FUN_NAME = 56,               /* FUN-NAME  */
  YYSYMBOL_VARIABLE_LIST = 57,             /* VARIABLE_LIST  */
  YYSYMBOL_58_IF_EXP = 58,                 /* IF-EXP  */
  YYSYMBOL_59_TEST_EXP = 59,               /* TEST-EXP  */
  YYSYMBOL_60_THEN_EXP = 60,               /* THEN-EXP  */
  YYSYMBOL_61_ELSE_EXP = 61                /* ELSE-EXP  */
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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   171

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   269


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
      22,    23,    20,    18,     2,    19,     2,    21,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      16,    17,    15,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    24,     2,    25,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    46,    46,    53,    57,    60,    61,    62,    66,    70,
      76,    83,    86,    92,    98,    99,   100,   101,   102,   103,
     107,   108,   109,   110,   111,   112,   113,   114,   117,   118,
     119,   120,   121,   122,   123,   124,   127,   128,   129,   132,
     133,   134,   137,   139,   147,   149,   150,   153,   157,   159,
     159,   162,   165,   169,   175,   179,   182,   185,   188,   192,
     196,   206,   209,   212
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
  "\"end of file\"", "error", "\"invalid token\"", "number", "boolval",
  "id", "mod", "andop", "orop", "notop", "printnum", "printbool", "define",
  "fun", "ifop", "'>'", "'<'", "'='", "'+'", "'-'", "'*'", "'/'", "'('",
  "')'", "'['", "']'", "$accept", "PROGRAM", "STMT_LIST", "STMT",
  "PRINT-STMT", "EXP_LIST", "EXP", "NUM-OP", "PLUS", "MINUS", "MULTIPLY",
  "DIVIDE", "MODULUS", "GREATER", "SMALLER", "EQUAL", "LOGICAL-OP",
  "AND-OP", "OR-OP", "NOT-OP", "DEF-STMT", "VARIABLE", "FUN-EXP",
  "FUN-IDs", "FUN_STMT_LIST", "FUN_STMT", "FUN-BODY", "FUN-CALL",
  "PARAM_LIST", "PARAM", "FUN-NAME", "VARIABLE_LIST", "IF-EXP", "TEST-EXP",
  "THEN-EXP", "ELSE-EXP", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      89,   -69,   -69,   -69,   113,     2,    89,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,    92,    92,    92,
      92,    92,    92,     3,   -17,    92,    92,    92,    92,    92,
      92,    92,    92,    -6,   -69,    92,    92,   -69,   -69,    89,
     149,    92,    92,    92,   -13,   -12,   -11,    92,    -2,    95,
     -69,    92,    92,    92,    92,    92,    92,    92,    92,   -69,
     -10,    92,    -9,   -69,    -8,    92,    92,   -69,   -69,   -69,
      -7,   -69,     3,    -5,   131,   -69,   -69,   -69,    95,    -4,
     -69,    92,    -1,     1,    92,    92,    20,    92,    21,   -69,
     -69,   -69,   -69,    25,    92,    27,   -69,   -69,   -69,   -69,
     -69,   -69,    31,   -69,   -69,    35,    37,   -69,    46,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    13,    12,    43,     0,     0,     4,     7,     5,    15,
      20,    21,    22,    23,    24,    25,    26,    27,    16,    36,
      37,    38,     6,    14,    18,    19,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,    55,    55,     1,     2,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      61,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,    55,     0,     3,     0,    11,    11,    41,     8,     9,
       0,    46,    59,     0,     0,    49,    50,    51,    48,     0,
      62,     0,     0,     0,    11,    11,     0,    11,     0,    52,
      54,    53,    32,     0,    11,     0,    42,    58,    45,    47,
      44,    63,     0,    33,    34,     0,     0,    29,     0,    31,
      39,    10,    40,    60,    35,    28,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -69,   -32,    23,   -69,   -20,     0,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -55,    22,    -3,   -69,   -68,   -69,   -69,   -69,   -37,   -69,
     -69,   -57,   -69,   -69,   -69,   -69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,    48,    49,     7,   103,   104,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    59,    87,    88,    89,    25,    70,    71,
      46,    83,    26,    61,    91,   112
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       8,    45,    47,     3,    86,    58,     8,    34,     3,    72,
      77,    78,    79,    99,   101,   102,   106,    73,   108,   110,
     109,    81,   113,     6,   114,   107,    44,    51,    52,    53,
      54,    55,    56,    86,   100,    60,    62,    63,    64,    65,
      66,    67,    68,   117,   119,    69,    69,    45,   120,     8,
     122,    74,    75,    76,   123,    57,   105,    80,   124,    85,
     125,    90,    92,    93,    94,    95,    96,    97,    98,   126,
       0,    69,    44,     0,   115,   116,     0,   118,     0,     0,
      82,    45,     0,     0,   121,     0,     0,     0,    85,     0,
       0,   111,     1,     2,     3,     1,     2,     3,     1,     2,
       3,     0,     0,     0,    82,     0,    44,     0,     0,     0,
       0,     4,     0,     0,    50,     0,     0,    84,     3,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     3,    27,    28,    29,
      30,     0,     0,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     3,    27,    28,    29,    30,     0,
       0,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43
};

static const yytype_int8 yycheck[] =
{
       0,     4,     0,     5,    59,    22,     6,    13,     5,    46,
      23,    23,    23,    23,    23,    23,    23,    49,    23,    23,
      88,    23,    23,     0,    23,    82,     4,    27,    28,    29,
      30,    31,    32,    88,    71,    35,    36,    37,    38,    39,
      40,    41,    42,    23,    23,    45,    46,    50,    23,    49,
      23,    51,    52,    53,    23,    33,    76,    57,    23,    59,
      23,    61,    62,    63,    64,    65,    66,    67,    68,    23,
      -1,    71,    50,    -1,    94,    95,    -1,    97,    -1,    -1,
      58,    84,    -1,    -1,   104,    -1,    -1,    -1,    88,    -1,
      -1,    91,     3,     4,     5,     3,     4,     5,     3,     4,
       5,    -1,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    22,    -1,    -1,    22,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    22,    27,    29,    30,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    53,    58,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    47,    48,    56,     0,    28,    29,
      22,    32,    32,    32,    32,    32,    32,    47,    22,    49,
      32,    59,    32,    32,    32,    32,    32,    32,    32,    32,
      54,    55,    54,    28,    32,    32,    32,    23,    23,    23,
      32,    23,    47,    57,    22,    32,    46,    50,    51,    52,
      32,    60,    32,    32,    32,    32,    32,    32,    32,    23,
      54,    23,    23,    31,    32,    31,    23,    57,    23,    50,
      23,    32,    61,    23,    23,    31,    31,    23,    31,    23,
      23,    31,    23,    23,    23,    23,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    26,    27,    28,    28,    29,    29,    29,    30,    30,
      31,    31,    32,    32,    32,    32,    32,    32,    32,    32,
      33,    33,    33,    33,    33,    33,    33,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    42,    42,    43,
      44,    45,    46,    47,    48,    49,    49,    50,    50,    51,
      51,    52,    53,    53,    54,    54,    55,    56,    57,    57,
      58,    59,    60,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     4,     4,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     6,     5,
       6,     5,     5,     5,     5,     6,     1,     1,     1,     6,
       6,     4,     5,     1,     5,     3,     2,     2,     0,     1,
       1,     1,     4,     4,     2,     0,     1,     1,     2,     0,
       6,     1,     1,     1
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
  case 2: /* PROGRAM: STMT STMT_LIST  */
#line 46 "Mini_LISP.y"
                         {
            type_stack.push(ROOT);
            (yyval.node) = creatNode((yyvsp[-1].node), (yyvsp[0].node));
            root = (yyval.node);
        }
#line 1289 "y.tab.c"
    break;

  case 3: /* STMT_LIST: STMT STMT_LIST  */
#line 53 "Mini_LISP.y"
                           {
              type_stack.push(ROOT);
              (yyval.node) = creatNode((yyvsp[-1].node), (yyvsp[0].node));
          }
#line 1298 "y.tab.c"
    break;

  case 4: /* STMT_LIST: %empty  */
#line 57 "Mini_LISP.y"
            { (yyval.node) = nullptr; }
#line 1304 "y.tab.c"
    break;

  case 8: /* PRINT-STMT: '(' printnum EXP ')'  */
#line 66 "Mini_LISP.y"
                                   { 
                type_stack.push(PRINT_NUM);
                (yyval.node) = creatNode((yyvsp[-1].node), nullptr);
            }
#line 1313 "y.tab.c"
    break;

  case 9: /* PRINT-STMT: '(' printbool EXP ')'  */
#line 70 "Mini_LISP.y"
                                    {
                type_stack.push(PRINT_BOOL);
                (yyval.node) = creatNode((yyvsp[-1].node), nullptr);
            }
#line 1322 "y.tab.c"
    break;

  case 10: /* EXP_LIST: EXP EXP_LIST  */
#line 76 "Mini_LISP.y"
                        {
             AST_Node* new_node = new AST_Node;
             new_node->type = type_stack.top();
             new_node->left = (yyvsp[-1].node);
             new_node->right = (yyvsp[0].node);
             (yyval.node) = new_node;
         }
#line 1334 "y.tab.c"
    break;

  case 11: /* EXP_LIST: %empty  */
#line 83 "Mini_LISP.y"
           { (yyval.node) = nullptr; }
#line 1340 "y.tab.c"
    break;

  case 12: /* EXP: boolval  */
#line 86 "Mini_LISP.y"
              {
        ASTBool* new_node = new ASTBool;
        new_node->type = BOOLVAL;
        new_node->boolval = (yyvsp[0].boolval);
        (yyval.node) = (AST_Node*)new_node;
    }
#line 1351 "y.tab.c"
    break;

  case 13: /* EXP: number  */
#line 92 "Mini_LISP.y"
             {
        ASTNumber* new_node = new ASTNumber;
        new_node->type = NUMBER;
        new_node->number = (yyvsp[0].ival);
        (yyval.node) = (AST_Node*)new_node;
    }
#line 1362 "y.tab.c"
    break;

  case 28: /* PLUS: '(' '+' EXP EXP EXP_LIST ')'  */
#line 117 "Mini_LISP.y"
                                    { (yyval.node) = creatNode((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1368 "y.tab.c"
    break;

  case 29: /* MINUS: '(' '-' EXP EXP ')'  */
#line 118 "Mini_LISP.y"
                            { (yyval.node) = creatNode((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1374 "y.tab.c"
    break;

  case 30: /* MULTIPLY: '(' '*' EXP EXP EXP_LIST ')'  */
#line 119 "Mini_LISP.y"
                                        { (yyval.node) = creatNode((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1380 "y.tab.c"
    break;

  case 31: /* DIVIDE: '(' '/' EXP EXP ')'  */
#line 120 "Mini_LISP.y"
                             { (yyval.node) = creatNode((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1386 "y.tab.c"
    break;

  case 32: /* MODULUS: '(' mod EXP EXP ')'  */
#line 121 "Mini_LISP.y"
                              { (yyval.node) = creatNode((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1392 "y.tab.c"
    break;

  case 33: /* GREATER: '(' '>' EXP EXP ')'  */
#line 122 "Mini_LISP.y"
                              { (yyval.node) = creatNode((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1398 "y.tab.c"
    break;

  case 34: /* SMALLER: '(' '<' EXP EXP ')'  */
#line 123 "Mini_LISP.y"
                              { (yyval.node) = creatNode((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1404 "y.tab.c"
    break;

  case 35: /* EQUAL: '(' '=' EXP EXP EXP_LIST ')'  */
#line 124 "Mini_LISP.y"
                                     { (yyval.node) = creatNode((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1410 "y.tab.c"
    break;

  case 39: /* AND-OP: '(' andop EXP EXP EXP_LIST ')'  */
#line 132 "Mini_LISP.y"
                                        { (yyval.node) = creatNode((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1416 "y.tab.c"
    break;

  case 40: /* OR-OP: '(' orop EXP EXP EXP_LIST ')'  */
#line 133 "Mini_LISP.y"
                                      { (yyval.node) = creatNode((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1422 "y.tab.c"
    break;

  case 41: /* NOT-OP: '(' notop EXP ')'  */
#line 134 "Mini_LISP.y"
                           { (yyval.node) = creatNode((yyvsp[-1].node), nullptr); }
#line 1428 "y.tab.c"
    break;

  case 42: /* DEF-STMT: '(' define VARIABLE EXP ')'  */
#line 137 "Mini_LISP.y"
                                       { (yyval.node) = creatNode((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1434 "y.tab.c"
    break;

  case 43: /* VARIABLE: id  */
#line 139 "Mini_LISP.y"
              {
             ASTID* new_node = new ASTID;
             new_node->type = ID;
             new_node->id = (yyvsp[0].id);
             (yyval.node) = (ASTID*)new_node;
         }
#line 1445 "y.tab.c"
    break;

  case 44: /* FUN-EXP: '(' fun FUN-IDs FUN-BODY ')'  */
#line 147 "Mini_LISP.y"
                                       { (yyval.node) = creatNode((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1451 "y.tab.c"
    break;

  case 45: /* FUN-IDs: '(' VARIABLE_LIST ')'  */
#line 149 "Mini_LISP.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 1457 "y.tab.c"
    break;

  case 46: /* FUN-IDs: '(' ')'  */
#line 150 "Mini_LISP.y"
              {}
#line 1463 "y.tab.c"
    break;

  case 47: /* FUN_STMT_LIST: FUN_STMT FUN_STMT_LIST  */
#line 153 "Mini_LISP.y"
                                       {
                  type_stack.push(FUN_BODY);
                  (yyval.node) = creatNode((yyvsp[-1].node), (yyvsp[0].node));
              }
#line 1472 "y.tab.c"
    break;

  case 48: /* FUN_STMT_LIST: %empty  */
#line 157 "Mini_LISP.y"
                { (yyval.node) = nullptr; }
#line 1478 "y.tab.c"
    break;

  case 52: /* FUN-CALL: '(' FUN-EXP PARAM_LIST ')'  */
#line 165 "Mini_LISP.y"
                                      {
             type_stack.push(FUN_DEF_CALL);
             (yyval.node) = creatNode((yyvsp[-2].node), (yyvsp[-1].node));
         }
#line 1487 "y.tab.c"
    break;

  case 53: /* FUN-CALL: '(' FUN-NAME PARAM_LIST ')'  */
#line 169 "Mini_LISP.y"
                                       {
             type_stack.push(FUN_CALL);
             (yyval.node) = creatNode((yyvsp[-2].node), (yyvsp[-1].node));
         }
#line 1496 "y.tab.c"
    break;

  case 54: /* PARAM_LIST: PARAM PARAM_LIST  */
#line 175 "Mini_LISP.y"
                              {
               type_stack.push(NUMBER);
               (yyval.node) = creatNode((yyvsp[-1].node), (yyvsp[0].node));
           }
#line 1505 "y.tab.c"
    break;

  case 55: /* PARAM_LIST: %empty  */
#line 179 "Mini_LISP.y"
             { (yyval.node) = nullptr; }
#line 1511 "y.tab.c"
    break;

  case 58: /* VARIABLE_LIST: VARIABLE VARIABLE_LIST  */
#line 188 "Mini_LISP.y"
                                       {
                  type_stack.push(ID);
                  (yyval.node) = creatNode((yyvsp[-1].node), (yyvsp[0].node));
              }
#line 1520 "y.tab.c"
    break;

  case 59: /* VARIABLE_LIST: %empty  */
#line 192 "Mini_LISP.y"
                { (yyval.node) = nullptr; }
#line 1526 "y.tab.c"
    break;

  case 60: /* IF-EXP: '(' ifop TEST-EXP THEN-EXP ELSE-EXP ')'  */
#line 196 "Mini_LISP.y"
                                                 {
    ASTIF* new_node = new ASTIF;
    new_node->type = type_stack.top();
    new_node->cond_exp = (yyvsp[-3].node);
    new_node->left = (yyvsp[-2].node);
    new_node->right = (yyvsp[-1].node);
    type_stack.pop();
    (yyval.node) = (AST_Node*)new_node;
}
#line 1540 "y.tab.c"
    break;


#line 1544 "y.tab.c"

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

#line 214 "Mini_LISP.y"


void yyerror(const char* message){
    cout << message << endl;
}

int main(void) {
    yyparse();
    Traversal(root, global_var_map);
//    printAST(root);
    return 0;
}
