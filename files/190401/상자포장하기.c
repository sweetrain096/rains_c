# include <stdio.h>
int t;
int n;
int data[30], tmp[30];
int result;

int max(int a, int b) {
	if (a >= b) return a;
	else return b;
}

void powerset(int k, int l_sum, int r_sum, int left, int right) {
	int tmp_sum = 0;
	for (int plus = k; plus < n; plus++) {
		tmp_sum += data[plus];
	}
	if (l_sum + r_sum + tmp_sum < result) return;

	if (k == n) {
		result = max(result, l_sum + r_sum);
		return;
	}
	tmp[k] = 1;
	if (left == 0) powerset(k + 1, l_sum + data[k], r_sum, data[k], right);
	else {
		if (data[k] < left) powerset(k + 1, l_sum + data[k], r_sum, data[k], right);
	}
	tmp[k] = 2;
	if (right == 0) powerset(k + 1, l_sum, r_sum + data[k], left, data[k]);
	else {
		if (data[k] > right) powerset(k + 1, l_sum, r_sum + data[k], left, data[k]);
	}
	tmp[k] = 0;
	powerset(k + 1, l_sum, r_sum, left, right);
}
int main() {
	int tc, i;
	scanf("%d", &t);
	for (tc = 0; tc < t; tc++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &data[i]);
		}
		result = 0;
		powerset(0, 0, 0, 0, 0);
		printf("%d\n", result);
	}

	return 0;
}