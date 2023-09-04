#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	char *args[] = {"ls", "-l", "-R", (char*)NULL};
	execvp("ls", args);
	return 0;
}
