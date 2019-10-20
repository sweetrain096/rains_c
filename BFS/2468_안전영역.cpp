#include <stdio.h>

int n;
int Map[110][110];
int visited[110][110];
int max_h;
int max;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int wp, rp;
int tr, tc;
int nr, nc;

struct Queue {
	int r;
	int c;
};
struct Queue Q[100 * 100];
struct Queue tmp;
void inque(int r, int c) {
	Q[wp].r = r;
	Q[wp].c = c;
	wp++;
}

int is_wall(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= n) return 1;
	return 0;
}

int BFS(int k) {
	int cnt;
	cnt = 0;
	rp = wp = 0;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (Map[r][c] > k && visited[r][c] == 0) {
				inque(r, c);
				visited[r][c] = 1;
				cnt++;
				while (rp < wp) {
					tmp = Q[rp++];
					tr = tmp.r;
					tc = tmp.c;
					//printf("r, c, now : %d %d %d \n", tr, tc, Map[tr][tc]);
					for (int i = 0; i < 4; i++) {
						nr = dr[i] + tr;
						nc = dc[i] + tc;
						if (is_wall(nr, nc) == 0 && Map[nr][nc] > k && visited[nr][nc] == 0) {
							inque(nr, nc);
							visited[nr][nc] = 1;
						}
					}
				}
				
			}
		}
	}
	return cnt;
}

int main(void) {
	freopen("2468_input.txt", "r", stdin);
	scanf("%d", &n);
	max = 1;
	max_h = 0;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			scanf("%d ", &Map[r][c]);
			if (max_h < Map[r][c]) max_h = Map[r][c];
		}
	}
	int cnt;
	for (int k = 1; k <= max_h; k++) {
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				visited[r][c] = 0;
			}
		}
		cnt = BFS(k);
		if (max < cnt) max = cnt;
	}
	printf("%d", max);

	return 0;
}