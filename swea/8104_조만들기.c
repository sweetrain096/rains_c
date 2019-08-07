#include<stdio.h>
int t;
int n, k;

int main(void) {
	freopen("8104_input.txt", "r", stdin);
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %d", &n, &k);
		printf("#%d ", tc);
		if (n % 2) {
			int result = (1 + (n - 1) * k) * ((n - 1) / 2);
			for (int rc = 1; rc <= k; rc++) {
				printf("%d ", result + ((n - 1) * k + rc));
			}
		}
		else {
			int result = (1 + n * k) * (n / 2);
			for (int rc = 1; rc <= k; rc++) {
				printf("%d ", result);
			}
			
		}
		printf("\n");
	}
	return 0;
}