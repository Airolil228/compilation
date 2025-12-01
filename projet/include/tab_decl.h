/*Anas et Yacine*/
#ifndef _TABDECL_H_
#define _TABDECL_H_

#include <stdio.h>
#include <stdlib.h>

#define Taille_TAB 5000
#define Zone_de_debordement 500
#define NB_TYPES_DE_BASE 4  /* nombre de types de base prédéfinis */

/*================== Nature ==================*/
/*Anas et Yacine*/
#define TYPE_B 0        /* 0: type de base       (TYPE_B) */
#define TYPE_S 1        /* 1: type structure     (TYPE_S) */
#define TYPE_T 2        /* 2: type tableau       (TYPE_T) */
#define VAR 3           /* 3: variable           (VAR)    */
#define PARAM 4         /* 4: paramètre          (PARAM)  */
#define PROC 5          /* 5: procédure          (PROC)   */
#define FCT 6           /* 6: fonction           (FUNC)   */


/*================== Structure ==================*/
/*Anas et Yacine*/
typedef struct {
    int nature;
    int suivant;
    int region;
    int description;
    int exec;
} TAB_DE_Decl;

extern TAB_DE_Decl tab_de_dec[Taille_TAB];
extern int zone_de_deb_utiliser;
extern int numregion;                       /* region courante */

/*================== Fonctions ==================*/
/*Anas et Yacine*/
/* Initialisation de la table */
void init_tab_decl();

/*Renvoie l'indice la déclaration insérée Sinon -1*/
/*Anas et Yacine*/
int inserer_decl(int lex_id, int nature, int region, int description, int exec);

/*Anas et Yacine*/
void afficher_tab_decl(FILE *flux);

/*Anas et Yacine*/
void afficher_chaine(FILE *flux, int lex_id);

/*Anas et Yacine*/
int association_nom(int idxLex, int typeRecherche);

#endif /* _TABDECL_H */