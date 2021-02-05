#include<stdio.h>
typedef struct node_s{
    int data;
    struct node_s *right;
    struct node_s *left;
}node_t;

node_t* insert(node_t *root,int data){
    node_t *newnode =(node_t *)malloc(sizeof(node_t));
    newnode->right=NULL;
    newnode->left=NULL;
    newnode->data=data;
    if(root==NULL){
        root = newnode;
        return root;
    }
    node_t *current=root;
    while(1){
        if(current==NULL){
            break;
        }
        if(current->data>data){
            if(current->left==NULL){
                current->left=newnode;
                return root;
            }else{
                current=current->left;
            }
        }else{
            if(current->right==NULL){
                current->right=newnode;
                return root;
            }else{
                current=current->right;
            }
        }
    }
}

void Print(node_t *current){
    if(current->left != NULL){
        Print(current->left);
    }
    printf("%d ", current->data);
    if(current->right != NULL){
        Print(current->right);
    }
}

int main(){
    node_t *root= NULL;
    char input[3];
    int data=0;
    scanf("%s",input);
    while(1){
        if(input[0]=='e')
            break;
        else if(input[0]=='i'){
            scanf("%d", &data);
            root = insert(root, data);
        }
        else if(input[0]=='p'){
            if(root==NULL)
                printf("null\n");
            else{
                Print(root);
                printf("\n");
            }
        }
        scanf("%s", input);
    }
}
