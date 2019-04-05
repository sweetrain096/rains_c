# include <stdio.h>
int r, c;
int base[40][40];
int sr, sc, er, ec;
int wp, rp;
int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };
int visited[4][40][40];
int result;
struct st {
	int r, c, bomb, cnt;
};

struct st Q[1000000];

void inque(int r, int c, int bomb, int cnt) {
	Q[wp].r = r;
	Q[wp].c = c;
	Q[wp].bomb = bomb;
	Q[wp].cnt = cnt;
	wp++;
}

int bfs() {
	int nr, nc;
	wp = rp = 0;
	inque(sr, sc, 0, 0);
	visited[0][sr][sc] = 1;
	struct st data;
	while (rp < wp) {
		data = Q[rp++];
		for (int i = 0; i < 4; i++) {
			nr = data.r + dr[i];
			nc = data.c + dc[i];
			if (nr < 1 || nr > r || nc < 1 || nc > c) continue;
			
			if (data.bomb > 3) continue;
			if (base[nr][nc] == 4) {
				//printf("%d %d, result!!! ori %d %d, data %d %d, bomb %d\n", nr, nc, er, ec, data.r, data.c, data.bomb);
				result = data.cnt + 1;
				return;
			}
			if (base[nr][nc] == 1) continue;
			if (base[nr][nc] == 2) {
				if (data.bomb < 3 && visited[data.bomb + 1][nr][nc] == 0) {
					inque(nr, nc, data.bomb + 1, data.cnt + 1);
					visited[data.bomb + 1][nr][nc] = 1;
				}
				
			}
			else if (base[nr][nc] == 0) {
				if (visited[data.bomb][nr][nc]) continue;
				inque(nr, nc, data.bomb, data.cnt + 1);
				visited[data.bomb][nr][nc] = 1;
			}
			//printf("%d %d : %d %d : cnt-%d, bomb-%d\n", data.r, data.c, nr, nc, data.cnt + 1, data.bomb);

			

		}
	}
}

int main() {
	//freopen("¹Ì·ÎÅ»Ãâ_input.txt", "r", stdin);
	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf("%d", &base[i][j]);
			if (base[i][j] == 3) {
				sr = i;
				sc = j;
			}
			else if (base[i][j] == 4) {
				er = i;
				ec = j;
			}
		}
	}
	result = 987654321;
	bfs();
	if (result == 987654321) result = -1;
	printf("%d", result);


	return 0;
}