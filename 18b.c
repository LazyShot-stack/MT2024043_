/*
===================================================================================
Name : 18b.c
Author : Dhruvik Patel - MT2024043
Description : Write a C Program to perform Record locking.
              Implement write lock.
              Implement read lock.
              b.Program to avoid race condition. When a record is accessed, first
		lock and then modify.
===================================================================================
*/


#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
        int n;
        printf("Enter the choice of flight:\n");
        scanf("%d",&n);
        struct flock f;
        f.l_type = F_WRLCK;
        f.l_whence = SEEK_SET;
        f.l_pid = getpid();
        int fd = open("Records.txt",O_RDWR);
        if (fd<0)
        {
                printf("Error in opening records!\n");
                return 0;
        }
        f.l_start = (n-1)*sizeof(int);
        f.l_len = sizeof(int);
        int lck = fcntl(fd,F_SETLKW,&f);
        if(lck<0)
        {
                printf("Error in lock\n");
        }
        else
        {
                printf("Lock successful!\n");
        }
        int val[3];
        int l = lseek(fd,(n-1)*sizeof(int),SEEK_SET);
        int rcount = read(fd,&val[n-1],sizeof(int));
        printf("Ticket Count of Flight %d Before: %d\n",n,val[n-1]);
        val[n-1]+=1;
        l = lseek(fd,(n-1)*sizeof(int),SEEK_SET);
        int wcount = write(fd,&val[n-1],sizeof(int));
        printf("Ticket Count of Flight %d After: %d\n",n,val[n-1]);
        char c;
        printf("Enter Q to unlock\n");
        scanf("%c",&c);
        while(c!='Q')
        {
                scanf("%c",&c);
        }
        lck = fcntl(fd,F_SETLKW,&f);
	if(lck<0)
        {
                printf("Error in unlock\n");
        }
        else
        {
                printf("Unlock successful!\n");
        }
        close(fd);
        return 0;
}

/*
Enter the choice of flight:
2
Lock successful!
Ticket Count of Flight 2 Before: 1
Ticket Count of Flight 2 After: 2
Enter Q to unlock
Q
Unlock successful!

Enter the choice of flight:
2
Lock successful!
Ticket Count of Flight 2 Before: 2
Ticket Count of Flight 2 After: 3
Enter Q to unlock
*/
