#pragma once
#include <string>

class Item
{
public:
	Item();
	Item(char symbol, std::string name);
	void setItemSymbol(int s);
	int getItemSymbol();
	void setItemName(std::string n);
	std::string getItemName();

private:
	char symbol;
	std::string name;
};



class Utils
{
public:
	static void gotoXY(short C, short R);

};