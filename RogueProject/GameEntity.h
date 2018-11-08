#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "Position.h"

class GameEntity : public Position
{
public:
	GameEntity();
	GameEntity(int x, int y, int newX, int newY, char s);
	void setSymbol(char s);
	char getSymbol() const;

private:

	char symbol;
};

#endif // GAMEENTITY_H