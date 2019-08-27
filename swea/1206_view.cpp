#include <stdio.h>
int n;
int buildings[1010];
int check_max;
int result;

int max(int a, int b, int c, int d) {
	int result = a;
	if (result < b) result = b;
	if (result < c) result = c;
	if (result < d) result = d;

	return result;
}

int main(void) {
	freopen("1206_input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		scanf("%d", &n);
		result = 0;
		for (int cnt = 0; cnt < n; cnt++) {
			scanf("%d", &buildings[cnt]);
		}
		for (int cnt = 2; cnt < n - 2; cnt++) {
			check_max = max(buildings[cnt - 2], buildings[cnt - 1], buildings[cnt + 1], buildings[cnt + 2]);
			if (buildings[cnt] > check_max) result += (buildings[cnt] - check_max);
		}
		printf("#%d %d\n", tc, result);
	}
	return 0;
}