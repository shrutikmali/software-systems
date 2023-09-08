/*
============================================================================
Name : 20
Author : Shrutik Mali
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 25 Aug 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
	int pid = getpid();
	int currPriority = getpriority(0, pid);
	int currNice = nice(0);
	printf("Current priority is: %d\n", currPriority);
	printf("Current nice is: %d\n", currNice);
	
	printf("Enter new nice: ");
	int newNice;
	scanf("%d", &newNice);
	nice(newNice);
	currPriority = getpriority(0, pid);
	currNice = nice(0);
	printf("Current priority is: %d\n", currPriority);
	printf("Current nice is: %d\n", currNice);
	
	return 0;
}
