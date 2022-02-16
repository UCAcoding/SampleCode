#pragma once
#include <windows.h>
#include <time.h>

//·£´ý ½Ãµå
#define randomize() srand((unsigned)time(NULL))
//·£´ý
#define random(n) (rand() % (n))

#define delay(n) Sleep(n)
#define clrscr() system("cls")
#define gotoxy(x,y) { COORD Cur = {x, y}; \
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);}
#define showcursor(bShow) { CONSOLE_CURSOR_INFO CurInfo = {20, bShow}; \
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo); }

