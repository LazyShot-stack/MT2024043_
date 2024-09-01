/*
============================================================================
Name : 4.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to open existing file in read write mode.
              Try O_EXCL flag also.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	char fname[50];
	printf("Enter file name\n");
	scanf("%s",fname);
        int fd = open(fname,O_EXCL | O_RDWR);
        if(fd<0)
        {
                perror("ALERT!!! Error in Opening File\n");
        }
        else
        {
                printf("File opened Successfully\n");
                printf("File descriptor: %d\n",fd);
        }
        return 0;
}

/*
Enter file name
3.c
File opened Successfully
File descriptor: 3

*/


