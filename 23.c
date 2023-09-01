#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	int cpid = fork();
	if(!cpid) {
		;
	}
	else {
		while(1);
	}
	return 0;
}
