#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "Item.h"
#include "Player.h"
#include "Utils.h"

const int LEVELWIDTH = 20;
const int LEVELHEIGHT = 10;

bool invActive = false;

char map[LEVELHEIGHT][LEVELWIDTH + 1] =
{ "aaaaaaaaaaaaaaaaaaaa",
"a         +        a",
"a  s               a",
"a                  a",
"a                  a",
"a  o            +  a",
"a                  a",
"a     +         d  a",
"a          +       a",
"aaaaaaaaaaaaaaaaaaaa"
};

std::vector<Item> inventory;
Item* sword = new Item('s',"Sword");
Item* armour = new Item('d', "Armour");
Item* potion = new Item('o', "Potion");


void invInput(Player& p, char* map[]);
void renderInventory();


void handleCollisions(Player& p)
{
	// Check the location that the player wants to move to on the map
	char nextLocation = map[p.getNewPositionY()][p.getNewPositionX()];

	// If the nextLocation is a border....
	if (nextLocation == 'a')
	{
		// ....then don't move i.e. set the new position back to the old position
		p.setNewPositionX(p.getPositionX());
		p.setNewPositionY(p.getPositionY());
	}
	if (nextLocation == ' ')
	{
		p.setPositionX(p.getNewPositionX());
		p.setPositionY(p.getNewPositionY());
		
	}
	// If the nextLocation is a health pack
	if (nextLocation == '+')
	{
		// Increase our health
		p.setHealth(p.getHealth() + 1);

		// Remove it from the map
		map[p.getNewPositionY()][p.getNewPositionX()] = ' ';
	}
	if (nextLocation == sword->getItemSymbol()) //if the player collides with the sword.
	{
		inventory.push_back(*sword); //adds to the inventory

		// Remove it from the map
		map[p.getNewPositionY()][p.getNewPositionX()] = ' ';
	}
	if (nextLocation == armour->getItemSymbol()) //if the player collides with the armour
	{
		inventory.push_back(*armour); //adds armour into the inventory

		// Remove it from the map
		map[p.getNewPositionY()][p.getNewPositionX()] = ' ';
	}
	if (nextLocation == potion->getItemSymbol()) // if the player collides with the potion
	{
		inventory.push_back(*potion); //adds potion into the inventory

		// Remove it from the map
		map[p.getNewPositionY()][p.getNewPositionX()] = ' ';
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
		renderInventory(); 
		invActive = true;
	}
}

void invInput(Player& p, char* map[])
{
	char input = _getch();
	while (true) {

		Utils::gotoXY(0, 18);
		std::cout << "Press 'G' to go back to game or 'D' to delete an item" << std::endl;
		std::cin >> input;
		if (input == 'g' || input == 'G')
		{
			Utils::renderMap(LEVELHEIGHT, map);	//prints out the map
			invActive = false;	//disables inventory controls
			break;
		}
		if (input == 'd' || input == 'D' && inventory.size() >= 0)
		{
			int x;
			Utils::gotoXY(0, 18);
			std::cout << "select the number you want to delete:                       " << std::endl;
			std::cin >> x;
			if (x >= 0 && x <= inventory.size())
			{
				p.dropItem(inventory[x].getItemSymbol(), map, p);
				inventory.erase(inventory.begin() + x);	//removes item from inventory
				renderInventory();
			}
			else {}
		}
	}
}

void renderInventory()
{
	Utils::clearScene();
	std::cout << "Inventory:" << std::endl;
	std::cout << "--------------------" << std::endl;
	for (int i = 0; i < inventory.size(); i++)		//prints out the vector of inventory items
	{
		std::cout << i << ": " << inventory[i].getItemName() << std::endl;
	}
	std::cout << "--------------------" << std::endl;
}

void main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	char* m[LEVELHEIGHT];
	*m = map[0];

	Player* p = new Player(Position(5,5,5,5), 'P', 100, 0);
	Utils::renderMap(LEVELHEIGHT, m);

	while (true)
	{
		if (invActive == false)
		{
			// Render the scene
			p->renderPlayer(*p);

			// Render the GUI
			Utils::renderGUI(*p, LEVELHEIGHT);

			// Handles the input and updates the players position
			handleInput(*p);

			// Handle collisions
			handleCollisions(*p);
		}
		if (invActive == true)
		{
			invInput(*p, m); //inventory controls
		}
	}

	system("pause");
}