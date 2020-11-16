/*
File: practice1.cpp
Date: Nov 13, 2020
Name: Andrew Kang
Goal:
study:

*/
#pragma warning(disable: 4996)

#include<stdio.h>
#include<stdlib.h>


void input1();
void input2();
void input3();
void input4();

void p1main()
{

	//printf("type two words that you want to combine");
	/*
	const char *str1 = "Hello";
	char str2[6] = "World";
	printf("%s %s\n",str1,str2);
	*/

	//input1();
	input4();
	//input3();
}

void input1()
{
	char str3[10];
	printf("type a word: \n");
	int err = scanf("%s",str3);
	
	printf("ouput:%s\n",str3);
	fflush(stdin);

}

void input2()
{
	char str[10];
	printf("type two words: \n");
	int err = scanf("%[^\n]s", str);

	printf("ouput:%s\n", str);
	fflush(stdin);

}

void input3()
{
	char *str = malloc(sizeof(char) * 10);// does not work at .cpp file since c++ compiler does not support
	
	printf("type words: \n");
	int err = scanf("%s", str);

	printf("ouput:%s\n", str);
	fflush(stdin);
	free(str);

}

void input4()
{
	char str[10];
	printf("type words: \n");
	fgets(str,10,stdin);

	printf("ouput:%s\n", str);

}




void combineStr()
{




}

/*
1. 3 different types of inputs
scanf- useful for word but not for something contain space
	 - abc\0 
gets- do not use since does not have string size limit
	- abc\n\0
	- abc\0
fgets- recommend this one.
	 - abc\n\0


*/
