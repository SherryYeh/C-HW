#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 100 /*定義最大堆疊容量*/
#include<string.h>
int stack[MAXSTACK];  //堆疊的陣列宣告
int top=-1;		//堆疊的頂端
int isEmpty();
void push(int);
int pop();
int main() {
    char str[100];
    int a,b,i=0,l;
    scanf("%d %s",&a,&str);
    l=strlen(str);
    int num=atoi(str);
    if(2<=a&&a<=16&&0<=num&&num<=1000000000){
        while(num>0){
            b=num%a;
            push(b);
            //printf("b=%d",b);
            num=num/a;
            if(num<a){
                printf("%d",num);
                break;
            }
        }
        while(isEmpty()==0){
            printf("%c",pop());
        }
        pop();
        return 0;
    }else{
        printf("E");
    }
}
int isEmpty(){
	if(top==-1){
		return 1;
	}else{
		return 0;
	}
}
/*將指定的資料存入堆疊*/
void push(int data){
	if(top>=MAXSTACK){
		printf("堆疊已滿,無法再加入\n");
	}else{
		top++;
		stack[top]=data;
	}
}
/*從堆疊取出資料*/
int pop(){
	int data;

	char z;
	int y[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	if(isEmpty()==0){
		data=stack[top];
		top--;
		//printf("W:%d",data);
        z=y[data];
		return z;
	}
}
