# include <stdio.h>
int n;
int data[30], check[30];
int sum1, sum2;
int result;

int abs(int a) {
	if (a >= 0) return a;
	else return -a;
}
int min(int a, int b) {
	if (a <= b) return a;
	else return b;
}

void powerset(int k, int cnt) {
	int i;
	sum1 = 0, sum2 = 0;
	if (cnt > (n / 2)) return;

	if (k == n) {
		if (cnt != n / 2) return;
		for (i = 0; i < n; i++) {
			if (check[i]) sum1 += data[i];
			else sum2 += data[i];
		}
		result = min(result, abs(sum1 - sum2));
		return;
	}
	check[k] = 1;
	powerset(k + 1, cnt + 1);
	check[k] = 0;
	
	powerset(k + 1, cnt);
}

int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}

	result = 9999999;
	powerset(0, 0);
	printf("%d", result);
}