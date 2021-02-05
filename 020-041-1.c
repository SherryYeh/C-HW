#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
int main() {
    char arr1[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char arr2[20];
    char str[100];
    int a,b,i=0,l,j=0;
    char m,h;
    scanf("%d %s",&a,&str);
    l=strlen(str);
    int num=atoi(str);
    if(2<=a&&a<=16&&0<=num&&num<=1000000000){
        while(num>0){
            b=num%a;
            arr2[i]=arr1[b];
            i+=1;
            num=num/a;
            if(num<a){
                arr2[i]=arr1[num];
                break;
            }
        }
        for(j=i;j>=0;j--){
            printf("%c",arr2[j]);
        }
    }else{
        printf("E");
    }
}
