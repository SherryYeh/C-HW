#include<stdio.h>
#include<string.h>
#include<math.h>
typedef struct circle{
    float r;
}Circle;
typedef struct rectangle{
    float a,b;
}Rectangle;
typedef struct square{
    float n;
}Square;
typedef struct triangle{
    float a,b,c;
}Triangle;
typedef struct shape{
    Circle circle;
    Rectangle rectangle;
    Square square;
    Triangle triangle;
    char name[500];
    int select;
}Shape;

Shape arr[500];
int count = 0;
void Print(Shape a){

    if(a.select == 1){
        printf("%.2f,%.2f\n",a.circle.r*2*3.14,a.circle.r*a.circle.r*3.14);
    }else if(a.select == 2){
        printf("%.2f,%.2f\n",2*(a.rectangle.a+a.rectangle.b),a.rectangle.a*a.rectangle.b);
    }else if(a.select == 3){
        printf("%.2f,%.2f\n",a.square.n*4,a.square.n*a.square.n);
    }else if(a.select == 4){
        float s=(a.triangle.a + a.triangle.b + a.triangle.c)/2.0;
        printf("%.2f,%.2f\n",a.triangle.a+a.triangle.b+a.triangle.c,sqrt(s *(s-a.triangle.a)*(s-a.triangle.b)*(s-a.triangle.c)));
    }
}
void sort(){
    int i,j;
    for(i=0;i<count-1;i++){
        for(j=i+1;j<count;j++){
            if(strcmp(arr[i].name,arr[j].name)>0){
                Shape tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
int isstar(char a[500]){
    int i;
    for(i=0;i<strlen(a);i++){
        if(a[i]=='*')
            return i;
    }
    return -1;
}
int main(){
    char choose[500];
    char tmp[500];
    while(1){
        scanf("%s",&tmp);
        if(strcmp(tmp,"exit")==0)
            break;
        else if(strcmp(tmp,"touch")==0 || strcmp(tmp,"cat")==0){
            strcpy(choose,tmp);
            continue;
        }
        if(strcmp(choose,"touch")==0){
            if(strcmp(tmp,"C")==0){
                arr[count].select=1;
                scanf(" %[^(](%f)",&arr[count].name,&arr[count].circle.r);
            }
            else if(strcmp(tmp,"R")==0){
                arr[count].select=2;
                scanf(" %[^(](%f,%f)",&arr[count].name,&arr[count].rectangle.a,&arr[count].rectangle.b);
            }
            else if(strcmp(tmp,"S")==0){
                arr[count].select=3;
                scanf(" %[^(](%f)",&arr[count].name,&arr[count].square.n);
            }
            else if(strcmp(tmp,"T")==0){
                arr[count].select=4;
                scanf(" %[^(](%f,%f,%f)",&arr[count].name,&arr[count].triangle.a,&arr[count].triangle.b,&arr[count].triangle.c);
            }
            count++;
        }
        else if(strcmp(choose,"cat")==0){
            sort();
            if(strcmp(tmp,"*")==0){
                int i;
                for(i=0;i<count;i++)
                    Print(arr[i]);
            }else if(tmp[0] == '*'){// *file
                int i;
                for(i=0; i<count; i++){
                    if(strlen(arr[i].name) >= strlen(tmp)){
                        char *tmp1 = &tmp[1];
                        if(strcmp(&arr[i].name[strlen(arr[i].name) - strlen(tmp1)], tmp1) == 0){
                            Print(arr[i]);
                        }
                    }
                }
            }else if(tmp[strlen(tmp)-1]=='*'){//file*
                int i;
                for(i=0;i<count;i++){
                    if(strlen(arr[i].name) >= strlen(tmp)){
                        if(strncmp(arr[i].name, tmp, strlen(tmp)-1)==0){
                            Print(arr[i]);
                        }
                    }
                }
            }else if(isstar(tmp)!=-1){
                int index=isstar(tmp);
                int i;
                for(i=0;i<count;i++){
                    if(strlen(arr[i].name) >= strlen(tmp)){

                        if(strncmp(arr[i].name,tmp, index) == 0){//file*
                            char *tmp1 = &tmp[index+1];
                            if(strcmp(&arr[i].name[strlen(arr[i].name) - strlen(tmp1)], tmp1) == 0){
                                Print(arr[i]);
                            }
                        }
                    }
                }
            }else{
                int i;
                for(i=0;i<count;i++){
                    if(strcmp(tmp,arr[i].name)==0)
                        Print(arr[i]);
                }
            }
        }
    }
}
