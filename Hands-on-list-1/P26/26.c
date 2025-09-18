/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 26.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to execute an executable program.
		a. use some executable program
		b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 05 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h>
#include <unistd.h> // execv()
int main()
{  
    char* arg[] = {"cat", "file.txt",NULL};
    execv("/bin/cat", arg);
    return 0;
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P26$ vim 26.c
	shivam@shivam:~/Desktop/Handsonlist_1/P26$ cc -o 26 26.c
	shivam@shivam:~/Desktop/Handsonlist_1/P26$ ./26
	Hi Shivam here
	Writing Code for Software Systems
	Thanks!!
	shivam@shivam:~/Desktop/Handsonlist_1/P26$ 
*/
