#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main(){
    int n;
    printf("\nenter the no of node");
    scanf("%d",&n);
    int d[n],v[n],adj[n][n];
    printf("\nenter adjaceny matrix \t");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        d[i]=INT_MAX;
        v[i]=0;
    }
    d[0]=0;
    for(int i=0;i<n-1;i++){
        int min_i,min=INT_MAX;
        for(int j=0;j<n;j++){
            if(!v[i] && min>d[j]){
                min=d[j];
                min_i=j;
            }
            v[min_i]=1;
        }
        for(int k=0;k<n;k++){
            if(!v[k]&&adj[i][k]&&d[min_i]!=INT_MAX&&d[min_i]+adj[k][min_i]<d[k]){
                d[k]=d[min_i]+adj[k][min_i];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("\nnode %d \t distance %d",i,d[i]);

    }
}