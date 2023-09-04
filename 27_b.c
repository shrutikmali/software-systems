#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	execlp("ls", "-R", "-l", (char*)NULL);
	return 0;
}
