#pragma once
#include "Board.h"

class Game
{
	
	char type;
	Board board;
public:
	Game();
	~Game();
	void inicialization();
	void mainGameLoop();
	char getType();
	void setType(char data);
	Board getBoard();
	void setBoard(int height, int width);
};

