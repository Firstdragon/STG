#include "map.h"

map::map()
{
	srand(time(0));

	len = 24;
	wid = 48;
	hei = 3;

	int ii, jj, s = 0;

	int startBonusCount;
	int startMoneyCount;
	floor = new cell **[len];				//Выделяем память под матрицу floor размера len*wid*hei
	for (int i = 0; i < len; i++)
	{
		floor[i] = new cell *[wid];
		for (int j = 0; j < wid; j++)
			floor[i][j] = new cell[hei];
	}
	for (int i = 0; i < len; i++)
		for (int j = 0; j < wid; j++)
			for (int k = 0; k < hei; k++)
				floor[i][j][k] = cell::WALL;		 //Всё заполняется "стеной"

	for (int k = 0; k < hei; k++)
	{
		int previousRoomLength;
		int previousRoomWidth;
		int blankSpace = 0;
		int roomsCount = 0;

		while ((blankSpace < ((2 * len + 2 * wid) + len*wid / 20)) && (roomsCount < 30))
		{
			ii = (rand() % (len - 2) + 1);
			jj = (rand() % (wid - 2) + 1);

			if (roomsCount == 0)
			{
				ii = 1;
				jj = 1;
			}

			int roomLength = (rand() % (len / 4) + (len / 8));
			int roomWidth = (rand() % (wid / 4) + (wid / 8));

			if ((ii + roomLength >= len - 2) || (jj + roomWidth >= wid - 2))
				continue;

			makeRoom(ii, jj, k, roomLength, roomWidth);

			roomsCount++;
		}
		roomsCount = 0;

		//Создание "рамок"
		makeLine(0, 0, k, wid, line::RIGHT, cell::WALL);
		makeLine(len - 1, 0, k, wid, line::RIGHT, cell::WALL);
		makeLine(0, 0, k, len, line::DOWN, cell::WALL);
		makeLine(0, wid - 1, k, len, line::DOWN, cell::WALL);

		//Расстановка лифтов
		if (k != hei - 1)
			makeLine(2, 1, k, 4, line::DOWN, cell::LIFT_UP);
		if (k != 0)
			makeLine(1, 2, k, 4, line::RIGHT, cell::LIFT_DOWN);

		//Раскидывание бонусов
		startBonusCount = (rand() % 8 + 3);
		for (int r = 0; r < startBonusCount; r++)
		{
			spawnBonus(k);
			bonusCount -= 1;
		}

		//Раскидывание денег
		startMoneyCount = (rand() % 6 + 2);
		for (int r = 0; r < startMoneyCount; r++)
		{
			spawnMoney(k);
			moneyCount -= 1;
		}
	}
};

