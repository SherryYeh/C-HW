#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int i=0,a;
    char word[10],gate[10],*p,sentence[10],tmp[10];
    gets(sentence);
    p=strtok(sentence,",");
    while(p!=NULL){
        word[i]=*p;
        tmp[i]=*p;
        i++;
        p=strtok(NULL,",");
    }

    i=0;
    gets(sentence);
    p=strtok(sentence,",");
    while(p!=NULL){
        gate[i]=*p;//printf("%c",gate[0]);
        i++;
        p=strtok(NULL,",");
    }
    if(gate[0]=='N'){
        if(word[0]=='0')
            word[0]='1';
        else
            word[0]='0';
    }
    printf("%c,",word[0]);
    for(i=1;i<3;i++){
        if(gate[i]=='A'){
            if(word[i-1]=='0'||word[i]=='0')
                word[i]='0';
            else
                word[i]='1';
        }else{
            if(word[i-1]=='1'||word[i]=='1')
                word[i]='1';
            else
                word[i]='0';
        }
        printf("%c,",word[i]);
    }
    if(gate[i]=='A'){
        if(tmp[2]=='0'||word[i]=='0')
            tmp[i]='0';
        else
            tmp[i]='1';
    }else{
        if(tmp[2]=='1'||word[i]=='1')
            tmp[i]='1';
        else
            tmp[i]='0';
    }
    if(gate[4]=='A'){
        if(tmp[i]=='0'||word[2]=='0')
            tmp[i]='0';
        else
            tmp[i]='1';
    }else{
        if(tmp[i]=='1'||word[2]=='1')
            tmp[i]='1';
        else
            tmp[i]='0';
    }
    printf("%c",tmp[i]);
}
