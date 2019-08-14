#include <stdio.h>
int tc;
int k;
int center;
int tmp;
int results[1300];
int pow(int n, int m) {
	int result = 1;
	for (int i = 0; i < m; i++) {
		result *= 2;
	}
	return result;
}

int main(void) {
	freopen("7985_input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d", &k);
		center = pow(2, k - 1);
		int now = center;
		printf("%d %d\n", k, center);
		for (int i = 1; i <= pow(2, k); i++) {
			scanf("%d", &tmp);
			
		}
	}
	return 0;
}