map::map(int g, int h, int d)
{
	len = g; wid = h; hei = d;
	int s = 0;
	int startBonusCount;
	int startMoneyCount;
	floor = new cell **[len];				//Выделяем память под матрицу floor размера len*wid
	for (int i = 0; i < len; i++)
	{
		floor[i] = new cell *[wid];
		for (int j = 0; j < wid; j++)
			floor[i][j] = new cell[hei];
	}
	for (int i = 0; i < len; i++)
		for (int j = 0; j < wid; j++)
			for (int k = 0; k < hei; k++)
				floor[i][j][k] = cell::BLANK;				//Заполняем всё нулями

	for (int k = 0; k < hei; k++)
	{
		//Создание "рамок"
		makeLine(0, 0, k, wid, line::RIGHT, cell::WALL);
		makeLine(len - 1, 0, k, wid, line::RIGHT, cell::WALL);
		makeLine(0, 0, k, len, line::DOWN, cell::WALL);
		makeLine(0, wid - 1, k, len, line::DOWN, cell::WALL);

		//Создание перекрёстных коридоров
		if (len % 2 == 0)
		{

			makeLine(0, wid / 2 + 2, k, len / 2 - 2, line::DOWN, cell::WALL);
			makeLine(0, wid / 2 - 3, k, len / 2 - 2, line::DOWN, cell::WALL);
			makeLine(len - 1, wid / 2 + 2, k, len / 2 - 2, line::UP, cell::WALL);
			makeLine(len - 1, wid / 2 - 3, k, len / 2 - 2, line::UP, cell::WALL);
			if (s != hei - 1)
				makeLine(len / 2 - 2, 1, k, 4, line::DOWN, cell::LIFT_UP);
			if (s != 0)
				makeLine(len / 2 - 2, wid - 2, k, 4, line::DOWN, cell::LIFT_DOWN);
		}
		else {
			makeLine(0, wid / 2 + 2, k, len / 2 - 1, line::DOWN, cell::WALL);
			makeLine(0, wid / 2 - 2, k, len / 2 - 1, line::DOWN, cell::WALL);
			makeLine(len - 1, wid / 2 + 2, k, len / 2 - 1, line::UP, cell::WALL);
			makeLine(len - 1, wid / 2 - 2, k, len / 2 - 1, line::UP, cell::WALL);
			if (s != hei - 1)
				makeLine(len / 2 - 1, 1, k, 3, line::DOWN, cell::LIFT_UP);
			if (s != 0)
				makeLine(len / 2 - 1, wid - 2, k, 3, line::DOWN, cell::LIFT_DOWN);
		}

		if (wid % 2 == 0)
		{
			makeLine(len / 2 + 2, 0, k, wid / 2 - 2, line::RIGHT, cell::WALL);
			makeLine(len / 2 - 3, 0, k, wid / 2 - 2, line::RIGHT, cell::WALL);
			makeLine(len / 2 + 2, wid - 1, k, wid / 2 - 2, line::LEFT, cell::WALL);
			makeLine(len / 2 - 3, wid - 1, k, wid / 2 - 2, line::LEFT, cell::WALL);
		}
		else {
			makeLine(len / 2 + 2, 0, k, wid / 2 - 1, line::RIGHT, cell::WALL);
			makeLine(len / 2 - 2, 0, k, wid / 2 - 1, line::RIGHT, cell::WALL);
			makeLine(len / 2 + 2, wid - 1, k, wid / 2 - 1, line::LEFT, cell::WALL);
			makeLine(len / 2 - 2, wid - 1, k, wid / 2 - 1, line::LEFT, cell::WALL);
		}

		if (wid % 2 == 0)							//Создание "дверей"
		{
			makeLine(1, wid / 4 - 2, k, len - 2, line::DOWN, cell::BLANK);
			makeLine(1, wid / 4 - 1, k, len - 2, line::DOWN, cell::BLANK);
			makeLine(1, wid / 4 * 3, k, len - 2, line::DOWN, cell::BLANK);
			makeLine(1, wid / 4 * 3 + 1, k, len - 2, line::DOWN, cell::BLANK);
		}
		else {
			makeLine(1, wid / 4 - 2, k, len - 2, line::DOWN, cell::BLANK);
			makeLine(1, wid / 4 - 1, k, len - 2, line::DOWN, cell::BLANK);
			makeLine(1, wid / 4 * 3 + 2, k, len - 2, line::DOWN, cell::BLANK);
			makeLine(1, wid / 4 * 3 + 1, k, len - 2, line::DOWN, cell::BLANK);
		}

		if (len % 2 == 0)							//Создание "дверей"
		{
			makeLine(len / 4 - 2, 1, k, wid - 2, line::RIGHT, cell::BLANK);
			makeLine(len / 4 - 1, 1, k, wid - 2, line::RIGHT, cell::BLANK);
			makeLine(len / 4 * 3, 1, k, wid - 2, line::RIGHT, cell::BLANK);
			makeLine(len / 4 * 3 + 1, 1, k, wid - 2, line::RIGHT, cell::BLANK);
		}
		else {
			makeLine(len / 4 - 2, 1, k, wid - 2, line::RIGHT, cell::BLANK);
			makeLine(len / 4 - 1, 1, k, wid - 2, line::RIGHT, cell::BLANK);
			makeLine(len / 4 * 3 + 2, 1, k, wid - 2, line::RIGHT, cell::BLANK);
			makeLine(len / 4 * 3 + 1, 1, k, wid - 2, line::RIGHT, cell::BLANK);
		}

		srand(time(0));
		startBonusCount = (rand() % 8 + 3);
		for (int r = 0; r < startBonusCount; r++)
		{
			spawnBonus(k);
			bonusCount -= 1;
		}

		srand(time(0));
		startMoneyCount = (rand() % 6 + 2);
		for (int r = 0; r < startMoneyCount; r++)
		{
			spawnMoney(k);
			moneyCount -= 1;
		}
		s++;
	}
}

