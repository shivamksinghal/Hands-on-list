/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 17B.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to simulate online ticket reservation. Implement write lock
                B. Write a separate program, to open the file, implement write lock, read
                   the ticket number, increment the number and print the new ticket number 
                   then close the file.
Date: 02 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf() perror()
#include <stdlib.h> // exit()
#include <fcntl.h> // fcntl() open()
#include <unistd.h> // write() read() close()

int main() {
    int fd;
    int ticket_no;

    struct flock lock;
    fd = open("db.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    lock.l_type = F_WRLCK;  
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;      
    lock.l_len = 0;
    lock.l_pid = getpid();

    fcntl(fd, F_SETLKW, &lock);

    read(fd, &ticket_no, sizeof(ticket_no));

    ticket_no++;
    lseek(fd, 0, SEEK_SET);

    write(fd, &ticket_no, sizeof(ticket_no));

    printf("New Ticket Reserved! Ticket no = %d\n", ticket_no);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P17$ cc -o 17B 17B.c
	shivam@shivam:~/Desktop/Handsonlist_1/P17$ ./17B
	New Ticket Reserved! Ticket no = 2
	shivam@shivam:~/Desktop/Handsonlist_1/P17$ ./17B
	New Ticket Reserved! Ticket no = 3
	shivam@shivam:~/Desktop/Handsonlist_1/P17$ ./17B
	New Ticket Reserved! Ticket no = 4
	shivam@shivam:~/Desktop/Handsonlist_1/P17$ 
*/
