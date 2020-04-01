#include <stdio.h>

int TC;
char number[10];
char num;
int cnt;
int numbers[11];
int main(void) {
	freopen("7728_input.txt", "r", stdin);
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%s", number);
		int i = 0;
		int now;
		for (int j = 0; j < 10; j++) {
			numbers[j] = 0;
		}
		while (number[i] != '\0') {
			now = number[i] - '0';

			if (numbers[now] == 0) numbers[now] = 1;
			i++;
		}
		cnt = 0;
		for (int j = 0; j < 10; j++) {
			if (numbers[j] == 1) cnt++;
		}
		printf("#%d %d\n", tc, cnt);

	}
	return 0;
}