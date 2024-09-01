/*
===================================================================================
Name : 15.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to display the environmental variable of the user.
===================================================================================
*/


#include<stdlib.h>
#include<stdio.h>

int main()
{
	char* user = getenv("USER");
	if (user == NULL)
	{
		printf("Error");
	}
	else
	{
		printf("Environmental variable for user is: %s\n",user);
	}

	return 0;
}

//Environmental variable for user is: lazyuser

