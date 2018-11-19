#ifndef MAP_H
#define MAP_H

#include <iostream>

class Map
{
public:
	Map();
	~Map();
	int getWidth();
	void setWidth(int w);
	int getHeight();
	void setHeight(int h);
	char getXY(int i, int j);
	void setXY(int i, int j, char value);
	void loadMap(std::string path);
	void printMap();


private:
	char *map;
	int mapWidth;
	int mapHeight;
};

#endif // MAP_H