calc: calc.y calc.l ast.c ast.h 
		bison -d calc.y
		flex calc.l
		gcc -o calc ast.c calc.tab.c lex.yy.c -lfl

clean: 
		rm calc.tab.c calc.tab.h lex.yy.c