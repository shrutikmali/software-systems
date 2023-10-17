/*
============================================================================
Name : 19d.c
Author : Shrutik Mali
Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 9 Oct 2023
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int res = mkfifo("mkfifo_libcall", 0744);
	if(res == -1) {
		printf("Error making FIFO file\n");
		return -1;
	}
	else {
		printf("FIFO file made\n");
	}
	return 0;
}
