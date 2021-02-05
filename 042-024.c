#include<stdio.h>
#include<math.h>
#include <string.h>
void add(int n1,int d1,int n2,int d2);
void multiply(int n1,int d1,int n2,int d2);
void math(int *ans1,int *ans2,int *x,int *posneg);
void output(int *ans1,int *ans2,int *x,int *posneg);
int main(){
    int n1,d1,n2,d2;
    scanf("%d/%d %d/%d",&n1,&d1,&n2,&d2);
    if(n1==0||d1==0||n2==0||d2==0){
        printf("ERROR\n");
        printf("ERROR");
    }else{
        add(n1,d1,n2,d2);
        multiply(n1,d1,n2,d2);
    }
}
void add(int n1,int d1,int n2,int d2){
    int ans1,ans2,x=0,posneg=0;
    ans1=n1*d2+n2*d1;
    ans2=d1*d2;
    math(&ans1,&ans2,&x,&posneg);
    output(&ans1,&ans2,&x,&posneg);
}
void multiply(int n1,int d1,int n2,int d2){
    int ans1,ans2,x=0,posneg=0;
    ans1=n1*n2;
    ans2=d1*d2;
    math(&ans1,&ans2,&x,&posneg);
    output(&ans1,&ans2,&x,&posneg);
}
void math(int *ans1,int *ans2,int *x,int *posneg){
    if(*ans1<0){
        *ans1=abs(*ans1);
        *posneg+=1;
    }
    if(*ans2<0){
        *ans2=abs(*ans2);
        *posneg+=1;
    }
    int i;
    for(i=*ans1;i>1;i--){
        if(*ans1%i==0&&*ans2%i==0){
            *ans1=*ans1/i;
            *ans2=*ans2/i;
            break;
        }
    }
    if(*ans1>=*ans2){
        *x=*ans1/(*ans2);
        *ans1=*ans1%*ans2;
    }
}
void output(int *ans1,int *ans2,int *x,int *posneg){
    if(*x==0){
        if(*ans1==0){
            printf("%d",*x);
        }else{
              if(*posneg==1){
                    printf("-%d/%d",*ans1,*ans2);
              }else{
                    printf("%d/%d",*ans1,*ans2);
              }
        }
    }else{
        if(*ans1==0){
            if(*posneg==1){
                printf("-%d",*x);
            }else{
                printf("%d",*x);
            }
        }else{
              if(*posneg==1){
                    printf("-%d(%d/%d)",*x,*ans1,*ans2);
              }else{
                    printf("%d(%d/%d)",*x,*ans1,*ans2);
              }
        }
    }
    printf("\n");
}
