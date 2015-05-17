#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <vector>
#include "Enums.h"

class map
{
protected:
public:


	struct rooms
	{
		int iRoom;
		int jRoom;
		int roomLen;
		int roomWid;
		int iRoomCenter;
		int jRoomCenter;
	};

	std::vector <rooms> room;

	int len;		 //длина
	int wid;		 //ширина
	int hei;		 //высота
	cell ***floor;	 //карта
	int bonusCount = 0;  //количество бонусов
	int moneyCount = 0;	 //количество денег

	map();
		
	map(int g, int h, int d);

	//Функция, рисующая линию      (коорд. i  | коорд. j |  длина линии |  направление    |    линия чего)
	void makeLine(int iFrom, int jFrom, int kFrom, int lineLength, line lineWhere, cell lineOfWhat);

	//Функция, размещающая бонус в случайном месте карты
	void spawnBonus(int floorNumber);

	//Функция, размещающая деньги в случайном месте карты
	void spawnMoney(int floorNumber);

	//Функция, создающая комнату с четырьмя дверями
	void makeRoom(int iiRoom, int jjRoom, int floorNumber, int roomLenn, int roomWidd);

	//Проверка клетки
	bool canYouMove(cell r);
	bool isbonus(cell b);

	~map();
};