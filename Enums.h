#pragma once

enum class cell {
	BLANK = 0,  // 0	�������
	WALL,       // 1	�����
	BONUS100,   // 2	����� �� 100 ���������
	BONUS200,   // 3	����� �� 200 ���������
	BONUS300,   // 4	����� �� 300 ���������
	MONEY100,   // 5	100 �����
	MONEY500,   // 6	500 �����
	PLAYER1,	// 7	����� 1
	PLAYER2,    // 8	����� 2
	BOT1,       // 9	��� 1
	BOT2,       // 10	��� 2
	LIFT_UP,    // 11	���� �����
	LIFT_DOWN   // 12	���� ����
};

enum class line {
	UP = 0,   // 0 �����
	LEFT,     // 1 �����
	RIGHT,    // 2 ������
	DOWN	  // 3 ����
};