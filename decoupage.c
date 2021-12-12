#include <graph.h>
#include <stdio.h> // pour pos_souris
#include <stdlib.h>
#include <string.h>
#define LONGFENETR 1400
#define HAUTFENETR 800

void ecrantitre(void){

	int x,y; // pour pos souris

	x=_X; // pour pos souris
	y=_Y; // pour pos souris

	int choiximage;
	couleur c;
	int nbrlignes=3;


	InitialiserGraphique();

	ChoisirEcran(1);
	CreerFenetre(0,0,LONGFENETR,HAUTFENETR);
	ChoisirTitreFenetre("Taquin");
	c=CouleurParNom("black");
	ChoisirCouleurDessin(c);
	ChargerImageFond("./xp.jpg");
	ChargerImage("./logo2.png",525,0,0,0,150,150);
	ChargerImage("./ani2.jpg",25,350,0,0,350,350); // image 1 
	ChargerImage("./ani3.jpg",487,350,0,0,350,350); // image 2
	ChargerImage("./ani4.jpg",950,350,0,0,350,350); // image 3
	DessinerRectangle(25,350,225,225);
	DessinerRectangle(487,350,225,225);
	DessinerRectangle(950,350,225,225);
	c=CouleurParNom("gray");
	ChoisirCouleurDessin(c);
	RemplirRectangle(400,650,150,50);
	RemplirRectangle(650,650,150,50);
	c=CouleurParNom("black");
	ChoisirCouleurDessin(c);
	DessinerRectangle(400,650,150,50);
	DessinerRectangle(650,650,150,50);
	EcrireTexte(448,682,"Jouer",1);
	EcrireTexte(694,682,"Quitter",1);
	EcrireTexte(200,250,"Veuillez selectionner votre image et le nombre de lignes / colonnes voulues :",1);
	RemplirTriangle(620,295,634,310,620,325);
	RemplirTriangle(580,295,566,310,580,325);

	while (1){

		if (nbrlignes==3){
			ChargerImage("./tailles.png",584,295,5,5,32,30);
		}

		if (nbrlignes==4){
			ChargerImage("./tailles.png",584,295,47,5,32,30);
		}

		if (nbrlignes==5){
			ChargerImage("./tailles.png",584,295,87,5,32,30);
		}

		if (nbrlignes==6){
			ChargerImage("./tailles.png",584,295,127,5,32,30);
		}

		if (nbrlignes==7){
			ChargerImage("./tailles.png",584,295,167,5,32,30);
		}

		if (nbrlignes==8){
			ChargerImage("./tailles.png",584,295,206,5,32,30);
		}

		if (choiximage==1){
			c=CouleurParNom("red");
			ChoisirCouleurDessin(c);
			DessinerRectangle(25,350,225,225);
			c=CouleurParNom("black");
			ChoisirCouleurDessin(c);
			DessinerRectangle(487,350,225,225);
			DessinerRectangle(950,350,225,225);
			//hauteurImage=640;
			//largeurImage=960;
		}

		if (choiximage==2){
			c=CouleurParNom("red");
			ChoisirCouleurDessin(c);
			DessinerRectangle(487,350,225,225);
			c=CouleurParNom("black");
			ChoisirCouleurDessin(c);
			DessinerRectangle(25,350,225,225);
			DessinerRectangle(950,350,225,225);

		}

		if (choiximage==3){
			c=CouleurParNom("red");
			ChoisirCouleurDessin(c);
			DessinerRectangle(950,350,225,225);
			c=CouleurParNom("black");
			ChoisirCouleurDessin(c);
			DessinerRectangle(25,350,225,225);
			DessinerRectangle(487,350,225,225);
		}

		CopierZone(1,0,0,0,LONGFENETR,HAUTFENETR,0,0);

		if (SourisCliquee()){

			SourisPosition();
			if (_X!=x||_Y!=y)
			{
			printf("x=%3d:y=%3d\n",_X,_Y);
			x=_X;
			y=_Y;
			}

			if (_X>=620 && _X<=634 && _Y>=295 && _Y<=325 && nbrlignes<8){
				nbrlignes++;
			}

			if (_X>=566 && _X<=580 && _Y>=295 && _Y<=325 && nbrlignes>3){
				nbrlignes--;
			}


			if (_X>=25 && _X<=250 && _Y>=350 && _Y<=575){
				choiximage=1;
			}

			if (_X>=487 && _X<=712 && _Y>=350 && _Y<=575){
				choiximage=2;
			}

			if (_X>=950 && _X<=1175 && _Y>=350 && _Y<=575){
				choiximage=3;
			}

			if (_X>=650 && _X<=800 && _Y>=650 && _Y<=700){
				FermerGraphique();
			}

			if (_X>=400 && _X<=550 && _Y>=650 && _Y<=700){
				break;
			}
		}
	}


}

