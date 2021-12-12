#include<stdlib.h>
#include "mouvements_helper.h"
#include<stdio.h>
#include<time.h>


void ajout_mouvement_possible(mouvements mouv, mouvements liste_mouvs_possibles[4]){
    /* Boucle dans le tableau pour rajouter le mouvement dans la prochaine case vide du tableau.*/
    int i;
    for (i=0; i< 4; i++){
        if (liste_mouvs_possibles[i] == NONE){
            liste_mouvs_possibles[i] = mouv; 
            return;
        }
    }

}

int is_mouvement_possible(mouvements move, int posLigne, int posColonne, int nbLignes, int nbColonnes){
    mouvements liste_mouvements_possibles[4] = {NONE, NONE, NONE, NONE};
    int i;

    get_possible_keyboard_mouvements(posLigne, posColonne, nbLignes, nbColonnes, liste_mouvements_possibles);


    for(i=0; i < 4; i++){
        if(liste_mouvements_possibles[i] == move){
            return 1;
        }
    }
    return 0;
}

mouvements get_possible_click_mouvement(int posLigne, int posColonne, int nbLignes, int nbColonnes, int grille[8][8]){
    /* Fonction qui retourne le mouvement (équivalent touche clavier) possible avec le click de la souris */

    /* On vérifie si la case concernée n'est pas le trou */
    if (grille[posLigne][posColonne] == 0){
        return NONE; /* Aucun mouvement n'est possible */ 
    }
    /* Check à gauche */
    if (posColonne - 1 >= 0){
        if(grille[posLigne][posColonne -1] == 0){
            return GAUCHE;
        }
    }
    /* Check à droite */
    if (posColonne + 1 < nbColonnes){
        if(grille[posLigne][posColonne + 1] == 0) {
            return DROITE;
        }
    }
    /* Check en bas */
    if (posLigne + 1 < nbLignes){
        if(grille[posLigne + 1][posColonne] == 0){
            return BAS;
        }
    }
    /* Check en haut*/
    if (posLigne - 1 >= nbLignes) {
        if(grille[posLigne -1][posColonne] == 0){
            return HAUT;
        }
    }
    /* Si aucun mouvement n'a été trouvé on retourne NONE */ 
    return NONE;

}

void get_possible_keyboard_mouvements(int posLigne, int posColonne, int nbLignes, int nbColonnes, mouvements liste_mouvs_possibles[4]){
 
   if (posLigne -1 >= 0){
        ajout_mouvement_possible(BAS, liste_mouvs_possibles);
   }
   if (posColonne - 1 >= 0){
        ajout_mouvement_possible(DROITE, liste_mouvs_possibles);
   }
   if (posColonne + 1 < nbColonnes)  {
        ajout_mouvement_possible(GAUCHE, liste_mouvs_possibles);
   }
   if (posLigne + 1 < nbLignes){
        ajout_mouvement_possible(HAUT, liste_mouvs_possibles);
   }
}

mouvements get_random_mouvement(int posLigne, int posColonne, int nbLignes, int nbColonnes){
    /* On se base sur la position du trou pour pouvoir calculer si on peut bouger ou pas 
    La fonction retourne une touche que va pouvoir effectuer le clavier.
    */
    int i;
    int nb_mouvements = 0; 
    mouvements liste_mouvs_possibles[4] = {NONE, NONE, NONE, NONE}; /* On initialise la liste des mouvements par des mouvements non existants */

    get_possible_keyboard_mouvements(posLigne, posColonne, nbLignes, nbColonnes, liste_mouvs_possibles);

    /* Boucle pour savoir le nombre de mouvements possibles et faire de l'aléatoire dessus*/

    for(i=0; i<4; i++){
        if(liste_mouvs_possibles[i] == NONE){
            break;
        }
        nb_mouvements++;
    }

    int nb_choisi = rand() % (nb_mouvements);
    return liste_mouvs_possibles[nb_choisi];
}
