#include <stdio.h>
int check(int i, int j, char map[][10], char player);
void get_position(char map[][10], char player);
void LoadData(char map[][10]);
int main() {
	char map[10][10];
	LoadData(map);
	printf("Player1\n");
	get_position(map, '0');
	printf("Player2\n");
	get_position(map, '1');
	return 0;
}
void LoadData(char map[][10]) {
	int i, j;
	char tmp = NULL;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			scanf("%c", &map[i][j]);
			scanf("%c", &tmp);//ÅªªÅ¥Õ
		}
	}
}
int check(int i, int j, char map[][10], char player) {
	//left and right count
	int count = 0, row, col;
	for (col = j-1; col > -1; col--) {
		if (map[i][col] == player) {
			count++;
		}else {
			break;
		}
	}
	for (col = j+1; j < 10; col++) {
		if (map[i][col] == player) {
			count++;
		}
		else {
			break;
		}
	}
	if (count >= 4) {
		return 1;
	}
	//top down check
	count = 0;
	for (row = i-1; row > -1; row--) {
		if (map[row][j] == player) {
			count++;
		}
		else {
			break;
		}
	}
	for (row = i+1; row < 10; row++) {
		if (map[row][j] == player) {
			count++;
		}
		else {
			break;
		}
	}

	if (count >= 4) {
		return 1;
	}else {
		return 0;
	}
}
void get_position(char map[][10], char player) {
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (map[i][j] == 'x') {
				if (check(i, j, map, player)) {
					printf("%d,%d\n", i, j);
				}
			}
		}
	}
}
