#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>
#include "Map.h"
#include "Actor.h"
#include "Utils.h"

class Player : public Actor
{
public:
	Player();
	Player(int x, int y, int newX, int newY, char symbol, int health, int armour, int dam);

	void setArmour(int a);
	int getArmour() const;

	bool dropItem(char drop, Map& gameMap, Player& p);
	void renderActor(Player& p);
	void renderInventory();
	void addToInventory(std::string n);
	void removeFromInventory(Map& gameMap, Player& p);
	void handleCollisions(Map& gameMap, Player& p);

	std::vector<std::string> inventory;
private:
	int health;
	int armour;
	int damage;
};

#endif // PLAYER_H