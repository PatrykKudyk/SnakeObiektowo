#include "Food.h"



Food::Food()
{
}


Food::~Food()
{
}

int Food::getX()
{
	return x;
}

int Food::getY()
{
	return y;
}

char Food::getType()
{
	return type;
}

void Food::setX(int data)
{
	x = data;
}

void Food::setY(int data)
{
	y = data;
}

void Food::setType(char data)
{
	type = data;
}
