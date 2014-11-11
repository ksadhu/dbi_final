#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20110908

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 3 "Parser.y"

	#include "ParseTree.h" 
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <iostream>

	extern "C" int yylex();
	extern "C" int yyparse();
	extern "C" void yyerror(char *s);
  
	/* these data structures hold the result of the parsing*/
	/*struct TableAtts *createtableatts;//stores the attributes and its types if Create Table Command is called or NULL*/
	struct CreateTable *createTable;
	struct FuncOperator *finalFunction; /* the aggregate function (NULL if no agg)*/
	struct TableList *tables; /* the list of tables and aliases in the query*/
	struct AndList *boolean; /* the predicate in the WHERE clause*/
	struct NameList *groupingAtts; /* grouping atts (NULL if no grouping)*/
	struct NameList *attsToSelect; /* the set of attributes in the SELECT (NULL if no such atts)*/
	struct Insert *insertinto;
	int distinctAtts; /* 1 if there is a DISTINCT in a non-aggregate query */
	int distinctFunc;  /* 1 if there is a DISTINCT in an aggregate query*/
	char *droptablename;
	int outputmode;
	char *outputfile;
        bool DDL;
	
#line 35 "Parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct TableAtts *mytableatts;
 	struct FuncOperand *myOperand;
	struct FuncOperator *myOperator; 
	struct TableList *myTables;
	struct ComparisonOp *myComparison;
	struct Operand *myBoolOperand;
	struct OrList *myOrList;
	struct AndList *myAndList;
	struct NameList *myNames;
	struct CrAttr *crattr;
	struct CreateTable *mycreatetables;
	char *actualChars;
	char whichOne;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 70 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#define YYERROR_DECL() yyerror(const char *s)
#define YYERROR_CALL(msg) yyerror(msg)

extern int YYPARSE_DECL();

