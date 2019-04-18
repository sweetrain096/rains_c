# include <stdio.h>
int n;
int data[30][30];
int result[30 * 30];
int cnt;
struct st {
	int r, c, cnt;
};

struct st stack[30 * 30];
int wp, rp;


void dfs(int row, int col) {
	int nr, nc;
	int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };
	cnt++;

	//wp = rp = 0;
	//in_stack(row, col, cnt++);
	data[row][col] = 0;
	for (int i = 0; i < 4; i++) {
		nr = row + dr[i];
		nc = col + dc[i];
		if (nr < 1 || nr > n || nc < 1 || nc > n) continue;
		if (data[nr][nc] == 0) continue;
		dfs(nr, nc);
	}
}

int main(void) {
	int sol = 0, cnt_check = 0;
	int tmp;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &data[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (data[i][j] == 1) {
				cnt = 0;
				dfs(i, j);
				result[cnt_check] = cnt;
				cnt_check++;
			}
		}
	}

	printf("%d\n", cnt_check);
	for (int i = 0; i < cnt_check - 1; i++) {
		for (int j = i + 1; j < cnt_check; j++) {
			if (result[i] > result[j]) {
				tmp = result[j];
				result[j] = result[i];
				result[i] = tmp;
			}
		}
	}
	for (int i = 0; i < cnt_check; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}