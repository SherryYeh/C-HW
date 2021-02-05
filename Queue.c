#include<stdio.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct queue
{
    node *start;
    node *end;
    char name[500];
    int len;
    struct queue *next;
} queue;
queue *root=NULL;
int yes(char name[500]){
    queue *current=root;
    while(current!=NULL)
    {
        if(strcmp(current->name,name)==0)
            return 1;
        current=current->next;
    }
    return 0;
}
void add(char name[500]){
    queue *newqueue = (queue *)malloc(sizeof(queue));
    newqueue->len=0;
    strcpy(newqueue->name,name);
    newqueue->start=NULL;
    newqueue->end=NULL;
    newqueue->next=NULL;// root->q1->q2->q3->NULL
    if(root==NULL)
    {
        root=newqueue;
    }
    else
    {
        queue *current = root;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=newqueue;
    }
}
void enqueue(char name[500],int data){
    if(yes(name))
    {
        node *in=(node *)malloc(sizeof(node));
        in->data=data;
        in->next=NULL;
        queue *current=root;
        while(current!=NULL)
        {
            if(strcmp(current->name,name)==0)
                break;
            current=current->next;
        }
        if(current->start==NULL) // is empty
        {
            current->end=in;
            current->start=in;
        }
        else  //not empty
        {
            current->end->next=in;
            current->end=in;
        }
        current->len++;
    }
    else
        printf("Queue %s isn't exist\n",name);
}
void dequeue(char name[500]){
    if(yes(name))
    {
        queue *current=root;
        while(current!=NULL)
        {
            if(strcmp(current->name,name)==0)
                break;
            current=current->next;
        }
        if(current->len==0)
            printf("Queue is empty\n");
        else
        {
            current->start=current->start->next;
            current->len--;
        }
    }
    else
        printf("Queue %s isn't exist\n",name);
}
void merge(char name1[500],char name2[500]){
    if(yes(name1)==0)
        printf("Queue %s isn't exist",name1);
    else if(yes(name2)==0)
        printf("Queue %s isn't exist",name2);
    else
    {
        queue *current1=root;
        while(current1!=NULL)
        {
            if(strcmp(current1->name,name1)==0)
                break;
            current1=current1->next;
        }
        queue *current2=root;
        while(current2!=NULL)
        {
            if(strcmp(current2->name,name2)==0)
                break;
            current2=current2->next;
        }
        if(current1->start==0)
            current1->start=current1->end=current2->start;
        else
            current1->end->next=current2->start;
        current1->end=current2->end;
        current1->len+=current2->len;

        current1=root;
        while(current1!=NULL)
        {
            if(strcmp(current1->next->name,name2)==0)//root->q1->q2->q3->NULL
                break;
            current1=current1->next;
        }
        queue *tmp = current1 ->next;

        current1->next=tmp->next;
    }
}
int main(){
    int choose,data;
    char name1[500],name2[500];
    while(1)
    {
        scanf("%d",&choose);
        if(choose==1)
        {
            scanf("%s",&name1);
            add(name1);
            if(root==NULL){
                printf("test");
            }
        }
        else if(choose==2)
        {
            scanf("%s %d",&name1,&data);
            enqueue(name1,data);
        }
        else if(choose==3)
        {
            scanf("%s",&name1);
            dequeue(name1);
        }
        else if(choose==4)
        {
            scanf("%s %s",&name1,&name2);
            merge(name1,name2);
        }else if(choose==5){
            printf("****************************************\n");
            queue *i;
            node *j;
            for(i = root;i!=NULL;i=i->next){// visite all queue;
                if(i->len==0)
                    printf("Queue Name:%s Queue Size:0 Queue Element:Queue is empty\n",i->name);
                else{
                    printf("Queue Name:%s Queue Size:%d Queue Element:",i->name,i->len);
                    for(j=i->start;j!=NULL;j=j->next ){
                        printf("%d ",j->data);
                    }
                    printf("\n");
                }
            }
            if(root==NULL)
                    printf("Isn't have any queue\n");
            printf("****************************************\n");
        }else if(choose==6)
            break;
    }
}
