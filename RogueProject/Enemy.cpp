#include "Enemy.h"


Enemy::Enemy() {}

Enemy::Enemy(int x, int y, int newX, int newY, char symbol, int h,  int dam, std::string name)
	:GameEntity(x, y, newX, newY, symbol)
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

void Enemy::renderEnemy(Enemy& e)
{
	// Blank old player position
	Utils::gotoXY(e.getPositionX(), e.getPositionY());
	std::cout << '.';

	// Draw new player position
	Utils::gotoXY(e.getNewPositionX(), e.getNewPositionY());
	std::cout << e.getSymbol();

	e.setPositionX(e.getNewPositionX());
	e.setPositionY(e.getNewPositionY());

	Sleep(60);
}

