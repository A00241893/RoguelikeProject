#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

const int LEVELWIDTH = 20;
const int LEVELHEIGHT = 10;

unsigned int playerPositionX = 5;
unsigned int playerPositionY = 5;
unsigned int newPlayerPositionX = playerPositionX;
unsigned int newPlayerPositionY = playerPositionY;

unsigned int health = 0;

char playerChar = 'P';
bool invActive = false;
std::vector<std::string> inventory;

char map[LEVELHEIGHT][LEVELWIDTH + 1] =
{ "aaaaaaaaaaaaaaaaaaaa",
"a         +        a",
"a  w               a",
"a                  a",
"a                  a",
"a  o            +  a",
"a                  a",
"a     +         x  a",
"a          +       a",
"aaaaaaaaaaaaaaaaaaaa"
};

void clearScene();
void invInput();
void renderInventory();

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
	if (nextLocation == 'w')
	{
		inventory.push_back("weapon");

		// Remove it from the map
		map[newPlayerPositionY][newPlayerPositionX] = ' ';
	}
	if (nextLocation == 'x')
	{
		inventory.push_back("armour");

		// Remove it from the map
		map[newPlayerPositionY][newPlayerPositionX] = ' ';
	}
	if (nextLocation == 'o')
	{
		inventory.push_back("potion");

		// Remove it from the map
		map[newPlayerPositionY][newPlayerPositionX] = ' ';
	}
}

void renderMap()
{
	clearScene();
	for (int i = 0; i<LEVELHEIGHT; i++)
	{
		std::cout << map[i] << std::endl;
	}

	gotoXY(0, 18);
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
	if (GetAsyncKeyState('I') & 0x8000) //open inventory
	{
		renderInventory();
		invActive = true;
	}
}

void invInput()
{
	char input;
	std::cin >> input;
	if (input == 'g' || input == 'G') //open Game
	{
		renderMap();
		invActive = false;
	}
	if (input == 'd' || input == 'D')
	{
		int x;
		gotoXY(0, 20);
		std::cout << "select the number you want to delete:" << std::endl;
		std::cin >> x;
		if (x >= 0 && x <= inventory.size())
		{
			inventory.erase(inventory.begin() + x);
			renderInventory();
		}
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
	gotoXY(0, 0);

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
	for (int i = 0; i < inventory.size(); i++)
	{
		std::cout << i << ": " << inventory[i] << std::endl;
	}
	std::cout << "--------------------" << std::endl;

	gotoXY(0, 18);
	std::cout << "Press G to go back to game" << std::endl;
	gotoXY(0, 19);
	std::cout << "Press D to delete an item" << std::endl;
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
			invInput();
		}
	}

	system("pause");
}