%{
#include "parser.tab.h"
int lineno = 0;
%}

%% 
[ \t] 			                                { /* eat white spaces */  }
\n                                              {++lineno;}
bool                                            {printf("Found: BOOL\n");return BOOL;}
break                                           {printf("Found: BREAK\n");return BREAK;}
callout                                         {printf("Found: CALLOUT\n");return CALLOUT;}
char                                            {printf("Found: CHAR\n");return CHAR;}
continue                                        {printf("Found: CONTINUE\n");return CONTINUE;}
declare                                         {printf("Found: DECLARE\n");return DECLARE;}
else                                            {printf("Found: ELSE\n");return ELSE;}
false                                           {printf("Found: FALSE\n");return FALSE;}
for                                             {printf("Found: FOR\n");return FOR;}
if                                              {printf("Found: IF\n");return IF;} 
int                                             {printf("Found: INT\n");return INT;}
Program                                         {printf("Found: PROGRAM\n");return PROGRAM;}
return                                          {printf("Found: RETURN\n");return RETURN;}
true                                            {printf("Found: TRUE\n");return TRUE;}
uint                                            {printf("Found: UINT\n");return UINT;}
void                                            {printf("Found: VOID\n");return VOID;}
while                                           {printf("Found: WHILE\n");return WHILE;}
class                                           {printf("Found: CLASS\n"); return CLASS;}
=                                               {printf("Found: ASSIGN\n"); return ASSIGN;}
\'.\'                                           {printf("Found: CHAR_LITERAL\n");return CHAR_LITERAL;}
\'\\(\a|\b|\f|\n|\r|\t|\v|\\|\'|\"|\?|\0)\'     {printf("Found: CHAR_LITERAL\n");return CHAR_LITERAL;}
\]                                              {printf("Found: CLOSE_ANG\n");return CLOSE_ANG;}
\}                                              {printf("Found: CLOSE_CURLY\n");return CLOSE_CURLY;}
\)                                              {printf("Found: CLOSE_PARAN\n");return CLOSE_PARAN;}
:                                               {printf("Found: COLON\n");return COLON;}
,                                               {printf("Found: COMMA\n");return COMMA;}
[a-zA-Z_][a-zA-Z0-9_]*                          {printf("Found: ID\n");return ID;}
[0-9]+                                          {printf("Found: INT_LITERAL\n");return INT_LITERAL;}
\[                                              {printf("Found: OPEN_ANG\n");return OPEN_ANG;}
\{                                              {printf("Found: OPEN_CURLY\n");return OPEN_CURLY;}
\(                                              {printf("Found: OPEN_PARAN\n");return OPEN_PARAN;}
\?                                              {printf("Found: QM\n");return QM;}
\"(\\.|[^"\\])*\"                               {printf("Found: STRING_LITERAL: %s\n", yytext);return STRING_LITERAL;}
;                                               {printf("Found: SEMICOLON\n");return SEMICOLON;}
\|\|                                            {printf("Found: LOGICAL_OR\n");return LOGICAL_OR;}
&&                                              {printf("Found: LOGICAL_AND\n");return LOGICAL_AND;}
==                                              {printf("Found: EQUALITY\n");return EQUALITY;}
!=                                              {printf("Found: NONEQUALITY\n");return NONEQUALITY;}
\<                                              {printf("Found: LESSTHAN\n");return LESSTHAN;}
\>                                              {printf("Found: LESSTHAN\n");return GREATERTHAN;}
\<=                                             {printf("Found: LEQ\n");return LEQ;}
\>=                                             {printf("Found: GEQ\n");return GEQ;}
-                                               {printf("Found: SUB\n");return SUB;}
\+                                              {printf("Found: ADD\n");return ADD;}
\*                                              {printf("Found: MULTIPLY\n");return MULTIPLY;}
\/                                              {printf("Found: DIVIDE\n");return DIVIDE;}
%                                               {printf("Found: MODULO\n");return MODULO;}
!                                               {printf("Found: LOGICAL_NOT\n");return LOGICAL_NOT;}
.			                                    {printf("Line No %d: Unrecognized character '%c'\n", lineno, yytext[0]);}
