#include "player.h"

player::player()
{};

// Upravlenie
void player::playerControls()
{
	std::cout << "Push button which you will use for move up:    ";
	moveUp = _getch();
	std::cout << static_cast<char>(moveUp) << std::endl;

	std::cout << "Push button which you will use for move left:  ";
	moveLeft = _getch();
	std::cout << static_cast<char>(moveLeft) << std::endl;

	std::cout << "Push button which you will use for move down:  ";
	moveDown = _getch();
	std::cout << static_cast<char>(moveDown) << std::endl;

	std::cout << "Push button which you will use for move right: ";
	moveRight = _getch();
	std::cout << static_cast<char>(moveRight) << std::endl;

}

// Dvizhenie igroka
int player::playerMoving(int caughtKey, map &map, cell r)
{
	if (caughtKey == moveUp)
	{
		if (map.canYouMove(map.floor[ii - 1][jj][kk]))
		{
			if (map.floor[ii - 1][jj][kk] == cell::LIFT_UP)
			{
				map.floor[ii][jj][kk] = cell::BLANK;
				kk++;
				map.floor[ii][jj][kk] = r;
			}
			else if (map.floor[ii - 1][jj][kk] == cell::LIFT_DOWN)
			{
				map.floor[ii][jj][kk] = cell::BLANK;
				kk--;
				map.floor[ii][jj][kk] = r;
			}
			else {
				if (map.floor[ii - 1][jj][kk] == cell::BONUS100)
				{
					map.bonusCount -= 1;
					playerHappiness += 100;
				}

				if (map.floor[ii - 1][jj][kk] == cell::BONUS200)
				{
					map.bonusCount -= 1;
					playerHappiness += 200;
				}

				if (map.floor[ii - 1][jj][kk] == cell::BONUS300)
				{
					map.bonusCount -= 1;
					playerHappiness += 300;
				}

				if (map.floor[ii - 1][jj][kk] == cell::MONEY100)
				{
					map.moneyCount -= 1;
					playerMoney += 100;
				}

				if (map.floor[ii - 1][jj][kk] == cell::MONEY500)
				{
					map.moneyCount -= 1;
					playerMoney += 500;
				}
				map.floor[ii][jj][kk] = cell::BLANK;
				ii--;
				map.floor[ii][jj][kk] = r;
			}
		}
	}


	if (caughtKey == moveDown)
	{
		if (map.canYouMove(map.floor[ii + 1][jj][kk]))
		{
			if (map.floor[ii + 1][jj][kk] == cell::LIFT_UP)
			{
				map.floor[ii][jj][kk] = cell::BLANK;
				kk++;
				map.floor[ii][jj][kk] = r;
			}
			else if (map.floor[ii + 1][jj][kk] == cell::LIFT_DOWN)
			{
				map.floor[ii][jj][kk] = cell::BLANK;
				kk--;
				map.floor[ii][jj][kk] = r;
			}
			else {
				if (map.floor[ii + 1][jj][kk] == cell::BONUS100)
				{
					map.bonusCount -= 1;
					playerHappiness += 100;
				}

				if (map.floor[ii + 1][jj][kk] == cell::BONUS200)
				{
					map.bonusCount -= 1;
					playerHappiness += 200;
				}

				if (map.floor[ii + 1][jj][kk] == cell::BONUS300)
				{
					map.bonusCount -= 1;
					playerHappiness += 300;
				}

				if (map.floor[ii + 1][jj][kk] == cell::MONEY100)
				{
					map.moneyCount -= 1;
					playerMoney += 100;
				}

				if (map.floor[ii + 1][jj][kk] == cell::MONEY500)
				{
					map.moneyCount -= 1;
					playerMoney += 500;
				}
				map.floor[ii][jj][kk] = cell::BLANK;
				ii++;
				map.floor[ii][jj][kk] = r;
			}
		}
	}

	if (caughtKey == moveRight)
	{
		if (map.canYouMove(map.floor[ii][jj + 1][kk]))
		{
			if (map.floor[ii][jj + 1][kk] == cell::LIFT_UP)
			{
				map.floor[ii][jj][kk] = cell::BLANK;
				kk++;
				map.floor[ii][jj][kk] = r;
			}
			else if (map.floor[ii][jj + 1][kk] == cell::LIFT_DOWN)
			{
				map.floor[ii][jj][kk] = cell::BLANK;
				kk--;
				map.floor[ii][jj][kk] = r;
			}
			else {
				if (map.floor[ii][jj + 1][kk] == cell::BONUS100)
				{
					map.bonusCount -= 1;
					playerHappiness += 100;
				}

				if (map.floor[ii][jj + 1][kk] == cell::BONUS200)
				{
					map.bonusCount -= 1;
					playerHappiness += 200;
				}

				if (map.floor[ii][jj + 1][kk] == cell::BONUS300)
				{
					map.bonusCount -= 1;
					playerHappiness += 300;
				}

				if (map.floor[ii][jj + 1][kk] == cell::MONEY100)
				{
					map.moneyCount -= 1;
					playerMoney += 100;
				}

				if (map.floor[ii][jj + 1][kk] == cell::MONEY500)
				{
					map.moneyCount -= 1;
					playerMoney += 500;
				}
				map.floor[ii][jj][kk] = cell::BLANK;
				jj++;
				map.floor[ii][jj][kk] = r;
			}
		}
	}

	if (caughtKey == moveLeft)
	{
		if (map.canYouMove(map.floor[ii][jj - 1][kk]))
		{

			if (map.floor[ii][jj - 1][kk] == cell::LIFT_UP)
			{
				map.floor[ii][jj][kk] = cell::BLANK;
				kk++;
				map.floor[ii][jj][kk] = r;
			}
			else if (map.floor[ii][jj - 1][kk] == cell::LIFT_DOWN)
			{
				map.floor[ii][jj][kk] = cell::BLANK;
				kk--;
				map.floor[ii][jj][kk] = r;
			}
			else {
				if (map.floor[ii][jj - 1][kk] == cell::BONUS100)
				{
					map.bonusCount -= 1;
					playerHappiness += 100;
				}

				if (map.floor[ii][jj - 1][kk] == cell::BONUS200)
				{
					map.bonusCount -= 1;
					playerHappiness += 200;
				}

				if (map.floor[ii][jj - 1][kk] == cell::BONUS300)
				{
					map.bonusCount -= 1;
					playerHappiness += 300;
				}

				if (map.floor[ii][jj - 1][kk] == cell::MONEY100)
				{
					map.moneyCount -= 1;
					playerMoney += 100;
				}

				if (map.floor[ii][jj - 1][kk] == cell::MONEY500)
				{
					map.moneyCount -= 1;
					playerMoney += 500;
				}

				map.floor[ii][jj][kk] = cell::BLANK;
				jj--;
				map.floor[ii][jj][kk] = r;
			}


		}
	}

	if ((caughtKey != moveUp) && (caughtKey != moveDown) && (caughtKey != moveLeft) && (caughtKey != moveRight))
		return -33;

	return 0;
}

player::~player()
{};