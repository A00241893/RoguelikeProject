#ifndef ACTOR_H
#define ACTOR_H

#include "GameEntity.h"

class Actor : public GameEntity
{
public:
	Actor();
	Actor(int x, int y, int newX, int newY, char s, int h, int d);

	void setHealth(int h);
	int getHealth() const;
	void setDamage(int d);
	int getDamage() const;

private:
	int health;
	int damage;
};

#endif // ACTOR_H