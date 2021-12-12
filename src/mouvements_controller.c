#include<stdio.h>
#include<stdlib.h>
#include "mouvements_helper.h"
#include "mouvements_controller.h"


void find_pos_trou(int* posLigne, int* posColonne, int nbLignes, int nbColonnes, int grille[8][8]){
    int j, i;
    for(i=0; i < nbLignes; i++){
        for(j=0; j < nbColonnes; j++){
            if(grille[i][j] == 0){
                *posLigne = i;
                *posColonne = j;
                return;
            }
        }
    }
}

void do_random_move(int grille[8][8], int nbLignes, int nbColonnes){
    int posLigne, posColonne;
    find_pos_trou(&posLigne, &posColonne, nbLignes, nbColonnes, grille);
    mouvements random_move = get_random_mouvement(posLigne, posColonne, nbLignes, nbColonnes);
    keyboard_move_grille(random_move, grille, nbLignes, nbColonnes);
}

int keyboard_move_grille(mouvements move, int grille[8][8], int nbLignes, int nbColonnes){
    /* On modifie la grille après avoir reçu le mouvements depuis les évenements clavier */
    int posLigne, posColonne;
    int mv_possible;

    find_pos_trou(&posLigne, &posColonne, nbLignes, nbColonnes, grille);

    /* Ajouter truc pour trouver la position colonne et la ligne*/ 
    mv_possible = is_mouvement_possible(move, posLigne, posColonne, nbLignes, nbColonnes);

    if(mv_possible){
        move_element_grille(move, grille, nbLignes, nbColonnes);
        return 1;
    }
    return 0;

}

int click_move_grille(int grille[8][8], int posLigne, int posColonne, int nbLignes, int nbColonnes){
    mouvements move_possible = get_possible_click_mouvement(posLigne, posColonne, nbLignes, nbColonnes, grille);
    if(move_possible == NONE){
        return 0;
    }

    move_element_grille(move_possible, grille, nbLignes, nbColonnes);
    return 1;
}


void move_element_grille(mouvements move, int grille[8][8], int nbLignes, int nbColonnes){
    /* On bouge les éléments ici */
    int posLigne, posColonne;
    find_pos_trou(&posLigne, &posColonne, nbLignes, nbColonnes, grille);

    if(move == HAUT){
        grille[posLigne][posColonne] = grille[posLigne + 1][posColonne];
        grille[posLigne + 1][posColonne] = 0;
    }

    if(move == BAS){
        grille[posLigne][posColonne] = grille[posLigne - 1][posColonne];
        grille[posLigne - 1][posColonne] = 0;
    }

    if(move == DROITE){
        grille[posLigne][posColonne] = grille[posLigne][posColonne - 1];
        grille[posLigne][posColonne - 1] = 0;
    }

    if(move == GAUCHE){
        grille[posLigne][posColonne] = grille[posLigne][posColonne + 1];
        grille[posLigne][posColonne + 1] = 0;
    }

}