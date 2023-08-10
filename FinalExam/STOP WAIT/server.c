#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
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
        printf("\nerror on creation ");
        exit(0);
    }
    else{
        printf("\nserver created ");
    }
    int b=bind(server,(struct sockaddr *)&servAddr,sizeof(servAddr));
    if(b<0){
        printf("\nerror on binding");
        exit(0);
    }
    else{
        printf("\nbinding is success");
    }
    if(listen(server,5)==0){
        printf("\nlistening");
    }
    else{
        printf("\n error on listen");
        exit(0);
    }
    client=accept(server,(struct sockaddr *)&clientAddr,&clientAddrSize);
    if(client<0){
        printf("\nerror on client");
        exit(0);
    }
    int sf=0,fc=8;
    while(sf<fc){
        send(client,&sf,sizeof(sf),0);
        int ack;
        recv(client,&ack,sizeof(ack),0);
        if(ack==sf){
            printf("\nsended successfully and recived ack %d",ack);
            sf++;
        }
        else{
            printf("\nresending the frame");
        }
    }
}