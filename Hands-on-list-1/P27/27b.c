/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 27b.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to execute ls -Rl by the following system calls
		b. execlp
Date: 05 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Using execlp:\n");
    execlp("ls", "ls", "-Rl", NULL);
    return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P27$ vim 27b.c
	shivam@shivam:~/Desktop/Handsonlist_1/P27$ cc -o 27b 27b.c
	shivam@shivam:~/Desktop/Handsonlist_1/P27$ ./27b
	Using execlp:
	.:
	total 40
	-rwxrwxr-x 1 shivam shivam 16000 Sep  5 12:13 27a
	-rw-rw-r-- 1 shivam shivam   737 Sep  5 12:14 27a.c
	-rwxrwxr-x 1 shivam shivam 16000 Sep  5 12:16 27b
	-rw-rw-r-- 1 shivam shivam   587 Sep  5 12:16 27b.c
	shivam@shivam:~/Desktop/Handsonlist_1/P27$ 
*/
