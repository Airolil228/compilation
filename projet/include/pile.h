#define PILE_H
#define PILE_H

typedef struct Element {
    int Element;
    struct Element* suivant;
} Element;

typedef struct Pile {
    Element* sommet;
} Pile;

typedef Pile* pile;

pile creer_pile();

void empiler(pile pile, int Element);
int depiler(pile pile);
int est_vide(pile pile);

void liberer_pile(pile pile);

#endif /* PILE_H */