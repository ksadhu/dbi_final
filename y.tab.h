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
extern YYSTYPE yylval;
