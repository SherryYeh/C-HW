#include<stdio.h>
#include<string.h>

int max = 0;

typedef struct{
    int arr[100];
    int f_len;
    int neg;
}BigDouble;


BigDouble ConvertToBigDouble(char *str){
    BigDouble result;
    int i;
    for(i=0; i<100; i++){
        result.arr[i] = 0;
    }
    result.neg = str[0] == '-' ? 1 : 0;

    int offset = max ;
    for(i=strlen(str)-1; i>(-1+result.neg); i--){
        result.arr[offset++] = str[i] - '0';
    }
    return result;
}
BigDouble Add(BigDouble a,BigDouble b){

    int i;
    BigDouble c=ConvertToBigDouble("0");
    if(a.neg==b.neg){
        c.neg=a.neg;

        for(i=0;i<100;i++)
            c.arr[i]=a.arr[i]+b.arr[i];
        for(i=0;i<100-1;i++){
            if(c.arr[i]>=10){
                c.arr[i+1]+=1;
                c.arr[i]-=10;
            }
        }
    }
    else if (a.neg == 1 && b.neg ==0){

        for(i=100-1;i>-1;i--){// - +
            if(a.arr[i]>b.arr[i]){
                c.neg=1;
                break;
            }else if(a.arr[i]<b.arr[i])
                break;
        }
        for(i=0;i<100;i++){
            if(c.neg==1)// b>a
                c.arr[i]+=a.arr[i]-b.arr[i];
            else
                c.arr[i]+=b.arr[i]-a.arr[i];
            if(c.arr[i]<0){
                c.arr[i+1]-=1;
                c.arr[i]+=10;
            }
        }

    }else if(a.neg==0&&b.neg==1){
        return Add(b, a);
    }

    return c;
}
BigDouble Multi(BigDouble a,BigDouble b){
    int i,j;
    BigDouble c=ConvertToBigDouble("0");
    if(a.neg!=b.neg)
        c.neg=1;
    for(i=0;i<45;i++){
        for(j=0;j<45;j++) {
            c.arr[i+j]+=a.arr[j]*b.arr[i];
            if(c.arr[i+j]>=10){
                c.arr[i+j+1]+=c.arr[i+j]/10;
                c.arr[i+j]=c.arr[i+j]%10;
            }
        }
    }
    c.f_len *= 2;
    return c;
}



BigDouble Minus(BigDouble a,BigDouble b){
    b.neg=b.neg==1?0:1;
    return Add(a,b);
}
void Print(BigDouble num){
    int i;
    if(num.neg == 1) printf("-");
    int integer_start_index;
    for(integer_start_index=99; integer_start_index>-1; integer_start_index--){
        if(num.arr[integer_start_index] != 0) break;

    }
    for(i=integer_start_index; i>=0; i--){
        printf("%d", num.arr[i]);
    }

    printf("\n");
}

int main(){
    char str1[100], str2[100];
    scanf("%s %s", str1, str2);

    BigDouble num1, num2;
    num1 = ConvertToBigDouble(str1);
    num2 = ConvertToBigDouble(str2);
    Print(Add(num1,num2));
    Print(Minus(num1,num2));
    Print(Multi(num1,num2));

}
