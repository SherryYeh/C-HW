#include<stdio.h>
int compute(int map[10000],int n){
    int line=0,i,j,x;
    for(i=0;i<n*n;i+=n){
        x=1;
        for(j=i+1;j<i+n;j++)
            if(map[i]==map[j])
                x++;
        if(x==n)
            line++;
    }
    for(i=0;i<n;i++){
        x=1;
        for(j=i+n;j<n*n;j+=n)
            if(map[i]==map[j])
                x++;
        if(x==n)
            line++;
    }
    for(i=0;i<1;i++){
        x=1;
        for(j=i+n+1;j<n*n;j+=n+1)
            if(map[i]==map[j])
                x++;
        if(x==n)
            line++;
    }
    for(i=n-1;i<n;i++){
        x=1;
        for(j=i+n-1;j<n*n-1;j+=n-1)
            if(map[i]==map[j])
                x++;
        if(x==n)
            line++;
    }
    return line;
}
int main(){
    int i,j,n,m=0,line1,line2;
    char w;
    int p1[10000],p2[10000],ans[10000];
    scanf("%d",&n);
    for(i=0;i<n*n;i++)
        scanf("%d",&p1[i]);
    for(i=0;i<n*n;i++)
        scanf("%d",&p2[i]);
    while(1){
        scanf("%d%c",&ans[m],&w);
        m++;
        if(w=='\n')
            break;
    }
    for(i=0;i<m;i++){
        for(j=0;j<n*n;j++){
            if(ans[i]==p1[j])
                p1[j]=-1;
            if(ans[i]==p2[j])
                p2[j]=-1;
        }
    }
    line1=compute(p1,n);
    line2=compute(p2,n);
    if(line1>line2){
        printf("Player1 wins %d, Player2 loses %d",line1,line2);
    }else if(line1<line2){
        printf("Player2 wins %d, Player1 loses %d",line2,line1);
    }else{
        printf("Draw %d",line1);
    }
}
