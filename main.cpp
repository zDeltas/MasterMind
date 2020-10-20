
#include <memory>

#include <vector>
#include <stdio.h>
#include <conio.h>


#include "Affichage.h"
#include "Joueur.h"
#include "Plateau.h"

using namespace std;

int main() {

#pragma region GestionCmd
	HANDLE f = CreateFileA("CONOUT$", GENERIC_WRITE | GENERIC_READ,
		FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	CONSOLE_FONT_INFOEX cfi = { sizeof(cfi) };
	cfi.dwFontSize.X = 8;
	cfi.dwFontSize.Y = 12;
	SetCurrentConsoleFontEx(f, false, &cfi);

	system("mode con lines=50 cols=150");
#pragma endregion


	Affichage::afficherInfo();


	Joueur j1("slaut");
	Plateau plat;

	while (true) {
		plat.placerPoint(j1.choixCouleur());
		Affichage::Block(2, 40);
		Affichage::Block(3, 42);
		Affichage::Block(4, 44);
		Affichage::Block(1, 46);
		plat.afficherPlateau();
	}
	
	
	

	return 0;
}