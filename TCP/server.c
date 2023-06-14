#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
int main(){
    int server,client;
    char message[1024];
    struct sockaddr_in servAddr;
    struct sockaddr_storage store;
    socklen_t addr_size;

    server=socket(AF_INET,SOCK_STREAM,0);
    servAddr.sin_family=AF_INET;
    servAddr.sin_port=htons(7891);
    servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    bind(server,(struct sockaddr *)&servAddr,sizeof(servAddr));
    if(listen(server,5)==0)
        printf("Listening\n");
    else
        printf("Error\n");
    client=accept(server,(struct sockaddr *)&store,&addr_size);
    recv(client,message,1024,0);
    printf("\ndata  received from client is %s",message);
    strcpy(message,"hello from server");
    printf("\nsending to server");
    send(client,message,sizeof(message),0);
    close(server);
    close(client);
}