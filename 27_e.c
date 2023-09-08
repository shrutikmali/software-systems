/*
============================================================================
Name : 27_e
Author : Shrutik Mali
Description : Write a program to execute ls -Rl by the following system calls: execvp
Date: 4 Sep 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	char *args[] = {"ls", "-l", "-R", (char*)NULL};
	execvp("ls", args);
	return 0;
}
