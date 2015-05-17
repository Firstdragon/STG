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
	int caughtKey;		// Номер захваченной с клавиатуры клавиши
	player player1;		// Игрок 1
	player player2;		// Игрок 2
	bot bot1;
	bot bot2;
	visual vis;		// Объект класса visual
	map mapp;		// Объект класса map


	gameEngine()
	{};

	~gameEngine()
	{};

	// Режим игры
	void gameMode();

	// Начальные установки
	void startGame(map &map, player &player1, player &player2);

	// Процесс игры
	void playGame();
};