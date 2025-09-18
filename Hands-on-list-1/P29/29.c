/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 29.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
              SCHED_RR).
Date: 06 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf()
#include <sched.h> // sched_getscheduler() sched_setscheduler()
#include <unistd.h> // getpid()

void print_policy(int policy) {
    	printf("Current scheduling policy: ");
	
	switch (policy) {
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        default:
            printf("UNKNOWN\n");
    }
}

int main(){
	pid_t pid = getpid();
 	int current_Policy;
  	struct sched_param parameter;
  	
	current_Policy = sched_getscheduler(pid);
	print_policy(current_Policy);
   	
	printf("Setting new scheduling policy...\n");

    	parameter.sched_priority = 11;
    	sched_setscheduler(pid, SCHED_FIFO, &parameter);
    	
	current_Policy = sched_getscheduler(pid);
        print_policy(current_Policy);

    	printf("Switching to SCHED_RR...\n");

    	parameter.sched_priority = 15;
    	sched_setscheduler(pid, SCHED_RR, &parameter);
    	current_Policy = sched_getscheduler(pid);
        print_policy(current_Policy);

  	return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P29$ vim 29.c
	shivam@shivam:~/Desktop/Handsonlist_1/P29$ sudo cc -o 29 29.c
	shivam@shivam:~/Desktop/Handsonlist_1/P29$ sudo ./29
	Current scheduling policy: SCHED_OTHER
	Setting new scheduling policy...
	Current scheduling policy: SCHED_FIFO
	Switching to SCHED_RR...
	Current scheduling policy: SCHED_RR
	shivam@shivam:~/Desktop/Handsonlist_1/P29$ 
*/
