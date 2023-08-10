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
    char message[1024];
    server=socket(AF_INET,SOCK_STREAM,0);
    servAddr.sin_family=AF_INET;
    servAddr.sin_port=htons(3000);
    servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(server<0){
        printf("\nerror on server ");
        exit(0);
    }
    else{
        printf("\nconnected");
    }
    int b=bind(server,(struct sockaddr *)&servAddr,sizeof(servAddr));
     if(b<0){
        printf("\nerror on binding ");
        exit(0);
    }
    else{
        printf("\nbindeded");
    }
     if(listen(server,5)==0){
        printf("\nlisteningserver ");
       
    }
    else{
        printf("\nerror on listening");
         exit(0);
    }
    client=accept(server,(struct sockaddr *)&clientAddr,&clientAddrSize);
     if(client<0){
        printf("\nerror on server ");
        exit(0);
    }
    else{
        printf("\nconnected");
    }
    char *wel="220 welcome to smtp server";
    send(client,wel,strlen(wel),0);
    while(1){
        recv(client,message,2014,0);
        printf("\nmessage from client is %s",message);
        if(strstr(message,"QUIT")!=NULL){
            char *res="201 goodbye";
            send(client,res,strlen(res),0);
            break;
        }
        else{
            char *res="250 ok";
            send(client,res,strlen(res),0);
        }
        memset(message,0,1024);
    }
}