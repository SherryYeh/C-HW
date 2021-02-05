#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void start(char tree[],char tree2[],int len,int level,char t[][100],int c){
    int i;
    char tree1L[99]={0},tree1R[99]={0},tree2L[99]={0},tree2rootright[99]={0};
    for(i=0;i<len;i++)
        if(tree[0]==tree2[i])
            break;
    if(i==len)
        return;
    strncpy(tree1L,tree+1,i);
    strcpy(tree1R,tree+i+1);
    strncpy(tree2L,tree2,i);
    strcpy(tree2rootright,tree2+i+1);
    if(tree[0]==0)
        level--;
    else
        t[level][c+i]=tree[0];
    start(tree1R,tree2rootright,strlen(tree+i),level+1,t,c+i);
    start(tree1L,tree2L,i,level+1,t,c);
}
void end(char tree[],char tree2[],int len,int level,char t[][100],int c){
    int i;
    char tree1L[99]={0},tree1R[99]={0},tree2L[99]={0},tree2rootright[99]={0};
    for(i=0;i<len;i++)
        if(tree[len-1]==tree2[i])
            break;
    if(i==len)
        return;
    strncpy(tree1L,tree,i);
    strncpy(tree1R,tree+i,len-i-1);
    strncpy(tree2L,tree2,i);
    strcpy(tree2rootright,tree2+i+1);
    if(tree[len-1]==0)
        level--;
    else
        t[level][c+i]=tree[len-1];
    end(tree1R,tree2rootright,strlen(tree+i),level+1,t,c+i);
    end(tree1L,tree2L,i,level+1,t,c);
}
int main(){
    int i,j;
    char choose1,choose2;
    char tree[100],tree2[100],t[10][100];
    for(i=0;i<10;i++)
        for(j=0;j<100;j++)
            t[i][j]=0;
    scanf("%c%*c",&choose1);
    scanf("%s%*c",tree);
    scanf("%c%*c",&choose2);
    scanf("%s%*c",tree2);
    if(choose1=='P'&&choose2=='I')
        start(tree,tree2,strlen(tree),0,t,0);
    if(choose1=='I'&&choose2=='P')
        start(tree2,tree,strlen(tree),0,t,0);
    if(choose1=='O'&&choose2=='I')
        end(tree,tree2,strlen(tree),0,t,0);
    if(choose1=='I'&&choose2=='O')
        end(tree2,tree,strlen(tree),0,t,0);
    for(i=0;i<10;i++)
        for(j=0;j<100;j++)
            if(t[i][j]!=0)
                printf("%c",t[i][j]);
}
