/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 24.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to create an orphan process.
Date: 04 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf()
#include <stdlib.h> // exit()
#include <unistd.h> // fork() sleep()

int main(){
	
	if(!fork()){
		printf("Child process (PID: %d), parent (PID: %d)\n", getpid(), getppid());
		sleep(4);
		printf("Child process (PID: %d) now has new parent (PID: %d)\n", getpid(), getppid());
	}
	else{
		printf("Parent process (PID: %d) exiting...\n", getpid());
		exit(0);
	}

	return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P24$ vim 24.c
	shivam@shivam:~/Desktop/Handsonlist_1/P24$ cc -o 24 24.c
	shivam@shivam:~/Desktop/Handsonlist_1/P24$ ./24
	Parent process (PID: 17023) exiting...
	Child process (PID: 17024), parent (PID: 17023)
	shivam@shivam:~/Desktop/Handsonlist_1/P24$ Child process (PID: 17024) now has new parent (PID: 1543)

	shivam@shivam:~/Desktop/Handsonlist_1/P24$ 
*/
