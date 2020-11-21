/*
File: pointer.c
Date: Nov 20, 2020
Name: Andrew Kang
Goal: the fundamental of pointer.
      this is why we use pointer.
*/


#include <stdio.h>


int local_func(int);
void ptr_func(int*, double*);

void ptrMain()
{
	int local_var = 10;

	int ptr_var = 10;
	double ptr_var2 = 10.45;


	int* ptr = &ptr_var;
	double* ptr2 = &ptr_var2;


	int ret_local_var = local_func(local_var);
	ptr_func(ptr, ptr2);

	printf("local variable: %d \n", ret_local_var);
	printf("ptr variable: %d %f\n", ptr_var, ptr_var2);

}

// can have only one return value.
int local_func(int a)
{
	a = 20;
	return a;
}


// does not have to have return, so reduce work.
// can change different types of values by using one function. 
void ptr_func(int* a, double* b)
{

	*a = 110;
	*b = 111.7;
}
