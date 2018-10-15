#include "Player.h"
#include <iostream>

Player::Player(){}

Player::Player(int xPos, int yPos, int newXPos, int newYPos, int h, char s)
	:Position(xPos, yPos, newXPos, newYPos)
{
	health = h;
	symbol = s;
}

void Player::setHealth(int h)
{
	health = h;
}
int Player::getHealth() const
{
	return health;
}

void Player::setSymbol(char s)
{
	symbol = s;
}
char Player::getSymbol() const
{
	return symbol;
}

void dropItem(char drop, char* map[], Player& p)
{
	/**checks if the spaces around the player is empty.
	if it is empty it prints the item to be dropped symbol in that space
	**/
	if (map[p.getNewPositionY()][p.getNewPositionX() - 1] == ' ')
	{
		map[p.getNewPositionY()][p.getNewPositionX() - 1] = drop;
	}
	else if (map[p.getNewPositionY()][p.getNewPositionX() + 1] == ' ')
	{
		map[p.getNewPositionY()][p.getNewPositionX() + 1] = drop;
	}
	else if (map[p.getNewPositionY() + 1][p.getNewPositionX()] == ' ')
	{
		map[p.getNewPositionY() + 1][p.getNewPositionX()] = drop;
	}
	else if (map[p.getNewPositionY() - 1][p.getNewPositionX()] == ' ')
	{
		map[p.getNewPositionY() - 1][p.getNewPositionX()] = drop;
	}
	else
	{
		std::cout << "There is no space to drop items" << std::endl;
	}
}


