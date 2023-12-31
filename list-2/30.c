/*
============================================================================
Name : 30.c
Author : Shrutik Mali
Description : Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Date: 10 Oct 2023
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
	key_t key = ftok(".", 30);
	int id = shmget(key, 100, IPC_CREAT);
	if(id == -1) {
		perror("Error in creating shm: ");
		return -1;
	}
	printf("SHM created\n");
	getchar();
	char *read_write = shmat(id, (void*)0, 0);
	printf("Message to write to SHM: ");
	scanf("%[^\n]", read_write);
	printf("Message written is: %s\n", read_write);

	char *read_only = shmat(id, (void*)0, SHM_RDONLY);
	/*
	printf("Writing to read_only: ");
	scanf("%s", read_only);
	*/
	int detach_res = shmdt(read_only);
	if(detach_res == -1) {
		perror("Error in detaching: ");
		return -1;
	}
	printf("SHM detached\n");
	struct shmid_ds info;
	int rem_res = shmctl(id, IPC_RMID, &info);
	if(rem_res == -1) {
		perror("Error in deleting SHM: ");
		return -1;
	}
	printf("SHM deleted\n");
	return 0;
}

	
