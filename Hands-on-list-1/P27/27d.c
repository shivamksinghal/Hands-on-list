/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 27d.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to execute ls -Rl by the following system calls
		d. execv
Date: 05 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Using execv:\n");
    char *arg[] = { "ls", "-Rl", NULL };
    execv("/bin/ls", arg);
    return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P27$ vim 27d.c
	shivam@shivam:~/Desktop/Handsonlist_1/P27$ cc -o 27d 27d.c
	shivam@shivam:~/Desktop/Handsonlist_1/P27$ ./27d
	Using execv:
	.:
	total 80
	-rwxrwxr-x 1 shivam shivam 16000 Sep  5 12:13 27a
	-rw-rw-r-- 1 shivam shivam   737 Sep  5 12:22 27a.c
	-rwxrwxr-x 1 shivam shivam 16000 Sep  5 12:16 27b
	-rw-rw-r-- 1 shivam shivam  1049 Sep  5 12:23 27b.c
	-rwxrwxr-x 1 shivam shivam 16056 Sep  5 12:21 27c
	-rw-rw-r-- 1 shivam shivam  1191 Sep  5 12:22 27c.c
	-rwxrwxr-x 1 shivam shivam 16048 Sep  5 12:25 27d
	-rw-rw-r-- 1 shivam shivam   616 Sep  5 12:24 27d.c
	shivam@shivam:~/Desktop/Handsonlist_1/P27$ 
*/
