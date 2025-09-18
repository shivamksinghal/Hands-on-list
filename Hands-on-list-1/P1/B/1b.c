/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 1b.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Create the following types of a files using (ii) system call
		b. hard link (link system call)
Date: 28 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf() perror()
#include <unistd.h> // link()

int main(){
	const char* original = "original.txt";
	const char* hardlink = "c_hardlink.txt";

	if(link(original,hardlink) == -1){
		perror("hardlink failed");
		return 1;
	}
	printf("Hard link successfully created!!\n");
	return 0;
}

/*
 Output
	shivam@shivam:~/Desktop/Handsonlist_1/P1/B$ vim 1b.c
	shivam@shivam:~/Desktop/Handsonlist_1/P1/B$ cc -o 1b 1b.c
	shivam@shivam:~/Desktop/Handsonlist_1/P1/B$ ./1b
	Hard link successfully created!!
	shivam@shivam:~/Desktop/Handsonlist_1/P1/B$ ls -l
	total 36
	-rwxrwxr-x 1 shivam shivam 16040 Aug  28 18:56 1b
	-rw-rw-r-- 1 shivam shivam  1485 Aug  28 18:55 1b.c
	-rwxrwxr-x 1 shivam shivam  1043 Aug  28 18:54 1b.sh
	-rw-rw-r-- 3 shivam shivam    22 Aug  28 18:52 c_hardlink.txt
	-rw-rw-r-- 3 shivam shivam    22 Aug  28 18:52 hardlink.txt
	-rw-rw-r-- 3 shivam shivam    22 Aug  28 18:52 original.txt
	shivam@shivam:~/Desktop/Handsonlist_1/P1/B$ 	
 */
