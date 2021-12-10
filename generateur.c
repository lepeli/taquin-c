#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"generateur.h"
#include"mouvements_controller.h"
#include"mouvements_helper.h"



void initialisation_grille(int nbLignes, int nbColonnes, int tab[8][8]){
    /* 
        Initialise la grille 
        Le 0 dans la grille correspondra au trou
    */
    int i,j; 

    for(i=0; i < 8; i++){
        for(j=0; j<8; j++){
            tab[i][j] = -1;
        }
    }

    for(i=0; i < (nbLignes * nbColonnes); i++){
        tab[i / nbColonnes][i%nbColonnes] = i; /* On insère les chiffres pour créer une grille initiale */ 
    }

}

void generation_grille(int grille[8][8], int nbLignes, int nbColonnes){
    /* On vient initialiser la grille puis faire des mouvements aléatoires jusqu'à ce qu'elle soit mélangée*/
    int i;
    srand(time(NULL));
    initialisation_grille(nbLignes, nbColonnes, grille);

    for(i=0; i< (20*(nbColonnes * nbLignes)); i++){
        do_random_move(grille, nbLignes, nbColonnes);
    }
}