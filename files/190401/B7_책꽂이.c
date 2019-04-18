# include <stdio.h>

int t;
int n, b;
int h[1000010], tmp[1000010];
int cnt, result, index, sum;


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
		powerset(n, k + 1, sum_data + h[k]);
		tmp[k] = 0;
		powerset(n, k + 1, sum_data);
	}
}


int main() {
	int tc, i, j;
	scanf("%d", &t);
	for (tc = 0; tc < t; tc++) {
		scanf("%d %d", &n, &b);
		for (i = 0; i < n; i++) {
			scanf("%d", &h[i]);
			tmp[i] = 0;
		}
		result = 999999999;
		powerset(n, 0, 0);

		printf("%d\n", result - b);



	}

	return 0;
}