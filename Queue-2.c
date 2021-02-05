#include<stdio.h>
int exist(char name[100][10],char find[100],int many,int choose){
    int i;
    for(i=0;i<many;i++){
        if(strcmp(find,name[i])==0)
            return i;
    }
    if(find == NULL){
        printf("Queue %s isn't exist\n",find);
    return -1;
    }
}
int main(){
    int i,j,choose,many=0,data[101][101],yes,first[100],end[100],start;
    int out[101]={0};
    char name[100][10],find[100];

    for(i=0;i<101;i++){
        for(j=0;j<101;j++){
            data[i][j]=-1;
        }
        data[i][100]=0;
    }
    while(1){
        scanf("%d",&choose);
        if(choose==1){
            scanf("%s",&name[many]);
            many++;
        }else if(choose==2){
            scanf("%s",&find);
            yes=exist(name,find,many,choose);
            if(yes!=-1){
                scanf("%d",&data[yes][data[yes][100]]);
                data[yes][100]++;
            }
        }else if(choose==3){
            scanf("%s",&find);
            yes=exist(name,find,many,choose);
            if(yes!=-1){
                if(data[yes][100]==0){
                    printf("Queue is empty\n");
                    continue;
                }
                data[yes][out[yes]]=-1;
                data[yes][100]--;
                out[yes]++;
            }
        }else if(choose==4){
            scanf("%s %s",&first,&end);
            start=exist(name,first,many,choose);
            yes=exist(name,end,many,choose);
            if(start!=-1 && yes!=-1){
                for(i=0;i<data[yes][100];i++){
                    data[start][data[start][100]+i]=data[yes][i];
                    data[start][100]++;
                }
                data[yes][100]=-1;
            }
        }else if(choose==5){
            printf("****************************************\n");
            for(i=0;i<many;i++){
                if(many==0)
                    printf("Isn't have any queue");
                else if(data[i][100]==-1){
                    continue;
                }else if(data[i][100]==0){
                    printf("Queue Name:%s Queue Size:%d Queue Element:Queue is empty",name[i],data[i][100]);
                }else{
                    printf("Queue Name:%s Queue Size:%d Queue Element:",name[i],data[i][100]);
                    for(j=0;j<100;j++){
                        if(data[i][j]!=-1)
                            printf("%d ",data[i][j]);
                    }
                }
                printf("\n");
            }
            printf("****************************************\n");
        }else if(choose==6)
            break;
    }
}
