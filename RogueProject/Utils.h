#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

class Utils
{
public:

	static void gotoXY(short C, short R);
	static void clearScene();
	static void printMsg(int x, int y, std::string msg);
};

#endif // UTILS_H