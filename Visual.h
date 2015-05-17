#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <ctime>

#include "Enums.h"
#include "map.h"
#include "player.h"

class visual
{
protected:
public:
		visual();

		~visual();

		// Vyvod tekuschego sostoyaniya karti v konsol'
		void gameConsoleOut(map &mapp, int p1hap, int p2hap, int p1money, int p2money, int p1s, int p2s);

		// Vyvod informacii v konce igry
		void gameOver(int p1hap, int p2hap, int p1money, int p2money);
};