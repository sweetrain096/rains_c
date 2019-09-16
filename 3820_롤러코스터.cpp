#include <stdio.h>
int testcase, n;
int a, b, v;
int v_list[200010];

typedef struct data {
	int a, b;
}data;

data list[200010];


/*int DP() {
	int min, incmin;
	int check;
	v_list[0] = 1;
	for (int r = 0; r < n; r++) {
		min = 0;
		check = -1;
		for (int c = 0; c < n; c++) {
			if (list[c].a && min == 0) {
				min = list[c].a * v_list[r] + list[c].b;
				check = c;
			}
			else if (list[c].a) {
				if (list[c].a * v_list[r] + list[c].b <= min) {
					min = list[c].a * v_list[r] + list[c].b;
					check = c;
					incmin = 0;
					for (int inc = 0; inc < n; inc++) {
						if (inc == c) continue;
						if (list[inc].a && incmin == 0) {
							incmin = min * list[inc].a + list[inc].b;
						}
						else if (list[inc].a) {
							if (list[inc].a * min + list[inc].b < incmin) {
								incmin = list[inc].a * min + list[inc].b;
								check = c;
							}
							else if (list[inc].a * min + list[inc].b == incmin) {
								check = c;
							}

						}
					}
				}
				
			}
			
		}
		v_list[r + 1] = min;
		list[check].a = 0;
		list[check].b = 0;
		printf("%d, ", v_list[r + 1]);
	}
	return v_list[n];
}
*/

int main(void) {
	freopen("3820_input.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int tc = 1; tc <= testcase; tc++) {
		scanf("%d", &n);
		v = 1;
		for (int cnt = 0; cnt < n; cnt++) {
			scanf("%d %d", &a, &b);
			list[cnt].a = a;
			list[cnt].b = b;
		}

		//printf("#%d %d\n", tc, DP());
	}

	return 0;
}