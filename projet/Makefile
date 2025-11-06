CFLAGS = -Wall -Wextra -g

parser: grammaire.tab.c grammaire.tab.h lex.yy.c
	gcc grammaire.tab.c lex.yy.c -o parser -lfl

test: src/tab_lexico.c test.c
	gcc $(CFLAGS) -o test test.c src/tab_lexico.c

grammaire.tab.c grammaire.tab.h : grammaire.y
	bison -d grammaire.y  -Wcounterexamples 

lex.yy.c : grammaire.l grammaire.tab.h
	flex grammaire.l

test_tab_lexico: src/tab_lexico.c 
	gcc $(CFLAGS) -o test_tab_lexico src/tab_lexico.c 

clean:
	rm -f parser grammaire.tab.c grammaire.tab.h lex.yy.c