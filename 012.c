#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    int i,j,k=0,num,wordlen,count,savenum[200][200]={},count1=0,count2=1,temp;
    char *word[5][200]={},*search[4]={},A[200]={},input[5][200]={};
    gets(A);
    for(i=0;i<5;i++){
        gets(input[i]);
    }
    search[0]=strtok(A," ");
    i=0;
    while(search[i]!=NULL){
        search[i+1]=strtok(NULL," ");
        i++;
    }
    num=search[1][0]-'0';
    for(i=0;i<200;i++){
        for(j=0;j<200;j++){
            savenum[i][j]=-1;
        }
    }
    for(i=0;i<5;i++){
        if(input[i]!='0'){
            word[i][0]=strtok(input[i]," ");
            wordlen=0;
            while(word[i][wordlen]!=NULL){
                word[i][wordlen+1]=strtok(NULL," ");
                wordlen++;
            }
            for(j=0;j<wordlen;j++){
                if(strcmp(word[i][j],search[0])==0){
                    savenum[count1][0]=i;
                    for(k=j-num;k<=j+num;k++){
                        if(k>=0&&k<wordlen){
                            if(k==j){
                                temp=count2;
                            }
                            savenum[count1][count2]=k;
                            count2++;
                        }
                    }
                    savenum[count1][count2]=temp;
                    count1++;
                    count2=1;
                }
            }
        }
    }
    char sentence[count1][200];
    int pos[count1],rank[count1],charcount[count1];
    for(i=0;i<count1;i++){
        rank[i]=i;
        charcount[i]=0;
    }
    for(i=0;i<count1;i++){
        sentence[i][0]='\0';
        for(j=1;j<200;j++){
            if(savenum[i][j+1]==-1){
                pos[i]=savenum[i][j];
                break;
            }
            strcat(sentence[i],word[savenum[i][0]][savenum[i][j]]);
            if(savenum[i][j+2]!=-1){
                strcat(sentence[i]," ");
            }
        }
    }
    for(i=0;i<count1;i++){
        if(search[2]='L'){
            for(j=1;j<pos[i];j++){
                charcount[i]+=strlen(word[savenum[i][0]][savenum[i][j]]);
            }
        }else{
            for(j=pos[i]+1;savenum[i][j+1]!=-1;j++){
                charcount[i]+=strlen(word[savenum[i][0]][savenum[i][j]]);
            }
        }
    }
    for(i=0;i<count1;i++){
        for(j=0;j<i;j++){
            if(charcount[rank[j]]>=charcount[rank[i]]){
                temp=rank[j];
                rank[j]=rank[i];
                rank[i]=temp;
            }
        }
    }
    for(i=0;i<count1;i++){
        for(j=0;j<i;j++){
            if(charcount[rank[j]]==charcount[rank[i]]){
                if(search[2]='L'){
                    if((int)word[savenum[j][0]][savenum[j][pos[j]-1]][strlen(word[savenum[j][0]][savenum[j][pos[j]-1]])-1]>(int)word[savenum[i][0]][savenum[i][pos[i]-1]][strlen(word[savenum[i][0]][savenum[i][pos[i]-1]])-1]){
                        temp=rank[j];
                        rank[j]=rank[i];
                        rank[i]=temp;
                    }
                }else{
                    if((int)word[savenum[rank[j]][0]][savenum[rank[j]][pos[rank[j]]+1]][0]>(int)word[savenum[rank[i]][0]][savenum[rank[i]][pos[rank[i]]+1]][0]){
                        temp=rank[j];
                        rank[j]=rank[i];
                        rank[i]=temp;
                    }
                }
            }
        }
    }
    for(i=0;i<count1;i++){
        count=0;
        for(j=0;j<strlen(sentence[rank[i]]);j++){
            if(sentence[rank[i]][j]==' '){
                count+=1;
            }else if(count==pos[rank[i]]-1){
                sentence[rank[i]][j]=toupper(sentence[rank[i]][j]);
            }else{
                sentence[rank[i]][j]=tolower(sentence[rank[i]][j]);
            }
            printf("%c",sentence[rank[i]][j]);
        }
        if(i!=count1-1){
            printf("\n");
        }
    }
}
