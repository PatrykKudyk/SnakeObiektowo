#pragma once
#include "Game.h"

class Menu
{
public:
	Menu();
	~Menu();
	void mainMenu();
	void greetings();
	void mapChoise(Game &game);
	int menuChoise();
	int mapSizeChoise();
	int mapTypeChoise();
};

