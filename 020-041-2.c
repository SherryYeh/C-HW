#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 100 /*�w�q�̤j���|�e�q*/
#include<string.h>
int stack[MAXSTACK];  //���|���}�C�ŧi
int top=-1;		//���|������
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
/*�N���w����Ʀs�J���|*/
void push(int data){
	if(top>=MAXSTACK){
		printf("���|�w��,�L�k�A�[�J\n");
	}else{
		top++;
		stack[top]=data;
	}
}
/*�q���|���X���*/
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
