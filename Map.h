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

	int len;		 //�����
	int wid;		 //������
	int hei;		 //������
	cell ***floor;	 //�����
	int bonusCount = 0;  //���������� �������
	int moneyCount = 0;	 //���������� �����

	map();
		
	map(int g, int h, int d);

	//�������, �������� �����      (�����. i  | �����. j |  ����� ����� |  �����������    |    ����� ����)
	void makeLine(int iFrom, int jFrom, int kFrom, int lineLength, line lineWhere, cell lineOfWhat);

	//�������, ����������� ����� � ��������� ����� �����
	void spawnBonus(int floorNumber);

	//�������, ����������� ������ � ��������� ����� �����
	void spawnMoney(int floorNumber);

	//�������, ��������� ������� � �������� �������
	void makeRoom(int iiRoom, int jjRoom, int floorNumber, int roomLenn, int roomWidd);

	//�������� ������
	bool canYouMove(cell r);
	bool isbonus(cell b);

	~map();
};