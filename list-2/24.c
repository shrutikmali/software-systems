/*
============================================================================
Name : 24.c
Author : Shrutik Mali
Description : Write a program to create a message queue and print the key and message queue id.
Date: 10 Oct 2023
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
	key_t key = ftok(".", 1);
	int queue = msgget(key, IPC_CREAT);
	if(queue == -1) {
		printf("Error in creating queue\n");
		return -1;
	}

	printf("Key is: %d\n", key);
	printf("Queue id is: %d\n", queue);
	return 0;
}
