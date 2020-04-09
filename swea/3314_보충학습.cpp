#include <stdio.h>
int TC;
int score;
int sum;
int main(void) {
	freopen("3314_input.txt", "r", stdin);
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		sum = 0;
		for (int i = 0; i < 5; i++) {
			scanf("%d ", &score);
			if (score < 40) sum += 40;
			else sum += score;
		}
		printf("#%d %d\n", tc, sum / 5);
	}
	return 0;
}