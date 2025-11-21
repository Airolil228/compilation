#ifndef TAB_REPRES_H
#define TAB_REPRES_H

#define MAX_TAB_REPRES 500

extern int tab_repres_entet[MAX_TAB_REPRES]; 

void insereTabRepres(int val);
void insereNbchampsTabReprese(int index_nb_champs,int nb_champs);
int taille_tab_repres();

#endif /* TAB_REPRES_H */