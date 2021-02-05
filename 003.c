#include <stdio.h>
#include <string.h>
void main(){
    char a[60],b[60],c[60*2];
    Input(a);
    Input(b);
    Add(a,b);
    Minus(a,b);
    Multi(a,b,c);
}
int Input(char n[]){
    char s[60];
    int i,len;
    for(i=0;i<60;i++)
        n[i]=0;
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
        n[i]=s[len-i-1]-'0';
}
void Add(char a[],char b[]){
    int i;
    char c[60];
    for(i=0;i<60;i++)
        c[i]=a[i]+b[i];
    for(i=0;i<60-1;i++){
        if(c[i]>=10){
            c[i+1]+=1;
            c[i]-=10;
        }
    }
    Print(c);
}
void Minus(char a[],char b[]){
    int i,j,x,y,z;
    char c[60];
    for(i=60-1;i>=0;i--){
        if(a[i]!=0){
            x=a[i];
            break;
        }
    }
    for(j=60-1;j>=0;j--){
        if(b[j]!=0){
            y=b[j];
            break;
        }
    }
    if((i==j&&x<y)||(i<j)){
        z=1;
    }
    for(i=0; i<60; i++){
        if(z==1)
            c[i]=b[i]-a[i];
        else
            c[i]=a[i]-b[i];
    }
    if(z==1)
        printf("-");
    for(i=0; i<60-1; i++){
        if(c[i]<0){
            c[i+1]-=1;
            c[i]+=10;
        }
    }
    Print(c);
}
void Multi(char a[],char b[],char c[]){
    int i,j;
    for(i=0;i<60*2;i++)
        c[i]=0;
    for(i=0;i<60;i++){
        for(j=0;j<60;j++) {
            c[i+j]+=a[j]*b[i];
            if(c[i+j]>=10){
                c[i+j+1]+=c[i+j]/10;
                c[i+j]=c[i+j]%10;
            }
        }
    }
    for(i=60*2-1;i>0;i--)
        if(c[i]!=0)
            break;
    for(;i>=0;i--)
        printf("%d",c[i]);
    printf("\n");
}
void Print(char c[]){
    int i;
    for(i=60-1;i>0;i--)
        if(c[i]!=0)
            break;
    for(;i>=0;i--)
        printf("%d",c[i]);
    printf("\n");
}
