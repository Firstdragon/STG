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

class player
{
protected:
public:
	int playerHappiness;		// Happiness igroka
	int playerMoney;		// Money igroka
	int moveUp;			// Nomer klavishi otvechaushei za dvijenie vverh
	int moveDown;			// Nomer klavishi otvechaushei za dvijenie vniz
	int moveLeft;			// Nomer klavishi otvechaushei za dvijenie vlevo
	int moveRight;			// Nomer klavishi otvechaushei za dvijenie vpravo
	bool botMode;			// Sostoyanie igroka (Player, bot)
	int ii;				// Koordinata i igroka
	int jj;				// Koordinata j igroka
	int kk;				// Koordinata k igroka
	int playerSimbol;		// Simvol igroka, otobrazhayushhijsya v konsoli

	player();

	// Upravlenie
	void playerControls();

	// Dvizhenie igroka
	int playerMoving(int caughtKey, map &map, cell r);

	~player();

};