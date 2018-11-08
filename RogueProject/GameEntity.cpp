#include "GameEntity.h"

GameEntity::GameEntity() {}

GameEntity::GameEntity(int x, int y, int newX, int newY, char s)
	:Position(x, y, newX, newY)
{
	symbol = s;
}

void GameEntity::setSymbol(char s)
{
	symbol = s;
}
char GameEntity::getSymbol() const
{
	return symbol;
}


