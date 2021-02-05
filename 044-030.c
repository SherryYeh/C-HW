#include<stdio.h>
#include<math.h>
void output(float x1,float y1,float x2,float y2,float *m,int m1,int m2,float *b,int b1,int b2);
int main(){
    float x1,y1,x2,y2,m,b;
    int m1,m2,b1,b2;
    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
    if((int)x1==x1&&(int)y1==y1&&(int)x2==x2&&(int)y2==y2){
        m=(y1-y2)/(x1-x2);
        m1=y1-y2;
        m2=x1-x2;
        b=(x2*y1-x1*y2)/(x2-x1);
        b1=x2*y1-x1*y2;
        b2=x2-x1;
        if((m1<0&&m2<0)||(m1>0&&m2<0)){
            m1*=-1;
            m2*=-1;
        }
        if((b1<0&&b2<0)||(b1>0&&b2<0)){
            b1*=-1;
            b2*=-1;
        }
        output(x1,y1,x2,y2,&m,m1,m2,&b,b1,b2);
    }else{
        printf("Error!");
        return;
    }
}
void output(float x1,float y1,float x2,float y2,float *m,int m1,int m2,float *b,int b1,int b2){
    if(x1==x2){
        printf("x=%.0f\n",x1);
        printf("x=%.0f",x1);
    }else{
        if(y1==y2){
            printf("y=%.0f\n",*b);
            printf("y=%.0f",*b);
        }else{
            if((int)*m==*m){
                if((int)*b==*b){
                    if(*m==1){
                        printf("y=x%+.0f\n",*b);
                        printf("y=x%+.0f",*b);
                    }else if(*m==-1){
                        printf("y=-x%+.0f\n",*b);
                        printf("y=-x%+.0f",*b);
                    }else{
                        printf("y=%.0fx%+.0f\n",*m,*b);
                        printf("y=%.0fx%+.0f",*m,*b);
                    }

                }else{
                    printf("y=%.0fx%+.2f\n",*m,*b);
                    printf("y=%.0fx%+d/%d",*m,b1,b2);
                }
            }else{
                if((int)*b==*b){
                    printf("y=%.2fx%+.0f\n",*m,*b);
                    printf("y=%d/%dx%+.0f",m1,m2,*b);
                }else{
                    printf("y=%.2fx%+.2f\n",*m,*b);
                    printf("y=%d/%dx%+d/%d",m1,m2,b1,b2);
                }
            }
        }
    }
}
