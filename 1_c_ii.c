/*
============================================================================
Name : 1_a_ii
Author : Shrutik Mali
Description : Create named fifo
Date: 7 Sep 2023.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
	int res = mknod("fifo_using_system_call", S_IFIFO, 0);
	if(res == -1) {
		printf("Error occurred\n");
		return -1;
	}
	printf("FIFO made\n");
	return 0;
}
