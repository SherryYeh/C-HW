#include<stdio.h>


//窮舉所有路徑從(0,0(走到 (n-1,m-1)
/*
input
2 3
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

*/
typedef struct{
    int i, j;
}point;

typedef struct {
    int len;
    point arr[1000];
}Stack;


int n,m;
char map[50][50];
Stack stack;



int go(int i,int j){
    if(i==n-1&&j==m-1){
        Print();
        int k;
        for(k=0; k<stack.len; k++){
            printf("(%d,%d) ", stack.arr[k].i, stack.arr[k].j);
        }
        printf("\n");
        return;
    }
    if(i+1<=n-1){
        if(map[i+1][j] == '0' ){
            stack.arr[stack.len].i = i+1;
            stack.arr[stack.len].j = j;
            stack.len ++;
            map[i+1][j] = '#';
            go(i+1,j);
            stack.len--;
            map[i+1][j] = '0';
        }

    }
    if(i-1>=0){
        if(map[i-1][j] == '0')
        {
            stack.arr[stack.len].i = i-1;
            stack.arr[stack.len].j = j;
            stack.len ++;
            map[i-1][j] = '#';
            go(i-1,j);
            stack.len--;
            map[i-1][j] = '0';
        }

    }
    if(j-1>=0){
        if(map[i][j-1] == '0' ){
            stack.arr[stack.len].i = i;
            stack.arr[stack.len].j = j-1;
            stack.len ++;
            map[i][j-1] = '#';
            go(i,j-1);
            stack.len--;
            map[i][j-1] = '0';
        }
    }
    if(j+1<=m-1){
        if(map[i][j+1] == '0'){
            stack.arr[stack.len].i = i;
            stack.arr[stack.len].j = j+1;
            stack.len ++;
            map[i][j+1] = '#';
            go(i,j+1);
            stack.len--;
            map[i][j+1] = '0';
        }
    }
}
int Print(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            printf("%c ",map[i][j]);
        printf("\n");
    }
}

int main(){
    stack.len = 0;
    int i,j;
    int tmp;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d", &tmp);
            map[i][j] = tmp + '0';
        }
    }
    map[0][0] = '#';
    stack.arr[stack.len].i = 0;
    stack.arr[stack.len].j = 0;
    stack.len++;
    go(0,0);
}
