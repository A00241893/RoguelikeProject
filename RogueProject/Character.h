#ifndef CHARACTER_H
#define CHARACTER_H
#include "Position.h"

class Character : public Position
{
public:
	Character();
	Character(int x, int y, int newX, int newY, char s, int h);
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

#endif // CHARACTER_H