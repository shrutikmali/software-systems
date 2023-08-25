#include <stdio.h>
#include <unistd.h>

int main() {
	int child_pid = fork();
	if(child_pid) {
		printf("PID of parent process: %d\n", getpid());
	}
	else {
		printf("PID of child process: %d\n", getpid());
	}
	return 0;
}
