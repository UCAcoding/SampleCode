#include <stdio.h>

extern int count;
int total = 0;  //main함수의 total 공유 안함 

int input_data() {
    int pos;
      while (1) {
          printf("양수를 입력하세요. ");
          scanf("%d", &pos);
          if (pos < 0) {
              break;
          }
          count++;
          total += pos;
      }
      return total;  //main함수로 총햡 전달
}