#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Item.h"
#include <vector>

class Player : public Character
{
public:
	Player();
	Player(Position pos, char s, int h);

	void dropItem(char drop, char * map[], Player & p);
	void renderPlayer(Player & p);
	void renderInventory(std::vector<Item>& inv);

};

#endif // PLAYER_H