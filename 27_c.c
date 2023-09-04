#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <fcntl.h>

int main() {
	char* envp[] = {"PATH=/bin", 0};
	execle("/bin/ls", "-R", "-l", (char*)NULL, envp);
	return 0;
}
