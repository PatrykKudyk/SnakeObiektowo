#include "Snake.h"



Snake::Snake()
{
}

Snake::Snake(int x, int y)
{
	this->x = x;
	this->y = y;
}


Snake::~Snake()
{
}

int Snake::getX()
{
	return x;
}

int Snake::getY()
{
	return y;
}

void Snake::setX(int data)
{
	x = data;
}

void Snake::setY(int data)
{
	y = data;
}
