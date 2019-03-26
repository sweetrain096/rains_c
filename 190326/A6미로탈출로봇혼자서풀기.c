# include <stdio.h>
int mr, mc;
int sr, sc, er, ec;
int maze[110][110];

struct check {
	int r, c, time;
};
struct check Q[110 * 110];

int rp, wp;
void inque(int r, int c, int time) {
	Q[wp].r = r;
	Q[wp].c = c;
	Q[wp].time = time;
	wp++;
}
int bfs(void) {
	int nr, nc;
	int dr[4] = { 1, -1, 0, 0 };
	int dc[4] = { 0, 0, 1, -1 };
	
	wp = rp = 0;
	struct check data;

	inque(sr, sc, 0);
	maze[sr][sc] = 1;
	
	
	while (rp < wp) {
		data = Q[rp++];
		if (data.r == er && data.c == ec)	return data.time;
		for (int i = 0; i < 4; i++) {
			nr = data.r + dr[i];
			nc = data.c + dc[i];
			if (nr < 1 || nr > mr || nc < 1 || nc > mc)	continue;
			if (maze[nr][nc] != 0)	continue;
			inque(nr, nc, data.time + 1);
			maze[nr][nc] = 1;
		}
	}
	return -1;
}

int main(void) {
	int i, j, result;
	scanf("%d %d", &mc, &mr);
	scanf("%d %d %d %d", &sc, &sr, &ec, &er);
	for (i = 1; i <= mr; i++) {
		for (j = 1; j <= mc; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	result = bfs();
	printf("%d", result);
}
