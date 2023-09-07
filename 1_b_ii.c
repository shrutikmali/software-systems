#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *args[]) {
	if(argc != 2) {
		printf("Expected 1 file name as argument\n");
		return -1;
	}
	char str_link[50] = "hardlink-";
	strcat(str_link, args[1]);
	int res = link(args[1], str_link);
	if(res != 0) {
		printf("Error occurred\n");
		return -1;
	}
	printf("Link created\n");
	return 0;
}
