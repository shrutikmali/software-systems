#include <stdio.h>
#include <unistd.h>

int main() {
	long pipe_buff, max_open;
	pipe_buff = pathconf(".", _PC_PIPE_BUF);
	max_open = sysconf(_SC_OPEN_MAX);
	printf("Max pipe buffer: %ld\n", pipe_buff);
	printf("Max files open: %ld\n", max_open);
	return 0;
}
