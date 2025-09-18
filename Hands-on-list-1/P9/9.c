/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 9.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to print the following information about a given file.
		a. inode
		b. number of hard links
		c. uid
		d. gid
		e. size
		f. block size
		g. number of blocks
		h. time of last access
		i. time of last modification
		j. time of last change
Date: 30 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf() perror()
#include <stdlib.h> // exit()
#include <sys/stat.h> // stat()
#include <unistd.h> // 
#include <time.h> // ctime()

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Enter valid input!!\n");
        exit(1);
    }

    struct stat file_info;

    if (stat(argv[1], &file_info) == -1) {
        perror("stat");
        exit(1);
    }

    printf("File: %s\n", argv[1]);
    printf("a. Inode: %ld\n", (long)file_info.st_ino);
    printf("b. Number of hard links: %ld\n", (long)file_info.st_nlink);
    printf("c. UID: %d\n", file_info.st_uid);
    printf("d. GID: %d\n", file_info.st_gid);
    printf("e. Size: %ld bytes\n", (long)file_info.st_size);
    printf("f. Block size: %ld bytes\n", (long)file_info.st_blksize);
    printf("g. Number of blocks: %ld\n", (long)file_info.st_blocks);
    printf("h. Time of last access: %s", ctime(&file_info.st_atime));
    printf("i. Time of last modification: %s", ctime(&file_info.st_mtime));
    printf("j. Time of last change: %s", ctime(&file_info.st_ctime));

    return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P9$ vim 9.c
	shivam@shivam:~/Desktop/Handsonlist_1/P9$ cc -o 9 9.c
	shivam@shivam:~/Desktop/Handsonlist_1/P9$ ./9 ../P8/file1.txt 
	File: ../P8/file1.txt
	a. Inode: 6686434
	b. Number of hard links: 1
	c. UID: 1000
	d. GID: 1000
	e. Size: 59 bytes
	f. Block size: 4096 bytes
	g. Number of blocks: 8
	h. Time of last access: Sat Aug 30 19:12:19 2025
	i. Time of last modification: Sat Aug 30 19:12:14 2025
	j. Time of last change: Sat Aug 30 19:12:14 2025
	shivam@shivam:~/Desktop/Handsonlist_1/P9$ 
*/
