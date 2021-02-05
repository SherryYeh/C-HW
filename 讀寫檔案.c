#include<stdio.h>
#include<string.h>
typedef struct{
    char name[255];
    int data[255];
    int len;
}File;

File all[255];
int many=0;

void binary(File a){
    printf("%d bytes\n",a.len);
    int b[8]={0},i=7;
    int j;
    for(j=0; j<a.len; j++){
         int num = a.data[j];

        for(i=7; i>-1; i--){
            b[i] = num % 2;
            num /= 2;
        }
        for(i=0;i<8;i++)
            printf("%d ",b[i]);
        printf("\n");
    }

}
int compare(char yes[255]){
    int i;
    for(i=0;i<many;i++){
        if(strcmp(yes,all[i].name)==0)
            return 1;
    }
    return 0;
}
int getindex(char search[255]){
    int i;
    for(i=0;i<many;i++){
        if(strcmp(all[i].name,search)==0)
            return i;
    }
    return -1;
}
void main(){
    int j=0,input,choose,where,change;
    char find[50];
    while(1){
        scanf("%d",&choose);
        if(choose==1){
            char filename[255];
            scanf("%s",&filename);
            int havefile=compare(filename);
            if(havefile)
                printf("Error\n");
            else
                strcpy(&all[many].name, filename);



            all[many].len = 0;

            while(1){
                scanf("%d",&input);
                if(input==-1)
                    break;
                all[many].data[all[many].len++] = input;
            }
            if(havefile==0)
                many++;
        }
        if(choose==2){

            scanf("%s",find);
            int index=getindex(find);
            if(index==-1)
                printf("Error\n");
            else{
                binary(all[index]);
            }
        }
        if(choose==3){
            scanf("%s",&find);
            int index=getindex(find);
            if(index==-1)
                printf("Error\n");

            else{
                scanf("%d %d",&where,&change);
                all[index].data[where-1]=change;
            }
        }
        if(choose==4)
            break;

    }
}
