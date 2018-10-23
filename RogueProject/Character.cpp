#include "Character.h"

Character::Character() {}

Character::Character(int x, int y, int newX, int newY, char s, int h)
	:Position(x, y, newX, newY)
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


