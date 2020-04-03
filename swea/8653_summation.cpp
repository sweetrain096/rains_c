#include <stdio.h>
int TC;
char number[10];
int min, max;
int pos;
int sum;

int main(void) {
	freopen("8658_input.txt", "r", stdin);
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		min = 9 * 10;
		max = 0;
		for (int i = 0; i < 10; i++) {
			scanf("%s", number);
			pos = 0;
			sum = 0;
			while (number[pos] != '\0') {
				sum += number[pos++] - '0';
			}
			if (min > sum) min = sum;
			if (max < sum) max = sum;
		}
		printf("#%d %d %d\n", tc, max, min);
	}

	return 0;
}