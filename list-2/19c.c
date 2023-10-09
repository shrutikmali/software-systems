#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
	int res = mknod("syscall_fifo", S_IFIFO, 0);
	if(res == -1) {
		printf("Error in making fifo\n");
	}
	else {
		printf("FIFO file made\n");
	}
	return 0;
}
