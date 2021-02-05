#include<stdio.h>
int main(){
    int  i,a,b,c,s,r,length,width,n,one,total=0;
    char kind;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%c",&kind);
        scanf("%c",&kind);
        if(kind=='C'){
            scanf("%d",&r);
            one=4*2*r;
        }
        if(kind=='R'){
            scanf("%d %d",&length,&width);
            one=(length+width)*2;
        }
        if(kind=='S'){
            scanf("%d",&s);
            one=s*4;
        }
        if(kind=='T'){
            scanf("%d %d %d",&a,&b,&c);
            one=a+b+c;
        }
        printf("%d\n",one);
        total+=one;
    }
    printf("%d",total);
}
