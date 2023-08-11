#include<stdio.h>
#include<stdlib.h>
int main(){
    int bsize,n,bucket=0,in,out;
    printf("\nenter the no of input ");
    scanf("%d",&n);
    printf("\nenter the bucket size ");
    scanf("%d",&bsize);
    printf("\nenter the out rate ");
    scanf("%d",&out);
    while(n!=0){
        printf("\nenter the current input ");
        scanf("%d",&in);
        if(in<=(bsize-bucket)){
            bucket+=in;
        }
        else{
            printf("\ndropping %d packets ",(in-(bsize-bucket)));
            bucket=bsize;
        }
        printf("\n status after %d in %d ",bucket,bsize);
        bucket-=out;
        printf("\nafter leak status %d in %d ",bucket,bsize);
    }
}