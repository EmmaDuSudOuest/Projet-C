#include "librairiesAtom.h"

#include "fonctionsAtom.h"

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
				printf("pos1: %d",OBUS.PosX);
				(OBUS.PosX)--;
				printf("pos2: %d",OBUS.PosX);
				break;
			case 2 :
				(OBUS.PosX)++;
				break;
			case 6 :
				(OBUS.PosY)++;
				break;
			case 4 :
				(OBUS.PosY)--;
				break;
			default:
				(OBUS.PosY)--;
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
