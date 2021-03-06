#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Player.h"

class Item : public GameEntity
{
public:
	Item();
	Item(char symbol, std::string name);

	void setItemName(std::string n);
	std::string getItemName() const;

	virtual void useItem(Player& p) const;

private:
	std::string name;
};

#endif // ITEM_H