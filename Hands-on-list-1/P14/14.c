/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 14.c
Author : SHIVAM SINGHAL 
Roll No : MT2025115
Description : Write a program to find the type of a file.
		a. Input should be taken from command line.
		b. Program should be able to identify any type of a file.
Date: 01 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf() //perror()
#include <stdlib.h> // exit()
#include <unistd.h>
#include <sys/stat.h> // lstat()
int main(int argc, char* argv[]){
	if(argc != 2){
		printf("Enter Valid Input!!\n");
		exit(1);
	}
	struct stat file_info;

	if(lstat(argv[1], &file_info) == -1){
		perror("lstat");
		exit(1);	
	}

	printf("File: %s\n", argv[1]);
	printf("File type : ");
	switch (file_info.st_mode & S_IFMT) {

		case S_IFREG:  printf("Regular file\n"); break;
	   	case S_IFDIR:  printf("Directory\n"); break;
	   	case S_IFLNK:  printf("Symbolic link\n"); break;
  	        case S_IFCHR:  printf("Character device\n"); break;
    		case S_IFBLK:  printf("Block device\n"); break;
    		case S_IFIFO:  printf("FIFO\n"); break;
    		case S_IFSOCK: printf("Socket\n"); break;
    		default:       printf("Unknown?\n");
	}

	return 0;
}
/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P14$ vim 14.c
	shivam@shivam:~/Desktop/Handsonlist_1/P14$ cc -o 14 14.c
	shivam@shivam:~/Desktop/Handsonlist_1/P14$ ./14
	Enter Valid Input!!
	shivam@shivam:~/Desktop/Handsonlist_1/P14$ ./14 /
	File: /
	File type : Directory
	shivam@shivam:~/Desktop/Handsonlist_1/P14$ ./14 ../P1/A/softlink.txt 
	File: ../P1/A/softlink.txt
	File type : Symbolic link
	shivam@shivam:~/Desktop/Handsonlist_1/P14$ ./14 ../P1/A/shelloutput.txt 
	File: ../P1/A/shelloutput.txt
	File type : Regular file
	shivam@shivam:~/Desktop/Handsonlist_1/P14$ 
*/
