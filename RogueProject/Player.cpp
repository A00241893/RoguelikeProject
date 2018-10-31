#include "Player.h"
#include "Utils.h"


Player::Player(){}

Player::Player(int x, int y, int newX, int newY, char s, int h)
	:Character(x, y, newX, newY, s, h)
{}

void Player::dropItem(char drop, Map gameMap, Player& p)
{
	/**checks if the spaces around the player is empty.
	if it is empty it prints the item's symbol to be dropped in that space
	**/
	if (gameMap.getXY(p.getNewPositionY(), p.getNewPositionX() - 1) == ' ')
	{
		gameMap.setXY(p.getNewPositionY(), p.getNewPositionX() - 1, drop);
	}
	else if (gameMap.getXY(p.getNewPositionY(), p.getNewPositionX() + 1) == ' ')
	{
		gameMap.setXY(p.getNewPositionY(), p.getNewPositionX() + 1, drop);
	}
	else if (gameMap.getXY(p.getNewPositionY() + 1, p.getNewPositionX()) == ' ')
	{
		gameMap.setXY(p.getNewPositionY() + 1, p.getNewPositionX(), drop);
	}
	else if (gameMap.getXY(p.getNewPositionY() - 1, p.getNewPositionX()) == ' ')
	{
		gameMap.setXY(p.getNewPositionY() - 1, p.getNewPositionX(), drop);
	}
	else
	{
		std::cout << "There is no space to drop items" << std::endl;
	}
}

void Player::renderPlayer(Player& p)
{
	// Blank old player position
	Utils::gotoXY(p.getPositionX(), p.getPositionY());
	std::cout << ' ';

	// Draw new player position
	Utils::gotoXY(p.getNewPositionX(), p.getNewPositionY());
	std::cout << p.getSymbol();

	p.setPositionX(p.getNewPositionX());
	p.setPositionY(p.getNewPositionY());

	Sleep(60);
}

void Player::renderInventory(std::vector<Item>& inventory)
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


