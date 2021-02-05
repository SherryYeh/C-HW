#include<stdio.h>
#include<string.h>
int main(){
    int i;
    char a[100],b[100];
    scanf("%s %s",a,b);
    search(a,b);
}
void same(int i,int j,char a[],char b[],int *index,int *max){
    int k,len,count=0;
    len=strlen(a)>strlen(b)?strlen(b):strlen(a);
    for(k=0;k<len;k++){
        if(j+k>strlen(a)-1||i+k>strlen(b)-1)
            break;
        if(b[i+k]==a[j+k]){

             count++;
        }else{
            break;
        }

    }
    if(count>*max){
        *max=count;
        *index=j;
    }
}
int search(char a[],char b[]){
    int i,j;
    int index=0;
    int max=0;
    for(i=0;i<strlen(b);i++){
        for(j=0;j<strlen(a);j++){
            if(b[i]==a[j])
                same(i,j,a,b,&index,&max);
        }
    }
    for(i=index;i<max+index;i++){
        printf("%c",a[i]);
    }
    printf("\n");
}
