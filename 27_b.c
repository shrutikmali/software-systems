/*
============================================================================
Name : 27_b
Author : Shrutik Mali
Description : Write a program to execute ls -Rl by the following system calls: execlp
Date: 4 Sep 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	execlp("ls", "-R", "-l", (char*)NULL);
	return 0;
}
