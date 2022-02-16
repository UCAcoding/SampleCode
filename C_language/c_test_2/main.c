//표준 입출력 헤더파일 printf, scanf, 
#include <stdio.h>
#include <Windows.h>  //sleep, cls,
//각종 윈도우 명령어 
#include <stdlib.h>  //동적 할당 
//malloc, realloc, calloc
#include "curser.h"



void app_run();
void if_a();
void while_a();
void for_a();
void for_a_p(char** ary, int num);
void struct_a();
void print_list(struct address* plist);

struct address {
    char name[20]; //이름을 저장할 멤버
    int age; //나이 저장할 멤버 
    char tel[20];
    char addr[80];

};


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
        if_a();  //완성 
        break;
    case 2:
        printf("while 문 함수입니다. \n ");
        while_a();
        break;
    case 3:
        printf("for문 함수입니다. \n");
        for_a();
        break;
    case 4:
        printf("구조체 입니다. ");

        struct_a();
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
    int* pnum = (int*)malloc(sizeof(int) * num);
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
        printf("낙제!\n");
        Sleep(1000);
        printf("다시 한번 기회를 주마 \n");

        for (int i = 0; i < num; i++) {

            scanf("%d", &pnum[i]);
            total += pnum[i];
        }

        printf("총점은 %d이고 \n", total);

        double avg = (double)total / num;

        printf("평균 값은 %.2lf", avg);

        if (avg < 50) {
            printf("유급");
        }
        else {
            printf("잘했어~");

        }

    }

    //사용이 끝난 배열은 동적 할당 해제, **
    free(pnum);
}

void while_a() {

    int num;
    int input;

    //숫자 섞기
    randomize();

    //while(1)무한 반복 
    while (1) {
        //0~100까지의 숫자중에 랜덤으로 하나를 num에 넣는다. 
         num = random(100)+1;
         //자동 줄바꿈(엔터) 되는 출력 명령어 
         puts("내가 생각한 숫자 하나를 맞춰봐~~에벨렐레");
         
         //while과 완벽히 같은데, 단 하나 다른점은, while은 조건이 거짓이면
         //실행이 되지 않는 반면, do~while문은 1번은 무조건 실행이 됩니다. 
         do {
             printf("숫자를 입력하세요. 끝날때는 999입력 : ");
             scanf("%d", &input);

             if (input == 999) {
                 puts("3초후 프로그램을 종료 합니다.");
                 Sleep(3000);
                 exit(0); //프로그램 종료 명령어 
                 //while_a 함수를 종료 하고 싶으면 return 
             }
             if (input == num) {
                 puts("짜라잔!!\n");
                 puts("맞췄습니다.");
             }
             else if (input > num) {
                 printf("입력한 숫자가 너무 큽니다.\n");
             }
             else {

                 printf("입력한 숫자가 너무 작습니다.\n");
             }


         } while (input != num);



    }





}




void for_a() {

    //문자 2차원 배열 == 
    char* pary[] = { "banana", "apple", "tiger" };
    char* ppary[] = { "aaa", "bbb","cccc","ddd", "eeee", "fffff" };

    for_a_p(pary, 3);
    printf("두번째 \n");
    for_a_p(ppary, 6);
}

void for_a_p(char** ary, int num) {

    for (int i = 0; i < num; i++) {

        printf("%s \n", ary[i]);
    }

}



void struct_a() {
    //구조체 배열 선언 
    struct address list[5] = {  //1차원 배열 
        //이름   나이    전화번호    주소 
        {"이이이", 10, "111-1111", "울산 어디"},
        {"삼이이", 20, "211-1111", "양산 어디"},
        {"사이이", 30, "311-1111", "서산 어디"},
        {"오이이", 40, "411-1111", "저산 어디"},
        {"육이이", 50, "511-1111", "우리산 어디"}
    };


    print_list(list);
}

                              //1차원 포인터고 포인터는 4바이트
void print_list(struct address* plist) {

    for (int i = 0; i < 5; i++) {

        printf("%10s%5d%15s%20s \n", (plist+i)->name, (plist + i)->age,
            (plist+i)->tel, (plist + i)->addr );
    }



}
