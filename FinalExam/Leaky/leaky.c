#include<stdlib.h>
#include<stdio.h>
int main(){
        int n,bsize,bucket=0,in,out;
        printf("\nenter the no of input");
        scanf("%d",&n);
        printf("\nenter the amount of outgoing rate ");
        scanf("%d",&out);
        printf("\nenter the bucketsize ");
        scanf("%d",&bsize);
        while(n!=0){
                printf("\nenter the incoming bucketsize\t");
                scanf("%d",&in);
                if(in<=(bsize-bucket))
                {
                        bucket+=in;
                        
                }
                else{
                        printf("dropping buckets is %d ",in-(bsize-bucket));
                        bucket=bsize;
                     }
                     printf("\nstatus is %d out of %d",bucket,bsize);
                     bucket-=out;
                     printf("\nafter leak of bucket %d out of %d",bucket,bsize);
                     n--;       
        }
}
