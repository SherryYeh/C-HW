#include<stdio.h>
typedef struct{
    int id;
    char name[100];
    int count;
    char subject[100][100];
    int credit[100];
    double score[100];
}student;

int search(student arr,int id, int people){
    int i;
    for(i=0; i<people; i++){
        if(arr[i].id == id)
            return i;
    }
    return -1;
}

double fixDouble(double num){
    int tmp = (int)(num * 1000);
    if(tmp % 10 >= 5){
        tmp /= 10;
        tmp += 1;
    }else{
        tmp /= 10;
    }
    double result = tmp / 100.0;
    return result;
}

int main(){
    int people,course[100],i,j,k,getcre[100]={0},sumcre[100]={0};
    double sumscore[100]={0},ave[100]={0},rank[100];
    for(i=0; i<100; i++){
        getcre[i]=0;
        sumcre[i]=0;
        sumscore[i]=0;
        ave[i]=0;
        rank[i] = 0;
        //printf("%d %d %lf %lf %lf", getcre[i], sumcre[i], sumscore[i], ave[i], rank[i]);
    }
    scanf("%d",&people);
    student stu[people];
    for(i=0;i<people;i++){
        scanf("%d %s",&stu[i].id, &stu[i].name);
        scanf("%d", &stu[i].count);
        for(j=0;j<stu[i].count;j++){
            scanf("%s %d %lf",&stu[i].subject[j],&stu[i].credit[j],&stu[i].score[j]);
            if(stu[i].score[j]>=60){
                getcre[i]+=stu[i].credit[j];
            }
            sumcre[i]+=stu[i].credit[j];
            sumscore[i]+=(stu[i].credit[j]*stu[i].score[j]);
        }
        ave[i]=(sumscore[i]/sumcre[i]);
        rank[i]=ave[i];
    }
    int A[100],x=0,w;
    while(1){
        scanf("%d",&A[x]);
        if(A[x]==0)
            break;
        x++;
    }

    double temp=0;
    for(k=0;k<people;k++){
        for(w=k+1;w<people;w++) {
            if(rank[k]<rank[w]){
                temp=rank[k];
                rank[k]=rank[w];
                rank[w]=temp;
            }
        }
    }

    for(i=0;i<x;i++){
        int index = search(stu, id, people);
        if(index > -1){
            printf("%d %s\n",stu[index].id,stu[index].name);
        }
                for(k=0;k<stu[j].count;k++){//the strudent imformation
                    printf("%s %d %.0lf\n",stu[j].subject[k],stu[j].credit[k],stu[j].score[k]);
                }

                printf("%d\n%.2lf\n",getcre[j],fixDouble(ave[j]));
                for(k=0;k<people;k++){
                    if(ave[j]==rank[k]){
                         printf("%d\n",k+1);
                         break;
                    }

                }
                break;
            }

        }
        if(j==people){
            printf("ERROR\n");
        }
    }
}
