#include <stdio.h>
int num(int i, int j);
void Sudo(int n);
int map[9][9], ans[18][3];//解答會有18列 每列有3個數字
int main() {
    int i, j;
	char tmp;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 10; j++) {
			scanf("%c", &tmp);
			if(tmp != '\n')
				map[i][j] = (int)tmp - (int)'0';
		}
	}
	Sudo(0);
	print();
	return 0;
}
void Sudo(int n) {
	int i, j;
	if (n == 18)//n表示已填的答案個數
		return;
	for (i = 0; i < 9; i++) {//拜訪所有數字，找到0的做處理
		for (j = 0; j < 9; j++) {
			if (map[i][j] == 0) {//該格為0
                    map[i][j] = num(i, j);//將答案填入該格
                    if (map[i][j] != 0) {//如果該格填入的不是零　表示這格有解
                        ans[n][0] = i;//將答案填入陣列中
                        ans[n][1] = j;
                        ans[n][2] = map[i][j];
                        Sudo(n + 1);//遞迴
                    }
			}
		}
	}
}
int num(int i, int j) {
	int flag[]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};//刪去法的表格 表示未使用過1表示已經使用過 0表示未使用
	int row, col,count = 0, result = 0;
	for (col = 0; col < 9; col++) {//橫排刪去法
		if (map[i][col] != 0) {
			flag[map[i][col]] = 1;//將該數字設為已使用過
		}
	}
	for (row = 0; row < 9; row++) {//直排消去
		if (map[row][j] != 0) {
			flag[map[row][j]] = 1;//將該數字設為已使用過s
		}
	}
	for (col = 1; col < 10; col++) {//刪完後檢查該格剩下哪個數字能填 也就是flag 還是0的位置
		if (flag[col]) {//如果這數字已經使用過 那True_count + 1
			count++;
		}else {//如果這個數字沒有使用過，那就記錄下來
			result = col;
		}
	}
	if (count == 8) {//檢查已使用的數字是否為8
		return result;
	}else {
		return 0;
	}
}
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void print(){
    int i,j;
    for(i=0;i<17;i++){
        for(j=i+1;j<18;j++){
            if(ans[j][0]<ans[i][0]||ans[j][0]==ans[i][0]&&ans[j][1]<ans[i][1]){
                swap(&ans[j][0],&ans[i][0]);
                swap(&ans[j][1],&ans[i][1]);
                swap(&ans[j][2],&ans[i][2]);
            }
        }
    }
    for(i=0;i<18;i++){
        printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    }
}
