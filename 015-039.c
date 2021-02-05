#include<stdio.h>
void one(int);
void two(int);
void three(int);
int main(){
    int a,n;
    scanf("%d %d",&a,&n);
    if(a==1){
        one(n);
    }else if(a==2){
        two(n);
    }else{
        three(n);
    }
}
void one(int n){
    int i,j;
    for(i=1;i<=n;i++){
        if(i<=(n+1)/2){
            for(j=1;j<=i;j++){
                printf("*");
            }
        }else{
            for(j=i;j<=n;j++){
                printf("*");
            }
        }
        printf("\n");
    }
}
void two(int n){
    int i,j;
    for(i=1;i<=n;i++){
        if(i<(n+1)/2){
            for(j=1;j<=(n+1)/2-i;j++){
                printf(".");
            }
            for(j=1;j<=i;j++){
                printf("*");
            }
        }else{
            for(j=1;j<=i-(n+1)/2;j++){
                printf(".");
            }
            for(j=1;j<=n+1-i;j++){
                printf("*");
            }
        }
         printf("\n");
    }
}
void three(int n){
    int i,j;
    for(i=1;i<=n;i++){
        if(i<(n+1)/2){
            for(j=1;j<=(n+1)/2-i;j++){
                printf(".");
            }
            for(j=1;j<=2*i-1;j++){
                printf("*");
            }
        }
        else{
            for(j=1;j<=i-(n+1)/2;j++){
                printf(".");
            }
            for(j=1;j<=(n+1-i)*2-1;j++){
                printf("*");
            }
        }
       printf("\n");
    }
}
