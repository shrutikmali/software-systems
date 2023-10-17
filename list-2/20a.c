/*
============================================================================
Name : 20a.c
Author : Shrutik Mali
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 9 Oct 2023
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
	mkfifo("myfifo", 0777);
	int fd = open("./myfifo", O_WRONLY);
	if(fd == -1) {
		printf("Error opening FIFO\n");
		return -1;
	}
	printf("FIFO opened\n");
	while(1) {
		printf("Enter message to send: ");
		char buffer[100];
		scanf("%s", buffer);
		write(fd, &buffer, sizeof(buffer));
	}

	return 0;
}
