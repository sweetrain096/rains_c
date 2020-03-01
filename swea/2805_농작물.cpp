#include <stdio.h>

int TC;
int n;
int Map[50][50];
int result;
int mid;

int main(void) {
	freopen("2805_input.txt", "r", stdin);
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d ", &n);
		result = 0;
		mid = int(n / 2);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &Map[i][j]);
			}
		}
		for (int i = 0; i < n / 2; i++) {
			for (int j = mid - i; j < mid + i + 1; j++) {
				result += Map[i][j];
				result += Map[n - i - 1][j];
			}
		}
		for (int i = 0; i < n; i++) { result += Map[mid][i]; }
		printf("#%d %d\n", tc, result);
	}
	return 0;
}