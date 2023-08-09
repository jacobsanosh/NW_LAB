#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
int main(){
    FILE *fle;
    int client;
    struct sockaddr_in servAddr,clientAddr;
    socklen_t clientAddrSize=sizeof(clientAddr);
    char message[1024];
    client=socket(AF_INET,SOCK_STREAM,0);
    servAddr.sin_family=AF_INET;
    servAddr.sin_port=htons(3000);
    servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(client<0){
        printf("\nerror on creation ");
        exit(1);
    }    
    else{
        printf("\nsuccess on creation");
    }
    int c=connect(client,(struct sockaddr *)&servAddr,sizeof(servAddr));
    if(c<0){
         printf("\nerror on server ");
        exit(1);
    }
    else{
        printf("\nsuccess on connection");
    }
    fle=fopen("demo.txt","r");
    if(fle==NULL){
        printf("\nerror on file");
        exit(1);
    }
    while(fscanf(fle,"%s",message)!=EOF){
        send(client,message,sizeof(message),0);
        bzero(message,1024);
    }
    close(client);
}