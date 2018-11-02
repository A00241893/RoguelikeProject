#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	Weapon(char s, std::string n, int d);
	void setDamage(int d);
	int getDamage() const;
	void useWeapon(Player& p, int amount);

private:
	int damage;
};

#endif // WEAPON_H