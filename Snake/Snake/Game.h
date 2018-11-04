#pragma once
#include "Board.h"
#include "Snake.h"
#include <vector>
#include "NormalFood.h"

class Game
{
	Board board;
	unsigned long int points;
	std::vector<Snake> snake;
	int gameSpeed;
public:
	Game();
	~Game();
	void inicialization();
	void mainGameLoop(char startDirection);
	void snakeBodyReplacing();
	void headMove(char direction);
	void directionChanger(char &dir, bool &quit, char tempDir);
	void snakeBoardMove();
	void generateFoodCords(Food &food);
	void foodBoardPlacing(Food &food);
	void gameEnd();
	void highScoreMenu();
	bool selfEating();
	bool foodEating(Food food1, Food food2, Food food3);
	bool isQualifiedToHS();
	int generateX();
	int generateY();
	Board getBoard();
	int getPoints();
	int getGameSpeed();
	void setBoard(int height, int width);
	void setPoints(int data);
	void setBoardType(int data);
	void setGameSpeed(int data);
};

