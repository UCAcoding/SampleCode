//표준 입출력 헤더파일 printf, scanf, 
#include <stdio.h>
#include <Windows.h>  //sleep, cls,
//각종 윈도우 명령어 
#include <stdlib.h>  //동적 할당 
//malloc, realloc, calloc

void app_run();
void if_a();



int main() {
    
    while (1) {
        app_run();
    }
    return 0;
}



void app_run() {
    //4바이트 
    int input; //정수형 변수 
    
    printf("숫자를 입력하세요\n");
    Sleep(1000); //1초간 쉬었다.
    printf("1~4까지 입력하세요\n");

    scanf("%d", &input);

    switch (input)
    {
    case 1:
        printf("if문 함수입니다.\n ");
        if_a();  //
        break;
    case 2:
        printf("2번 입니다. ");
        break;
    case 3:
        printf("3번 입니다. ");
        break;
    case 4:
        printf("4번 입니다. ");
        break;
    default:  //위 case에 없는 숫자를 입력했을때, default아래의 코드가 실행된다. 
        printf("%d는 잘못된 숫자입니다.", input);

        break;
    }

}



void if_a() {

    
    int num;

    printf("배열의 크기를 정하세요 : ");
    scanf("%d", &num);

    //쉽게 얘기 해서 배열 만드는 명령어 
    int*pnum = (int*)malloc(sizeof(int) * num);
    int total = 0;
    
    for (int i = 0; i < num; i++) {

        scanf("%d", &pnum[i]);
        total += pnum[i];
    }

    printf("총점은 %d이고 \n", total);

    double avg = (double)total / num;

    printf("평균 값은 %.2lf", avg);

    if (avg > 80) {

        printf("참 잘했어요! 짝짝짝\n");

    }
    else if (avg > 60) {

        printf("조금 잘했어요! 짝\n");

    }
    else if (avg > 50) {

        printf("더 조금 잘했어요!\n");

    }
    else {
        printf("낙제!");

    }



}
