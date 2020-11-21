/*
File: practice3.c
Date: Nov 20, 2020
Name: Andrew Kang
Goal:


*/
#pragma warning(disable: 4996)



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum TYPE {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT
};


void swapValue(void* ptr1, void* ptr2, enum TYPE t);
void allocMemory(void** ptr, int size);
void helloString(char* s1);
void printArray(int* arr, int count);
void print2DArray(int arr[][5], int col, int row);



void p3main()
{
	printf("PRACTICE 3 \n");


    /********************************************************************************************************/
    /*
    char c1 = 'a';
    char c2 = 'b';
    swapValue(&c1, &c2, TYPE_CHAR);       // 변수의 메모리 주소와 TYPE_CHAR를 넣음
    printf("%c %c\n", c1, c2);            // b a: swapValue에 의해서 값이 서로 바뀜

    int num1 = 10;
    int num2 = 20;
    swapValue(&num1, &num2, TYPE_INT);   // 변수의 메모리 주소와 TYPE_INT를 넣음
    printf("%d %d\n", num1, num2);       // 20 10: swapValue에 의해서 값이 서로 바뀜

    float num3 = 1.234567f;
    float num4 = 7.654321f;
    swapValue(&num3, &num4, TYPE_FLOAT);  // 변수의 메모리 주소와 TYPE_FLOAT를 넣음
    printf("%f %f\n", num3, num4);        // 7.654321f 1.234567: 
    */                                    // swapValue에 의해서 값이 서로 바뀜

    /********************************************************************************************************/

    long long* numPtr;

    // 단일 포인터 long long *numPtr의 메모리 주소는 long long **와 같음, 할당할 크기도 넣음 
    allocMemory((void**)&numPtr, sizeof(long long));

    *numPtr = 10;
    printf("%lld\n", *numPtr);

    free(numPtr);    // 동적 메모리 해제

    

    /********************************************************************************************************/
    /*
    char s1[10] = "world!";   // 배열 형태의 문자열

    helloString(s1);
    helloString("world!");
    */


    /*
    int numArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    printArray(numArr, sizeof(numArr) / sizeof(int));    // 배열과 요소의 개수를 넣음


    int numArr2[2][5] = {
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 10 }
    };

    int col = sizeof(numArr2[0]) / sizeof(int);      // 5: 2차원 배열의 가로 크기를 구할 때는 
                                                    // 가로 한 줄을 요소의 크기로 나눠줌

    int row = sizeof(numArr2) / sizeof(numArr2[0]);   // 2: 2차원 배열의 세로 크기를 구할 때는 
                                       // 배열이 차지하는 공간을 가로 한 줄의 크기로 나눠줌

    print2DArray(numArr2, col, row);    // 2차원 배열과 가로, 세로 크기를 넣음

    */





}

void swapValue(void* ptr1, void* ptr2, enum TYPE t)    // 반환값 없음, void 포인터 매개변수 두 개와
{                                                      // 변수의 자료형을 알려줄 열거형을 받음
    switch (t)
    {
    case TYPE_CHAR:    // 문자면 char *로 변환한 뒤 역참조하여 값을 서로 바꿈
    {
        char temp;
        temp = *(char*)ptr1;
        *(char*)ptr1 = *(char*)ptr2;
        *(char*)ptr2 = temp;
        break;
    }
    case TYPE_INT:     // 정수면 int *로 변환한 뒤 역참조하여 값을 서로 바꿈
    {
        int temp;
        temp = *(int*)ptr1;
        *(int*)ptr1 = *(int*)ptr2;
        *(int*)ptr2 = temp;
        break;
    }
    case TYPE_FLOAT:    // 실수면 float *로 변환한 뒤 역참조하여 값을 서로 바꿈
    {
        float temp;
        temp = *(float*)ptr1;
        *(float*)ptr1 = *(float*)ptr2;
        *(float*)ptr2 = temp;
        break;
    }
    }
}

void allocMemory(void** ptr, int size)    // 반환값 없음, void 이중 포인터 매개변수 지정
{
    *ptr = malloc(size);    // void **ptr을 역참조하여 void *ptr에 메모리 할당
}


void helloString(char* s1)    // 반환값 없음, char 포인터 매개변수 한 개 지정
{
    printf("Hello, %s\n", s1);    // Hello, 와 매개변수를 조합하여 문자열 출력
}



void printArray(int* arr, int count)    // 매개변수를 포인터로 지정하여 배열을 받음
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}


void print2DArray(int arr[][5], int col, int row)    // 2차원 배열의 포인터와 가로, 세로 크기를 받음
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }
}