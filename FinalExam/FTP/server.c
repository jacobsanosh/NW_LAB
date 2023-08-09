#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
int main(){
        int server,client;
        struct sockaddr_in servAddr,clientAddr;
        struct sockaddr_storage store;
        socklen_t clientAddrSize=sizeof(clientAddr);
        char message[1024];
        //creating socket
        server=socket(AF_INET,SOCK_STREAM,0);
        servAddr.sin_family=AF_INET;
        servAddr.sin_port=htons(3000);
        servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");

        if(server<0){
                printf("\n error on creating");
        }
        else{
                printf("\nsocket created");
        }
        int b=bind(server,(struct sockaddr *)&servAddr,sizeof(servAddr));
        if(b<0){
                printf("\nerror on binding");
        }
        else{
                printf("\nbinding is done successfully");
        }
        if(listen(server,5)==0){
                printf("\nstarted listening");
        }
        else{
                printf("\nerror on listening");
                exit(1);
        }
        client=accept(server,(struct sockaddr *)&clientAddr,&clientAddrSize);
        if(client<0){
                printf("\nerror on client ");
                exit(1);
        }
        else{
                printf("\naccepted");
        }
        FILE *fle=fopen("output.txt","w");
        while(1){
                int r=recv(client,message,1024,0);
                fprintf(fle,"%s\n",message);
                if(r<=0){
                        break;
                }
                bzero(message,1024);
        }
}
