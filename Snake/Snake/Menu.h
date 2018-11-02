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
	void instruction();
	void highScoresDisplay();
	int menuChoise();
	int mapSizeChoise();
	int mapTypeChoise();
};

