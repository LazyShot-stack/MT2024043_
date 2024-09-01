/*
===================================================================================
Name : 13.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to wait for a STDIN for 10 seconds. Check if the 
	      data is available within 10 seconds.
===================================================================================
*/


#include<stdio.h>
#include<sys/select.h>

int main()
{
	fd_set fd;
	struct timeval t;
	t.tv_sec=10;
	t.tv_usec=0;
	FD_ZERO(&fd);
	FD_SET(0,&fd);
	int val = select(1,&fd,NULL,NULL,&t);
	if (val == 0)
	{
		printf("Input not entered in 10 seconds!\n");
		return 0;
	}
	else
	{
		printf("Input entered in 10 seconds\n");
	}
	return 0;
}

/* - i didnt entered input within 10 seconds
Input not entered in 10 seconds!
*/


