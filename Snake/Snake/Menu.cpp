#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::mainMenu()
{
	greetings();
	system("cls");
	int choise = menuChoise();
	switch(choise)
	{
	case 1:

		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		break;
	}
}

void Menu::greetings()
{
	cout << "\t\t\tWitaj w grze SNAKE!" << endl << endl
		<< "Juz za sekunde bedziesz mogl zagrac w SNAKE'a" << endl;
	cin.get();
	cin.get();
}

void Menu::mapChoise(Game &game)
{

}

int Menu::menuChoise()
{
	int number;
	cout << "\t\t\t\t\tSNAKE" << endl << endl
		<< "Co chcialbys teraz zrobic?" << endl
		<< "[1] Zagrac w gre." << endl
		<< "[2] Przeczytac instrukcje." << endl
		<< "[3] Zobaczyc tabele z najwyzszymi wynikami." << endl
		<< "[4] Wyjsc z gry." << endl;;
	cin >> number;
	return number;
}

int Menu::mapSizeChoise()
{
	int number;
	cout << "Wybierz rozmiar mapy na jakim chcialbys grac:" << endl
		<< "[1] 15x25" << endl
		<< "[2] 20x30" << endl
		<< "[3] 25x35" << endl;
	cin >> number;
	return number;
}

int Menu::mapTypeChoise()
{
	int number;
	cout << "Wybierz typ mapy na jakim chcialbys grac:" << endl
		<< "[1] Czysta, zwykla mapa" << endl
		<< "[2] Mapa z przeszkodami" << endl;
	cin >> number;
	return number;
}
