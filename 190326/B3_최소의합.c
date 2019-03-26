# include <stdio.h>

int n;
int data[20][20];
int visited[20];
int min1, result1 = 0;
int min2, result2 = 99999999999999999;

void dfs1(int row) {
	if (row == n) return;
	min1 = data[row][0];
	for (int i = 1; i < n; i++) {
		if (data[row][i] < min1) {
			min1 = data[row][i];
		}
	}
	result1 += min1;
	dfs1(row + 1);
}

void dfs2(int row, int sum_data) {
	if (result2 < sum_data) return;
	if (row == n) {
		if (sum_data < result2) {
			result2 = sum_data;
			return;
		}
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] != 0) continue;
		sum_data += data[row][i];
		visited[i] = 1;
		dfs2(row + 1, sum_data);
		visited[i] = 0;
		sum_data -= data[row][i];
	}
}


int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &data[i][j]);
		}
	}

	dfs1(0);
	printf("%d\n", result1);

	dfs2(0, 0);
	printf("%d", result2);
}