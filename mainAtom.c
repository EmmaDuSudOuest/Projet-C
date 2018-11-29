#include "librairiesAtom.h"
#include "fonctionsAtom.h"



int main (int argc, char * argv[]) {
	int choix;
	choix = MENU(107,672,"menuFacile.txt","menuDifficile.txt","menuQuitter.txt");
	switch (choix) {
		//mode facile
		case 0 :
			MODE_FACILE("map.txt", 672, 107,"tankGauche.txt","tankDroite.txt","tankHaut",20,50,27,9,8);
			break;
		//quitter
		case 2 :
			AFFICHAGE_MENU(214, 672, "out.txt");
			return 0;
	}
	return 0;
}

