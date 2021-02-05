#include<stdio.h>
#include<string.h>
int many;
typedef struct{
    char name[50];
    char data[300];
    int size;
}onefile;

onefile all[30];
void sort(){
    int i=0, j=0;
    onefile tmp;
    for(i=0; i<30-1; i++){
        for(j=0; j<30-i-1; j++){
            if(strcmp(all[j].name, all[j+1].name)>0){
                tmp = all[j];
                all[j] = all[j+1];
                all[j+1] = tmp;
            }
        }
    }
}
void touch(){
    char *p;
    p=strtok(NULL," ");
    while(p!=NULL){
        strcpy(all[many].name, p);
        many++;
        p=strtok(NULL," ");
    }
    sort(all);
}
int starplace(char *p){
    if(*p=='*')
        return 1;
    p++;
    while(*p!='\0'){
        if(*p=='*')
            return 2;
        p++;
    }
    return 0;
}
int same(char *all,char *file,int star){
    if(star==1){
        file++;
        all++;
        while(*file!='\0'&&*all!='\0'){
            if(*file!=*all)
                return -1;
            file++;
            all++;
        }
        return 1;
    }else if(star==2){
        while(*file!='*'){
            if(*file!=*all)
                return -1;
            file++;
            all++;
        }
        return 1;
    }
}
int find(char *fileName, int locate){
    int i,star;
    star=starplace(fileName);
    if(star==0){
        for(i=locate; i<many; i++){
            if(strcmp(all[i].name,fileName)==0){
                return i;
            }
        }
    }else{
        for(i=locate; i<many; i++){
            if(same(all[i].name,fileName,star)){
                return i;
            }
        }
    }
    return -1;
}

void vim(){
    char *fileName;
    int i=0,j,locate,save=0,size=0;
    char c,cmd[3],data[300];
    fileName = strtok(NULL, " ");
    locate = find(fileName, 0);
    c = fgetc(stdin);
    c = fgetc(stdin);
    if(c!='\n')
        data[i++]=c;
    while(1){
        c = fgetc(stdin);
        if(c==':'){
            fgets(cmd,sizeof(cmd),stdin);
            if(cmd[0]=='w'){
                save=1;
                all[locate].size=size;
                for(j=0;j<all[locate].size;j++)
                    all[locate].data[j]=data[j];
                if(cmd[1]=='q')
                    return;
            }else if(cmd[0]=='q'){
                if(cmd[1]=='!')
                    return;
                else if(save==0){
                    printf("error\n");
                    return;
                }else
                    return;
            }
        }else{
            data[i]=c;
            size=i+1;
            i++;
        }
    }
}

void cat(){
    char *fileName;
    int i,locate=0;
    fileName=strtok(NULL," ");
    while(1){
        locate = find(fileName, locate);
        if(locate==-1)
            break;
        for(i=0; i<all[locate].size; i++)
            printf("%c", all[locate].data[i]);
        locate++;
    }
}

void head(){
    int i,count=0,line=10,locate=0;
    char *fileName,*tmp,cmd[]="-n";
    tmp=strtok(NULL," ");
    if(strcmp(tmp, cmd)==0){
        tmp=strtok(NULL, " ");
        line=tmp[0]-'0';
        fileName=strtok(NULL, " ");
    }else
        fileName=tmp;
    while(1){
        locate=find(fileName, locate);
        if(locate==-1)
            return;
        count=0;
        for(i=0;i<all[locate].size;i++){
            printf("%c",all[locate].data[i]);
            if(all[locate].data[i]=='\n')
                count++;
            if(line==count)
                break;
        }
        locate++;
    }
}

void tail(){
    int i=0,count=0,line=10,pline=0,locate=0;
    char *fileName,*tmp,cmd[]="-n";
    tmp=strtok(NULL," ");
    if(strcmp(cmd,tmp)==0){
        tmp=strtok(NULL, " ");
        line=tmp[0]-'0';
        fileName=strtok(NULL, " ");
    }else
        fileName=tmp;
    while(1){
        locate=find(fileName,locate);
        if(locate==-1) return;
        count=0;
        for(i=0;i<all[locate].size;i++){
            if(all[locate].data[i]=='\n')
                count++;
        }
        pline=count-line;
        if(pline<0)
            pline=0;
        count=1;
        for(i=0;i<all[locate].size;i++){
            if(count>pline)
                printf("%c",all[locate].data[i]);
            if(all[locate].data[i]=='\n')
                count++;
        }
        locate++;
    }
}
void rm(){
    char *p;
    int locate=-1;
    char c[]="z";
    c[0]+=1;
    p=strtok(NULL, " ");
    while(p!=NULL){
        locate = find(p, 0);
        strcpy(all[locate].name, c);
        all[locate].size = 0;
        sort(all);
        many--;
        p=strtok(NULL, " ");
    }
}
int main(){
    int i=0;
    char *a,input[100];

    char c[]="z";
    c[0]+=1;
    for(i=0; i<30; i++){
        strcpy(all[i].name, c);
        all[i].size = 0;
    }

    while(1){
        fgets(input, sizeof(input), stdin);
        strtok(input,"\n");
        a=strtok(input," ");
        if(strcmp(a,"touch")==0){
            touch();
        }else if(strcmp(a,"vim")==0){
            vim();
        }else if(strcmp(a,"cat")==0){
            cat();
        }else if(strcmp(a,"head")==0){
            head();
        }else if(strcmp(a,"tail")==0){
            tail();
        }else if(strcmp(a,"rm")==0){
            rm();
        }else if(strcmp(a,"ls")==0){
            for(i=0;i<many; i++){
                printf("%s ",all[i].name);
            }
            printf("\n");
        }else if(strcmp(a,"exit")==0)
            break;
    }
}
