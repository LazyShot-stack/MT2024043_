/*
===================================================================================
Name : 17a.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to open a file and store ticket number.
===================================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
        int fd = open("ticket.txt",O_RDWR,00600);
        if(fd<0)
        {
                printf("File could not be created\n");
                return 0;
        }
        int n;
        printf("Enter ticker number:\n");
        scanf("%d",&n);
        int wcount = write(fd,&n,sizeof(int));
	write(fd,"\n",1);
        if(wcount<0)
        {
                printf("Error");
        }
        else
        {
                printf("Ticket number stored successfully!\n");
        }
        return 0;
}


/*
Enter ticker number:
12
Ticket number stored successfully!
*/
