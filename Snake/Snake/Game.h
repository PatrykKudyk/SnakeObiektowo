#pragma once
#include "Board.h"
#include "Snake.h"
#include <vector>

class Game
{
	Board board;
	int points;
	std::vector<Snake> snake;
public:
	Game();
	~Game();
	void inicialization();
	void mainGameLoop(char startDirection);
	void snakeBodyReplacing();
	void headMove(char direction);
	void directionChanger(char &dir, bool &quit, char tempDir);
	void snakeBoardMove();
	Board getBoard();
	int getPoints();
	void setBoard(int height, int width);
	void setPoints(int data);
	void setBoardType(int data);
};

