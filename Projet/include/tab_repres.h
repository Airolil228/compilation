#ifndef TAB_REPRES_H
#define TAB_REPRES_H

/* Ce module a été réaliser par Vasily */
#define MAX_TAB_REPRES 500

extern int tab_repres_entet[MAX_TAB_REPRES]; 
extern int deplacement_courant[100];  /* Déplacement pour chaque région */

void insereTabRepres(int val);
void insereNbchampsTabReprese(int index_nb_champs,int nb_champs);
int taille_tab_repres();
void initDepl(); 
int deplacer(int taille);
int getTaille(int ind_decl);
void init_tab_repres();
void afficher_tab_repres();
int sauvegarde_tab_repres(FILE *f);
int charger_tab_repres(FILE *f);


#endif /* TAB_REPRES_H */