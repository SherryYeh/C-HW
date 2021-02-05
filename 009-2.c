#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max_start_index = 0;
int max_length = 0;
int compare(char *str1, char *str2){
    int count = 0;
    while(1){
        if(*str1 == '\0' || *str2 == '\0'){
            break;
        }
        if(*str1 != *str2){
            break;
        }
        str1++;
        str2++;
        count++;
    }
    return count;
}
int main(){
    char str1[255], str2[255];
    scanf("%s", str1);
    scanf("%s", str2);
    int str1_l = strlen(str1);
    int str2_l = strlen(str2);
    int i, j;
    for(i=0; i<str1_l; i++){
        for(j=0; j<str2_l; j++){
            int count = compare(&str1[i], &str2[j]);
            if(count > max_length){
                max_length = count;
                max_start_index = i;
            }
        }

    }
    i=max_start_index;
    while(max_length--){
        printf("%c", str1[i]);
        i++;
    }
    printf("\n");
}
