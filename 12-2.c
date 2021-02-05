#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char const *argv[]) {
    int i=0,j=0,k=0,num=0,direction=0,wordlen=0,count1=0,count2=1,temp=0;
    char *word[5][100],*search[4],A[100],input[5][1000];
    gets(A);
    for(i=0;i<5;i++){
        gets(input[i]);
    }
    search[0]=strtok(A," ");
    i=1;
    while(search[i-1]!=NULL){
        search[i]=strtok(NULL," ");
        i++;
    }
    num=search[1][0]-'0';
    int savenum[100][100];
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            savenum[i][j]=-1;
        }
    }
    if(search[2]='L'){
        direction=1;
    }
    else{
        direction=2;
    }
    for(i=0;i<5;i++){
        if(strcmp(input[i],"0")!=0){
            word[i][0]=strtok(input[i]," ");
            wordlen=1;
            while(word[i][wordlen-1]!=NULL){
                word[i][wordlen]=strtok(NULL," ");
                wordlen+=1;
            }
            wordlen-=1;
            for(j=0;j<wordlen;j++){
                if(strcmp(word[i][j],search[0])==0){
                    savenum[count1][0]=i;
                    for(k=j-num;k<=j+num;k++){
                        if(k>=0&&k<wordlen){
                            if(k==j){
                                temp=count2;
                            }
                            savenum[count1][count2]=k;
                            count2+=1;
                        }
                    }
                    savenum[count1][count2]=temp;
                    count1+=1;
                    count2=1;
                }
            }
        }
    }
    char sentence[count1][1000];
    int pos[count1],sort[count1],wordlenchar[count1];
    for(i=0;i<count1;i++){
        sort[i]=i;
        wordlenchar[i]=0;
    }
    for(i=0;i<count1;i++){
        sentence[i][0]='\0';
        for(j=1;j<100;j++){
            if(savenum[i][j+1]==-1){
                //printf("%d",savenum[i][j]);
                pos[i]=savenum[i][j];
                //printf("%s %d\n",word[savenum[i][0]][savenum[i][pos[i]]],pos[i]);
                break;
            }
            //printf("%d,",savenum[i][j]);
            strcat(sentence[i],word[savenum[i][0]][savenum[i][j]]);
            if(savenum[i][j+2]!=-1){
                strcat(sentence[i]," ");
            }
        }
        //printf("\n");
        //
    }
    for(i=0;i<count1;i++){
        if(direction==1){
            for(j=1;j<pos[i];j++){
                wordlenchar[i]+=strlen(word[savenum[i][0]][savenum[i][j]]);
            }
        }
        else{
            for(j=pos[i]+1;savenum[i][j+1]!=-1;j++){
                wordlenchar[i]+=strlen(word[savenum[i][0]][savenum[i][j]]);
            }
            //printf("%d\n",wordlenchar[i]);
        }
    }
    for(i=0;i<count1;i++){
        for(j=0;j<i;j++){
            if(wordlenchar[sort[j]]>=wordlenchar[sort[i]]){
                temp=sort[j];
                sort[j]=sort[i];
                sort[i]=temp;
            }
        }
    }
    /*for(i=0;i<count1;i++){
        printf("%s %d\n",sentence[sort[i]],sort[i]);
    }
    printf("\n\n");*/
    for(i=0;i<count1;i++){
        for(j=0;j<i;j++){
            if(wordlenchar[sort[j]]==wordlenchar[sort[i]]){
                if(direction==1){
                    //printf("%s %s %d %d\n",word[savenum[j][0]][savenum[j][pos[j]-1]],word[savenum[i][0]][savenum[i][pos[i]-1]],j,i);
                    if((int)word[savenum[j][0]][savenum[j][pos[j]-1]][strlen(word[savenum[j][0]][savenum[j][pos[j]-1]])-1]>(int)word[savenum[i][0]][savenum[i][pos[i]-1]][strlen(word[savenum[i][0]][savenum[i][pos[i]-1]])-1]){
                        temp=sort[j];
                        sort[j]=sort[i];
                        sort[i]=temp;
                    }
                }
                else{
                    //printf("%s %s\n",word[savenum[j][0]][savenum[j][pos[j]+1]],word[savenum[i][0]][savenum[i][pos[i]+1]]);
                    if((int)word[savenum[sort[j]][0]][savenum[sort[j]][pos[sort[j]]+1]][0]>(int)word[savenum[sort[i]][0]][savenum[sort[i]][pos[sort[i]]+1]][0]){
                        temp=sort[j];
                        sort[j]=sort[i];
                        sort[i]=temp;
                    }
                }
            }
        }
    }
    /*for(i=0;i<count1;i++){
        printf("%s %d\n",sentence[sort[i]],sort[i]);
    }*/
    for(i=0;i<count1;i++){
        wordlen=0;
        for(j=0;j<strlen(sentence[sort[i]]);j++){
            if(sentence[sort[i]][j]==' '){
                wordlen+=1;
            }
            else if(wordlen==pos[sort[i]]-1){
                sentence[sort[i]][j]=toupper(sentence[sort[i]][j]);
            }
            else{
                sentence[sort[i]][j]=tolower(sentence[sort[i]][j]);
            }
            printf("%c",sentence[sort[i]][j]);
        }
        if(i!=count1-1){
            printf("\n");
        }
    }
    return 0;
}
