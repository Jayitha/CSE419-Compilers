%{
  #include <iostream>
  using namespace std;
  extern int yylex();
%}
%%
[ \t\n]          ;
[a-zA-Z]+[\ ]+[A][a-z]+wal     { cout << "Found one " << yytext << endl; }
.                ;
%%

int main()
{
  // open a file handle to a particular file:
  FILE *myfile = fopen("names.csv", "r");
  // make sure it's valid:
  if (!myfile) {
    cout << "I can't open file!" << endl;
    return -1;
  }
  // set lex to read from it instead of defaulting to STDIN:
  yyin = myfile;
  
  // lex through the input:
  while(yylex());
}
