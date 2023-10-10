#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>

int main() {
    int cfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(5000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int connect_res = connect(cfd, (struct sockaddr*)&server, sizeof(server));
    if(connect_res == -1) {
        printf("Error connecting\n");
        return -1;
    }
    printf("Connected to server\n");
	printf("Getting next port\n");
	sleep(3);
    int newPort;
    recv(cfd, &newPort, sizeof(newPort), 0);
    printf("New port: %d\n", newPort);
   	cfd = socket(AF_INET, SOCK_STREAM, 0);
   	server.sin_port = htons(newPort);
   	connect_res = connect(cfd, (struct sockaddr*)&server, sizeof(server));
   	if(connect_res == -1) {
   		printf("Error connecting\n");
   		return -1;
   	}
   	sleep(30);
   	return 0;
}
