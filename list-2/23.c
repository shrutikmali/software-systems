/*
============================================================================
Name : 23.c
Author : Shrutik Mali
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 10 Oct 2023
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
	long pipe_buff, max_open;
	pipe_buff = pathconf(".", _PC_PIPE_BUF);
	max_open = sysconf(_SC_OPEN_MAX);
	printf("Max pipe buffer: %ld\n", pipe_buff);
	printf("Max files open: %ld\n", max_open);
	return 0;
}
