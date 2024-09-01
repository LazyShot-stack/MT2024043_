/*
==============================================================================
Name : 3.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to create file and print its descriptor value.
==============================================================================
*/


#include <stdio.h>
#include <fcntl.h>

int main()
{
	char fname[50];
	printf("Enter file name\n");
	scanf("%s",fname);
        int fd= creat(fname,O_CREAT);
        if(fd<0)
        {
                perror("ALERT!!! File not created\n");
        }

        else
        {
                printf("File created Successfully\n");
                printf("File descriptor: %d\n",fd);
        }
        return 0;
}

/*
Enter file name
new_file
File created Successfully
File descriptor: 3

*/
