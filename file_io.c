/*
File: file_io.c
Date: Nov 21, 2020
Name: Andrew Kang
Goal: 
*/
#pragma warning(disable: 4996)


#include <stdio.h>
#include <stdlib.h>    
#include <string.h> 


/*
fread:

    fread(buffer, sizeof(buffer) - 1, 1, stdin);    // 표준 입력(stdin)에서 문자열 읽기
                     // 버퍼 끝에 NULL이 들어갈 수 있도록 sizeof(buffer) - 1을 지정




fgets: 줄바꿈(\n)이 있으면 버퍼 크기와는 상관 없이 \n까지 문자열을 읽습니다(\n도 포함).
    fgets(buffer, sizeof(buffer), stdin);
   
*/
void read_file()
{
    char buffer[20] = { 0, };    // 파일을 읽을 때 사용할 임시 공간, 미리 0으로 전부 초기화

    FILE* fp = fopen("hello.txt", "r");     // hello.txt 파일을 읽기 모드로 열기.
                                            // 파일 포인터를 반환
    //opt1
      fread(buffer, sizeof(buffer), 1, fp);   // hello.txt에서 버퍼 크기(20바이트)만큼 1번 값을 읽음
    
    //opt2
    //fgets(buffer, sizeof(buffer), fp);    // hello.txt에서 문자열을 읽음

    printf("%s\n", buffer);    // Hello, world!: 파일의 내용 출력

    fclose(fp);    // 파일 포인터 닫기
}


void write_file()
{
    FILE* fp = fopen("hello2.txt", "w");     // hello.txt 파일을 쓰기 모드(w)로 열기.
                                                // 파일 포인터를 반환

    //opt1
     fprintf(fp, "%s %d\n", "Hello", 100);   // 서식을 지정하여 문자열을 파일에 저장

    //opt2
    //char* s1 = "Hello, world!";
    //fwrite(s1, strlen(s1), 1, fp);    // strlen으로 문자열의 길이를 구함.
                                      // 문자열의 길이만큼 1번 파일에 저장



    fclose(fp);    // 파일 포인터 닫기


}



void size_file()
{
    char* buffer;
    int size;
    int count;

    FILE* fp = fopen("hello.txt", "r");    // hello.txt 파일을 읽기 모드(r)로 열기.
                                           // 파일 포인터를 반환

    fseek(fp, 0, SEEK_END);    // 파일 포인터를 파일의 끝으로 이동시킴
    size = ftell(fp);          // 파일 포인터의 현재 위치를 얻음

    buffer = malloc(size + 1);    // 파일 크기 + 1바이트(문자열 마지막의 NULL)만큼 동적 메모리 할당
    memset(buffer, 0, size + 1);  // 파일 크기 + 1바이트만큼 메모리를 0으로 초기화

    fseek(fp, 0, SEEK_SET);                // 파일 포인터를 파일의 처음으로 이동시킴
    count = fread(buffer, size, 1, fp);    // hello.txt에서 파일 크기만큼 값을 읽음

    printf("%s size: %d, count: %d\n", buffer, size, count);
    // Hello world! size: 13, count: 1: 파일의 내용, 파일 크기, 읽은 횟수 출력

    fclose(fp);     // 파일 포인터 닫기

    free(buffer);   // 동적 메모리 해제


}