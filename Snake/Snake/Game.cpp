#include "Game.h"
#include <ios>


Game::Game()
{
}


Game::~Game()
{
}

void Game::inicialization()
{
}

void Game::mainGameLoop()
{
	do
	{
		
	} while (true);
}

char Game::getType()
{
	return type;
}

void Game::setType(char data)
{
	type = data;
}

Board Game::getBoard()
{
	return board;
}

void Game::setBoard(int height, int width)
{
	board.setHeight(height);
	board.setWidth(width);
	board.inicialiseBoard();
}
