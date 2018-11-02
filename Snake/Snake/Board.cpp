#include "Board.h"



Board::Board()
{
}

Board::~Board()
{ 
	if (board != nullptr)
		for (int i = 0; i < height; i++)
			delete[] board[i];
	delete[] board;
}

void Board::inicialiseBoard()
{
	board = new char*[height];
	for (int i = 0; i < height; i++)
		board[i] = new char[width];
}

int Board::getHeight()
{
	return height;
}

int Board::getWidth()
{
	return width;
}

void Board::setHeight(int data)
{
	height = data;
}

void Board::setWidth(int data)
{
	width = data;
}
