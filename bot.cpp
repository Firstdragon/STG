#include "bot.h"

int bot::move(map &map, player &playerbot, int k)
{
	if ((isherei == 0 || isherej == 0) || (isherei == playerbot.ii && isherej == playerbot.jj) || (!map.isbonus(map.floor[isherei][isherej][k]) && !reset))
	{
		reset = false;
		for (int q = 1; q < 48; q++)
		{
			if (playerbot.ii - q < 0)
				m = 0; else m = playerbot.ii - q;
			if (playerbot.jj - q < 0)
				s = 0; else s = playerbot.jj - q;
			if (playerbot.ii + q >= len)
				z = len; else z = playerbot.ii + q;
			if (playerbot.jj + q >= wid)
				x = wid; else x = playerbot.jj + q;
			for (int i = m; i < z; i++)
				for (int j = s; j < x; j++)
					if (map.isbonus(map.floor[i][j][k]))
					{
						isherei = i;
						isherej = j;
						if (i < playerbot.ii && map.canYouMove(map.floor[playerbot.ii - 1][playerbot.jj][k]))
							return playerbot.moveUp;
						if (i > playerbot.ii && map.canYouMove(map.floor[playerbot.ii + 1][playerbot.jj][k]))
							return playerbot.moveDown;
						if (j < playerbot.jj && map.canYouMove(map.floor[playerbot.ii][playerbot.jj - 1][k]))
							return playerbot.moveLeft;
						if (j > playerbot.jj && map.canYouMove(map.floor[playerbot.ii][playerbot.jj + 1][k]))
							return playerbot.moveRight;

					};
		}
	}
	else
	{
		if (isherei < playerbot.ii && map.canYouMove(map.floor[playerbot.ii - 1][playerbot.jj][k]))
			return playerbot.moveUp;
		if (isherei > playerbot.ii && map.canYouMove(map.floor[playerbot.ii + 1][playerbot.jj][k]))
			return playerbot.moveDown;
		if (isherej < playerbot.jj && map.canYouMove(map.floor[playerbot.ii][playerbot.jj - 1][k]))
			return playerbot.moveLeft;
		if (isherej > playerbot.jj && map.canYouMove(map.floor[playerbot.ii][playerbot.jj + 1][k]))
			return playerbot.moveRight;
	}
	srand(time(0));
	isherei = (rand() % len);
	isherej = (rand() % wid);

	reset = true;
	if (map.canYouMove(map.floor[playerbot.ii - 1][playerbot.jj][k]))
		return playerbot.moveUp;
	if (map.canYouMove(map.floor[playerbot.ii + 1][playerbot.jj][k]))
		return playerbot.moveDown;
	if (map.canYouMove(map.floor[playerbot.ii][playerbot.jj - 1][k]))
		return playerbot.moveLeft;
	if (map.canYouMove(map.floor[playerbot.ii][playerbot.jj + 1][k]))
		return playerbot.moveRight;

}