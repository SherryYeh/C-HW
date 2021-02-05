#include<stdio.h>
void second(int x,int y,int a[10][10],int b[10][10]){
    int c[10][10],i,j;
    for(i=0;i<y;i++){
        for(j=0;j<x;j++){
            c[i][j]=a[i][j]+b[i][j];
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<y;i++){
        for(j=0;j<x;j++){
            c[i][j]=a[i][j]-b[i][j];
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void third(int y,int n,int p,int a[10][10],int b[10][10]){
    int c[y][n],i,j,k;
    for(i=0;i<y;i++){
        for(j=0;j<n;j++){
            c[i][j]=0;
            for(k=0;k<p;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int i,j,x,y,n,p,a[10][10],b[10][10];
    scanf("%d %d",&y,&x);
    for(i=0;i<y;i++){
        for(j=0;j<x;j++){
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d %d",&p,&n);
    for(i=0;i<p;i++){
        for(j=0;j<n;j++){
            scanf("%d",&b[i][j]);
        }
    }
    if(x==n&&y==p){
        second(x,y,a,b);
    }else{
        printf("ERROR\n");
        printf("ERROR\n");
    }
    if(x==p){
        third(y,n,p,a,b);
    }else{
        printf("ERROR\n");
    }
}
