/*
============================================================================
Name : 25
Author : Shrutik Mali
Description : Write a program to create three child processes. The parent should wait for a particular child (use
	      waitpid system call).
Date: 1 Sep 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
	printf("Hierarchy: A -> B -> C\n");
	int c1pid = fork();
	int wb_status;
	if(!c1pid) {
		int wc_status;
		int c2pid = fork();
		if(!c2pid) {
			printf("Press a key to return to parent B\n");
			getchar();
		}
		else {
			waitpid(c2pid, &wc_status, WUNTRACED | WCONTINUED);
			printf("Returned to parent B\n");
			printf("Press a key to return to parent A\n");
			getchar();
		}
	}
	else {
		waitpid(c1pid, &wb_status, WUNTRACED | WCONTINUED);
		printf("Returned to parent A\n");
	}
	return 0;
}
