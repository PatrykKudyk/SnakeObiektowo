#pragma once
#include "Food.h"
#include <vector>
#include "Snake.h"

class NormalFood :
	public Food
{
public:
	NormalFood();
	~NormalFood();
	void eatingFood(std::vector<Snake> &snake, unsigned long int &points);
};

