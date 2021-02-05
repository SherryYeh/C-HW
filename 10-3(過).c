#include <stdio.h>
#include <string.h>
int first(char *a){
    int i=0,j,x=0,y=1;
    char num[10];
    while(*a!=0){
        while(isdigit(*a)){
            num[i]=*a;
            i++;
            a++;
        }
        if(i!=0){
            j=i;
            for(i=0;i<j;i++){
                x+=(num[i]-'0')*y;
                y*=10;
            }
            y=1;
            i=0;
        }
        a++;
    }
    printf("%04d",x%10000);
}
int second(char *b){
    char compare[100];
    int count[100];
    int i=0;
    for(i=0;i<100;i++){
        compare[i]='\0';
        count[i]=0;
    }
    while(*b!=NULL){
        while(*b==' '){
            b++;
        }
        for(i=0;i<100;i++){
            if(compare[i]=='\0'){
                compare[i] = *b;
                if(isdigit(*b)){
                    count[i] = *b-'0';
                }else{
                    count[i]++;
                }
                break;
            }else if(compare[i]==*b && *b>'9'){
                count[i]++;
                break;
            }
        }
        b++;
    }
    for(i=0;i<strlen(compare)-1;i++){
        if(count[i]<=10)
            printf("%d",count[i]);
    }
 }
int main(){
    char a[100],b[100];
    fgets(a,sizeof(a),stdin);
    fgets(b,sizeof(b),stdin);
    first(a);
    second(b);
}
