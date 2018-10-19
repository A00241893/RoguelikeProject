#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player();
	Player(Position pos, char s, int h, int d);

	void dropItem(char drop, char * map[], Player & p);
	void renderPlayer(Player & p);

};