#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#include <ctype.h>
int prime(int);
int output(int);
int main(){
    int a,i,m,j,tot=0,sum;
    char str[100];
    scanf("%s",&str);
    m=strlen(str);//printf("%d\n",m);
    for(i=0;i<m;i++){
        if(isdigit(str[i])==0){
            printf("E");
            return;
        }
    }
    int n=atoi(str);
    if(1000>n&&n>0){
        if(n==2){
            printf("2,2\n");
            tot+=2;
        }
        for(j=2;j<n;j++){
            if(n%j==0&&prime(j)){
                sum=output(j);
                tot+=sum;
            }
        }
        printf("%d",tot);
    }else{
        printf("E");
    }
}
int prime(int j){
    int k;
    for(k=2;k<j;k++){//printf("j=%d\n",j);
        if(j%k==0){
            return 0;
        }
    }
    return 1;
}
int output(int j){
    int sum=1,w;
    for(w=2;w<=j;w++){
        sum*=w;
    }
    printf("%d,%d\n",j,sum);
    return sum;
}
