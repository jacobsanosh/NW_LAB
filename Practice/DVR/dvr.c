#include<stdio.h>
#include<stdlib.h>
struct node{
    int dist[20],from[20];
}rt[20];
int main(){
    int i,j,k,count=0,d[20][20],n;
    printf("\nenter the no of node ");
    scanf("%d",&n);
    printf("\nenter the adjacency ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&d[i][j]);
            d[i][i]=0;
            rt[i].dist[j]=d[i][j];
            rt[i].from[j]=j;
        }
    }
    do{
        count=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    if(rt[i].dist[j]>d[i][k]+rt[k].dist[j]){
                        rt[i].dist[j]=d[i][k]+rt[k].dist[j];
                        rt[i].from[j]=k;
                        count++;
                    }
                }
            }
        }
    }while(count!=0);
    for(int i=0;i<n;i++){
        printf("\nfor state %d",i+1);
        for(int j=0;j<n;j++){
            printf("\n%d node distance via %d is %d",j+1,rt[i].from[j]+1,rt[i].dist[j]);
        }
    }
}