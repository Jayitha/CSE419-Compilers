%{
    #include<stdio.h>
    #include "evaluate.h"
    #define YYSTYPE struct ASTNode *
    #include "parser.tab.h"
%}
%define api.value.type { struct ASTNode * }

%token ASSIGN
%token BOOL
%token CALLOUT
%token CHAR
%token CHAR_LITERAL
%token CLOSE_ANG
%token CLOSE_CURLY
%token CLOSE_PARAN
%token COLON
%token COMMA
%token DECLARE
%token ELSE
%token FALSE
%token FOR
%token ID
%token IF
%token INT
%token INT_LITERAL
%token OPEN_ANG
%token OPEN_CURLY
%token OPEN_PARAN
%token PROGRAM
%token QM
%token STRING_LITERAL
%token SEMICOLON
%token TRUE
%token VOID
%token WHILE

%left LOGICAL_OR
%left LOGICAL_AND
%nonassoc EQUALITY NONEQUALITY LESSTHAN GREATERTHAN LEQ GEQ
%left SUB ADD
%left MULTIPLY DIVIDE MODULO
%right LOGICAL_NOT

%%

program: PROGRAM OPEN_CURLY var_decls method_decls CLOSE_CURLY {
           $$ = getASTNodeProgram($3, $4, BOTH_PROGRAM); 
           printf("\n\n\n");
           printf("-------------------------------------------------------------\n");
           printf("                         POSTFIX AST                         \n");
           printf("-------------------------------------------------------------\n");
           printPostFix($$);
           printf("\n\n\n");
           printf("-------------------------------------------------------------\n");
           printf("                         INTERPRETER                         \n");
           printf("-------------------------------------------------------------\n");
           evaluate($$);
           }
       | PROGRAM OPEN_CURLY method_decls CLOSE_CURLY {
           $$ = getASTNodeProgram(NULL,$3, METHOD_DECLS_ONLY_PROGRAM);
           printf("\n\n\n");
           printf("-------------------------------------------------------------\n");
           printf("                         POSTFIX AST                         \n");
           printf("-------------------------------------------------------------\n"); 
           printPostFix($$);
           printf("\n\n\n");
           printf("-------------------------------------------------------------\n");
           printf("                         INTERPRETER                         \n");
           printf("-------------------------------------------------------------\n");
           evaluate($$);}
       | PROGRAM OPEN_CURLY var_decls CLOSE_CURLY {
           $$ = getASTNodeProgram($3, NULL, VAR_DECLS_ONLY_PROGRAM);
           printf("\n\n\n");
           printf("-------------------------------------------------------------\n");
           printf("                         POSTFIX AST                         \n");
           printf("-------------------------------------------------------------\n");  
           printPostFix($$);
           printf("\n\n\n");
           printf("-------------------------------------------------------------\n");
           printf("                         INTERPRETER                         \n");
           printf("-------------------------------------------------------------\n");
           evaluate($$);}
;
var_decls: var_decl var_decls {$$ = getASTNodeVarDecls($1, $2);}
         | var_decl {$$ = getASTNodeVarDecls($1, NULL);}
;
var_decl: DECLARE type location SEMICOLON {$$ = getASTNodeVarDecl($2, $3);}
;
method_decls: method_decl method_decls {$$ = getASTNodeMethodDecls($1, $2);}
            | method_decl {$$ = getASTNodeMethodDecls($1, NULL);}
;
method_decl: ID OPEN_PARAN method_args CLOSE_PARAN block {$$ = getASTNodeMethodDecl($1->stringLiteral, $3, $5);}
;

method_args: VOID {$$ = getASTNodeMethodArgs(NULL, NULL, VOID_METHODARGSTYPE);}
           | method_arg COMMA method_args {$$ = getASTNodeMethodArgs($1, $2, MULTIPLE_METHODARGSTYPE);}
           | method_arg {$$ = getASTNodeMethodArgs($1, NULL, NONVOID_METHODARGSTYPE);}
;
method_arg: type ID {$$ = getASTNodeMethodArg($1, $2->stringLiteral, NULL, NULL, SINGLE_METHODARGTYPE);}
          | type ID OPEN_ANG INT_LITERAL CLOSE_ANG {$$ = getASTNodeMethodArg($1, $2->stringLiteral, $4, NULL, ARRAY_METHODARGTYPE);}
          | type ID OPEN_ANG INT_LITERAL CLOSE_ANG OPEN_ANG INT_LITERAL CLOSE_ANG {$$ = getASTNodeMethodArg($1, $2->stringLiteral, $4, $7, MATRIX_METHODARGTYPE);}
;
block: OPEN_CURLY var_decls statements CLOSE_CURLY {$$ = getASTNodeBlock($2, $3, BOTH_BLOCKTYPE);}
     | OPEN_CURLY statements CLOSE_CURLY {$$ = getASTNodeBlock(NULL, $2, STATEMENTS_ONLY_BLOCKTYPE);}
     | OPEN_CURLY var_decls CLOSE_CURLY {$$ = getASTNodeBlock($2, NULL, VAR_DECLS_ONLY_BLOCKTYPE);}
;
statements: statement statements {$$ = getASTNodeStatements($1, $2);}
          | statement {$$ = getASTNodeStatements($1, NULL);}
