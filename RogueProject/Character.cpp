#include "Character.h"

Character::Character() {}

Character::Character(Position pos, char s, int h)
{
	health = h;
	symbol = s;
	pos = Position(0, 0, 0, 0);
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


