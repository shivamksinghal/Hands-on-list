/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 30.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 06 Sep, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h> // printf()
#include <stdlib.h> // exit() system()
#include <unistd.h> // fork() sleep() setsid() chdir()
#include <sys/stat.h> // umask()

int main() {
	pid_t pid = fork();
    	if (pid > 0)
		exit(0);
	printf("Pid is : %d\n",getpid());
	umask(0);
    	setsid();
    	chdir("/");
  	while (1) {
        	system("/home/shivam/Desktop/Handsonlist_1/P30/myscript.sh");
        	sleep(10);
    	}
    	return 0;
}

/*
 Output:
 
 	//Terminal
 	shivam@shivam:~/Desktop/Handsonlist_1/P30$ vim 30.c
 	shivam@shivam:~/Desktop/Handsonlist_1/P30$ cc -o 30 30.c
	shivam@shivam:~/Desktop/Handsonlist_1/P30$ ./30
	Pid is : 5031
	shivam@shivam:~/Desktop/Handsonlist_1/P30$ kill 5031
	shivam@shivam:~/Desktop/Handsonlist_1/P30$
	
	//daemon_log.txt
	Script ran at: Saturday 06 September 2025 06:46:25 PM IST
	Script ran at: Saturday 06 September 2025 06:46:35 PM IST
	Script ran at: Saturday 06 September 2025 06:46:45 PM IST
	Script ran at: Saturday 06 September 2025 06:46:55 PM IST
	Script ran at: Saturday 06 September 2025 06:47:05 PM IST
	Script ran at: Saturday 06 September 2025 06:47:15 PM IST 
*/

