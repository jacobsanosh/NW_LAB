#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<ctype.h>
int main(){
    int server,n;
    struct sockaddr_in servAddr,clientAddr;
    socklen_t clientAddrSize=sizeof(clientAddr);
    server=socket(AF_INET,SOCK_DGRAM,0);
    servAddr.sin_family=AF_INET;
    servAddr.sin_port=htons(3000);
    char message[1024];
    servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(server<0){
        printf("\nerror on creating server");
        exit(0);
    }
    else{
        printf("\ncreated server");
    }
    while(1){
        printf("\nenter n ");
        scanf("%d",&n);
        sendto(server,&n,sizeof(n),0,(struct sockaddr *)&servAddr,sizeof(servAddr));
        recvfrom(server,message,sizeof(message),0,(struct sockaddr *)&clientAddr,&clientAddrSize);
        printf("\n %s",message);
    }
}