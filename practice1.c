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
void strSplit();

void p1main()
{

	//printf("type two words that you want to combine");
	/*
	const char *str1 = "Hello";
	char str2[6] = "World";
	printf("%s %s\n",str1,str2);
	*/
	
	strSplit();
	
}
/**************************************************************************************char[] + one word + scanf*/
void input1()
{
	int err2 = getchar();// fflush(stdin) not working in gcc 
	char str3[10];
	printf("type a word: \n");
	int err = scanf("%s",str3);
	
	printf("ouput:%s\n",str3);
}
/**************************************************************************************char[] + setence + scanf*/
void input2()
{
	int err2 = getchar();
	char str[10];
	printf("type two words: \n");
	int err = scanf("%[^\n]s", str);

	printf("ouput:%s\n", str);
}
/**************************************************************************************char * + scanf*/
void input3()
{
	int err2 = getchar();
	char *str = malloc(sizeof(char) * 10);// does not work at .cpp file since c++ compiler does not support
	
	printf("type words: \n");
	int err = scanf("%s", str);

	printf("ouput:%s\n", str);
	free(str);
}
/**************************************************************************************char[] + fgets*/
void input4()
{
	int err = getchar();
	char str[10];
	printf("type words: \n");
	fgets(str,10,stdin);
	printf("ouput:%s\n", str);
}

void strSplit()
{
	char str[20] = "sibal nom a";

	char* ptr = strtok(str," ");

	while (ptr != NULL)
	{
		printf("%s \n",ptr);
		ptr = strtok(NULL, " ");
	
	}

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

// fflush(stdin) not working in gcc 

/*
ptr = strtok(NULL, " ");

1. sibal nom a //search space
2. sibal\0nom a//replace \0 
3. ptr = sibal\0
   str = nom a\0
4. nom\0a\0
   ptr = nom\0
   str = a\0

*/