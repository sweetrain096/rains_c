# include <stdio.h>
int t;
int n;
int sr, sc, er, ec;
int data[20][2];
int result;
int last_check;
int tmp[2];

int abs(int a) {
	if (a >= 0) return a;
	else return -a;
}
int min(int a, int b) {
	if (a >= b) return b;
	else return a;
}

void perm(int n, int k, int sum_data) {
	int i, tmp_sum, j;

	if (result < sum_data) return;
	if (n == k) {
		last_check = sum_data + abs(data[k - 1][0] - er) + abs(data[k - 1][1] - ec);
		result = min(last_check, result);

	}
	else {
		for (i = k; i < n; i++) {
			for (j = 0; j <= 1; j++) {
				tmp[j] = data[k][j];
				data[k][j] = data[i][j];
				data[i][j] = tmp[j];
			}


			if (k == 0) {
				tmp_sum = abs(sr - data[k][0]) + abs(sc - data[k][1]);
				perm(n, k + 1, sum_data + tmp_sum);
			}
			else {
				tmp_sum = abs(data[k - 1][0] - data[k][0]) + abs(data[k - 1][1] - data[k][1]);
				perm(n, k + 1, sum_data + tmp_sum);
			}
			for (j = 0; j <= 1; j++) {
				tmp[j] = data[k][j];
				data[k][j] = data[i][j];
				data[i][j] = tmp[j];
			}

		}
	}
}
int main(void) {
	freopen("workshop1_input.txt", "r", stdin);
	int tc, i;
	
	scanf("%d", &t);
	
	for (tc = 0; tc < t; tc++) {
		result = 999999999;
		scanf("%d", &n);
		for (i = 0; i < 4 + (n * 2); i++) {
			if (i == 0) scanf("%d", &sr);
			else if (i == 1) scanf("%d", &sc);
			else if (i == 2) scanf("%d", &er);
			else if (i == 3) scanf("%d", &ec);
			else {
				if (i % 2 == 0) scanf("%d", &data[i / 2 - 2][0]);
				else scanf("%d", &data[i / 2 - 2][1]);
			}
		}
		
		

		perm(n, 0, 0);
		printf("#%d %d\n", tc + 1, result);
		
	}

}