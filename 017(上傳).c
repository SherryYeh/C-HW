#include<stdio.h>
#include<string.h>
int tearank(int j,char tea[5][5]){
    int rank=1,k;
    for(k=0;k<4;k++){
        if(tea[j][k]==j+'W')
            break;
        rank++;
    }
    return rank;
}
int stuyes(char student,char result[5][3]){
    int i;
    for(i=0;i<4;i++)
        if(result[i][1]==student)
            return 1;
    return 0;
}
void second(char result[5][3],char stu[5][5],char tea[5][5]){
    char findtea;
    int i,j,k,minrank,yes=0;
    for(i=0;i<4;i++)
        for(j=0;j<2;j++)
            result[i][j]='\0';
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            minrank=tearank(j,tea);
            if(stuyes(stu[j][i],result))
                continue;
            findtea=j+'W';
            if(result[findtea-'W'][0])
                continue;
            for(k=j+1;k<4;k++){
                if(stu[k][i]==stu[j][i]){
                    int temp=tearank(k,tea);
                    if(temp<minrank && !result[k][0]){
                        minrank=temp;
                        findtea=k+'W';
                    }
                }
            }
            result[findtea-'W'][0]=findtea;
            result[findtea-'W'][1]=stu[j][i];
            yes++;
            if(yes==4)
                break;
        }
    }
    for(i=0;i<4;i++)
        printf("%c->%c\n",result[i][0],result[i][1]);
}
int main(){
    char *p,sentence[50],stu[5][5],tea[5][5],result[5][3];
    int i,j;
    for(i=0;i<4;i++){
        j=0;
        gets(sentence);
        p=strtok(sentence,",");
        while(p!=NULL){
            stu[i][j]=*p;
            j++;
            p=strtok(NULL,",");
        }
    }
    for(i=0;i<4;i++){
        j=0;
        gets(sentence);
        p=strtok(sentence,",");
        while(p!=NULL){
            tea[i][j]=*p;
            j++;
            p=strtok(NULL,",");
        }
    }
    second(result,stu,tea);
}
