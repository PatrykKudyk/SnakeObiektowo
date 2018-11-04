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
	bool quit = true;
	Game game;
	greetings();
	do {
		system("cls");
		int choise = menuChoise();
		switch (choise)
		{
		case 1:
			mapChoise(game);
			system("cls");
			game.inicialization();
			break;
		case 2:
			instruction();
			break;
		case 3:
			highScoresDisplay();
			break;
		case 4:
			quit = false;
			break;
		default:
			break;
		}
	} while (quit);
}

void Menu::greetings()
{
	cout << "\t\t\tWitaj w grze SNAKE!" << endl << endl
		<< "\tJuz za sekunde bedziesz mogl zagrac w SNAKE'a" << endl << endl
		<< "\tWcisnij [Enter]" << endl;
	cin.get();
}

void Menu::mapChoise(Game &game)
{
	int choise;
	system("cls");
	choise = mapSizeChoise();
	switch(choise)
	{
	case 1:
		game.setBoard(15, 25);
		break;
	case 2:
		game.setBoard(20, 35);
		break;
	case 3:
		game.setBoard(25, 45);
		break;
	default:
		break;
	}
	choise = mapTypeChoise();
	switch(choise)
	{
	case 1:
		game.setBoardType(0);
		break;
	case 2:
		game.setBoardType(1);
		break;
	default:
		break;
	}
}

void Menu::instruction()
{
	cout << "\t\t\tInstrukcja\n\n";
}

void Menu::highScoresDisplay()
{
	cout << "\t\t\tTabela Wynikow" << endl;
}

int Menu::menuChoise()
{
	int number;
	cout << "\t\t\t\t\tSNAKE" << endl << endl
		<< "\tCo chcialbys teraz zrobic?" << endl
		<< "[1] Zagrac w gre." << endl
		<< "[2] Przeczytac instrukcje." << endl
		<< "[3] Zobaczyc tabele z najwyzszymi wynikami." << endl
		<< "[4] Wyjsc z gry." << endl << endl
		<< "Wyboru dokonaj poprzez wprowadzenie odpowiedniej cyfry oraz zatwierdz" << endl
		<< "przyciskiem [Enter]" << endl;
	cin >> number;
	return number;
}

int Menu::mapSizeChoise()
{
	int number;
	cout << "Wybierz rozmiar mapy na jakim chcialbys grac:" << endl
		<< "[1] 15x25" << endl
		<< "[2] 20x35" << endl
		<< "[3] 25x45" << endl;
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
