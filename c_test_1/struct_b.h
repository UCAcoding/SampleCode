#pragma once

#include <stdio.h>
          // 0   1   2   3   4 
enum e_num {aaa,bbb,ccc,ddd,eee};

typedef int ��Ʈ;

//Ÿ���� �ٽ� ���� �Ѵ�. 
typedef struct list_a
{
    int num;
    //�ڱ� ���� ����ü 
    struct list_a* next;


}list;

void struct_b() {
    
    list a = { 10,0 };  //0�� �ּҸ� ���� �ʰڴٴ� �ǹ� 
    list b = { 30,0 };
    list c = { 40,0 };

    list* head = &a;
    list* *current;

    //10��� 
    //�ڷ� ����
    a.next = &b;
    b.next = &c;
    //���� ����Ʈ 
    //a�� ��
    printf("%d", head->num);  //a.num�� ���� ����϶�. 
    //b�� ��
    printf("%d", head->next->num);  //a.next�� ���� ����϶�. 
    //c�� �� 
    printf("%d", head->next->next->num);  //a.next�� ���� ����϶�. 

}


//����ü 
void struct_c() {
    //�޸� �Ƴ���
    union student {
        int num;
        double grade;
    };

    union student s1 = { 100};
    //�̶� double grade ��� ������ �� �� ����. 
    printf("%d \n", s1.num);

    s1.grade = 3.14;
    //s1.grade�� �� �� �ִ�. 
    printf("%.2lf \n", s1.grade);
    //����� ����� ���� �ʴ´�. 
    printf("%d \n", s1.num);





}
