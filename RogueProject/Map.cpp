#include "Map.h"
#include <fstream>

Map::Map()
{
	mapWidth = NULL;
	mapHeight = NULL;
	map = NULL;
}

Map::~Map() //deconstructor
{
	if (map != NULL)
	{
		delete[] map;
	}
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

void Map::loadMap(std::string path)
{
	if (map != NULL)
	{
		delete[] map;
	}

	std::string line;
	std::ifstream myfile(path);
	if (myfile.is_open())
	{
		myfile >> mapWidth;
		myfile >> mapHeight;

		map = new char[mapWidth * mapHeight];

		for (int i = 0; i < mapWidth; i++)
		{
			for (int j = 0; j < mapHeight; j++)
			{
				myfile >> map[i*mapHeight + j];
			}
		}
		myfile.close();
	}
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
