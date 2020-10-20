#include "Joueur.h"
#include <conio.h>
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
		
		Affichage::text("Quelle couleur: ", -1, 1, 1);
		couleur = _getch();
		if (couleur <= 56 && couleur >= 49) {
			Correct = false;
		}
		else {

		}
	} while (Correct);
	return couleur;
}



