#ifndef GAMEENTITY_H
#define GAMEENTITY_H

class GameEntity
{
public:
	GameEntity();
	GameEntity(int x, int y, int newX, int newY, char s);

	void setPositionX(int x);
	void setPositionY(int y);
	int getPositionX() const;
	int getPositionY() const;
	void setNewPositionX(int x);
	void setNewPositionY(int y);
	int getNewPositionX() const;
	int getNewPositionY() const;
	void setSymbol(char s);
	char getSymbol() const;

private:
	int xPos;
	int yPos;
	int newXPos;
	int newYPos;
	char symbol;
};

#endif // GAMEENTITY_H