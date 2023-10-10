#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
	key_t key_binary = ftok(".", 31);
	int binary = semget(key_binary, 1, IPC_CREAT);
	if(binary == -1) {
		perror("Error in creating binary semaphore: ");
		return -1;
	}
	printf("Binary semaphore created\n");

	key_t key_counting = ftok(".", 10);
	int counting = semget(key_counting, 10, IPC_CREAT);
	if(counting == -1) {
		perror("Error in creating counting semaphore: ");
		return -1;
	}
	printf("Couting semaphore created\n");
	return 0;
}
