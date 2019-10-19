%{
#include <string.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;
#include "parser.tab.h"
int lineno = 0;
%}

%% 
[ \t] 		{ /* eat white spaces */  }
[a-zA-Z]+[0-9]*	{      int i=0;
		       for(i = 0; i<5;i++)
			yylval.sval[i] = yytext[i]; yylval.sval[i]='\0'; return IDENTIFIER; }
[0-9]+          { yylval.ival = atoi(yytext); return DIGIT;}
[+|-]           { int i=0;
                       for(i = 0; i<1;i++)
                        yylval.sval[i] = yytext[i]; yylval.sval[i]='\0';return OP;}
\n		{ ++lineno; return '\n'; }
.		{ printf("Line No %d: Unrecognized character '%c'\n", lineno, yytext[0]);}

