# include <stdio.h>
int t, n;
int cookie[20][2], robot[20][2];
int data[20][20];
int visited[20]; //引切端滴
int nmin;

int abs(int a) {
	if (a >= 0) return a;
	else return -a;
}


void dfs(no, nsum) {
	if (nsum > nmin) return;
	if (no >= n) {
		if (nsum < nmin) {
			nmin = nsum;
			return;
		}
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		dfs(no + 1, nsum + data[no][i]);
		visited[i] = 0;
	}
	
}
int main() {
	freopen("引切.txt", "r", stdin);
	int tc, i, j;
	scanf("%d", &t);
	for (tc = 0; tc < t; tc++) {
		scanf("%d", &n);

		for (i = 0; i < n * 2; i++) {
			if (i % 2 == 0) scanf("%d", &cookie[i / 2][0]);
			else scanf("%d", &cookie[i / 2][1]);
		}

		for (i = 0; i < n * 2; i++) {
			if (i % 2 == 0) scanf("%d", &robot[i / 2][0]);
			else scanf("%d", &robot[i / 2][1]);
		}


		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				data[i][j] = abs(robot[i][0] - cookie[j][0]) + abs(robot[i][1] - cookie[j][1]);
			}
		}
		nmin = 9999999;
		dfs(0, 0);
		printf("%d\n", nmin);


	}


	return 0;
}