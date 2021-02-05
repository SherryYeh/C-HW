#include<stdio.h>
#include<string.h>
int main(){
    int i;
    char str[50];
    char *word[50];
    gets(str);
    for(i=0;i<strlen(str);i++){
        str[i]=tolower(str[i]);
    }
    GetWords(str,word);
}
int GetWords(char *sentence,char *word[]){
    int i=0,j,k,w;
    char *p;
    p=strtok(sentence," ");
    while(p!=NULL){
        word[i]=p;
        i++;
        p=strtok(NULL," ");
    }
    for(j=0;j<i;j++){
        w=1;
        for(k=j+1;k<i;k++){
            if(strcmp(word[j],word[k])==0){
                w++;
                word[k]="repeat";
            }
        }
        if(word[j]!="repeat")
            printf("%s %d\n",word[j],w);
    }
}
