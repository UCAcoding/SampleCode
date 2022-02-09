#pragma once

#include <stdio.h>
          // 0   1   2   3   4 
enum e_num {aaa,bbb,ccc,ddd,eee};

typedef int 인트;

//타입을 다시 정의 한다. 
typedef struct list_a
{
    int num;
    //자기 참조 구조체 
    struct list_a* next;


}list;

void struct_b() {
    
    list a = { 10,0 };  //0은 주소를 넣지 않겠다는 의미 
    list b = { 30,0 };
    list c = { 40,0 };

    list* head = &a;
    list* *current;

    //10출력 
    //자료 구조
    a.next = &b;
    b.next = &c;
    //연결 리스트 
    //a의 값
    printf("%d", head->num);  //a.num의 값을 출력하라. 
    //b의 값
    printf("%d", head->next->num);  //a.next의 값을 출력하라. 
    //c의 값 
    printf("%d", head->next->next->num);  //a.next의 값을 출력하라. 

}


//공용체 
void struct_c() {
    //메모리 아낄때
    union student {
        int num;
        double grade;
    };

    union student s1 = { 100};
    //이때 double grade 멤버 변수는 쓸 수 없다. 
    printf("%d \n", s1.num);

    s1.grade = 3.14;
    //s1.grade만 쓸 수 있다. 
    printf("%.2lf \n", s1.grade);
    //제대로 출력이 되지 않는다. 
    printf("%d \n", s1.num);





}
