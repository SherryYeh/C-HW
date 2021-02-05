#include<stdio.h>
#include<string.h>
#include<ctype.h>
void tok(char *data2[5][200],char data[5][200],char *spl){
	int i,j;
	for(i=0;i<5;i++){
		data2[i][0] = strtok(data[i],spl);
		for(j=0;data2[i][j]!=NULL;){
			data2[i][++j] = strtok(NULL,spl);
		}
	}
}
int f(char result3[200][200],char *result[200][200],char *result2[200][200],char *data[5][200],char *dataO[5][200],char *p,int n,char lr){
	int a=0,i,j,k,m,m2,m3,x,sum[200];
	char inv[200][200];
	for(i=0;i<200;i++)	{
		inv[i][0]='\0';
		result3[i][0]=' ';
		for(j=1;j<200;j++){
			inv[i][j]='0';
		}
		sum[i]=-1;
	}
	for(i=0;i<5;i++){
		if(data[i][0][0]!='0'){
			for(j=0;data[i][j]!=NULL;j++){
				if(strcmp(data[i][j],p)==0){
					m3=0;
					sum[a]=0;
					if(j-n<0)k=0,m3=j-n;
					else k=j-n;
					for(m=0;m<n+m3;k++,m++){  //左邊
						result[a][m] = data[i][k];
						result2[a][m] = dataO[i][k];
						if(lr=='L'){
							sum[a]+=strlen(result2[a][m]);
							strinsert(inv[a],result2[a][m],0);
						}
					}
					result[a][m] = p;//中間
					result2[a][m++] = p;
					m2=0;
					for(k=j+1;data[i][k]!=NULL&&m2<n;k++,m2++,m++){
						result[a][m] = data[i][k];//右邊
						result2[a][m] = dataO[i][k];
						if(lr=='R'){
							sum[a]+=strlen(result2[a][m]);
							strinsert(inv[a],result2[a][m],0);
						}
					}
					a++;
				}
			}
		}
	}
	for(i=0;i<strlen(p);i++)p[i]=toupper(p[i]);
	for(i=0;i<a;i++){
		x=0;
		for(j=0;result[i][j]!=NULL;j++){
			for(k=0;result[i][j][k]!='\0';k++,x++){
				result3[i][x] = result[i][j][k];
			}
			result3[i][x]=' ';
			x++;
		}
		result3[i][x]='\0';
	}
	sort(result3,result,a,lr,p,n,sum,inv);
	return a;
}
void sort2(char result3[200][200],char inv[200][200],int start,int end,char lr){
	int i,j,x;char temp2[200],temp[200];
	for(i=start;i<end;i++){
		for(j=i;j<end;j++){
			if(lr=='L'){
				for(x=strlen(inv[i])-1;x>=0;x--){
					if(inv[i][x]>inv[j][x]){
						strcpy(temp2,inv[j]),strcpy(temp,result3[j]);
						strcpy(inv[j],inv[i]),strcpy(result3[j],result3[i]);
						strcpy(inv[i],temp2),strcpy(result3[i],temp);
						break;
					}
					else if(inv[i][x]<inv[j][x]) break;
				}
			}
			if(lr=='R'){
				for(x=0;x<strlen(inv[i]);x++){
					if(inv[i][x]>inv[j][x]){
						strcpy(temp2,inv[j]),strcpy(temp,result3[j]);
						strcpy(inv[j],inv[i]),strcpy(result3[j],result3[i]);
						strcpy(inv[i],temp2),strcpy(result3[i],temp);
						break;
					}
					else if(inv[i][x]<inv[j][x])break;
				}
			}
		}
	}

}
void sort(char result3[200][200],char *result[200][200],int a,char lr,char *p,int n,int *sum,char inv[200][200]){
	int i,j,temps;
	char temp[200],temp2[200];
	for(i=0;i<a;i++){
		for(j=0;j<a;j++){
			if(sum[i]<sum[j]){
				strcpy(temp2,inv[j]),temps = sum[i],strcpy(temp,result3[i]);
				strcpy(inv[j],inv[i]),sum[i] = sum[j],strcpy(result3[i],result3[j]);
				strcpy(inv[i],temp2),sum[j] = temps,strcpy(result3[j],temp);
			}
		}
	}
	i=0,j=0;
	while(i<a){
		for(;sum[i]==sum[i+1];i++);
		i++;
		sort2(result3,inv,j,i,lr);
		j=i;
	}
}
void strinsert(char *a,char *b,int p){
	int i,j;
	for(i=0;a[i]!='\0';i++);
	for(j=0;b[j]!='\0';j++,i++){
		a[i] = b[j];
	}
	a[i]='\0';
}

int main(){
	char p[200],lr,data[5][200],dataO[5][200],*data2[5][200],*result[200][200],*spl=" ";int i,j,n;
	char *dataO2[5][200],*result2[200][200];
	char result3[200][200];
	int a;
	scanf("%s %d %c ",p,&n,&lr);
	for(i=0;i<5;i++){
		gets(data[i]);
		for(j=0;data[i][j]!='\0';j++){
			dataO[i][j] = data[i][j];
			data[i][j] = tolower(data[i][j]);
			p[j] = tolower(p[j]);
		}
	}
	tok(data2,data,spl);
	tok(dataO2,dataO,spl);
	a=f(result3,result,result2,data2,dataO2,p,n,lr);
	for(i=0;i<a;i++){
		printf("%s\n",result3[i]);
	}
	return 0;
}
