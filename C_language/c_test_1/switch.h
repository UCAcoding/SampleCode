#pragma once
//ǥ�� ����� ������� 
#include <stdio.h>
//���ڿ� ���� �������
#include <string.h>
//�޸� ���� �������
#include <stdlib.h>
//���� ���� ��ƿ��Ƽ
#include "curser.h"

//�Լ� ����, �Լ��� �����Լ��� �ε�Ǳ����� �˰� �ϱ� ���ؼ� 
void switch_a();
int if_a(int num);
void while_a();
void for_a();

void func();
void ary();
void pary(double* pd_ary, char** c_ary);
void static_a();
//�۷ι� ���� 
int g_num = 100;




void switch_a() {

    //int�� ���� 
    int input;

    ///if�� �Լ� ���� ���� 
    int if_return;
    int if_input;
    //////////////

    printf("�޴��� �����ϼ���\n");

    delay(1000);
    scanf("%d", &input);

    switch (input)
    {


    case 1:
        printf("if�� �Լ� ����\n\n");
        delay(1000);  //1�� ���� 
        clrscr();  //ȭ�� ����� 
        printf("���ڸ� �ϳ� �Է��ϼ���. 1~10���� \n");
        scanf("%d", &if_input);

        if ((0 > if_input) || (10 < if_input)) {
            printf("\n\n�߸��� �Է��Դϴ�. \n");
            printf("ó������ �ٽ� ���ּ��� \n");
        }
        else {
            if_return = if_a(if_input);
        }
        break;


    case 2:
        printf("while�� �Լ� ����\n\n");
        delay(1000);  //1�� ���� 
        clrscr();  //ȭ�� ����� 
        while_a();
        break;
    case 3:
        printf("for�� �Լ� ����\n\n");
        delay(1000);  //1�� ���� 
        clrscr();  //ȭ�� ����� 
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




//num == if_input�� ��
int if_a(int num) {
    //num�� �Էµ� �� ��ŭ ������ �Ҵ�. 
    int* num_p = (int*)malloc(sizeof(int) * num);  //4����Ʈ * num


    //�Ҵ翡 �����ϸ� NULL�����͸� ��ȯ 
    if (num_p == NULL) {
        printf(" �޸𸮰� �����մϴ�. \n");
        delay(500);
        printf("���� ���� �ϰڽ��ϴ�.\n");
        exit(1);
    }

    printf("%d ��ŭ ���ڸ� �Է��� �� �ּ���. \n\n", num);

    int total = 0;

    for (int i = 0; i < num; i++) {

        scanf("%d", &num_p[i]);
        total += num_p[i];
    }

    printf("�Է��� ���� ������ %d �Դϴ�. \n", total);
    printf("����� %.2lf �Դϴ�. \n", (double)total / num);

    free(num_p);
}


void while_a() {
    int num_count = 0;
    int num_input, num_cal;

    printf("���� �Է��ϼ��� :  ");
    scanf("%d", &num_input);

    num_cal = num_input;

    //�ڸ��� ����
    while (num_cal > 0) {
        num_count++;
        num_cal /= 10;

    }
    printf("�Է��� ���ڴ� %d �ڸ� ���� �Դϴ�. \n", num_count);


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
        printf("�ָ� �����ϴ�.");

    }
    else {
        printf("���� �����ϴ�.");
    }

}


void func() {

    //�۷ι� ������ ��𼭶� ������ �� �� �ִ�. 
    printf("�۷ι� ���� ��� %d \n", g_num);
    delay(2000);
    clrscr();
    //�������� == auto ���� ����. 


    auto int l_num = 10;
    l_num++;
    printf("���� ���� �� %d \n", l_num);
    //�Լ��� ��������� ���� �ִ� ���� 
    static int s_num = 0;
    s_num++;
    printf("����ƽ ������ %d \n", s_num);


}



void ary() {
    //1���� double�� �迭
    double d_ary[3] = { 1.1,2.2,3.3 };
    //2���� ���ڿ� �迭 == ���ڿ� �迭 ������ 
    char* c_ary[] = { "dog", "cat", "banana" };
    pary(d_ary, c_ary);
}


void pary(double* pd_ary, char** c_ary) {

    for (int i = 0; i < 3; i++) {

        printf("�Ҽ� ��� %.1lf \n", pd_ary[i]);
        printf("���� ��� %s \n", c_ary[i]);

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

    //������ ������ 
    printf("���� %d \n", (*p_num).kor);
    //����ü ������ ���� ->
    printf("���� %d \n", p_num->kor);

}
