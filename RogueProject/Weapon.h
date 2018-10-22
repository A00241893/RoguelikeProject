#ifndef WEAPONS_H
#define WEAPONS_H
#include <string>
#include "Item.h"

class Weapon : Item
{
public:
	Weapon();
	Weapon(char symbol, std::string name, int damage);
	void setDamage(int h);
	int getDamage() const;

private:
	int damage;
};

#endif // WEAPONS_H