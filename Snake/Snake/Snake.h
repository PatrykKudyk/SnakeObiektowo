#pragma once
class Snake
{
	int x;
	int y;
public:
	Snake();
	Snake(int x, int y);
	~Snake();
	int getX();
	int getY();
	void setX(int data);
	void setY(int data);
};