;
statement: location ASSIGN expr SEMICOLON {$$ = getASTNodeStatement($1, $3, NULL, NULL, NULL, ASSIGNMENT_STATEMENTTYPE);}
         | method_call SEMICOLON {$$ = getASTNodeStatement($1, NULL, NULL, NULL, NULL, METHOD_CALL_STATEMENTTYPE);}
         | if_else_statment {$$ = getASTNodeStatement($1, NULL, NULL, NULL, NULL, IFTHENELSE_STATEMENTTYPE);}
         | expr QM block COLON block {$$ = getASTNodeStatement($1, $3, $5, NULL, NULL, TERNARY_STATEMENTTYPE);}
         | WHILE OPEN_PARAN expr CLOSE_PARAN block {$$ = getASTNodeStatement($3, $5, NULL, NULL, NULL, WHILE_STATEMENTTYPE);}
         | FOR OPEN_PARAN expr SEMICOLON statement CLOSE_PARAN block {$$ = getASTNodeStatement($3, $5, $7, NULL, NULL, FOR_STATEMENTTYPE);}
         | block {$$ = getASTNodeStatement($1, NULL, NULL, NULL, NULL, BLOCK_STATEMENTTYPE);}
;
if_else_statment: IF OPEN_PARAN expr CLOSE_PARAN block {$$ = getASTNodeIfElse($3, $5, NULL);}
                | IF OPEN_PARAN expr CLOSE_PARAN block ELSE block {$$ = getASTNodeIfElse($3, $5, $7);}
;
method_call: CALLOUT OPEN_PARAN STRING_LITERAL CLOSE_PARAN {$$ = getASTNodeMethodCall($3, NULL);}
           | CALLOUT OPEN_PARAN STRING_LITERAL COMMA callout_args CLOSE_PARAN {$$ = getASTNodeMethodCall($3, $5);}
;
callout_args: expr COMMA callout_args {$$ = getASTNodeCalloutArgs($1, $3);}
            | expr {$$ = getASTNodeCalloutArgs($1, NULL);}
;
expr: location {$$ = getASTNodeExpr($1, NULL, LOCATION_EXPRTYPE);}
    | literal {$$ = getASTNodeExpr($1, NULL, LITERAL_EXPRTYPE);}
    | expr ADD expr {$$ = getASTNodeExpr($1, $3, ADD_EXPRTYPE);}
    | expr SUB expr {$$ = getASTNodeExpr($1, $3, SUB_EXPRTYPE);}
    | expr MULTIPLY expr {$$ = getASTNodeExpr($1, $3, MUL_EXPRTYPE);}
    | expr DIVIDE expr {$$ = getASTNodeExpr($1, $3, DIV_EXPRTYPE);}
    | expr MODULO expr {$$ = getASTNodeExpr($1, $3, MOD_EXPRTYPE);}
    | expr LEQ expr {$$ = getASTNodeExpr($1, $3, LEQ_EXPRTYPE);}
    | expr GEQ expr {$$ = getASTNodeExpr($1, $3, GEQ_EXPRTYPE);}
    | expr LESSTHAN expr {$$ = getASTNodeExpr($1, $3, LESSTHAN_EXPRTYPE);}
    | expr GREATERTHAN expr {$$ = getASTNodeExpr($1, $3, GREATERTHAN_EXPRTYPE);}
    | expr EQUALITY expr {$$ = getASTNodeExpr($1, $3, EQUALITY_EXPRTYPE);}
    | expr NONEQUALITY expr {$$ = getASTNodeExpr($1, $3, NONEQUALITY_EXPRTYPE);}
    | expr LOGICAL_OR expr {$$ = getASTNodeExpr($1, $3, LOGICAL_OR_EXPRTYPE);}
    | expr LOGICAL_AND expr {$$ = getASTNodeExpr($1, $3, LOGICAL_AND_EXPRTYPE);}
    | SUB expr {$$ = getASTNodeExpr($2, NULL, UNISUB_EXPRTYPE);}
    | LOGICAL_NOT expr {$$ = getASTNodeExpr($2, NULL, LOGICAL_NOT_EXPRTYPE);}
    | OPEN_PARAN expr CLOSE_PARAN {$$ = getASTNodeExpr($2, NULL, EXPR_PARAN_EXPRTYPE);}
;
location: ID {$$ = getASTNodeLocation($1->stringLiteral, NULL, NULL, SINGLE_LOCATIONTYPE);}
        | ID OPEN_ANG expr CLOSE_ANG {$$ = getASTNodeLocation($1->stringLiteral, $3, NULL, ARRAY_LOCATIONTYPE);}
        | ID OPEN_ANG expr CLOSE_ANG OPEN_ANG expr CLOSE_ANG {$$ = getASTNodeLocation($1->stringLiteral, $3, $6, MATRIX_LOCATIONTYPE);}
;

literal: INT_LITERAL {$$ = getASTNodeINTLiteral($1->intLiteral);}
       | CHAR_LITERAL {$$ = getASTNodeCHARLiteral($1->charLiteral);}
       | bool_literal {$$ = $1;}
       | STRING_LITERAL {$$ = getASTNodeSTRINGLiteral($1->stringLiteral);}
;
bool_literal: TRUE {$$ = getASTNodeBOOLLiteral(TRUE_BOOL);}
            | FALSE {$$ = getASTNodeBOOLLiteral(FALSE_BOOL);}
;

type: INT {$$ = getASTNodeType(INT_TYPETYPE);}
    | BOOL {$$ = getASTNodeType(BOOL_TYPETYPE);}
    | CHAR {$$ = getASTNodeType(CHAR_TYPETYPE);}
;
%%
yyerror(char *s)
{
        fprintf(stderr, "error: %s\n", s);
}
main(int argc, char **argv)
{
        printf("-------------------------------------------------------------\n");
        printf("                        SCANNER OUTPUT                       \n");
        printf("-------------------------------------------------------------\n");
        yyparse();
        printf("Parsing Over\n");
}

