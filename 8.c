/*
============================================================================
Name : 8.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to open file in read only mode.
              Read and display contents line by line.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
        char fname[50], dname[50];
        printf("Enter file name\n");
	scanf("%s",fname);
	int fd = open(fname,O_RDONLY);
	if (fd<0)
	{
		printf("File does not exist\n");
		return 0;
	}
	char line[100];
        int i=0, rdcount, wrcount;
        char buff;
	rdcount = read(fd,&buff,1);
	while(rdcount!=0)
	{
		while(buff!='\n')
		{
			wrcount = write(1,&buff,1);
			rdcount = read(fd,&buff,1);
		}
		
		printf("\n");
		rdcount = read(fd,&buff,1);
	}
	int f = close(fd);
	if (f <0)
	{
		printf("File could not be closed");
	}
	return 0;
}


/*
          Enter file name
          2.c
          /*
          ============================================================================
          Name : 2.c
          Author : Dhruvik Patel - MT2024043
          Description : Write a C Program to execute infinite loop in background.
	                Display process related information from /proc directory.
          ============================================================================
          */

          /*

          #include<stdio.h>
          int main()
          {
                  for(;;){
                  }
                  return 0;
          }

          */
          // ls -l proc/
          // ls -d [0-9]* - list all process dir
          // cat /proc/PID/status - status of process
          // cat /proc/PID/statm - mem usage by process
          // list of fds - ls -l /proc/PID/fd
          // stat gives detail statistics - pid, proc name, state, parentid, etc
*/
