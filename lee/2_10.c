#include <stdio.h>


void if_a();
void for_a();
void while_a();

//메인함수 
int main() {
   

    while_a();


    return 0;
}


void while_a() {

    int num;
    int total = 0;
    while (1) {
        printf("숫자를 입력하세요.\n 0을 입력하면 종료 됩니다. \n");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        total += num;

    }

    printf("총 합은 %d 입니다. \n", total);

}


void for_a() {
    int num;
    printf("반복할 횟수를 입력하세요 \n");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("%d번 반복합니다.\n", i);

    }

}


//함수의 정의 
void if_a() {
    //4바이트 정수형 변수 
    int a = 10;
    double b = 3.14; //8바이트 
    char c = 'a';  //

    scanf("%d", &a);


    if (a == 10) {
        printf("나이는 10살 입니다.");

    }
    else if (a == 9) {
        printf("나이는 10살 입니다.");

    }
    else if (a == 20) {

        printf("나이는 20살 입니다.");

    }
    else {

        printf("원하는 나이가 아닙니다.");
    }



}
