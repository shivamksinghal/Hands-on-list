/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 27c.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to execute ls -Rl by the following system calls
		c. execle
Date: 05 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Using execle:\n");
    char *env[] = { NULL };
    execle("/bin/ls", "ls", "-Rl", NULL, env);
    return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P27$ vim 27c.c
	shivam@shivam:~/Desktop/Handsonlist_1/P27$ cc -o 27c 27c.c
	shivam@shivam:~/Desktop/Handsonlist_1/P27$ ./27c
	Using execle:
	.:
	total 60
	-rwxrwxr-x 1 shivam shivam 16000 Sep  5 12:13 27a
	-rw-rw-r-- 1 shivam shivam   737 Sep  5 12:14 27a.c
	-rwxrwxr-x 1 shivam shivam 16000 Sep  5 12:16 27b
	-rw-rw-r-- 1 shivam shivam  1049 Sep  5 12:18 27b.c
	-rwxrwxr-x 1 shivam shivam 16056 Sep  5 12:21 27c
	-rw-rw-r-- 1 shivam shivam   625 Sep  5 12:21 27c.c
	shivam@shivam:~/Desktop/Handsonlist_1/P27$ 
*/
