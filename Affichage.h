#pragma once
#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include <iostream>
#include <windows.h>
#include <string>

class Affichage
{

	

public:


	Affichage();
	~Affichage();

	static void text(std::string text, int couleur, int x, int y);

	static void resetCursor();

	static void Cursor(bool value= true);

	static void afficherInfo();

	static void Block(int c, int pos);

private:
	static int numCouleur(int couleur);



};
#endif // !AFFICHAGE_H