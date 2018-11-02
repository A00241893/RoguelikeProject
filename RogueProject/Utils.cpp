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

void Utils::renderGUI(Player& p)
{
	/** prints the GUI under the map
	**/
	Utils::gotoXY(2, 12);
	std::cout << "Health: " << p.getHealth();
	Utils::gotoXY(2, 13);
	std::cout << "Armour: " << p.getArmour();
	Utils::gotoXY(2, 14);
	std::cout << "Damage: " << p.getDamage();

	Utils::gotoXY(0, 18);
	std::cout << "Press I to go to the Inventory" << std::endl;
}

void Utils::printInventory(std::vector<Item>& inv)
{
	Utils::clearScene();
	std::cout << "Inventory:" << std::endl;
	std::cout << "--------------------" << std::endl;
	for (int i = 0; i < inv.size(); i++)		//prints out the vector of inventory items
	{
		std::cout << i << ": " << inv[i].getItemName() << std::endl;
	}
	std::cout << "--------------------" << std::endl;
}
