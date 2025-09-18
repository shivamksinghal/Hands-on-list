/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 18.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to perform Record locking.
		a. Implement write lock
		b. Implement read lock
	      Create three records in a file. Whenever you access a particular record, first lock it then modify/access
	      to avoid race condition.
Date: 02 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf() perror() getchar()
#include <stdlib.h> // exit() atoi()
#include <unistd.h> // getpid() lseek() write()
#include <fcntl.h> // open() fcntl()


void lock_record(int fd, int record_no, int lock_type) {
	struct flock lock;
    	lock.l_type = lock_type;           
    	lock.l_whence = SEEK_SET;
   	lock.l_start = record_no * sizeof(int);
    	lock.l_len = sizeof(int);           
    	lock.l_pid = getpid();

    	fcntl(fd, F_SETLKW, &lock);
}

void unlock_record(int fd, int record_no) {
	struct flock lock;
    	lock.l_type = F_UNLCK;
   	lock.l_whence = SEEK_SET;
    	lock.l_start = record_no * sizeof(int);
    	lock.l_len = sizeof(int);
    	lock.l_pid = getpid();

    	fcntl(fd, F_SETLK, &lock);
}

int main(int argc, char *argv[]) {
    
	if (argc != 3) {
        printf("Enter valid input!!\n");
        exit(1);
    }

    	int record_no = atoi(argv[1]);
   	char mode = argv[2][0];
    	int fd, data;

    	fd = open("file.txt", O_RDWR | O_CREAT, 0666);
    	if (fd == -1) {
        	perror("open");
        	exit(1);
    	}

    	off_t filesize = lseek(fd, 0, SEEK_END);
    	if (filesize < 3 * sizeof(int)) {
        	int arr[3] = {100, 200, 300};
        	write(fd, arr, sizeof(arr));
    	}

    	if (mode == 'r') {
        	printf("Process %d: Trying to READ record %d\n", getpid(), record_no);
        	lock_record(fd, record_no, F_RDLCK);

        	lseek(fd, record_no * sizeof(int), SEEK_SET);
        	read(fd, &data, sizeof(data));
        	printf("Process %d: Read record[%d] = %d\n", getpid(), record_no, data);

        	getchar();

        	unlock_record(fd, record_no);
        	printf("Process %d: Released READ lock on record %d\n", getpid(), record_no);

    	} 
    	else if (mode == 'w') {
        	printf("Process %d: Trying to WRITE record %d\n", getpid(), record_no);
        	lock_record(fd, record_no, F_WRLCK);

        	lseek(fd, record_no * sizeof(int), SEEK_SET);
        	read(fd, &data, sizeof(data));
        	printf("Process %d: Current value = %d\n", getpid(), data);
 
        	data += 10;
        	lseek(fd, record_no * sizeof(int), SEEK_SET);
        	write(fd, &data, sizeof(data));
        	printf("Process %d: Updated record[%d] = %d\n", getpid(), record_no, data);

        	getchar();

        	unlock_record(fd, record_no);
        	printf("Process %d: Released WRITE lock on record %d\n", getpid(), record_no);

    	}

    	close(fd);
    	return 0;
}
/*
 Output:
	// Terminal 1
	shivam@shivam:~/Desktop/Handsonlist_1/P18$ vim 18.c
	shivam@shivam:~/Desktop/Handsonlist_1/P18$ cc -o 18 18.c
	shivam@shivam:~/Desktop/Handsonlist_1/P18$ ./18 1 w
	Process 7027: Trying to WRITE record 1
	Process 7027: Current value = 200
	Process 7027: Updated record[1] = 210
 
	// Terminal 2
	shivam@shivam:~/Desktop/Handsonlist_1/P18$ ./18 1 w
	Process 7039: Trying to WRITE record 1

	// Terminal 3
	shivam@shivam:~/Desktop/Handsonlist_1/P18$ ./18 2 w
	Process 7049: Trying to WRITE record 2
	Process 7049: Current value = 300
	Process 7049: Updated record[2] = 310

	// Terminal 4
	shivam@shivam:~/Desktop/Handsonlist_1/P18$ ./18 2 r
	Process 7071: Trying to READ record 2
*/

