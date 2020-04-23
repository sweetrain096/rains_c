#include <stdio.h>
int TC;
int n;
int numbers[1000];
int result;
int temp;
char num_char[20];

int is_right(int number) {
	sprintf(num_char, "%d", number);
	int pos = 0;
	while (num_char[pos] != '\0') {
		if (num_char[pos + 1] != '\0') {
			if (num_char[pos + 1] - num_char[pos] != 1) return 0;
		}
		pos++;
	}
	return 1;
}

int main(void) {
	freopen("9839_input.txt", "r", stdin);
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		result = -1;
		scanf("%d ", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d ", &numbers[i]);
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				temp = numbers[i] * numbers[j];
				if (is_right(temp) == 0) continue;
				if (result < temp) result = temp;
			}
		}
		printf("#%d %d\n", tc, result);
	}
	return 0;
}