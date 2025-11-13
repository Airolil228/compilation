CFLAGS = -Wall -Wextra -g

OBJ = tab_lexico.o tab_declarations.o pile.o tab_region.o

parser: grammaire.tab.c grammaire.tab.h lex.yy.c $(OBJ)
	gcc $(OBJ) grammaire.tab.c lex.yy.c -o parser -lfl

test: test.c pile.o 
	gcc pile.o test.c -o test -lfl

grammaire.tab.c grammaire.tab.h: grammaire.y
	bison -d grammaire.y -Wcounterexamples

tab_lexico.o: src/tab_lexico.c include/tab_lexico.h
	gcc $(CFLAGS) -c src/tab_lexico.c -o tab_lexico.o

tab_declarations.o: src/tab_decl.c include/tab_decl.h
	gcc $(CFLAGS) -c src/tab_decl.c -o tab_declarations.o

tab_region.o: src/tab_region.c include/tab_region.h
	gcc $(CFLAGS) -c src/tab_region.c -o tab_region.o

pile.o: src/pile.c include/pile.h
	gcc $(CFLAGS) -c src/pile.c -o pile.o

lex.yy.c: grammaire.l grammaire.tab.h
	flex grammaire.l

clean:
	rm -f parser grammaire.tab.c *_tab_* grammaire.tab.h lex.yy.c *.o test