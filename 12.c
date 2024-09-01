/*
===================================================================================
Name : 12.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to find out the opening mode of a file. Use fcntl.
===================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
        char fname[50];
        printf("Enter file name\n");
	scanf("%s",fname);
        int fd = open(fname, O_RDWR);
        if (fd<0)
        {
                printf("File does not exist!\n");
                return 0;
        }
	printf("File access mode:%d\n",fcntl(fd,F_GETFL));
	int cl = close(fd);
	return 0;
}

/*
Enter file name
3.c
File access mode:32770
*/
