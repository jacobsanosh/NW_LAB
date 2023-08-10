#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>

int main(){
    int server,client;
    struct sockaddr_in servAddr,clientAddr;
    socklen_t clientAddrSize=sizeof(clientAddr);

    server=socket(AF_INET,SOCK_STREAM,0);
    servAddr.sin_family=AF_INET;
    servAddr.sin_port=htons(3000);
    servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    if(server<0){
        printf("\nerror on server");
        exit(1);
    }
    else{
        printf("\nserver created successfully");
    }
    int b=bind(server,(struct sockaddr *)&servAddr,sizeof(servAddr));
    if(b<0)
    {
        printf("\nerror on binding");
        exit(1);
    }
    else{
        printf("\nbinding is successfully");
    }
    if(listen(server,5)==0){
        printf("\nlistening");
    }
    else{
        printf("\nerror on listening");
        exit(0);
    }
    client=accept(server,(struct sockaddr *)&clientAddr,&clientAddrSize);
    if(client<0){
        printf("\nerror on client");
        exit(0);
    }
    else{
        printf("\nclient is connected");
    }
    int ws=4,fc=8,sf=0;
    while(sf<fc){
        send(client,&sf,sizeof(sf),0);
        printf("\nsened frame->%d",sf);
        int recvack;
        recv(client,&recvack,sizeof(recvack),0);
        printf("\n rec %d sended %d",recvack,sf);
        if(sf==recvack){
            sf++;
        }
        else{
            printf("\nnot received ack");
        }
    }
}