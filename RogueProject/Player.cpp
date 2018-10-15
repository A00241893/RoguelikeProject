#include "Player.h"
#include "Utils.h"
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

void Player::dropItem(char drop, char* map[], Player& p)
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

void Player::renderPlayer(Player& p)
{
	// Blank old enemy position
	Utils::gotoXY(p.getPositionX(), p.getPositionY());
	std::cout << ' ';

	// Draw new enemy position
	Utils::gotoXY(p.getNewPositionX(), p.getNewPositionY());
	std::cout << p.getSymbol();

	p.setNewPositionX(p.getPositionX());
	p.setNewPositionY(p.getPositionY());

	Sleep(60);
}


