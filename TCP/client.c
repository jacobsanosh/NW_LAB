#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
int main(){
    int client;
    char message[1024];
    struct sockaddr_in servAddr;
    struct sockaddr_storage store;
    socklen_t addr_size;
    client=socket(AF_INET,SOCK_STREAM,0);
    servAddr.sin_family=AF_INET;
    servAddr.sin_port=htons(7891);
    servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    connect(client,(struct sockaddr *)&servAddr,sizeof(servAddr));
    printf("\nsending data to server");
    printf("\nentet the data to be send to server \t");
    scanf("%s",message);
    send(client,message,sizeof(message),0);
    recv(client,message,1024,0);
    printf("\ndata from serever is %s",message);
    close(client);
}