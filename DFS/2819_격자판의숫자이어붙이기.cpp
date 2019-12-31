#include <stdio.h>
#include <math.h>

int T;
char map[4][5];
char number[8];
int result;
int numbers[10000000] = { 0, };
int index[100000];
int idx;

int deg[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int make_int(char *number) {
	double mul = 10;
	int int_num = 0;
	for (int i = 0; i< 7; i++){
		int_num += (number[6 - i] - '0') * pow(mul, i);
	}
	return int_num;
}

int is_wall(int r, int c) {
	if (r < 0 || r >= 4 || c < 0 || c >= 4) return 1;
	return 0;
}

void make_number(int r, int c, int cnt) {
	if (cnt == 7) {
		//printf("%s\n", number);
		if (numbers[make_int(number)] == 0) {
			result++;
			numbers[make_int(number)] = 1;
			index[idx++] = make_int(number);
		}
		return;
	}
	int dr, dc;
	int nr, nc;
	for (int i = 0; i < 4; i++) {
		dr = deg[i][0];
		dc = deg[i][1];
		nr = dr + r;
		nc = dc + c;
		if (is_wall(nr, nc) == 0) {
			number[cnt++] = map[nr][nc];
			make_number(nr, nc, cnt);

			number[cnt--] = '\0';
		}

	}


}
int main(void) {
	freopen("2819_input.txt", "r", stdin);
	scanf("%d ", &T);

	for (int tc = 1; tc <= T; tc++) {
		result = 0;
		idx = 0;
		for (int i = 0; i < 4; i++) {
			for (int r = 0; r < 4; r++) {
				scanf("%c ", &map[i][r]);
			}
		}
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				number[0] = map[r][c];
				make_number(r, c, 1);
			}
		}
		printf("#%d %d\n", tc, result);
		for (int j = 0; j < idx; j++) {
			numbers[index[j]] = 0;
			index[j] = 0;
		}
	}


	return 0;
}