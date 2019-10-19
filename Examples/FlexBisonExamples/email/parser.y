%{
  #include <stdio.h>
  #include <iostream>
  using namespace std;
  // Explain how to generate more that one info tuples using the production. 
  // stuff from flex that bison needs to know about:
  // left derivation and right derivation 
  extern int yylex();
  extern int yyparse();
  extern FILE *yyin;
  void yyerror(char *s);
%}

%token  NAME 
%token  EMAIL
%token  ROLL
%token  BRACE
%%

Goal:     BRACE NAME EMAIL ROLL BRACE '\n'
	| Goal BRACE NAME EMAIL ROLL BRACE '\n'
	;

%%

void yyerror(char *s)
{
        fprintf(stderr, "error: %s\n", s);
}


main(int argc, char **argv)
{
        yyparse();
        printf("Parsing Over\n");
}



