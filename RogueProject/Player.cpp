#include "Player.h"

Player::Player()
{
	armour = 0;
}

Player::Player(int x, int y, int newX, int newY, char symbol, int h, int arm, int dam)
	:Actor(x, y, newX, newY, symbol, h, dam)
{
	armour = arm;
}

void Player::setArmour(int a)
{
	armour = a;
}
int Player::getArmour() const
{
	return armour;
}

void Player::renderActor(Player& p)
{
	// Blank old player position
	Utils::gotoXY(p.getPositionX(), p.getPositionY());
	std::cout << '.';

	// Draw new player position
	Utils::gotoXY(p.getNewPositionX(), p.getNewPositionY());
	std::cout << p.getSymbol();

	p.setPositionX(p.getNewPositionX());
	p.setPositionY(p.getNewPositionY());

	Sleep(60);
}

bool Player::dropItem(char drop, Map& gameMap, Player& p)
{
	/**checks if the spaces around the player is empty.
	if it is empty it prints the item's symbol to be dropped in that space
	**/
	if (gameMap.getXY(p.getNewPositionY(), p.getNewPositionX() - 1) == '.')
	{
		gameMap.setXY(p.getNewPositionY(), p.getNewPositionX() - 1, drop);
		return true;
	}
	else if (gameMap.getXY(p.getNewPositionY(), p.getNewPositionX() + 1) == '.')
	{
		gameMap.setXY(p.getNewPositionY(), p.getNewPositionX() + 1, drop);
		return true;
	}
	else if (gameMap.getXY(p.getNewPositionY() + 1, p.getNewPositionX()) == '.')
	{
		gameMap.setXY(p.getNewPositionY() + 1, p.getNewPositionX(), drop);
		return true;
	}
	else if (gameMap.getXY(p.getNewPositionY() - 1, p.getNewPositionX()) == '.')
	{
		gameMap.setXY(p.getNewPositionY() - 1, p.getNewPositionX(), drop);
		return true;
	}
	else
	{
		return false;
	}
}

void Player::renderInventory()
{
	Utils::clearScene();
	std::cout << "Inventory:" << std::endl;
	std::cout << "--------------------" << std::endl;
	for (int i = 0; i < inventory.size(); i++)		//prints out the vector of inventory items
	{
		std::cout << i << ": " << inventory[i] << std::endl;
	}
	std::cout << "--------------------" << std::endl;
}

void Player::addToInventory(std::string n)
{
	inventory.push_back(n); //adds item to the inventory
}

void Player::removeFromInventory(Map& gameMap, Player& p)
{
	int itemToDrop;
	Utils::printMsg(0, 18, "select the number you want to drop:");
	std::cin >> itemToDrop;
	if (itemToDrop >= 0 && itemToDrop <= inventory.size()) //if valid number is entered and something is in the inventory
	{
		//prints item symbol back onto map
		if (p.dropItem(inventory[itemToDrop].at(0), gameMap, p) == true)
		{
			//removes item from inventory
			inventory.erase(inventory.begin() + itemToDrop);
			p.renderInventory();
		}
		else {
			p.renderInventory();
			Utils::printMsg(0, 17, "no space to drop item!!");
		}
	}
	else {
		Utils::printMsg(0, 17, "enter valid input!!");
	}
}

void Player::handleCollisions(Map& gameMap, Player& p)
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
	if (nextLocation == 'H')
	{
		p.addToInventory("Health"); //adds potion to the inventory
		gameMap.setXY(p.getNewPositionY(), p.getNewPositionX(), '.'); // Remove it from the map
	}
	if (nextLocation == 'S')
	{
		p.addToInventory("Sword"); //adds sword to the inventory
		gameMap.setXY(p.getNewPositionY(), p.getNewPositionX(), '.'); // Remove it from the map
	}
	if (nextLocation == 'M')
	{
		p.addToInventory("Mace"); //adds mace to the inventory
		gameMap.setXY(p.getNewPositionY(), p.getNewPositionX(), '.'); // Remove it from the map
	}
	if (nextLocation == 'I')
	{
		p.addToInventory("Iron"); //adds iron armour to the inventory
		gameMap.setXY(p.getNewPositionY(), p.getNewPositionX(), '.'); // Remove it from the map
	}
	if (nextLocation == 'L')
	{
		p.addToInventory("Leather"); //adds leather armour to the inventory
		gameMap.setXY(p.getNewPositionY(), p.getNewPositionX(), '.'); // Remove it from the map
	}
	//for (int i = 0; i < 5; i++)
	//{
	//	if (nextLocation == itemPtr[i]->getSymbol()) //if the player collides with an item.
	//	{
	//		p->addToInventory(itemPtr[i]->getItemName()); //adds item to the inventory

	//		// Remove it from the map
	//		gameMap->setXY(p->getNewPositionY(), p->getNewPositionX(), '.');
	//	}
	//}
}
