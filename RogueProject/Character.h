#pragma once
#include "Position.h"

class Character : public Position
{
public:
	Character();
	Character(int xPos, int yPos, int newXPos, int newYPos, int h, char s);
	void setHealth(int h);
	int getHealth() const;
	void setSymbol(char s);
	char getSymbol() const;

private:

	int health;
	char symbol;
};