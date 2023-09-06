#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = creat("fileDescriptor.txt", O_CREAT);
    printf("%d\n", fd);
    return 0;
}