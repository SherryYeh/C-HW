#include <stdio.h>
void back(int city[9][9],int walked[9][9],int i,int j,int *sum){
	walked[i][j] = 0;
	*sum -= city[i][j];
}
int walk(int city[9][9],int walked[9][9],int i,int j,
         int n,int m,int *sum,int *min){
	*sum += city[i][j];
	walked[i][j] = 1;
	if(i==n-1 && j==m-1){
		if(*sum<*min){
			return *sum;
		}else{
			return *min;
		}
	}
	else if(*sum>=*min){
		return *min;
	}
	else{
		if(i+1<n){
			if(walked[i+1][j]==0){
				*min = walk(city,walked,i+1,j,n,m,sum,min);
			    back(city,walked,i+1,j,sum);
			}
		}
		if(j+1<m){
			if(walked[i][j+1]==0){
		     	*min = walk(city,walked,i,j+1,n,m,sum,min);
		    	back(city,walked,i,j+1,sum);
		    }
		}
		if(i-1>=0){
			if(walked[i-1][j]==0){
			    *min = walk(city,walked,i-1,j,n,m,sum,min);
			    back(city,walked,i-1,j,sum);
			}
		}
		if(j-1>=0){
			if(walked[i][j-1]==0){
			    *min = walk(city,walked,i,j-1,n,m,sum,min);
			    back(city,walked,i,j-1,sum);
		    }
		}
	}
	return *min;
}
void main(){
	int i,j,m,n,sum=0,min=99999;
    int city[9][9]={},walked[9][9]={};
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=0;i<n;i++){
    	for(j=0;j<m;j++){
    		scanf("%d",&city[i][j]);
    		walked[i][j] = 0;
		}
	}
	min = walk(city,walked,0,0,n,m,&sum,&min);
    printf("%d",min);
}
