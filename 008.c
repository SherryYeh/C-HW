#include<stdio.h>
#include<string.h>
int del(char *str,char A[100], char *result){
    while(*str!='\0'){
        if(strncmp(str,A,strlen(A))!=0)  {
            *result=*str;//printf("W=%sE=%s\n",str,result);
            str++;
            result++;
        }else{
            str+=strlen(A);
        }
    }
    *result='\0';
}
int main(){
    int i=0,j,k;
    char str[100][100],temp[100],A[100],result[100][100];
    scanf("%s",A);
    while(1){
        scanf("%s",str[i]);
        if(strcmp(str[i],"-1")==0){
            break;
        }
        i++;
    }
    for(j=0;j<i;j++){
        del(str[j],A,result[j]);
    }
    for(j=0;j<i-1;j++){
        for(k=j+1;k<i;k++){
            if(strcmp(result[j],result[k])>0){//printf("%s\n",result[j]);
                strcpy(temp,result[j]);
                strcpy(result[j],result[k]);
                strcpy(result[k],temp);
            }//printf("%s\n",result[j]);
        }
    }
    for(j=0;j<i;j++){
        printf("%s\n",result[j]);
    }

}
