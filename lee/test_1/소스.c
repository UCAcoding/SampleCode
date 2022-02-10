#include <stdio.h>
#include <conio.h> //키보드 입력 출력 
#include "curser.h"

#define _CRT_SECURE_NO_WARNINGS

void start();
void switch_a();
void if_a();

int main() {

    start();
    return 0;
}


void start() {
    gotoxy(10, 10);
    printf("프로그램 만들기\n");
    delay(1000);
    for (int i = 5; i > 0; i--) {
        clrscr();
        gotoxy(10, 10);
        printf("%d\n", i);
        delay(400);
    }

    switch_a();
}

void switch_a() {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    printf("메뉴를 선택하세요.\n");
    printf("===============+\n");
    printf("1. if 함수 실행 \n");
    printf("2. for 함수 실행 \n");
    printf("3. while 함수 실행 \n");
    printf("===============+\n");
    delay(2000);
    clrscr();
    int input;
    scanf("%d", &input);


    switch (input) {
    case 1:
        PrintString(hStdOut, BLUE, "if문 실행");
        delay(500);
        if_a();
        break;
    case 2:
        break;
    case 3:
        break;
  
    }
    


}
 


void if_a() {

    int num1, num2, num3;
    printf("점수를 3개 입력해 주세요\n");
    scanf("%d %d %d", &num1, &num2, &num3);
    int total = (num1 + num2 + num3) / 3;

    if (total > 80) {
        printf("참 잘했어요.\n");
    
    }
    else if (total > 60) {
        printf("정당히 잘 했어요 \n");
    }
    else {
        printf("시험을 다시 치세요.\n");
        scanf("%d %d %d", &num1, &num2, &num3);
        if ((num1 + num2 + num3) / 3 < 60) {
            printf("실격 입니다.\n");
        }
        else {
            printf("재시험 합격입니다. \n");
        }


    }

}