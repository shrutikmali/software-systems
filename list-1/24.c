/*
============================================================================
Name : 24
Author : Shrutik Mali
Description : Write a program to create an orphan process.
Date: 1 Sep 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int cpid = fork();
	if(!cpid) {
		while(1);
	}
	else {
		;
	}
	return 0;
}
