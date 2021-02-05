#include<stdio.h>
#include<stdlib.h>

typedef struct node_s{
    int data;
    struct node_s *left;
    struct node_s *right;
}node_t;

node_t* insert(node_t *root, int data){
    node_t *current, *newNode;

    newNode = (node_t*)malloc(sizeof(node_t));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root==NULL){
        root = newNode;
        return root;
    }
    current = root;
    while(current!=NULL){
        if(current->data < data){
            if(current->right==NULL){
                current->right = newNode;
                return root;
            }
            else current = current->right;
        }
        else{
            if(current->left==NULL){
                current->left = newNode;
                return root;
            }
            else current = current->left;
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
    node_t *root;
    char commend[3];
    int data=0;

    root = NULL;

    scanf("%s", commend);
    while(commend[0]!='e'){
        if(commend[0]=='i'){
            scanf("%d", &data);
            root = insert(root, data);
        }
        else if(commend[0]=='p'){
            if(root==NULL) printf("null\n");
            else{
                Print(root);
                printf("\n");
            }
        }
        scanf("%s", commend);
    }



    return 0;
}
