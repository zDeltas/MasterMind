#include "Joueur.h"

using namespace std;

Joueur::Joueur()
{
}

Joueur::Joueur(string Nom)
{
	nom = Nom;
}

Joueur::~Joueur()
{
}

string Joueur::returnNom()
{
	return nom;
}

int Joueur::choixCouleur()
{
	bool Correct = true;
	int couleur = 0;
	

	do {
		
		Affichage::text("Quelle couleur: ", 'w', 1, 1);
		couleur = _getch();
		if (couleur <= 56 && couleur >= 49 || couleur == 13 || couleur == 8) {
			Correct = false;
		}
		else {

		}
	} while (Correct);
	return couleur;
}



