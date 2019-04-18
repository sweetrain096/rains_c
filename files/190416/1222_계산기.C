#include <stdio.h>
char data[150];
int temp, result;
char now;
int main() {
	freopen("1222_input.txt", "r", stdin);
	int tc, i;
	int tmp;

	for (tc = 1; tc <= 10; tc++) {
		scanf("%d", &temp);
		scanf("%s", data);
		i = 0;
		now = data[i];
		result = 0;


		while (now != '\0') {
			if (i == 0) {
				i++;
				continue;
			}
			if (now == '+') {
				now = data[i++];
				continue;
			}
			tmp = now - '0';
			result += tmp;
			now = data[i++];
		}
		printf("#%d %d\n", tc, result);
	}

	return 0;
}