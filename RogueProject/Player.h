#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Item.h"
#include <vector>

class Player : public Character
{
public:
	Player();
	Player(int x, int y, int newX, int newY, char s, int h);

	void dropItem(char drop, char* map[], Player & p);
	void renderPlayer(Player & p);
	void renderInventory(std::vector<Item>& inv);

};

#endif // PLAYER_H