#ifndef GAMEENTITY_H
#define GAMEENTITY_H
#include "Position.h"

class GameEntity : public Position
{
public:
	GameEntity();
	GameEntity(int x, int y, int newX, int newY, char s, int h);
	void setHealth(int h);
	int getHealth() const;
	void setSymbol(char s);
	char getSymbol() const;

	Position& getPosition() { return pos; }

private:

	Position pos;
	int health;
	char symbol;
};

#endif // GAMEENTITY_H