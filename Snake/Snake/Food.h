#pragma once
class Food
{
	int x;
	int y;
	char type;
public:
	Food();
	virtual ~Food();
	int getX();
	int getY();
	char getType();
	void setX(int data);
	void setY(int data);
	void setType(char data);
};

