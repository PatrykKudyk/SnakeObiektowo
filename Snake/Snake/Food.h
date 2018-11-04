#pragma once
class Food
{
	int x;
	int y;
public:
	Food();
	virtual ~Food();
	int getX();
	int getY();
	void setX(int data);
	void setY(int data);
};

