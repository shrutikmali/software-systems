#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = creat("existingFile.txt", O_EXCL);
    printf("%d\n", fd);
    return 0;
}