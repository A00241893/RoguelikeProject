#include "GameEntity.h"

GameEntity::GameEntity() 
{
	xPos = 0;
	yPos = 0;
	newXPos = 0;
	newYPos = 0;
	symbol = ' ';
}

GameEntity::GameEntity(int x, int y, int newX, int newY, char s)
{
	xPos = x;
	yPos = y;
	newXPos = newX;
	newYPos = newY;
	symbol = s;
}

void GameEntity::setPositionX(int x)
{
	xPos = x;
}
void GameEntity::setPositionY(int y)
{
	yPos = y;
}
int GameEntity::getPositionX() const
{
	return xPos;
}
int GameEntity::getPositionY() const
{
	return yPos;
}
void GameEntity::setNewPositionX(int x)
{
	newXPos = x;
}
void GameEntity::setNewPositionY(int y)
{
	newYPos = y;
}
int GameEntity::getNewPositionX() const
{
	return newXPos;
}
int GameEntity::getNewPositionY() const
{
	return newYPos;
}
void GameEntity::setSymbol(char s)
{
	symbol = s;
}
char GameEntity::getSymbol() const
{
	return symbol;
}


