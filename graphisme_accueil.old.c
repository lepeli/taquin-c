#include<graph.h>
#include<stdlib.h>
#include<stdio.h>

#include"graphisme_accueil.h"
#include"constants.h"

void ecrantitre(void){

	int x,y; /* pour pos souris */

	x=_X; /* pour pos souris */
	y=_Y; /* pour pos souris */

	int choiximage=0;
	couleur c;
	int nbrlignes=3;
	int hauteurImage;
	int LargeurImage;
	int curseurClavierLigne=0;
	int curseurClavierColonne=0;

	KeySym t;

	InitialiserGraphique();

	ChoisirEcran(1);
	CreerFenetre(0,0,LONGFENETR,HAUTFENETR);
	ChoisirTitreFenetre("Taquin");
	c=CouleurParNom("black");
	ChoisirCouleurDessin(c);
	ChargerImageFond("./images/xp.jpg");
	ChargerImage("./images/logo2.png",525,0,0,0,150,150);
	ChargerImage("./images/ani2.jpg",25,350,0,0,350,350); /* image 1 */ 
	ChargerImage("./images/ani3.jpg",487,350,0,0,350,350); /* image 2 */
	ChargerImage("./images/ani4.jpg",950,350,0,0,350,350); /* image 3 */
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
			ChargerImage("./images/tailles.png",584,295,5,5,32,30);
		}

		if (nbrlignes==4){
			ChargerImage("./images/tailles.png",584,295,47,5,32,30);
		}

		if (nbrlignes==5){
			ChargerImage("./images/tailles.png",584,295,87,5,32,30);
		}

		if (nbrlignes==6){
			ChargerImage("./images/tailles.png",584,295,127,5,32,30);
		}

		if (nbrlignes==7){
			ChargerImage("./images/tailles.png",584,295,167,5,32,30);
		}

		if (nbrlignes==8){
			ChargerImage("./images/tailles.png",584,295,206,5,32,30);
		}

		if (choiximage==1){
			c=CouleurParNom("red");
			ChoisirCouleurDessin(c);
			DessinerRectangle(25,350,225,225);
			c=CouleurParNom("black");
			ChoisirCouleurDessin(c);
			DessinerRectangle(487,350,225,225);
			DessinerRectangle(950,350,225,225);
			/* hauteurImage=640; */
			/* largeurImage=960; */
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

		/* début curseurClavier */
		
		if (curseurClavierLigne == 1 && curseurClavierColonne == 1){
		  c=CouleurParNom("red");
		  ChoisirCouleurDessin(c);
		  RemplirTriangle(620,295,634,310,620,325);
		}

		/* début curseurClavier */

		if (ToucheEnAttente()){
		  t=Touche();
		  if (curseurClavierLigne == 0 && curseurClavierColonne == 0) {
		    curseurClavierLigne=1;
		    curseurClavierColonne=1;
		  } else {
		    /* gestion pour chaque touche (haut/bas = ligne + 1 si possible, gauche/droite = colonne + 1 si possible) */
		  }
		}

		/* début curseurClavier */

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
