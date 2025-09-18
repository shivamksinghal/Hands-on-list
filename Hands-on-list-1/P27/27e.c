/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 27e.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to execute ls -Rl by the following system calls
		e. execvp
Date: 05 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Using execvp:\n");
    char *args[] = { "ls", "-Rl", NULL };
    execvp("ls", args);
    return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P27$ vim 27e.c
	shivam@shivam:~/Desktop/Handsonlist_1/P27$ cc -o 27e 27e.c
	shivam@shivam:~/Desktop/Handsonlist_1/P27$ ./27e
	Using execvp:
	.:
	total 100
	-rwxrwxr-x 1 shivam shivam 16000 Sep  5 12:13 27a
	-rw-rw-r-- 1 shivam shivam   737 Sep  5 12:22 27a.c
	-rwxrwxr-x 1 shivam shivam 16000 Sep  5 12:16 27b
	-rw-rw-r-- 1 shivam shivam  1049 Sep  5 12:23 27b.c
	-rwxrwxr-x 1 shivam shivam 16056 Sep  5 12:21 27c
	-rw-rw-r-- 1 shivam shivam  1191 Sep  5 12:22 27c.c
	-rwxrwxr-x 1 shivam shivam 16048 Sep  5 12:26 27d
	-rw-rw-r-- 1 shivam shivam  1285 Sep  5 12:26 27d.c
	-rwxrwxr-x 1 shivam shivam 16056 Sep  5 12:29 27e
	-rw-rw-r-- 1 shivam shivam   615 Sep  5 12:29 27e.c
	shivam@shivam:~/Desktop/Handsonlist_1/P27$ 
*/
