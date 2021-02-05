#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 30

typedef struct{
    char name[50];
    char text[300];
    int size;
}file_t;

int compare(char *s, char *b, int mod){

    if(mod==1){
        while(*s!='\0') s++;
        while(*b!='\0') b++;
        while(*s!='*'){
            if(*s!=*b) return -1;
            s--;
            b--;
        }
        return 0;
    }
    if(mod==2){
        while(*s!='*'){
            if(*s!=*b) return -1;
            s++;
            b++;
        }
        return 0;
    }
}

int haveStart(char *p){
    if(*p=='*') return 1;
    p++;
    while(*p!='\0'){
        if(*p=='*') return 2;
        p++;
    }
    return 0;
}

int find(file_t *allFile,char *fileName, int amount, int locate){
    int i=0;
    int mod=0;
    mod = haveStart(fileName);
    if(mod==0){
        for(i=locate; i<amount; i++){
            if(strcmp(allFile[i].name, fileName)==0){
                return i;
            }
        }
    }
    else{
        for(i=locate; i<amount; i++){
            if(compare(fileName, allFile[i].name, mod)==0){
                return i;
            }
        }
    }
    return -1;
}

void initialize(file_t *allFile){
    int i=0;
    char c[]="z";

    c[0]+=1;
    for(i=0; i<SIZE; i++){
        strcpy(allFile[i].name, c);
        allFile[i].size = 0;
    }
}

void sort(file_t *allFile){
    int i=0, j=0;
    file_t tmp;

    for(i=0; i<SIZE-1; i++){
        for(j=0; j<SIZE-i-1; j++){
            if(strcmp(allFile[j].name, allFile[j+1].name)>0){
                tmp = allFile[j];
                allFile[j] = allFile[j+1];
                allFile[j+1] = tmp;
            }
        }
    }

}

void touch_f(file_t *allFile, int *amount){
    char *p;

    while(1){
        p = strtok(NULL, " ");
        if(p==NULL) break;
        strcpy(allFile[*amount].name, p);
        (*amount)++;
    }
    sort(allFile);
}

void rm_f(file_t *allFile, int *amount){
    char *p;
    int locate=-1;
    char c[]="z";
    c[0]+=1;

    while(1){
        p = strtok(NULL, " ");
        if(p==NULL) break;
        locate = find(allFile, p, *amount, 0);
        strcpy(allFile[locate].name, c);
        allFile[locate].size = 0;
        sort(allFile);
        (*amount)--;
    }
}

void vim_f(file_t *allFile, int amount){
    char *fileName;
    int locate=0, i=0, j=0;
    char text[300];
    char c;
    char command[3];
    int save=0;
    int size=0;

    fileName = strtok(NULL, " ");
    locate = find(allFile, fileName, amount, 0);
    c = fgetc(stdin);
    c = fgetc(stdin);
    if(c!='\n') text[i++] = c;
    while(1){
        c = fgetc(stdin);
        if(c==':'){
            fgets(command, sizeof(command),stdin);
            if(command[0]=='w'){
                save = 1;
                allFile[locate].size = size;
                for(j=0; j<allFile[locate].size; j++) allFile[locate].text[j] = text[j];
                if(command[1]=='q') return;
            }
            else if(command[0]=='q'){
                if(command[1]=='!') return;
                else if(save==0) {
                    printf("error\n");
                    return;
                }
                else return;
            }
        }
        else{
            text[i] = c;
            size = i+1;
            i++;
        }
    }
}

void cat_f(file_t *allFile, int amount){
    char *fileName;
    int locate=0;
    int i=0;

    fileName = strtok(NULL, " ");
    while(1){
        locate = find(allFile, fileName, amount, locate);
        if(locate==-1) break;
        for(i=0; i<allFile[locate].size; i++){
            printf("%c", allFile[locate].text[i]);
        }
        locate++;
    }
}

void head_f(file_t *allFile, int amount){
    char *fileName;
    int locate=0;
    int i=0;
    int line=10;
    int count=0;
    char command[]="-n";
    char *tmp;

    tmp = strtok(NULL, " ");
    if(strcmp(tmp, command)==0){
        tmp = strtok(NULL, " ");
        line = tmp[0]-'0';
        fileName = strtok(NULL, " ");
    }
    else fileName = tmp;

    while(1){
        locate = find(allFile, fileName, amount, locate);
        if(locate==-1) return;
        count=0;
        for(i=0; i<allFile[locate].size; i++){
            printf("%c", allFile[locate].text[i]);
            if(allFile[locate].text[i]=='\n') count++;
            if(count==line) break;
        }
        locate++;
    }
}

void tail_f(file_t *allFile, int amount){
    char *fileName;
    int locate=0;
    int i=0;
    int line=10;
    int pline=0;
    int count=0;
    char command[]="-n";
    char *tmp;

    tmp = strtok(NULL, " ");
    if(strcmp(tmp, command)==0){
        tmp = strtok(NULL, " ");
        line = tmp[0]-'0';
        fileName = strtok(NULL, " ");
    }
    else fileName = tmp;

    while(1){
        locate = find(allFile, fileName, amount, locate);
        if(locate==-1) return;
        count=0;
        for(i=0; i<allFile[locate].size; i++){
            if(allFile[locate].text[i]=='\n') count++;
        }
        pline = count - line;
        if(pline<0) pline=0;
        count=1;
        for(i=0; i<allFile[locate].size; i++){
            if(count>pline) printf("%c", allFile[locate].text[i]);
            if(allFile[locate].text[i]=='\n') count++;
        }
        locate++;
    }
}

void ls_f(file_t *allFile, int amount){
    int i=0;
    for(i=0; i<amount; i++){
        printf("%s ", allFile[i].name);
    }
    printf("\n");
}

int main(){
    file_t allFile[SIZE];
    int amount=0, i=0;
    char *p;
    char IN[100];
    char touch[]="touch", vim[]="vim", cat[]="cat", head[]="head", tail[]="tail", rm[]="rm", ls[]="ls", exit[]="exit";

    initialize(allFile);

    while(1){
        fgets(IN, sizeof(IN), stdin);
        strtok(IN, "\n");

        p = strtok(IN, " ");

        if(strcmp(p, touch)==0){
            touch_f(allFile, &amount);
        }
        else if(strcmp(p, ls)==0){
            ls_f(allFile, amount);
        }
        else if(strcmp(p, vim)==0){
            vim_f(allFile, amount);
        }
        else if(strcmp(p, cat)==0){
            cat_f(allFile, amount);
        }
        else if(strcmp(p, head)==0){
            head_f(allFile, amount);
        }
        else if(strcmp(p, tail)==0){
            tail_f(allFile, amount);
        }
        else if(strcmp(p, rm)==0){
            rm_f(allFile, &amount);
        }
        else if(strcmp(p, exit)==0) break;
    }
    return 0;
}
