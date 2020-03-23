#include <stdio.h>

int TC;
int n;
int cnt;
int mine;
char map[310][310];
int visited[310][310];
int dr[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dc[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int rp, wp;

typedef struct Queue {
	int r, c;
}Queue;
Queue queue[1000 * 1000];

int is_wall(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= n) return 1;
	return 0;
}

void inque(int r, int c) {
	queue[wp].r = r;
	queue[wp].c = c;
	wp++;
}
int bfs(int r, int c, int cnt) {
	Queue temp;
	int nr, nc;
	rp = wp = 0;
	inque(r, c);
	visited[r][c] = 1;
	map[r][c] = '0';
	while (rp < wp) {
		temp = queue[rp++];
		mine = 0;
		for (int i = 0; i < 8; i++) {
			nr = temp.r + dr[i];
			nc = temp.c + dc[i];
			if (is_wall(nr, nc) == 0 && map[nr][nc] == '*') mine++;
		}
		if (mine == 0) {
			for (int i = 0; i < 8; i++) {
				nr = temp.r + dr[i];
				nc = temp.c + dc[i];
				if (is_wall(nr, nc) == 0 && visited[nr][nc] == 0 && map[nr][nc] == '.') {
					visited[nr][nc] = 1;
					map[nr][nc] = '0';
					inque(nr, nc);
				}
			}
		}
		else {
			map[temp.r][temp.c] = mine + '0';
		}
	}
	//for (int i = 0; i < n; i++) printf("%s\n", map[i]);

	return cnt + 1;
}

int main(void) {
	freopen("1868_input.txt", "r", stdin);
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d ", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", map[i]);
		}
		//for (int i = 0; i < n; i++) printf("%s\n", map[i]);
		int nr, nc;
		int mine_cnt;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != '.') continue;
				mine_cnt = 0;
				for (int k = 0; k < 8; k++) {
					nr = i + dr[k];
					nc = j + dc[k];
					if (is_wall(nr, nc) == 0 && visited[nr][nc] == 0 && map[nr][nc] == '*') mine_cnt++;
				}
				if (mine_cnt == 0)cnt = bfs(i, j, cnt);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == '.') cnt++;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) visited[i][j] = 0;
		}
		printf("#%d %d\n", tc, cnt);
	}


	return 0;
}