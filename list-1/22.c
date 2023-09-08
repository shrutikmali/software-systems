/*
============================================================================
Name : 22
Author : Shrutik Mali
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
              parent processes. Check output of the file.
Date: 1 Sep 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	int fd = open("file22.txt", O_RDWR);
	int pid = fork();
	if(!pid) {
		char childBuff[] = "Written by child\n";
		int writeRes = write(fd, &childBuff, sizeof(childBuff));
	}
	else {
		char parentBuff[] = "Written by parent\n";
		int writeRes = write(fd, &parentBuff, sizeof(parentBuff));
	}
	return 0;
}
