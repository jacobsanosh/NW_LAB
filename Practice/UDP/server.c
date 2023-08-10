#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<ctype.h>
int check(int n){
    printf("checking");
    for(int i=2;i<n/2+1;i++){
        if(n%i==0){
            return -1;
        }
    }
    return 1;
}
int main(){
    int server,n;
    struct sockaddr_in servAddr,clientAddr;
    socklen_t clientAddrSize=sizeof(clientAddr);
    server=socket(AF_INET,SOCK_DGRAM,0);
    servAddr.sin_family=AF_INET;
    servAddr.sin_port=htons(3000);
    servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(server<0){
        printf("\nerror on creating server");
        exit(0);
    }
    else{
        printf("\ncreated server");
    }
    int b=bind(server,(struct sockaddr *)&servAddr,sizeof(servAddr));
    if(b<0){
       printf("\nerror on binding server");
        exit(0);
    }
    else{
        printf("\ncreated binding");
    }
    while(1){
        printf("\nhi");
        recvfrom(server,&n,sizeof(n),0,(struct sockaddr *)&clientAddr,&clientAddrSize);
        printf("rec -> %d",n);
        if(check(n)==-1){
            char *s="not prime";
            sendto(server,s,sizeof(s),0,(struct sockaddr *)&clientAddr,clientAddrSize);
        }
        else{
            char *s="prime";
            sendto(server,s,sizeof(s),0,(struct sockaddr *)&clientAddr,clientAddrSize);
        }
    }
}