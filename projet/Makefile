#YACCINE ANAS VASILY BENEDICT
CFLAGS = -Wall -Wextra -g

OBJ = tab_lexico.o tab_declarations.o pile.o semantique.o tab_repres.o
OBJDIR=obj 

parser: grammaire.tab.c grammaire.tab.h lex.yy.c $(OBJ)
	gcc -w $(OBJ) grammaire.tab.c lex.yy.c -o parser -lfl

test_tab_repres: src/tab_repres.c include/tab_repres.h
	gcc -w $(CFLAGS) src/tab_repres.c -o test_tab_repres

grammaire.tab.c grammaire.tab.h: grammaire.y
	bison -d grammaire.y -Wcounterexamples

tab_lexico.o: src/tab_lexico.c include/tab_lexico.h
	gcc $(CFLAGS) -c src/tab_lexico.c -o tab_lexico.o

tab_declarations.o: src/tab_decl.c include/tab_decl.h
	gcc $(CFLAGS) -c src/tab_decl.c -o tab_declarations.o

#tab_region.o: src/tab_region.c include/tab_region.h
#	gcc $(CFLAGS) -c src/tab_region.c -o tab_region.o

semantique.o: src/semantique.c include/semantique.h
	gcc $(CFLAGS) -c src/semantique.c -o semantique.o

tab_repres.o: src/tab_repres.c include/tab_repres.h
	gcc $(CFLAGS) -c src/tab_repres.c -o tab_repres.o

pile.o: src/pile.c include/pile.h
	gcc $(CFLAGS) -c src/pile.c -o pile.o

lex.yy.c: grammaire.l grammaire.tab.h
	flex grammaire.l

$(OBJDIR): 
	mkdir -p $(OBJDIR) 

clean:
	rm -f parser grammaire.tab.c *_tab_* grammaire.tab.h lex.yy.c *.o test $(OBJDIR)