#include <stdio.h>
int TC;
char N[1000000];
int first, second, third;
char now;
int now_cnt;
int len_demicals;
int main(void) {
	freopen("No1_input.txt", "r", stdin);
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%s ", N);
		//printf("%s \n", N);
		first = N[0] - '0';
		second = N[1] - '0';
		third = N[2] - '0';
		//printf("%d %d %d \n", first, second, third);

		now_cnt = 0;
		now = N[now_cnt];
		while (now != '\0') {
			now = N[now_cnt++];
		}
		len_demicals = now_cnt - 2;

		// ¹Ý¿Ã¸²
		if (third >= 5) {
			second += 1;
			if (second == 10) {
				first += 1;
				second = 0;
				if (first == 10) {
					first = 1;
					len_demicals += 1;
				}
			}
		}
		printf("#%d %d.%d*10^%d\n", tc, first, second, len_demicals);
	}
	return 0;
}