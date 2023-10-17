/*
============================================================================
Name : 20b.c
Author : Shrutik Mali
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 9 Oct 2023
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
	int fd = open("myfifo", O_RDONLY);
	if(fd == -1) {
		printf("Error opening FIFO\n");
		return -1;
	}
	char buff[100];
	while(read(fd, &buff, sizeof(buff))) {
		printf("Message from FIFO: %s\n", buff);
	}
	return 0;
}
