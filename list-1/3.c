/*
============================================================================
Name : 3
Author : Shrutik Mali
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 11 Aug 2023.
============================================================================
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = creat("fileDescriptor.txt", O_CREAT);
    printf("%d\n", fd);
    return 0;
}
