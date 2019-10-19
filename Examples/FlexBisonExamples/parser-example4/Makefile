parser.tab.c parser.tab.h: parser.y
  			   bison -d parser.y

lex.yy.c: scanner.l scanner.tab.h
 	  flex scanner.l

parse:  lex.yy.c parser.tab.c parser.tab.h
   	g++ parser.tab.c lex.yy.c -lfl -o parse
