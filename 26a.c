/*
===================================================================================
Name : 26a.c
Author : Dhruvik Patel - MT2024043
Description : Write a program to execute an executable program.
              a. use some executable program
===================================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("In Main and executing the hello program...\n");
    int val = system("./hello"); 
    if (val == -1) {
        printf("Error: Failed to execute the program.\n");
        return 1;
    }
    
    printf("Program executed with return value %d\n", WEXITSTATUS(val));
    return 0;
}

/*
In Main and executing the hello program...
Hello from the executable program!
Program executed with return value 0
*/
