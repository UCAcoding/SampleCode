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



int main() {
    switch_a();
} 


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

        if (0 >= input || 10 < input) {
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
        break;
    case 3:
        printf("for�� �Լ� ����\n\n");
        delay(1000);  //1�� ���� 
        clrscr();  //ȭ�� ����� 
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