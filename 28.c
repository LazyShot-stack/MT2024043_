/*
===================================================================================
Name : 28.c
Author : Dhruvik Patel - MT2024043
Description : Write a program to get maximum and minimum real time priority.
===================================================================================
*/
#include <stdio.h>
#include <sched.h>
#include <errno.h>

int main() {
    int max, min;
    
    max = sched_get_priority_max(SCHED_FIFO);
    if (max == -1) {
        perror("Error in Max!!!");
        return 1;
    }
    min = sched_get_priority_min(SCHED_FIFO);
    if (min == -1) {
        perror("Error in Min!!!");
        return 1;
    }
    printf("Maximum real-time priority: %d\n", max);
    printf("Minimum real-time priority: %d\n", min);
    return 0;
}

/*
Maximum real-time priority: 99
Minimum real-time priority: 1
*/

