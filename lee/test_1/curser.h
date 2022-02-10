#pragma once

#include <windows.h>
#include <time.h>
#include <string.h>

//���� �õ�
#define randomize() srand((unsigned)time(NULL))
//����
#define random(n) (rand() % (n))

#define delay(n) Sleep(n)
#define clrscr() system("cls")
#define gotoxy(x,y) { COORD Cur = {x, y}; \
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);}
#define showcursor(bShow) { CONSOLE_CURSOR_INFO CurInfo = {20, bShow}; \
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo); }


//���� ���
#define RED         (FOREGROUND_RED | FOREGROUND_INTENSITY)
#define BLUE        (FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define PINK        (RED | BLUE)
#define WHITE       (RED | GREEN | BLUE)
#define GREEN       (FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define YELLOW      (RED | GREEN)
#define SKYBLUE     (GREEN | BLUE)

#define RED_BG      (BACKGROUND_RED | BACKGROUND_INTENSITY)
#define BLUE_BG     (BACKGROUND_BLUE | BACKGROUND_INTENSITY)
#define PINK_BG     (RED_BG | BLUE_BG)
#define WHITE_BG    (RED_BG | GREEN_BG | BLUE_BG)
#define GREEN_BG    (BACKGROUND_GREEN | BACKGROUND_INTENSITY)
#define YELLOW_BG   (RED_BG | GREEN_BG)
#define SKYBLUE_BG  (GREEN_BG | BLUE_BG)

//��� �Լ� 
void PrintString(HANDLE hStdOut, WORD Attribute, LPCSTR str)
{
    SetConsoleTextAttribute(hStdOut, Attribute);
    puts(str);
}
