%{
int lineno = 0;
%}

%% 
[a-zA-Z0-9+-]	{ return yytext[0]; }
\n		{ ++lineno; }
.		{ printf("Line No %d: Unrecognized character '%c'\n", lineno, yytext[0]);}
