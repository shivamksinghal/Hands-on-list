: << 'COMMENT'
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 1b.sh
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Create the following types of a files using (i) shell command
	      b. hard link (link system call)
Date: 28 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
COMMENT

ln original.txt hardlink.txt

: << 'COMMENT'
shivam@shivam:~/Desktop/Handsonlist_1/P1/B$ echo "Testing for hard link" > original.txt
shivam@shivam:~/Desktop/Handsonlist_1/P1/B$ ./1b.sh 
shivam@shivam:~/Desktop/Handsonlist_1/P1/B$ ls -l
total 12
-rwxrwxr-x 1 shivam shivam 1003 Aug  28 18:52 1b.sh
-rw-rw-r-- 2 shivam shivam   22 Aug  28 18:52 hardlink.txt
-rw-rw-r-- 2 shivam shivam   22 Aug  28 18:52 original.txt
shivam@shivam:~/Desktop/Handsonlist_1/P1/B$ cat hardlink.txt 
Testing for hard link
shivam@shivam:~/Desktop/Handsonlist_1/P1/B$ 
COMMENT
