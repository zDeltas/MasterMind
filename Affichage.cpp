#include "Affichage.h"


using namespace std;

CONSOLE_CURSOR_INFO cursor;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



Affichage::Affichage() {

}

Affichage::~Affichage() {

}

void Affichage::text(string text, char couleur, int x, int y)
{
	int couleurNum = 16;

#pragma region switchCouleur



	switch (couleur)
	{
	case 'r': //Rouge
		couleurNum = 4;
		break;
	case 'g': //Vert
		couleurNum = 2;
		break;
	case 'b': //Bleu
		couleurNum = 1;
		break;
	case 'w': //Blanc
		couleurNum = 7;
		break;
	case 'n': //Noir
		couleurNum = 0;
		break;
	default:
		couleurNum = 16;
		break;
	}
#pragma endregion

	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
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


void Affichage::Block(int c, int place, int ligne, int depart) {

#pragma region SwitchCouleur
	switch (c)
	{
	case 1:
		c = 4;
		break;
	case 2:
		c = 14;
		break;
	case 3:
		c = 9;
		break;
	case 4:
		c = 8;
		break;
	case 5:
		c = 2;
		break;
	case 6:
		c = 15;
		break;
	case 7:
		c = 13;
		break;
	case 8:
		c = 11;
		break;
	default:
		c = 0;
		break;
	}
#pragma endregion

	COORD coord;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	for (int i = 1; i <= 2; i++) {
		for (int y = 1; y <= 2; y++) {
			coord.X = depart - 1 + i + (place*2);
			coord.Y = y + ligne * 2;

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cout << string(1, char(219));
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}



void Affichage::afficherInfo() {
	system("cls");
	
	


	for (int i = 1; i < 151; i++) {
		Affichage::text("-", 1, i, 49);
	}
	cout << endl;

	Affichage::text("1=Rouge, 2=Jaune, 3=Bleu, 4=Gris, 5=Vert, 6=Blanc, 7=Violet, 8=Bleu Cyan", 'w', 1, 50);
	Affichage::text("<Return>: Annuler, <Enter>: Valider", 'r', 115, 50);
	Affichage::resetCursor();
}

void Affichage::paramCmd(int W, int H, int fX, int fY)
{


	_COORD coord;
	coord.X = W;
	coord.Y = H;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = H - 1;
	Rect.Right = W - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      
	SetConsoleScreenBufferSize(Handle, coord);           
	SetConsoleWindowInfo(Handle, TRUE, &Rect);           


	HANDLE f = CreateFileA("CONOUT$", GENERIC_WRITE | GENERIC_READ,
		FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	CONSOLE_FONT_INFOEX cfi = { sizeof(cfi) };
	cfi.dwFontSize.X = fX;
	cfi.dwFontSize.Y = fY;
	SetCurrentConsoleFontEx(f, false, &cfi);

	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	/*
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		cout << csbi.dwSize.Y << " " <<  csbi.dwSize.X;
	}
	*/
}

void Affichage::presentation()
{
	Affichage::text("Creation de Damien LE BORGNE", 'w', 1, 1);
	Affichage::text("MasterMind", 'w', 50, 10);
	Affichage::text("Appuier sur un touche pour continuer", 'w', 25, 20);
	bool b = _getch();

}
