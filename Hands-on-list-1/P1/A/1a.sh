: << 'COMMENT'
--------------------------------------------------------------------
--------------------------------------------------------------------
Name : 1a.sh
Author : SHIVAM SINGHAL
Roll No : MT2025115
Description : Create the following types of a files using (i) shell command
	      a. soft link (symlink system call)
Date: 28 Aug, 2025
--------------------------------------------------------------------
--------------------------------------------------------------------
COMMENT

ln -s original.txt softlink.txt

: << 'COMMENT'
shivam@shivam:~/Desktop/Handsonlist_1/P1/A$ echo "Testing soft link working properly or not!" > original.txt
shivam@shivam:~/Desktop/Handsonlist_1/P1/A$ ./1a.sh 
shivam@shivam:~/Desktop/Handsonlist_1/P1/A$ ls -l
total 8
-rwxrwxr-x 1 shivam shivam 550 Aug  28 18:31 1a.sh
-rw-rw-r-- 1 shivam shivam  43 Aug  28 18:35 original.txt
lrwxrwxrwx 1 shivam shivam  12 Aug  28 18:36 softlink.txt -> original.txt
shivam@shivam:~/Desktop/Handsonlist_1/P1/A$ cat softlink.txt 
Testing soft link working properly or not!
shivam@shivam:~/Desktop/Handsonlist_1/P1/A$ 

COMMENT
