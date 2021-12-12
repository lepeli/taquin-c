#ifndef MOUVEMENTS_CONTROLLER_H

#define MOUVEMENTS_CONTROLLER_H
#include"mouvements_helper.h"
#endif

void find_pos_trou(int* posLigne, int* posColonne, int nbLignes, int nbColonnes, int grille[8][8]);
void do_random_move(int grille[8][8], int nbLignes, int nbColonnes);

void keyboard_move_grille(mouvements move, int grille[8][8], int nbLignes, int nbColonnes);
void click_move_grille();
void move_element_grille(mouvements move, int grille[8][8], int nbLignes, int nbColonnes);