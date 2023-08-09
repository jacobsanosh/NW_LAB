#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/inet.h>
#include<netinet/in.h>
int main(){
        int client;
        char message[1024];
        struct sockarrd_in servAddr;
        struct sockaddr_storage store;
        socklen_t addr_size;
        client=socket(AF_INET,SOCK_STREAM,0);
        servAddr.sin_familt=AF_INET;
        servAddr.sin_port=htons(7891);
        servAddr.sin_addr.s_addr=inte_addr("127.0.0.1");
        connect(client,(struct sockaddr *)&servAddr,sizeof(servAddr));
        printf("sending data to server");
        printf("\nenter the data to be send");
        scnaf("%s",message);
        send(client,message,size(message),0);
        recv(client,message,1024,0);
        printf("\n data from server is %s",message);
        close(client);
}
