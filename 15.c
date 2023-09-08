/*
============================================================================
Name : 15
Author : Shrutik Mali
Description : Write a program to display the environmental variable of the user (use environ).
Date: 24 Aug 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main() {
	int i = 0;
	while(environ[i]) {
		printf("%s\n", environ[i]);
		i++;
	}
	return 0;
}
