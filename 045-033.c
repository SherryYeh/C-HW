#include<stdio.h>
int compute(int all[10][10]);
int right(int i,int j,int all[10][10]);
int down(int i,int j,int all[10][10]);
int slide1(int i,int j,int all[10][10]);
int slide2(int i,int j,int all[10][10]);
int main(){
    int i,j;
    int all[10][10];
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            scanf("%d",&all[i][j]);
        }//printf("%d",all);
    }
    compute(all);
}
int compute(int all[10][10]){
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(all[i][j]==0){
                if(right(i,j,all) || down(i,j,all) || slide1(i,j,all) || slide2(i,j,all)){
                    printf("%d %d\n",i,j);
                }
            }
        }
    }
}
int right(int i,int j,int all[10][10]){
    int a=j;
    int count=0;
    while(1){
        if(a-1<0){
            break;
        }else{
            a-=1;
            if(all[i][a]==1){
                count+=1;
            }
            if(all[i][a]==0){
                break;
            }
        }
    }
    int a2=j;
    while(1){
        if(a2+1>9){
            break;
        }else{
            a2+=1;
            if(all[i][a2]==1){
                  count+=1;
            }
            if(all[i][a2]==0){
                break;
            }
        }
    }
    if(count>=4){
        return 1;
    }else{
        return 0;
    }
}
int down(int i,int j,int all[10][10]){
    int a=i;
    int count=0;
    while(1){
        if(a-1<0){
            break;
        }else{
            a-=1;
            if(all[a][j]==1){
                count+=1;
            }
            if(all[a][j]==0){
                break;
            }
        }
    }
    int a2=i;
    while(1){
        if(a2+1>9){
            break;
        }else{
            a2+=1;
            if(all[a2][j]==1){
                  count+=1;
            }
            if(all[a2][j]==0){
                break;
            }
        }
    }
    if(count>=4){
        return 1;
    }else{
        return 0;
    }
}
int slide1(int i,int j,int all[10][10]){
    int a=i;
    int b=j;
    int count=0;
    while(1){
        if(a-1<0 || b-1<0){
            break;
        }else{
            a-=1;
            b-=1;
            if(all[a][b]==1){
                count+=1;
            }
            if(all[a][b]==0){
                break;
            }
        }
    }
    int a2=i;
    int b2=j;
    while(1){
        if(a2+1>9 || b2+1>9){
            break;
        }else{
            a2+=1;
            b2+=1;
            if(all[a2][b2]==1){
                  count+=1;
            }
            if(all[a2][b2]==0){
                break;
            }
        }
    }
    if(count>=4){
        return 1;
    }else{
        return 0;
    }
}
int slide2(int i,int j,int all[10][10]){
    int a=i;
    int b=j;
    int count=0;
    while(1){
        if(a+1>9 || b-1<0){
            break;
        }else{
            a+=1;
            b-=1;
            if(all[a][b]==1){
                count+=1;
            }
            if(all[a][b]==0){
                break;
            }
        }
    }
    int a2=i;
    int b2=j;
    while(1){
        if(a2-1<0 || b2+1>9){
            break;
        }else{
            a2-=1;
            b2+=1;
            if(all[a2][b2]==1){
                count+=1;
            }
            if(all[a2][b2]==0){
                break;
            }
        }
    }
    if(count>=4){
        return 1;
    }else{
        return 0;
    }
}
