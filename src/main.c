#include<stdlib.h>
#include<stdio.h>
#include<graph.h>

#include"graphisme_victoire.h"
#include"graphisme_accueil.h"
#include"generateur.h"
#include"decoupagev2.h"
#include"constants.h"
/* 
Point d'entrée du programme du taquin. Celui qui va gérer tous les appels des différentes parties.
*/


/* @TO DO: Faire l'ordre des appels ici */

int main(void){
    int grille[8][8]; /* On initialise ici la grille du taquin pour pouvoir l'utiliser ensuite */
    int nbColonnes, nbLignes;
    int choiximage;
    InitialiserGraphique();
    CreerFenetre(0,0, LONGFENETR, HAUTFENETR);
    choiximage = ecranmenu(&nbLignes, &nbColonnes);

    generation_grille(grille, nbLignes, nbColonnes);

    ChoisirTitreFenetre("Taquin");
    printgrille(grille, nbLignes, nbColonnes, choiximage);

    return EXIT_SUCCESS;
}
