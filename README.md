
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


2.imageLayer
# ImageLayer
* 다운로드 주소 : https://vo.la/mOdv
* 이미지 출력을 도와주기 위한 유틸리티
* 포토샵, 일러스트 같은 프로그램의 레이어 개념을 생각하면 편합니다.
* Visual Studio로는 테스트 되었지만 다른 IDE는 아직 안해봤습니다.

## 사용법
1. 3개의 파일을 모두 자신의 프로젝트에 추가한다. (헤더파일, 이미지, 메인 파일이 모두 같은 폴더에 있어야 함)
2. ImageLayerImple.h를 수정한다.
	```c 
	//ImageLayerImple.h
	#define CONSOLE_WIDTH 180 //자신의 콘솔 사이즈에 맞게 설정한다.
	#define CONSOLE_HEIGHT 48
	```
## 사용 예시
* 이미지 띄우기
	```c
	#include <stdio.h>
	#include "ImageLayer.h"

	int main() {
		Sleep(500);

		ImageLayer imageLayer = DEFAULT_IMAGE_LAYER;
		imageLayer.initialize(&imageLayer); //초기화

		Image images[3] = {
			{"sample2.bmp", 0, 0, 2}, //{이미지 이름, 시작 x좌표, 시작 y좌표, 크기 배율(쓰지 않으면 기본값인 16이 들어감)} 
			{"sample.bmp", 500, 500},
			{"sample.bmp", 200, 200}
		}; //배열의 첫 원소가 가장 아래 그려진다.

		imageLayer.imageCount = 3; //images 배열의 크기보다 작거나 같아야 한다.
		imageLayer.images = images;

		imageLayer.renderAll(&imageLayer);

		getchar();
	}
	```

* 이미지 띄우고 움직이기
	```c
    #include <stdio.h>
    #include "ImageLayer.h"

    int main() {
	    Sleep(500);

	    ImageLayer imageLayer = DEFAULT_IMAGE_LAYER;
	    imageLayer.initialize(&imageLayer);

	    Image images[3] = {
		    {"sample2.bmp", 0, 0},
		    {"sample.bmp", 500, 500},
		    {"sample.bmp", 200, 200},
	    };

	    imageLayer.imageCount = 3;
	    imageLayer.images = images;
        
        //반복문 안에서 이미지의 위치를 조정한 다음 renderAll()
	    for(int i = 0; i < 1000; i += 3) {
		    imageLayer.images[0].x = i;
		    imageLayer.images[1].y = i;

		    imageLayer.renderAll(&imageLayer);
	    }

	    getchar();
    }
	```

## 고급 사용법
1. 이미지 출력이 되지 않는다면 이 링크를 참고 해보세요. https://vo.la/0Uhb
2. 기본적으로 검정색(RGB(0, 0, 0))이 투명색으로 설정 되있는데 투명색을 수정하고 싶다면
```imageLayer.transparentColor = RGB(0, 0, 0); //자신이 원하는 색``` 으로 설정하면 됩니다.
3. ```imageLayer.fadeIn(&imageLayer);``` 으로 fade in, <br>
    ```imageLayer.fadeOut(&imageLayer);```으로 fade out 할 수 있습니다.


