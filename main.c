#include<stdlib.h>
#include<stdio.h>
#include<graph.h>

#include"graphisme_victoire.h"
#include"graphisme_accueil.h"
#include"generateur.h"
#include"decoupagev2.h"

#define LONGFENETR 1200
#define HAUTFENETR 800

/* 
Point d'entrée du programme du taquin. Celui qui va gérer tous les appels des différentes parties.
*/


/* @TO DO: Faire l'ordre des appels ici */

int main(void){
    int grille[8][8]; /* On initialise ici la grille du taquin pour pouvoir l'utiliser ensuite */
    generation_grille(grille, 3, 3);
    InitialiserGraphique();
    CreerFenetre(0,0, LONGFENETR, HAUTFENETR);
    ChoisirTitreFenetre("Taquin");
    printcase(grille, 3,3);
    /* ecrantitre(); */

    return EXIT_SUCCESS;
}
