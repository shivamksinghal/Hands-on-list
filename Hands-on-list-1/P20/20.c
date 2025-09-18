/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 20.c 
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 03 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/


#include <stdio.h> // printf()
#include <unistd.h> // getpid() nice()
#include <sys/resource.h> // getpriority()
int main() {
    int pid = getpid();
    int old_prio, new_prio;

    old_prio = getpriority(PRIO_PROCESS, pid);
    printf("PID = %d\n", pid);
    printf("Old nice value = %d\n", old_prio);
    nice(11);
    new_prio = getpriority(PRIO_PROCESS, pid);
    printf("New nice value = %d\n", new_prio);

    return 0;
}
/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P20$ vim 20.c
	shivam@shivam:~/Desktop/Handsonlist_1/P20$ cc -o 20 20.c
	shivam@shivam:~/Desktop/Handsonlist_1/P20$ ./20
	PID = 31230
	Old nice value = 0
	New nice value = 11
	shivam@shivam:~/Desktop/Handsonlist_1/P20$ 
*/
