#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *args[]) {
	if(argc != 2) {
		printf("Invalid number of arguments, expected %d\n", (argc - 1));
		return -1;
	}
	struct stat information;
	int res = stat(args[1], &information);
	if(res == -1) {
		printf("Could not read information of file\n");
		return -1;
	}
	printf("inode: %d\n", information->ino_t);
	printf("Number of hard links: %d\n", information->nlink_t);
	printf("uid: %d\n", information->uid_t);
	printf("gid: %d\n", infomation->gid_t);
	printf("size: %d\n", information->off_t);
	printf("block size: %d\n", information->blksize_t);
	printf("number of blocks: %d\n", (information->off_t / information->blksize_t));
	printf("time of last access: \n"
