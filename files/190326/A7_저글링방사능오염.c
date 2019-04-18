# include <stdio.h>

int row, col, sr, sc;
int map[110][110];
struct st {
	int r, c, time;
};

int wp, rp;
struct st Q[110 * 110];
void inque(int r, int c, int time) {
	Q[wp].r = r;
	Q[wp].c = c;
	Q[wp].time = time;
	wp++;
}
int bfs(void) {
	int nr, nc;

	wp = rp = 0;
	inque(sr, sc, 3);
	map[sr][sc] = 0;

	struct st data;
	
	int dr[4] = { 0, 0, 1, -1 }, dc[4] = { 1, -1, 0, 0 };
	while (rp < wp) {
		data = Q[rp++];
		//printf("%d %d %d\n", data.r, data.c, data.time);
		for (int i = 0; i < 4; i++) {
			nr = data.r + dr[i];
			nc = data.c + dc[i];
			if (nr < 1 || nr > row || nc < 1 || nc > col) continue;
			if (map[nr][nc] != 1) continue;
			inque(nr, nc, data.time + 1);
			map[nr][nc] = 0;
		}
	}
	return data.time;
}
int main(void) {
	int result, cnt = 0;
	scanf("%d %d", &col, &row);
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	scanf("%d %d", &sc, &sr);

	result = bfs();
	printf("%d\n", result);

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (map[i][j] == 1) cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}