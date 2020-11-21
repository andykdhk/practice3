/*
File: pointer_reason.c
Date: Nov 20, 2020
Name: Andrew Kang
Goal: the fundamental of pointer.
why we use pointer.
*/

#pragma once
#pragma warning(disable: 4996)

#include <stdio.h>


int local_func(int);
void ptr_func(int*, float*);

void ptr_reason()
{
	int local_var = 10;
	
	int ptr_var = 10;
	float ptr_var2 = 10.45;

	
	int* ptr = &ptr_var;
	float* ptr2 = &ptr_var2;

	
	int ret_local_var = local_func(local_var);	
	ptr_func(ptr,ptr2);

	printf("local variable: %d \n", ret_local_var);


	printf("ptr variable: %d &f\n", ptr_var);

}

// can have only one type of return value.
int local_func(int a)
{
	a = 20;
	return a;
}


// does not have to return, so reduce work.
// can change different types of values by using one function. 
void ptr_func(int* a, float* b)
{

	*a = 110;
	*b = 111.7;
}
