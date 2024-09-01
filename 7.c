/*
============================================================================
Name : 7.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to copy file1 into file2.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
                char fname[50], dname[50];
                int rcount,wcount;
	        char buff;
	        printf("Enter source file name\n");
	        scanf("%s",fname);
	        printf("Enter destination file name\n");
	        scanf("%s",dname);
                
                int fd1 = open(fname,O_RDONLY);
		if (fd1<0)
		{
			printf("Source file does not exist!\n");
			return 0;
		}
		int fd2 = open(dname ,O_RDWR|O_CREAT);
		if (fd2<0)
		{
			printf("Destination file cannot be created!\n");
			return 0;
		}
		rcount = read(fd1,&buff,1);
		while (rcount!=0)
		{
			wcount = write(fd2,&buff,1);
			rcount = read(fd1,&buff,1);
		}
		int src_close=close(fd1);
		int dest_close=close(fd2);
		if (src_close<0 || dest_close< 0)
		{
			printf("Problem in closing files!\n");
		}
		else
		{
			printf("File copied Successfully!\n");
		}
	        return 0;
}

/*
Enter source file name
1.c
Enter destination file name
2.c
File copied Successfully!
*/
