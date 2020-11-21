/*
File: practice2.c
Date: Nov 18, 2020
Name: Andrew Kang
Goal: pointer return
*/
#pragma warning(disable: 4996)



#include <stdio.h>
#include<stdlib.h>
#include<string.h>



int* numPt();
char* rt1();
char* rt2();
void* mallocPtr();


void p2main()
{
	printf("PRACTICE 2 \n");


	/*int* num = numPt();
	printf("%d\n", *num);
	free(num);
	*/

	/*
	char* str;
	str = rt1();
	//str = rt2();

	printf("%s\n", str);
	//free(str);
	*/

	char* str = mallocPtr();
	strcpy(str, "hel lo");
	printf("[mallocPtr()]:%s \n",str);
	free(str);
	
	int* num = mallocPtr();
	num[0] = 10;
	printf("[mallocPtr()]:%d \n", num[0]);
	free(num);
	

	
}


/*
purpose: to return pointer must use dynamic allocation. 
because local var(stack) will disappear as soon as f() done
malloc(heap) wont done until free 
so
pointer return == malloc

*/

int* numPt()
{
	int* numPtr = malloc(sizeof(int));
	
	*numPtr = 10;
	return numPtr;
}
/*
purpose: to return pointer 

* char str[20] == local var == stack == ram(stack) section -> disappear as soon as f() done
* char* str ==  local var == stack == ram(stack) section
* "hello world" == read-only memory == rom(data) section
* return *str == send address of the read-only memory 
* return str[20] == can send address of the var, but that var will not exist there anymore.
* 
*so
* 
*  str[20] -> string stored in stack var
* *str -> just a pointer for read-only memory 
*/
char* rt1()
{
	//char str[20] = "hello world"; 
	char* str = "hello world";

	return str;
}
/*
* ram(heap) == possible
* str == just a pointer for heap memory
*/
char* rt2()
{
	char* str = malloc(sizeof(char) * 20);
	strcpy(str, "Hello, world!");
	return str;
}

void* mallocPtr()
{
	void* ptr = malloc(100);// 100 bytes
	return ptr;
}

