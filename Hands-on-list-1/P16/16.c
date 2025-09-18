/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 16.c 
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to perform mandatory locking.
		a. Implement write lock
		b. Implement read lock
Date: 02 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/


#include <stdio.h> // printf() perror() getchar()
#include <stdlib.h> // exit()
#include <unistd.h> // close() getpid()
#include <fcntl.h> // open() fcntl()

void lockFile(int fd, short type){
	struct flock lock;
	lock.l_type = type;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	
	if(type == F_WRLCK)
		printf("Trying to acquire write lock...\n"); 
	else
		printf("Trying to acquire read lock...\n");

	fcntl(fd,F_SETLKW,&lock);
	
	if(type == F_WRLCK)
		printf("Write lock acquired successfully by PID %d\n",getpid());
	else
		printf("Read lock acquired successfully by PID %d\n", getpid());
}

void unlockFile(int fd){
	struct flock lock;
        lock.l_type = F_UNLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_pid = getpid();

	fcntl(fd,F_SETLK,&lock);

	printf("Lock released by PID %d\n", getpid());
}
int main(int argc, char* argv[]){
	if(argc != 3){
		printf("Enter Valid Input!!\n");
		exit(1);
	}

	int fd = open(argv[1],O_RDWR);

	if(fd == -1){
		perror("open");
		exit(1);
	}

	if(argv[2][0] == 'w') lockFile(fd,F_WRLCK);
	else	lockFile(fd,F_RDLCK);

	printf("Press Enter to release the lock : ");
	getchar();

	unlockFile(fd);
	close(fd);

	return 0;

}

/*
 Output: Terminal 1
 	shivam@shivam:~/Desktop/Handsonlist_1/P16$ vim 16.c
	shivam@shivam:~/Desktop/Handsonlist_1/P16$ cc -o 16 16.c
	shivam@shivam:~/Desktop/Handsonlist_1/P16$ ./16 
	Enter Valid Input!!
	shivam@shivam:~/Desktop/Handsonlist_1/P16$ ./16 file w
	Trying to acquire write lock...
	Write lock acquired successfully by PID 16870
	Press Enter to release the lock : 
*/

/*
 Output: Terminal 2
 	shivam@shivam:~/Desktop/Handsonlist_1/P16$ ./16 file r
	Trying to acquire read lock...

*/
