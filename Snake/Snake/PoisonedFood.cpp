#include "PoisonedFood.h"



PoisonedFood::PoisonedFood()
{
	setType('p');
	counter = 0;
}


PoisonedFood::~PoisonedFood()
{
}

void PoisonedFood::eatingFood(std::vector<Snake>& snake,unsigned long int& points)
{
	if(snake.size() > 1)
		snake.pop_back();
	points += 20;
}

int PoisonedFood::getCounter()
{
	return counter;
}

void PoisonedFood::setCounter(int data)
{
	counter = data;
}
