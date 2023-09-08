/*
============================================================================
Name : 12
Author : Shrutik Mali
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 24 Aug 2023.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *args[]) {
	if(argc != 2) {
		printf("Expected 1 argument\n");
		return -1;
	}
	int fd = open(args[1], O_RDWR);
	int access_mode = fcntl(fd, F_GETFL);
	printf("access mode: %d\n", access_mode);
	close(fd);
	return 0;
}
