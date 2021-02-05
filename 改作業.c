#include<stdio.h>
#include<string.h>
int isdelay(int num, char notdelay[20][10],char name[20]){
    int j;
    for(j=0;j<num;j++){
        if(strcmp(notdelay[j],name)==0)
            return 0;
    }
    return 1;
}
int main(){
    int i=0,j=0,mode,num,new;
    char name[20][10],notdelay[20][10];
    while(1){
        scanf("%s",&name[i]);
        if(strcmp(name[i],"-1")==0)
            break;
        strcpy(notdelay[i],name[i]);
        i++;
    }
    num=i--;
    while(1){
        scanf("%d",&mode);
        if(mode==1){
            i++;
            scanf("%s",&name[i]);
            new=i;
        }else if(mode==2){
            if(i<0){
                printf("Empty\n",i);
                i=0;
            }else {
                if(isdelay(num,notdelay,name[i]))
                    printf("%s's HW is delay\n",name[i]);
                else
                    printf("%s's HW is not delay\n",name[i]);
            }
            i--;
        }else if(mode==3){
            if(i==new){
                for(j=i;j>=0;j--)
                    printf("%s's HW is delay\n",name[j]);
            }else
                printf("Empty\n");
            break;
        }
    }
}
