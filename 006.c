#include<stdio.h>
#include<string.h>

int max_f_len = 0;//假設str1 = "1.23", str2 = "1.234", 我們在做轉換時會把str1的小數位補齊，變成str1 = "1.230"


typedef struct{
    int arr[100];
    int f_len;
    int signbit;
}BigDouble;


//取得小數點後有幾位
int get_f_len(char*str){
    int count = 0, i = 0;
    for(i=strlen(str)-1; i>-1; i--){

        if(str[i] == '.'){
            return count;
        }
        count ++;
    }
    return 0;
}

//將字串轉成我們定義的BigDouble格式
BigDouble ConvertToBigDouble(char *str){
    //初始化
    BigDouble result;
    int i;
    for(i=0; i<100; i++){
        result.arr[i] = 0;
    }
    result.signbit = str[0] == '-' ? 1 : 0;//如果str[0] == 0 那result.signbit = 1 否則 result.signbit = 0
    result.f_len = max_f_len;//不管是str1 或 str2 都會是max_f_len個小數位


    int offset = max_f_len - get_f_len(str);//計算位移量
    for(i=strlen(str)-1; i>(-1+result.signbit); i--){//看我給你照片就知道這邊在幹嘛了
        if(str[i] == '.') continue;
        result.arr[offset++] = str[i] - '0';
    }
    return result;
}
BigDouble Add(BigDouble a,BigDouble b){
    int i;
    BigDouble c=ConvertToBigDouble("0");
    if(a.signbit==b.signbit){
        c.signbit=a.signbit;

        for(i=0;i<100;i++)
            c.arr[i]=a.arr[i]+b.arr[i];
        for(i=0;i<100-1;i++){
            if(c.arr[i]>=10){
                c.arr[i+1]+=1;
                c.arr[i]-=10;
            }
        }
    }
    else if (a.signbit == 1 && b.signbit ==0){

        for(i=100-1;i>-1;i--){// - +
            if(a.arr[i]>b.arr[i]){
                c.signbit=1;
                break;
            }else if(a.arr[i]<b.arr[i])
                break;
        }
        for(i=0;i<100;i++){
            if(c.signbit==1)// b>a
                c.arr[i]+=a.arr[i]-b.arr[i];
            else
                c.arr[i]+=b.arr[i]-a.arr[i];
            if(c.arr[i]<0){
                c.arr[i+1]-=1;
                c.arr[i]+=10;
            }
        }

    }else if(a.signbit==0&&b.signbit==1){
        /*
        for(i=100-1;i>-1;i--){// + -
            if(a.arr[i]<b.arr[i]){
                c.signbit=1;
                break;
            }else if(a.arr[i]>b.arr[i])
                break;

        }
        for(i=0;i<100;i++){
            if(c.signbit==1)// b>a
                c.arr[i]+=b.arr[i]-a.arr[i];
            else
                c.arr[i]+=a.arr[i]-b.arr[i];
            if(c.arr[i]<0){
                c.arr[i+1]-=1;
                c.arr[i]+=10;
            }
        }*/
        return Add(b, a);

    }
    return c;
}
BigDouble Multi(BigDouble a,BigDouble b){
    int i,j;
    BigDouble c=ConvertToBigDouble("0");
    if(a.signbit!=b.signbit)
        c.signbit=1;
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
    b.signbit=b.signbit==1?0:1;
    return Add(a,b);
}
void Print(BigDouble num){
    int i;
    if(num.signbit == 1) printf("-");

    //為了去掉整數開頭多餘0，所以要從陣列最後面往前找，找到第一個不是0的地方即為整數的個位數位置
    int integer_start_index;
    for(integer_start_index=99; integer_start_index>-1; integer_start_index--){
        if(num.arr[integer_start_index] != 0) break;
    }
    if(integer_start_index < num.f_len) printf("0");//若發現我們找的位置已經低於小數點的標記位那記得整數位至少要輸出一個0
    for(i=integer_start_index; i>=num.f_len; i--){//開始從個位數輸出直到小數點那位
        printf("%d", num.arr[i]);
    }

    int float_end_index;//為了去掉小數點後方多餘的0，所以要從陣列開頭往後找，第一個不是0的地方即為小數的MSB
    for(float_end_index=0; float_end_index< 100; float_end_index++){
        if(num.arr[float_end_index] != 0) break;
    }
    if(float_end_index < num.f_len){//若找到的位置是小於小數點的標記位，表示有浮點數
        printf(".");
        for(i=num.f_len-1; i>=float_end_index; i--){
            printf("%d", num.arr[i]);
        }
    }
    printf("\n");
}

int main(){
    char str1[100], str2[100];
    scanf("%s %s", str1, str2);

    int str1_f_len = get_f_len(str1);
    int str2_f_len = get_f_len(str2);
    max_f_len = str1_f_len > str2_f_len ? str1_f_len : str2_f_len;
    BigDouble num1, num2;
    num1 = ConvertToBigDouble(str1);
    num2 = ConvertToBigDouble(str2);
    Print(Add(num1,num2));
    Print(Minus(num1,num2));
    Print(Multi(num1,num2));

}
