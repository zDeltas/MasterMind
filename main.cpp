#include "Affichage.h"
#include "Joueur.h"
#include "Plateau.h"

using namespace std;


int main() {

	Affichage::paramCmd(150, 50, 8, 12);
	Affichage::presentation();
	Affichage::afficherInfo();


	Joueur j1("joueur");


	Plateau plat;
	plat.genererCode();
	plat.afficherCode();


	while (plat.inGame) {
		plat.placerPoint(j1.choixCouleur());
		plat.afficherPlateau();
	}

	return 0;
}