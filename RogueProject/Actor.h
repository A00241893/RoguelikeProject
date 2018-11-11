#ifndef ACTOR_H
#define ACTOR_H

#include "GameEntity.h"

class Actor : public GameEntity
{
public:
	Actor();
	Actor(int xPos, int yPos, int newXPos, int newYPos, char symbol);
	void setNewPositionX(int x);
	void setNewPositionY(int y);
	int getNewPositionX() const;
	int getNewPositionY() const;

private:
	int newXPos;
	int newYPos;
};

#endif // ACTOR_H