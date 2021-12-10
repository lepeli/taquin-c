#include <graph.h>
#include <stdio.h> /* pour pos_souris */
#include <stdlib.h>

#include"graphisme_victoire.h"


#define LONGFENETR 1200
#define HAUTFENETR 800



void pos_souris(){ /* affiche la pos de la souris dans la console à chaque clic */
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
		ecranvictoire();
		/* pos_souris(); */
	}
}


int main(void){
	affichage();
}