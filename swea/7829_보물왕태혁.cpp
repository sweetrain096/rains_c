#include <stdio.h>

int TC;
int n; 
int temp;
int min, max;
int main(void) {
	freopen("7829_input.txt", "r", stdin);
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d ", &n);
		scanf("%d ", &temp);
		max = temp;
		min = temp;
		for (int i = 0; i < n - 1; i++) {
			scanf("%d ", &temp);
			if (min > temp) min = temp;
			if (max < temp) max = temp;
		}
		printf("#%d %d\n", tc, min * max);
	}
	return 0;
}