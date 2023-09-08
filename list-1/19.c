/*
============================================================================
Name : 19
Author : Shrutik Mali
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 25 Aug 2023.
============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
	struct timeval initial;
	struct timeval final;
	gettimeofday(&initial, NULL);
	getpid();
	gettimeofday(&final, NULL);
	printf("Time required to execute getpid(): %ld microseconds\n", (final.tv_usec - initial.tv_usec));
	return 0;
}
