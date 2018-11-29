typedef struct {

	int Direction;

	int PosX;

	int PosY;

	//int Blindage;

	//int Blindage_orig;

	//int Touches;
	int TailleX;
	int TailleY;
	int Carrosserie;

	//char Type;

	//int Etat;

	//int Mise_a_jour;

	//struct tank * NXT;

}tank;

typedef struct {
	int Actif;

	int Direction;

	int PosX;

	int PosY;

}obus;




char ** ALLOCATION_MAT_DYN (int NB_L, int NB_C);



char ** CHARGEMENT_MAP (char * nom_fic, int NB_L, int NB_C);



void CLEAR_MYTANK (int NB_L, int NB_C,int PosX, int PosY);

void AFFICHE_MYTANK (char * nom_fic, int NB_L, int NB_C,int PosX, int PosY);



void AFFICHAGE_MAT(int NB_L, int NB_C, char ** MAT);

void AFFICHAGE_MENU (int NB_L, int NB_C, char * nom_fic);


char key_pressed();

int MENU(int NB_L, int NB_C, char * facile, char * difficile, char * quitter);

void MODE_FACILE (char * nameMapFile, int mapX, int mapY, char * nameTankFile,int PX,int PY, int TX, int TY, int DIR);


void INITIALIZE_TANK(char ** map,tank TANK,int PX,int PY, int TX, int TY, int DIR, char * nameFile);

void INITIALIZE_OBUS(obus OBUS, int Actif, int PX,int PY, int DIR);

obus * INITIALIZE_LIST_OBUS ();

void DEPLACE_OBUS(obus OBUS, char ** map);

//void THROW_BULLET(int TailleY, int TailleX,int PosX, int PosY, int Dir, char ** map);

void MOVE_TANK(tank TANK,int DIR, char ** map, int NB_L, int NB_C);
