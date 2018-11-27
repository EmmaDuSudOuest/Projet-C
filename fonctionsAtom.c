#include "librairiesAtom.h"
#include "fonctionsAtom.h"

char ** ALLOCATION_MAT_DYN (int NB_L, int NB_C) {
	int i;
	char ** MAT = malloc(NB_L*sizeof(char*));
	for (i=0;i<NB_L;i++) {
		MAT[i] = malloc(NB_C*sizeof(char));
	}
	return MAT;
}


char ** CHARGEMENT_MAP (char * nom_fic, int NB_L, int NB_C) {
	char c;
	char ** map;
	map = ALLOCATION_MAT_DYN(NB_L+1,NB_C+1);
	FILE * fic = fopen(nom_fic,"r");
	for (int i=0;i<=(NB_L);i++) {
		for (int j=0;j<=(NB_C);j++) {
			c = fscanf(fic, "%c", &map[i][j]);
		}
	}
	return map;
}

void  AFFICHE_MYTANK (char * nom_fic, int NB_L, int NB_C,int PosX, int PosY) {
	char c;
	FILE * fic = fopen(nom_fic,"r");
	for (int i=0;i<NB_L;i++) {
		for (int j=0;j<NB_C;j++) {
			fscanf(fic,"%c", &c);
			printf("\033[%d;%dH%c\n",i+PosX,j+PosY,c);
		}
	}
}

void AFFICHAGE_MAT (int NB_L, int NB_C, char ** MAT) {
	int i;int j;
	for (i=0;i<NB_L;i++) {
		for (j=0;j<NB_C;j++) {
			if (MAT[i][j] == '\n') {
				if (j!=NB_C-1)
					{printf("\n");}
			} else {printf("%c",MAT[i][j]);}
		}
	}
}

void AFFICHAGE_MENU (int NB_L, int NB_C, char * nom_fic) {
	char ligne[NB_C];
	FILE * fic = fopen(nom_fic,"r");
	system("clear");
	for (int i=0;i<NB_L;i++) {
             fgets(ligne, NB_C, fic);
	     printf("%s", ligne);
	     /*
	       switch(c){
                        case '|': printf("\e[43mE \e[0m");
				  break;
                        case '.': printf("\e[31mA\e[0m");
                                  break;
			case '6': printf("\e[43mZ \e[0m");
                                  break;
                        case '5': printf("\e[31mR \e[0m");
                                  break;
                        case '4': printf("\e[31mT\e[0m");
                                  break;
			case '3': printf("\e[43mI \e[0m");
                                  break;
                        case '2': printf("\e[31mP \e[0m");
                                  break;
                        case '1': printf("\e[31mM \e[0m");
                                  break;
	       }*/
	       }
				//ligne = "";
}

char key_pressed() {
	struct termios oldterm, newterm;
	int oldfd; char c, result = 0;
	tcgetattr (STDIN_FILENO, &oldterm);
	newterm = oldterm; newterm.c_lflag &= ~(ICANON | ECHO);
	tcsetattr (STDIN_FILENO, TCSANOW, &newterm);
	oldfd = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl (STDIN_FILENO, F_SETFL, oldfd | O_NONBLOCK);
	c = getchar();
	tcsetattr (STDIN_FILENO, TCSANOW, &oldterm);
	fcntl (STDIN_FILENO, F_SETFL, oldfd);
	if (c!= EOF) {ungetc(c, stdin); result = getchar();}
	return result;
}

int MENU(int NB_L, int NB_C, char * facile, char * difficile, char * quitter) {
	int etat = 0;
	int sortie = 0;	
	AFFICHAGE_MENU(NB_L*2, NB_C, facile);
	while (sortie==0) {
		//if (key_pressed()== '\033') {
		//key_pressed();
		switch (key_pressed()) {
			case 'B' :
				if (etat==0) {
					etat=1;
					AFFICHAGE_MENU(NB_L*2, NB_C, difficile);
				} else if (etat==1) {
					etat=2;
					AFFICHAGE_MENU(NB_L*2, NB_C, quitter);
				}
				break;
			case 'A' :
				if (etat==1) {
					etat=0;
					AFFICHAGE_MENU(NB_L*2, NB_C, facile);
				} else if (etat==2) {
					etat=1;
					AFFICHAGE_MENU(NB_L*2, NB_C, difficile);
				}
				break;
			case '\n' :
				sortie =1;
				return etat;				
		} /*else if (key_pressed()== 'q') {
				sortie =1;
				return etat;
			}*/
	}
}

