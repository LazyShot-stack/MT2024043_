/*
===================================================================================
Name : 18a.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to perform Record locking.
	      Implement write lock.
	      Implement read lock.
	      a.Create three records in a file.
===================================================================================
*/


#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
        struct flight{
                int ticket_count;
        };
        struct flight f[3];
        for(int i=0;i<3;i++)
        {
                f[i].ticket_count = 0;
        }
        int fd = open("Records.txt",O_RDWR);
        if (fd<0)
        {
                printf("Error in opening file\n");
                return 0;
        }
        int wcount;
        wcount = write(fd,&f,sizeof(f));
        close(fd);
        return 0;
}

