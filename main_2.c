#include <stdio.h>

void select() {
	int input;
	scanf("%d", &input);
	switch (input) {
	case 1:
		printf("if�� \n");
		if_func();
		break;
	case 2:
		printf("for�� \n");
		for_func();
		break;
	case 3:
		printf("struct�� \n");
		struct_func();
		break;
	case 4:
		printf("���� �Ҵ� \n");
		malloc_func();
		break;
	default:
		printf("�߸��� ���� �Է��ϼ̽��ϴ�. ");
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