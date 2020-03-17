#include <stdio.h>

int TC;
int n;
int map[110][110];
int visited[110][110];
int wp, rp;

int dr[4] = { -1, 0, 0, 1 };
int dc[4] = { 0, -1, 1, 0 };

typedef struct Queue {
	int r, c;
}Queue;

Queue Q[1000000];
Queue tmp;
void inque(int r, int c) {
	Q[wp].r = r;
	Q[wp].c = c;
	wp++;
}

int bfs() {
	int nr, nc;
	inque(0, 0);
	visited[0][0] = 0;
	
	while (rp <= wp) {
		tmp = Q[rp++];
		for (int i = 0; i < 4; i++) {
			nr = tmp.r + dr[i];
			nc = tmp.c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
			if (nr + nc == 0) continue;
			if (visited[nr][nc] > visited[tmp.r][tmp.c] + map[nr][nc]) {
				visited[nr][nc] = visited[tmp.r][tmp.c] + map[nr][nc];
				inque(nr, nc);
			}
		}
	}
	return visited[n - 1][n - 1];
}

int main(void) {
	freopen("1249_input.txt", "r", stdin);
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d ", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &map[i][j]);
				visited[i][j] = 100000;
			}
		}
		wp = rp = 0;

		printf("#%d %d\n", tc, bfs());
	}

	return 0;
}