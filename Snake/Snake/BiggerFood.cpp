#include "BiggerFood.h"



BiggerFood::BiggerFood()
{
	setType('b');
	counter = 0;
}


BiggerFood::~BiggerFood()
{
}

void BiggerFood::eatingFood(std::vector<Snake>& snake, int& points)
{
	snake.push_back(Snake(snake.back().getX(), snake.back().getY()));
	points += 30;
}

int BiggerFood::getCounter()
{
	return counter;
}

void BiggerFood::setCounter(int data)
{
	counter = data;
}
