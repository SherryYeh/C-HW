#include<stdio.h>
#include<string.h>
typedef struct node{
    int id;
    int score;
    struct node *next;
}one;
one *make(int id,int score){
    one *newnode=(one *)malloc(sizeof(one));
    newnode->next=NULL;
    newnode->id=id;
    newnode->score=score;
    return newnode;
}
void swap(one **a,one **b){
    one *tmp=make((*a)->id,(*a)->score);
    (*a)->id=(*b)->id;
    (*a)->score=(*b)->score;
    (*b)->id=tmp->id;
    (*b)->score=tmp->score;
}
void sort(one **root){
    one *i, *j;
    for(i=*root; i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->score-j->score<0)
                swap(&i,&j);
        }
    }


}
void print(one **root){
    one *current=*root;
    while(current!=NULL){
        printf("%d %d\n",current->id,current->score);
        current=current->next;
    }
    printf("\n");
}
int main(){
    int score,id;
    int x1,x2,x3,x4,x5,x6,x7,x8;
    one *root=NULL;
    scanf("%d %d %d %d",&x1,&x2,&x3,&x4);
    one *newnode=make(x1,x2);
    if(root==NULL){
        root=newnode;
    }else{
        newnode->next=root;
        root=newnode;
    }
    one *newnode2=make(x3,x4);
    if(root==NULL){
        root=newnode2;
    }else{
        newnode2->next=root;
        root=newnode2;
    }
    print(&root);

    scanf("%d %d %d %d",&x5,&x6,&x7,&x8);
    one *newnode3=make(x5,x6);
    if(root==NULL){
        root=newnode3;
    }else{
        newnode3->next=root;
        root=newnode3;
    }
    one *newnode4=make(x7,x8);
    if(root==NULL){
        root=newnode4;
    }else{
        newnode4->next=root;
        root=newnode4;
    }
    sort(&root);
    print(&root);
}
