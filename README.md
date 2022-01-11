# Python_class
![header](https://capsule-render.vercel.app/api?type=wave&color=auto&height=300&section=header&text=샘플%20코드들&fontSize=90)








#### ***샘플 코드 관련***

 1. 수업에쓸 샘플 코드들. 


 *cursor.h*
 
 ''' #include <windows.h>'''
'''#include <time.h>'''

#define randomize() srand((unsigned)time(NULL))
#define random(n) (rand() % (n))
#define delay(n) Sleep(n)
#define clrscr() system("cls")
#define gotoxy(x,y) { COORD Cur = {x, y}; \
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);}
#define showcursor(bShow) { CONSOLE_CURSOR_INFO CurInfo = {20, bShow}; \
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo); }
'''




