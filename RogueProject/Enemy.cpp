#include "Enemy.h"


Enemy::Enemy() {}

Enemy::Enemy(int x, int y, int newX, int newY, char symbol, int h,  int dam, std::string name)
	:Actor(x, y, newX, newY, symbol)
{
	health = h;
	damage = dam;
}

void Enemy::setHealth(int h)
{
	health = h;
}
int Enemy::getHealth() const
{
	return health;
}
void Enemy::setDamage(int d)
{
	damage = d;
}
int Enemy::getDamage() const
{
	return damage;
}

