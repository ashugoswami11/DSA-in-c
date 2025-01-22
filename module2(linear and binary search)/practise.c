#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 8080

int main(){
    //creating variable
    int clientsocket;
    struct sockaddr_in serveraddr;
    char buffer[1024];

    //crating socket
    clientsocket = socket(PF_INET, SOCK_STREAM,0);
    printf("socket created successfully !\n");

    memset(serveraddr, "\0", sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = inet_addr(127.0.0.1);

    connect(clientsocket_(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    printf("connected to the server successfully\n");
}