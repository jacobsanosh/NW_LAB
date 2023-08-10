#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<ctype.h>
int main(){
    int client,server;
    struct sockaddr_in sevrAddr,clientAddr;
    socklen_t clientAddrSize=sizeof(clientAddr);
    server=socket(AF_INET,SOCK_STREAM,0);
    sevrAddr.sin_family=AF_INET;
    sevrAddr.sin_port=htons(3000);
    sevrAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    char message[1024];
    if(server<0){
        printf("\nerror on creating server");
        exit(0);
    }
    else{
        printf("\nserver created ");
    }
    int b=bind(server,(struct sockaddr *)&sevrAddr,sizeof(sevrAddr));
     if(b<0){
        printf("\nerror on binding ");
        exit(0);
    }
    else{
        printf("\nbinded ");
    }
    if(listen(server,5)==0){
        printf("\n listening ");
    }
    else{
        printf("\nerror on listening ");
        exit(0);
    }
    client=accept(server,(struct sockaddr *)&clientAddr,&clientAddrSize);
     if(client<0){
        printf("\nerror on creating client");
        exit(0);
    }
    else{
        printf("\nclient created ");
    }
    FILE *fle=fopen("demo.txt","r");
    if(fle==NULL){
        printf("\nno file with this name");
        exit(0);
    }
    while(fscanf(fle,"%s",message)!=EOF){
        send(client,message,1024,0);
    }
}