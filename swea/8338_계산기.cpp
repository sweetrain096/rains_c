#include <stdio.h>
int testcase;
int n;
int result;
int tmp;
int main(void) {
	freopen("8338_input.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int tc = 1; tc <= testcase; tc++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			if (i == 0) scanf("%d", &result);
			else {
				scanf("%d", &tmp);
				if (tmp == 0) continue;
				else if (tmp + result >= tmp * result) result += tmp;
				else result *= tmp;
			}
		}
		printf("#%d %d\n", tc, result);
	}
	return 0;
}