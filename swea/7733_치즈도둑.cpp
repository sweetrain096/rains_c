#include <stdio.h>
int TC;
int n;
int map[100][100];
int visited[100][100];
int max_day;
int day;
int result;
int cnt;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

struct queue {
	int r, c;
};
struct queue Q[100 * 100];
int rp, wp;
void inque(int r, int c) {
	Q[wp].r = r;
	Q[wp].c = c;
	wp++;
}

void bfs(int r, int c) {
	rp = 0;
	wp = 0;
	inque(r, c);
	int nr, nc;
	struct queue temp;
	while (rp < wp) {
		temp = Q[rp++];
		for (int i = 0; i < 4; i++) {
			nr = temp.r + dr[i];
			nc = temp.c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
			if (visited[nr][nc]) continue;
			if (map[nr][nc]) {
				visited[nr][nc] = 1;
				inque(nr, nc);
			}
		}
	}
}

int main(void) {
	freopen("7733_input.txt", "r", stdin);
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		result = 0;
		scanf("%d ", &n);
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				scanf("%d ", &map[r][c]);
				if (map[r][c] > max_day) max_day = map[r][c];
			}
		}
		for (day = 0; day <= max_day; day++) {
			cnt = 0;
			for (int r = 0; r < n; r++) {
				for (int c = 0; c < n; c++) {
					visited[r][c] = 0;
					if (map[r][c] == day) map[r][c] = 0;
				}
			}
			for (int r = 0; r < n; r++) {
				for (int c = 0; c < n; c++) {
					if (visited[r][c] == 0 && map[r][c]) {
						bfs(r, c);
						cnt++;
					}
				}
			}
			if (result < cnt) result = cnt;
		}
		printf("#%d %d\n", tc, result);
	}

	return 0;
}