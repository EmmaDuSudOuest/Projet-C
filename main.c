#include "librairies.h"
#include "fonctions.h"


int main (int argc, char * argv[]) {
	int choix;
	choix = MENU(107,672,"menuFacile.txt","menuDifficile.txt","menuQuitter.txt");
	switch (choix) {
	//choix désigne quel option a choisi le joueur entre Facile (0), Difficile (1) et Quitter (2)
		//quitter
		case 2 :
			AFFICHAGE_MENU(214, 672, "out.txt");
			return 0;
		//facile et difficile (nous n'avons pas programmé le mode difficile)
		default :
			MODE_FACILE("map.txt", 672, 107,"tankGauche.txt","tankDroite.txt","tankHaut",20,50,27,9,8);
			break;
	}
	return 0;
}

