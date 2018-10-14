#include "Position.h"

Position::Position()
{
	xPos = 0;
	yPos = 0;
	newXPos = 0;
	newYPos = 0;
}

Position::Position(int x, int y, int newX, int newY)
{
	xPos = x;
	yPos = y;
	newXPos = newX;
	newYPos = newY;
}

void Position::setPositionX(int x)
{
	xPos = x;
}
void Position::setPositionY(int y)
{
	yPos = y;
}
void Position::setNewPositionX(int x)
{
	newXPos = x;
}
void Position::setNewPositionY(int y)
{
	newYPos = y;
}
int Position::getPositionX() const
{
	return xPos;
}
int Position::getPositionY() const
{
	return yPos;
}
int Position::getNewPositionX() const
{
	return newXPos;
}
int Position::getNewPositionY() const
{
	return newYPos;
}