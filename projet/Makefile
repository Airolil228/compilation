parser: grammaire.tab.c grammaire.tab.h lex.yy.c
	gcc grammaire.tab.c lex.yy.c -o parser -lfl

grammaire.tab.c grammaire.tab.h : grammaire.y
	bison -d grammaire.y  -Wcounterexamples 

lex.yy.c : grammaire.l grammaire.tab.h
	flex grammaire.l


clean: 
	rm -f parser grammaire.tab.c grammaire.tab.h lex.yy.c