#include "Board.h"
#include <iostream>


Board::Board()
{
	height = 0;
	width = 0;
	type = 0;
	board = nullptr;
}

Board::~Board()
{ 
	if (board != nullptr)
	{
		for (int i = 0; i < height; i++)
			delete[] board[i];
		delete[] board;
	}
}

void Board::inicialiseBoard()
{
	board = new char*[height];
	for (int i = 0; i < height; i++)
		board[i] = new char[width];
	clearingBoard();
}

void Board::displayBoard()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			std::cout << board[i][j];
		std::cout << std::endl;
	}
		
}

void Board::clearingBoard()
{
	switch (type)
	{
	case 0:
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (i == 0 || i == height - 1) board[i][j] = 219;// 205;
				else if (j == 0 || j == width - 1) board[i][j] = 219;// 186;
				else board[i][j] = 32;
			}
		}
		break;
	case 1:
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (i == 0 || i == height - 1) board[i][j] = 219;// 205;
				else if (j == 0 || j == width - 1) board[i][j] = 219;// 186;
				else if (i == 2)
				{
					if (j >= width / 3 && j <= (width / 3) + 2)
						board[i][j] = 219;
					else board[i][j] = 32;
				}
				else if (j == width / 2)
				{
					if (i >= height / 2 && i <= (height / 2) + 4)
						board[i][j] = 219;
					else board[i][j] = 32;
				}
				else if (i == 3)
				{
					if (j >= width - 6 && j <= width - 3)
						board[i][j] = 219;
					else board[i][j] = 32;
				}
				else if (j == width - 3)
				{
					if (i > 3 && i <= 7)
						board[i][j] = 219;
					else board[i][j] = 32;
				}
				else board[i][j] = 32;
			}
		}
		break;
	default:
		break;
	}
}

int Board::getHeight()
{
	return height;
}

int Board::getWidth()
{
	return width;
}

int Board::getType()
{
	return type;
}

char** Board::getBoard()
{
	return board;
}

void Board::setHeight(int data)
{
	height = data;
}

void Board::setWidth(int data)
{
	width = data;
}

void Board::setType(int data)
{
	type = data;
}

void Board::setBoardPoint(int x, int y, char data)
{
	board[y][x] = data;
}

void Board::resetBoard()
{
	for (int i = 0; i < height; i++)
		delete[] board[i];
	delete[] board;
	char** temp = nullptr;
	board = temp;
}
