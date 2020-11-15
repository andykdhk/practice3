/*
File: practice1.cpp
Date: Nov 13, 2020
Name: Andrew Kang
Goal:
study:

*/
#pragma warning(disable: 4996)

#include<stdio.h>

void iostr();
void iostr2();

void p1main()
{

	//printf("type two words that you want to combine");
	/*
	const char *str1 = "Hello";
	char str2[6] = "World";
	printf("%s %s\n",str1,str2);
	*/

	//iostr();
	iostr2();
}

void iostr()
{
	char str3[10];
	printf("type a word: \n");
	int err = scanf("%s",str3);
	
	printf("ouput:%s\n",str3);
	fflush(stdin);

}

void iostr2()
{
	char str[15];
	printf("type two words: \n");
	int err = scanf("%[^\n]s", str);

	printf("ouput:%s\n", str);
	fflush(stdin);

}






void combineStr()
{




}