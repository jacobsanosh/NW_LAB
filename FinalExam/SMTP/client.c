#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
int main(){
    int client;
    struct sockaddr_in servAddr;
    socklen_t servAddrSize=sizeof(servAddr);
    char message[1024];
    client=socket(AF_INET,SOCK_STREAM,0);
    servAddr.sin_family=AF_INET;
    servAddr.sin_port=htons(3000);
    servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    if(client<0){
        printf("\nerror on creating client");
        exit(0);
    }
    else{
        printf("\ncreated ");
    }
    int c=connect(client,(struct sockaddr *)&servAddr,servAddrSize);
     if(c<0){
        printf("\nerror on connection ");
        exit(0);
    }
    else{
        printf("\nconnected");
    }
    char wel[1024];
    recv(client,wel,1024,0);
    printf("%s",wel);
    
    char *email[]={
        "hello local host",
        "MAIL FROM:<sender@123.com>",
        "RCPT TO:<receiver@123.com>",
        "DATA",
        "Subjct:enthokkea und sugam allea QUIT"
    };
    for(int i=0;i<sizeof(email)/sizeof(email[0]);i++){
        send(client,email[i],strlen(email[i]),0);
        recv(client,message,1024,0);
        printf("\nmessage is %s",message);
    }

}