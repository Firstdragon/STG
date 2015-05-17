#pragma once

enum class cell {
	BLANK = 0,  // 0	пустота
	WALL,       // 1	стена
	BONUS100,   // 2	бонус на 100 хеппенеса
	BONUS200,   // 3	бонус на 200 хеппенеса
	BONUS300,   // 4	бонус на 300 хеппенеса
	MONEY100,   // 5	100 денег
	MONEY500,   // 6	500 денег
	PLAYER1,	// 7	игрок 1
	PLAYER2,    // 8	игрок 2
	BOT1,       // 9	бот 1
	BOT2,       // 10	бот 2
	LIFT_UP,    // 11	лифт вверх
	LIFT_DOWN   // 12	лифт вниз
};

enum class line {
	UP = 0,   // 0 вверх
	LEFT,     // 1 влево
	RIGHT,    // 2 вправо
	DOWN	  // 3 вниз
};