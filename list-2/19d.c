#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int res = mkfifo("mkfifo_libcall", 0744);
	if(res == -1) {
		printf("Error making FIFO file\n");
		return -1;
	}
	else {
		printf("FIFO file made\n");
	}
	return 0;
}
