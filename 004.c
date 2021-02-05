#include<stdio.h>
#include<math.h>
typedef struct{
    int id;
    char name[100];
    float score[100];
}student;
float fixfloat(float num){
    int tmp = (int)(num * 1000);
    if(tmp % 10 >= 5){
        tmp /= 10;
        tmp += 1;
    }else{
        tmp /= 10;
    }
    float result = tmp / 100.0;
    return result;
}
int main(){
    int i,people,j,k,w;
    float rank[100],sumscore[100],avescore0=0,avescore1=0,avescore2=0,total=0,x,y=0,bigave=0,minave=0,big,min;
    scanf("%d",&people);
    student stu[people];
    for(i=0;i<people;i++){
        sumscore[i]=0;
        scanf("%d %s %f %f %f",&stu[i].id,&stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        sumscore[i]=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
        total+=sumscore[i];
        avescore0+=(stu[i].score[0]/people);
        avescore1+=(stu[i].score[1]/people);
        avescore2+=(stu[i].score[2]/people);
        rank[i]=sumscore[i];
    }
    int temp=0;
    for(k=0;k<people;k++){
        for(w=k+1;w<people;w++) {
            if(rank[k]<rank[w]){
                temp=rank[k];
                rank[k]=rank[w];
                rank[w]=temp;
            }
        }
    }
    for(i=0;i<people;i++){
        for(j=0;j<people;j++){
            if(rank[i]==sumscore[j])
                printf("%d %s %.0f %.0f %.0f %.0f %d\n",stu[j].id,stu[j].name,stu[j].score[0],stu[j].score[1],stu[j].score[2],rank[i],i+1);;
        }
    }
    printf("%.2f\n%.2f\n%.2f\n%.2f\n",fixfloat(avescore0),fixfloat(avescore1),fixfloat(avescore2),fixfloat(total/people));
    if(people%2==0){
        printf("%.2f\n",fixfloat((rank[people/2]+rank[people/2-1])/2));
    }else{
        printf("%.2f\n",fixfloat(rank[people/2]));
    }
    for(i=0;i<people;i++){
        x=total/people;
        y+=(pow((rank[i]-x),2));
    }
    printf("%.2f\n%.2f\n",fixfloat(y/people),fixfloat(sqrt(y/people)));
    if(people%2==0){
        big=people/2-1;
        min=people/2;
    }else{
        big=people/2-1;
        min=people/2+1;
    }
    j=0;
    for(i=big;i>=0;i--){
        bigave+=rank[i];
        j++;
    }
    printf("%.2f\n",fixfloat(bigave/j));
    j=0;
    for(i=min;i<people;i++){
        minave+=rank[i];
        j++;
    }
    printf("%.2f\n",fixfloat(minave/j));
}
