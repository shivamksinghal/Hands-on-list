/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 8.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
	      Close the file when end of file is reached.
Date: 30 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf()  perror()
#include <stdlib.h> // exit()
#include <unistd.h> // read() close()
#include <fcntl.h> // open() O_RDONLY

int main(int argc, char* argv[]){

	if(argc != 2){
		printf("Enter Valid Input!!\n");
		exit(1);
	}

	int fd,n,i;
	char buff[256];
	fd = open(argv[1],O_RDONLY);
	if(fd == -1){
		perror("File opening Failed");
		exit(1);
	}
	while((n = read(fd,buff,sizeof(buff))) > 0){
		for(i = 0; i < n; i++){
			putchar(buff[i]);
		}
	}
	close(fd);
	return 0;
}
/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P8$ vim 8.c
	shivam@shivam:~/Desktop/Handsonlist_1/P8$ cc -o 8 8.c
	shivam@shivam:~/Desktop/Handsonlist_1/P8$ ./8 
	Enter Valid Input!!
	shivam@shivam:~/Desktop/Handsonlist_1/P8$ ./8 file1.txt
	Hi Shivam here
	Writing Code for Software Systems

	Thanks!!
	shivam@shivam:~/Desktop/Handsonlist_1/P8$
*/	
