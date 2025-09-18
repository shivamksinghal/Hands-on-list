/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 28.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to get maximum and minimum real time priority.
Date: 06 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/


#include <stdio.h> // printf()
#include <sched.h> // sched_get_priority_max() sched_get_priority_min()

int main() {
    int max, min;

    max = sched_get_priority_max(SCHED_FIFO);
    min = sched_get_priority_min(SCHED_FIFO);
    printf("SCHED_FIFO  -> Max Priority: %d, Min Priority: %d\n", max, min);

    max = sched_get_priority_max(SCHED_RR);
    min = sched_get_priority_min(SCHED_RR);
    printf("SCHED_RR    -> Max Priority: %d, Min Priority: %d\n", max, min);

    max = sched_get_priority_max(SCHED_OTHER);
    min = sched_get_priority_min(SCHED_OTHER);
    printf("SCHED_OTHER -> Max Priority: %d,  Min Priority: %d\n", max, min);

    return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1$ vim 28.c
	shivam@shivam:~/Desktop/Handsonlist_1$ cc -o 28 28.c
	shivam@shivam:~/Desktop/Handsonlist_1$ ./28
	SCHED_FIFO  -> Max Priority: 99, Min Priority: 1
	SCHED_RR    -> Max Priority: 99, Min Priority: 1
	SCHED_OTHER -> Max Priority: 0,  Min Priority: 0
	shivam@shivam:~/Desktop/Handsonlist_1$ 
*/
