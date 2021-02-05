#include<stdio.h>
#include<string.h>

int getindex(char string[500]){
    if(strcmp(string,"BC")==0)
        return 0;
    else if(strcmp(string,"NC")==0)
        return 1;
    else if(strcmp(string,"CT")==0)
        return 2;
    else if(strcmp(string,"NS")==0)
        return 3;
    else if(strcmp(string,"NM")==0)
        return 4;
    else if(strcmp(string,"HL")==0)
        return 5;
    else if(strcmp(string,"NL")==0)
        return 6;
}

char **split(char sentence[500],char word[500]){
    char *tmp=(char *)malloc(sizeof(char)*strlen(sentence)+1);
    strcpy(tmp, sentence);
    char **result = (char **)malloc(sizeof(char *) * 100);
    int i = 0;
    result[i] = strtok(tmp, word);
    while(result[i] != NULL){
        i++;
        result[i] = strtok(NULL, word);
    }
    return result;
}
char *format(char choose[100]){
    int i,many=0,index=0;
    char tmp[100] = "";
    char *result=(char *)malloc(sizeof(char)*100);
    for(i=0;i<strlen(choose);i++){
        tmp[index]=choose[i];
        index++;
        if(choose[i]==' '){
            index--;
        }
    }
    tmp[index]='\0';
    index = 0;
    for(i=0;i<strlen(tmp);i++){
        result[index] = tmp[i];
        index++;
        if(tmp[i]=='+'||tmp[i+1] == '+'){
            many=0;
        }else{
            many++;
        }

        if(many == 2&&i!=strlen(tmp)-1){
            result[index] = ' ';
            index++;
            many = 0;
        }
    }
    result[index]='\0';
    return result;
}
int compare(char **space,int adj[7]){
    int i=0;
    while(space[i]!=NULL){
        if(adj[getindex(space[i])]!=1){
            return 0;
        }
        i++;
    }
    return 1;
}
int repeat(char **yes,char one[500]){
    int i=0;
    while(yes[i]!=NULL){
        if(strcmp(yes[i],one)==0)
            return 1;
        i++;
    }return 0;
}
char **search(char one[100][500],int adj[100][7],int n,char **list){
    int i=0,j,index=0;
    char **yes = (char **)malloc(sizeof(char *)*(n+1));
    for(i=0;i<n;i++){
        yes[i]=NULL;
    }
    i=0;
    while(list[i]!=NULL){
        char **space=split(list[i]," ");
        for(j=0;j<n;j++){
            if(compare(space,adj[j])&&repeat(yes,one[j])==0){
                yes[index]=one[j];
                index++;
            }
        }
        i++;
    }
    return yes;
}
void swap(char **a,char **b){
    char *tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
void sort(char **ans1){
    int i,j;
    for(i=0;ans1[i] !=NULL;i++){
        for(j=i+1;ans1[j] !=NULL;j++){
            if(strcmp(ans1[i],ans1[j])>0){
                swap(&ans1[i],&ans1[j]);
            }
        }
    }
}
int main(){
    int n,i,j,index,m;
    scanf("%d\n",&n);
    char one[100][500],sentence[500],choose[100];
    int adj[100][7]={0};
    for(i=0;i<n;i++){
        gets(sentence);
        char **cut = split(sentence, " ");
        strcpy(one[i],cut[0]);
        for(j=1;cut[j]!=NULL;j++){
            index=getindex(cut[j]);
            adj[i][index]=1;
        }

    }
    scanf("%d\n",&m);
    for(i=0;i<m;i++){
        gets(choose);
        char *format_str = format(choose);
        char **list = split(format_str,"+");
        char **ans1=search(one,adj,n,list);
        sort(ans1);
        j=0;
        while(ans1[j]!=NULL){
            printf("%s ",ans1[j]);
            j++;
        }

        printf("\n");
    }

}
