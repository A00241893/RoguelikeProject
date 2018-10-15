#pragma once
#include "Position.h"

class Player : public Position
{
public:
	Player();
	Player(int xPos, int yPos, int newXPos, int newYPos, int h, char s);
	void setHealth(int h);
	int getHealth() const;
	void setSymbol(char s);
	char getSymbol() const;

	void dropItem(char drop, char * map[], Player & p);
	void renderPlayer(Player & p);

private:

	int health;
	char symbol;
};