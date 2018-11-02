#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Map.h"
#include <vector>

class Player : public Character
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

private:
	int armour;
	int damage;

};

#endif // PLAYER_H