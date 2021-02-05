#include<stdio.h>
#include<math.h>
void compute(int x1,int y1,int x2,int y2,int *perimeter,int *area);
int main(){
    int x1,y1,x2,y2,bp=0,ba=0;
    while(1){
        scanf("%d",&x1);
        if(x1==-1){
            break;
        }
        scanf("%d %d %d",&y1,&x2,&y2);
        if(x1==x2||y1==y2){
            printf("Error");
            return 0;
        }
        compute(x1,y1,x2,y2,&bp,&ba);
    }
    printf("%d\n%d",ba,bp);
}
void compute(int x1,int y1,int x2,int y2,int *perimeter,int *area){
    int p,a;
    p=(abs(x2-x1)+abs(y2-y1))*2;
    if(p>*perimeter){
        *perimeter=p;
    }
    a=abs((x2-x1)*(y2-y1));
    if(a>*area){
        *area=a;
    }
}
