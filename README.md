# Python_class
![header](https://capsule-render.vercel.app/api?type=wave&color=auto&height=300&section=header&text=샘플%20코드들&fontSize=90)








#### ***샘플 코드 관련***

 *수업에쓸 샘플 코드들. 
 
  1.cursor.h*
 c언어에서 랜덤, 딜레이, 화면 지우기, gotoxy,커서 토글 
 
```
#include <windows.h>
#include <time.h>

#define randomize() srand((unsigned)time(NULL))
#define random(n) (rand() % (n))
#define delay(n) Sleep(n)
#define clrscr() system("cls")
#define gotoxy(x,y) { COORD Cur = {x, y}; \
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);}
#define showcursor(bShow) { CONSOLE_CURSOR_INFO CurInfo = {20, bShow}; \
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo); }
```




