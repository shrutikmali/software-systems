#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
	int write_fd = open("fifo_btoa", O_WRONLY);
	int read_fd = open("fifo_atob", O_RDONLY);
	char buff[100];
	while(1) {
		read(read_fd, &buff, sizeof(buff));
		printf("Received message: %s\n", buff);
		printf("Enter message to send: ");
		scanf("%s", buff);
		write(write_fd, &buff, sizeof(buff));
	}
	return 0;
}
