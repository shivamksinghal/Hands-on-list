/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 19.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 03 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf()
#include <unistd.h> // getpid()
#include <stdint.h>

int main() {
    unsigned long long start, end;
    unsigned high, low;
    pid_t pid;
    
    __asm__ __volatile__ ("rdtsc" : "=a"(low), "=d"(high));
    start = ((unsigned long long)low) | (((unsigned long long)high) << 32);
    
    pid = getpid();
    
    __asm__ __volatile__ ("rdtsc" : "=a"(low), "=d"(high));
    end = ((unsigned long long)low) | (((unsigned long long)high) << 32);          

    printf("PID: %d\n", pid);
    printf("Time taken by getpid() = %llu cycles\n", (end - start));

    return 0;
}
/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P19$ vim 19.c
	shivam@shivam:~/Desktop/Handsonlist_1/P19$ cc -o 19 19.c
	shivam@shivam:~/Desktop/Handsonlist_1/P19$ ./19
	PID: 30224
	Time taken by getpid() = 16150 cycles
	shivam@shivam:~/Desktop/Handsonlist_1/P19$ 
*/
