/*
============================================================================
Name : 1.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to create soft link, hard link and fifo files
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	char f1[20],f2[20];
	printf("Enter filename to be pointed by soft link and soft link filename \n");
	scanf("%s",f1);
        scanf("%s",f2);	
        int sft = symlink(f1,f2);
        if(sft<0)
        {
                perror("Failed to create soft link\n");
                return 1;
        }
	else
	{
		printf("Soft link file created successfully!\n");
	}

	printf("Enter filename to be pointed by hard link and hard link filename\n");
        scanf("%s",f1);
        scanf("%s",f2);
        int hrd = link(f1,f2);
        if(hrd<0)
        {
                perror("Failed to create hard link\n");
                return 1;
        }
	else
        {
                printf("Hard link file created successfully!\n");
        }

	printf("Enter pipe name\n");
        scanf("%s",f1);
        int p = mknod(f1,S_IFIFO,0);
        if(p<0)
	{
                perror("Failed to create pipe\n");
	}
	else
        {
                printf("Pipe created successfully!\n");
        }

        return 0;
}


/* Enter filename to be pointed by soft link and soft link filename 
2.c
soft
Soft link file created successfully!
Enter filename to be pointed by hard link and hard link filename
3.c
hard
Hard link file created successfully!
Enter pipe name
fifopipe
Pipe created successfully! */

// ln -s for soft link and ln for hardlink 

