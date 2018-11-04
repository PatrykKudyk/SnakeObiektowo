#include "Game.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
#include "NormalFood.h"
#include "BiggerFood.h"
#include "PoisonedFood.h"
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

Game::Game()
{
}

Game::~Game()
{
}

void Game::inicialization()
{
	board.inicialiseBoard();
	snake.push_back(Snake(board.getWidth() / 2, board.getHeight() / 2));
	snake.push_back(Snake(board.getWidth() / 2 - 1, board.getHeight() / 2));
	mainGameLoop(72);
}

void Game::mainGameLoop(char startDirection)
{
	char direction = startDirection;
	char tempChar = 0;
	bool game = true;
	int counter = 0;
	NormalFood normal;
	BiggerFood bigger;
	PoisonedFood poisoned;
	generateFoodCords(normal);
	do {
		system("cls");
		do
		{
			bool quit = false;
			if (_kbhit())
			{
				tempChar = _getch();
			}
			directionChanger(direction, quit, tempChar);
			if (quit) break;
		} while (_kbhit() != false);
		board.clearingBoard();
		if (bigger.getCounter() % 50 == 0)
			generateFoodCords(bigger);
		if (poisoned.getCounter() % 65 == 0)
			generateFoodCords(poisoned);
			
		foodBoardPlacing(bigger);
		foodBoardPlacing(normal);
		foodBoardPlacing(poisoned);
		snakeBodyReplacing();
		headMove(direction);
		if (board.getBoard()[snake.front().getY()][snake.front().getX()] != 32 || direction == 27 || selfEating())
			if(!foodEating(normal, bigger, poisoned))
				game = false;
		if(snake.front().getX() == normal.getX() && snake.front().getY() == normal.getY())
		{
			normal.eatingFood(snake,points);
			generateFoodCords(normal);
		}

		if (snake.front().getX() == bigger.getX() && snake.front().getY() == bigger.getY())
		{
			bigger.eatingFood(snake, points);
			generateFoodCords(bigger);
			bigger.setCounter(1);
		}

		if (snake.front().getX() == poisoned.getX() && snake.front().getY() == poisoned.getY())
		{
			poisoned.eatingFood(snake, points);
			generateFoodCords(poisoned);
			poisoned.setCounter(1);
		}

		snakeBoardMove();
		board.displayBoard();	
		
		if (snake.size() == 1)
			game = false;

		cout << "\nPunkty: " << points << endl;
		cout << "Wielkosc wieza: " << snake.size() << endl;
		Sleep(gameSpeed);
		bigger.setCounter(bigger.getCounter() + 1);
		poisoned.setCounter(poisoned.getCounter() + 1);
	} while (game);
	system("cls");
	points = points*snake.size()*(gameSpeed / 10);
	gameEnd();
	system("cls");
	if (isQualifiedToHS())
		highScoreMenu();
	else
	{
		cout << "Niestety, ale nie zakwalifikowales sie do" << endl
			<< "najwyzszych wynikow. Sprobuj jeszcze raz." << endl;
		cin.get();
		cin.get();
	}
	snake.clear();
	points = 0;
	board.resetBoard();
}

void Game::snakeBodyReplacing()
{
	for (int i = snake.size() - 1; i > 0; i--)
	{
		snake[i].setX(snake[i - 1].getX());
		snake[i].setY(snake[i - 1].getY());
	}
}

void Game::headMove(char direction)
{
	switch (direction)
	{
	case 72://góra
		snake.front().moveUp();
		break;
	case 80:
		snake.front().moveDown();
		break;
	case 75:
		snake.front().moveLeft();
		break;
	case 77:
		snake.front().moveRight();
		break;
	default:
		break;
	}
}

void Game::directionChanger(char& dir, bool& quit, char tempDir)
{
	switch (tempDir)
	{
	case 80://dó³
		if (dir != 72 && dir != 80) dir = tempDir;
		quit = true;
		break;
	case 77://prawo
		if (dir != 75 && dir != 77) dir = tempDir;
		quit = true;
		break;
	case 75://lewo
		if (dir != 75 && dir != 77) dir = tempDir;
		quit = true;
		break;
	case 72://góra
		if (dir != 72 && dir != 80) dir = tempDir;
		quit = true;
		break;
	case 27:
		dir = tempDir;
		quit = true;
		break;
	default:
		break;
	}
}

void Game::snakeBoardMove()
{
	for(int i = snake.size() - 1; i >= 0; i--)
	{
		if (i == 0)
			board.setBoardPoint(snake.front().getX(), snake.front().getY(), 'O');
		else
			board.setBoardPoint(snake[i].getX(), snake[i].getY(), 'o');
	}
}

