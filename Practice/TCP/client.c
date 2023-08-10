#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<ctype.h>
int main(){
    int client;
    struct sockaddr_in serverAddr;
    char message[1024];

    client=socket(AF_INET,SOCK_STREAM,0);
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons(3000);
    serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(client<0){
        printf("\nerror on client creation");
        exit(0);
    }
    else{
        printf("\nclient is created ");
    }
    int c=connect(client,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
    if(c<0){
        printf("\nerror on connection creation");
        exit(0);
    }
    else{
        printf("\nconnection is created ");
    }
    while(1){
        printf("\nenter the string ");
        scanf("%s",message);
        send(client,message,1024,0);
        recv(client,message,sizeof(message),0);
        printf("\nupper case is %s",message);
        memset(message,0,1024);
    }
}