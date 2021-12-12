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

	int choiximage=0;
	couleur c;
	int nbrlignes=3;
	int nbrcolonnes=3;
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
	ChargerImageFond("./xp.jpg");
	ChargerImage("./logo2.png",LONGFENETR/2-150/2,0,0,0,150,150);
	
	ChargerImage("./iuttitre.png",25,350,0,0,337,225); // image 1
	ChargerImage("./valochetitre.png",LONGFENETR/2-225/2,350,0,0,225,225); // image 2
	ChargerImage("./charmingtitre.png",LONGFENETR-398-25,350,0,0,398,225); // image 3
	
	DessinerRectangle(25,350,337,225); // cadre img 1
	DessinerRectangle(LONGFENETR/2-225/2,350,225,225); // cadre img 2
	DessinerRectangle(LONGFENETR-398-25,350,398,225); // cadre img 3

	ChargerImage("./jouer.png",LONGFENETR/2-(151*3/2),650,0,0,151,51);
	ChargerImage("./quitter.png",LONGFENETR/2+(151*2/3)-23,650,0,0,151,51);
	
	EcrireTexte(375,215,"Veuillez selectionner votre image et le nombre de lignes / colonnes voulues :",1);

	EcrireTexte(585,275,"Lignes",1);
	EcrireTexte(742,275,"Colonnes",1);
	
	RemplirTriangle(LONGFENETR/2-105,295,LONGFENETR/2-119,310,LONGFENETR/2-105,325);
	RemplirTriangle(LONGFENETR/2-100+37,295,LONGFENETR/2-100+51,310,LONGFENETR/2-100+37,325);
	
	RemplirTriangle(LONGFENETR/2+100-32+37,295,LONGFENETR/2+100-32+51,310,LONGFENETR/2+100-32+37,325);
	RemplirTriangle(LONGFENETR/2+100-32-5,295,LONGFENETR/2+100-32-19,310,LONGFENETR/2+100-32-5,325);

	while (1){

		if (nbrlignes==3){
		  ChargerImage("./tailles.png",LONGFENETR/2-100,295,5,5,32,30);
		}

		if (nbrlignes==4){
		  ChargerImage("./tailles.png",LONGFENETR/2-100,295,47,5,32,30);
		}

		if (nbrlignes==5){
		  ChargerImage("./tailles.png",LONGFENETR/2-100,295,87,5,32,30);
		}

		if (nbrlignes==6){
		  ChargerImage("./tailles.png",LONGFENETR/2-100,295,127,5,32,30);
		}

		if (nbrlignes==7){
		  ChargerImage("./tailles.png",LONGFENETR/2-100,295,167,5,32,30);
		}

		if (nbrlignes==8){
		  ChargerImage("./tailles.png",LONGFENETR/2-100,295,206,5,32,30);
		}

		if (nbrcolonnes==3){
		  ChargerImage("./tailles.png",LONGFENETR/2+100-32,295,5,5,32,30);
		}

		if (nbrcolonnes==4){
		  ChargerImage("./tailles.png",LONGFENETR/2+100-32,295,47,5,32,30);
		}

		if (nbrcolonnes==5){
		  ChargerImage("./tailles.png",LONGFENETR/2+100-32,295,87,5,32,30);
		}

		if (nbrcolonnes==6){
		  ChargerImage("./tailles.png",LONGFENETR/2+100-32,295,127,5,32,30);
		}

		if (nbrcolonnes==7){
		  ChargerImage("./tailles.png",LONGFENETR/2+100-32,295,167,5,32,30);
		}

		if (nbrcolonnes==8){
		  ChargerImage("./tailles.png",LONGFENETR/2+100-32,295,206,5,32,30);
		}

		if (choiximage==1){
			c=CouleurParNom("red");
			ChoisirCouleurDessin(c);
			DessinerRectangle(25,350,337,225);
			c=CouleurParNom("black");
			ChoisirCouleurDessin(c);
			DessinerRectangle(LONGFENETR/2-225/2,350,225,225);
			DessinerRectangle(LONGFENETR-398-25,350,398,225);
			//hauteurImage=640;
			//largeurImage=960;
		}

		if (choiximage==2){
			c=CouleurParNom("red");
			ChoisirCouleurDessin(c);
			DessinerRectangle(LONGFENETR/2-225/2,350,225,225);
			c=CouleurParNom("black");
			ChoisirCouleurDessin(c);
			DessinerRectangle(25,350,337,225);
			DessinerRectangle(LONGFENETR-398-25,350,398,225);

		}

		if (choiximage==3){
			c=CouleurParNom("red");
			ChoisirCouleurDessin(c);
			DessinerRectangle(LONGFENETR-398-25,350,398,225);
			c=CouleurParNom("black");
			ChoisirCouleurDessin(c);
			DessinerRectangle(25,350,337,225);
			DessinerRectangle(LONGFENETR/2-225/2,350,225,225);
		}

		CopierZone(1,0,0,0,LONGFENETR,HAUTFENETR,0,0);

		// début curseurClavier

	

		if (curseurClavierLigne == 1){
		    c=CouleurParNom("black");
		    ChoisirCouleurDessin(c);
		    ChargerImage("./valochetitre.png",LONGFENETR/2-225/2,350,0,0,225,225);
		    DessinerRectangle(LONGFENETR/2-225/2,350,225,225);
		    ChargerImage("./iuttitre.png",25,350,0,0,337,225);
		    DessinerRectangle(25,350,337,225);
		    ChargerImage("./charmingtitre.png",LONGFENETR-398-25,350,0,0,398,225);
		    DessinerRectangle(LONGFENETR-398-25,350,398,225);
		  if (curseurClavierColonne == 1){
		    c=CouleurParNom("blue");
		    ChoisirCouleurDessin(c);
		    RemplirTriangle(LONGFENETR/2-105,295,LONGFENETR/2-119,310,LONGFENETR/2-105,325);
		    
		    c=CouleurParNom("black");
		    ChoisirCouleurDessin(c);
		    RemplirTriangle(LONGFENETR/2-100+37,295,LONGFENETR/2-100+51,310,LONGFENETR/2-100+37,325);
		   }
		  if (curseurClavierColonne == 2){
		    c=CouleurParNom("blue");
		    ChoisirCouleurDessin(c);
		    RemplirTriangle(LONGFENETR/2-100+37,295,LONGFENETR/2-100+51,310,LONGFENETR/2-100+37,325);
		    
		    c=CouleurParNom("black");
		    ChoisirCouleurDessin(c);
		    RemplirTriangle(LONGFENETR/2-105,295,LONGFENETR/2-119,310,LONGFENETR/2-105,325);
		    RemplirTriangle(LONGFENETR/2+100-32-5,295,LONGFENETR/2+100-32-19,310,LONGFENETR/2+100-32-5,325);
		  }
		  if (curseurClavierColonne == 3){
		    c=CouleurParNom("blue");
		    ChoisirCouleurDessin(c);
		   RemplirTriangle(LONGFENETR/2+100-32-5,295,LONGFENETR/2+100-32-19,310,LONGFENETR/2+100-32-5,325);
		   
		   c=CouleurParNom("black");
		    ChoisirCouleurDessin(c);
		    RemplirTriangle(LONGFENETR/2-100+37,295,LONGFENETR/2-100+51,310,LONGFENETR/2-100+37,325);
		    RemplirTriangle(LONGFENETR/2+100-32+37,295,LONGFENETR/2+100-32+51,310,LONGFENETR/2+100-32+37,325);
		  }
		  if (curseurClavierColonne == 4){
		    c=CouleurParNom("blue");
		    ChoisirCouleurDessin(c);
		    RemplirTriangle(LONGFENETR/2+100-32+37,295,LONGFENETR/2+100-32+51,310,LONGFENETR/2+100-32+37,325);
		    
		    c=CouleurParNom("black");
		    ChoisirCouleurDessin(c);
		    RemplirTriangle(LONGFENETR/2+100-32-5,295,LONGFENETR/2+100-32-19,310,LONGFENETR/2+100-32-5,325);
		    
		  }
		}

		if (curseurClavierLigne == 2){
		    c=CouleurParNom("black");
		    ChoisirCouleurDessin(c);
		    RemplirTriangle(LONGFENETR/2-105,295,LONGFENETR/2-119,310,LONGFENETR/2-105,325);
		    RemplirTriangle(LONGFENETR/2-100+37,295,LONGFENETR/2-100+51,310,LONGFENETR/2-100+37,325);
		    RemplirTriangle(LONGFENETR/2+100-32+37,295,LONGFENETR/2+100-32+51,310,LONGFENETR/2+100-32+37,325);
		    RemplirTriangle(LONGFENETR/2+100-32-5,295,LONGFENETR/2+100-32-19,310,LONGFENETR/2+100-32-5,325);

		    ChargerImage("./jouer.png",LONGFENETR/2-(151*3/2),650,0,0,151,51);
		    ChargerImage("./quitter.png",LONGFENETR/2+(151*2/3)-23,650,0,0,151,51);
		    
		  
		  if (curseurClavierColonne == 1){
		    c=CouleurParNom("blue");
		    ChoisirCouleurDessin(c);
		    RemplirTriangle(360,520,300,573,360,573);
		    c=CouleurParNom("black");
		    ChoisirCouleurDessin(c);
		    ChargerImage("./valochetitre.png",LONGFENETR/2-225/2,350,0,0,225,225);
		    DessinerRectangle(LONGFENETR/2-225/2,350,225,225);
		    
		  }
		  if (curseurClavierColonne == 2){
		    c=CouleurParNom("blue");
		    ChoisirCouleurDessin(c);
		    RemplirTriangle(811,525,770,573,811,573);
		    c=CouleurParNom("black");
		    ChoisirCouleurDessin(c);
		    ChargerImage("./iuttitre.png",25,350,0,0,337,225);
		    DessinerRectangle(25,350,337,225);
		    ChargerImage("./charmingtitre.png",LONGFENETR-398-25,350,0,0,398,225);
		    DessinerRectangle(LONGFENETR-398-25,350,398,225);
		  }
		  if (curseurClavierColonne == 3){
		    c=CouleurParNom("blue");
		    ChoisirCouleurDessin(c);
		    RemplirTriangle(1373,525,1321,573,1373,573);
		    c=CouleurParNom("black");
		    ChoisirCouleurDessin(c);
		    ChargerImage("./valochetitre.png",LONGFENETR/2-225/2,350,0,0,225,225);
		    DessinerRectangle(LONGFENETR/2-225/2,350,225,225);
		  }
		}

		if (curseurClavierLigne == 3){

		    c=CouleurParNom("black");
		    ChoisirCouleurDessin(c);
		    ChargerImage("./valochetitre.png",LONGFENETR/2-225/2,350,0,0,225,225);
		    DessinerRectangle(LONGFENETR/2-225/2,350,225,225);
		    ChargerImage("./iuttitre.png",25,350,0,0,337,225);
		    DessinerRectangle(25,350,337,225);
		    ChargerImage("./charmingtitre.png",LONGFENETR-398-25,350,0,0,398,225);
		    DessinerRectangle(LONGFENETR-398-25,350,398,225);
		    
		  if (curseurClavierColonne == 1){
		    ChargerImage("./jouercurseur.png",LONGFENETR/2-(151*3/2),650,0,0,151,51);
		    ChargerImage("./quitter.png",LONGFENETR/2+(151*2/3)-23,650,0,0,151,51);
		  }
		  if (curseurClavierColonne == 2){
		    ChargerImage("./jouer.png",LONGFENETR/2-(151*3/2),650,0,0,151,51);
		    ChargerImage("./quittercurseur.png",LONGFENETR/2+(151*2/3)-23,650,0,0,151,51);
		  }
		}

			DessinerRectangle(25,350,337,225); // cadre img 1
	DessinerRectangle(LONGFENETR/2-225/2,350,225,225); // cadre img 2
	DessinerRectangle(LONGFENETR-398-25,350,398,225); // cadre img 3
	
		/* gestion pour chaque touche (haut/bas = ligne + 1 si possible, gauche/droite = colonne + 1 si possible) */


		if (ToucheEnAttente()){
		  t=Touche();
		  if (curseurClavierLigne == 0 && curseurClavierColonne == 0) {
		    curseurClavierLigne=1;
		    curseurClavierColonne=1;
		  } else {
		    
		    if (t == XK_Left){
		      if (curseurClavierColonne != 1){
			curseurClavierColonne--;
		      }
		    }
		    
		    if (t == XK_Right){
		      if (curseurClavierLigne==1 && curseurClavierColonne != 4 || curseurClavierLigne==2 && curseurClavierColonne != 3 || curseurClavierLigne==3 && curseurClavierColonne != 2){
			curseurClavierColonne++;
		      }
		      /* écrire ici si envie de faire comme pac man et retourner tout à gauche si on appuie à droite */
		    }
		    
		    if (t == XK_Up){
		      if (curseurClavierLigne != 1){
			curseurClavierLigne--;
			while (curseurClavierLigne==1 && curseurClavierColonne>4 || curseurClavierLigne==2 && curseurClavierColonne>3 || curseurClavierLigne==3 && curseurClavierColonne>2 ){
			  curseurClavierColonne--;
			}
		      }
		    }

		    if (t == XK_Down){
		      if (curseurClavierLigne != 3){
			curseurClavierLigne++;
		     	while (curseurClavierLigne==1 && curseurClavierColonne>4 || curseurClavierLigne==2 && curseurClavierColonne>3 || curseurClavierLigne==3 && curseurClavierColonne>2 ){
			  curseurClavierColonne--;
			}
		      }
		    }
		  }
		  printf("%d %d\n", curseurClavierLigne, curseurClavierColonne);
		}

		// début curseurClavier
	
		if (SourisCliquee()){

			SourisPosition();
			if (_X!=x||_Y!=y)
			{
			printf("x=%3d:y=%3d\n",_X,_Y);
			x=_X;
			y=_Y;
			}

			if (_X>=LONGFENETR/2-100+37 && _X<=LONGFENETR/2-100+51 && _Y>=295 && _Y<=325 && nbrlignes<8){
				nbrlignes++;
			}

			if (_X>=LONGFENETR/2-119 && _X<=LONGFENETR/2-105  && _Y>=295 && _Y<=325 && nbrlignes>3){
				nbrlignes--;
			}

			if (_X>=LONGFENETR/2+100-32+37 && _X<=LONGFENETR/2+100-32+51 && _Y>=295 && _Y<=325 && nbrcolonnes<8){
				nbrcolonnes++;
			}

			if (_X>=LONGFENETR/2+100-32-19 && _X<=LONGFENETR/2+100-32-5  && _Y>=295 && _Y<=325 && nbrcolonnes>3){
				nbrcolonnes--;
			}


			if (_X>=25 && _X<=25+337 && _Y>=350 && _Y<=575){
				choiximage=1;
			}

			if (_X>=LONGFENETR/2-225/2 && _X<=LONGFENETR/2+225/2 && _Y>=350 && _Y<=575){
				choiximage=2;
			}

			if (_X>=LONGFENETR-398-25 && _X<=1175 && _Y>=350 && _Y<=575){
				choiximage=3;
			}

			if (_X>=LONGFENETR/2+(151*2/3)-23 && _X<=LONGFENETR/2+(151*2/3)-23+151 && _Y>=650 && _Y<=701){
				FermerGraphique();
				/* On quitte le programme */
			}

			if (_X>=LONGFENETR/2-(151*3/2) && _X<=LONGFENETR/2-(151*3/2)+151 && _Y>=650 && _Y<=701){
				break;
				/* lancement du jeu */
			}
		}
	}
	
}
