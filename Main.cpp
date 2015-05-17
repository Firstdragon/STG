#include "map.h"
#include "player.h"
#include "gameEngine.h"
#include "visual.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

int main()
{
	gameEngine game;

	game.playGame();

	system("pause");

	return 0;
}