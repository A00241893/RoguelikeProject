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

void Utils::printMsg(int x, int y, std::string msg)
{
	Utils::gotoXY(x, y); //goes to where message should be printed.
	for (int j = 0; j < 100; j++) //clears previous message
	{
		std::cout << ' ';
	}
	Utils::gotoXY(x, y); //goes to where message should be printed
	std::cout << msg << std::endl; //prints new message
}


