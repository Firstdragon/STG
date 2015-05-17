#include "Visual.h"

visual::visual()
{};

visual::~visual()
{};

// Vyvod tekushhego sostoyaniya karty v konsol
void visual::gameConsoleOut(map &mapp, int p1hap, int p2hap, int p1money, int p2money, int p1s, int p2s)
{
	system("cls");
	std::cout << "\n\n\tPlayer 1 happiness: " << p1hap << "\t\t\tPlayer 2 happiness: " << p2hap << "\n\n";
	std::cout << "\n\n\tPlayer 1 money: " << p1money << "\t\t\tPlayer 2 money: " << p2money << "\n\n";
	for (int k = 0; k < mapp.hei; k++)
	{
		for (int i = 0; i < mapp.len; i++)
		{
			for (int j = 0; j < mapp.wid; j++)
			{

				if (mapp.floor[i][j][k] == cell::WALL)
				{
					std::cout << "#";
				}
				if (mapp.floor[i][j][k] == cell::BLANK)
				{
					std::cout << " ";
				}
				if (mapp.floor[i][j][k] == cell::PLAYER1 || mapp.floor[i][j][k] == cell::BOT1)
				{
					std::cout << p1s;
				}
				if (mapp.floor[i][j][k] == cell::PLAYER2 || mapp.floor[i][j][k] == cell::BOT2)
				{
					std::cout << p2s;
				}
				if (mapp.floor[i][j][k] == cell::BONUS100)
				{
					std::cout << "X";
				}
				if (mapp.floor[i][j][k] == cell::BONUS200)
				{
					std::cout << "Y";
				}
				if (mapp.floor[i][j][k] == cell::BONUS300)
				{
					std::cout << "Z";
				}
				if (mapp.floor[i][j][k] == cell::MONEY100)
				{
					std::cout << "$";
				}
				if (mapp.floor[i][j][k] == cell::MONEY500)
				{
					std::cout << "%";
				}
				if (mapp.floor[i][j][k] == cell::LIFT_UP)
				{
					std::cout << "^";
				}
				if (mapp.floor[i][j][k] == cell::LIFT_DOWN)
				{
					std::cout << "v";
				}

			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}
}

// Vyvod informacii v konce igry
void visual::gameOver(int p1hap, int p2hap, int p1money, int p2money)
{
	system("cls");
	std::cout << "\n\t\t\tGAME OVER\n\n\tPLAYER 1 TOTAL HAPPINESS: " << p1hap << "\tPLAYER 2 TOTAL HAPPINESS :" << p2hap <<
		"\n\n\tPLAYER 1 REMAINING MONEY: " << p1money << "\tPLAYER 2 REMAINING MONEY: " << p2money << "\n\n";

}