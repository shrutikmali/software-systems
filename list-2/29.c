#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    struct msqid_ds info;
    int res = msgctl(3, IPC_RMID, &info);
	if(res == -1) {
		perror("Error in deleting queue: ");
		return -1;
	}
	printf("Queue deleted\n");
	return 0;
}
