bison -d parser.y;
flex scanner.l;
g++ -std=c++11 parser.tab.c lex.yy.c -lfl -o parse

