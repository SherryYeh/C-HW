#include <stdio.h>
int num(int i, int j);
void Sudo(int n);
int map[9][9], ans[18][3];//�ѵ��|��18�C �C�C��3�ӼƦr
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
	if (n == 18)//n��ܤw�񪺵��׭Ӽ�
		return;
	for (i = 0; i < 9; i++) {//���X�Ҧ��Ʀr�A���0�����B�z
		for (j = 0; j < 9; j++) {
			if (map[i][j] == 0) {//�Ӯ欰0
                    map[i][j] = num(i, j);//�N���׶�J�Ӯ�
                    if (map[i][j] != 0) {//�p�G�Ӯ��J�����O�s�@��ܳo�榳��
                        ans[n][0] = i;//�N���׶�J�}�C��
                        ans[n][1] = j;
                        ans[n][2] = map[i][j];
                        Sudo(n + 1);//���j
                    }
			}
		}
	}
}
int num(int i, int j) {
	int flag[]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};//�R�h�k����� ��ܥ��ϥιL1��ܤw�g�ϥιL 0��ܥ��ϥ�
	int row, col,count = 0, result = 0;
	for (col = 0; col < 9; col++) {//��ƧR�h�k
		if (map[i][col] != 0) {
			flag[map[i][col]] = 1;//�N�ӼƦr�]���w�ϥιL
		}
	}
	for (row = 0; row < 9; row++) {//���Ʈ��h
		if (map[row][j] != 0) {
			flag[map[row][j]] = 1;//�N�ӼƦr�]���w�ϥιLs
		}
	}
	for (col = 1; col < 10; col++) {//�R�����ˬd�Ӯ�ѤU���ӼƦr��� �]�N�Oflag �٬O0����m
		if (flag[col]) {//�p�G�o�Ʀr�w�g�ϥιL ��True_count + 1
			count++;
		}else {//�p�G�o�ӼƦr�S���ϥιL�A���N�O���U��
			result = col;
		}
	}
	if (count == 8) {//�ˬd�w�ϥΪ��Ʀr�O�_��8
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
