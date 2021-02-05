#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void pre(char tree[],char tree2[],int len,int level,char t[][100],int c)
{

    int i;
    char tree1rootleft[99]={0},tree1rootright[99]={0},tree2rootleft[99]={0},tree2rootright[99]={0};
    for(i=0;i<len;i++) if(tree[0]==tree2[i]) break;
    if(i==len) return;
    strncpy(tree1rootleft,tree+1,i);
    strcpy(tree1rootright,tree+i+1);
    strncpy(tree2rootleft,tree2,i);
    strcpy(tree2rootright,tree2+i+1);
    //printf("%s\n",tree1rootleft);
    // printf("%c",tree[0]);
    //printf("%s\n",tree2);
    if(tree[0]==0) level--;
    if(tree[0]!=0) t[level][c+i]=tree[0];
    pre(tree1rootright,tree2rootright,strlen(tree+i),level+1,t,c+i);
    pre(tree1rootleft,tree2rootleft,i,level+1,t,c);
}
void post(char tree[],char tree2[],int len,int level,char t[][100],int c)
{

    int i;
    char tree1rootleft[99]={0},tree1rootright[99]={0},tree2rootleft[99]={0},tree2rootright[99]={0};
    for(i=0;i<len;i++) if(tree[len-1]==tree2[i]) break;
    if(i==len) return;
    strncpy(tree1rootleft,tree,i);
    strncpy(tree1rootright,tree+i,len-i-1);
    strncpy(tree2rootleft,tree2,i);
    strcpy(tree2rootright,tree2+i+1);
    //printf("%s\n",tree);
    //if(tree[len-1]!=0) printf("%c",tree[len-1]);
    if(tree[len-1]==0) level--;
    if(tree[len-1]!=0) t[level][c+i]=tree[len-1];
    post(tree1rootright,tree2rootright,strlen(tree+i),level+1,t,c+i);
    post(tree1rootleft,tree2rootleft,i,level+1,t,c);
}
int main()
{
    int i,j;
    char order1,order2;
    char tree[100],tree2[100],t[10][100];
    for(i=0;i<10;i++)for(j=0;j<100;j++) t[i][j]=0;
    scanf("%c%*c",&order1);
    scanf("%s%*c",tree);
    scanf("%c%*c",&order2);
    scanf("%s%*c",tree2);
    if(order1=='P'&&order2=='I') pre(tree,tree2,strlen(tree),0,t,0);
    if(order1=='I'&&order2=='P') pre(tree2,tree,strlen(tree),0,t,0);
    if(order1=='O'&&order2=='I') post(tree,tree2,strlen(tree),0,t,0);
    if(order1=='I'&&order2=='O') post(tree2,tree,strlen(tree),0,t,0);
    for(i=0;i<10;i++)for(j=0;j<100;j++) if(t[i][j]!=0)    printf("%c%d\n",t[i][j],j);
}
