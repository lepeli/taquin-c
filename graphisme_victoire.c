#include<stdlib.h>
#include<stdio.h>
#include<graph.h>

#include"graphisme_victoire.h"
#include"constants.h"


void ecranvictoire(void){
    couleur c;
    ChoisirEcran(2);
    ChargerImageFond("./images/xp.jpg");
    ChargerImage("./images/victorydenis.png",350,150,0,0,480,359);
    c=CouleurParNom("red");
    ChoisirCouleurDessin(c);
    EcrireTexte(100,100,"VIKTOIRRRRRRRRRRR !!!!!!!!!",1); /* marche pas */
    CopierZone(2,0,0,0,LONGFENETR,HAUTFENETR,0,0);
    c=CouleurParNom("gray");
    ChoisirCouleurDessin(c);
    RemplirRectangle(400,650,150,50);
    c=CouleurParNom("black");
    ChoisirCouleurDessin(c);
    DessinerRectangle(400,650,150,50);

    CopierZone(2,0,0,0,LONGFENETR,HAUTFENETR,0,0);

    while (1){
        if (SourisCliquee()){
            if (_X>=400 && _X<=550 && _Y>=650 && _Y<=700){
                FermerGraphique();
                break;
            }
        }
    }

}