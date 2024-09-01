/*
===================================================================================
Name : 14.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to find the type of a file.
===================================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
        char fname[50];
        printf("Enter file name\n");
	scanf("%s",fname);
        int fd = open(fname,O_RDWR);
        if (fd<0)
        {
                printf("File does not exist!\n");
                return 0;
	}
	struct stat s;
	int s1 = lstat(fname,&s);
	if (s1<0)
	{
		printf("Error in Obtaining File Status\n");
		return 0;
	}	
	printf("File type is: ");
	switch (s.st_mode & S_IFMT) 
	{
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
         }
        int cl = close(fd);
        return 0;
}

/*
Enter file name
13.c
File type is: regular file
*/


