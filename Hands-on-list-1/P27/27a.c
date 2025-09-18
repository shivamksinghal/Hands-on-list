/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 27a.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to execute ls -Rl by the following system calls
		a. execl
Date: 05 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Using execl:\n");
    execl("/bin/ls", "ls", "-Rl", NULL);
    return 0;
}

/*
 Output:
 	Using execl:
	.:
	total 20
	-rwxrwxr-x 1 shivam shivam 16000 Sep  5 12:13 27a
	-rw-rw-r-- 1 shivam shivam   589 Sep  5 12:13 27a.c
*/
