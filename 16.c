/*
===================================================================================
Name : 16.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to implement mandatory locking.
	      Implement read and write lock.
===================================================================================
*/


#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
        char fname[50];
        printf("Enter file name\n");
	scanf("%s",fname);
	struct flock rdlck;
	rdlck.l_whence = SEEK_SET;
	rdlck.l_start = 0;
	rdlck.l_len = 0;
	rdlck.l_pid = getpid();

        int fd = open(fname, O_RDWR);
        if (fd<0)
        {
                printf("File could not be opened\n");
                return 0;
        }
	char c;
	printf("Before Critical Section\n");
	printf("Read(R) or Write(W)?\n");
	scanf("%c",&c);
	if(c=='R')
	{
		rdlck.l_type = F_RDLCK;
	}
	else
	{
		rdlck.l_type = F_WRLCK;
	}
	int f = fcntl(fd,F_SETLKW,&rdlck);
	if( f<0)
        {
                printf("Could not perform locking\n");
        }
	else
        {
                printf("Lock Successfull\n");
        }
	printf("Enter Q to release lock\n");
	scanf("%c",&c);
	while(c!='Q')
	{
		scanf("%c",&c);
	}
	f = fcntl(0,F_GETLK,&rdlck);
	if( f<0)
        {
                printf("Could not perform unlocking\n");
        }
        else
        {
                printf("Unlock Successfull\n");
        }
	printf("Exit Critical Section\n");
	close(fd);
	return 0;
}

/* 
Enter file name
4.c
Before Critical Section
Read(R) or Write(W)?
Lock Successfull
Enter Q to release lock
Q
Unlock Successfull
Exit Critical Section



Enter file name
4.c
Before Critical Section
Read(R) or Write(W)?
Lock Successfull
Enter Q to release lock

*/
