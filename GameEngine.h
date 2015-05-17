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
#include "visual.h"
#include "bot.h"

class gameEngine
{
protected:
public:
	int caughtKey;		// Nomer zaxvachennoj s klaviatury klavishi
	player player1;		// Igrok 1
	player player2;		// Igrok 2
	bot bot1;
	bot bot2;
	visual vis;		// Obekt klassa visual
	map mapp;		// Obekt klassa map


	gameEngine()
	{};

	~gameEngine()
	{};

	// Rezhim igry
	void gameMode();

	// Nachalnye ustanovki
	void startGame(map &map, player &player1, player &player2);

	// Process igry
	void playGame();
};