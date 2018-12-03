#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include "Map.h"
#include "Player.h"
#include "Actor.h"
#include "Utils.h"

class Enemy : public Actor
{
public:
	Enemy();
	Enemy(int x, int y, int newX, int newY, char symbol, int health, int dam, std::string name);

	void renderActor(Enemy& e);
	void enemyCollisions(Enemy& e, Map& gameMap, double distance);
	bool enemyState(Player& p, Map& gameMap, Enemy& e);
	void evade(Player& p, Enemy& e);
	void chase(Player& p, Enemy& e);

private:
	int health;
	int damage;
};

#endif // ENEMY_H