void Game::generateFoodCords(Food& food)
{
	int x, y;
	do
	{
		x = rand() % board.getWidth();
		y = rand() % board.getHeight();
	} while (board.getBoard()[y][x] != 32);
	food.setY(y);
	food.setX(x);
}

void Game::foodBoardPlacing(Food& food)
{
	if (food.getType() == 'n')
		board.setBoardPoint(food.getX(), food.getY(), 224);
	if (food.getType() == 'b')
		board.setBoardPoint(food.getX(), food.getY(), 153);
	if (food.getType() == 'p')
		board.setBoardPoint(food.getX(), food.getY(), 207);
}

void Game::gameEnd()
{
	cout << "\n\tNiestety, ale przegrales.\n"
		<< "\tTwoj wynik to: " << points << endl
		<< "\tTwoj waz mial dlugosc: " << snake.size() << endl
		<< "\tGratuluje!" << endl;
	cin.get();
	cin.get();
}

void Game::highScoreMenu()
{
	fstream fileNames, fileScores;
	string name, line;
	do 
	{
		system("cls");
		cout << "Podaj swoj nick" << endl
			<< "(Nie moze miec wiecej niz 6 znakow!): ";
		cin >> name;
	} while (name.size() > 6);
	
	vector<string> names;
	vector<double> pointsVec;
	double points;
	fileNames.open("HighScoresNames.txt", ios::in);
	fileScores.open("HighScoresPoints.txt", ios::in);
	if (fileNames.good() && fileScores.good())
	{
		while (!fileNames.eof())
		{
			getline(fileNames, line);
			names.push_back(line);
			fileScores >> points;
			pointsVec.push_back(points);
		}
		fileNames.close();
		fileScores.close();
	}
	pointsVec.push_back(this->points);
	sort(pointsVec.rbegin(), pointsVec.rend());
	int position;
	for (int i = 0; i < pointsVec.size(); i++)
		if (pointsVec[i] == (double)this->points)
			position = i;
	vector<string> tempNames;
	for (int i = 0; i < position; i++)
		tempNames.push_back(names[i]);
	tempNames.push_back(name);
	for (int i = position; i < names.size(); i++)
		tempNames.push_back(names[i]);

	fileNames.open("HighScoresNames.txt", ios::out | ios::trunc);
	fileScores.open("HighScoresPoints.txt", ios::out | ios::trunc);
	if (fileNames.good() && fileScores.good())
	{
		for (int i = 0; i < pointsVec.size() - 1; i++)
		{
			fileNames << tempNames[i] << endl;
			fileScores << pointsVec[i] << endl;
		}
		fileNames.close();
		fileScores.close();
	}
}

bool Game::selfEating()
{
	for (int i = 1; i < snake.size(); i++)
		if (snake.front().getX() == snake[i].getX() && snake.front().getY() == snake[i].getY())
			return true;
	return false;
}

bool Game::foodEating(Food food1, Food food2, Food food3)
{
	if (snake.front().getX() == food1.getX() && snake.front().getY() == food1.getY())
		return true;
	if (snake.front().getX() == food2.getX() && snake.front().getY() == food2.getY())
		return true;
	if (snake.front().getX() == food3.getX() && snake.front().getY() == food3.getY())
		return true;
	return false;
}

bool Game::isQualifiedToHS()
{
	fstream file;
	double score;
	file.open("HighScoresPoints.txt", ios::in);
	if (file.good())
	{
		vector<double> scores;
		while(!file.eof())
		{
			file >> score;
			scores.push_back(score);
		}
		for (int i = 0; i < scores.size(); i++)
			if ((double)points > scores[i])
				return true;
		return false;
	}
	else
		cout << "Nie udalo sie otworzyc pliku z najwyzszymi wynikami." << endl;
	return false;
}

int Game::generateX()
{
	return rand() % board.getWidth();

}

int Game::generateY()
{
	return rand() % board.getHeight();
}

Board Game::getBoard()
{
	return board;
}

int Game::getPoints()
{
	return points;
}

int Game::getGameSpeed()
{
	return gameSpeed;
}

void Game::setBoard(int height, int width)
{
	board.setHeight(height);
	board.setWidth(width);
}

void Game::setPoints(int data)
{
	points = data;
}

void Game::setBoardType(int data)
{
	board.setType(data);
}

void Game::setGameSpeed(int data)
{
	gameSpeed = data;
}
