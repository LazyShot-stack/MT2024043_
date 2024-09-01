/*
===================================================================================
Name : 19.c
Author : Dhruvik Patel - MT2024043
Description : Write a program to find out time taken to execute getpid system call. 
Use time stamp counter.
===================================================================================
*/

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>

static inline uint64_t rdtsc() {
    uint32_t lo, hi;
    __asm__ volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t start, end;
    start = rdtsc();
    pid_t pid = getpid();
    end = rdtsc();
    uint64_t diff = end - start;
    printf("PID: %d\n", pid);
    printf("Time taken (in TSC ticks): %lu\n", diff);
    return 0;
}

/*
PID: 35926
Time taken (in TSC ticks): 11774
*/
