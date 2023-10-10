#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/select.h>

int main() {
	int fd = open("myfifo", O_RDONLY);

	fd_set stdin_set;
	struct timeval timelimit;
	FD_ZERO(&stdin_set);
	FD_SET(fd, &stdin_set);

	timelimit.tv_sec = 10;

	int res = select(1, &stdin_set, NULL, NULL, &timelimit);
	if(res) {
		printf("Data is available\n");
	}
	else {
		printf("No data available\n");
	}
	return 0;
}
