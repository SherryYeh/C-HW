#include<stdio.h>
void add(int move[], int run){
    int i=0;
    for(i=28; i>=0; i--){
        move[i+1] = move[i];
    }
    if(run==1) move[0] = -100;
    else if(run==2) move[0] = 100;
    else if(run==3) move[0] = -1;
    else if(run==4) move[0] = +1;
}

int f_move(int snake[], int move[], int run, int get){
    int i=0;
    int n;
    if(get==1){
        for(i=28; i>=0; i--){
            snake[i+1] = snake[i];
        }
        if(run==1) snake[0] = snake[1]-100;
        else if(run==2) snake[0] = snake[1]+100;
        else if(run==3) snake[0] = snake[1]-1;
        else if(run==4) snake[0] = snake[1]+1;
    }
    else{
        for(i=0; i<30; i++){
            if(snake[i]==-1) break;
            snake[i] = snake[i] + move[i];
        }
    }
}

int getFruit(int snake[], int fruit[], int move[]){
    int i=0;
    for(i=0; i<10; i++){
        if(snake[0]+move[0]==fruit[i]){
			fruit[i]=-1;
			return 1;
		}
    }
    return 0;
}

int isGameOver(int snake[], int move[], int run, int last_run){
    int head_i=0, head_j=0;
    int i=0;

    head_i = snake[0]/100;
    head_j = snake[0]%100;

    if(head_i==1 && run==1) return 1; //撞上牆
    if(head_i==18 && run==2) return 1; //撞下牆
    if(head_j==1 && run==3) return 1; //撞左牆
    if(head_j==18 && run==4) return 1; //撞右牆

    //吃自己
    if(snake[1] != -1){
    	if(run == 1 && last_run == 2) return 1;
    	if(run == 2 && last_run == 1) return 1;
    	if(run == 3 && last_run == 4) return 1;
    	if(run == 4 && last_run == 3) return 1;

        for(i=1; i<30; i++){
            if(snake[i]==-1) break;
            if(snake[0]+move[0] == snake[i]+move[i]) return 1;
        }
    }
    return 0;
}
/*void p_all(int snake[], int fruit[]){
    int i=0, j=0, k=0;
    int sw=0;

    for(i=0; i<20; i++){
        for(j=0; j<20; j++){
            if(i==0 || i==19 || j==0 || j==19){
                printf("w");
                sw = 1;
            }
            else{
                for(k=0; k<30; k++){
                    if(snake[k] == i*100+j){
                        printf("0");
                        sw = 1;
                        break;
                    }
                    if(fruit[k] == i*100+j){
                        printf("*");
                        sw = 1;
                    }
                }
            }
            if(sw == 0){
                printf("#");
            }
            sw = 0;
        }
        printf("\n");
    }

}*/
void Print(int snake[]){
    int i=0;

    for(i=0; i<30; i++){
        if(snake[i]==-1) break;
    }
    printf("%d\n", i);

    for(i=0; i<30; i++){
        if(snake[i]==-1) break;
        printf("%d %d\n", snake[i]/100, snake[i]%100);
    }

}

int main(){
	int i=0, j=0;
	int x=0,y=0;
    int move[30];
	int IN=0;           //上 1 下 2 左 3 右 4 前進一格 5
	int run=4;
	int last_run=4;
    int snake[30];
    int fruit[10];
    int fruit_amount=0;
    int get=0;

	//給初值
	snake[0] = 909;
	move[0]=0;
	for(i=1; i<30; i++){
        snake[i] = -1;
        move[i] = 0;
	}

	scanf("%d", &fruit_amount);
	for(i=0; i<fruit_amount; i++){
        fflush(stdin);
        scanf("%d %d", &x, &y);
        fruit[i] = x*100 + y;
	}
	for(i; i<10; i++){
        fruit[i] = -1;
	}
    //p_all(snake, fruit);
	while(IN!=-1){
        fflush(stdin);
        scanf("%d", &IN);
        if(IN==0){
            Print(snake);
        }
        else if(IN==5){
            add(move, run);
            if(isGameOver(snake, move, run, last_run)==0){
            	get = getFruit(snake, fruit, move);
                f_move(snake, move, run, get);
                //p_all(snake, fruit);
                last_run = run;
            }
            else{
               break;
            }
        }
        else{
            run = IN;
        }
	}
    Print(snake);
	return 0;
}


