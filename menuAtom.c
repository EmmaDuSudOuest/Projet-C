#include "librairiesAtom.h"

#include "fonctionsAtom.h"



void MODE_FACILE (char * nameMapFile, int mapX, int mapY, char * nameTankFile,int PX,int PY,int TX,int TY, int DIR) {			
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
				theTank.Direction = 8;
				if(map[PX-2][PY]==' '){
					CLEAR_MYTANK (TY, TX,PX,PY);
					PX --;
					AFFICHE_MYTANK(nameTankFile, TY, (TX-1),(PX),PY);
				}
				break;
				
			case 'B' :
				theTank.Direction = 2;
				if(map[PX+8][PY]==' '){
					CLEAR_MYTANK (TY, TX,PX,PY);
					PX++;
					AFFICHE_MYTANK(nameTankFile, TY, (TX-1),(PX),PY);
				}
		
				break;

			case 'D' :
				theTank.Direction = 4;
				if(map[PX][PY-3]==' '){
					CLEAR_MYTANK (TY, TX,PX,PY);
					PY= PY- 2;
					AFFICHE_MYTANK(nameTankFile, TY, (TX-1),PX,PY);
				}
				break;

			case 'C' :
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
						listeObus[i].PosY=PY + TX/2;
						break;
					case 2 :
						listeObus[i].PosX=PX + TY;
						listeObus[i].PosY=PY + TX/2;
						break;
					case 6 :
						listeObus[i].PosX=PX + TY/2;
						listeObus[i].PosY=PY + TX;
						break;
					case 4 :
						listeObus[i].PosX=PX + TY/2;
						listeObus[i].PosY=PY;
						break;
				}
					
				
		}
		//t = clock();
		for (int i=0;i<50;i++) {
			if (listeObus[i].Actif==1 /*&& t%5000 == 0*/) {
				DEPLACE_OBUS(listeObus[i], map);
				printf("numObus: %d",i);
			}
		}
	
	}
}

