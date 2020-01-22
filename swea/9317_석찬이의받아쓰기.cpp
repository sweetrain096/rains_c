#include <stdio.h>

int TC;
int n;
int result;
char correct[100010];
char answer[100010];

int main(void) {
	freopen("9317_input.txt", "r", stdin);
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d ", &n);
		scanf("%s", correct);
		scanf("%s", answer);
		result = 0;
		for (int i = 0; i < n; i++) {
			if (correct[i] == answer[i]) result++;
		}
		printf("#%d %d\n", tc, result);
	}
	return 0;
}