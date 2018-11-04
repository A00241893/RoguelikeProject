#ifndef POTION_H
#define POTION_H
#include <string>
#include "Item.h"

class Potion : public Item
{
public:
	Potion();
	Potion(char symbol, std::string name, int health);
	void setHealth(int h);
	int getHealth() const;

	void useItem(Player& p);

private:
	int health;
};

#endif // POTION_H