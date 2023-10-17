/*
============================================================================
Name : 16.c
Author : Shrutik Mali
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication
Date: 6 Sep 2023
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd1[2];
	int fd2[2];
	pipe(fd1);
	pipe(fd2);

	int pid = fork();
	if(!pid) {
		close(fd2[0]);
		close(fd1[1]);
		while(1) {
			char readBuffer[20];
			read(fd1[0], &readBuffer, sizeof(readBuffer));
			printf("Message received from parent: %s\n", readBuffer);
			printf("Enter message to send to parent: ");
			char writeBuffer[20];
			//scanf("%[^\n]", writeBuffer);
			fgets(writeBuffer, sizeof(writeBuffer), stdin);
			write(fd2[1], &writeBuffer, sizeof(writeBuffer));
		}
	}
	else {
		close(fd1[0]);
		close(fd2[1]);
		while(1) {
			char writeBuffer[20];
			printf("Enter message to send to child: ");
			//scanf("%[^\n]", writeBuffer);
			fgets(writeBuffer, sizeof(writeBuffer), stdin);
			write(fd1[1], &writeBuffer, sizeof(writeBuffer));
			char readBuffer[20];
			read(fd2[0], &readBuffer, sizeof(readBuffer));
			printf("Message received from child: %s\n", readBuffer);
		}
	}
	return 0;
}
