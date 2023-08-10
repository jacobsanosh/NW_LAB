#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main(){
        int client;
        char message[1024];
        struct sockaddr_in servAddr;
        socklen_t serAddrSize=sizeof(servAddr);
        client=socket(AF_INET,SOCK_STREAM,0);
        servAddr.sin_family=AF_INET;
        servAddr.sin_port=htons(7891);
        servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
        connect(client,(struct sockaddr *)&servAddr,serAddrSize);
        printf("sending data to server");
        printf("\nenter the data to be send");
        scanf("%s",message);
        send(client,message,sizeof(message),0);
        recv(client,message,1024,0);
        printf("\n data from server is %s",message);
        close(client);
}
