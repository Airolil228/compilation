/*Anas et Yacine*/
#pragma once
#include "tab_lexico.h"
#include "tab_decl.h"
#include "pile.h"
#include "tab_regions.h"


/* init global (à appeler avant yyparse) */
void sem_init(void);

/* lexème → index (insère si absent) */
int sem_ident(const char *yytext);

/* déclarations de variables globales / locales */
void sem_decl_var(int id_lex, int type_code, int taille_type);

/* déclaration d’un paramètre formel */
void sem_decl_param(int id_lex, int type_code, int offset);

/* déclaration d’une fonction */
void sem_decl_fct(int id_lex, int type_retour, int etiq_exec);

/* déclaration d’une procédure */
void sem_decl_proc(int id_lex, int etiq_exec);

/* déclaration d’un type de base nommé (alias) */
void sem_decl_type_base(int id_lex, int code_type);

/* déclaration d’un type struct (monType1) */
void sem_decl_struct(int id_lex, int region_champs, int taille_struct);

/* déclaration d’un type tableau */
void sem_decl_tab(int id_lex, int type_elem, int borne_inf, int borne_sup);

/* fin des déclarations globales (fixe taille reg 0) */
void sem_fin_globaux(void);

/* debug */
void sem_dump(void);
