#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	execl("/bin/ls", "-R", "-l", (char*)NULL);
	return 0;
}
