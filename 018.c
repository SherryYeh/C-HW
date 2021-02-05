#include<stdio.h>
#include<math.h>
void decimal_to_binary(int n,int length,char *binary){
    int i=0,j;
    for(i=0;i<length;i++){
        binary[length-i-1]=(n%2)+'0';
        n=n/2;

    }
    binary[length]='\0';

}
int binary_to_decimal(const char* binary,int length){
    int sum=0,i;
    for(i=0;i<length;i++){
        if(binary[i]=='1')
            sum+=pow(2,length-i-1);
    }
    return sum;
}
int loopCircuit(int n){
    int m=0;
    while(1){
        if(n==0||n==1)
            break;
        else if(n%2==0){
            n=n/2;
        }
        else{
            n=(n+1)/2;
        }
        m++;
    }
    return m;
}
int main(){
    int n,length,middle,i,result=0;
    char binary[50],input[50];
    while(1){
        scanf("%s %d",&input,&middle);

        int temp=binary_to_decimal(input,8);
        result=0;
        for(i=0;i<=temp;i++){
            result+=loopCircuit(i);
        }
        decimal_to_binary(result,11,binary);
        printf("%s\n",binary);
        if(middle==-1)
            break;
    }



}
