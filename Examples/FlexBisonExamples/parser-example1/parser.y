%{
  #include <stdio.h>
  #include <iostream>
  using namespace std;

  // stuff from flex that bison needs to know about:
  extern int yylex();
  extern int yyparse();
  extern FILE *yyin;
  void yyerror(char *s);
%}

%%

Goal:	Expr '\n'
	| Goal Expr '\n' { cout << $1 <<"  " <<$2 <<endl; }
	;

Expr: 	Expr Op Term
	| Term
	;

Term:	Number 
	| Id
	;

Op:	'+'
	| '-'
	;

Id:	Alpha Id { cout << $1 <<"  " <<$2 <<endl; }
	| Alpha 
	;

Alpha: 'a' | 'b' | 'c' | 'd' | 'e' | 'f' | 'g' | 'h'
   	| 'i' | 'j' | 'k' | 'l' | 'm' | 'n' | 'o' | 'p'
	| 'q' | 'r' | 's' | 't' | 'u' | 'v' | 'w' | 'x' | 'y' | 'z'
	| 'A' | 'B' | 'C' | 'D' | 'E' | 'F' | 'G' | 'H'
        | 'I' | 'J' | 'K' | 'L' | 'M' | 'N' | 'O' | 'P'
        | 'Q' | 'R' | 'S' | 'T' | 'U' | 'V' | 'W' | 'X' | 'Y' | 'Z'
	;

Number: Number Digit { cout << $1 <<"  " <<$2 <<endl; }
	| Digit
	;

Digit: '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
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



