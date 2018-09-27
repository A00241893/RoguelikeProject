#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "Item.h"

const int LEVELWIDTH = 20;
const int LEVELHEIGHT = 10;

unsigned int playerPositionX = 5;
unsigned int playerPositionY = 5;
unsigned int newPlayerPositionX = playerPositionX;
unsigned int newPlayerPositionY = playerPositionY;

unsigned int health = 0;

char playerChar = 'P';
bool invActive = false;
std::vector<Item> inventory;
Item* sword = new Item('s',"Sword");
Item* armour = new Item('d', "Armour");
Item* potion = new Item('o', "Potion");

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

void clearScene();
void invInput();
void renderInventory();
void dropItem(char drop);

void gotoXY(short C, short R)
{
	COORD xy;
	xy.X = C;
	xy.Y = R;
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void handleCollisions()
{
	// Check the location that the player wants to move to on the map
	char nextLocation = map[newPlayerPositionY][newPlayerPositionX];

	// If the nextLocation is a border....
	if (nextLocation == 'a')
	{
		// ....then don't move i.e. set the new position back to the old position
		newPlayerPositionX = playerPositionX;
		newPlayerPositionY = playerPositionY;
	}
	// If the nextLocation is a health pack
	if (nextLocation == '+')
	{
		// Increase our health
		health++;

		// Remove it from the map
		map[newPlayerPositionY][newPlayerPositionX] = ' ';
	}
	if (nextLocation == sword->getItemSymbol())
	{
		inventory.push_back(*sword); //adds sword into the inventory

		// Remove it from the map
		map[newPlayerPositionY][newPlayerPositionX] = ' ';
	}
	if (nextLocation == armour->getItemSymbol())
	{
		inventory.push_back(*armour); //adds armour into the inventory

		// Remove it from the map
		map[newPlayerPositionY][newPlayerPositionX] = ' ';
	}
	if (nextLocation == potion->getItemSymbol())
	{
		inventory.push_back(*potion); //adds potion into the inventory

		// Remove it from the map
		map[newPlayerPositionY][newPlayerPositionX] = ' ';
	}
}

void renderMap()
{
	clearScene(); //blanks out the screen
	for (int i = 0; i<LEVELHEIGHT; i++)  //prints out the map
	{
		std::cout << map[i] << std::endl;
	}

	gotoXY(0, 18);	//prints the below text at this location
	std::cout << "Press I to go to the Inventory" << std::endl;
}

void handleInput()
{
	newPlayerPositionX = playerPositionX;
	newPlayerPositionY = playerPositionY;

	if (GetKeyState(VK_UP) & 0x8000)
	{
		newPlayerPositionY = playerPositionY - 1;
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		newPlayerPositionY = playerPositionY + 1;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		newPlayerPositionX = playerPositionX + 1;
	}
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		newPlayerPositionX = playerPositionX - 1;
	}
	if (GetAsyncKeyState('I') & 0x8000) //prints out inventory when I is pressed
	{
		renderInventory(); 
		invActive = true;
	}
}

void invInput()
{
	char input = _getch();
	while (true) {
		gotoXY(0, 18);
		std::cout << "Press 'G' to go back to game or 'D' to delete an item" << std::endl;
		std::cin >> input;
		if (input == 'g' || input == 'G')
		{
			renderMap();	//prints out the map
			invActive = false;	//disables inventory controls
			break;
		}
		if (input == 'd' || input == 'D' && inventory.size() >= 0)
		{
			int x;
			gotoXY(0, 18);
			std::cout << "select the number you want to delete:                       " << std::endl;
			std::cin >> x;
			if (x >= 0 && x <= inventory.size())
			{
				dropItem(inventory[x].getItemSymbol()); //prints symbol back in the map
				inventory.erase(inventory.begin() + x);	//removes item from inventory
				renderInventory();
			}
			else {}
		}
	}
}

void dropItem(char drop)
{
	/**checks if the spaces around the player is empty. 
	if it is empty it prints the item to be dropped symbol in that space
	**/
	if (map[newPlayerPositionY][newPlayerPositionX - 1] == ' ')
	{
		map[newPlayerPositionY][newPlayerPositionX - 1] = drop;
	}
	else if (map[newPlayerPositionY][newPlayerPositionX + 1] == ' ')
	{
		map[newPlayerPositionY][newPlayerPositionX + 1] = drop;
	}
	else if (map[newPlayerPositionY + 1][newPlayerPositionX] == ' ')
	{
		map[newPlayerPositionY + 1][newPlayerPositionX] = drop;
	}
	else if (map[newPlayerPositionY - 1][newPlayerPositionX] == ' ')
	{
		map[newPlayerPositionY - 1][newPlayerPositionX] = drop;
	}
	else
	{
		std::cout << "There is no space to drop items" << std::endl;
	}
}

void renderPlayer()
{
	// Blank old enemy position
	gotoXY(playerPositionX, playerPositionY);
	std::cout << ' ';

	// Draw new enemy position
	gotoXY(newPlayerPositionX, newPlayerPositionY);
	std::cout << playerChar;

	playerPositionX = newPlayerPositionX;
	playerPositionY = newPlayerPositionY;

	Sleep(60);
}

void renderGUI()
{
	gotoXY(2, LEVELHEIGHT + 3);
	std::cout << "Health: " << health;
}

void clearScene() // Blanks out the screen
{
	gotoXY(0, 0); // goes to first position in the scene

	/** prints out 40 x 100 blank spaces 
	**/
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
	gotoXY(0, 0);
}

void renderInventory()
{
	clearScene();
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

	renderMap();

	while (true)
	{
		if (invActive == false)
		{
			// Render the scene
			renderPlayer();

			// Render the GUI
			renderGUI();

			// Handles the input and updates the players position
			handleInput();

			// Handle collisions
			handleCollisions();
		}
		if (invActive == true)
		{
			invInput(); //inventory controls
		}
	}

	system("pause");
}