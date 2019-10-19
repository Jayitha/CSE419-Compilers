%{
#include <string.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;
#include "parser.tab.h"
int lineno = 0;
// Remove the space at rhe end of the emai and name and see what happens and why ? 
%}

%% 
[ \t] 		{ /* eat white spaces */  }
[a-zA-z]+[@][a-z]+[.][c][o][m][\ ]+     {printf("\n %s", yytext); return EMAIL;}
[a-zA-Z]+[\ ]*[a-zA-Z]+[\ ]+		{printf("\n %s", yytext);return NAME; }
[0-9]+          		        {printf("\n %s", yytext);return ROLL;}
[\{|\}]        			        {return BRACE;}
\n				        { ++lineno; return '\n'; }
.				        { printf("Line No %d: Unrecognized character '%c'\n", lineno, yytext[0]);}
