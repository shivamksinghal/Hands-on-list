/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 6.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 29 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h>
#include <unistd.h> // read() write()
int main() {
    char input[100];
    int n;
    n = read(0, input, sizeof(input));
    write(1, input, n);
    return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P6$ vim 6.c
	shivam@shivam:~/Desktop/Handsonlist_1/P6$ cc -o 6 6.c
	shivam@shivam:~/Desktop/Handsonlist_1/P6$ ./6
	Hi Shivam is Here
	Hi Shivam is Here
	shivam@shivam:~/Desktop/Handsonlist_1/P6$ 
*/
