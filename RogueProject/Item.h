#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item
{
public:
	Item();
	Item(char itemSymbol, std::string name);
	void setItemSymbol(int s);
	int getItemSymbol();
	void setItemName(std::string n);
	std::string getItemName();

private:
	char itemSymbol;
	std::string name;
};

#endif // ITEM_H