#include<stdio.h>
int check(char map[10][10],int i,int j,int off_i,int off_j,char player);
void position(char map[][10], char player);
int main(){
    char map[10][10];
    int i,j;
    char tmp=NULL;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            scanf("%c",&map[i][j]);
            scanf("%c",&tmp);//ÅªªÅ¥Õ
        }
    }
    printf("Player1\n");
    position(map,'0');
    printf("Player2\n");
    position(map,'1');
}
void position(char map[10][10],char player){
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
			if((map[i][j]=='x')&&((check(map,i,j,0,1,player)+check(map,i,j,0,-1,player)>= 4)
                                ||(check(map,i,j,1,0,player)+check(map,i,j,-1,0,player)>=4)
                                 ||(check(map,i,j,1,1,player)+check(map,i,j,-1,-1,player)>= 4)
                                ||((check(map,i,j,-1,1,player)+check(map,i,j,1,-1,player))>=4)))
                printf("%d,%d\n",i,j);
        }
    }
}
int check(char map[10][10],int i,int j,int off_i,int off_j,char player){
    int count=0;
    while(1){
        if((0<=i+off_i<=9)&&(0<=j+off_j<=9)&&(map[i+off_i][j+off_j]==player)){
            count++;
            i+=off_i;
            j+=off_j;
        }else{
            return count;
        }
    }
}

