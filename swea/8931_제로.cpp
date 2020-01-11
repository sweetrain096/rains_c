#include <stdio.h>

int TC;
int k;
int nums[100000];
int num, cursor;
int result;

int main(void) {
	freopen("8931_input.txt", "r", stdin);
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d ", &k);
		result = 0;
		cursor = 0;
		for (int i = 0; i < k; i++) {
			scanf("%d ", &num);
			if (num) nums[cursor++] = num;
			else nums[cursor--] = 0;
		}

		for (int i = 0; i < cursor; i++) result += nums[i];
		printf("#%d %d\n", tc, result);
	}


	return 0;
}