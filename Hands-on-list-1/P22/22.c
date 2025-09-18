/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 22.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
	      parent processes. Check output of the file.
Date: 04 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h>
#include <unistd.h> //write() close() fork()
#include <fcntl.h> // open()
int main(){
	int fd = open("file.txt",O_RDWR | O_CREAT | O_TRUNC, 0666);

	if(!fork())
		write(fd,"Written by Child...\n",21);
	else
		write(fd,"Written by Parent...\n",22);
	
	close(fd);
	return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P22$ vim 22.c
	shivam@shivam:~/Desktop/Handsonlist_1/P22$ cc -o 22 22.c
	shivam@shivam:~/Desktop/Handsonlist_1/P22$ ./22
	shivam@shivam:~/Desktop/Handsonlist_1/P22$ cat file.txt 
	Written by Parent...
	Written by Child...
	shivam@shivam:~/Desktop/Handsonlist_1/P22$ 
*/
