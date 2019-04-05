# include <stdio.h>
int t, n;
int map[110][110], bfs_map[110][110];
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int wp, rp;

struct st {
	int r, c;
};

struct st Q[100000];

void inque(int r, int c) {
	Q[wp].r = r;
	Q[wp].c = c;
	wp++;
}


int bfs() {
	int i;
	int nr, nc;
	wp, rp = 0, 0;

	bfs_map[0][0] = 0;
	inque(0, 0);

	struct st data;
	while (rp < wp) {
		data = Q[rp++];

		for (i = 0; i < 4; i++) {
			nr = dr[i] + data.r;
			nc = dc[i] + data.c;

			if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
			if (bfs_map[nr][nc] > bfs_map[data.r][data.c] + map[nr][nc]) {
				bfs_map[nr][nc] = bfs_map[data.r][data.c] + map[nr][nc];
				inque(nr, nc);
			}
		}
	}
	return bfs_map[n - 1][n - 1];
}




int main() {
	freopen("º¸±Þ·Î.txt", "r", stdin);
	int tc, i, j;
	scanf("%d", &t);
	for (tc = 0; tc < t; tc++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%1d", &map[i][j]);
				bfs_map[i][j] = 9999999;
			}
		}
		printf("#%d %d\n", tc + 1, bfs());
	}

	return 0;
}