#pragma once
#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "include.h"

class Affichage
{

	

public:


	Affichage();
	~Affichage();

	static void text(std::string text, char couleur, int x, int y);

	static void resetCursor();

	static void Cursor(bool value= true);

	static void afficherInfo();

	static void Block(int c, int place, int ligne, int depart);

	static void paramCmd(int W, int H, int fX, int fY);

	static void presentation();

	

private:




};
#endif // !AFFICHAGE_H