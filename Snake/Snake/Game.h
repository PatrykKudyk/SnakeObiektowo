#pragma once
class Game
{
	int height;
	int width;
	char type;
public:
	Game();
	~Game();
	void mainGameLoop();
	int getHeight();
	int getWidth();
	char getType();
	void setHeight(int data);
	void setWidth(int data);
	void setType(char data);
};

