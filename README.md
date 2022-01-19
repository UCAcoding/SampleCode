
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

 사용예
```
#include <stdio.h>
#include <cursor.h>

int main()
{
	printf("3초 후에 화면을 지웁니다.\n");
	delay(3000);
	//화면 지움
	clrscr();
	//프롬프트 위치 이동 
	gotoxy(20, 10);
	printf("화면 중앙에 문자열을 출력합니다.\n");
}
```



2.컬러 문자 바꿔 주기 
사용예 
```

int main( )
{
    HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );

    PrintString(hStdOut, RED, "빨간색");
    PrintString(hStdOut, BLUE, "파란색");
    PrintString(hStdOut, PINK, "분홍색");
    PrintString(hStdOut, WHITE, "하얀색");
    PrintString(hStdOut, GREEN, "초록색");
    PrintString(hStdOut, YELLOW, "노란색");
    PrintString(hStdOut, SKYBLUE, "하늘색\n");

    PrintString(hStdOut, RED_BG, "빨간배경");
    PrintString(hStdOut, BLUE_BG, "파란배경");
    PrintString(hStdOut, PINK_BG, "분홍배경");
    PrintString(hStdOut, WHITE_BG, "하얀배경");
    PrintString(hStdOut, GREEN_BG, "초록배경");
    PrintString(hStdOut, YELLOW_BG, "노란배경");
    PrintString(hStdOut, SKYBLUE_BG, "하늘배경\n");

    PrintString(hStdOut, YELLOW_BG | PINK, "노란배경 빨간글씨");
	PrintString(hStdOut, WHITE_BG | GREEN, "하얀배경 빨간글씨");
	PrintString(hStdOut, GREEN_BG | WHITE, "초록배경 빨간글씨");
	PrintString(hStdOut, BLUE_BG | RED, "파랑배경 빨간글씨");

    CloseHandle(hStdOut);

    return 0;
}

```
