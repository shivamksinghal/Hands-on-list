/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 5.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to create five new files with infinite loop. Execute the program in the background
	      and check the file descriptor table at /proc/pid/fd.
Date: 29 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // perror()
#include <stdlib.h> // exit()
#include <unistd.h> // sleep()
#include <fcntl.h> // creat()
#include <string.h> //strcpy() strcar()
int main(){
	int i;
	char filename[20];
	while(1){
		for(i=1;i<=5;i++){
			strcpy(filename,"file");
			filename[4] = i + '0';
			filename[5] = '\0';
			strcat(filename,".txt");
			int fd = creat(filename,0666);
			if(fd == -1){
				perror("Failed!!");
				exit(1);
			}
			sleep(1);	
		}
	}
	return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P5$ vim 5.c
	shivam@shivam:~/Desktop/Handsonlist_1/P5$ cc -o 5 5.c
	shivam@shivam:~/Desktop/Handsonlist_1/P5$ ./5 &
	[1] 24514
	shivam@shivam:~/Desktop/Handsonlist_1/P5$ ls -lv /proc/24514/fd
	total 0
	lrwx------ 1 shivam shivam 64 Aug 29 22:24 0 -> /dev/pts/0
	lrwx------ 1 shivam shivam 64 Aug 29 22:24 1 -> /dev/pts/0
	lrwx------ 1 shivam shivam 64 Aug 29 22:24 2 -> /dev/pts/0
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 3 -> /home/shivam/Desktop/Handsonlist_1/P5/file1.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 4 -> /home/shivam/Desktop/Handsonlist_1/P5/file2.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 5 -> /home/shivam/Desktop/Handsonlist_1/P5/file3.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 6 -> /home/shivam/Desktop/Handsonlist_1/P5/file4.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 7 -> /home/shivam/Desktop/Handsonlist_1/P5/file5.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 8 -> /home/shivam/Desktop/Handsonlist_1/P5/file1.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 9 -> /home/shivam/Desktop/Handsonlist_1/P5/file2.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 10 -> /home/shivam/Desktop/Handsonlist_1/P5/file3.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 11 -> /home/shivam/Desktop/Handsonlist_1/P5/file4.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 12 -> /home/shivam/Desktop/Handsonlist_1/P5/file5.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 13 -> /home/shivam/Desktop/Handsonlist_1/P5/file1.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 14 -> /home/shivam/Desktop/Handsonlist_1/P5/file2.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 15 -> /home/shivam/Desktop/Handsonlist_1/P5/file3.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 16 -> /home/shivam/Desktop/Handsonlist_1/P5/file4.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 17 -> /home/shivam/Desktop/Handsonlist_1/P5/file5.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 18 -> /home/shivam/Desktop/Handsonlist_1/P5/file1.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 19 -> /home/shivam/Desktop/Handsonlist_1/P5/file2.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 20 -> /home/shivam/Desktop/Handsonlist_1/P5/file3.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 21 -> /home/shivam/Desktop/Handsonlist_1/P5/file4.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 22 -> /home/shivam/Desktop/Handsonlist_1/P5/file5.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 23 -> /home/shivam/Desktop/Handsonlist_1/P5/file1.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 24 -> /home/shivam/Desktop/Handsonlist_1/P5/file2.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 25 -> /home/shivam/Desktop/Handsonlist_1/P5/file3.txt
	l-wx------ 1 shivam shivam 64 Aug 29 22:24 26 -> /home/shivam/Desktop/Handsonlist_1/P5/file4.txt
*/

