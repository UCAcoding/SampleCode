#include <stdio.h>

double averate();
int input_data();

//���� ���� �� 
int count = 0;  //���� intput.c���ϰ� ����
static int total = 0;  //�� ���������� ���� main�Լ����� ���� 


int main() {

    double avg; //


   total =  input_data();
   avg = averate();
   printf("��հ��� %.2lf�Դϴ�.", avg);
}

