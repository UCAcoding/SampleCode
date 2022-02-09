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


int main() {

    switch_a();
} 


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
