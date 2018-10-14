#include "Character.h"

Character::Character()
{
	health = 0;
	symbol = ' ';
}

Character::Character(int xPos, int yPos, int newXPos, int newYPos, int h, char s)
	:Position(xPos, yPos, newXPos, newYPos)
{
	health = h;
	symbol = s;
}

void Character::setHealth(int h)
{
	health = h;
}
int Character::getHealth() const
{
	return health;
}

void Character::setSymbol(char s)
{
	symbol = s;
}
char Character::getSymbol() const
{
	return symbol;
}