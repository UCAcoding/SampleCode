#include <stdio.h>

extern int count;
int total = 0;  //main�Լ��� total ���� ���� 

int input_data() {
    int pos;
      while (1) {
          printf("����� �Է��ϼ���. ");
          scanf("%d", &pos);
          if (pos < 0) {
              break;
          }
          count++;
          total += pos;
      }
      return total;  //main�Լ��� ���u ����
}