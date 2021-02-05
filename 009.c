#include<stdio.h>
#include<string.h>
int main(){
    int i;
    char a[100],b[100];
    scanf("%s %s",a,b);
    if(strlen(b)>strlen(a)){
        search(a,b);
    }else{
        search(b,a);
    }
}
int search(char a[],char b[]){
    int i=0,j=0,count=0,k,h=0,max=0,x=0;//printf("%d\n",strlen(b));
    int sum[100];
    char L[100][100];
    for(i=0;i<100;i++)
        sum[i]=0;
    for(i=0;i<strlen(b);i++){
        for(k=0;k<strlen(a);k++){
          // printf("A=%d %c %d %c %d\n",i+count,b[i+count],k,a[k],i);
            if(b[i+count]==a[k]){
                count++;
                L[x][j]=a[k];//printf("%c %d C=%d\n",L[x][j],x,count);
                j++;
            }else if(count>0){
                j=0;
                sum[x]=count;
                x++;//printf("B=%d %d\n",x,sum[x]);
                if(max<count){
                    max=count;
                }
                count=0;
                break;
            }
            if(i+count==strlen(b)&&count!=0){
                sum[x]=count;
                if(max<count){
                    max=count;
                }
            }
            if(b[i+count]=='\0')
                break;
        }
    }
    for(i=0;i<strlen(b);i++){
        if(sum[i]==max){
            for(j=0;j<max;j++){
                printf("%c",L[i][j]);
            }
            break;
        }
    }
}
