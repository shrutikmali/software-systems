/*
============================================================================
Name : 21
Author : Shrutik Mali
Description : Write a program, call fork and print the parent and child process id.
Date: 25 Aug 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
	int child_pid = fork();
	if(child_pid) {
		printf("PID of parent process: %d\n", getpid());
	}
	else {
		printf("PID of child process: %d\n", getpid());
	}
	return 0;
}
