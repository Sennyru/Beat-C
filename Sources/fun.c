/* fun.c */

#include "fun.h"


// (x, y) ��ǥ�� Ŀ���� ���´�.
void gotoxy(int x, int y) {
	static COORD pos = {0,};
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// xĭ, yĭ��ŭ Ŀ���� �ű��.
void movexy(int x, int y) {
	gotoxy(curX() + x, curY() + y);
}

// Ŀ�� ����� �����Ѵ�.
void setCursor(CURSOR_TYPE curType) {
	static CONSOLE_CURSOR_INFO CurInfo = {0,};

	switch (curType) {
		case HIDE:
			CurInfo.dwSize = 1;
			CurInfo.bVisible = FALSE;
			break;
		case UNDERBAR:
			CurInfo.dwSize = 1;
			CurInfo.bVisible = TRUE;
			break;
		case BLOCK:
			CurInfo.dwSize = 100;
			CurInfo.bVisible = TRUE;
			break;
	}

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

// ���� Ŀ���� X ��ǥ�� �����Ѵ�.
int curX() {
	static CONSOLE_SCREEN_BUFFER_INFO curInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	return curInfo.dwCursorPosition.X;
}

// ���� Ŀ���� Y ��ǥ�� �����Ѵ�.
int curY() {
	static CONSOLE_SCREEN_BUFFER_INFO curInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	return curInfo.dwCursorPosition.Y;
}