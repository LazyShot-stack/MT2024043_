/*
===================================================================================
Name : 22.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to open a file, call fork, and then write to the
	      file by both the child as well as the parent processes.
	      Check output of the file.
===================================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
        char fname[50];
        printf("Enter file name\n");
	scanf("%s",fname);
	int fd = open(fname,O_RDWR,00600);
	if(fd<0)
	{
		printf("File does not exist\n");
		return 0;
	}
	char c1[40] = "This text is written by parent\n";
        char c2[40] = "This test is written by child\n";
	int wcount = write(fd,c1,sizeof(c1));
	if(wcount<0)
	{
		printf("Error in writing by parent\n");
		return 0;
	}
	int c_id = fork();
        if(c_id==-1)
        {
                perror("Error in creating child process\n");
                return 0;
        }
        if(!c_id)
	{
		lseek(fd,0,SEEK_CUR);
		wcount = write(fd,c2,sizeof(c2));
		if(wcount<0)
		{
			printf("Error in writing by child process");
		}
	}
	return 0;
}

/*
Enter file name
123
File does not exist

Enter file name
2.c

*/
