/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 17A.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to simulate online ticket reservation. Implement write lock
		A. Write a program to open a file, store a ticket number and exit.
Date: 02 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf() perror()
#include <stdlib.h> // exit()
#include <unistd.h> // write() close()
#include <fcntl.h> // open()

int main(){
	int fd;
	int ticket_no = 1;

    	fd = open("db.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
    	if (fd == -1) {
        	perror("open");
        	exit(1);
    	}

    	write(fd, &ticket_no, sizeof(ticket_no));
	printf("Ticket no: %d\n", ticket_no);

   	close(fd);
	return 0;
}
/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P17$ cc -o 17A 17A.c
	shivam@shivam:~/Desktop/Handsonlist_1/P17$ ./17A
	Ticket no: 1
	shivam@shivam:~/Desktop/Handsonlist_1/P17$
*/	
