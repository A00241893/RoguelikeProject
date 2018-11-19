#include "Potion.h"

Potion::Potion(){
	pHealth = 0;
}

Potion::Potion(char s, std::string n, int h)
	: Item(s, n){}

void Potion::setPotion(int h)
{
	pHealth = h;
}
int Potion::getPotion() const
{
	return pHealth;
}

void Potion::useItem(Player& p) const
{
	p.setHealth(p.getHealth() + 20);
	if (p.getHealth() > 100)
	{
		p.setHealth(100);
	}
	else {}
}
