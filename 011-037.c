#include<stdio.h>
int main(){
    int x1,x2,x3,x4,y1,y2,y3,y4,z1,z2,z3,z4;
    scanf("%d %d",&x1,&x2);
    if(x2==2){
        scanf("%d %d",&x3,&x4);
    }else{
        scanf("%d",&x3);
        x4=1;
    }
    scanf("%d %d",&y1,&y2);
    if(y2==1){
        scanf("%d",&y3);
        y4=1;
    }else{
        scanf("%d %d",&y3,&y4);
    }
    scanf("%d %d",&z1,&z2);
    if(z2==1){
        scanf("%d",&z3);
        z4=1;
    }else{
        scanf("%d %d",&z3,&z4);
    }
    if((x1<1000)||(y1<1000)||(z1<1000)){
        printf("-1");
    }else{
        if((x2>2)||(y2>2)||(z2>2)){
            printf("-1");
        }else{
            if((x3>59)||(x4>59)||(y3>59)||(y4>59)||(z3>59)||(z4>59)){
                printf("-1");
            }else{
                if(x3==y3||x3==y4)
                    printf("%d,%d,%d\n",x1,y1,x3);
                if(x4==y3||x4==y4)
                    printf("%d,%d,%d\n",x1,y1,x4);
                if(z3==x3||z3==x4)
                    printf("%d,%d,%d\n",x1,z1,z3);
                if(z4==x3||z4==x4)
                    printf("%d,%d,%d\n",x1,z1,z4);
                if(y3==z3||y3==z4)
                    printf("%d,%d,%d\n",y1,z1,y3);
                if(y4==z3||y4==z4)
                    printf("%d,%d,%d\n",y1,z1,y4);
                else{
                    printf("correct");
                    }
                }
            }
        }
    return 0;
}
