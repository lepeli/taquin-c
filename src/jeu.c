#include<graph.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"mouvements_controller.h"
#include"generateur.h"
#include"mouvements_helper.h"
#include"graphisme_victoire.h"

int haswon(int grille_resolue[8][8], int grille[8][8]){
    int i,j;

    for(i=0; i < 8; i++){
        for(j=0; j < 8; j++){
            if(grille[i][j] != grille_resolue[i][j]){
                return 0; /* La grille n'a pas été résolue puisqu'un élément est différent d'une grille résolue */
            }
        }
    }
    return 1; /* La grille est résolue, let's goo gg wp*/
}

void deroulejeu(int grille[8][8], int nblignes, int nbcolonnes, int choiximage){
    int victory = 0;
    int grille_resolue[8][8];
    int largeurimage, hauteurimage;
    int casecliquee=-1, lignecliquee=-1;
    initialisation_grille(nblignes, nbcolonnes, grille_resolue);
    generation_grille(grille, nblignes, nbcolonnes);


    int nbcoups=0;
    int var1, var2;

    int possible;

    KeySym t;
    int x,y;

    x=_X; 
    y=_Y;

    if (choiximage == 1){
        largeurimage=600;
        hauteurimage=399;
    }

    if (choiximage == 2){
        largeurimage=500;
        hauteurimage=500;
    }

    if (choiximage == 3){
        largeurimage=600;
        hauteurimage=339;
    }

    printgrille(grille, nblignes, nbcolonnes, choiximage);

    while (victory!=1){
        
        if (SourisCliquee()){
            SourisPosition();
            if (_X>700 && _X <700+largeurimage && _Y>0 && _Y < hauteurimage){
                nbcoups++;
                for (var1 = 700; var1 < _X ; var1=var1+(largeurimage/nbcolonnes)){
                    casecliquee++;
                }
                for (var2=0; var2 < _Y ; var2=var2+(hauteurimage/nblignes)){
                    lignecliquee++;
                }
                printf("Case cliquée : %d / Ligne cliquée : %d\n", casecliquee, lignecliquee);
                possible = click_move_grille(grille, lignecliquee, casecliquee, nblignes, nbcolonnes);

                if (possible == 1){ /* si mouvement possible, alors on reprint les cases comme il faut (le mouvement a déjà été interprété dans la grille) */
                    printgrille(grille, nblignes, nbcolonnes, choiximage);
                    victory = haswon(grille_resolue, grille);

                }
            }
            
            casecliquee=-1;
            lignecliquee=-1;

        }
        
        if (ToucheEnAttente()){
            t=Touche();
            if (t == XK_Left){
                keyboard_move_grille(GAUCHE, grille, nblignes, nbcolonnes);
            }
            if (t == XK_Right){
                keyboard_move_grille(DROITE, grille, nblignes, nbcolonnes);
            }
            if (t == XK_Up){
                keyboard_move_grille(HAUT, grille, nblignes, nbcolonnes);
            }
            if (t == XK_Down){
                keyboard_move_grille(BAS, grille, nblignes, nbcolonnes);
            }

            printgrille(grille, nblignes, nbcolonnes, choiximage);
            victory = haswon(grille_resolue, grille);

        }


        
    }
    if(victory == 1){
            ecranvictoire();
    }
}