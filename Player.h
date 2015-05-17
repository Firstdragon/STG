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
	int playerHappiness;		// �������� ������
	int playerMoney;		// ���������� ����� ������
	int moveUp;			// ����� �������, ���������� �� �������� �����
	int moveDown;			// ����� �������, ���������� �� �������� ����
	int moveLeft;			// ����� �������, ���������� �� �������� �����
	int moveRight;			// ����� �������, ���������� �� �������� ������
	bool botMode;			// ��������� ������ (���/�������� �����), ����� ����������� �����
	int ii;				// ���������� i ������
	int jj;				// ���������� j ������
	int kk;				// ���������� k ������
	int playerSimbol;		// ������ ������, �������������� � �������

	player();

	// ����������
	void playerControls();

	// �������� ������
	int playerMoving(int caughtKey, map &map, cell r);

	~player();

};