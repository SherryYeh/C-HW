#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* @param {char*} source ��l����r
* @param {char*} find �j�M����r
* @param {char*} rep ��������r*/
char *str_replace (char *source, char *find,  char *rep){
   int find_L=strlen(find);   // �j�M��r������
   int rep_L=strlen(rep);   // ������r������
   int length=strlen(source)+1;   // ���G��r������
   int gap=0;   // �w�찾���q
   char *result = (char*)malloc(sizeof(char) * length);   // �إߵ��G��r�A�ýƻs��r
   strcpy(result, source);
   char *former=source;   // �|���Q���N���r��
   char *location= strstr(former, find);   // �j�M��r�X�{���_�l��}����
   // ���i�j�M����������r
   while(location!=NULL){
       gap+=(location - former);       // �W�[�w�찾���q
       result[gap]='\0';       // �N�����Ÿ��w�b�j�M�쪺��}�W
       length+=(rep_L-find_L);       // �p��s������
       result = (char*)realloc(result, length * sizeof(char));       // �ܧ�O����Ŷ�
       strcat(result, rep);       // ��������r�걵�b���G�᭱
       gap+=rep_L;       // ��s�w�찾���q
       former=location+find_L;       // ��s�|���Q���N���r�ꪺ��}
       strcat(result, former);       // �N�|���Q���N����r�걵�b���G�᭱
       location= strstr(former, find);       // �j�M��r�X�{���_�l��}����
   }
   return result;
}
int main(){
   char* str1 = "this is a string of characters";
   char* str2 = str_replace(str1, "is","FFF");
   printf( "str1: '%s'\n", str1 );
   printf( "str2: '%s'\n", str2 );
}
