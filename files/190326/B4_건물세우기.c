# include <stdio.h>
int n, result = 99999999999999999;
int data[15][15];
int visited[15];

void dfs(int row, int sum_data) {
	if (sum_data > result) return;
	if (row == n) {
		if (result > sum_data) {
			result = sum_data;
			return;
		}
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] != 0) continue;
		sum_data += data[row][i];
		visited[i] = 1;
		dfs(row + 1, sum_data);
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


	dfs(0, 0);
	printf("%d", result);
}