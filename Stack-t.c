#include<stdio.h>
#include<string.h>
typedef struct node{
    int data;
    struct node *next;
}node_t;
typedef node_t *nodep_t;
typedef struct{
    node_t pop;
}stack_t;
void create(node_t root,int data){
    node_t *newnode;
    newnode->next=NULL;
    newnode->data=data;
    //root->newnode;
}
int push(node_t root,int data){
    node_t *newnode;
    data=newnode->data;
    newnode->data=NULL;
    //root->newnode;
    return data;
}
int pop(node_t *root,int data){
    if(root->data==NULL)
        printf("The Stack is empty");
    else{
        while(root->data==NULL){
            printf("The data %d is pop",root->data);
            root=root->next;
        }
    }
}
int main(){
    int i=0,j=0,mode,num,data[20];
    while(1){
        scanf("%d",&mode);
        if(mode==1){
            i++;
            scanf("%d",&data[i]);
        }else if(mode==2){
            if(i<=0){
                printf("The Stack is empty\n");
                //i=0;
            }else {
                printf("The data %d is pop\n",data[i]);
            }
            i--;
            if(i<=0)
                i=0;
        }else if(mode==3){
            break;
        }
    }
}
