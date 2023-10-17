/*
============================================================================
Name : 22.c
Author : Shrutik Mali
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 10 Oct 2023
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/select.h>

int main() {
	int fd = open("myfifo", O_RDONLY);

	fd_set stdin_set;
	struct timeval timelimit;
	FD_ZERO(&stdin_set);
	FD_SET(fd, &stdin_set);

	timelimit.tv_sec = 10;

	int res = select(1, &stdin_set, NULL, NULL, &timelimit);
	if(res) {
		printf("Data is available\n");
	}
	else {
		printf("No data available\n");
	}
	return 0;
}
