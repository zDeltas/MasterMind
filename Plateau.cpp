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
	int c = couleur-48;
	tableauPoint[cursor] = c;
	cursor += 1;
	if (cursor == 4) {
		cursor = 0;
	}
}

void Plateau::afficherPlateau()
{
	for (int i = 0; i < 4; i++) {
		Affichage::text(string(1, char(219)), 2, 40 + cursor, 1);
	}
	for (int i = 0; i < 4; i++) {
		Affichage::text(string(1, char(219)), 2, 80 + cursor, 1);
	}
}

