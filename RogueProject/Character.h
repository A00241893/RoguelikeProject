#pragma once
#include "Position.h"

class Character : public Position
{
public:
	Character();
	Character(Position pos, char s, int h, int d);
	void setHealth(int h);
	int getHealth() const;
	void setDamage(int h);
	int getDamage() const;
	void setSymbol(char s);
	char getSymbol() const;

	Position& getPosition() { return pos; }

private:

	Position pos;
	int damage;
	int health;
	char symbol;
};