/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 4.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 29 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf() perror()
#include <unistd.h>// open() close()
#include <fcntl.h> // flags -- O_RDWR
#include <stdlib.h> // exit()

int main(){
	int fd;
	fd = open("file.txt",O_RDWR);
	if(fd == -1){
		perror("File not opened");
		exit(1);
	}
	printf("File opened successfully with fd = %d\n",fd);
	close(fd);
	fd = open("demo.txt",O_RDWR | O_CREAT | O_EXCL,0666);
	if(fd == -1){
		perror("Failed");
		exit(1);
	}
	printf("File opened successfully with fd = %d\n",fd);
	return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P4$ vim 4.c
	shivam@shivam:~/Desktop/Handsonlist_1/P4$ cc -o 4 4.c
	shivam@shivam:~/Desktop/Handsonlist_1/P4$ ./4
	File opened successfully with fd = 3
	File opened successfully with fd = 3
	shivam@shivam:~/Desktop/Handsonlist_1/P4$ ls
	4  4.c  demo.txt  file.txt
	shivam@shivam:~/Desktop/Handsonlist_1/P4$ ./4
	File opened successfully with fd = 3
	Failed: File exists
	shivam@shivam:~/Desktop/Handsonlist_1/P4$ 
*/
