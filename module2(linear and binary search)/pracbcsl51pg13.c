//regular c-library files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//sys files.
#include<sys/socket.h>
#include<sys/types.h>

//internet files.
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 8080;

int main(){
    //<---these are declarations--->
    int client_socket; // declaring a variable
    struct sockaddr_in serveraddr; //structure
    char buffer[1024] = {0}; //character array of size 1024

    //creating a client socket.
    client_socket = socket(PF_INET, SOCK_STREAM, 0);
    printf("client socket created successfully..\n");
    
}
