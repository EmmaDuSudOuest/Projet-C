#include "librairies.h"
#include "fonctions.h"

//Initialise et dirige le jeu, saisie des touches clavier
 void MODE_FACILE (char * nameMapFile, int mapX, int mapY, char * nameTankFile,int PX,int PY,int TX,int TY, int DIR) {			
	char ** map;
	int endGame;
	map = CHARGEMENT_MAP(nameMapFile, mapY, mapX);
	system("clear");
 	AFFICHAGE_MAT (108, 673,map);
	tank theTank;
 	INITIALIZE_TANK(map,theTank,PX,PY,TX,TY,DIR,nameTankFile);
	listeObus* listeDesObus;
	listeDesObus = INITIALIZE_LIST_OBUS ();
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
 			/*
			Cette programmation d'obus ne fonctionnant pas, nous avons mis en commentaire la touche de tir
			
			case 'e' :
				;
				obus newObus;
				INITIALIZE_OBUS(newObus, 1, PX,PY, theTank.Direction);
				INSERT_OBUS(listeDesObus, newObus);
				switch (theTank.Direction) {

					case 8 :
						newObus.PosX=PX;
						newObus.PosY =PY + TX/2;
						break;
					case 2 :
						newObus.PosX=PX + TY;
						newObus.PosY=PY + TX/2;
						break;
					case 6 :
						newObus.PosX=PX + TY/2;
						newObus.PosY=PY + TX;
						break;
					case 4 :
						newObus.PosX=PX + TY/2;
						newObus.PosY=PY;
						break;
				}*/
			}
		/*			
		t = clock();
		obus *actuel = listeDesObus->Premier;
		if (t%5000==0) {
			while (actuel != NULL)
			{	
				if (actuel->Actif==1) {
					DEPLACE_OBUS(*actuel, map);
				}
				actuel = actuel->Next;
			}
		}*/
		
	}
}

