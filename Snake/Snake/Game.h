#pragma once
#include "Board.h"
#include "Snake.h"
#include <vector>
#include "NormalFood.h"

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
	void generateFoodCords(NormalFood &food);
	void foodBoardPlacing(NormalFood &food);
	void gameEnd();
	bool selfEating();
	int generateX();
	int generateY();
	Board getBoard();
	int getPoints();
	void setBoard(int height, int width);
	void setPoints(int data);
	void setBoardType(int data);
};

