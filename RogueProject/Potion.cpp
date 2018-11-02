#include "Potion.h"

Potion::Potion(){}

Potion::Potion(char s, std::string n)
	: Item(s, n){}

void Potion::usePotion(Player& p) 
{
	p.setHealth(p.getHealth() + 20); //adds 20 to the players health when potion is used.

	if (p.getHealth() > 100) //if health goes over 100 then health is set to 100
	{
		p.setHealth(100);
	}
}