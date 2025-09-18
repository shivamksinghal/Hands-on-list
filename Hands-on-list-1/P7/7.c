/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 7.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 30 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/
#include <stdio.h> // printf() perror()
#include <stdlib.h> // exit()
#include <unistd.h> // read() write() close() lseek()
#include <fcntl.h> // open()
int main(int argc, char* argv[]){
	
	int src_fd, dest_fd, size,n;
	
	if(argc != 3){
		printf("Enter Valid Input\n");
		exit(1);
	}
	
	src_fd = open(argv[1],O_RDONLY);
	if(src_fd == -1){
		perror("File Not Found!!");
		exit(1);
	}
	
	dest_fd = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, 0666);
	
	
	size = lseek(src_fd,0,SEEK_END);
	lseek(src_fd,0,SEEK_SET);
	
	char buff[size];
	
	n = read(src_fd,buff,size);
	write(dest_fd,buff,n);
	
	close(src_fd);
	close(dest_fd);
	
	printf("File successfully copied!!\n");
	
	return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P7$ vim 7.c
	shivam@shivam:~/Desktop/Handsonlist_1/P7$ ls
	7  7.c  file1.txt
	shivam@shivam:~/Desktop/Handsonlist_1/P7$ cc -o 7 7.c
	shivam@shivam:~/Desktop/Handsonlist_1/P7$ ./7
	Enter Valid Input
	shivam@shivam:~/Desktop/Handsonlist_1/P7$ ./7 file1.txt file2.txt
	File successfully copied!!
	shivam@shivam:~/Desktop/Handsonlist_1/P7$ ls
	7  7.c  file1.txt  file2.txt
	shivam@shivam:~/Desktop/Handsonlist_1/P7$ cat file1.txt
	Hi Shivam here
	Writing Code for Software Systems
	Thanks!!
	shivam@shivam:~/Desktop/Handsonlist_1/P7$ cat file2.txt
	Hi Shivam here
	Writing Code for Software Systems
	Thanks!!
	shivam@shivam:~/Desktop/Handsonlist_1/P7$
*/

