/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 23.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to create a Zombie state of the running program.
Date: 04 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf()
#include <stdlib.h> // exit()
#include <unistd.h> // fork() sleep()

int main() {
	
	if(!fork()){
		printf("Child process (PID: %d) exiting...\n",getpid());
		exit(0);
	}
	else{
		printf("Parent process (PID: %d)\n", getpid());
		printf("Parent is sleeping...\n");
		sleep(30);
		printf("Parent exiting...\n");
	}
    	return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P23$ vim 23.c
	shivam@shivam:~/Desktop/Handsonlist_1/P23$ cc -o 23 23.c
	shivam@shivam:~/Desktop/Handsonlist_1/P23$ ./23
	Parent process (PID: 15028)
	Parent is sleeping...
	Child process (PID: 15029) exiting...
	Parent exiting...
*/
