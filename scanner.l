%{
#include "ast.h"
#include "parser.tab.h"
#include <string.h>
int lineno = 0;
%}
%% 
[ \t] 			                                        { /* eat white spaces */  }
\n                                                      {++lineno;}
bool                                                    {printf("Found: BOOL\n");return BOOL;}
callout                                                 {printf("Found: CALLOUT\n");return CALLOUT;}
char                                                    {printf("Found: CHAR\n");return CHAR;}
declare                                                 {printf("Found: DECLARE\n");return DECLARE;}
else                                                    {printf("Found: ELSE\n");return ELSE;}
false                                                   {printf("Found: FALSE\n");return FALSE;}
for                                                     {printf("Found: FOR\n");return FOR;}
if                                                      {printf("Found: IF\n");return IF;} 
int                                                     {printf("Found: INT\n");return INT;}
Program                                                 {printf("Found: PROGRAM\n");return PROGRAM;}
true                                                    {printf("Found: TRUE\n");return TRUE;}
void                                                    {printf("Found: VOID\n");return VOID;}
while                                                   {printf("Found: WHILE\n");return WHILE;}
=                                                       {printf("Found: ASSIGN\n"); return ASSIGN;}
\'\\n\'                                                 {yylval = (struct ASTNode *) malloc(sizeof(struct ASTNode)); yylval->charLiteral = '\n'; printf("Found: CHAR_LITERAL %c\n",yylval->charLiteral);return CHAR_LITERAL;}
\'\\\a\'                                                {yylval = (struct ASTNode *) malloc(sizeof(struct ASTNode)); yylval->charLiteral = '\a'; printf("Found: CHAR_LITERAL %c\n",yylval->charLiteral);return CHAR_LITERAL;}
\'\\b\'                                                 {yylval = (struct ASTNode *) malloc(sizeof(struct ASTNode)); yylval->charLiteral = '\b'; printf("Found: CHAR_LITERAL %c\n",yylval->charLiteral);return CHAR_LITERAL;}
\'\\f\'                                                 {yylval = (struct ASTNode *) malloc(sizeof(struct ASTNode)); yylval->charLiteral = '\f'; printf("Found: CHAR_LITERAL %c\n",yylval->charLiteral);return CHAR_LITERAL;}
\'\\r\'                                                 {yylval = (struct ASTNode *) malloc(sizeof(struct ASTNode)); yylval->charLiteral = '\r'; printf("Found: CHAR_LITERAL %c\n",yylval->charLiteral);return CHAR_LITERAL;}
\'\\t\'                                                 {yylval = (struct ASTNode *) malloc(sizeof(struct ASTNode)); yylval->charLiteral = '\t'; printf("Found: CHAR_LITERAL %c\n",yylval->charLiteral);return CHAR_LITERAL;}
\'\\v\'                                                 {yylval = (struct ASTNode *) malloc(sizeof(struct ASTNode)); yylval->charLiteral = '\v'; printf("Found: CHAR_LITERAL %c\n",yylval->charLiteral);return CHAR_LITERAL;}
\'\\\\\'                                                {yylval = (struct ASTNode *) malloc(sizeof(struct ASTNode)); yylval->charLiteral = '\\'; printf("Found: CHAR_LITERAL %c\n",yylval->charLiteral);return CHAR_LITERAL;}
\'\\\'\'                                                {yylval = (struct ASTNode *) malloc(sizeof(struct ASTNode)); yylval->charLiteral = '\''; printf("Found: CHAR_LITERAL %c\n",yylval->charLiteral);return CHAR_LITERAL;}
\'\\\"\'                                                {yylval = (struct ASTNode *) malloc(sizeof(struct ASTNode)); yylval->charLiteral = '\"'; printf("Found: CHAR_LITERAL %c\n",yylval->charLiteral);return CHAR_LITERAL;}
\'\\?\'                                                 {yylval = (struct ASTNode *) malloc(sizeof(struct ASTNode)); yylval->charLiteral = '\?'; printf("Found: CHAR_LITERAL %c\n",yylval->charLiteral);return CHAR_LITERAL;}
\'\\0\'                                                 {yylval = (struct ASTNode *) malloc(sizeof(struct ASTNode)); yylval->charLiteral = '\0'; printf("Found: CHAR_LITERAL %c\n",yylval->charLiteral);return CHAR_LITERAL;}                                                           
\'.\'                                                   {yylval = (struct ASTNode *) malloc(sizeof(struct ASTNode)); yylval->charLiteral = yytext[1]; printf("Found: CHAR_LITERAL %c\n",yytext[1]);return CHAR_LITERAL;}
:                                                       {printf("Found: COLON\n");return COLON;}
\]                                                      {printf("Found: CLOSE_ANG\n");return CLOSE_ANG;}
\}                                                      {printf("Found: CLOSE_CURLY\n");return CLOSE_CURLY;}
\)                                                      {printf("Found: CLOSE_PARAN\n");return CLOSE_PARAN;}
,                                                       {printf("Found: COMMA\n");return COMMA;}
[a-zA-Z_][a-zA-Z0-9_]*                                  {printf("Found: ID\n");yylval = (struct ASTNode *)malloc(sizeof(struct ASTNode)); yylval->stringLiteral = (char *)malloc((strlen(yytext)+1)*sizeof(char)); strcpy(yylval->stringLiteral, yytext);return ID;}
-?[0-9]+                                                {printf("Found: INT_LITERAL\n");yylval = (struct ASTNode *)malloc(sizeof(struct ASTNode)); yylval->intLiteral=atoi(yytext); return INT_LITERAL;}
\[                                                      {printf("Found: OPEN_ANG\n");return OPEN_ANG;}
\{                                                      {printf("Found: OPEN_CURLY\n");return OPEN_CURLY;}
\(                                                      {printf("Found: OPEN_PARAN\n");return OPEN_PARAN;}
\?                                                      {printf("Found: QM\n");return QM;}
\"(\\.|[^"\\])*\"                                       {printf("Found: STRING_LITERAL: %s\n", yytext);yylval = (struct ASTNode *)malloc(sizeof(struct ASTNode));yylval->stringLiteral = (char *)malloc((strlen(yytext))*sizeof(char)); strncpy(yylval->stringLiteral, yytext+1, strlen(yytext)-2);return STRING_LITERAL;}
;                                                       {printf("Found: SEMICOLON\n");return SEMICOLON;}
\|\|                                                    {printf("Found: LOGICAL_OR\n");return LOGICAL_OR;}
&&                                                      {printf("Found: LOGICAL_AND\n");return LOGICAL_AND;}
==                                                      {printf("Found: EQUALITY\n");return EQUALITY;}
!=                                                      {printf("Found: NONEQUALITY\n");return NONEQUALITY;}
\<                                                      {printf("Found: LESSTHAN\n");return LESSTHAN;}
\>                                                      {printf("Found: LESSTHAN\n");return GREATERTHAN;}
\<=                                                     {printf("Found: LEQ\n");return LEQ;}
\>=                                                     {printf("Found: GEQ\n");return GEQ;}
-                                                       {printf("Found: SUB\n");return SUB;}
\+                                                      {printf("Found: ADD\n");return ADD;}
\*                                                      {printf("Found: MULTIPLY\n");return MULTIPLY;}
\/                                                      {printf("Found: DIVIDE\n");return DIVIDE;}
%                                                       {printf("Found: MODULO\n");return MODULO;}
!                                                       {printf("Found: LOGICAL_NOT\n");return LOGICAL_NOT;}
.			                                            {printf("Line No %d: Unrecognized character '%c'\n", lineno, yytext[0]);}
        