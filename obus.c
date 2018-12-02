#include "librairies.h"
#include "fonctions.h"

//Initialise la liste chaînée d'obus
listeObus * INITIALIZE_LIST_OBUS () {
	listeObus *liste = malloc(sizeof(listeObus));
   	obus *unObus = malloc(sizeof(obus));
	if (liste != NULL && unObus != NULL)
   	{
		unObus->Next = NULL;
		liste->Premier = unObus;
    	}
	return liste;
}

//Insère un obus en début de liste chaînée
void INSERT_OBUS(listeObus *liste, obus myObus)
{
    if (liste != NULL)
    {
   	 myObus.Next = liste->Premier;
    	liste->Premier = &myObus;
    }
}

void DELETE_OBUS(listeObus *liste)
{
    if (liste != NULL) {
	if (liste->Premier != NULL)
   	 {
        obus *aSupprimer = liste->Premier;
        liste->Premier = liste->Premier->Next;
        free(aSupprimer);
   	 }
    }
}

//Initialise un obus
void INITIALIZE_OBUS(obus OBUS, int estActif, int PX,int PY, int DIR) {
	OBUS.Actif = estActif;
	OBUS.PosX = PX;
	OBUS.PosY = PY;
	OBUS.Direction = DIR;
}


//Déplace un obus d'une case en fonction de sa position et de sa direction
void DEPLACE_OBUS(obus OBUS, char ** map) {	
	char c = 'O';
	printf("\033[%d;%dH \n",OBUS.PosX,OBUS.PosY);
	switch (OBUS.Direction) {
		case 8 :
			if (map[OBUS.PosX-1][OBUS.PosY]==' ') {
				(OBUS.PosX)--;
				printf("\033[%d;%dH%c\n",OBUS.PosX,OBUS.PosY,c);
			} else OBUS.Actif = 0;
			break;
		case 2 :
			if (map[OBUS.PosX+1][OBUS.PosY]==' ') {
				(OBUS.PosX)++;
				printf("\033[%d;%dH%c\n",OBUS.PosX,OBUS.PosY,c);
			} else OBUS.Actif = 0;
			break;
		case 6 :
			if (map[OBUS.PosX][OBUS.PosY+1]==' ') {
				(OBUS.PosY)++;
				printf("\033[%d;%dH%c\n",OBUS.PosX,OBUS.PosY,c);
			} else OBUS.Actif = 0;
			break;
		case 4 :
			if (map[OBUS.PosX][OBUS.PosY-1]==' ') {
				(OBUS.PosY)--;
				printf("\033[%d;%dH%c\n",OBUS.PosX,OBUS.PosY,c);
			} else OBUS.Actif = 0;
			break;
	}
}
