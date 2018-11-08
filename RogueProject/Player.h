#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>
#include "Map.h"
#include "GameEntity.h"

#include "Utils.h"

class Player : public GameEntity
{
public:
	Player();
	Player(int x, int y, int newX, int newY, char symbol, int health, int armour, int dam);

	void setHealth(int h);
	int getHealth() const;
	void setDamage(int d);
	int getDamage() const;
	void setArmour(int a);
	int getArmour() const;

	bool dropItem(char drop, Map& gameMap, Player & p);
	void renderPlayer(Player & p);

private:
	int health;
	int armour;
	int damage;

};

#endif // PLAYER_H