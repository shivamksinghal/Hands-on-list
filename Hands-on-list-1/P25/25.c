/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 25.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to create three child processes. The parent should wait for a particular child (use
	      waitpid system call).
Date: 05 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf()
#include <unistd.h> // sleep() fork()
#include <sys/wait.h> // waitpid()

int main(){
	pid_t i,j,k;

	if(!(i = fork()))
		sleep(1);
	else if(!(j = fork()))
		sleep(3);
	else if(!(k = fork()))
		sleep(10);
	else{
		printf("Parent PID=%d waiting for Child 3 PID=%d\n", getpid(), k);
		waitpid(k,NULL,0);
		printf("Parent: Child 3 finished\n");
	}
	return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P25$ vim 25.c
	shivam@shivam:~/Desktop/Handsonlist_1/P25$ cc -o 25 25.c
	shivam@shivam:~/Desktop/Handsonlist_1/P25$ ./25
	Parent PID=8092 waiting for Child 3 PID=8095
	Parent: Child 3 finished
	shivam@shivam:~/Desktop/Handsonlist_1/P25$ 
*/
