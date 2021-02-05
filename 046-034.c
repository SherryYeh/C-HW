#include<stdio.h>
void compute(int all[9][9]);
int judge(int one[9]);
int main(){
    int all[9][9];
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            scanf("%d",&all[i][j]);
        }
    }
    int w;
    for(w=0;w<9;w++){
        if(judge(all[w])==0){
            printf("No");
            return 0;
        }
    }
    int k,h;
    for(k=0;k<9;k++){
        int down[9];
        for(h=0;h<9;h++){
            down[h]=(all[h][k]);
        }
        if(judge(down)==0){
            printf("No");
            return 0;
        }
    }
    compute(all);
}
void compute(int all[9][9]){
    int i=0;
    int c=0;
    int b,j,k;
    for(b=0;b<9;b++){
        int part[9];
        int a;
        a=i*3;
        int w=0;
        for(j=a;j<a+3;j++){
            for(k=c;k<c+3;k++){
                part[w]=all[j][k];
                w+=1;
            }
        }
        if(judge(part)==1){
            c+=3;
            if(k==9){
                i+=1;
                c=0;
            }
        }else{
            printf("No");
            return;
        }
    }
    printf("Yes");
}
int judge(int one[9]){
    int i,j;
    for(i=0;i<8;i++){
        for(j=i+1;j<9;j++){
            if(one[i]==one[j]){
                return 0;
            }
        }
    }
    return 1;
}
