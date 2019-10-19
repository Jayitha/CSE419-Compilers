%{
	#include <iostream>
	using namespace std;
	extern int yylex();
%}
%option noyywrap

%%
[ \t\n]	;
[a-zA-z]+[@][a-z]+[.][c][o][m] {cout <<" email found: " <<yytext<<endl;}
%%

int main(int, char**){

	while(yylex());
} 
