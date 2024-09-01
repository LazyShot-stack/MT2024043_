/*
============================================================================
Name : 6.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program using sys calls to take input from STDIN and 
	      display on STDOUT.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
        int rcount,wcount;
	char inp[200];
	printf("Input:\n");
	rcount = read(0,&inp,200);
	wcount = write(1,&inp,rcount);
	return 0;
}

/*
Input:
hello I am Lazy user, test input for pragram 6.c
hello I am Lazy user, test input for pragram 6.c
*/
