#include <graph.h>
#include <stdio.h> /* pour pos_souris */
#include <stdlib.h>
#include <string.h>
#define LONGFENETR 1400
#define HAUTFENETR 800

void printcase(int casevoulue){

	couleur coul;

	coul=CouleurParNom("black");
	ChoisirCouleurDessin(coul);

 int hauteurimage, largeurimage, lignevoulue, colonnevoulue;
 int choiximage;
 int decoupageligne, decoupagecolonne;
  choiximage=2;
  decoupageligne=4;
  decoupagecolonne=4;
  int bouclehauteur=0, bouclelargeur=0;
  int decalage=0,decalagehauteur=0;

  int hauteurimagecree=0, largeurimagecree=0;

  int lignecase=0;

  int x,y;
  int largeurcasecree, hauteurcasecree;

  int suite[]={1,0,8,5,3,4,6,7,2,10,9,11,12,14,13,15};
  int compteursuite=0;
  
  ChoisirEcran(3);

  EffacerEcran(coul);

  if (choiximage==1){
    largeurimage=600;
    hauteurimage=399;
    ChargerImage("./iut.png",0,0,0,0,600,399);
  }

   if (choiximage==2){
    largeurimage=480;
    hauteurimage=359;
    ChargerImage("./victorydenis.png",0,0,0,0,480,359);
  }

   /* autres choix image */

   for (x=0; x<decoupageligne; x++){
     for (y=0; y<decoupagecolonne; y++){
       
     lignecase=0;
       casevoulue=suite[compteursuite];

       printf("%d ", casevoulue); /* pour vérif */
       compteursuite++;
   while(casevoulue>=decoupagecolonne){
     casevoulue=casevoulue-decoupagecolonne;
     lignecase++;
   }

   largeurcasecree=largeurimage/decoupagecolonne*casevoulue; 
   hauteurcasecree=hauteurimage/decoupageligne*lignecase;
      ChargerImage("./victorydenis.png",700+largeurimagecree+decalage,hauteurimagecree+decalagehauteur,largeurcasecree, hauteurcasecree, largeurimage/decoupagecolonne, hauteurimage/decoupageligne);
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

