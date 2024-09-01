/*
===================================================================================
Name : 25.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to create three child processes.
	      The parent should wait for a particular child
===================================================================================
*/


#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int c[3];
	int choice;
	printf("Enter which process should parent wait for:\n");
	scanf("%d",&choice);
	int w;
	for(int i=0;i<3;i++)
	{
		c[i] = fork();
		if(c[i]==-1)
		{
			printf("Error in creating child %d\n",i+1);
			return 0;
		}
		if(c[i]!=0)
		{
			continue;
		}
		else if(i==choice-1)
		{
			sleep(5);
			printf("Child:%d terminated successfully!\n",i+1);
			return 0;
		}
		else
		{
			printf("Child:%d terminated successfully!\n",i+1);
			return 0;
		}
	}
	waitpid(c[choice-1],&w,0);
	printf("Parent terminated successfully!\n");
	return 0;

}

/*
Enter which process should parent wait for:
2
Child:1 terminated successfully!
Child:3 terminated successfully!
Child:2 terminated successfully!
Parent terminated successfully!
*/
