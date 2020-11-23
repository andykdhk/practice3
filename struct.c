/*
File: struct.c
Date: Nov 22, 2020
Name: Andrew Kang
Goal:
*/
#pragma warning(disable: 4996)

#include <stdio.h>
#include <string.h>



struct Person {            // 구조체 정의
    char name[20];         // 구조체 멤버 
    int age;              
    char address[100];     
};


typedef struct _Monster {   
    char name[20];          
    int age;                   
    char address[100];       
} Monster;

//1*
typedef struct {   // 구조체 이름이 없는 익명 구조체
    char name[20];        
    int age;              
    char address[100];    
} Fairy;          


struct Data {
    char c1;
    int* numPtr;    // 포인터
};

struct Person getPerson(struct Person p)    // Person 구조체를 반환하는 getPerson 함수 정의
{

    strcpy(p.name, "bb");
    p.age = 20;
    strcpy(p.address, "bbbc");

    return p;    // 구조체 변수 반환
}

void setPerson(struct Person* p)    // 반환값 없음, 구조체 포인터 매개변수 한 개 지정
{
    // 매개변수로 받은 포인터에서 구조체 멤버의 값 변경
    strcpy(p->name, "ccc");
    p->age = 40;
    strcpy(p->address, "ccc");
}

void struct_main()
{
    
    struct Person p1;     // 구조체 변수 선언
    
    //put info
    strcpy(p1.name, "Andy");
    p1.age = 30;
    strcpy(p1.address, "xxx-440");
    /*
    //get info
    printf("Name: %s\n", p1.name);       
    printf("Age: %d\n", p1.age);        
    printf("Address: %s\n", p1.address);   

    */
    /***************************************************************/
    //new struct var
    /*
    Monster m1;
    
    strcpy(m1.name, "Candy");
    m1.age = 50;
    strcpy(m1.address, "xxx-440");

    //get info
    printf("Nmae: %s\n", m1.name);
    printf("Age: %d\n", m1.age);
    printf("Address: %s\n", m1.address);
    */
    /****************************************************************/
    /*
    struct Person* p1 = malloc(sizeof(struct Person));    // 구조체 포인터 선언, 메모리 할당

    //put info
    strcpy(p1->name, "홍길동");
    p1->age = 30;
    strcpy(p1->address, "서울시 용산구 한남동");

    //get info
    printf("이름: %s\n", p1->name);       // 홍길동
    printf("나이: %d\n", p1->age);        // 30
    printf("주소: %s\n", p1->address);    // 서울시 용산구 한남동

    free(p1); 
    */



    /*****************************************************************/
    /*
    int num1 = 10;

    struct Data* d2 = malloc(sizeof(struct Data));    // 구조체 포인터에 메모리 할당

    d2->numPtr = &num1;

    printf("%d\n", *d2->numPtr);    // 10: 구조체 포인터의 멤버를 역참조

    d2->c1 = 'a';
    printf("%c\n", (*d2).c1);      //  a: 구조체 포인터를 역참조하여 c1에 접근
                                   // d2->c1과 같음
    printf("%d\n", *(*d2).numPtr); // 10: 구조체 포인터를 역참조하여 numPtr에 접근한 뒤 다시 역참조
                                   // *d2->numPtr과 같음

    free(d2);
    */
    /***********************************************************************************/
    /* 3*
    struct Person p1;      // 구조체 변수 선언
    struct Person* ptr;    // 구조체 포인터 선언

    ptr = &p1;    // p1의 메모리 주소를 구하여 ptr에 할당

    // 화살표 연산자로 구조체 멤버에 접근하여 값 할당
    ptr->age = 30;

    printf("나이: %d\n", p1.age);      // 나이: 30: 구조체 변수의 멤버 값 출력
    printf("나이: %d\n", ptr->age);    // 나이: 30: 구조체 포인터의 멤버 값 출력
    */


    /***********************************************************************************/
    /*4*
    struct Person p2;
    p2 = getPerson(p1);
    // getPerson에서 저장한 값이 출력됨
    printf("Name: %s\n", p2.name);
    printf("Age: %d\n", p2.age);
    printf("Address: %s\n", p2.address);
    */

    /************************************************************************************/
 
    
    setPerson(&p1);
    printf("Name: %s\n", p1.name);
    printf("Age: %d\n", p1.age);
    printf("Address: %s\n", p1.address);

}





/*
1. typedef
typedef 구조체 별칭을 정의할 때 매번 구조체 이름을 지정해주려니 이것도 꽤 번거롭습니다.
이때는 익명 구조체(anonymous structure)를 사용하면 구조체 이름을 지정하지 않아도 됩니다.
즉, typedef로 구조체를 정의하면서 이름을 생략할 수 있습니다.
*/

/*
2. pointer
보통 구조체는 멤버 변수가 여러 개 들어있어서 크기가 큰 편입니다. 
그래서 구조체 변수를 일일이 선언해서 사용하는 것보다는 포인터에 
메모리를 할당해서 사용하는 편이 효율적입니다.

*/

/*
3. struct pointer
 그럼 동적 메모리를 할당하지 않고 구조체 포인터를 사용하는 방법은 없을까요? 
이때는 구조체 변수에 & (주소 연산자)를 사용하면 됩니다.
*/

/*
4. struct function

have struct argumnet(type local var and pointer)
have struct return


*/