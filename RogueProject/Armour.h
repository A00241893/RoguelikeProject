#ifndef ARMOUR_H
#define ARMOUR_H
#include "Item.h"

class Armour : public Item
{
public:
	Armour();
	Armour(int x, int y, int newX, int newY, char symbol, std::string name, int armour);
	void setArmour(int a);
	int getArmour() const;

	//void useItem(Player& p);

private:
	int armour;
};

#endif // ARMOUR_H