//Функция, рисующая линию      (коорд. i  | коорд. j |  длина линии |  направление    |    линия чего)
void map::makeLine(int iFrom, int jFrom, int kFrom, int lineLength, line lineWhere, cell lineOfWhat)
{
	if (lineWhere == line::RIGHT)
		for (int j = jFrom; j < jFrom + lineLength; j++)
			floor[iFrom][j][kFrom] = lineOfWhat;
	if (lineWhere == line::LEFT)
		for (int j = jFrom; j > jFrom - lineLength; j--)
			floor[iFrom][j][kFrom] = lineOfWhat;
	if (lineWhere == line::UP)
		for (int i = iFrom; i > iFrom - lineLength; i--)
			floor[i][jFrom][kFrom] = lineOfWhat;
	if (lineWhere == line::DOWN)
		for (int i = iFrom; i < iFrom + lineLength; i++)
			floor[i][jFrom][kFrom] = lineOfWhat;
}

//Функция, размещающая бонус в случайном месте карты
void map::spawnBonus(int floorNumber)
{
	if (bonusCount < 15)
	{

		int i = (rand() % (len - 3) + 2);
		int j = (rand() % (wid - 3) + 2);
		if (floor[i][j][floorNumber] == cell::BLANK)
		{
			int c = (rand() % 3 + 1);
			if (c == 1) floor[i][j][floorNumber] = cell::BONUS100;
			if (c == 2) floor[i][j][floorNumber] = cell::BONUS200;
			if (c == 3) floor[i][j][floorNumber] = cell::BONUS300;
			bonusCount += 1;
		}

	}
}

//Функция, размещающая деньги в случайном месте карты
void map::spawnMoney(int floorNumber)
{
	if (moneyCount < 5)
	{

		int i = (rand() % (len - 4) + 2);
		int j = (rand() % (wid - 4) + 2);
		if (floor[i][j][floorNumber] == cell::BLANK)
		{
			int c = (rand() % 2 + 1);
			if (c == 1) floor[i][j][floorNumber] = cell::MONEY100;
			if (c == 2) floor[i][j][floorNumber] = cell::MONEY500;
			moneyCount += 1;
		}

	}
}

//Функция, создающая комнату с четырьмя дверями
void map::makeRoom(int iiRoom, int jjRoom, int floorNumber, int roomLenn, int roomWidd)
{
	for (int i = iiRoom; i < iiRoom + roomLenn; i++)
		for (int j = jjRoom; j < jjRoom + roomWidd; j++)
			floor[i][j][floorNumber] = cell::BLANK;
	floor[iiRoom + roomLenn / 2][jjRoom - 1][floorNumber] = cell::BLANK;
	floor[iiRoom + roomLenn / 2][jjRoom + roomWidd][floorNumber] = cell::BLANK;
	floor[iiRoom - 1][jjRoom + roomWidd / 2][floorNumber] = cell::BLANK;
	floor[iiRoom + roomLenn][jjRoom + roomWidd / 2][floorNumber] = cell::BLANK;

	rooms tempRoom;

	tempRoom.iRoom = iiRoom;
	tempRoom.jRoom = jjRoom;
	tempRoom.roomLen = roomLenn;
	tempRoom.roomWid = roomWidd;
	tempRoom.iRoomCenter = iiRoom + roomLenn / 2;
	tempRoom.jRoomCenter = jjRoom + roomWidd / 2;

	room.push_back(tempRoom);
};

//Проверка клетки
bool map::canYouMove(cell r)			//Функция, проверяющая возможность перемещения
{
	if ((r == cell::WALL) || (r == cell::PLAYER1) || (r == cell::PLAYER2))
	return false;
	else return true;
}
bool map::isbonus(cell b)
{
	if ((b == cell::BONUS100) || (b == cell::BONUS200) || (b == cell::BONUS300) || (b == cell::MONEY100) || (b == cell::MONEY500))
		return true;
	else return false;
}

map::~map()					//Очистка выделеной памяти
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < wid; j++)
			delete[] floor[i][j];
		delete floor[i];
	}
	delete[] floor;
}