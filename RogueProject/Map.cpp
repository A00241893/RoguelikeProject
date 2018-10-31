#include "Map.h"

Map::Map(char *map, int w, int h)
{
	map = NULL;
	w = 0;
	h = 0;
}
Map::Map()
{
	delete[] map;
}

void Map::setWidth(int w)
{
	mapWidth = w;
}

int Map::getWidth()
{
	return mapWidth;
}

void Map::setHeight(int h)
{
	mapHeight = h;
}

int Map::getHeight()
{
	return mapHeight;
}

void Map::setXY(int i, int j, char value)
{
	map[i*mapWidth + j] = value;
}

char Map::getXY(int i, int j)
{
	return map[i*mapWidth + j];
}

void Map::initMap(char *m, int width, int height)
{
	mapWidth = width;
	mapHeight = height;
	map = new char[height * width];

	memcpy(map, m, width*height);
}

void Map::printMap()
{
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			std::cout << map[i*mapWidth + j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}