#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "Position.h"
#include "Weapon.h"
#include "Armour.h"
#include "Potion.h"
#include "GameEngine.h"
#include "Map.h"

const int LEVELWIDTH = 20;
const int LEVELHEIGHT = 10;
bool invActive = false;
std::vector<Item> inventory;

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	GameEngine gameEng;

	char map[LEVELHEIGHT][LEVELWIDTH + 1] =
	{ "aaaaaaaaaaaaaaaaaaaa",
		"a                  a",
		"a              h   a",
		"a      s           a",
		"a           i      a",
		"a                  a",
		"a                  a",
		"a              m   a",
		"a   l              a",
		"aaaaaaaaaaaaaaaaaaaa"
	};

	Map* gameMap = new Map(&map[0][0], LEVELWIDTH+1, LEVELHEIGHT);
	gameMap->initMap(&map[0][0], LEVELWIDTH+1, LEVELHEIGHT);
	gameMap->printMap();

	Item *itemPtr[5];
	itemPtr[0] = new Potion('h', "Health", 20);
	itemPtr[1] = new Weapon('s', "Sword", 5);
	itemPtr[2] = new Weapon('m', "Mace", 10);
	itemPtr[3] = new Armour('l', "Leather", 5);
	itemPtr[4] = new Armour('i', "Iron", 10);

	Player* p = new Player(5,5,5,5, 'P', 50, 0, 0);

	while (true)
	{
		if (invActive == false)
		{
			// Render the scene
			p->renderPlayer(*p);

			// Render the GUI
			gameEng.renderGUI(*p);

			// Handles the input
			if (gameEng.handleInput(*p, inventory) == true)
			{
				invActive = true; // activates inventory
			}

			// Handle collisions
			p->handleCollisions(*p, itemPtr, *gameMap, inventory);
		}
		if (invActive == true)
		{
			if (gameEng.invInput(*p, *gameMap, inventory) == true) //inventory controls
			{
				invActive = false; // activates game controls
			}
		}
	}

	system("pause");
	return 0;
}