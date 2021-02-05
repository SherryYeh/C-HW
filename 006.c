#include<stdio.h>
#include<string.h>

int max_f_len = 0;//���]str1 = "1.23", str2 = "1.234", �ڭ̦b���ഫ�ɷ|��str1���p�Ʀ�ɻ��A�ܦ�str1 = "1.230"


typedef struct{
    int arr[100];
    int f_len;
    int signbit;
}BigDouble;


//���o�p���I�ᦳ�X��
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

//�N�r���ন�ڭ̩w�q��BigDouble�榡
BigDouble ConvertToBigDouble(char *str){
    //��l��
    BigDouble result;
    int i;
    for(i=0; i<100; i++){
        result.arr[i] = 0;
    }
    result.signbit = str[0] == '-' ? 1 : 0;//�p�Gstr[0] == 0 ��result.signbit = 1 �_�h result.signbit = 0
    result.f_len = max_f_len;//���ެOstr1 �� str2 ���|�Omax_f_len�Ӥp�Ʀ�


    int offset = max_f_len - get_f_len(str);//�p��첾�q
    for(i=strlen(str)-1; i>(-1+result.signbit); i--){//�ݧڵ��A�Ӥ��N���D�o��b�F���F
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

    //���F�h����ƶ}�Y�h�l0�A�ҥH�n�q�}�C�̫᭱���e��A���Ĥ@�Ӥ��O0���a��Y����ƪ��Ӧ�Ʀ�m
    int integer_start_index;
    for(integer_start_index=99; integer_start_index>-1; integer_start_index--){
        if(num.arr[integer_start_index] != 0) break;
    }
    if(integer_start_index < num.f_len) printf("0");//�Y�o�{�ڭ̧䪺��m�w�g�C��p���I���аO�쨺�O�o��Ʀ�ܤ֭n��X�@��0
    for(i=integer_start_index; i>=num.f_len; i--){//�}�l�q�Ӧ�ƿ�X����p���I����
        printf("%d", num.arr[i]);
    }

    int float_end_index;//���F�h���p���I���h�l��0�A�ҥH�n�q�}�C�}�Y�����A�Ĥ@�Ӥ��O0���a��Y���p�ƪ�MSB
    for(float_end_index=0; float_end_index< 100; float_end_index++){
        if(num.arr[float_end_index] != 0) break;
    }
    if(float_end_index < num.f_len){//�Y��쪺��m�O�p��p���I���аO��A��ܦ��B�I��
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
