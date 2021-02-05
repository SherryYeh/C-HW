#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char const *argv[]) {
    int i=0,j=0,k=0,keynum=0,direction=0,count=0,savenumcount1=0,savenumcount2=1,temp=0;
    char *data[5][100],*cut[4],keyword[100],input[5][1000];
    gets(keyword);
    for(i=0;i<5;i++){
        gets(input[i]);
    }
    cut[0]=strtok(keyword," ");
    i=1;
    while(cut[i-1]!=NULL){
        cut[i]=strtok(NULL," ");
        i+=1;
    }
    keynum=cut[1][0]-'0';
    int savenum[100][100];
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            savenum[i][j]=-1;
        }
    }
    if(strcmp(cut[2],"L")==0){
        direction=1;
    }
    else{
        direction=2;
    }
    for(i=0;i<5;i++){
        if(strcmp(input[i],"0")!=0){
            data[i][0]=strtok(input[i]," ");
            count=1;
            while(data[i][count-1]!=NULL){
                data[i][count]=strtok(NULL," ");
                count+=1;
            }
            count-=1;
            for(j=0;j<count;j++){
                if(strcmp(data[i][j],cut[0])==0){
                    savenum[savenumcount1][0]=i;
                    for(k=j-keynum;k<=j+keynum;k++){
                        if(k>=0&&k<count){
                            if(k==j){
                                temp=savenumcount2;
                            }
                            savenum[savenumcount1][savenumcount2]=k;
                            savenumcount2+=1;
                        }
                    }
                    savenum[savenumcount1][savenumcount2]=temp;
                    savenumcount1+=1;
                    savenumcount2=1;
                }
            }
        }
    }
    char sentence[savenumcount1][1000];
    int pos[savenumcount1],sort[savenumcount1],countchar[savenumcount1];
    for(i=0;i<savenumcount1;i++){
        sort[i]=i;
        countchar[i]=0;
    }
    for(i=0;i<savenumcount1;i++){
        sentence[i][0]='\0';
        for(j=1;j<100;j++){
            if(savenum[i][j+1]==-1){
                //printf("%d",savenum[i][j]);
                pos[i]=savenum[i][j];
                //printf("%s %d\n",data[savenum[i][0]][savenum[i][pos[i]]],pos[i]);
                break;
            }
            //printf("%d,",savenum[i][j]);
            strcat(sentence[i],data[savenum[i][0]][savenum[i][j]]);
            if(savenum[i][j+2]!=-1){
                strcat(sentence[i]," ");
            }
        }
        //printf("\n");
        //
    }
    for(i=0;i<savenumcount1;i++){
        if(direction==1){
            for(j=1;j<pos[i];j++){
                countchar[i]+=strlen(data[savenum[i][0]][savenum[i][j]]);
            }
        }
        else{
            for(j=pos[i]+1;savenum[i][j+1]!=-1;j++){
                countchar[i]+=strlen(data[savenum[i][0]][savenum[i][j]]);
            }
            //printf("%d\n",countchar[i]);
        }
    }
    for(i=0;i<savenumcount1;i++){
        for(j=0;j<i;j++){
            if(countchar[sort[j]]>=countchar[sort[i]]){
                temp=sort[j];
                sort[j]=sort[i];
                sort[i]=temp;
            }
        }
    }
    for(i=0;i<savenumcount1;i++){
        for(j=0;j<i;j++){
            if(countchar[sort[j]]==countchar[sort[i]]){
                if(direction==1){
                    //printf("%s %s %d %d\n",data[savenum[j][0]][savenum[j][pos[j]-1]],data[savenum[i][0]][savenum[i][pos[i]-1]],j,i);
                    if((int)data[savenum[j][0]][savenum[j][pos[j]-1]][strlen(data[savenum[j][0]][savenum[j][pos[j]-1]])-1]>(int)data[savenum[i][0]][savenum[i][pos[i]-1]][strlen(data[savenum[i][0]][savenum[i][pos[i]-1]])-1]){
                        temp=sort[j];
                        sort[j]=sort[i];
                        sort[i]=temp;
                    }
                }
                else{
                    //printf("%s %s\n",data[savenum[j][0]][savenum[j][pos[j]+1]],data[savenum[i][0]][savenum[i][pos[i]+1]]);
                    if((int)data[savenum[sort[j]][0]][savenum[sort[j]][pos[sort[j]]+1]][0]>(int)data[savenum[sort[i]][0]][savenum[sort[i]][pos[sort[i]]+1]][0]){
                        temp=sort[j];
                        sort[j]=sort[i];
                        sort[i]=temp;
                    }
                }
            }
        }
    }
    for(i=0;i<savenumcount1;i++){
        count=0;
        for(j=0;j<strlen(sentence[sort[i]]);j++){
            if(sentence[sort[i]][j]==' '){
                count+=1;
            }
            else if(count==pos[sort[i]]-1){
                sentence[sort[i]][j]=toupper(sentence[sort[i]][j]);
            }
            else{
                sentence[sort[i]][j]=tolower(sentence[sort[i]][j]);
            }
            printf("%c",sentence[sort[i]][j]);
        }
        if(i!=savenumcount1-1){
            printf("\n");
        }
    }
    return 0;
}
