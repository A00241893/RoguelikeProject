#include <windows.h>
#include <iostream>
#include <string>

const int LEVELWIDTH = 20;
const int LEVELHEIGHT = 10;

unsigned int playerPositionX = 5;
unsigned int playerPositionY = 5;
unsigned int newPlayerPositionX = playerPositionX;
unsigned int newPlayerPositionY = playerPositionY;

unsigned int health = 0;

char playerChar = 'P';


char map[LEVELHEIGHT][LEVELWIDTH + 1] =
{ "aaaaaaaaaaaaaaaaaaaa",
"a         +        a",
"a                  a",
"a                  a",
"a                  a",
"a               +  a",
"a                  a",
"a     +            a",
"a          +       a",
"aaaaaaaaaaaaaaaaaaaa"
};

void gotoScreenPosition(short C, short R)
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
}

void renderMap()
{
	for (int i = 0; i<LEVELHEIGHT; i++)
	{
		std::cout << map[i] << std::endl;
	}
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
}

void renderPlayer()
{
	// Blank old enemy position
	gotoScreenPosition(playerPositionX, playerPositionY);
	std::cout << ' ';

	// Draw new enemy position
	gotoScreenPosition(newPlayerPositionX, newPlayerPositionY);
	std::cout << playerChar;

	playerPositionX = newPlayerPositionX;
	playerPositionY = newPlayerPositionY;

	Sleep(60);
}

void renderGUI()
{
	gotoScreenPosition(2, LEVELHEIGHT + 3);
	std::cout << "Health: " << health;
}

void main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, 800, 800, TRUE);

	renderMap();

	while (true)
	{
		// Handles the input and updates the players position
		handleInput();

		// Handle collisions
		handleCollisions();

		// Render the scene
		renderPlayer();

		// Render the GUI
		renderGUI();
	}

	system("pause");
}