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

	


private:
	int tableauPoint[4] = { 0 };
	int cursor = 0;
};
#endif // !PLATEAU_H
