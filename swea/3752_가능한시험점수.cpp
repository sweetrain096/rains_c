#include <stdio.h>
int TC, n;
int numbers[100] = { 0, };
int check[10010] = { 0, };
int sum_list[10010] = { 0, };
int num;
int cnt, result;
int main(void) {
	freopen("3752_input.txt", "r", stdin);

	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d ", &numbers[i]);
		}
		cnt = 1;
		for (int i = 0; i < n; i++) {
			int forcnt = cnt;
			for (int j = 0; j < forcnt; j++) {
				num = sum_list[j] + numbers[i];
				if (check[num]) continue;
				check[num] = 1;
				sum_list[cnt++] = num;

			}
		}
		for (int i = 0; i < cnt; i++) {
			check[sum_list[i]] = 0;
			printf("%d ", sum_list[i]);
		}
		printf("\n");

		printf("#%d %d\n", tc, cnt);
	}

	return 0;
}