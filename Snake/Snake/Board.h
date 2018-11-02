#pragma once
class Board
{
	char **board;
	int height;
	int width;
public:
	Board();
	~Board();
	void inicialiseBoard();
	int getHeight();
	int getWidth();
	void setHeight(int data);
	void setWidth(int data);
};

