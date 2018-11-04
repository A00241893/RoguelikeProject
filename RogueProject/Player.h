#ifndef PLAYER_H
#define PLAYER_H
#include "GameEntity.h"
#include "Item.h"
#include "Map.h"
#include <vector>

class Player : public GameEntity
{
public:
	Player();
	Player(int x, int y, int newX, int newY, char sym, int health, int arm, int dam);

	void setDamage(int h);
	int getDamage() const;
	void setArmour(int a);
	int getArmour() const;

	bool dropItem(char drop, Map gameMap, Player & p);
	void renderPlayer(Player & p);
	void handleCollisions(Player& p, Item* ptr[5], Map& gameMap, std::vector<Item>& inv);

private:
	int armour;
	int damage;

};

#endif // PLAYER_H