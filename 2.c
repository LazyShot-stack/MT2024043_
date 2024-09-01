/*
============================================================================
Name : 2.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to execute infinite loop in background.
	      Display process related information from /proc directory.
============================================================================
*/


#include<stdio.h>
int main()
{
        for(;;){
        }
        return 0;
}


// ls -l proc/
// ls -d [0-9]* - list all process dir
// cat /proc/PID/status - status of process
// cat /proc/PID/statm - mem usage by process
// list of fds - ls -l /proc/PID/fd
// stat gives detail statistics - pid, proc name, state, parentid, etc

