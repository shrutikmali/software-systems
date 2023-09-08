/*
============================================================================
Name : 27_c
Author : Shrutik Mali
Description : Write a program to execute ls -Rl by the following system calls: execle
Date: 4 Sep 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <fcntl.h>

int main() {
	char* envp[] = {"PATH=/bin", 0};
	execle("/bin/ls", "-R", "-l", (char*)NULL, envp);
	return 0;
}
