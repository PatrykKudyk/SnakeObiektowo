#include <iostream>
#include "Menu.h"
#include <ctime>

int main()
{
	srand(time(NULL));
	Menu menu;
	menu.mainMenu();

	exit(EXIT_SUCCESS);
}
