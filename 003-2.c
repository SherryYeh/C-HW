#include "stdio.h"
#include "string.h"
void Add(char *num1,char *num2,char *num3){
    int len1=strlen(num1),len2=strlen(num2),i=0,carry=0,a[60],b[60],c[120];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(i=len1-1;i>=0;i--)
        a[len1-1-i]=num1[i]-'0';
    for(i=len2-1;i>=0;i--)
        b[len2-1-i]=num2[i]-'0';
    while(i<len1) {
        c[i]=a[i]+b[i]+carry;
        if (c[i]>=10) {
            carry=c[i]/10;
            c[i]%=10;
        }else{
            carry = 0;
        }
        i++;
    }
    if(carry!=0){
        c[i]=carry;
        i++;
    }
    int len3=i;
    for(i=len3-1;i>=0;i--)
        num3[len3-1-i]=c[i]+'0';
    num3[len1]='\0';
}
void Minus(char *num1,char *num2,char *num3){
    int len1=strlen(num1),len2=strlen(num2),i=0,carry=0,a[60],b[60],c[120],X;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(i=len1-1;i>=0;i--)
        a[len1-1-i]=num1[i]-'0';
    for(i=len2-1;i>=0;i--)
        b[len2-1-i]=num2[i]-'0';
    while(i<len1){
        if(a[len1-1]<b[len1-1]){
            c[i]=b[i]-a[i]-carry;
            X=1;
        }else{
            c[i]=a[i]-b[i]-carry;
        }
        if(c[i]<0) {
            c[i]+=10,
            carry=1;
        }else{
            carry=0;
        }
        i++;
    }
    if(X==1)
        printf("-");
    while(len1>1&&c[len1-1]==0){
        len1--;
    }
    int len3=len1;
    for(i=len3-1;i>=0;i--)
        num3[i]=c[len3-1-i]+'0';
    num3[len3]='\0';
}
void Multi(char *num1,char *num2,char *num3){
    int len1=strlen(num1),len2=strlen(num2),i,x=0,j,carry=0,y=0,t;
    for (i=0;i<60;i++)
        num3[i]='0';
    num3[60-1]=0;
    for (i=len1-1;i>=0;i--,x++) {
        for(j=len2-1,y=0;j>=0;j--,y++) {
            t=((num1[i]-'0')*(num2[j]-'0')+carry+(num3[60-2-x-y]-'0'))%10+'0';
            carry=((num1[i]-'0')*(num2[j]-'0')+carry+(num3[60-2-x-y]-'0'))/10;
            num3[60-2-x-y]=t;
            if (j==0){
                num3[60-3-x-y]='0'+carry;
                carry=0;
            }
        }
    }
    if(num3[60-len1-len2-1]=='0')
        x=len1+len2-1;
    else
        x=len1+len2;
    for(i=0;i<x;i++)
        num3[i]=num3[i+60-x-1];
    num3[x]=0;
}
void main(){
    char a[60],b[60],c[120];
    scanf("%s %s",a,b);
    Add(a,b,c);
    printf("%s\n",c);
    Minus(a,b,c);
    printf("%s\n",c);
    Multi(a,b,c);
    printf("%s\n",c);
    _getch();
}
