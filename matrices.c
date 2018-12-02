//MATRICES

#include "librairies.h"
#include "fonctions.h"

//Alloue dynamiquement de la mémoire à une matrice
char ** ALLOCATION_MAT_DYN (int NB_L, int NB_C) {
	int i;
	char ** MAT = malloc(NB_L*sizeof(char*));
	for (i=0;i<NB_L;i++) {
		MAT[i] = malloc(NB_C*sizeof(char));
	}
	return MAT;
}

//Charge le fichier txt dans une matrice
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

//Affiche une matrice
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
