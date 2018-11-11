#include "Actor.h"

Actor::Actor()
{
	newXPos = 0;
	newYPos = 0;
}

Actor::Actor(int x, int y, int newX, int newY, char symbol)
	:GameEntity(x, y, symbol)
{
	newXPos = newX;
	newYPos = newY;
}

void Actor::setNewPositionX(int x)
{
	newXPos = x;
}
void Actor::setNewPositionY(int y)
{
	newYPos = y;
}
int Actor::getNewPositionX() const
{
	return newXPos;
}
int Actor::getNewPositionY() const
{
	return newYPos;
}