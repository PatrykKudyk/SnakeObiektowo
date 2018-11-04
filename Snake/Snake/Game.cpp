#include "Game.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
#include "NormalFood.h"

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
	NormalFood normal;
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
		foodBoardPlacing(normal);
		snakeBodyReplacing();
		headMove(direction);
		if (board.getBoard()[snake.front().getY()][snake.front().getX()] != 32 || direction == 27 || selfEating())
			if(snake.front().getX() != normal.getX() && snake.front().getY() != normal.getY())
				game = false;
		if(snake.front().getX() == normal.getX() && snake.front().getY() == normal.getY())
		{
			generateFoodCords(normal);
			snake.push_back(Snake(snake.back().getX(),snake.back().getY()));
			points += 10;
		}
		snakeBoardMove();
		board.displayBoard();	
		

		cout << "\nPunkty: " << points << endl;
		cout << "Wielkosc wieza: " << snake.size() << endl;
		Sleep(120);
	} while (game);
	system("cls");
	gameEnd();
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
			board.setBoardPoint(snake.front().getX(), snake.front().getY(), 254);
		else
			board.setBoardPoint(snake[i].getX(), snake[i].getY(), 'o');
	}
}

void Game::generateFoodCords(NormalFood& food)
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

void Game::foodBoardPlacing(NormalFood& food)
{
	board.setBoardPoint(food.getX(), food.getY(), 224);
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

bool Game::selfEating()
{
	for (int i = 1; i < snake.size(); i++)
		if (snake.front().getX() == snake[i].getX() && snake.front().getY() == snake[i].getY())
			return true;
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
