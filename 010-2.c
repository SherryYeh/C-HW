#include<stdio.h>
#include<string.h>
int main(){
    int i,j=-1,n,sum=0,k=0,w,q,count,x;
    char a[100],b[100],*word[100],*num[100];
    gets(a);
    gets(b);
    n=Getwords(a,word);
    for(i=0;i<n;i++){
        if(isdigit(*word[i])){
            j++;
            num[j]=word[i];
            strrev(num[j]);
            sum+=atoi(num[j]);
        }
    }
    printf("%d",sum);
    while(b[k]!='\0'){
        k++;
    }
    for(w=0;w<k;w++){
        count=1;
        for(q=w+1;q<k;q++){
            if(b[w]=' ')
                break;
            if(isdigit(b[w])){
                printf("%c",b[w]);
                break;
            }
            if(b[w]==b[q]){
                count+=1;
            }
            for(x=w-1;x>=0;x--){
                if(b[w]==b[x]){
                    count=100;
                    break;
                }
            }
            if(count>=10){
                count=100;
                break;
            }
        }
        //printf("%c %d\n",b[w],count);
        if(count<100)
            printf("%d",count);
    }
}
int Getwords(char *a,char *word[]){
    int i=-1;
    char *tmp;
    tmp=strtok(a," ");
    while(tmp!=NULL){
        i++;
        word[i]=tmp;
        tmp=strtok(NULL," ");
    }
    return i;
}
