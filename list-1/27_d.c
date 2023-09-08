/*
============================================================================
Name : 27_b
Author : Shrutik Mali
Description : Write a program to execute ls -Rl by the following system calls: execv
Date: 4 Sep 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	char *args[] = {"ls", "-R", "-l", NULL};
	execv("/bin/ls", args);
	return 0;
}
