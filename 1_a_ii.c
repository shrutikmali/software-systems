/*
============================================================================
Name : 1_a_ii
Author : Shrutik Mali
Description : Create symlink
Date: 7 Sep 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *args[]) {
	if(argc != 2) {
		printf("Expected file name as argument\n");
		return -1;
	}
	char str_link[50] = "symlink-";
	strcat(str_link, args[1]);
	int res = symlink(args[1], str_link);
	if(res != 0) {
		printf("Error occurred\n");
		return -1;
	}
	printf("Link created\n");
	return 0;
}
