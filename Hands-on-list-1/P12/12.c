/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 12.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 31 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf() perror()
#include <stdlib.h> // exit()
#include <unistd.h> // close()
#include <fcntl.h> // open() fcntl()

int main(){
	int fd,flag,mode;

	fd = open("file.txt",O_RDWR);

	if(fd == -1){
		perror("File not opended : ");
		exit(1);
	}	
	
	flag = fcntl(fd, F_GETFL);
	mode = flag & 3;

	if(mode == 0)	
		printf("File is opened in Read Only mode\n");
	else if(mode == 1)
		printf("File is opened in Write Only mode\n");
	else if(mode == 2)
		printf("File is opened in Read-Write mode\n");
	else
		printf("Unknown mode\n");
	close(fd);
	return 0;
}

/*
 Output:
	shivam@shivam:~/Desktop/Handsonlist_1/P12$ vim 12.c
	shivam@shivam:~/Desktop/Handsonlist_1/P12$ cc -o 12 12.c
	shivam@shivam:~/Desktop/Handsonlist_1/P12$ ./12
	File is opened in Read-Write mode
	shivam@shivam:~/Desktop/Handsonlist_1/P12$
*/
