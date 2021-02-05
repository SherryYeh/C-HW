#include<stdio.h>
int n,m,min=9999999999;
int map[10][10],yes[10][10]={0};
void road(int i,int j,int sum){
    if(sum>min)
        return;
    if(j>=m||i>=n||j<0||i<0){
        return;
    }
    yes[i][j]=1;
    sum+=map[i][j];
    if(i==n-1&&j==m-1){
        min=sum<min?sum:min;
        yes[i][j]=0;
        return;
    }
    if(yes[i][j+1]==0)
        road(i,j+1,sum);
    if(yes[i][j-1]==0)
        road(i,j-1,sum);
    if(yes[i+1][j]==0)
        road(i+1,j,sum);
    if(yes[i-1][j]==0)
        road(i-1,j,sum);
    yes[i][j]=0;
}
int main(){
    int i,j,sum;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&map[i][j]);
        }
    }
    road(0,0,0);
    printf("%d",min);
}
