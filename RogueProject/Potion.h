#ifndef POTION_H
#define POTION_H
#include <string>
#include "Item.h"

class Potion : public Item
{
public:
	Potion();
	Potion(int x, int y, char symbol, std::string name, int h);
	void setPotion(int h);
	int getPotion() const;

	void useItem(Player& p) const;

private:
	int pHealth;
};

#endif // POTION_H