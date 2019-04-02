# include <stdio.h>
int max_length;
int n;
int length_data[60], fix_data[60];
int result;

int min(int a, int b) {
	if (a <= b) return a;
	else return b;
}

void dfs(int k, int drive_time, int fix_time) {
	if (fix_time > result) return;

	if (k == n) {
		if (drive_time + length_data[k] > max_length) return;
		result = min(result, fix_time);
		return;
	}
	if (drive_time + length_data[k] > max_length) return;
	else if (drive_time + length_data[k] == max_length) {
		dfs(k + 1, 0, fix_time + fix_data[k]);
	}
	dfs(k + 1, drive_time + length_data[k], fix_time);
	dfs(k + 1, 0, fix_time + fix_data[k]);
}
int main() {
	int i;
	scanf("%d", &max_length);
	scanf("%d", &n);
	for (i = 0; i <= n; i++) {//0번은 첫번째 정비소까지 거리. 무조건 지나간다.
		scanf("%d", &length_data[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &fix_data[i], &fix_data[i]);
	}
	result = 9999999;
	dfs(0, 0, 0);
	printf("%d", result);
}