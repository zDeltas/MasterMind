#pragma once
#ifndef JOUEUR_H
#define JOUEUR_H
#include "Affichage.h"

class Joueur
{
public:
	Joueur();
	Joueur(std::string Nom);
	~Joueur();

	std::string returnNom();
	int choixCouleur();


private:
	std::string nom;


};

#endif // !JOUEUR_H