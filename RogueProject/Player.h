#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Item.h"
#include "Map.h"
#include <vector>

class Player : public Character
{
public:
	Player();
	Player(int x, int y, int newX, int newY, char s, int h);

	void dropItem(char drop, Map gameMap, Player & p);
	void renderPlayer(Player & p);
	void renderInventory(std::vector<Item>& inv);

};

#endif // PLAYER_H