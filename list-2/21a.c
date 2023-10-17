/*
============================================================================
Name : 21a.c
Author : Shrutik Mali
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 9 Oct 2023
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
	int fifo_atob = mkfifo("fifo_atob", 0777);
	int fifo_btoa = mkfifo("fifo_btoa", 0777);

	int read_fd = open("fifo_btoa", O_RDONLY);
	int write_fd = open("fifo_atob", O_WRONLY);
	char buff[100];
	while(1) {
		printf("Enter message to send: ");
		scanf("%s", buff);
		write(write_fd, &buff, sizeof(buff));
		read(read_fd, &buff, sizeof(buff));
		printf("Received message: %s\n", buff);
	}

	return 0;
}
