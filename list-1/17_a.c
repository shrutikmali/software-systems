/*
============================================================================
Name : 17_a
Author : Shrutik Mali
Description : Write a program to open a file, store a ticket number and exit.
Date: 25 Aug 2023.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd = open("ticket.txt", O_RDWR);
	struct {
		int ticketNo;
	} data;
	data.ticketNo = 0;
	write(fd, &data, sizeof(data));
	close(fd);
	return 0;
}
