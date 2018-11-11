#include "Position.h"

Position::Position()
{
	xPos = 0;
	yPos = 0;
}

Position::Position(int x, int y)
{
	xPos = x;
	yPos = y;
}

void Position::setPositionX(int x)
{
	xPos = x;
}
void Position::setPositionY(int y)
{
	yPos = y;
}
int Position::getPositionX() const
{
	return xPos;
}
int Position::getPositionY() const
{
	return yPos;
}