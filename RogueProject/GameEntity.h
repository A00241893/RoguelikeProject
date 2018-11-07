#ifndef GAMEENTITY_H
#define GAMEENTITY_H

class GameEntity
{
public:
	GameEntity();
	GameEntity(char s);
	void setSymbol(char s);
	char getSymbol() const;

private:

	char symbol;
};

#endif // GAMEENTITY_H