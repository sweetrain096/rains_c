#include <stdio.h>

char right[10] = "croak";
int TC;
char input[2510];



int main(void) {
	freopen("5550_input.txt", "r", stdin);
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		int data[5] = { 0, 0, 0, 0, 0 };
		int able[500] = { 0, };
		int cnt = 0;
		scanf("%s", input);
		int now_cnt = 0;
		char now = input[now_cnt++];

		while (now != '\0') {
			if (cnt == -1) break;
			for (int i = 0; i < 5; i++) {
				if (i == 0) {
					if (now == right[i]) {
						if (cnt == 0) able[cnt++] = 1;
						else {
							int flag = 0;
							for (int j = 0; j < cnt; j++) {
								if (able[j] == 0) {
									able[j] = 1;
									flag = 1;
									break;
								}
							}
							if (flag == 0) {
								able[cnt++] = 1;
							}
						}
						data[i]++;
						break;
					}
				}
				else {
					if (now == right[i]) {
						if (data[i - 1] > data[i]) {
							data[i]++;
							if (i == 4) {
								for (int j = 0; j < cnt; j++) {
									if (able[j] == 1) {
										able[j] = 0;
										break;
									}
								}
							}
						}
						else { cnt = -1; }
						break;
					}
				}
			}
			now = input[now_cnt++];
		}
		if (data[0] != data[4]) cnt = -1;
		printf("#%d %d\n", tc, cnt);
	}
	

	return 0;
}