#include <stdio.h>
int tc;
long long int left, right, n;

int main(void) {
	freopen("8016_input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%lld", &n);
		left = (n - 1) * (n - 1) * 2 + 1;
		right = n * n * 2 - 1;
		printf("#%d %lld %lld\n", t, left, right);
	}
	return 0;
}