#include<stdio.h>
#include<math.h>
#define ERROR 'E'
typedef char queue_element_t;
typedef struct queue_node_s{
    queue_element_t element;
    struct queue_node_s *restp;
}queue_node_t;
typedef struct{
    queue_node_t *rearp;
    queue_node_t *frontp;
}queue_t;
queue_element_t dequeue(queue_t *qp){
    queue_element_t data;
    queue_node_t *p=qp->frontp;
    if(p==NULL)return ERROR;
    else if(p==qp->rearp)qp->rearp=NULL;
    data=p->element;
    qp->frontp=p->restp;
    free(p);
    return data;
}
void enqueue(queue_t *qp,queue_element_t data){
    queue_node_t *newNode;
    newNode=(queue_node_t*)malloc(sizeof(queue_node_t));
    newNode->element=data;
    newNode->restp=NULL;
    if(qp->rearp==NULL){
        qp->frontp=newNode;
        qp->rearp=newNode;
    }
    qp->rearp->restp=newNode;
    qp->rearp=newNode;
}
int main(){
    queue_t s={NULL,NULL}; enqueue(&s,'2');
    enqueue(&s,'+');     enqueue(&s,'3');
    printf("%c ",dequeue(&s));printf("%c ",dequeue(&s));
    printf("%c ",dequeue(&s));printf("%c ",dequeue(&s));
}
