/*
============================================================================
Name : 4
Author : Shrutik Mali
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 11 Aug 2023.
============================================================================
*/


#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = creat("existingFile.txt", O_EXCL);
    printf("%d\n", fd);
    return 0;
}