void printcase(int casevoulue){

	couleur coul;

	coul=CouleurParNom("black");
	ChoisirCouleurDessin(coul);

 int hauteurimage, largeurimage, lignevoulue, colonnevoulue;
 int choiximage;
  int decoupage;
  choiximage=2;
  decoupage=3;
  int bouclehauteur=0, bouclelargeur=0;
  int decalage=0,decalagehauteur=0;

  int hauteurimagecree=0, largeurimagecree=0;

  int lignecase=0;

  int x,y;
  int largeurcasecree, hauteurcasecree;

  int suite[]={2,0,8,5,3,4,6,7,1};
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

  // autres choix image
 
   if (choiximage==1){
  while(bouclehauteur != decoupage){
    while(bouclelargeur != decoupage){
      ChargerImage("./iut.png",700+largeurimagecree+decalage,hauteurimagecree+decalagehauteur,largeurimagecree+5, hauteurimagecree, largeurimage/decoupage, hauteurimage/decoupage);
      largeurimagecree=largeurimagecree+(largeurimage/decoupage);
      bouclelargeur++;
      decalage=decalage+5;
    }
    hauteurimagecree=hauteurimagecree+(hauteurimage/decoupage);
    largeurimagecree=0;
    bouclelargeur=0;
    bouclehauteur++;
    decalage=0;
    decalagehauteur=decalagehauteur+5;
 }
 }
   for (x=0; x<decoupage; x++){
     lignecase=0;
     for (y=0; y<decoupage; y++){
       casevoulue=suite[compteursuite];

     	      printf("%d ", casevoulue); // pour vérif
       compteursuite++;
   while(casevoulue>=decoupage){
     casevoulue=casevoulue-decoupage;
     lignecase++;
   }

   // decoupage par ligne / colonne indépendant

   // bug de boucle --> les cases à afficher correspondent mais sont pas bien affichées :/ 

   largeurcasecree=largeurimage/decoupage*casevoulue; // corriger ça et ça devrait être bon pour le réarrangement 
   hauteurcasecree=(hauteurimage/decoupage)*lignecase; // ça aussi, à voir
      ChargerImage("./victorydenis.png",700+largeurimagecree+decalage,hauteurimagecree+decalagehauteur,largeurcasecree+5, hauteurcasecree, largeurimage/decoupage, hauteurimage/decoupage);
      largeurimagecree=largeurimagecree+(largeurimage/decoupage);

      bouclelargeur++;
      decalage=decalage+5;
     }
    hauteurimagecree=hauteurimagecree+(hauteurimage/decoupage);
    largeurimagecree=0;
    bouclelargeur=0;
    bouclehauteur++;
    decalage=0;
    decalagehauteur=decalagehauteur+5;
    printf("\n"); // pour vérif
 }

  
  CopierZone(3,0,0,0,LONGFENETR,HAUTFENETR,0,0);

  // gestion des coordonnées
  
 

}

void ecranjeu(int choiximage){

  couleur c;
  int suite[]={2,4,8,1,3,5,6,7,0};
  int i;

  for (i=0; i<1; i++){
    printcase(suite[i]);
  }

  Touche();
 
  
}

void ecranvictoire(void){

	couleur c;
	
	ChoisirEcran(2);
	ChargerImageFond("./xp.jpg");
	ChargerImage("./victorydenis.png",350,150,0,0,480,359);
	c=CouleurParNom("red");
	ChoisirCouleurDessin(c);
	EcrireTexte(100,100,"VIKTOIRRRRRRRRRRR !!!!!!!!!",1); // marche pas trop
	CopierZone(2,0,0,0,1200,800,0,0);
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





void pos_souris(){ // affiche la pos de la souris dans la console à chaque clic
	char t[50];
	int x,y,ty,tx;   
	couleur c;
	tx=LONGFENETR;
	ty=HAUTFENETR;
 
	c=CouleurParNom("black"); 
	SourisPosition();
	x=_X;
	y=_Y;
	while(1)
	{	if (SourisCliquee()){
		SourisPosition();
		if (_X!=x||_Y!=y)
		{
			printf("x=%3d:y=%3d\n",_X,_Y);
			x=_X;
			y=_Y;
		}
	}
	}
}


void affichage(void){ /*Gère l'affichage de l'écran titre */

	while(1){
		ecrantitre();
		ecranjeu(1);
		//ecranvictoire();
		//pos_souris();
	}
}


int main(void){
	affichage();
}
