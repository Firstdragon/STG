#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <ctime>

#include "Enums.h"
#include "Player.h"
#include "Map.h"


class bot
{
public:
	int m = 0;
	int s = 0;
	int z = 0;
	int x = 0;
	int isherei = 0;
	int isherej = 0;
	int len = 24;
	int wid = 48;
	bool reset = false;

	int move(map &map, player &playerbot, int k);
};