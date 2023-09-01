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
