#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>

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
			difficultyChoise(game);
			system("cls");
			game.inicialization();
			break;
		case 2:
			system("cls");
			instruction();
			break;
		case 3:
			system("cls");
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
		<< "\tJuz za sekunde bedziesz mogl zagrac w SNAKE'a" << endl;
	pressEnter();
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

void Menu::difficultyChoise(Game& game)
{
	int number;
	cout << "Wybierz poziom trudnosci na jakim chcialbys grac:" << endl
		<< "[1] latwy" << endl
		<< "[2] sredni" << endl
		<< "[3] trudny" << endl
		<< "[4] bardzo trudny" << endl;
	cin >> number;
	switch(number)
	{
	case 1:
		game.setGameSpeed(120);
		break;
	case 2:
		game.setGameSpeed(90);
		break;
	case 3:
		game.setGameSpeed(60);
		break;
	case 4:
		game.setGameSpeed(30);
		break;
	default:
		game.setGameSpeed(120);
		break;
	}
}

void Menu::instruction()
{
	ifstream file;
	string line;
	file.open("Instruction.txt", ios::in);
	if (file.good())
	{
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl; //wyœwietlenie linii
		}
		file.close();
	}
	else
		cout << "Niestety, ale nie udalo sie otworzyc instrukcji." << endl;
	pressEnter();
	cin.get();
	cin.get();
}

void Menu::highScoresDisplay()
{
	ifstream fileNames, fileScores;
	string line;
	int counter = 1;
	fileNames.open("HighScoresNames.txt", ios::in);
	fileScores.open("HighScoresPoints.txt", ios::in);
	if (fileNames.good() && fileScores.good())
	{
		cout << "\t\tTabela Najwyzszych Wynikow" << "\n\n";
		while (!fileNames.eof())
		{
			getline(fileNames, line);
			cout << counter << ". " << line << "   ";
			getline(fileScores, line);
			cout << line << endl;
			counter++;
		}
		fileNames.close();
		fileScores.close();
	}
	else
		cout << "Niestety, ale nie udalo sie otworzyc tabeli." << endl;
	pressEnter();
	cin.get();
	cin.get();
}

void Menu::pressEnter()
{
	cout << "\nNacisnij [Enter]\n";
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
