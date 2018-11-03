#pragma once
class Board
{
	char **board;
	int height;
	int width;
	int type; //1 - normal, 2 - with walls
public:
	Board();
	~Board();
	void inicialiseBoard();
	void displayBoard();
	void clearingBoard();
	int getHeight();
	int getWidth();
	int getType();
	char** getBoard();
	void setHeight(int data);
	void setWidth(int data);
	void setType(int data);
	void setBoardPoint(int x, int y, char data);
	void resetBoard();
};

