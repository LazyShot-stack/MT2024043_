/*
===========================================================================================
Name : 30.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to run a script at a specific time using a Daemon process.
===========================================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<time.h>

int main()
{
    struct tm t;
    t.tm_hour = 15;
    t.tm_min = 38;
    t.tm_sec = 0;
    if(fork()==0)
    {
	    setsid();
	    umask(0);
	    chdir("/");
	    while(1)
	    {
		    time_t timevalue = time(NULL);
		    struct tm* currtime = localtime(&timevalue);
		    if(currtime->tm_hour == t.tm_hour && currtime->tm_min == t.tm_min && currtime->tm_sec == t.tm_sec)
		    {
			    printf("This is a sample text\n");
			    return 0;
		    }
	    }
    }
    else
    {
	    exit(0);
    }
    return 0;
}

/*
This is a sample text
*/

