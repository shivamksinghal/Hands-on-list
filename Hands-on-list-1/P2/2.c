/*
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 2.c
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
	      identify all the process related information in the corresponding proc directory.
Date: 28 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
*/

#include <stdio.h>
void main(){
	while(1);
}

/*
 Output:
 	shivam@shivam:~/Desktop/Handsonlist_1/P2$ vim 2.c
	shivam@shivam:~/Desktop/Handsonlist_1/P2$ cc -o 2 2.c
	shivam@shivam:~/Desktop/Handsonlist_1/P2$ ./2 &
	[1] 22097
	shivam@shivam:~/Desktop/Handsonlist_1/P2$ more /proc/22097/status
	Name:	2
	Umask:	0002
	State:	R (running)
	Tgid:	22097
	Ngid:	0
	Pid:	22097
	PPid:	16458
	TracerPid:	0
	Uid:	1000	1000	1000	1000
	Gid:	1000	1000	1000	1000
	FDSize:	256
	Groups:	4 24 27 30 46 122 135 136 1000 
	NStgid:	22097
	NSpid:	22097
	NSpgid:	22097
	NSsid:	16458
	Kthread:	0
	VmPeak:	    2716 kB
	VmSize:	    2644 kB
	VmLck:	       0 kB
	VmPin:	       0 kB
	VmHWM:	    1024 kB
	VmRSS:	    1024 kB
	RssAnon:	       0 kB
	RssFile:	    1024 kB
	RssShmem:	       0 kB
	VmData:	      92 kB
	VmStk:	     132 kB
	VmExe:	       4 kB
	VmLib:	    1796 kB
	VmPTE:	      40 kB
	VmSwap:	       0 kB
	HugetlbPages:	       0 kB
	CoreDumping:	0
	shivam@shivam:~/Desktop/Handsonlist_1/P2$ 
 */
