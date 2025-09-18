/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 1a.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Create the following types of a files using (ii) system call
		a. soft link (symlink system call)
Date: 28 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf(), perror()
#include <unistd.h>// symlink()

int main(){
	const char* original = "original.txt";
	const char* c_softlink = "c_softlink.txt";

	if(symlink(original,c_softlink) == -1){
		perror("symlink failed");
		return 1;
	}
	printf("Soft Link is successfully created %s -> %s\n",c_softlink,original);
	return 0;
}

/*
 Output
 	shivam@shivam:~/Desktop/Handsonlist_1/P1/A$ vim sym_link.c
	shivam@shivam:~/Desktop/Handsonlist_1/P1/A$ cc -o sym_link sym_link.c
	shivam@shivam:~/Desktop/Handsonlist_1/P1/A$ ./sym_link 
	Soft Link is successfully created c_softlink.txt -> original.txt
	shivam@shivam:~/Desktop/Handsonlist_1/P1/A$ cc -o sym_link sym_link.c
	shivam@shivam:~/Desktop/Handsonlist_1/P1/A$ ./sym_link 
	symlink failed: File exists
	shivam@shivam:~/Desktop/Handsonlist_1/P1/A$ ls -l
	total 28
	lrwxrwxrwx 1 shivam shivam    12 Aug 24 15:21 c_softlink.txt -> original.txt
	-rw-rw-r-- 1 shivam shivam    43 Aug 24 14:49 original.txt
	-rw-rw-r-- 1 shivam shivam   496 Aug 24 14:55 shelloutput.txt
	lrwxrwxrwx 1 shivam shivam    12 Aug 24 14:49 softlink.txt -> original.txt
	-rwxrwxr-x 1 shivam shivam 16056 Aug 24 15:21 sym_link
	-rw-rw-r-- 1 shivam shivam   311 Aug 24 15:17 sym_link.c
	shivam@shivam:~/Desktop/Handsonlist_1/P1/A$ 
*/
