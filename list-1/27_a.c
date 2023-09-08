/*
============================================================================
Name : 27_a
Author : Shrutik Mali
Description : Write a program to execute ls -Rl by the following system calls: execl
Date: 4 Sep 2023.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	execl("/bin/ls", "-R", "-l", (char*)NULL);
	return 0;
}
