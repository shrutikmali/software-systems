#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
	key_t key = ftok(".", 0);
	int queue = msgget(key, IPC_CREAT);
	if(queue == -1) {
		printf("Error in making queue\n");
		return -1;
	}

	struct msqid_ds info;
	msgctl(queue, IPC_STAT, &info);

	printf("Access permissions: %u\n", info.msg_perm.mode);
	printf("UID: %d\n", info.msg_perm.uid);
	printf("GID: %d\n", info.msg_perm.gid);
	printf("Time of last message send: %ld\n", info.msg_stime);
	printf("Time of last message receive: %ld\n", info.msg_rtime);
	printf("Time of last change or modification: %ld\n", info.msg_ctime);
	printf("Size of queue: %lu\n", info.msg_cbytes);
	printf("Number of messages in queue: %lu\n", info.msg_qnum);
	printf("Maximum number of bytes allowed: %lu\n", info.msg_qbytes);
	printf("PID of msgsnd: %d\n", info.msg_lspid);
	printf("PID of msgrcv: %d\n", info.msg_lrpid);

	return 0;
}
