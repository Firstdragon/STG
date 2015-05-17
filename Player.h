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
	int playerHappiness;		// Хеппинес игрока
	int playerMoney;		// Количество денег игрока
	int moveUp;			// Номер клавиши, отвечающей за движение вверх
	int moveDown;			// Номер клавиши, отвечающей за движение вниз
	int moveLeft;			// Номер клавиши, отвечающей за движение влево
	int moveRight;			// Номер клавиши, отвечающей за движение вправо
	bool botMode;			// Состояние игрока (бот/реальный игрок), будет реализовано позже
	int ii;				// Координата i игрока
	int jj;				// Координата j игрока
	int kk;				// Координата k игрока
	int playerSimbol;		// Символ игрока, отображающийся в консоли

	player();

	// Управление
	void playerControls();

	// Движение игрока
	int playerMoving(int caughtKey, map &map, cell r);

	~player();

};