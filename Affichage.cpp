#include "Affichage.h"


using namespace std;

CONSOLE_CURSOR_INFO cursor;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



Affichage::Affichage() {

}

Affichage::~Affichage() {

}

void Affichage::text(std::string text, int couleur, int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	int couleurNum = numCouleur(couleur);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), couleurNum);
	cout << text;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Affichage::resetCursor() {
	COORD c; c.X = 1; c.Y = 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


void Affichage::Cursor(bool value)
{
	GetConsoleCursorInfo(hConsole, &cursor);
	cursor.bVisible = value;
	GetConsoleCursorInfo(hConsole, &cursor);
}

void Affichage::Block(int c, int pos) {

	for (int i = 1; i <= 2; i++) {
		for (int y = 1; y <= 2; y++) {
			Affichage::text(string(1, char(219)), c, pos + y, i);
		}
	}

}

void Affichage::afficherInfo() {
	system("cls");
	
	//CONSOLE_SCREEN_BUFFER_INFO csbi;

	//if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
	//	printf("Lignes   : %hd\nColonnes : %hd\n", csbi.dwSize.Y, csbi.dwSize.X);


	for (int i = 1; i < 151; i++) {
		Affichage::text("-", 1, i, 49);
	}
	cout << endl;

	Affichage::text("1=Rouge, 2=Jaune, 3=Bleu, 4=Gris, 5=Vert, 6=Blanc, 7=Violet, 8=Bleu Cyan", 1, 1, 50);
	Affichage::resetCursor();
}

int Affichage::numCouleur(int couleur)
{
	switch (couleur)
	{
	case 1:
		return 4;
		break;
	case 2:
		return 14;
		break;
	case 3:
		return 9;
		break;
	case 4:
		return 8;
		break;
	case 5:
		return 2;
		break;
	case 6:
		return 15;
		break;
	case 7:
		return 13;
		break;
	case 8:
		return 11;
		break;
	default:
		return 15;
		break;
	}

}
