/*
============================================================================
Name : 26.c
Author : Shrutik Mali
Description : Write a program to send messages to the message queue. Check $ipcs -q
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
	char mtext[];
};

int main() {
	key_t key = ftok(".", 0);
    int queue = msgget(key, IPC_CREAT);
    if(queue == -1) {
    	printf("Error in making queue\n");
        return -1;
    }
    char message[100] = "Message to queue";
	int size = 100;
	struct msgbuf msg;
	msg.mtype = (long)1;
	strcpy(msg.mtext, message);

	int res = msgsnd(queue, &msg, size, 0);
	if(res == -1) {
		
		perror("Error in sending message\n");
		return -1;
	}
	printf("Message sent to queue\n");
	return 0;
}
