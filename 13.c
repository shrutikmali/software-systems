/*
============================================================================
Name : 13
Author : Shrutik Mali
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
	      verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 24 Aug 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

int main() {
	fd_set stdin_set;
	struct timeval timelimit;
	FD_ZERO(&stdin_set);
	FD_SET(0, &stdin_set);
	
	timelimit.tv_sec = 10;
	
	int res = select(1, &stdin_set, NULL, NULL, &timelimit);
	if(res) {
		printf("Data is available\n");
	}
	else {
		printf("No data available\n");
	}
	return 0;
}
