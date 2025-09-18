/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 10.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
	      bytes (use lseek) and write again 10 bytes.
	      	a. check the return value of lseek
		b. open the file with od and check the empty spaces in between the data.
Date: 31 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/
#include <stdio.h> // printf() perror()
#include <stdlib.h> // exit()
#include <unistd.h> // lseek() write() close()
#include <fcntl.h> // open()
int main(){
	int fd,n;
	long int lseek_value;
	char arr1[] = "1234567890";
	char arr2[] = "ABCDEFGHIJ";

	fd = open("file.txt",O_RDWR | O_CREAT | O_TRUNC, 0666);
	
	if(fd == -1){
		perror("Failed");
		exit(1);
	}

       	n = write(fd,arr1,10);
	lseek_value = lseek(fd,n,SEEK_CUR);
	
	printf("lseek value : %ld\n",lseek_value);
	
	write(fd,arr2,10);
	
	printf("Successfully Written in the File!!\n");
	
	close(fd);
	return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P10$ vim 10.c
	shivam@shivam:~/Desktop/Handsonlist_1/P10$ cc -o 10 10.c
	shivam@shivam:~/Desktop/Handsonlist_1/P10$ ./10 
	lseek value : 20
	Successfully Written in the File!!
	shivam@shivam:~/Desktop/Handsonlist_1/P10$ cat file.txt 
	1234567890ABCDEFGHIJshivam@shivam:~/Desktop/Handsonlist_1/P10$ vim 10.c
	shivam@shivam:~/Desktop/Handsonlist_1/P10$ cc -o 10 10.c
	shivam@shivam:~/Desktop/Handsonlist_1/P10$ ./10 
	lseek value : 20
	Successfully Written in the File!!
	shivam@shivam:~/Desktop/Handsonlist_1/P10$ od -c file.txt 
	0000000   1   2   3   4   5   6   7   8   9   0  \0  \0  \0  \0  \0  \0
	0000020  \0  \0  \0  \0   A   B   C   D   E   F   G   H   I   J
	0000036
	shivam@shivam:~/Desktop/Handsonlist_1/P10$ 
*/
