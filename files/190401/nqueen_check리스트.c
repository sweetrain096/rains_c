# include <stdio.h>
int n, cnt;
int check1[20], check2[20], check3[20];

void dfs(int k) {
	if (k == n) {
		cnt += 1;
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (check1[i] || check2[(k + i)] || check3[(n - 1) - (k - i)]) continue;
			check1[i] = 1;
			check2[(k + i)] = 1;
			check3[(n - 1) - (k - i)] = 1;

			dfs(k + 1);

			check1[i] = 0;
			check2[(k + i)] = 0;
			check3[(n - 1) - (k - i)] = 0;

		}
	}
}


int main() {
	scanf("%d", &n);

	cnt = 0;
	dfs(0);
	printf("%d", cnt);

	return 0;
}