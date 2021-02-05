#include<stdio.h>
int n;
char map[50][50];
int bol = 0;

int go(int i,int j){
    map[i][j] = '#';
    if(i==n-2&&j==n-2){
        bol = 1;
        Print();
        return;
    }
    if(i+1<=n-1){
        if(map[i+1][j] == '0' && bol==0){
            go(i+1,j);
        }

    }
    if(i-1>=0){
        if(map[i-1][j] == '0' && bol==0){
            go(i-1,j);
        }

    }
    if(j-1>=0){
        if(map[i][j-1] == '0' && bol==0){
            go(i,j-1);
        }
    }
    if(j+1<=n-1){
        if(map[i][j+1] == '0' && bol==0){
            go(i,j+1);
        }

    }
    map[i][j] = '*';
}
int Print(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%c ",map[i][j]);
        printf("\n");
    }
}

int main(){
    int i,j;
    int tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &tmp);
            map[i][j] = tmp + '0';
        }
    }
    go(1,1);
}
