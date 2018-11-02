#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "Item.h"
#include "Weapon.h"
#include "Armour.h"
#include "Potion.h"
#include "Player.h"
#include "Utils.h"
#include "Map.h"

const int LEVELWIDTH = 20;
const int LEVELHEIGHT = 10;
bool invActive = false;
std::vector<Item> inventory;


void handleInput(Player & p);
void invInput(Player& p, Map& gameMap);

void handleInput(Player& p)
{
	char input = _getch();
	p.setNewPositionX(p.getPositionX());
	p.setNewPositionY(p.getPositionY());

	if (GetKeyState(VK_UP) & 0x8000)
	{
		p.setNewPositionY(p.getPositionY() - 1);
		//newPlayerPositionY = playerPositionY - 1;
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		p.setNewPositionY(p.getPositionY() + 1);
		//newPlayerPositionY = playerPositionY + 1;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		p.setNewPositionX(p.getPositionX() + 1);
		//newPlayerPositionX = playerPositionX + 1;
	}
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		p.setNewPositionX(p.getPositionX() - 1);
		//newPlayerPositionX = playerPositionX - 1;
	}
	if (input == 'i' || input == 'I') //prints out inventory when I is pressed
	{
		Utils::printInventory(inventory); 
		invActive = true;
	}
}

void invInput(Player& p, Map& gameMap)
{
	char input = _getch();
	while (true) {

		Utils::gotoXY(0, 18);
		std::cout << "Press 'G' to go back to game or 'D' to delete an item" << std::endl;
		std::cin >> input;
		if (input == 'g' || input == 'G')
		{
			Utils::clearScene();
			gameMap.printMap();

			invActive = false;	//disables inventory controls
			break;
		}
		if (input == 'd' || input == 'D' && inventory.size() >= 0)
		{
			int input;
			Utils::gotoXY(0, 18);
			std::cout << "select the number you want to delete:                       " << std::endl;
			std::cin >> input;
			if (input >= 0 && input <= inventory.size())
			{
				//prints first letter of items name back onto map
				if (p.dropItem(inventory[input].getItemSymbol(), gameMap, p) == true)
				{
					//removes item from inventory
					inventory.erase(inventory.begin() + input);
					Utils::printInventory(inventory);
				}
				else
				{
					Utils::printInventory(inventory); 
				}				
			}
			else {}
		}
	}
}

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

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

	Potion* health = new Potion('h', "Health");
	Weapon* sword = new Weapon('s', "Sword", 5);
	Weapon* mace = new Weapon('m', "Mace", 10);
	Armour* leather = new Armour('l', "Leather", 5);
	Armour* iron = new Armour('i', "Iron", 10);

	//Item *itemPtr[5];
	//itemPtr[0] = new Potion('h', "health");
	//itemPtr[1] = new Weapon('s', "sword", 5);
	//itemPtr[2] = new Weapon('m', "mace", 10);
	//itemPtr[3] = new Armour('l', "leather", 5);
	//itemPtr[4] = new Armour('i', "iron", 10);

	Player* p = new Player(5,5,5,5, 'P', 50, 0, 0);

	while (true)
	{
		if (invActive == false)
		{
			// Render the scene
			p->renderPlayer(*p);

			// Render the GUI
			Utils::renderGUI(*p);

			// Handles the input and updates the players position
			handleInput(*p);

			// Handle collisions
			p->handleCollisions(*p, *health, *sword, *mace, *leather, *iron, *gameMap, inventory);
		}
		if (invActive == true)
		{
			invInput(*p, *gameMap); //inventory controls
		}
	}

	system("pause");
	return 0;
}