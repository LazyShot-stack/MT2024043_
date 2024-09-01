/*
===================================================================================
Name : 27d.c
Author : Dhruvik Patel - MT2024043
Description : Write a program to execute ls -Rl by the following system calls
		a. execl
		b. execlp
		c. execle
		d. execv
		e. execvp
===================================================================================
*/

#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	int c;
	c = fork();
        if(c==-1)
        {
                printf("Error\n");
                return 0;
        }
        else
        {
                if(c==0)
                {
		
		    const char *args[] = {"ls", "-Rl", nullptr};
		    printf("Execution using execv() system call\n");
                    execv("/bin/ls", const_cast<char *const *>(args));
	            exit(1);

                }
        }
	wait(NULL);
	return 0;
}

/*
Execution using execv() system call
.:
total 148
-rw-rw-r-- 1 lazyuser lazyuser  1413 Aug 30 14:18 10.c
-rw-rw-r-- 1 lazyuser lazyuser  1948 Aug 30 14:23 11.c
-rw-rw-r-- 1 lazyuser lazyuser   744 Aug 30 14:27 12.c
-rw-rw-r-- 1 lazyuser lazyuser   766 Aug 30 14:32 13.c
-rw-rw-r-- 1 lazyuser lazyuser  1453 Aug 30 14:34 14.c
-rw-rw-r-- 1 lazyuser lazyuser   565 Aug 30 14:35 15.c
-rw-rw-r-- 1 lazyuser lazyuser  1738 Aug 30 14:39 16.c
-rw-rw-r-- 1 lazyuser lazyuser   938 Aug 31 03:03 17a.c
-rw-rw-r-- 1 lazyuser lazyuser  1498 Aug 31 03:04 17b.c
-rw-rw-r-- 1 lazyuser lazyuser  1726 Aug 30 00:26 1.c
-rw-rw-r-- 1 lazyuser lazyuser   923 Aug 30 14:52 20.c
-rw-rw-r-- 1 lazyuser lazyuser   611 Aug 30 14:57 21.c
-rw-rw-r-- 1 lazyuser lazyuser  1255 Aug 30 15:04 22.c
-rw-rw-r-- 1 lazyuser lazyuser   647 Aug 30 15:06 23.c
-rw-rw-r-- 1 lazyuser lazyuser   723 Aug 30 15:11 24.c
-rw-rw-r-- 1 lazyuser lazyuser  1149 Aug 30 15:15 25.c
-rw-rw-r-- 1 lazyuser lazyuser  1068 Aug 31 12:05 26.c
-rw-rw-r-- 1 lazyuser lazyuser  2526 Aug 31 12:33 27a.c
-rw-rw-r-- 1 lazyuser lazyuser  2718 Aug 31 12:33 27b.c
-rw-rw-r-- 1 lazyuser lazyuser  2661 Aug 31 12:33 27c.c
-rw-rw-r-- 1 lazyuser lazyuser   912 Aug 31 12:44 27d.c
-rw-rw-r-- 1 lazyuser lazyuser   859 Aug 31 12:41 27e.c
-rw-rw-r-- 1 lazyuser lazyuser  2507 Aug 30 15:31 29.c
-rw-rw-r-- 1 lazyuser lazyuser   677 Aug 30 11:38 2.c
-rw-rw-r-- 1 lazyuser lazyuser  1009 Aug 30 15:38 30.c
-rw-rw-r-- 1 lazyuser lazyuser   779 Aug 30 11:41 3.c
-rw-rw-r-- 1 lazyuser lazyuser   829 Aug 30 11:45 4.c
-rw-rw-r-- 1 lazyuser lazyuser  1831 Aug 30 13:53 5.c
-rw-rw-r-- 1 lazyuser lazyuser   649 Aug 30 13:56 6.c
-rw-rw-r-- 1 lazyuser lazyuser  1287 Aug 30 14:06 7.c
-rw-rw-r-- 1 lazyuser lazyuser  1894 Aug 30 14:11 8.c
-rw-rw-r-- 1 lazyuser lazyuser  1328 Aug 30 14:15 9.c
-rwxrwxr-x 1 lazyuser lazyuser 16480 Aug 31 12:44 a.out
*/
