#pragma once
#include "tab_lexico.h"
#include "tab_decl.h"
/*#include "tab_regions.h"*/

/* init global (à appeler avant yyparse) */
/*Anas Yaccine*/
void sem_init(void);

/* lexème → index (insère si absent) */
/*Anas Yaccine*/
int sem_ident(const char *yytext);

/* déclarations */
/*Anas Yaccine*/
void sem_decl_var(int id_lex, int type_code, int taille_type);

/* fin des déclarations globales (fixe taille reg 0) */
/*Anas Yaccine*/
void sem_fin_globaux(void);

/* debug */
/*Anas Yaccine*/
void sem_dump(void);

