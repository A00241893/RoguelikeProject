#include "Utils.h"

void Utils::gotoXY(short C, short R)
{
	COORD xy;
	xy.X = C;
	xy.Y = R;
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void Utils::clearScene()
{
	Utils::gotoXY(0, 0);

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
	Utils::gotoXY(0, 0);
}

void Utils::renderMap(int lHeight, char* map[])
{
	Utils::clearScene(); //blanks out the screen
	for (int i = 0; i < lHeight; i++)  //prints out the map
	{
		std::cout << map[i] << std::endl;
	}

	Utils::gotoXY(0, 18);
	std::cout << "Press I to go to the Inventory" << std::endl;
}

void Utils::renderGUI(Player& p, int lHeight)
{
	Utils::gotoXY(2, lHeight + 3);
	std::cout << "Health: " << p.getHealth();
}