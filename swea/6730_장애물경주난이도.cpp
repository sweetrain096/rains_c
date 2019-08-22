#include <stdio.h>
int T;
int n;
int maxU, maxD;
int now, pre;

int main(void) {
	freopen("6730_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &n);
		maxU = maxD = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &now);
			if (pre == -1) {
				pre = now;
			}
			if (pre > now && pre - now > maxD) maxD = pre - now;
			else if (pre < now && now - pre > maxU) maxU = now - pre;
			pre = now;
		}
		pre = -1;
		printf("#%d %d %d\n", tc, maxU, maxD);
	}
	return 0;
}