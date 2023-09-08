/*
============================================================================
Name : 30
Author : Shrutik Mali
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 5 Sep 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	int pid = fork();
	if(!pid) {
		int sid = setsid();
		chdir("/");
		close(0);
		close(1);
		close(2);
		printf("Daemon process\n");
		while(1);
	}
	else {
		printf("Child pid is: %d\n", pid);
		printf("Parent exiting\n");
		exit(0);
	}
	return 0;
}
