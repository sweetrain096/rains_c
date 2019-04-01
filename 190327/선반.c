# include <stdio.h>
int tc;
int n, b;
int data[30], tmp[30];
int result;

int min(int a, int b) {
	if (a >= b) return b;
	else return a;
}

void powerset(int n, int k, int sum_data) {
	if (sum_data >= b) {
		result = min(result, sum_data);
		return;
	}
	if (n == k) return;
	else {
		tmp[k] = 1;
		powerset(n, k + 1, sum_data + data[k]);
		tmp[k] = 0;
		powerset(n, k + 1, sum_data);
	}
}

int main() {
	int i, j;
	scanf("%d", &tc);
	for (i = 0; i < tc; i++) {
		scanf("%d %d", &n, &b);
		for (j = 0; j < n; j++) {
			scanf("%d", &data[j]);
			tmp[j] = 0;
		}
		result = 999999999;
		powerset(n, 0, 0);

		printf("#%d %d\n", i + 1, result - b);

	}
	return 0;
}