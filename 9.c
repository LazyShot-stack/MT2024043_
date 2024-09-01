/*
============================================================================
Name : 9.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to display information about a file.
============================================================================
*/


#include<stdio.h>
#include<sys/stat.h>
#include<time.h>

int main()
{
        char fname[50], dname[50];
        printf("Enter file name\n");
	scanf("%s",fname);
	struct stat s;
	int f = stat(fname,&s);
	if (f<0)
	{
		printf("Error! No such file exists\n");
		return 0;
	}

	printf("Inode number:%ju\n",s.st_ino);
	printf("Number of Hard Links:%ju\n",s.st_nlink);
	printf("Uid:%u\n",s.st_uid);
	printf("Gid:%u\n",s.st_gid);
	printf("Inode number:%jd bytes\n",s.st_size);
	printf("Block size:%jd bytes\n",s.st_blksize);
	printf("Number of Blocks:%jd\n",s.st_blocks);
	printf("Time of last access:%s\n",ctime(&s.st_atime));
	printf("Time of last modification:%s\n",ctime(&s.st_mtime));
	printf("Time of last change:%s\n",ctime(&s.st_ctime));
	return 0;
}

/*
Enter file name
29.c
Inode number:4333975
Number of Hard Links:1
Uid:1000
Gid:1000
Inode number:2379 bytes
Block size:4096 bytes
Number of Blocks:8
Time of last access:Tue Aug 27 16:01:01 2024

Time of last modification:Tue Aug 27 16:01:01 2024

Time of last change:Tue Aug 27 16:01:01 2024
*/
