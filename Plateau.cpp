#include "Plateau.h"


using namespace std;

Plateau::Plateau()
{
}

Plateau::~Plateau()
{
}

void Plateau::placerPoint(int couleur)
{

	if (couleur == 13) {
		if (cursor == 4) {
			cursor += 1;
		}
		
	}
	else if (couleur == 8) {
		if (cursor > 0) {
			cursor -= 1;
			tableauPoint[cursor] = 0;
		}
	}
	else {
		int c = couleur - 48;
		tableauPoint[cursor] = c;
		if (cursor < 4) {
			cursor += 1;
		}
		
	}
	
	if (cursor == 5 && couleur == 13) {
		cursor = 0;
		espace += 1;
		testerPoint();
		for (int i = 0; i < 4; i++) {
			tableauPoint[i] =  0 ;
		}
	}
}





void Plateau::afficherPlateau()
{
	int calc = 0;
	for (int i = 0; i < 4; i++) {
		Affichage::Block(tableauPoint[i], i, abs(nbEssaye) + espace, 55);
	}
	for (int i = 0; i < 4; i++) {
		tableau[i] + calc;
	}
	for (int i = 0; i < 4; i++) {
		if (calc != 0) {
			cout << tableau[i];
		}
	}
	
}

void Plateau::genererCode()
{
	random_device r;
	default_random_engine e1(r());
	uniform_int_distribution<int> uniform_dist(1, 8);
	int nbAlea = 0;
	for (int i = 0; i < 4; i++) {
		nbAlea = uniform_dist(e1);
		tableau[i] = nbAlea;
	}
	
	
	

	
}

void Plateau::afficherCode()
{
	for (int i = 0; i < 4; i++) {
		cout << tableau[i];
	}
}

void Plateau::testerPoint()
{
	int pbp = 0; //Points bien placés
	int pmp = 0; //Points mal placés
	for (int i = 0; i < 4; i++) {
		if (tableau[i] == tableauPoint[i]) {
			pbp += 1;
		}

		for (int y = 0; y < 4; y++) {
			if (tableauPoint[y] == tableau[i]) {
				pmp += 1;
			}
		}
	}
	pmp -= pbp;

	if (pbp == 4) {
		inGame = false;
	}
	nbEssaye -= 1;

	auto phrase = "Votre combinaison " + to_string(tableauPoint[0]) + to_string(tableauPoint[1]) + to_string(tableauPoint[2]) + to_string(tableauPoint[3]) + " contient " + to_string(pbp) + " pions bien places et " + to_string(pmp) + " pions mal places";

	if (pbp <= 1 && pmp <= 1) {
		auto phrase = "Votre combinaison " + to_string(tableauPoint[0]) + to_string(tableauPoint[1]) + to_string(tableauPoint[2]) + to_string(tableauPoint[3]) + " contient " + to_string(pbp) + " pion bien places et " + to_string(pmp) + " pion mal places";
	}
	else if (pbp > 1 && pmp > 1) {
		auto phrase = "Votre combinaison " + to_string(tableauPoint[0]) + to_string(tableauPoint[1]) + to_string(tableauPoint[2]) + to_string(tableauPoint[3]) + " contient " + to_string(pbp) + " pions bien places et " + to_string(pmp) + " pions mal places";
	}
	else if (pbp >= 1 && pmp < 1) {
		auto phrase = "Votre combinaison " + to_string(tableauPoint[0]) + to_string(tableauPoint[1]) + to_string(tableauPoint[2]) + to_string(tableauPoint[3]) + " contient " + to_string(pbp) + " pions bien places et " + to_string(pmp) + " pion mal places";
	}
	else{
		auto phrase = "Votre combinaison " + to_string(tableauPoint[0]) + to_string(tableauPoint[1]) + to_string(tableauPoint[2]) + to_string(tableauPoint[3]) + " contient " + to_string(pbp) + " pion bien places et " + to_string(pmp) + " pions mal places";
	}



	if ((nbTotalEssaie - abs(nbEssaye)) == 0) {
		inGame = false;
	}

	Affichage::text(phrase, 'r', 75, (abs(nbEssaye) + espace)*2-2);


	string ess = "";

	if (nbTotalEssaie - abs(nbEssaye) == 1) {
		ess = "Il vous reste " + to_string(nbTotalEssaie - abs(nbEssaye)) + " essaie";
	}
	else {
		ess = "Il vous reste " + to_string(nbTotalEssaie - abs(nbEssaye)) + " essaies";
	}
	

	Affichage::text(ess, 'r', 75, (abs(nbEssaye) + espace)*2-1);

}

