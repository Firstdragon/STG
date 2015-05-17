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
	int caughtKey;		// ����� ����������� � ���������� �������
	player player1;		// ����� 1
	player player2;		// ����� 2
	bot bot1;
	bot bot2;
	visual vis;		// ������ ������ visual
	map mapp;		// ������ ������ map


	gameEngine()
	{};

	~gameEngine()
	{};

	// ����� ����
	void gameMode();

	// ��������� ���������
	void startGame(map &map, player &player1, player &player2);

	// ������� ����
	void playGame();
};