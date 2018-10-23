#include "Utils.h"

void Utils::gotoXY(short C, short R)
{
	/** sets the cursor position
	**/
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

void Utils::renderMap(int lHeight, int lWidth, char* m[])
{
	Utils::clearScene(); //blanks out the screen
	
	/** prints the map out to the scene
	**/
	for (int i = 0; i < lHeight; i++)
	{
		for (int j = 0; j < lWidth; j++)
		{
			std::cout << m[i][j];
		}
		std::cout << std::endl;
	}
}

void Utils::renderGUI(Player& p)
{
	/** prints the GUI under the map
	**/
	Utils::gotoXY(2, 13);
	std::cout << "Health: " << p.getHealth();

	Utils::gotoXY(0, 18);
	std::cout << "Press I to go to the Inventory" << std::endl;
}