typedef struct {

	int Direction;

	int PosX;

	int PosY;

	int TailleX;
	int TailleY;
	int Carrosserie;

}tank;

#ifndef H_LISTE_CHAINEE
#define H_LISTE_CHAINEE

typedef struct obus obus;

struct obus{
	int Actif;

	int Direction;

	int PosX;

	int PosY;
	obus * Next;

};

typedef struct listeObus listeObus;

struct listeObus{
    obus * Premier;
};

listeObus * INITIALIZE_LIST_OBUS ();

void INITIALIZE_OBUS(obus OBUS, int Actif, int PX,int PY, int DIR);

void INSERT_OBUS(listeObus *liste, obus myObus);

void DELETE_OBUS(listeObus *liste);

void DEPLACE_OBUS(obus OBUS, char ** map);

#endif

char ** ALLOCATION_MAT_DYN (int NB_L, int NB_C);

char ** CHARGEMENT_MAP (char * nom_fic, int NB_L, int NB_C);

void CLEAR_MYTANK (int NB_L, int NB_C,int PosX, int PosY);

void AFFICHE_MYTANK (char * nom_fic, int NB_L, int NB_C,int PosX, int PosY);

void AFFICHAGE_MAT(int NB_L, int NB_C, char ** MAT);

void AFFICHAGE_MENU (int NB_L, int NB_C, char * nom_fic);

char key_pressed();

int MENU(int NB_L, int NB_C, char * facile, char * difficile, char * quitter);

void MODE_FACILE (char * nameMapFile, int mapX, int mapY, char * nameTankFile,int PX,int PY, int TX, int TY, int DIR);

void MOVE_TANK(tank TANK,int DIR, char ** map, int NB_L, int NB_C);
