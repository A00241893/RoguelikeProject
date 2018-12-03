#include "Actor.h"

Actor::Actor()
{
	health = 0;
	damage = 0;
}

Actor::Actor(int x, int y, int newX, int newY, char s, int h, int d)
	:GameEntity(x, y, newX, newY, s)
{
	health = h;
	damage = d;
}

void Actor::setHealth(int h)
{
	health = h;
}
int Actor::getHealth() const
{
	return health;
}
void Actor::setDamage(int d)
{
	damage = d;
}
int Actor::getDamage() const
{
	return damage;
}


