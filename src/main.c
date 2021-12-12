#include<stdlib.h>
#include<stdio.h>
#include<graph.h>

#include"graphisme_accueil.h"
#include"generateur.h"
#include"decoupagev2.h"
#include"constants.h"
#include"jeu.h"

/* 
Point d'entrée du programme du taquin. Celui qui va gérer tous les appels des différentes parties.
*/


/* @TO DO: Faire l'ordre des appels ici */

int main(void){
    while (1){
    int grille[8][8]; /* On initialise ici la grille du taquin pour pouvoir l'utiliser ensuite */
    int nbColonnes, nbLignes;
    int choiximage;
    InitialiserGraphique();
    CreerFenetre(0,0, LONGFENETR, HAUTFENETR);
    ChoisirTitreFenetre("Taquin");
    choiximage = ecranmenu(&nbLignes, &nbColonnes);

    ChoisirTitreFenetre("Taquin");
    deroulejeu(grille, nbLignes, nbColonnes, choiximage);
    return EXIT_SUCCESS;
    }
}
