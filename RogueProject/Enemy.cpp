#include "Enemy.h"


Enemy::Enemy() {}

Enemy::Enemy(int x, int y, int newX, int newY, char symbol, int h,  int dam, std::string name)
	:Actor(x, y, newX, newY, symbol, h, dam){}


void Enemy::renderActor(Enemy& e)
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
		e.renderActor(e);
	}
	else if (nextLocation == 'a')
	{
		// ....then don't move i.e. set the new position back to the old position
		e.setNewPositionX(e.getPositionX());
		e.setNewPositionY(e.getPositionY());
	}
	else if (nextLocation == 'P')
	{
		// ....then don't move i.e. set the new position back to the old position
		e.setNewPositionX(e.getPositionX());
		e.setNewPositionY(e.getPositionY());
	}
}

bool Enemy::enemyState(Player& p, Map& gameMap, Enemy& e)
{
	e.setNewPositionX(e.getPositionX());
	e.setNewPositionY(e.getPositionY());

	int x1 = p.getNewPositionX();
	int y1 = p.getNewPositionY();
	int x2 = e.getPositionX();
	int y2 = e.getPositionY();

	double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1);

	if (distance <= 1)
	{
		return true; //when player and enemy attack each other
	}
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

void Enemy::chase(Player& p, Enemy& e) //enemy moves towards the player
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

void Enemy::evade(Player& p, Enemy& e) //enemy moves away from the player
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

