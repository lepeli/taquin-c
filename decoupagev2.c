#include <graph.h>
#include <stdio.h> /* pour pos_souris */
#include <stdlib.h>
#include <string.h>
#include"constants.h"

void printcase(int grille[8][8], int decoupageligne, int decoupagecolonne){
    int casevoulue;
    int caseactuelle;
    couleur coul;

    coul=CouleurParNom("black");
    ChoisirCouleurDessin(coul);

    int hauteurimage, largeurimage, lignevoulue, colonnevoulue;
    int choiximage;
    choiximage=2;
    int bouclehauteur=0, bouclelargeur=0;
    int decalage=0,decalagehauteur=0;

    int hauteurimagecree=0, largeurimagecree=0;

    int lignecase=0;

    int x,y;
    int largeurcasecree, hauteurcasecree;

    int compteursuite=0;

    ChoisirEcran(3);

    EffacerEcran(coul);

    if (choiximage==1){
        largeurimage=600;
        hauteurimage=399;
        ChargerImage("./images/iut.png",0,0,0,0,600,399);
    }

    if (choiximage==2){
        largeurimage=480;
        hauteurimage=359;
        ChargerImage("./images/victorydenis.png",0,0,0,0,480,359);
    }

    /* autres choix image */

    for (x=0; x < decoupageligne; x++){
        for (y=0; y < decoupagecolonne; y++){

        lignecase=0;

        /* à utiliser :  */
        /* decoupagecolonne / decoupageligne / suite */
        caseactuelle = grille[x][y];
        casevoulue=grille[x][y]; /* à intégrer avec fonction random */

        /* pour déroulé jeu : possibilité de reparcourir ce code avec un "cache" pour ne charger l'image que quand il y a besoin d'un changement */

        printf("%d ", casevoulue); /* pour vérif */
        while(casevoulue>=decoupagecolonne){
            casevoulue=casevoulue-decoupagecolonne;
            lignecase++;
        }

        largeurcasecree=largeurimage/decoupagecolonne*casevoulue; 
        hauteurcasecree=hauteurimage/decoupageligne*lignecase;
        if(caseactuelle != 0){
            ChargerImage("./images/victorydenis.png",700+largeurimagecree+decalage,hauteurimagecree+decalagehauteur,largeurcasecree, hauteurcasecree, largeurimage/decoupagecolonne, hauteurimage/decoupageligne);
        } else{
            ChargerImage("./images/victorydenis.png",700+largeurimagecree+decalage,hauteurimagecree+decalagehauteur,8000, 980000, largeurimage/decoupagecolonne, hauteurimage/decoupageligne);

        }
            largeurimagecree=largeurimagecree+(largeurimage/decoupagecolonne);

        decalage=decalage+5;
        }
    hauteurimagecree=hauteurimagecree+(hauteurimage/decoupageligne);
    largeurimagecree=0;
    bouclelargeur=0;
    bouclehauteur++;
    decalage=0;
    decalagehauteur=decalagehauteur+5;
    printf("\n"); /* pour vérif */

    }

    CopierZone(3,0,0,0,LONGFENETR,HAUTFENETR,0,0);

    /* gestion des coordonnées */

    Touche();


}

