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

	int len;		 //dlina
	int wid;		 //shirina
	int hei;		 //vysota
	cell ***floor;	 //karta
	int bonusCount = 0;  //kolichestvo bonusov
	int moneyCount = 0;	 //kolichestvo deneg

	map();
		
	map(int g, int h, int d);

	//Funkciya, risuyushhaya liniyu      (koord. i  | koord. j |  dlina linii |  napravlenie    |    liniya chego)
	void makeLine(int iFrom, int jFrom, int kFrom, int lineLength, line lineWhere, cell lineOfWhat);

	//Funkciya, razmeshhayushhaya bonus v sluchajnom meste karty
	void spawnBonus(int floorNumber);

	//Funkciya, razmeshhayushhaya dengi v sluchajnom meste karty
	void spawnMoney(int floorNumber);

	//Funkciya, sozdayushhaya komnatu s chetyrmya dveryami
	void makeRoom(int iiRoom, int jjRoom, int floorNumber, int roomLenn, int roomWidd);

	//Proverka kletki
	bool canYouMove(cell r);
	bool isbonus(cell b);

	~map();
};