#include <stdio.h>
int tn;
int arr[100][100];
int max, sum, sum2;

int main(void) {
	freopen("1209_input.txt", "r", stdin);
	for (int tc = 0; tc < 10; tc++) {
		scanf("%d", &tn);
		max = 0;
		int r, c;
		for (r = 0; r < 100; r++) {
			sum = 0;
			for (c = 0; c < 100; c++) {
				scanf("%d", &arr[r][c]);
				sum += arr[r][c];
			}
			if (sum > max) max = sum;
		}

		for (c = 0; c < 100; c++) {
			sum = 0;
			for (r = 0; r < 100; r++) {
				sum += arr[r][c];
			}
			if (sum > max) max = sum;
		}

		sum = sum2 = 0;
		for (int i = 0; i < 100; i++) {
			sum += arr[i][i];
			sum2 += arr[i][99 - i];
		}
		if (sum > max) max = sum;
		if (sum2 > max) max = sum2;

		printf("#%d %d\n", tn, max);
	}
}