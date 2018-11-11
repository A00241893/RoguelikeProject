#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include "Map.h"
#include "Actor.h"
#include "Utils.h"

class Enemy : public Actor
{
public:
	Enemy();
	Enemy(int x, int y, int newX, int newY, char symbol, int health, int dam, std::string name);

	void setHealth(int h);
	int getHealth() const;
	void setDamage(int d);
	int getDamage() const;

private:
	int health;
	int damage;

};

#endif // ENEMY_H