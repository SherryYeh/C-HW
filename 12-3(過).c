#include<stdio.h>
#include<string.h>
#include<ctype.h>
void mystrtok(char *word2[5][200],char input[5][200],char *spl){
	int i,j;
	for(i=0;i<5;i++){
		word2[i][0] = strtok(input[i],spl);
		for(j=0;word2[i][j]!=NULL;){
			word2[i][++j] = strtok(NULL,spl);
		}
	}
}
int compute(char *final[200][200],char *final2[200][200],char final3[200][200],char *input[5][200],char *input2[5][200],char *p,int n,char direction){
	int a=0,i,j,k,m,m2,m3,x,times[200];
	char inverse[200][200];
	for(i=0;i<200;i++){
		inverse[i][0]='\0';
		final3[i][0]=' ';
		for(j=1;j<200;j++){
			inverse[i][j]='0';
		}
		times[i]=-1;
	}
	for(i=0;i<5;i++){
		if(input[i][0][0]!='0'){
			for(j=0;input[i][j]!=NULL;j++){
				if(strcmp(input[i][j],p)==0){
					m3=0;
					times[a]=0;
					if(j-n<0)
                        k=0,m3=j-n;
					else
                        k=j-n;
					for(m=0;m<n+m3;k++,m++){
						final[a][m] = input[i][k];
						final2[a][m] = input2[i][k];
						if(direction=='L'){
							times[a]+=strlen(final2[a][m]);
							strinsert(inverse[a],final2[a][m],0);
						}
					}
					final[a][m] = p;
					final2[a][m++] = p;
					m2=0;
					for(k=j+1;input[i][k]!=NULL&&m2<n;k++,m2++,m++){
						final[a][m] = input[i][k];
						final2[a][m] = input2[i][k];
						if(direction=='R'){
							times[a]+=strlen(final2[a][m]);
							strinsert(inverse[a],final2[a][m],0);
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
		for(j=0;final[i][j]!=NULL;j++){
			for(k=0;final[i][j][k]!='\0';k++,x++)
				final3[i][x] = final[i][j][k];
			final3[i][x]=' ';
			x++;
		}
		final3[i][x]='\0';
	}
	rank(final3,final,a,direction,p,n,times,inverse);
	return a;
}
void strinsert(char *a,char *b,int p){
	int i,j;
	for(i=0;a[i]!='\0';i++);
	for(j=0;b[j]!='\0';j++,i++){
		a[i] = b[j];
	}
	a[i]='\0';
}
void rank(char final3[200][200],char *final[200][200],int a,char direction,char *p,int n,int *times,char inverse[200][200]){
	int i,j,temps;
	char temp[200],temp2[200];
	for(i=0;i<a;i++){
		for(j=0;j<a;j++){
			if(times[i]<times[j]){
				strcpy(temp2,inverse[j]),temps = times[i],strcpy(temp,final3[i]);
				strcpy(inverse[j],inverse[i]),times[i] = times[j],strcpy(final3[i],final3[j]);
				strcpy(inverse[i],temp2),times[j] = temps,strcpy(final3[j],temp);
			}
		}
	}
	i=0,j=0;
	while(i<a){
		for(;times[i]==times[i+1];i++);
		i++;
		rank2(final3,inverse,j,i,direction);
		j=i;
	}
}
void rank2(char final3[200][200],char inverse[200][200],int start,int end,char direction){
	int i,j,x;char temp2[200],temp[200];
	for(i=start;i<end;i++){
		for(j=i;j<end;j++){
			if(direction=='L'){
				for(x=strlen(inverse[i])-1;x>=0;x--){
					if(inverse[i][x]>inverse[j][x]){
						strcpy(temp2,inverse[j]),strcpy(temp,final3[j]);
						strcpy(inverse[j],inverse[i]),strcpy(final3[j],final3[i]);
						strcpy(inverse[i],temp2),strcpy(final3[i],temp);
						break;
					}
					else if(inverse[i][x]<inverse[j][x]) break;
				}
			}
			if(direction=='R'){
				for(x=0;x<strlen(inverse[i]);x++){
					if(inverse[i][x]>inverse[j][x]){
						strcpy(temp2,inverse[j]),strcpy(temp,final3[j]);
						strcpy(inverse[j],inverse[i]),strcpy(final3[j],final3[i]);
						strcpy(inverse[i],temp2),strcpy(final3[i],temp);
						break;
					}
					else if(inverse[i][x]<inverse[j][x])break;
				}
			}
		}
	}

}
int main(){
	char p[200],direction,input[5][200],input2[5][200],*word2[5][200],*final[200][200],*spl=" ";
	int i,j,n;
	char *word3[5][200],*final2[200][200];
	char final3[200][200];
	int a;
	scanf("%s %d %c ",p,&n,&direction);
	for(i=0;i<5;i++){
		gets(input[i]);
		for(j=0;input[i][j]!='\0';j++){
			input2[i][j] = input[i][j];
			input[i][j] = tolower(input[i][j]);
			p[j] = tolower(p[j]);
		}
	}
	mystrtok(word2,input,spl);
	mystrtok(word3,input2,spl);
	a=compute(final,final2,final3,word2,word3,p,n,direction);
	for(i=0;i<a;i++){
		printf("%s\n",final3[i]);
	}
	return 0;
}
