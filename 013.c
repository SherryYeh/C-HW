#include<stdio.h>
void tryadd(int move[],int direct){
    int i=0;
    for(i=28; i>=0; i--){
        move[i+1]=move[i];
    }
    if(direct==1)
        move[0]=-100;
    else if(direct==2)
        move[0]=100;
    else if(direct==3)
        move[0]=-1;
    else if(direct==4)
        move[0]=1;
}
int go(int snake[], int move[], int direct, int get){
    int i;
    if(get==1){
        for(i=28;i>=0;i--){
            snake[i+1] = snake[i];
        }
        if(direct==1)
            snake[0]=snake[1]-100;
        else if(direct==2)
            snake[0]=snake[1]+100;
        else if(direct==3)
            snake[0]=snake[1]-1;
        else if(direct==4)
            snake[0]=snake[1]+1;
    }else{
        for(i=0;i<30;i++){
            if(snake[i]==-1)
                break;
            snake[i]=snake[i]+move[i];
        }
    }
}
int eat(int snake[],int fruitxy[],int move[]){
    int i;
    for(i=0;i<10;i++){
        if(snake[0]+move[0]==fruitxy[i]){
			return 1;
		}
    }
    return 0;
}
int gameover(int snake[], int move[], int direct, int lastdirect){
    int headx=0,heady;
    int i=0;
    headx=snake[0]/100;
    heady=snake[0]%100;
    if(headx==1 && direct==1)
        return 1;
    if(headx==18 && direct==2)
        return 1;
    if(heady==1 && direct==3)
        return 1;
    if(heady==18 && direct==4)
        return 1;
    if(snake[1]!=-1){
    	if(direct==1 && lastdirect==2)
            return 1;
    	if(direct==2 && lastdirect==1)
            return 1;
    	if(direct==3 && lastdirect==4)
            return 1;
    	if(direct==4 && lastdirect==3)
            return 1;
        for(i=1;i<30;i++){
            if(snake[i]==-1)
                break;
            if(snake[0]+move[0]==snake[i]+move[i])
                return 1;
        }
    }
    return 0;
}
void Print(int snake[]){
    int i=0;
    for(i=0; i<30; i++){
        if(snake[i]==-1)
            break;
    }
    printf("%d\n",i);
    for(i=0;i<30; i++){
        if(snake[i]==-1)
            break;
        printf("%d %d\n",snake[i]/100,snake[i]%100);
    }
}
int main(){
	int i,j,x,y,input[50]={},direct=4,lastdirect=4,snake[30],fruitxy[10],fruits,move[30],get;
	snake[0]=909;
	move[0]=0;
	for(i=1;i<30; i++){
        snake[i]=-1;
        move[i]=0;
	}
	scanf("%d",&fruits);
	for(i=0;i<fruits;i++){
        scanf("%d %d",&x,&y);
        fruitxy[i]=x*100+y;
	}
    i=0;
    while(1){
        scanf("%d",&input[i]);
        if(input[i]==-1)
            break;
        i++;
    }
    for(j=0;j<=i;j++){
        if(input[j]==5){
            tryadd(move,direct);
            if(gameover(snake,move,direct,lastdirect)==0){
            	get=eat(snake,fruitxy,move);
                go(snake,move,direct,get);
                lastdirect=direct;
            }
        }
        else if(input[j]==0 || input[j]==-1 || gameover==1)
            Print(snake);
        else
            direct=input[j];
    }
}
