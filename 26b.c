/*
===================================================================================
Name : 26b.c
Author : Dhruvik Patel - MT2024043
Description : Write a program to execute an executable program.
              b. pass some input to an executable program. 
              (for example execute an executable of $./a.out name)
===================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed!!!");
        return 1;
    }

    if (pid == 0) {
        const char *args[] = {"./temp", "user", NULL};
        execvp(args[0], (char* const*)args);
        perror("Failed!!!");
        return 1;
    } else {
        wait(NULL); 
        printf("Executable program has finished.\n");
    }

    return 0;
}

/*
Hello, user!
Executable program has finished.
*/

