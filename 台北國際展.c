#include<stdio.h>
#include<string.h>
typedef struct Company{
    char name[500];//廠商名字
    char site[10];//展區位置(代號，如:P0001)
    char topic[10];//主題(如: AI、Blockchain...)
    char country[10];//國家
    int award;//得獎數量
    struct Company *next;
}one;
one *make(char name[500],char site[10],char topic[10],char country[10],int award){
    one *newnode=(one *)malloc(sizeof(one));
    newnode->next=NULL;
    strcpy(newnode->name,name);
    strcpy(newnode->site,site);
    strcpy(newnode->topic,topic);
    strcpy(newnode->country,country);
    newnode->award=award;
    return newnode;
}
void swap(one **a,one **b){
    one *tmp=make((*a)->name,(*a)->site,(*a)->topic,(*a)->country,(*a)->award);
    strcpy((*a)->name,(*b)->name);
    strcpy((*a)->site,(*b)->site);
    strcpy((*a)->topic,(*b)->topic);
    strcpy((*a)->country,(*b)->country);
    (*a)->award=(*b)->award;
    strcpy((*b)->name,tmp->name);
    strcpy((*b)->site,tmp->site);
    strcpy((*b)->topic,tmp->topic);
    strcpy((*b)->country,tmp->country);
    (*b)->award=tmp->award;
}
void sort(char mode[500],int a,one **root){
    one *i, *j;
    for(i=*root; i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(strcmp(mode,"name")==0){
                if(a==1){
                    if(strcmp(i->name,j->name)<0){
                        swap(&i,&j);
                    }else if(strcmp(i->name, j->name) == 0){
                        if(strcmp(i->site,j->site)<0)
                            swap(&i,&j);
                    }
                }else{
                    if(strcmp(i->name,j->name)>0){
                        swap(&i,&j);
                    }else if(strcmp(i->name, j->name) == 0){
                        if(strcmp(i->site,j->site)>0)
                            swap(&i,&j);
                    }
                }
            }else if(strcmp(mode,"site")==0){
                if(a==1){
                    if(strcmp(i->site,j->site)<0){
                        swap(&i,&j);
                    }
                }else{
                    if(strcmp(i->site,j->site)>0){
                        swap(&i,&j);
                    }
                }
            }else if(strcmp(mode,"topic")==0){
                if(a==1){
                    if(strcmp(i->topic,j->topic)<0){
                        swap(&i,&j);
                    }else if(strcmp(i->topic, j->topic) == 0){
                        if(strcmp(i->site,j->site)<0)
                            swap(&i,&j);
                    }
                }else{
                    if(strcmp(i->topic,j->topic)>0){
                        swap(&i,&j);
                    }else if(strcmp(i->topic, j->topic) == 0){
                        if(strcmp(i->site,j->site)>0)
                            swap(&i,&j);
                    }
                }
            }else if(strcmp(mode,"country")==0){
                if(a==1){
                    if(strcmp(i->country,j->country)<0){
                        swap(&i,&j);
                    }else if(strcmp(i->country, j->country) == 0){
                        if(strcmp(i->site,j->site)<0)
                            swap(&i,&j);
                    }
                }else{
                    if(strcmp(i->country,j->country)>0){
                        swap(&i,&j);
                    }else if(strcmp(i->country, j->country) == 0){
                        if(strcmp(i->site,j->site)>0)
                            swap(&i,&j);
                    }
                }
            }else if(strcmp(mode,"award")==0){
                if(a==1){
                    if(i->award-j->award<0){
                        swap(&i,&j);
                    }else if(i->award-j->award == 0){
                        if(strcmp(i->site,j->site)<0)
                            swap(&i,&j);
                    }
                }else{
                    if(i->award-j->award>0){
                        swap(&i,&j);
                    }else if(i->award- j->award == 0){
                        if(strcmp(i->site,j->site)>0)
                            swap(&i,&j);
                    }
                }
            }
        }
    }
    one *current=*root;
    while(current!=NULL){
        printf("%s %s\n",current->name,current->site);
        current=current->next;
    }
    printf("\n");
}

int main(){
    char name[500],site[10],topic[10],country[10],mode[500];
    int award,a;
    one *root=NULL;
    while(1){
        scanf("%s",&name);
        if(strcmp(name,"-1")==0)
            break;
        scanf("%s %s %s %d",&site,&topic,&country,&award);
        one *newnode=make(name,site,topic,country,award);
        if(root==NULL){
            root=newnode;
        }else{
            newnode->next=root;
            root=newnode;
        }
    }
    while(1){
        scanf("%s",&mode);
        if(strcmp(mode,"exit")==0)
            break;
        scanf("%d",&a);
        sort(mode,a,&root);
    }

}
