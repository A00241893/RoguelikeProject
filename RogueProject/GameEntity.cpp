#include "GameEntity.h"

GameEntity::GameEntity() {}

GameEntity::GameEntity(int x, int y, char s)
	:Position(x, y)
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


