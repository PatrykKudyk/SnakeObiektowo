#pragma once
#include "Food.h"
#include "Snake.h"
#include <vector>

class PoisonedFood :
	public Food
{
	int counter;
public:
	PoisonedFood();
	~PoisonedFood();
	void eatingFood(std::vector<Snake> &snake, int &points);
	int getCounter();
	void setCounter(int data);
};

