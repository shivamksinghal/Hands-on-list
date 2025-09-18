/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 3.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 28 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf() perror()
#include <fcntl.h> // creat()
#include <unistd.h> // close()
#include <stdlib.h> //exit()
int main(){
	int fd;
	fd = creat("shivam.txt",0644);
	if(fd == -1){
		perror("creat() failed");
		exit(1);
	}
	printf("File is successfully created with fd = %d\n",fd);
	close(fd);
	return 0;
}

/*
 Output:
	shivam@shivam:~/Desktop/Handsonlist_1$ cd P3
	shivam@shivam:~/Desktop/Handsonlist_1/P3$ vim 3.c
	shivam@shivam:~/Desktop/Handsonlist_1/P3$ cc -o 3 3.c
	shivam@shivam:~/Desktop/Handsonlist_1/P3$ ./3
	File is successfully created with fd = 3
	shivam@shivam:~/Desktop/Handsonlist_1/P3$ ls -l
	total 20
	-rwxrwxr-x 1 shivam shivam 16128 Aug 28 19:56 3
	-rw-rw-r-- 1 shivam shivam   769 Aug 28 19:56 3.c
	-rw-r--r-- 1 shivam shivam     0 Aug 28 19:57 shivam.txt
	shivam@shivam:~/Desktop/Handsonlist_1/P3$
*/
