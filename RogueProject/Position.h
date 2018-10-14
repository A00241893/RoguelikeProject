#pragma once

class Position
{
public:
	Position();
	Position(int xPos, int yPos, int newXPos, int newYPos);
	void setPositionX(int x);
	void setPositionY(int y);
	void setNewPositionX(int x);
	void setNewPositionY(int y);
	int getPositionX() const;
	int getPositionY() const;
	int getNewPositionX() const;
	int getNewPositionY() const;

private:
	int xPos;
	int yPos;
	int newXPos;
	int newYPos;
};
