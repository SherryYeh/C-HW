#include<stdio.h>
typedef struct{
    int use[50],a;
}stack;

int room,all[10][3],time=0,max=0;
int same(stack c,int p){
    int i;
    for(i=0;i<c.a;i++){
        if(c.use[i]==p){
            return 1;
        }
    }
    return 0;
}

int arrange(int n,int b,stack c){
    int j;
    if(c.a==b){
        compute(c);
        return;
    }
    int i;
    for(i=1; i<=n; i++){
        if(same(c,i)==0){
        c.use[c.a++] = i;
        arrange(n, b, c);
        c.a--;
        }
    }
}
void compute(stack c){
    int result[50]={0},i,j,t=0;
    for(i=0;i<c.a;i++){
        int index=c.use[i]-1;
        for(j=all[index][1];j<all[index][2];j++){
            result[j]++;
            t++;
        }
    }
    int bol=1;
    for(i=0;i<25;i++){
        if(room<result[i]){
            bol=0;
        }
    }
    if(bol==1){
        if(max<c.a)
            max=c.a;
        if(time<t)
            time=t;
    }

}
int main(){
    int n,i;
    scanf("%d %d",&room,&n);
    for(i=0;i<n;i++)
        scanf("%d %d %d",&all[i][0],&all[i][1],&all[i][2]);
    stack arr;
    arr.a=0;
    for(i=1;i<=n;i++)
        arrange(n,i,arr);

    printf("%d\n%d",time,max);
}
