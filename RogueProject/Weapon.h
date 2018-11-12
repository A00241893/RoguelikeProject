#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	Weapon(int x, int y, char s, std::string n, int d);
	void setDamage(int d);
	int getDamage() const;

	void useItem(Player& p) const;

private:
	int damage;
};

#endif // WEAPON_H