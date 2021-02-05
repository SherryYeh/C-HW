#include<stdio.h>
struct C{
  int f;
};
struct S{
  int d;
};
struct R{
  int a;
  int b;
};
struct T{
  int w1;
  int w2;
  int w3;
};
struct shape{
	struct C c;
	struct S s;
  struct R r;
	struct T t;
};
int main(){
  	int n,i,all=0;
    char sh;
    scanf("%d%*c",&n);
    struct shape total[n];
    for(i=0;i<n;i++){
      scanf("%c",&sh);
      if(sh=='C'){
        scanf("%d",&total[i].c.f);
        all += (total[i].c.f)*2*4;
        printf("%d\n",(total[i].c.f)*2*4);
      }
      if(sh=='S'){
        scanf("%d",&total[i].s.d);
        all+=(total[i].s.d)*4;
        printf("%d\n",(total[i].s.d)*4);
      }
      if(sh=='R'){
        scanf("%d %d",&total[i].r.a,&total[i].r.b);
        all+=(total[i].r.a+total[i].r.b)*2;
        printf("%d\n",(total[i].r.a+total[i].r.b)*2);
      }
      if(sh=='T'){
        scanf("%d %d %d",&total[i].t.w1,&total[i].t.w2,&total[i].t.w3);
        all+=(total[i].t.w1+total[i].t.w2+total[i].t.w3);
        printf("%d\n",(total[i].t.w1+total[i].t.w2+total[i].t.w3));
      }
    scanf("%*c");  
    }
    printf("%d",all);
    return 0;
}
