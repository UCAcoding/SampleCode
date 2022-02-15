#include <stdio.h>

void select() {
	int input;
	scanf("%d", &input);
	switch (input) {
	case 1:
		printf("if문 \n");
		if_func();
		break;
	case 2:
		printf("for문 \n");
		for_func();
		break;
	case 3:
		printf("struct문 \n");
		struct_func();
		break;
	case 4:
		printf("동적 할당 \n");
		malloc_func();
		break;
	default:
		printf("잘못된 값을 입력하셨습니다. ");
	}
}


void if_func() {
	int i;
	scanf("%d", &i);

}void for_func() {

}

void struct_func() {

}

void malloc_func() {

}