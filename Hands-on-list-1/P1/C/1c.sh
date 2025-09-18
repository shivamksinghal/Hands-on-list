: << 'COMMENT'
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 1c.sh
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Create the following types of a files using (i) shell command
	      c. FIFO (mkfifo Library Function or mknod system call)
Date: 28 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
COMMENT

mkfifo myfifo
mknod myfifo2 p

: << 'COMMENT'
shivam@shivam:~/Desktop/Handsonlist_1/P1/C$ ./1c.sh 
shivam@shivam:~/Desktop/Handsonlist_1/P1/C$ ls -l
total 4
-rwxrwxr-x 1 shivam shivam 887 Aug  28 19:01 1c.sh
prw-rw-r-- 1 shivam shivam   0 Aug  28 19:02 myfifo
prw-rw-r-- 1 shivam shivam   0 Aug  28 19:02 myfifo2
shivam@shivam:~/Desktop/Handsonlist_1/P1/C$ 
COMMENT
