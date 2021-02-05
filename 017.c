#include <stdio.h>
#include <stdlib.h>
char sw[4][4], tw[4][4], result[4][2];
int been_arranged(char student){
    int i;
    for(i=0;i<4;i++)
        if(result[i][1]==student)
            return 1;
    return 0;
}
int teacher_like_rank(int j, int i){
    int rank=1, k;
    for(k=0; k<4; k++){
        if(tw[j][k]==j+'W')
            break;
        rank++;
    }
    return rank;
}
void arrange(){
    char opt_teacher;
    int bestrank, match=0, i, j, k;
    for(i=0; i<4; i++)
        for(j=0; j<2; j++)
            result[i][j]='\0';
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(been_arranged(sw[j][i]))
                continue;
            opt_teacher=j+'W';
            if(result[opt_teacher-'W'][0])
                continue;
            bestrank=teacher_like_rank(j, i);
            for(k=j+1; k<4; k++){
                if(sw[k][i]==sw[j][i]){
                    int temp=teacher_like_rank(k, i);
                    if(temp<bestrank && !result[k][0]){
                        bestrank=temp;
                        opt_teacher=k+'W';
                    }
                }
            }
            result[opt_teacher-'W'][0]=opt_teacher;
            result[opt_teacher-'W'][1]=sw[j][i];
            match++;
            if(match==4) goto finish;
        }
    }
    finish:
    for(i=0; i<4; i++)
        printf("%c->%c\n", result[i][0], result[i][1]);
}
int main(){
    char *p,sentence[50];
    int i,j;
    for(i=0;i<4;i++){
        j=0;
        gets(sentence);
        p=strtok(sentence,",");
        while(p!=NULL){
            sw[i][j]=*p;
            j++;
            p=strtok(NULL,",");
        }
    }
    for(i=0;i<4;i++){
        j=0;
        gets(sentence);
        p=strtok(sentence,",");
        while(p!=NULL){
            tw[i][j]=*p;
            j++;
            p=strtok(NULL,",");
        }
    }
    arrange();
}
