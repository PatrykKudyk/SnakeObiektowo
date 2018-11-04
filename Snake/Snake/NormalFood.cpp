#include "NormalFood.h"



NormalFood::NormalFood()
{
	setType('n');
}


NormalFood::~NormalFood()
{
}

void NormalFood::eatingFood(std::vector<Snake> &snake, int &points)
{
	snake.push_back(Snake(snake.back().getX(), snake.back().getY()));
	points += 10;
}
