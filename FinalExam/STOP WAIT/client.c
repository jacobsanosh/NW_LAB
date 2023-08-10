#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
int main(){
    int client;
    struct sockaddr_in servAddr;
    
    client=socket(AF_INET,SOCK_STREAM,0);
    servAddr.sin_family=AF_INET;
    servAddr.sin_port=htons(3000);
    servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(client<0){
        printf("\nerror on client");
        exit(0);
    }
    else{
        printf("\nclient is connnected");
    }
    int c=connect(client,(struct sockaddr *)&servAddr,sizeof(servAddr));
    if(c<0){
        printf("\nerror on connection ");
        exit(0);
    }
    else{
        printf("\nconnection is success");
    }
    int exp=0,fc=8;
    while(exp<fc){
        int pack;
        recv(client,&pack,sizeof(pack),0);
        if(pack==exp){
            printf("\nrecived packet %d ",pack);
            send(client,&pack,sizeof(pack),0);
            exp++;
        }
        else{
            pack=-1;
            send(client,&pack,sizeof(pack),0);
        }
    }
}