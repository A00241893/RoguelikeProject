#include "Player.h"


Player::Player(){}

Player::Player(int x, int y, int newX, int newY, char symbol, int h, int arm, int dam)
	:GameEntity(x, y, newX, newY, symbol)
{
	health = h;
	armour = arm;
	damage = dam;
}

void Player::setHealth(int h)
{
	health = h;
}
int Player::getHealth() const
{
	return health;
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

