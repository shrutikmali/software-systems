/*
============================================================================
Name : 16
Author : Shrutik Mali
Description : Write a program to perform mandatory locking.
		a. Implement write lock
		b. Implement read lock
Date: 24 Aug 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *args[]) {
	if(argc != 2) {
		printf("Expected 1 argument\n");
		return -1;
	}
	struct flock lock;
	// Write lock
	int fd = open(args[1], O_WRONLY);
	if(fd == -1) {
		printf("Could not open file\n");
		return -1;
	}
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Acquiring lock\n");
	fcntl(fd, F_SETLKW, &lock);
	printf("Lock acquired\n");
	printf("Press any key to release lock\n");
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("Lock released\n");
	return 0;
}
