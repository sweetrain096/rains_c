# include <stdio.h>
int n;
int s[20], b[20];
int check[20];
int result;

int abs(int a) {
	if (a >= 0) return a;
	else return -a;
}

int min(int a, int b) {
	if (a <= b) return a;
	else return b;
}
void powerset(int k) {
	int j;
	int mul_s = 1, sum_b = 0;
	int check_0 = 0;
	if (k == n) {
		for (j = 0; j < n; j++) {
			if (check[j]) {
				mul_s *= s[j];
				sum_b += b[j];
			}
			else check_0 += 1;
		}
		if (check_0 == n) return;
		result = min(result, abs(mul_s - sum_b));
		return;
	}
	check[k] = 1;
	powerset(k + 1);
	check[k] = 0;
	powerset(k + 1);
	
}

int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
		scanf("%d", &b[i]);
	}
	result = 9999999;
	powerset(0);
	printf("%d", result);

	return 0;
}