#define Name 257
#define Float 258
#define Int 259
#define String 260
#define SELECT 261
#define GROUP 262
#define DISTINCT 263
#define BY 264
#define FROM 265
#define WHERE 266
#define SUM 267
#define AS 268
#define AND 269
#define OR 270
#define CREATE 271
#define TABLE 272
#define HEAP 273
#define SORTED 274
#define INSERT 275
#define INTO 276
#define DROP 277
#define SET 278
#define OUTPUT 279
#define STDOUT 280
#define NONE 281
#define ON 282
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   13,
   13,   11,   11,   12,   14,   14,   14,   14,   15,   15,
   10,   10,    8,    8,    4,    4,    4,    4,    4,    5,
    5,    5,    5,    2,    2,    1,    1,    7,    6,    6,
    6,    9,    9,    9,    9,    3,    3,    3,
};
static const short yylen[] = {                            2,
    6,    9,    8,   10,    4,    3,    3,    3,    3,    3,
    1,    3,    1,    2,    3,    1,    1,    2,    4,    5,
    1,    3,    3,    5,    3,    5,    3,    1,    2,    1,
    1,    1,    1,    5,    3,    3,    1,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,   21,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    6,    8,    7,    9,    0,   48,
   46,   47,    0,    0,    0,    0,   22,    0,    0,    0,
    0,    5,    0,    0,   29,   30,   31,   32,   33,    0,
   19,    0,    0,    0,    0,    0,    0,   20,    0,   25,
   23,    0,    0,    0,   14,    0,    0,    0,   45,   43,
   44,   42,    0,    0,    0,    0,    0,    0,   12,   26,
    0,    0,   39,   40,   41,    0,    0,   24,    3,    0,
    0,   36,   38,    0,    0,   34,    0,    4,    0,   10,
};
static const short yydgoto[] = {                          6,
   73,   63,   35,   36,   50,   86,   74,   39,   75,   10,
   56,   57,   98,   11,   12,
};
static const short yysindex[] = {                      -254,
 -235, -259, -242, -253, -252,    0,    0, -237,  -40,  -19,
 -234,   -2, -214, -231, -211, -251,  -19,    7,  -37, -209,
 -208, -237,   10, -206,    0,    0,    0,    0,  -37,    0,
    0,    0,  -37,  -37,  -31,   11,    0, -215,  -42,  -19,
 -203,    0,   14,   15,    0,    0,    0,    0,    0,  -37,
    0, -200,   18, -198, -197,   20,   19,    0,  -31,    0,
    0, -224, -196, -204,    0, -201, -203,  -37,    0,    0,
    0,    0,   21, -205,  -23, -195, -189, -233,    0,    0,
 -199, -224,    0,    0,    0, -224, -237,    0,    0, -210,
   18,    0,    0,  -19, -186,    0,   29,    0, -186,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -191,
    0, -190,    0,    0,    0,    0, -188,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   35,    0,    0,    0,    0, -187,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   38,    0,   39,    0,
    0,    0,   81,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   41,    0,    0,    0,    0,    0,    0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   84,    0,    0,   85,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    4,   -3,    0,  -24,   28,    0,    0,    0,    3,   -4,
   23,    0,   -8,    0,    0,
};
#define YYTABLESIZE 263
static const short yytable[] = {                         19,
   35,   54,   33,   17,   43,   26,    1,   34,   44,   45,
   48,   47,   13,   46,   14,   49,    2,   40,   15,    7,
    3,    7,    4,    5,   20,   60,   16,    8,   27,   28,
   21,    9,   69,   70,   71,   72,   83,   85,   84,   89,
   90,   22,   23,   80,   24,   25,   29,   37,   38,   41,
   42,   51,   52,   55,   58,   59,   61,   62,   64,   65,
   66,   81,   67,   77,   82,   76,   78,   88,   87,   91,
   97,   95,   99,   17,   16,   28,   18,   15,   13,   27,
    1,   37,   94,    2,   11,   92,   68,   96,   93,   79,
  100,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   30,
   31,   32,   18,   53,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   35,
};
static const short yycheck[] = {                         40,
    0,   44,   40,    8,   29,  257,  261,   45,   33,   34,
   42,   43,  272,   45,  257,   47,  271,   22,  272,  257,
  275,  257,  277,  278,   44,   50,  279,  263,  280,  281,
  265,  267,  257,  258,  259,  260,   60,   61,   62,  273,
  274,   44,  257,   68,  276,  257,   40,  257,  257,   40,
  257,   41,  268,  257,   41,   41,  257,   40,  257,  257,
   41,   41,   44,  268,  270,  262,  268,  257,  264,  269,
  257,  282,   44,  265,  265,   41,  265,  265,   41,   41,
    0,   41,   87,    0,    0,   82,   59,   91,   86,   67,
   99,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  258,  259,  263,  266,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 282
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,0,
"'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"Name","Float","Int","String","SELECT","GROUP","DISTINCT","BY","FROM",
"WHERE","SUM","AS","AND","OR","CREATE","TABLE","HEAP","SORTED","INSERT","INTO",
"DROP","SET","OUTPUT","STDOUT","NONE","ON",
};
static const char *yyrule[] = {
"$accept : SQL",
"SQL : SELECT WhatIWant FROM Tables WHERE AndList",
"SQL : SELECT WhatIWant FROM Tables WHERE AndList GROUP BY Atts",
"SQL : CREATE TABLE Name '(' Createattributes ')' AS HEAP",
"SQL : CREATE TABLE Name '(' Createattributes ')' AS SORTED ON sortattributes",
"SQL : INSERT Name INTO Name",
"SQL : DROP TABLE Name",
"SQL : SET OUTPUT STDOUT",
"SQL : SET OUTPUT Name",
"SQL : SET OUTPUT NONE",
"sortattributes : Name ',' sortattributes",
"sortattributes : Name",
"Createattributes : Newatt ',' Createattributes",
"Createattributes : Newatt",
"Newatt : Name Name",
"WhatIWant : Function ',' Atts",
"WhatIWant : Function",
"WhatIWant : Atts",
"WhatIWant : DISTINCT Atts",
"Function : SUM '(' CompoundExp ')'",
"Function : SUM DISTINCT '(' CompoundExp ')'",
"Atts : Name",
"Atts : Atts ',' Name",
"Tables : Name AS Name",
"Tables : Tables ',' Name AS Name",
"CompoundExp : SimpleExp Op CompoundExp",
"CompoundExp : '(' CompoundExp ')' Op CompoundExp",
"CompoundExp : '(' CompoundExp ')'",
"CompoundExp : SimpleExp",
"CompoundExp : '-' CompoundExp",
"Op : '-'",
"Op : '+'",
"Op : '*'",
"Op : '/'",
"AndList : '(' OrList ')' AND AndList",
"AndList : '(' OrList ')'",
"OrList : Condition OR OrList",
"OrList : Condition",
"Condition : Literal BoolComp Literal",
"BoolComp : '<'",
"BoolComp : '>'",
"BoolComp : '='",
"Literal : String",
"Literal : Float",
"Literal : Int",
"Literal : Name",
"SimpleExp : Float",
"SimpleExp : Int",
"SimpleExp : Name",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 504 "Parser.y"

#line 351 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 107 "Parser.y"
	{
	tables = yystack.l_mark[-2].myTables;
	boolean = yystack.l_mark[0].myAndList;	
	groupingAtts = NULL;
	droptablename=NULL;
	createTable=NULL;
	groupingAtts=NULL;
	insertinto=NULL;
	outputmode=0;
        DDL=false;
}
break;
case 2:
#line 120 "Parser.y"
	{
	tables = yystack.l_mark[-5].myTables;
	boolean = yystack.l_mark[-3].myAndList;	
	groupingAtts = yystack.l_mark[0].myNames;
	droptablename=NULL;
	createTable=NULL;
	insertinto=NULL;
	outputmode=0;
        DDL=false;
}
break;
case 3:
#line 131 "Parser.y"
	{
	createTable=(struct CreateTable *) malloc (sizeof (struct CreateTable));
	createTable->tableName=yystack.l_mark[-5].actualChars;
	createTable->sortkeys=NULL;
	createTable->atts=yystack.l_mark[-3].mytableatts;
	droptablename=NULL;
	insertinto=NULL;
	outputmode=0;
        DDL=true;
}
break;
case 4:
#line 142 "Parser.y"
	{
	createTable=(struct CreateTable *) malloc (sizeof (struct CreateTable));
	createTable->tableName=yystack.l_mark[-7].actualChars;
	createTable->sortkeys=yystack.l_mark[0].myNames;
	createTable->atts=yystack.l_mark[-5].mytableatts;
	droptablename=NULL;
	insertinto=NULL;
	outputmode=0;
        DDL=true;
}
break;
case 5:
#line 153 "Parser.y"
	{
	insertinto=(struct Insert *)malloc(sizeof(struct Insert));
	insertinto->filename=yystack.l_mark[-2].actualChars;
	insertinto->dbfile=yystack.l_mark[0].actualChars;
	droptablename=NULL;
	createTable=NULL;
	tables = NULL;
	boolean = NULL;	
	groupingAtts = NULL;
	createTable=NULL;
	groupingAtts=NULL;
	outputmode=0;
        DDL=true;

}
break;
case 6:
#line 169 "Parser.y"
	{
	insertinto=NULL;
	createTable=NULL;
	tables = NULL;
	boolean = NULL;	
	groupingAtts = NULL;
	createTable=NULL;
	groupingAtts=NULL;
	droptablename=yystack.l_mark[0].actualChars;
	outputmode=0;
        DDL=true;
}
break;
case 7:
#line 182 "Parser.y"
	{
	outputmode=1;
        DDL=true;
}
break;
case 8:
#line 187 "Parser.y"
	{	
	outputmode=2;
	outputfile=yystack.l_mark[0].actualChars;
        DDL=true;
}
break;
case 9:
#line 193 "Parser.y"
	{
	outputmode=3;
        DDL=true;
}
break;
case 10:
#line 199 "Parser.y"
	{
	yyval.myNames=(struct NameList *) malloc (sizeof (struct NameList));
	yyval.myNames->name=yystack.l_mark[-2].actualChars;
	yyval.myNames->next=yystack.l_mark[0].myNames;
}
break;
case 11:
#line 205 "Parser.y"
	{
	yyval.myNames=(struct NameList *) malloc (sizeof (struct NameList));
	yyval.myNames->name=yystack.l_mark[0].actualChars;;
	yyval.myNames->next=NULL;
}
break;
case 12:
#line 212 "Parser.y"
	{
	yyval.mytableatts=(struct TableAtts *) malloc (sizeof (struct TableAtts));
	yyval.mytableatts->Op=yystack.l_mark[-2].crattr;
	yyval.mytableatts->next=yystack.l_mark[0].mytableatts;
}
break;
case 13:
#line 218 "Parser.y"
	{
	yyval.mytableatts=(struct TableAtts *) malloc (sizeof (struct TableAtts));
	yyval.mytableatts->Op=yystack.l_mark[0].crattr;
	yyval.mytableatts->next=NULL;
}
break;
case 14:
#line 225 "Parser.y"
	{
	yyval.crattr=(struct CrAttr *) malloc (sizeof (struct CrAttr));
	yyval.crattr->value=yystack.l_mark[-1].actualChars;
	yyval.crattr->type=yystack.l_mark[0].actualChars;
}
break;
case 15:
#line 232 "Parser.y"
	{
	attsToSelect = yystack.l_mark[0].myNames;
	distinctAtts = 0;
}
break;
case 16:
#line 238 "Parser.y"
	{
	attsToSelect = NULL;
}
break;
case 17:
#line 243 "Parser.y"
	{
	distinctAtts = 0;
	finalFunction = NULL;
	attsToSelect = yystack.l_mark[0].myNames;
}
break;
case 18:
#line 250 "Parser.y"
	{
	distinctAtts = 1;
	finalFunction = NULL;
	attsToSelect = yystack.l_mark[0].myNames;
	finalFunction = NULL;
}
break;
case 19:
#line 258 "Parser.y"
	{
	distinctFunc = 0;
	finalFunction = yystack.l_mark[-1].myOperator;
}
break;
case 20:
#line 264 "Parser.y"
	{
	distinctFunc = 1;
	finalFunction = yystack.l_mark[-1].myOperator;
}
break;
case 21:
#line 270 "Parser.y"
	{
	yyval.myNames = (struct NameList *) malloc (sizeof (struct NameList));
	yyval.myNames->name = yystack.l_mark[0].actualChars;
	yyval.myNames->next = NULL;
}
break;
case 22:
#line 277 "Parser.y"
	{
	yyval.myNames = (struct NameList *) malloc (sizeof (struct NameList));
	yyval.myNames->name = yystack.l_mark[0].actualChars;
	yyval.myNames->next = yystack.l_mark[-2].myNames;
}
break;
case 23:
#line 284 "Parser.y"
	{
	yyval.myTables = (struct TableList *) malloc (sizeof (struct TableList));
	yyval.myTables->tableName = yystack.l_mark[-2].actualChars;
	yyval.myTables->aliasAs = yystack.l_mark[0].actualChars;
	yyval.myTables->next = NULL;
}
break;
case 24:
#line 292 "Parser.y"
	{
	yyval.myTables = (struct TableList *) malloc (sizeof (struct TableList));
	yyval.myTables->tableName = yystack.l_mark[-2].actualChars;
	yyval.myTables->aliasAs = yystack.l_mark[0].actualChars;
	yyval.myTables->next = yystack.l_mark[-4].myTables;
}
break;
case 25:
#line 302 "Parser.y"
	{
	yyval.myOperator = (struct FuncOperator *) malloc (sizeof (struct FuncOperator));	
	yyval.myOperator->leftOperator = (struct FuncOperator *) malloc (sizeof (struct FuncOperator));
	yyval.myOperator->leftOperator->leftOperator = NULL;
	yyval.myOperator->leftOperator->leftOperand = yystack.l_mark[-2].myOperand;
	yyval.myOperator->leftOperator->right = NULL;
	yyval.myOperator->leftOperand = NULL;
	yyval.myOperator->right = yystack.l_mark[0].myOperator;
	yyval.myOperator->code = yystack.l_mark[-1].whichOne;	

}
break;
case 26:
#line 315 "Parser.y"
	{
	yyval.myOperator = (struct FuncOperator *) malloc (sizeof (struct FuncOperator));	
	yyval.myOperator->leftOperator = yystack.l_mark[-3].myOperator;
	yyval.myOperator->leftOperand = NULL;
	yyval.myOperator->right = yystack.l_mark[0].myOperator;
	yyval.myOperator->code = yystack.l_mark[-1].whichOne;	

}
break;
case 27:
#line 325 "Parser.y"
	{
	yyval.myOperator = yystack.l_mark[-1].myOperator;

}
break;
case 28:
#line 331 "Parser.y"
	{
	yyval.myOperator = (struct FuncOperator *) malloc (sizeof (struct FuncOperator));	
	yyval.myOperator->leftOperator = NULL;
	yyval.myOperator->leftOperand = yystack.l_mark[0].myOperand;
	yyval.myOperator->right = NULL;	

}
break;
case 29:
#line 340 "Parser.y"
	{
	yyval.myOperator = (struct FuncOperator *) malloc (sizeof (struct FuncOperator));	
	yyval.myOperator->leftOperator = yystack.l_mark[0].myOperator;
	yyval.myOperator->leftOperand = NULL;
	yyval.myOperator->right = NULL;	
	yyval.myOperator->code = '-';

}
break;
case 30:
#line 351 "Parser.y"
	{
	yyval.whichOne = '-';
}
break;
case 31:
#line 356 "Parser.y"
	{
	yyval.whichOne = '+';
}
break;
case 32:
#line 361 "Parser.y"
	{
	yyval.whichOne = '*';
}
break;
case 33:
#line 366 "Parser.y"
	{
	yyval.whichOne = '/';
}
break;
case 34:
#line 372 "Parser.y"
	{
        /* here we need to pre-pend the OrList to the AndList*/
        /* first we allocate space for this node*/
        yyval.myAndList = (struct AndList *) malloc (sizeof (struct AndList));

        /* hang the OrList off of the left*/
        yyval.myAndList->left = yystack.l_mark[-3].myOrList;

        /* hang the AndList off of the right*/
        yyval.myAndList->rightAnd = yystack.l_mark[0].myAndList;

}
break;
case 35:
#line 386 "Parser.y"
	{
        /* just return the OrList!*/
        yyval.myAndList = (struct AndList *) malloc (sizeof (struct AndList));
        yyval.myAndList->left = yystack.l_mark[-1].myOrList;
        yyval.myAndList->rightAnd = NULL;
}
break;
case 36:
#line 395 "Parser.y"
	{
        /* here we have to hang the condition off the left of the OrList*/
        yyval.myOrList = (struct OrList *) malloc (sizeof (struct OrList));
        yyval.myOrList->left = yystack.l_mark[-2].myComparison;
        yyval.myOrList->rightOr = yystack.l_mark[0].myOrList;
}
break;
case 37:
#line 403 "Parser.y"
	{
        /* nothing to hang off of the right*/
        yyval.myOrList = (struct OrList *) malloc (sizeof (struct OrList));
        yyval.myOrList->left = yystack.l_mark[0].myComparison;
        yyval.myOrList->rightOr = NULL;
}
break;
case 38:
#line 412 "Parser.y"
	{
        /* in this case we have a simple literal/variable comparison*/
        yyval.myComparison = yystack.l_mark[-1].myComparison;
        yyval.myComparison->left = yystack.l_mark[-2].myBoolOperand;
        yyval.myComparison->right = yystack.l_mark[0].myBoolOperand;
}
break;
case 39:
#line 421 "Parser.y"
	{
        /* construct and send up the comparison*/
        yyval.myComparison = (struct ComparisonOp *) malloc (sizeof (struct ComparisonOp));
        yyval.myComparison->code = LESS_THAN;
}
break;
case 40:
#line 428 "Parser.y"
	{
        /* construct and send up the comparison*/
        yyval.myComparison = (struct ComparisonOp *) malloc (sizeof (struct ComparisonOp));
        yyval.myComparison->code = GREATER_THAN;
}
break;
case 41:
#line 435 "Parser.y"
	{
        /* construct and send up the comparison*/
        yyval.myComparison = (struct ComparisonOp *) malloc (sizeof (struct ComparisonOp));
        yyval.myComparison->code = EQUALS;
}
break;
case 42:
#line 443 "Parser.y"
	{
        /* construct and send up the operand containing the string*/
        yyval.myBoolOperand = (struct Operand *) malloc (sizeof (struct Operand));
        yyval.myBoolOperand->code = STRING;
        yyval.myBoolOperand->value = yystack.l_mark[0].actualChars;
}
break;
case 43:
#line 451 "Parser.y"
	{
        /* construct and send up the operand containing the FP number*/
        yyval.myBoolOperand = (struct Operand *) malloc (sizeof (struct Operand));
        yyval.myBoolOperand->code = DOUBLE;
        yyval.myBoolOperand->value = yystack.l_mark[0].actualChars;
}
break;
case 44:
#line 459 "Parser.y"
	{
        /* construct and send up the operand containing the integer*/
        yyval.myBoolOperand = (struct Operand *) malloc (sizeof (struct Operand));
        yyval.myBoolOperand->code = INT;
        yyval.myBoolOperand->value = yystack.l_mark[0].actualChars;
}
break;
case 45:
#line 467 "Parser.y"
	{
        /* construct and send up the operand containing the name*/
        yyval.myBoolOperand = (struct Operand *) malloc (sizeof (struct Operand));
        yyval.myBoolOperand->code = NAME;
        yyval.myBoolOperand->value = yystack.l_mark[0].actualChars;
}
break;
case 46:
#line 479 "Parser.y"
	{
        /* construct and send up the operand containing the FP number*/
        yyval.myOperand = (struct FuncOperand *) malloc (sizeof (struct FuncOperand));
        yyval.myOperand->code = DOUBLE;
        yyval.myOperand->value = yystack.l_mark[0].actualChars;
}
break;
case 47:
#line 487 "Parser.y"
	{
        /* construct and send up the operand containing the integer*/
        yyval.myOperand = (struct FuncOperand *) malloc (sizeof (struct FuncOperand));
        yyval.myOperand->code = INT;
        yyval.myOperand->value = yystack.l_mark[0].actualChars;
}
break;
case 48:
#line 495 "Parser.y"
	{
        /* construct and send up the operand containing the name*/
        yyval.myOperand = (struct FuncOperand *) malloc (sizeof (struct FuncOperand));
        yyval.myOperand->code = NAME;
        yyval.myOperand->value = yystack.l_mark[0].actualChars;
}
break;
#line 998 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
