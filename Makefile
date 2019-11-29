parser: scanner.l parser.y ast.c ast.h evaluate.c evaluate.h
	bison -d --report=state parser.y
	flex scanner.l
	gcc -Wall -o parser evaluate.c ast.c lex.yy.c parser.tab.c -lfl

clean:
	rm lex.yy.c parser.tab.c parser.tab.h

