/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 1c.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Create the following types of a files using (ii) system call
		c. FIFO (mkfifo Library Function or mknod system call)
Date: 28 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf() perror()
#include <sys/types.h>
#include <sys/stat.h> // mkfifo()

int main(){
	const char* filename = "fifo1";
	if(mkfifo(filename,0666) == -1){
		perror("File not created");
		return 1;
	}
	printf("FIFO file is successfully created --> %s\n",filename);
	return 0;
}
/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P1/C$ vim 1c.c
	shivam@shivam:~/Desktop/Handsonlist_1/P1/C$ cc -o 1c 1c.c
	shivam@shivam:~/Desktop/Handsonlist_1/P1/C$ ./1c
	FIFO file is successfully created --> fifo1
	shivam@shivam:~/Desktop/Handsonlist_1/P1/C$ ls -l
	total 24
	-rwxrwxr-x 1 shivam shivam 16048 Aug  28 19:08 1c
	-rw-rw-r-- 1 shivam shivam  1459 Aug  28 19:07 1c.c
	-rwxrwxr-x 1 shivam shivam   880 Aug  28 19:03 1c.sh
	prw-rw-r-- 1 shivam shivam     0 Aug  28 19:08 fifo1
	prw-rw-r-- 1 shivam shivam     0 Aug  28 19:02 myfifo
	prw-rw-r-- 1 shivam shivam     0 Aug  28 19:02 myfifo2
	shivam@shivam:~/Desktop/Handsonlist_1/P1/C$ 
*/
