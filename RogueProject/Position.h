#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
	Position();
	Position(int xPos, int yPos);
	void setPositionX(int x);
	void setPositionY(int y);
	int getPositionX() const;
	int getPositionY() const;

private:
	int xPos;
	int yPos;
};

#endif // POSITION_H