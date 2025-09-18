/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 21.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program, call fork and print the parent and child process id.
Date: 03 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf()
#include <unistd.h> // fork()

int main(){
	if(!fork()) 
		printf("Child pid is : %d\n", getpid());
	else 
		printf("Parent pid is : %d\n",getpid());
	
	return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P21$ vim 21.c
	shivam@shivam:~/Desktop/Handsonlist_1/P21$ cc -o 21 21.c
	shivam@shivam:~/Desktop/Handsonlist_1/P21$ ./21
	Parent pid is : 31429
	Child pid is : 31430
	shivam@shivam:~/Desktop/Handsonlist_1/P21$
*/	
