#include<stdio.h>
typedef struct node_s{
    int data;
    struct node_s *right;
    struct node_s *left;
}node_t;

typedef struct tree_s{
    node_t *root;
}tree_t;

node_t *make(int data){
    node_t *newnode =(node_t *)malloc(sizeof(node_t));
    newnode->right=NULL;
    newnode->left=NULL;
    newnode->data=data;
    return newnode;
}

int insert(tree_t *tree,int data){
    node_t *current=tree->root;
    while(1){
        if(current==NULL){
            tree->root=make(data);
            break;
        }
        if(current->data>data){
            if(current->left==NULL){
                current->left=make(data);
                break;
            }else{
                current=current->left;
            }
        }else{
            if(current->right==NULL){
                current->right=make(data);
                break;
            }else{
                current=current->right;
            }
        }
    }
}

int main(){
    tree_t tree;
    tree.root=NULL;
    insert(&tree,5);
    insert(&tree,3);
    insert(&tree,8);
    insert(&tree,6);
    printf("%d",tree.root->right->left->data);
}
