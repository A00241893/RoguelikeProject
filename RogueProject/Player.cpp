#include "Player.h"


Player::Player(){}

Player::Player(int x, int y, int newX, int newY, char s, int h, int arm, int dam)
	:GameEntity(x, y, newX, newY, s, h)
{
	armour = arm;
	damage = dam;
}

void Player::setDamage(int d)
{
	damage = d;
}
int Player::getDamage() const
{
	return damage;
}
void Player::setArmour(int a)
{
	armour = a;
}
int Player::getArmour() const
{
	return armour;
}

bool Player::dropItem(char drop, Map gameMap, Player& p)
{
	/**checks if the spaces around the player is empty.
	if it is empty it prints the item's symbol to be dropped in that space
	**/
	if (gameMap.getXY(p.getNewPositionY(), p.getNewPositionX() - 1) == ' ')
	{
		gameMap.setXY(p.getNewPositionY(), p.getNewPositionX() - 1, drop);
		return true;
	}
	else if (gameMap.getXY(p.getNewPositionY(), p.getNewPositionX() + 1) == ' ')
	{
		gameMap.setXY(p.getNewPositionY(), p.getNewPositionX() + 1, drop);
		return true;
	}
	else if (gameMap.getXY(p.getNewPositionY() + 1, p.getNewPositionX()) == ' ')
	{
		gameMap.setXY(p.getNewPositionY() + 1, p.getNewPositionX(), drop);
		return true;
	}
	else if (gameMap.getXY(p.getNewPositionY() - 1, p.getNewPositionX()) == ' ')
	{
		gameMap.setXY(p.getNewPositionY() - 1, p.getNewPositionX(), drop);
		return true;
	}
	else
	{
		return false;
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

void Player::handleCollisions(Player& p, Item* ptr[5], Map& gameMap, std::vector<Item>& inv)
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

