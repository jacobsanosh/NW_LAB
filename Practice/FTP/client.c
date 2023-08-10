#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<ctype.h>
int main(){
    int client;
    struct sockaddr_in sevrAddr;
    client=socket(AF_INET,SOCK_STREAM,0);
    sevrAddr.sin_family=AF_INET;
    sevrAddr.sin_port=htons(3000);
    sevrAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    char message[1024];
    if(client<0){
        printf("\nerror on creating server");
        exit(0);
    }
    else{
        printf("\nserver created ");
    }
    int c=connect(client,(struct sockaddr *)&sevrAddr,sizeof(sevrAddr));
    if(c<0){
        printf("\nerror on connection server");
        exit(0);
    }
    else{
        printf("\nconnected ");
    }
    FILE *fle=fopen("res.txt","w");
    while(1){
        int r=recv(client,message,sizeof(message),0);
        if(r<=0){
            break;
        }
        fprintf(fle,"%s\n",message);
    }
}