#include<stdio.h>
#include<string.h>
void times(char **word){
    char *rank[100];
    int i,j,times[100];
    for(i=0;i<100;i++){
        rank[i]=NULL;
        times[i]=0;
    }
    for(i=0;i<100;i++){
        if(*(word+i)==NULL)
            break;
        for(j=0;j<100;j++){
            if(rank[j]==NULL){
                rank[j]=*(word+i);
                times[j]++;
                break;
            }else if(strcmp(rank[j],*(word+i))==0){
                times[j]++;
                break;
            }
        }
    }
    sort(&rank[0],times);
    for(i=0;i<100;i++){
        if(rank[i]==NULL)
                break;
        printf("%s %d\n",rank[i],times[i]);
    }
}
void  sort(char **rank, int times[]){
    char *temp, **p;
    int int_temp=0;
    int n=0,i,j;
    p=rank;
    while(*p!=NULL){
        n++;
        p++;
    }
    for(i=0;i<n-1; i++){
        for(j=0;j<n-i-1; j++){
            if(times[j]<times[j+1] || (times[j]==times[j+1] && strcmp(*(rank+j),*(rank+j+1))>0)){
                temp=*(rank+j);
                *(rank+j)=*(rank+j+1);
                *(rank+j+1)=temp;
                int_temp=times[j];
                times[j]=times[j+1];
                times[j+1]=int_temp;
            }
        }
    }
}
int main(){
    char sentence[100],s1[100],s2[100];
    int i=0,j,w,k,q,z;
    gets(sentence);
    scanf("%s %s",s1,s2);
    char *word[100];
    word[0]=strtok(sentence," ");
    while(word[i]!=NULL){
        i++;
        word[i]=strtok(NULL," ");
    }
    for(j=0;j<i;j++){
        if(strcmp(word[j],s1)==0)
            printf("%s ",s2);
        else
            printf("%s ",word[j]);
    }
    printf("\n");
    for(j=0;j<i;j++){
        if(strcmp(word[j],s1)==0)
            printf("%s ",s2);
        printf("%s ",word[j]);
    }
    printf("\n");
    for(j=0;j<i;j++){
        if(strcmp(word[j],s1)!=0)
            printf("%s ",word[j]);
    }
    printf("\n");
    times(&word[0]);
}
