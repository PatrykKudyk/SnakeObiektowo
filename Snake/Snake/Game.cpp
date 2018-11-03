#include "Game.h"
#include <conio.h>
#include <iostream>
#include <windows.h>

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
	char direction = 32;
	bool loopWork = true;
	while(loopWork)
	{
		do
		{
			if (_kbhit())
			{
				direction = _getch();
			}

			switch (direction)
			{
			case 80:
				loopWork = false;
				break;
			case 77:
				loopWork = false;
				break;
			case 75:
				loopWork = false;
				break;
			case 72:
				loopWork = false;
				break;
			default:
				break;
			}
			if (!loopWork) break;
		} while (_kbhit() != false);
	}
	snake.push_back(Snake(board.getWidth() / 2, board.getHeight() / 2));
	snake.push_back(snake.front());
	snake.push_back(snake.front());
	mainGameLoop(direction);
}

void Game::mainGameLoop(char startDirection)
{
	char direction = startDirection;
	char tempChar = 0;
	bool game = true;
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
		snakeBodyReplacing();
		snakeBoardMove();
		board.displayBoard();

		headMove(direction);

		if (board.getBoard()[snake.front().getX()][snake.front().getY()] != 32 || direction == 27)
			game = false;

		cout << "\n Punkty: " << points << endl;
		Sleep(80);
	} while (game);

	board.resetBoard();
}

void Game::snakeBodyReplacing()
{
	for (int i = snake.size() - 1; i > 0; i--)
			snake[i] = snake[i - 1];
}

void Game::headMove(char direction)
{
	switch (direction)
	{
	case 72:
		snake.front().setY(snake.front().getY() + 1);
		break;
	case 80:
		snake.front().setY(snake.front().getY() - 1);
		break;
	case 75:
		snake.front().setX(snake.front().getX() - 1);
		break;
	case 77:
		snake.front().setX(snake.front().getX() + 1);
		break;
	default:
		break;
	}
}

void Game::directionChanger(char& dir, bool& quit, char tempDir)
{
	switch (tempDir)
	{
	case 80:
		if (dir != 72 && dir != 80) dir = tempDir;
		quit = true;
		break;
	case 77:
		if (dir != 75 && dir != 77) dir = tempDir;
		quit = true;
		break;
	case 75:
		if (dir != 75 && dir != 77) dir = tempDir;
		quit = true;
		break;
	case 72:
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
