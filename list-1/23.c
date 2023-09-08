/*
============================================================================
Name : 23
Author : Shrutik Mali
Description : Write a program to create a Zombie state of the running program.
Date: 1 Sep 2023.
============================================================================
*/

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
