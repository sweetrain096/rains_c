#include <stdio.h>

int TC;
int n;
int deg[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int Map[1000][1000];
int visited[1000][1000];
int min, cnt;
int newMin, newCnt;


int is_wall(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= n) return 1;
	return 0;
}

void dfs(int r, int c) {
	visited[r][c] = 1;
	if (newMin > Map[r][c]) newMin = Map[r][c];
	newCnt++;

	int nr, nc;
	for (int i = 0; i < 4; i++) {
		nr = r + deg[i][0];
		nc = c + deg[i][1];
		if (is_wall(nr, nc) == 0 && visited[nr][nc] == 0) {
			if (Map[r][c] - Map[nr][nc] == -1 || Map[r][c] - Map[nr][nc] == 1) dfs(nr, nc);
		}

	}
}

int main(void) {
	freopen("1861_input.txt", "r", stdin);
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d ", &n);
		min = n * n;
		cnt = 0;
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				scanf("%d ", &Map[r][c]);
			}
		}

		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				if (visited[r][c] == 0) {
					newMin = n * n;
					newCnt = 0;
					dfs(r, c);
					if (newCnt > cnt) {
						cnt = newCnt;
						min = newMin;
					}
					else if (newCnt == cnt) {
						if (min > newMin) min = newMin;
					}
				}
			}
		}
		printf("#%d %d %d\n", tc, min, cnt);

		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				Map[r][c] = 0;
				visited[r][c] = 0;
			}
		}
	}

	return 0;
}