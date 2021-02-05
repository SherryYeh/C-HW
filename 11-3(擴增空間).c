#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* @param {char*} source 原始的文字
* @param {char*} find 搜尋的文字
* @param {char*} rep 替換的文字*/
char *str_replace (char *source, char *find,  char *rep){
   int find_L=strlen(find);   // 搜尋文字的長度
   int rep_L=strlen(rep);   // 替換文字的長度
   int length=strlen(source)+1;   // 結果文字的長度
   int gap=0;   // 定位偏移量
   char *result = (char*)malloc(sizeof(char) * length);   // 建立結果文字，並複製文字
   strcpy(result, source);
   char *former=source;   // 尚未被取代的字串
   char *location= strstr(former, find);   // 搜尋文字出現的起始位址指標
   // 漸進搜尋欲替換的文字
   while(location!=NULL){
       gap+=(location - former);       // 增加定位偏移量
       result[gap]='\0';       // 將結束符號定在搜尋到的位址上
       length+=(rep_L-find_L);       // 計算新的長度
       result = (char*)realloc(result, length * sizeof(char));       // 變更記憶體空間
       strcat(result, rep);       // 替換的文字串接在結果後面
       gap+=rep_L;       // 更新定位偏移量
       former=location+find_L;       // 更新尚未被取代的字串的位址
       strcat(result, former);       // 將尚未被取代的文字串接在結果後面
       location= strstr(former, find);       // 搜尋文字出現的起始位址指標
   }
   return result;
}
int main(){
   char* str1 = "this is a string of characters";
   char* str2 = str_replace(str1, "is","FFF");
   printf( "str1: '%s'\n", str1 );
   printf( "str2: '%s'\n", str2 );
}
