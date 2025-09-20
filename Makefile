arith1: y.tab.c lex.yy.o 
	gcc  y.tab.c -o arith1 lex.yy.o

lex.yy.o:lex.yy.c
	gcc -c lex.yy.c

lex.yy.c:arith1.l
	lex arith1.l

y.tab.c:arith1.y
	yacc -d arith1.y




