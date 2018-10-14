#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player();
	Player(int xPos, int yPos, int newXPos, int newYPos, int h, char s);
	void renderPlayer();

private:

};