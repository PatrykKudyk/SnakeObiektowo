#pragma once
#include "Food.h"
#include "Snake.h"
#include <vector>

class BiggerFood :
	public Food
{
	int counter;
public:
	BiggerFood();
	~BiggerFood();
	void eatingFood(std::vector<Snake> &snake,unsigned long int &points);
	int getCounter();
	void setCounter(int data);
};

