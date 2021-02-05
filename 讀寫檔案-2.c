#include<stdio.h>
#include<string.h>
void binary(int a){
    int b[8]={0},i=7;
    while(1){
        b[i]=a%2;
        i--;
        a=a/2;
        if(a<2){
            b[i]=a;
            for(i=0;i<8;i++)
                printf("%d ",b[i]);
            printf("\n");
            return;
        }
    }
}
void main(){
    int i=0,j,choose,list[20],where,num;
	FILE *file ;
	char filename[10],search[10];
	while(1){
        scanf("%d",&choose);
        while(1){
            if(choose==1){
                scanf("%s",&filename);
                while(1){
                    scanf("%d",&list[i]);
                    if(list[i]==-1)
                        break;
                    for(j=0;j<i;j++)
                        if(list[i]==list[j])
                            printf("Error");
                    i++;
                }
            }else if(choose==2){
                scanf("%s",&search);
                if(strcmp(search,filename)==0){
                    printf("%d bytes\n",i);
                    for(j=0;j<i;j++)
                        binary(list[j]);
                }else
                    printf("Error");
            }
            else if(choose==3){
                scanf("%s",&search);
                if(strcmp(search,filename)==0){
                    scanf("%d %d",&where,&num);
                    list[where-1]=num;printf("A %d",list[where]);
                }else
                    printf("Error");
            }
            break;
        }
        if(choose==4)
            break;
	}
}
