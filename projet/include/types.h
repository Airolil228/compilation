#define TAB_LEXICO_H 499
#define MAX_LONGUEUR_LEXEME  50

struct lexeme_unit {
    int longueur_lexeme;                           /* longueur du lexeme */
    char lexeme[MAX_LONGUEUR_LEXEME];              /* le lexeme */
    int suivant;                                   /* index du prochain element en cas de collision */
};


struct lexeme_unit tab_lexico[TAB_LEXICO_H];   /* table de hachage des lexemes */
int nb_elements_tab_lexico = 0;                /* nombre d'elements dans la table lexico */
