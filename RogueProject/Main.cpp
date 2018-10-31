#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "Item.h"
#include "Player.h"
#include "Utils.h"
#include "Map.h"

const int LEVELWIDTH = 20;
const int LEVELHEIGHT = 10;
bool invActive = false;
std::vector<Item> inventory;

void invInput(Player& p, Map& gameMap);

void handleCollisions(Player& p, Item& potion, Item& armour, Item& sword, Map& gameMap)
{
	// Check the location that the player wants to move to on the map
	char nextLocation = gameMap.getXY(p.getNewPositionY(), p.getNewPositionX());

	// If the nextLocation is a border....
	if (nextLocation == 'a')
	{
		// ....then don't move i.e. set the new position back to the old position
		p.setNewPositionX(p.getPositionX());
		p.setNewPositionY(p.getPositionY());
	}
	// If the nextLocation is a health pack
	if (nextLocation == '+')
	{
		// Increase our health
		p.setHealth(p.getHealth() + 1);

		// Remove it from the map
		gameMap.setXY(p.getNewPositionY(), p.getNewPositionX(), ' ');
	}
	if (nextLocation == sword.getItemSymbol()) //if the player collides with the sword.
	{
		inventory.push_back(sword); //adds to the inventory

		// Remove it from the map
		gameMap.setXY(p.getNewPositionY(), p.getNewPositionX(), ' ');
	}
	if (nextLocation == armour.getItemSymbol()) //if the player collides with the armour
	{
		inventory.push_back(armour); //adds armour into the inventory

		// Remove it from the map
		gameMap.setXY(p.getNewPositionY(), p.getNewPositionX(), ' ');
	}
	if (nextLocation == potion.getItemSymbol()) // if the player collides with the potion
	{
		inventory.push_back(potion); //adds potion into the inventory

		// Remove it from the map
		gameMap.setXY(p.getNewPositionY(), p.getNewPositionX(), ' ');
	}
}

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
		p.renderInventory(inventory); 
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
				//prints item back onto map
				p.dropItem(inventory[input].getItemSymbol(), gameMap, p);
				//removes item from inventory
				inventory.erase(inventory.begin() + input);
				p.renderInventory(inventory);
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
		"a         +        a",
		"a              d   a",
		"a      s           a",
		"a                  a",
		"a               +  a",
		"a                  a",
		"a     +        o   a",
		"a          +       a",
		"aaaaaaaaaaaaaaaaaaaa"
	};

	Map* gameMap = new Map(&map[0][0], LEVELWIDTH+1, LEVELHEIGHT);
	gameMap->initMap(&map[0][0], LEVELWIDTH+1, LEVELHEIGHT);
	gameMap->printMap();

	Item* sword = new Item('s', "Sword");
	Item* armour = new Item('d', "Armour");
	Item* potion = new Item('o', "Potion");

	Player* p = new Player(5,5,5,5, 'P', 100);

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
			handleCollisions(*p, *potion, *armour, *sword, *gameMap);
		}
		if (invActive == true)
		{
			invInput(*p, *gameMap); //inventory controls
		}
	}

	system("pause");
	return 0;
}