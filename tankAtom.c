#include "librairiesAtom.h"
 #include "fonctionsAtom.h"
 void AFFICHE_MYTANK (char * nom_fic, int NB_L, int NB_C,int PosX, int PosY) {
 	char c;
 	FILE * fic = fopen(nom_fic,"r");
 	for (int i=0;i<NB_L;i++) {
 		for (int j=0;j<NB_C;j++) {
 			fscanf(fic,"%c", &c);
			printf("\033[%d;%dH%c\n",i+PosX,j+PosY,c);
 		}
 	}
 }
 void INITIALIZE_TANK(char ** map,tank TANK,int PX,int PY, int TX, int TY, int DIR, char * nameFileC) {
	AFFICHE_MYTANK(nameFileC, TY, (TX-1),PX,PY);
	TANK.PosX = PX;
	TANK.PosY = PY;
	TANK.TailleX = TX;
	TANK.TailleY = TY;
	TANK.Direction = DIR;
 }
 void CLEAR_MYTANK (int NB_L, int NB_C,int PosX, int PosY) {
 	for (int i=0;i<NB_L;i++) {
 		for (int j=0;j<NB_C;j++) {
 			printf("\033[%d;%dH \n",i+PosX,j+PosY);
 		}
 	}
 }



