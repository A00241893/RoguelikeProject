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

void Utils::handleCollisions(Player& p, Item* ptr[5], Map& gameMap, std::vector<Item>& inv)
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
	for (int i = 0; i < 5; i++)
	{
		if (nextLocation == ptr[i]->getItemSymbol()) //if the player collides with an item.
		{
			inv.push_back(*ptr[i]); //adds item to the inventory

									// Remove it from the map
			gameMap.setXY(p.getNewPositionY(), p.getNewPositionX(), ' ');
		}
	}
}


