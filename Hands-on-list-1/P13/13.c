/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 13.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
	      verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 01 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf() perror()
#include <stdlib.h> // exit()
#include <unistd.h> // read() 
#include <sys/select.h> // select()

int main() {
    fd_set read_fd;
    struct timeval timeout;
    int n;

    FD_ZERO(&read_fd);
    FD_SET(0, &read_fd);    
    timeout.tv_sec = 10;   
    timeout.tv_usec = 0;

    printf("Waiting for input for 10 seconds...\n");

    n = select(1, &read_fd, NULL, NULL, &timeout);

    if(n == -1){
	    perror("select error");
	    exit(1);
    }
    else if(n == 0){
	    printf("No input within 10 seconds.\n");
    }
    else{
	    char buff[100];
            int n = read(0,buff,sizeof(buff)-1);
            buff[n] = '\0';
            printf("Data available on STDIN is -->  %s\n",buff);
    }
    return 0;
}
/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P13$ vim 13.c
	shivam@shivam:~/Desktop/Handsonlist_1/P13$ ./13
	Waiting for input for 10 seconds...
	shivam singhal
	Data available on STDIN is -->  shivam singhal

	shivam@shivam:~/Desktop/Handsonlist_1/P13$ ./13
	Waiting for input for 10 seconds...
	No input within 10 seconds.
	shivam@shivam:~/Desktop/Handsonlist_1/P13$ 
*/
