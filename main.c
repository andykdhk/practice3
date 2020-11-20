/*
File: main.cpp
Date: Nov 13, 2020
Name: Andrew Kang
Goal: 
study:

*/
#pragma warning(disable: 4996)

#include "practice1.h"
#include "practice2.h"
#include<stdio.h>


int main(void)
{
	int menu;
	int retMenu;

	while (1)
	{
		printf("[0]:EXIT \n");
		printf("[1]string handling: \n");
		printf("[2]function handling: \n");

		retMenu = scanf("%d", &menu);
		if (retMenu == 0)
		{
			printf("ERROR: MENU SELECTION\n");
			return 0;
		}
		fflush(stdin);
	
		switch (menu)
		{
			case 1:

				p1main();
				break;

			case 2:
			
				p2main();
				break;

			case 0:

				printf("BYE \n");
				return 0;
			
			default:
				printf("ERROR: selection does not exist \n");
				break;
		}
	
	}
	return 0;
}