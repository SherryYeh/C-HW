char *Strrep(char *s1,char *s2,int pos){//字符串的取代
     int i,j;
     pos--;//计算取代的起始位置，减1使其成为索引值（从0计数）
     i=0;
     for(j=pos;s1[j]!='/0';j++){//从取代的起始位置开始
        if (s2[i]!='/0'){
            s1[j]=s2[i];//进行取代
            i++;
        }else
            break;
  
    }
    return s1;
}

char *Strins(char *s1,char *s2,int pos){//字符串的插入
     int s1_length,s2_length;
     int i,j;
     pos--;
     s1_length=strlen(s1);
     s2_length=strlen(s2);
     for(i=s1_length;i>=pos;i--)//将插入位置之后的所有字符往后移，以空出s2所需的字符长度
        s1[i+s2_length]=s1[i];
     for(j=pos;s2[j-pos]!='/0';j++)//将字符串s2的内容填入所空出的字符串s1中
        s1[j]=s2[j-pos];  
    return s1;
}

char *Strdel(char *s,int pos,int len){//字符串的删除
     int i;
     pos--;
     for(i=pos+len;s[i]!='/0';i++)//从pos开始删除字符串
         s[i-len]=s[i];
     s[i-len]='/0';
     return s;
}
