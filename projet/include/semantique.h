#pragma once
#include "tab_lexico.h"
#include "tab_decl.h"
/*#include "tab_regions.h"*/

/* init global (à appeler avant yyparse) */
void sem_init(void);

/* lexème → index (insère si absent) */
int sem_ident(const char *yytext);

/* déclarations */
void sem_decl_var(int id_lex, int type_code, int taille_type);

/* fin des déclarations globales (fixe taille reg 0) */
void sem_fin_globaux(void);

/* debug */
void sem_dump(void);

