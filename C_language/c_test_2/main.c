//ǥ�� ����� ������� printf, scanf, 
#include <stdio.h>
#include <Windows.h>  //sleep, cls,
//���� ������ ��ɾ� 
#include <stdlib.h>  //���� �Ҵ� 
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
    char name[20]; //�̸��� ������ ���
    int age; //���� ������ ��� 
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
    //4����Ʈ 
    int input; //������ ���� 

    printf("���ڸ� �Է��ϼ���\n");
    Sleep(1000); //1�ʰ� ������.
    printf("1~4���� �Է��ϼ���\n");

    scanf("%d", &input);

    switch (input)
    {
    case 1:
        printf("if�� �Լ��Դϴ�.\n ");
        if_a();  //�ϼ� 
        break;
    case 2:
        printf("while �� �Լ��Դϴ�. \n ");
        while_a();
        break;
    case 3:
        printf("for�� �Լ��Դϴ�. \n");
        for_a();
        break;
    case 4:
        printf("����ü �Դϴ�. ");

        struct_a();
        break;
    default:  //�� case�� ���� ���ڸ� �Է�������, default�Ʒ��� �ڵ尡 ����ȴ�. 
        printf("%d�� �߸��� �����Դϴ�.", input);

        break;
    }

}



void if_a() {


    int num;

    printf("�迭�� ũ�⸦ ���ϼ��� : ");
    scanf("%d", &num);

    //���� ��� �ؼ� �迭 ����� ��ɾ� 
    int* pnum = (int*)malloc(sizeof(int) * num);
    int total = 0;

    for (int i = 0; i < num; i++) {

        scanf("%d", &pnum[i]);
        total += pnum[i];
    }

    printf("������ %d�̰� \n", total);

    double avg = (double)total / num;

    printf("��� ���� %.2lf", avg);

    if (avg > 80) {

        printf("�� ���߾��! ¦¦¦\n");

    }
    else if (avg > 60) {

        printf("���� ���߾��! ¦\n");

    }
    else if (avg > 50) {

        printf("�� ���� ���߾��!\n");

    }
    else {
        printf("����!\n");
        Sleep(1000);
        printf("�ٽ� �ѹ� ��ȸ�� �ָ� \n");

        for (int i = 0; i < num; i++) {

            scanf("%d", &pnum[i]);
            total += pnum[i];
        }

        printf("������ %d�̰� \n", total);

        double avg = (double)total / num;

        printf("��� ���� %.2lf", avg);

        if (avg < 50) {
            printf("����");
        }
        else {
            printf("���߾�~");

        }

    }

    //����� ���� �迭�� ���� �Ҵ� ����, **
    free(pnum);
}

void while_a() {

    int num;
    int input;

    //���� ����
    randomize();

    //while(1)���� �ݺ� 
    while (1) {
        //0~100������ �����߿� �������� �ϳ��� num�� �ִ´�. 
         num = random(100)+1;
         //�ڵ� �ٹٲ�(����) �Ǵ� ��� ��ɾ� 
         puts("���� ������ ���� �ϳ��� �����~~��������");
         
         //while�� �Ϻ��� ������, �� �ϳ� �ٸ�����, while�� ������ �����̸�
         //������ ���� �ʴ� �ݸ�, do~while���� 1���� ������ ������ �˴ϴ�. 
         do {
             printf("���ڸ� �Է��ϼ���. �������� 999�Է� : ");
             scanf("%d", &input);

             if (input == 999) {
                 puts("3���� ���α׷��� ���� �մϴ�.");
                 Sleep(3000);
                 exit(0); //���α׷� ���� ��ɾ� 
                 //while_a �Լ��� ���� �ϰ� ������ return 
             }
             if (input == num) {
                 puts("¥����!!\n");
                 puts("������ϴ�.");
             }
             else if (input > num) {
                 printf("�Է��� ���ڰ� �ʹ� Ů�ϴ�.\n");
             }
             else {

                 printf("�Է��� ���ڰ� �ʹ� �۽��ϴ�.\n");
             }


         } while (input != num);



    }





}




void for_a() {

    //���� 2���� �迭 == 
    char* pary[] = { "banana", "apple", "tiger" };
    char* ppary[] = { "aaa", "bbb","cccc","ddd", "eeee", "fffff" };

    for_a_p(pary, 3);
    printf("�ι�° \n");
    for_a_p(ppary, 6);
}

void for_a_p(char** ary, int num) {

    for (int i = 0; i < num; i++) {

        printf("%s \n", ary[i]);
    }

}



void struct_a() {
    //����ü �迭 ���� 
    struct address list[5] = {  //1���� �迭 
        //�̸�   ����    ��ȭ��ȣ    �ּ� 
        {"������", 10, "111-1111", "��� ���"},
        {"������", 20, "211-1111", "��� ���"},
        {"������", 30, "311-1111", "���� ���"},
        {"������", 40, "411-1111", "���� ���"},
        {"������", 50, "511-1111", "�츮�� ���"}
    };


    print_list(list);
}

                              //1���� �����Ͱ� �����ʹ� 4����Ʈ
void print_list(struct address* plist) {

    for (int i = 0; i < 5; i++) {

        printf("%10s%5d%15s%20s \n", (plist+i)->name, (plist + i)->age,
            (plist+i)->tel, (plist + i)->addr );
    }



}
