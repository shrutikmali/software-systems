/*
============================================================================
Name : 19c.c
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
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
	int res = mknod("syscall_fifo", S_IFIFO, 0);
	if(res == -1) {
		printf("Error in making fifo\n");
	}
	else {
		printf("FIFO file made\n");
	}
	return 0;
}
