/*
============================================================================
Name : 27.c
Author : Shrutik Mali
Description : Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Date: 10 Oct 2023
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msgbuf {
        long mtype;
        char mtext[100];
};

int main() {
	struct msgbuf msg;
	int size_recv = msgrcv(1, &msg, 100, (long)1, 0);
	if(size_recv == -1) {
		perror("Error in receving message: ");
		return -1;
	}
	printf("Message received: %s\n", msg.mtext);
	return 0;
}
