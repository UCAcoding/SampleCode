#include <stdio.h>
#include <conio.h> //Ű���� �Է� ��� 
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
    printf("���α׷� �����\n");
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

    printf("�޴��� �����ϼ���.\n");
    printf("===============+\n");
    printf("1. if �Լ� ���� \n");
    printf("2. for �Լ� ���� \n");
    printf("3. while �Լ� ���� \n");
    printf("===============+\n");
    delay(2000);
    clrscr();
    int input;
    scanf("%d", &input);


    switch (input) {
    case 1:
        PrintString(hStdOut, BLUE, "if�� ����");
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
    printf("������ 3�� �Է��� �ּ���\n");
    scanf("%d %d %d", &num1, &num2, &num3);
    int total = (num1 + num2 + num3) / 3;

    if (total > 80) {
        printf("�� ���߾��.\n");
    
    }
    else if (total > 60) {
        printf("������ �� �߾�� \n");
    }
    else {
        printf("������ �ٽ� ġ����.\n");
        scanf("%d %d %d", &num1, &num2, &num3);
        if ((num1 + num2 + num3) / 3 < 60) {
            printf("�ǰ� �Դϴ�.\n");
        }
        else {
            printf("����� �հ��Դϴ�. \n");
        }


    }

}