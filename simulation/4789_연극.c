#include <stdio.h>

char people[1002];
int T;
int total, result;

int main(void) {
	freopen("4789_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%s", people);
		total = 0;
		result = 0;
		for (int i = 0; i <= 1001; i++) {
			if (people[i] == '\0') break;
			if (total < i) {
				result += i - total;
				total += i - total;
			}
			total += people[i] - 48;
		}
		printf("#%d %d\n", tc, result);

	}

	return 0;
}