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
	}
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
		}
	}
}

void MODE_FACILE (char * nameMapFile, int mapX, int mapY, char * nameTankFileA, char * nameTankFileB, char * nameTankFileC,int PX,int PY,int TX,int TY, int DIR) {			
	char ** map;
	int endGame;
	map = CHARGEMENT_MAP(nameMapFile, mapY, mapX);
	system("clear");

	AFFICHAGE_MAT (108, 673,map);
	tank theTank;

	INITIALIZE_TANK(map,theTank,PX,PY,TX,TY,DIR,nameTankFile);
	obus * listeObus;
	listeObus = INITIALIZE_LIST_OBUS ();
	endGame = 0;
	clock_t start_t, t;
	start_t = clock();
	while (endGame == 0) {
		switch (key_pressed()) {

			case 'q' :
				AFFICHAGE_MENU(214, 672, "out.txt");
				endGame = 1;
				break;

			case 'A' :
				INITIALIZE_TANK(map,theTank,PX,PY,TX,TY,nameTankFileA);
				theTank.Direction = 8;
				if(map[PX-2][PY]==' '){
					CLEAR_MYTANK (TY, TX,PX,PY);
					PX --;
					AFFICHE_MYTANK(nameTankFile, TY, (TX-1),(PX),PY);
				}
				break;
				
			case 'B' :
				INITIALIZE_TANK(map,theTank,PX,PY,TX,TY,nameTankFileB);
				theTank.Direction = 2;
				if(map[PX+8][PY]==' '){
					CLEAR_MYTANK (TY, TX,PX,PY);
					PX++;
					AFFICHE_MYTANK(nameTankFile, TY, (TX-1),(PX),PY);
				}
		
				break;

			case 'D' :
				INITIALIZE_TANK(map,theTank,PX,PY,TX,TY,nameTankFileA);
				theTank.Direction = 4;
				if(map[PX][PY-3]==' '){
					CLEAR_MYTANK (TY, TX,PX,PY);
					PY= PY- 2;
					AFFICHE_MYTANK(nameTankFile, TY, (TX-1),PX,PY);
				}
				break;

			case 'C' :
				INITIALIZE_TANK(map,theTank,PX,PY,TX,TY,nameTankFileC);
				theTank.Direction = 6;
				if(map[PX][PY+6]==' '){
					CLEAR_MYTANK (TY, TX,PX,PY);
					PY= PY+2;
					AFFICHE_MYTANK(nameTankFile, TY, (TX-1),PX,PY);
				}
				break;

			case 'e' :
				;
				int i=0;
				while (listeObus[i].Actif==1) {
					i++;
				}
				listeObus[i].Actif=1;
				listeObus[i].Direction=theTank.Direction;
				switch (theTank.Direction) {

					case 8 :
						listeObus[i].PosX=PX;
						listeObus[i].PosY=PY + TY/2;
						break;
					case 2 :
						listeObus[i].PosX=PX + TX;
						listeObus[i].PosY=PY + TY/2;
						break;
					case 6 :
						listeObus[i].PosX=PX + TX/2;
						listeObus[i].PosY=PY + TY;
						break;
					case 4 :
						listeObus[i].PosX=PX + TX/2;
						listeObus[i].PosY=PY + TY/2;
						break;
				}
					printf("%d",listeObus[i].PosX);
				
		}
		t = clock();
		for (int i=0;i<50;i++) {
			if (listeObus[i].Actif==1 && t%50000 == 0) {
				DEPLACE_OBUS(listeObus[i], map);
			}
		}
	
	}
}


void INITIALIZE_TANK(char ** map,tank TANK,int PX,int PY, int TX, int TY, int DIR, char * nameFile) {
	AFFICHE_MYTANK(nameFile, TY, (TX-1),PX,PY);
	TANK.PosX = PX;
	TANK.PosY = PY;
	TANK.TailleX = TX;
	TANK.TailleY = TY;
	TANK.Direction = DIR;


}


void INITIALIZE_OBUS(obus OBUS, int Actif, int PX,int PY, int DIR) {
	OBUS.Actif = 0;
	OBUS.PosX = PX;
	OBUS.PosY = PY;
	OBUS.Direction = DIR;


}

obus * INITIALIZE_LIST_OBUS () {
	obus * listeObus = malloc(50*sizeof(obus));
	for (int i=0;i<=50;i++) {
		obus OBUS;
		INITIALIZE_OBUS(OBUS,0,0,0,8);
		listeObus[i] = OBUS;
	}
	return listeObus;
}

void DEPLACE_OBUS(obus OBUS, char ** map) {	
	char c = 'O';
	if (map[OBUS.PosX-1][OBUS.PosY]==' ') {
		printf("\033[%d;%dH \n",OBUS.PosX,OBUS.PosY);
		switch (OBUS.Direction) {
			case 8 :
				OBUS.PosX--;
				break;
			case 2 :
				OBUS.PosX++;
				break;
			case 6 :
				OBUS.PosY++;
				break;
			case 4 :
				OBUS.PosY--;
				break;
			default:
				OBUS.PosY--;
		}
		printf("\033[%d;%dH%c\n",OBUS.PosX,OBUS.PosY,c);
	} else OBUS.Actif = 0;
	
}
/*
void THROW_BULLET(int TailleX, int TailleY,int PosX, int PosY, int Dir, char ** map) {
	int crushed = 0;
	char c = 'O';	
	switch (Dir) {
		case 8 :
			x= PosX;
			y= PosY + TailleY/2;
			while (crushed==0) {
				if (map[x-1][y]==' ') {
					printf("\033[%d;%dH%c\n",x,y,c);
					usleep(40000);
					printf("\033[%d;%dH \n",x,y);
					x--;
				} else crushed = 1;
			}
			break;

		case 2 :
			x= PosX + TailleX;
			y= PosY + TailleY/2;
			while (crushed==0) {
				if (map[x-1][y]==' ') {
					printf("\033[%d;%dH%c\n",x,y,c);
					usleep(40000);
					printf("\033[%d;%dH \n",x,y);
					x++;
				} else crushed = 1;
			}
			break;	
		case 4 :
			x= PosX + TailleX/2;
			y= PosY;
			while (crushed==0) {
				if (map[x-1][y]==' ') {
					printf("\033[%d;%dH%c\n",x,y,c);
					usleep(10000);
					printf("\033[%d;%dH \n",x,y);
					y--;
				} else crushed = 1;
			}
			break;	
		case 6 :
			x= PosX + TailleX/2;
			y= PosY + TailleY;
			while (crushed==0) {
				if (map[x-1][y]==' ') {
					printf("\033[%d;%dH%c\n",x,y,c);
					usleep(10000);
					printf("\033[%d;%dH \n",x,y);
					y++;
				} else crushed = 1;
			}
			break;			
	}

}*/



void CLEAR_MYTANK (int NB_L, int NB_C,int PosX, int PosY) {

	for (int i=0;i<NB_L;i++) {

		for (int j=0;j<NB_C;j++) {

			printf("\033[%d;%dH \n",i+PosX,j+PosY);

		}

	}

}