void MODE_FACILE (char * nameMapFile, int mapX, int mapY, char * nameTankFileA, char * nameTankFileB, char * nameTankFileC, int PX,int PY,int TX,int TY){		
	char ** map;
	int endGame;
	map = CHARGEMENT_MAP(nameMapFile, mapY, mapX);
	system("clear");
	AFFICHAGE_MAT (108, 673,map);
	tank theTank;
	//AFFICHE_MYTANK ("tankGauche.txt",9,27,100,100); 
	//INITIALIZE_TANK(map,theTank,PX,PY,TX,TY,nameTankFileA,nameTankFileB,nameTankFileC);
	endGame = 0;
	while (endGame == 0) {
		switch (key_pressed()) {
			case 'q' :
				endGame = 1;
				break;
			case 'A' : 
			INITIALIZE_TANK(map,theTank,PX,PY,TX,TY,nameTankFileA);
				//if(PX !=1)  
				if(map[PX-2][PY]==' '){
				CLEAR_MYTANK (TY, TX,PX,PY);
				PX --;
				AFFICHE_MYTANK(nameTankFileA, TY, (TX-1),(PX),PY);
			
			}
				break;
				
			case 'B' :
			INITIALIZE_TANK(map,theTank,PX,PY,TX,TY,nameTankFileB);
			if(map[PX+8][PY]==' '){
			CLEAR_MYTANK (TY, TX,PX,PY);
			PX++;
				AFFICHE_MYTANK(nameTankFileB, TY, (TX-1),(PX),PY);
			}
		
				break;
			case 'D' :
			INITIALIZE_TANK(map,theTank,PX,PY,TX,TY,nameTankFileA);
			if(map[PX][PY-3]==' '){
			CLEAR_MYTANK (TY, TX,PX,PY);
			PY= PY- 2;
				AFFICHE_MYTANK(nameTankFileC, TY, (TX-1),PX,PY);
			}
			
				
				break;
			case 'C' :
			INITIALIZE_TANK(map,theTank,PX,PY,TX,TY,nameTankFileA);
			if(map[PX][PY+10]==' '){
			CLEAR_MYTANK (TY, TX,PX,PY);
			PY= PY+2;
			AFFICHE_MYTANK(nameTankFileC, TY, (TX-1),PX,PY);
			break;
			}
		}
	}
}
/*
void INCLUDE_TANK (char ** map, int NB_L, int NB_C, tank TANK) {
		int i;int j;
		for (i=0;i<TANK.TailleY;i++) {
			for (j=0;j<TANK.TailleX;j++) {
				if (TANK.Carrosserie[i][j]!='\n') {					
					if (j>=TANK.TailleX-i-1) {
						map[TANK.PosY+i+1][TANK.PosX+j-TANK.TailleX] = TANK.Carrosserie[i][j];
					} else {
						map[TANK.PosY+i][TANK.PosX+j] = TANK.Carrosserie[i][j];
					}
				}
			}
		}
}

void CLEAR_TANK (char ** map, int NB_L, int NB_C, tank TANK) {
		int i;int j;
		
	        printf(TANK.TailleY);
		for (i=0;i<TANK.TailleY;i++) {
			for (j=0;j<TANK.TailleX;j++) {
				printf("Heyyyyyyyyyyyyyyyyyyyyyyyyy");
				if (TANK.Carrosserie[i][j]!='\n') {					
					if (j>=TANK.TailleX-i-1) {
						map[TANK.PosY+i+1][TANK.PosX+j-TANK.TailleX] ='1';
					} else {
						map[TANK.PosY+i][TANK.PosX+j] ='1';
					}
				}
			}
		}
}
*/

void INITIALIZE_TANK(char ** map,tank TANK,int PX,int PY, int TX, int TY, char * nameFileA) {
	AFFICHE_MYTANK(nameFileA,TY, (TX-1),PX,PY);
	TANK.PosX = PX;
	TANK.PosY = PY;
	TANK.TailleX = TX;
	TANK.TailleY = TY;

}
/*
void MOVE_TANK(tank TANK,int DIR, char ** map, int NB_L, int NB_C) {
	switch (DIR) {
		case 2 :
			
			CLEAR_TANK (map,107,672,TANK);
			
			TANK.PosY = 10;
			INCLUDE_TANK (map,107,672,TANK);
			break;
		case 4 :
			CLEAR_TANK (map,107,672,TANK);
			(TANK.PosX)--;
			INCLUDE_TANK (map,107,672,TANK);
			break;
		case 6 :
			CLEAR_TANK (map,107,672,TANK);
			(TANK.PosX)++;
			INCLUDE_TANK (map,107,672,TANK);
			break;
		case 8 :
			CLEAR_TANK (map,107,672,TANK);
			(TANK.PosY)++;
			INCLUDE_TANK (map,107,672,TANK);
			break;
	}
}
*/

void CLEAR_MYTANK (int NB_L, int NB_C,int PosX, int PosY) {
	for (int i=0;i<NB_L;i++) {
		for (int j=0;j<NB_C;j++) {
			printf("\033[%d;%dH \n",i+PosX,j+PosY);
		}
	}
}




