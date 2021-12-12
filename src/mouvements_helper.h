#ifndef MOUVEMENTS_HELPER_H

#define MOUVEMENTS_HELPER_H

typedef enum {DROITE, GAUCHE, HAUT, BAS, NONE} mouvements;
/*

Les mouvements correspondent aux touches du clavier.

DROITE: 0
GAUCHE: 1
HAUT: 2
BAS: 3
NONE: 4

*/
mouvements get_possible_click_mouvement(int posLigne, int posColonne, int nbLignes, int nbColonnes, int grille[8][8]);
mouvements get_random_mouvement(int posLigne, int posColonne, int nbLignes, int nbColonnes);
int is_mouvement_possible(mouvements move, int posLigne, int posColonne, int nbLignes, int nbColonnes);
void get_possible_keyboard_mouvements(int posLigne, int posColonne, int nbLignes, int nbColonnes, mouvements liste_mouvs_possibles[4]);

#endif
