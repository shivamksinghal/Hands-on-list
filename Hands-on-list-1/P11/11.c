/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 11.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
	      descriptors and check whether the file is updated properly or not.
		a. use dup
		b. use dup2
		c. use fcntl
Date: 31 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf() perror()
#include <stdlib.h> // exit()
#include <unistd.h> // dup() dup2() write()
#include <fcntl.h> // open() fcntl()
#include <string.h> // strlen()
int main(){
	int fd,dup_fd;
	char arr1[] = "dup() original fd\n"; 
	char arr2[] = "dup() duplicate fd\n";
	char arr3[] = "dup2() original fd\n";
	char arr4[] = "dup2() duplicate fd\n";
	char arr5[] = "fcntl() original fd\n";
	char arr6[] = "fcntl() duplicate fd\n";

//----------------------------A-----------------------------------//
	
	fd = open("file.txt",O_WRONLY | O_CREAT | O_APPEND, 0666);

	if(fd == -1){
		perror("open");
		exit(1);
	}

	printf("Original fd = %d\n",fd);
	
	dup_fd = dup(fd);

	printf("Duplicate fd using dup() = %d\n",dup_fd);

	write(fd, arr1, strlen(arr1));
	write(dup_fd, arr2, strlen(arr2));

	close(fd);
	close(dup_fd);

//----------------------------B-----------------------------------//
	
	fd = open("file.txt",O_WRONLY | O_CREAT | O_APPEND, 0666);

        if(fd == -1){
                perror("open");
                exit(1);
        }

        dup_fd = dup2(fd,11);

        printf("Duplicate fd using dup2() = %d\n",dup_fd);

        write(fd, arr3, strlen(arr3));
        write(dup_fd, arr4, strlen(arr4));

        close(fd);
        close(dup_fd);

//----------------------------C-----------------------------------//
	
	fd = open("file.txt",O_WRONLY | O_CREAT | O_APPEND, 0666);

        if(fd == -1){
                perror("open");
                exit(1);
        }

        dup_fd = fcntl(fd,F_DUPFD,0);

        printf("Duplicate fd using fcntl() = %d\n",dup_fd);

        write(fd, arr5, strlen(arr5));
        write(dup_fd, arr6, strlen(arr6));

        close(fd);
        close(dup_fd);

	return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P11$ vim 11.c
	shivam@shivam:~/Desktop/Handsonlist_1/P11$ cc -o 11 11.c
	shivam@shivam:~/Desktop/Handsonlist_1/P11$ ./11
	Original fd = 3
	Duplicate fd using dup() = 4
	Duplicate fd using dup2() = 11
	Duplicate fd using fcntl() = 4
	shivam@shivam:~/Desktop/Handsonlist_1/P11$ cat file.txt 
	dup() original fd
	dup() duplicate fd
	dup2() original fd
	dup2() duplicate fd
	fcntl() original fd
	fcntl() duplicate fd
	shivam@shivam:~/Desktop/Handsonlist_1/P11$ 
*/
