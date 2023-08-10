#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<ctype.h>

void tranfer(char *s){
    for(int i=0;i<strlen(s);i++){
    s[i]=toupper(s[i]);
    }
}
int main(){
    char message[1024];
    int server,client;
    struct sockaddr_in serveAddr,clientAddr;
    socklen_t clientAddrSize=sizeof(clientAddr);
    server=socket(AF_INET,SOCK_STREAM,0);
    serveAddr.sin_family=AF_INET;
    serveAddr.sin_port=htons(3000);
    serveAddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    if(server<0){
        printf("\nerror on creating server");
        exit(0);
    }
    else{
        printf("\nserver created ");
    }
    int b=bind(server,(struct sockaddr *)&serveAddr,sizeof(serveAddr));
    if(b<0){
        printf("\nerror on binding");
        exit(0);
    }
    else{
        printf("\nbinding doned");
    }
    if(listen(server,5)==0){
        printf("\nlisteing");
    }
    else{
        printf("\nerror");
        exit(0);
    }
    client=accept(server,(struct sockaddr *)&clientAddr,&clientAddrSize);
    if(client<0){
        printf("\nerror from client");
        exit(0);
    }
    else{
        printf("client connected ");
    }
    while(1){
        recv(client,message,sizeof(message),0);
        tranfer(message);
        send(client,message,1024,0);
    }
    close(client);
    close(server);
}