%{
#include "parser.tab.h"
int lineno = 0;
%}

%% 
[ \t] 			{ /* eat white spaces */  }
[a-zA-Z][a-zA-Z]* 	{ printf("Found ID: %s\n", yytext); return ID; }
[0-9][0-9]*		{ printf("Found NUMBER: %s\n", yytext); return NUMBER; }
[+-]			{ printf("Found %c\n", yytext[0]); return yytext[0]; }
\n			{ ++lineno; return '\n'; }
.			{ printf("Line No %d: Unrecognized character '%c'\n", lineno, yytext[0]);}
