#include "GameEntity.h"

GameEntity::GameEntity() {}

GameEntity::GameEntity(int x, int y, int newX, int newY, char s, int h)
	:Position(x, y, newX, newY)
{
	health = h;
	symbol = s;
}

void GameEntity::setHealth(int h)
{
	health = h;
}
int GameEntity::getHealth() const
{
	return health;
}

void GameEntity::setSymbol(char s)
{
	symbol = s;
}
char GameEntity::getSymbol() const
{
	return symbol;
}


