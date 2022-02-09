#pragma once
//표준 입출력 헤더파일 
#include <stdio.h>
//문자열 관련 헤더파일
#include <string.h>
//메모리 관련 헤더파일
#include <stdlib.h>
//각종 편의 유틸리티
#include "curser.h"

//함수 선언, 함수가 메인함수가 로드되기전에 알게 하기 위해서 
void switch_a();
int if_a(int num);
void while_a();
void for_a();

void func();
void ary();
void pary(double* pd_ary, char** c_ary);
void static_a();
//글로벌 변수 
int g_num = 100;




void switch_a() {

    //int형 변수 
    int input;

    ///if문 함수 관련 변수 
    int if_return;
    int if_input;
    //////////////

    printf("메뉴를 선택하세요\n");

    delay(1000);
    scanf("%d", &input);

    switch (input)
    {


    case 1:
        printf("if문 함수 실행\n\n");
        delay(1000);  //1초 쉬고 
        clrscr();  //화면 지우고 
        printf("숫자를 하나 입력하세요. 1~10까지 \n");
        scanf("%d", &if_input);

        if ((0 > if_input) || (10 < if_input)) {
            printf("\n\n잘못된 입력입니다. \n");
            printf("처음부터 다시 해주세요 \n");
        }
        else {
            if_return = if_a(if_input);
        }
        break;


    case 2:
        printf("while문 함수 실행\n\n");
        delay(1000);  //1초 쉬고 
        clrscr();  //화면 지우고 
        while_a();
        break;
    case 3:
        printf("for문 함수 실행\n\n");
        delay(1000);  //1초 쉬고 
        clrscr();  //화면 지우고 
        for_a();
        break;

    case 4:
        func();
        func();
        func();
        break;

    case 5:
        ary();
        break;
    case 6:
        static_a();
        break;

    default:
        break;
    }

}




//num == if_input의 값
int if_a(int num) {
    //num에 입력된 수 만큼 공간을 할당. 
    int* num_p = (int*)malloc(sizeof(int) * num);  //4바이트 * num


    //할당에 실패하면 NULL포인터를 반환 
    if (num_p == NULL) {
        printf(" 메모리가 부족합니다. \n");
        delay(500);
        printf("강제 종료 하겠습니다.\n");
        exit(1);
    }

    printf("%d 만큼 숫자를 입력을 해 주세요. \n\n", num);

    int total = 0;

    for (int i = 0; i < num; i++) {

        scanf("%d", &num_p[i]);
        total += num_p[i];
    }

    printf("입력한 값의 총합은 %d 입니다. \n", total);
    printf("평균은 %.2lf 입니다. \n", (double)total / num);

    free(num_p);
}


void while_a() {
    int num_count = 0;
    int num_input, num_cal;

    printf("숫자 입력하세요 :  ");
    scanf("%d", &num_input);

    num_cal = num_input;

    //자리수 계산기
    while (num_cal > 0) {
        num_count++;
        num_cal /= 10;

    }
    printf("입력한 숫자는 %d 자리 숫자 입니다. \n", num_count);


}


void for_a() {

    clrscr();
    int num;
    scanf("%d", &num);


    for (int i = 1; i < num; i++) {
        gotoxy(i, 10);
        putch('#');
        gotoxy(i - 1, 10);
        putch(' ');
        delay(100);
    }

    if (num > 40) {
        printf("멀리 갔습니다.");

    }
    else {
        printf("조금 갔습니다.");
    }

}


void func() {

    //글로벌 변수는 어디서라도 영향을 줄 수 있다. 
    printf("글로벌 변수 출력 %d \n", g_num);
    delay(2000);
    clrscr();
    //지역변수 == auto 말은 뺀다. 


    auto int l_num = 10;
    l_num++;
    printf("지역 변수 값 %d \n", l_num);
    //함수가 사라지더라도 남아 있는 변수 
    static int s_num = 0;
    s_num++;
    printf("스태틱 변수값 %d \n", s_num);


}



void ary() {
    //1차원 double형 배열
    double d_ary[3] = { 1.1,2.2,3.3 };
    //2차원 문자열 배열 == 문자열 배열 포인터 
    char* c_ary[] = { "dog", "cat", "banana" };
    pary(d_ary, c_ary);
}


void pary(double* pd_ary, char** c_ary) {

    for (int i = 0; i < 3; i++) {

        printf("소수 출력 %.1lf \n", pd_ary[i]);
        printf("문자 출력 %s \n", c_ary[i]);

    }


}



void static_a() {

    struct num {
        int kor;
        int eng;
        int math;
    };

    struct num lee = { 90,80,70 };
    struct num* p_num = &lee;

    //포인터 연산방식 
    printf("국어 %d \n", (*p_num).kor);
    //구조체 포인터 연산 ->
    printf("국어 %d \n", p_num->kor);

}
