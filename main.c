#include <stdio.h> //표준 입출력 함수 printf 

#define _CRT_SECURE_NO_WARNINGS //매크로 함수 scanf의 에러 표시가 나지 않게 한다

void select();
void if_func();
void for_func();
void struct_func();
void malloc_func();


int main() {
	while (1) {
		select();
	}
}
