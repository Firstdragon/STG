#pragma once

enum class cell {
	BLANK = 0,  // 0	pustota
	WALL,       // 1	stena
	BONUS100,   // 2	bonus na 100 xeppenesa
	BONUS200,   // 3	bonus na 200 xeppenesa
	BONUS300,   // 4	bonus na 300 xeppenesa
	MONEY100,   // 5	100 deneg
	MONEY500,   // 6	500 deneg
	PLAYER1,	// 7	igrok 1
	PLAYER2,    // 8	igrok 2
	BOT1,       // 9	bot 1
	BOT2,       // 10	bot 2
	LIFT_UP,    // 11	lift vverx
	LIFT_DOWN   // 12	lift vniz
};

enum class line {
	UP = 0,   // 0 vverx
	LEFT,     // 1 vlevo
	RIGHT,    // 2 vpravo
	DOWN	  // 3 vniz
};