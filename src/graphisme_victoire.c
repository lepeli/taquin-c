#include<stdlib.h>
#include<stdio.h>
#include<graph.h>

#include"graphisme_victoire.h"
#include"constants.h"


void ecranvictoire(void){
    int sortir;
    couleur c;
    ChoisirEcran(2);
    ChargerImageFond("./images/xp.jpg");
    ChargerImage("./images/victorydenis.png",350,150,0,0,480,359);
    c=CouleurParNom("red");
    ChoisirCouleurDessin(c);
    EcrireTexte(100,100,"VIKTOIRRRRRRRRRRR !!!!!!!!!",1); /* marche pas */
    CopierZone(2,0,0,0,LONGFENETR,HAUTFENETR,0,0);

    ChargerImage("./images/ecrantitre.png",LONGFENETR/2-(151*3/2),650,0,0,151,51);
    ChargerImage("./images/quitter.png",LONGFENETR/2+(151*2/3)-23,650,0,0,151,51);

    CopierZone(2,0,0,0,LONGFENETR,HAUTFENETR,0,0);

    while (sortir!=1){
        if (SourisCliquee()){
            if (_X>=LONGFENETR/2+(151*2/3)-23 && _X<=LONGFENETR/2+(151*2/3)-23+151 && _Y>=650 && _Y<=701){
                FermerGraphique();
                /* On quitte le programme */
            }
            if (_X>=LONGFENETR/2-(151*3/2) && _X<=LONGFENETR/2-(151*3/2)+151 && _Y>=650 && _Y<=701){
                sortir=1;
        }
    }
    }
}