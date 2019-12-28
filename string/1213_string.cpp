#include <stdio.h>

int tn;
char str[1010];
char target[1010];
int len_str;
int len_target;
int cnt;
int cnt_char;
int flag;

int main(void) {
	freopen("1213_input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		scanf("%d", &tn);
		scanf("%s", str);
		cnt_char = 0;
		while (str[cnt_char] != '\0') cnt_char++;
		len_str = cnt_char;

		scanf("%s", target);
		cnt_char = 0;
		while (target[cnt_char] != '\0') cnt_char++;
		len_target = cnt_char;
		
		cnt = 0;
		for (int i = 0; i <= len_target - len_str; i++) {
			flag = 1;
			for (int j = 0; j < len_str; j++) {
				if (str[j] != target[i + j]) flag = 0;
				if (flag == 0) break;
			}
			if (flag) cnt++;
		}
		printf("#%d %d\n", tn, cnt);
	}
	return 0;
}