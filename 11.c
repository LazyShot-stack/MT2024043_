/*
===================================================================================
Name : 11.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to open a file. Duplicate the file descriptor using
              dup, dup2, fcntl. Append the file using these descriptors.
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
	int fd = open(fname, O_RDWR | O_APPEND);
	if (fd<0)
	{
		printf("File does not exist!\n");
		return 0;
	}
	int newfd1 = dup(fd);
	if (newfd1<0)
        {
                printf("File descriptor could not be created using dup!\n");
		return 0;
        }
	char s[5];
	printf("Enter 5 bytes to be appened using oldfd\n");
	scanf("%s",s);
	int wrcount = write(fd,s,5);
	printf("dup : Enter 5 bytes to be appened using newfd\n");
        scanf("%s",s);
        wrcount = write(newfd1,s,5);
	int cl = close(newfd1);

	int newfd2 = dup2(fd,8);
        if (newfd2<0)
        {
                printf("File descriptor could not be created using dup2!\n");
                return 0;
        }
        printf("dup2 :Enter 5 bytes to be appened using newfd\n");
        scanf("%s",s);
        wrcount = write(newfd2,s,5);
        cl = close(newfd2);

	int newfd3 = fcntl(fd,F_DUPFD,9);
        if (newfd3<0)
        {
                printf("File descriptor could not be created using fcntl!\n");
                return 0;
        }
        printf("fcntl :Enter 5 bytes to be appened using newfd\n");
        scanf("%s",s);
        wrcount = write(newfd3,s,5);
        cl = close(newfd3);
	return 0;
}

/*
Enter file name
3.c
Enter 5 bytes to be appened using oldfd
hey
dup : Enter 5 bytes to be appened using newfd
hery
dup2 :Enter 5 bytes to be appened using newfd
hello
fcntl :Enter 5 bytes to be appened using newfd
hiii

*/
