#include "GameEngine.h"

void gameEngine::gameMode()
{
	player1.playerSimbol = 1;
	player2.playerSimbol = 2;
	std::string p1; std::string p2;
	std::cout << "Write who will play, for example: \"player bot\"" << std::endl;
	std::cin >> p1 >> p2;

	if ((p1 != "player" && p1 != "bot") || (p2 != "player" && p2 != "bot"))
	{
		std::cout << "Error, incorrect input" << std::endl;
		system("pause");
		exit(-1);
	}

	if (p1 == "player") 
	{
		player1.botMode = false;
	}
	else if (p1 == "bot")
	{
		player1.botMode = true;
		player1.moveUp = 119;
		player1.moveLeft = 97;
		player1.moveDown = 115;
		player1.moveRight = 100;
	}
	if (p2 == "player") 
	{
		player2.botMode = false;
	}
	else if (p2 == "bot")
	{
		player2.botMode = true;
		player2.moveUp = 105;
		player2.moveLeft = 106;
		player2.moveDown = 107;
		player2.moveRight = 108;

	}
}

void gameEngine::startGame(map &map, player &player1, player &player2)
{
	gameMode();


	player1.ii = 2;
	player1.jj = 2;
	player1.kk = 0;
	player2.ii = 4;
	player2.jj = 4;
	player2.kk = 1;
	map.floor[player1.ii][player1.jj][player1.kk] = cell::PLAYER1;
	map.floor[player2.ii][player2.jj][player2.kk] = cell::PLAYER2;

	player1.playerHappiness = 0;
	player2.playerHappiness = 0;

	player1.playerMoney = 1000;
	player2.playerMoney = 1000;

	if (player1.botMode == false)
	{
		std::cout << "\nPlayer 1 control settings: \n";
		player1.playerControls();
	}


	if (player2.botMode == false)
	{
		std::cout << "\nPlayer 2 control settings: \n";
		player2.playerControls();
	}

	Sleep(1000);
}

void gameEngine::playGame()
{
	int b;
	int k;
	startGame(mapp, player1, player2);
	int caughtKey = 0;
	while (caughtKey != 27)
	{
		vis.gameConsoleOut(mapp, player1.playerHappiness, player2.playerHappiness, player1.playerMoney, player2.playerMoney, player1.playerSimbol, player2.playerSimbol);
		if (!player1.botMode || !player2.botMode)
		{
			caughtKey = _getch();
			if (caughtKey == 0)
				caughtKey = _getch();
		}
		else Sleep(10);
		if (player1.botMode == false && player2.botMode == false)
		{
			if ((player1.playerMoving(caughtKey, mapp, cell::PLAYER1)) == -33)
				player2.playerMoving(caughtKey, mapp, cell::PLAYER2);
		}
		if (player1.botMode == false && player2.botMode == true)
		{
			player1.playerMoving(caughtKey, mapp, cell::PLAYER1);
			player2.playerMoving(bot2.move(mapp, player2, player2.kk), mapp, cell::PLAYER2);
		}
		if (player1.botMode == true && player2.botMode == false)
		{
			player1.playerMoving(bot1.move(mapp, player1, player1.kk), mapp, cell::PLAYER1);
			player2.playerMoving(caughtKey, mapp, cell::PLAYER2);
		}
		if (player1.botMode == true && player2.botMode == true)
		{
			player1.playerMoving(bot1.move(mapp, player1, player1.kk), mapp, cell::PLAYER1);
			player2.playerMoving(bot2.move(mapp, player2, player2.kk), mapp, cell::PLAYER2);
		}

		srand(time(0));
		b = (rand() % 2 + 1);
		k = (rand() % 2);
		if (b == 2)
			mapp.spawnBonus(k);


		srand(time(0));
		b = (rand() % 5);
		k = (rand() % 2);
		if (b == 2)
			mapp.spawnMoney(k);
	}
	vis.gameOver(player1.playerHappiness, player2.playerHappiness, player1.playerMoney, player2.playerMoney);
}