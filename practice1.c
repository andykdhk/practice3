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
void strType();



void p1main()
{
	
	strType();
	
}
void strType()
{
	char str1 = 'a';//changeable;
	char str2[6] = "World";//changeable;
	const char* str3 = "Hello";//not changeable; so const; address keep changing; read-only memory;
	char* str4 = malloc(sizeof(char) * 20);//changeable; heap; not read-only; str4[0] = 'a';//dereferencing explain at bottom.
	strcpy(str4, "sibal nom a3");
	

	printf("%s \n",str3);
	//printf("%s %s\n", str3, str2);


	free(str4);
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
	char *str = malloc(sizeof(char) * 10);// malloc does not work at .cpp file since c++ compiler does not support
	
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
	char *str2 = "sibal nom a2"; // address keep changing so does not work
	char* str3 = malloc(sizeof(char) * 20);
	strcpy(str3,"sibal nom a3");

	/*split*********************/
	char* ptr = strtok(str3," ");
	while (ptr != NULL)
	{
		printf("%s \n",ptr);
		ptr = strtok(NULL, " ");
	}
	/**********************split*/

	free(str3);
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

/*
A pointer references a location in memory, 
and obtaining the value at the location a pointer refers to is known as dereferencing the pointer.

*/