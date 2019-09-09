#include <stdio.h>

int n;
int cnt;
int Map[20][20];
int visited[20][20];

int is_wall(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= n) {
		return 1;
	}
	return 0;
}

void Backtracking(int hr, int hc, int tr, int tc) {
	visited[hr][hc] = 1;

	if (hr == n - 1 && hc == n - 1) {
		cnt++;
	}
	if (is_wall(hr + 1, hc + 1) == 0 && visited[hr + 1][hc + 1] == 0 && Map[hr + 1][hc + 1] == 0) {
		if (Map[hr + 1][hc] == 0 && Map[hr][hc + 1] == 0) {
			Backtracking(hr + 1, hc + 1, hr, hc);
		}
	}
	if (hr == tr || (hr == tr + 1 && hc == tc + 1)) {
		if (is_wall(hr, hc + 1) == 0 && visited[hr][hc + 1] == 0 && Map[hr][hc + 1] == 0) {
			Backtracking(hr, hc + 1, hr, hc);
		}
	}
	if (hc == tc || (hr == tr + 1 && hc == tc + 1)) {
		if (is_wall(hr + 1, hc) == 0 && visited[hr + 1][hc] == 0 && Map[hr + 1][hc] == 0) {
			Backtracking(hr + 1, hc, hr, hc);
		}
	}

	visited[hr][hc] = 0;
}

int main(void) {
	freopen("17070_input.txt", "r", stdin);
	scanf("%d", &n);
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			scanf("%d ", &Map[r][c]);
		}
	}
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			visited[r][c] = 0;
		}
	}

	cnt = 0;
	Backtracking(0, 1, 0, 0);
	printf("%d", cnt);
	return 0;
}