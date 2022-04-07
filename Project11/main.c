#include <stdio.h>

double averate();
int input_data();

//전역 변수 선 
int count = 0;  //공유 intput.c파일과 공유
static int total = 0;  //이 전역변수는 오직 main함수에만 존재 


int main() {

    double avg; //


   total =  input_data();
   avg = averate();
   printf("평균값은 %.2lf입니다.", avg);
}

