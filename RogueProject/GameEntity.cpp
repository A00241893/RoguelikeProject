#include "GameEntity.h"

GameEntity::GameEntity() {}

GameEntity::GameEntity(char s)
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


