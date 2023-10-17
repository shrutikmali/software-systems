/*
============================================================================
Name : 34s.c
Author : Shrutik Mali
Description : Write a program to create a concurrent server.
a. use fork
b. use pthread_create
Date: 10 Oct 2023
============================================================================
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int main() {
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(5000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    int bind_res = bind(sfd, (struct sockaddr*)&server, sizeof(server));

    if(bind_res == -1) {
        printf("Error binding\n");
        return -1;
    }
	int nextHost = 5001;
    while(1) {
    	printf("Listening\n");
    	int listen_res = listen(sfd, 5);

    	if(listen_res != 0) {
        	printf("Error listening\n");
    	}

		struct sockaddr_in client;
    	int client_size = sizeof(client);
    	int cfd = accept(sfd, (struct sockaddr*)&client, &client_size);
    	if(cfd == -1) {
        	printf("Error accepting client\n");
    	}

		// Send the next port to client
		send(cfd, &nextHost, sizeof(nextHost), 0);

    	if(!fork()) {
			sfd = socket(AF_INET, SOCK_STREAM, 0);
    		//struct sockaddr_in server;
    		server.sin_family = AF_INET;
    		server.sin_port = htons(nextHost);
    		server.sin_addr.s_addr = inet_addr("127.0.0.1");
    		bind_res = bind(sfd, (struct sockaddr*)&server, sizeof(server));

			if(bind_res == -1) {
				printf("Error binding in child\n");
				return -1;
			}
			printf("Child listening\n");
			if(listen(sfd, 1) != 0) {
				perror("Error listening in child: ");
				return -1;
			}

			cfd = accept(sfd, (struct sockaddr*)&client, &client_size);
			if(cfd == -1) {
				perror("Error accepting in child: ");
				return -1;
			}
			printf("A client connected\n");
			sleep(30);
			return 0;
    	}
    	else {
			nextHost++;
    	}
    }
    return 0;
}
