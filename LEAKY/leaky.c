#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,bsize,bucket=0,in,out;
    printf("\nenter the no of input\t");
    scanf("%d",&n);
    printf("\nenter the outgoing rate\t");
    scanf("%d",&out);
    printf("\nenter the bucket size\t");
    scanf("%d",&bsize);
    while(n!=0){
        printf("\nenter the incoming bucket size \t");
        scanf("%d",&in);
        if(in<=(bsize-bucket)){
            bucket+=in;
            printf("\nstatus %d out of %d",bucket,bsize);
        }
        else{
            printf("\ndroipped bucket is %d",in-(bsize-bucket));
            printf("\nstatus %d out of %d",bucket,bsize);
            bucket=bsize;
        }
        printf("\nstatus after removal %d out of %d",bucket,bsize);
        bucket-=out;
        n--;
    }

}