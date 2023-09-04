#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	char *args[] = {"ls", "-R", "-l", NULL};
	execv("/bin/ls", args);
	return 0;
}
