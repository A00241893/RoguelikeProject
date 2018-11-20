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

void Enemy::enemyCollisions(Enemy& e, Map& gameMap, double distance) 
{
	// Check the location that the player wants to move to on the map
	char nextLocation = gameMap.getXY(e.getNewPositionY(), e.getNewPositionX());

	// If the nextLocation is empty....
	if (distance > 1 && nextLocation == '.')
	{
		e.renderEnemy(e);
	}
	else
	{
		// ....then don't move i.e. set the new position back to the old position
		e.setNewPositionX(e.getPositionX());
		e.setNewPositionY(e.getPositionY());
	}
}

void Enemy::enemyState(Player& p, Map& gameMap, Enemy& e)
{
	e.setNewPositionX(e.getPositionX());
	e.setNewPositionY(e.getPositionY());

	int x1 = p.getNewPositionX();
	int y1 = p.getNewPositionY();
	int x2 = e.getPositionX();
	int y2 = e.getPositionY();

	double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1);

	if (distance < 4 && p.getHealth() < e.getHealth())
	{
		chase(p, e);
		enemyCollisions(e, gameMap, distance);
	}
	else if (distance < 4 && p.getHealth() > e.getHealth())
	{
		evade(p, e);
		enemyCollisions(e, gameMap, distance);
	}
	else if (p.getHealth() == e.getHealth()){}
}

void Enemy::chase(Player& p, Enemy& e)
{
	if (e.getPositionX() > p.getNewPositionX())
	{
		e.setNewPositionX(e.getPositionX() - 1);
	}
	else if (e.getPositionX() < p.getNewPositionX())
	{
		e.setNewPositionX(e.getPositionX() + 1);
	}

	if (e.getPositionY() > p.getNewPositionY())
	{
		e.setNewPositionY(e.getPositionY() - 1);
	}
	else if (e.getPositionY() < p.getNewPositionY())
	{
		e.setNewPositionY(e.getPositionY() + 1);
	}
}

void Enemy::evade(Player& p, Enemy& e)
{
	if (e.getPositionX() < p.getNewPositionX())
	{
		e.setNewPositionX(e.getPositionX() - 1);
	}
	else if (e.getPositionX() > p.getNewPositionX())
	{
		e.setNewPositionX(e.getPositionX() + 1);
	}

	if (e.getPositionY() < p.getNewPositionY())
	{
		e.setNewPositionY(e.getPositionY() - 1);
	}
	else if (e.getPositionY() > p.getNewPositionY())
	{
		e.setNewPositionY(e.getPositionY() + 1);
	}
}

