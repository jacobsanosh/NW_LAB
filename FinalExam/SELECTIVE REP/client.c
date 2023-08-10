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
    socklen_t servAddrSize=sizeof(servAddr);

    client=socket(AF_INET,SOCK_STREAM,0);
    servAddr.sin_family=AF_INET;
    servAddr.sin_port=htons(3000);
    servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(client<0){
        printf("something went wrong on creating client");
        exit(0);
    }
    else{
        printf("\nclient created successfilly");
    }
    int c=connect(client,(struct sockaddr *)&servAddr,servAddrSize);
    if(c<0){
        printf("\nerror on creatig connection");
        exit(0);
    }
    else{
        printf("\nconnection success");
    }
    int ws=4,fs=8,exp=0;
    while(exp<fs){
        int recvd;
        recv(client,&recvd,sizeof(recvd),0);
        printf("\n%d -> %d",recvd,exp);
        if(recvd==exp){
            send(client,&recvd,sizeof(recvd),0);
            exp++;
        }
        else{
            int res=-1;
            send(client,&res,sizeof(res),0);
        }

    }
}