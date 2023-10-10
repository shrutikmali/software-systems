#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
	key_t key = ftok(".", 28);
    int queue = msgget(key, IPC_CREAT | 0666);
   	if(queue == -1) {
   		printf("Error in making queue\n");
        return -1;
    }

   	struct msqid_ds info;
   	msgctl(queue, IPC_STAT, &info);

   	printf("Current permission is: %o\n", info.msg_perm.mode);
	info.msg_perm.mode = 0400;
	msgctl(queue, IPC_SET, &info);
	msgctl(queue, IPC_STAT, &info);
	printf("New permission is: %o\n", info.msg_perm.mode);
	return 0;
}
