#pragma once
#ifndef PLATEAU_H
#define PLATEAU_H
#include "Affichage.h"

class Plateau
{
public:
	Plateau();
	~Plateau();

	void placerPoint(int couleur);
	void afficherPlateau();
	
	void genererCode();
	void afficherCode();

	bool inGame = true;

private:
	void testerPoint();
	int tableauPoint[4] = { 0 };
	int tableau[4] = { 0 };
	int cursor = 0;
	int nbEssaye = 0;
	int espace = 0;
	int nbTotalEssaie = 12;


};
#endif // !PLATEAU_H
