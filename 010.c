#include<stdio.h>
#include<string.h>
int main(){
    int i,j=-1,n,sum=0,k=0,w,q,count,x;
    char a[100]={},b[100]={},*word[100]={},*num[100]={},result[100]={};
    fgets(a,sizeof(a),stdin);
    fgets(b,sizeof(b),stdin);
    n=Getwords(a,word);
    for(i=0;i<=n;i++){
        if(isdigit(*word[i])){
            j++;
            num[j]=word[i];
            sum+=reverse(num[j],strlen(num[j]));
        }
    }
    printf("%d",sum);
    while(b[k]!='\0'){
        k++;
    }
    for(w=0;w<k;w++){
        count=1;
        if(w==k-1){
            for(x=k-2;x>=0;x--){
                if(b[w]==b[x]){
                    count=100;
                }
            }
            break;
        }
        for(q=w+1;q<k;q++){//printf("Q=%c %d\n",b[q],q);
            if(b[w]==' '){
                count=100;
                break;
            }
            if(isdigit(b[w])){
                printf("%c",b[w]);
                break;
            }
            if(b[w]==b[q]){
                count+=1;
            }

            if(count>=10){
                count=100;
                break;
            }
        }
        for(x=w-1;x>=0;x--){//printf("B %c %c %d\n",b[w],b[x],count);
            if(b[w]==' '){
                count=100;
                break;
            }
            if(b[w]==b[x]){
                count=100;
                break;
            }
        }   // printf("C  %s %d\n",w,count);
        if(count<100)
            printf("%d",count);
    }
}
int Getwords(char *a,char *word[]){
    int i=-1;
    char *tmp={'0'};
    tmp=strtok(a," ");
    while(tmp!=NULL){
        i++;
        word[i]=tmp;
        tmp=strtok(NULL," ");
    }
    return i;
}
void reverse(char num[],int n){
	int i,j=-1,sum;
	char result[100]={};
	for(i=n-1;i>=0;i--){
        j++;
        result[j]=num[i];
	}
    sum=atoi(result);
    return sum;
}
