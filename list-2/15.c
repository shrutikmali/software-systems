/*
============================================================================
Name : 15.c
Author : Shrutik Mali
Description : Write a simple program to send some data from parent to the child process.
Date: 5 Sep 2023
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	int pipefd[2];
	int res = pipe(pipefd);
	if(res != 0) {
		printf("Error occurred\n");
		return -1;
	}
	int pid = fork();
	if(!pid) {
		char buffer[10];
		read(pipefd[0], &buffer, sizeof(buffer));
		printf("Data received: %s\n", buffer);
	}
	else {
		char buffer[10];
		printf("Enter data to send: ");
		scanf("%s", buffer);
		write(pipefd[1], &buffer, sizeof(buffer));
	}
	return 0;
}
