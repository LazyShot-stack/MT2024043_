/*
==================================================================================
Name : 5.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to create five new files with infinite loop.
              Execute in background and check file descriptors in /proc directory.
==================================================================================
*/


#include<stdio.h>
#include<fcntl.h>
int main()
{
        int fd1 = open("f1.txt",O_CREAT | O_RDWR | O_EXCL, 0644);
        int fd2 = open("f2.txt",O_CREAT | O_RDWR | O_EXCL, 0644);
        int fd3 = open("f3.txt",O_CREAT | O_RDWR | O_EXCL, 0644);
        int fd4 = open("f4.txt",O_CREAT | O_RDWR | O_EXCL, 0644);
        int fd5 = open("f5.txt",O_CREAT | O_RDWR | O_EXCL, 0644);
        if(fd1<0)
        {
                perror("f1.txt not created");
        }
        else
        {
                printf("f1.txt created successfully");
        }
        if(fd2<0)
        {
                perror("f2.txt not created");
        }
        else
        {
                printf("f2.txt created successfully");
        }
        if(fd3<0)
        {
                perror("f3.txt not created");
        }
        else
        {
                printf("f3.txt created successfully");
        }
        if(fd4<0)
        {
                perror("f4.txt not created");
        }
        else
        {
                printf("f4.txt created successfully");
        }
        if(fd5<0)
        {
                perror("f5.txt not created");
        }
        else
	{
                printf("f5.txt created successfully");
        }
	while(1)
        {
        }
        return 0;
}

//42833
/*
f1.txt not created: File exists
f2.txt not created: File exists
f3.txt not created: File exists
f4.txt not created: File exists
f5.txt not created: File exists

*/
