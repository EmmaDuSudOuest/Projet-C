#include "librairiesAtom.h"
#include "fonctionsAtom.h"

int MENU(int NB_L, int NB_C, char * facile, char * difficile, char * quitter) {
	int etat = 0;
	int sortie = 0;	
	AFFICHAGE_MENU(NB_L*2, NB_C, facile);
	while (sortie==0) {
usleep(1);
		//if (key_pressed()== '\033') {
		//key_pressed();
		switch (key_pressed()) {
usleep(3);
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

void AFFICHAGE_MENU (int NB_L, int NB_C, char * nom_fic) {
	char ligne[NB_C];
	char c;
	FILE * fic = fopen(nom_fic,"r");
	system("clear");
	for (int i=0;i<NB_L;i++) {
             fgets(ligne, NB_C, fic);
	     int c = printf("%s", ligne);
	    
	       /*switch(c){
			case '6': printf("\e[49m|");
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



