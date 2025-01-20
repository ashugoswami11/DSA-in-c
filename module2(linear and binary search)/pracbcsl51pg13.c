#include<stdio.h> //normal header files
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>
#include<arpa/inet.h>

# define PORT 8080;

int main(){
    //variables declaration
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};

    //creating client socket
    client_socket = socket(PF_INET, SOCK_STREAM, 0);
    printf("client socket created successfully!");

    //to clean the server_addr
    memset(server_addr, "\0", sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(127.0.0.1);

    connect(client_socket, (struct sockaddr*) &server_addr, sizeof(server_addr));
    printf("connected to the server successfully!");
}
